/*
 * Copyright (c) Amel Technology. All right reserved.
 * Copyright (c) Logitech Inc. All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 */
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>

#include <cstdio>
#include <cerrno>
#include <cstring>
#include <vector>

#include "NT3H1101.h"

#define _STR(x) #x
#define STRINGIFY(x)    _STR(x)
#define NXPNFC_DEVICE "/dev/i2c-" STRINGIFY(NXPNFC_BUS)

/*
 * this file has been extensively modified from the SmartEverything source
 * to handle i2c transfers via the Linux i2c library instead of
 * the Arduino "Wire" library.
 * Borrows heavily on the MFI library in the ADK
 */

static const char *i2c_device = NXPNFC_DEVICE;
static int i2c = -1;
static uint16_t base_i2c_flags = 0;

static bool i2c_open(const char *dev)
{
        if (i2c < 0) {
                i2c = open(dev, O_RDWR);
        }
        return i2c >= 0;
}

using Batch = std::vector < i2c_msg >;

static bool process_batch(Batch && batch)
{
        if (!i2c_open(i2c_device))
                return false;
        for (auto && msg:batch) {
                // Process all I2C commands, retrying each one if necessary
                bool ok { };

                for (auto sleep_us = 500; sleep_us < 1024000; sleep_us *= 2) {

                        auto msgs = i2c_rdwr_ioctl_data { &msg, 1 };
                        ok =::ioctl(i2c, I2C_RDWR, &msgs) >= 1;
                        if (ok)
                                break;  // Success, no need to retry

                        if (errno == ENXIO || errno == EBUSY) {
                                // Implement an exponential backoff
                                usleep(sleep_us);
                                continue;
                        } else {
                                std::fprintf(stderr, "i2c transfer failed: %m\n");
                                return false;
                        }
                }

                if (!ok) {
                        std::fprintf(stderr, "i2c transfer failed after many retries\n");
                        return false;
                }
        }
        return true;
}

static bool writeBufferRegister(uint8_t slaveAddress, uint8_t regToWrite,
                                const uint8_t * dataToWrite, uint16_t dataLen)
{
        // Prepare the I2C commands
        uint8_t write_buffer[dataLen + 1];

        write_buffer[0] = regToWrite;
        memcpy(&write_buffer[1], dataToWrite, dataLen);
        Batch batch {
                i2c_msg {
                        slaveAddress, base_i2c_flags, ++dataLen, write_buffer}};
        return process_batch(std::move(batch));
}

static bool readRegisters(uint8_t slaveAddress, uint8_t regToRead,
                          int bytesToRead, uint8_t * dest)
{
        // Prepare the I2C commands
        Batch batch {
                i2c_msg {
        slaveAddress, base_i2c_flags, 1, (uint8_t *) & regToRead}};
        while (bytesToRead > 0) {
                int16_t seg_len = std::min(bytesToRead, NFC_PAGE_SIZE);

                batch.emplace_back(i2c_msg {
                                   slaveAddress,
                                   (uint16_t) (I2C_M_RD | base_i2c_flags),
                                   (uint16_t) seg_len, dest}
                );
                dest = dest + seg_len;
                bytesToRead -= seg_len;
        }

        return process_batch(std::move(batch));
}

bool NT3H1101_C::readManufacturingData(uint8_t nfcPageBuffer[])
{
        return readRegisters(_address, MANUFACTURING_DATA_REG, NFC_PAGE_SIZE,
                             nfcPageBuffer);
}

bool NT3H1101_C::readUID(uint8_t nfcPageBuffer[])
{
        return readRegisters(_address, MANUFACTURING_DATA_REG, UID_SIZE,
                             nfcPageBuffer);
}

bool NT3H1101_C::readUserPage(uint8_t userPagePtr, uint8_t nfcPageBuffer[])
{
        uint8_t reg = USER_START_REG + userPagePtr;

        // if the requested page is out of the register exit with error
        if (reg > USER_END_REG) {
                return false;
        }

        return readRegisters(_address, reg, NFC_PAGE_SIZE, nfcPageBuffer);

}

bool NT3H1101_C::writeUserPage(uint8_t userPagePtr,
                               const uint8_t nfcPageBuffer[])
{

        uint8_t reg = USER_START_REG + userPagePtr;

        if (reg > USER_END_REG) {
                return false;
        }

        bool ret =
            writeBufferRegister(_address, reg, nfcPageBuffer, NFC_PAGE_SIZE);
        if (ret)
                usleep(100);    // give some time to NC for store the buffer

        return ret;
}

NT3H1101_C smeNfcDriver;

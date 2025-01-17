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
 *
 */
#ifndef NT3H1101_h
#define NT3H1101_h

#include "SmeNfcConfig.h"
#include "nfctag/NT3H1101_model.h"
#include "SmeNfc.h"

#ifndef NXPNFC_ADDRESS
#define NXPNFC_ADDRESS 0x55
#endif

#define MANUFACTURING_DATA_REG 0x0
#define USER_START_REG 0x1

#ifdef NT3H1201_DEF             // for the 2K
#define USER_END_REG   0x77
#define CONFIG_REG	   0x7A
#elif  NT3H1101_DEF             // for the 1K
#define USER_END_REG   0x38     // just the first 8 bytes for the 1K
#define CONFIG_REG	   0x3A
#else
#warning Assuming NT3H1101 model
#define USER_END_REG   0x38     // just the first 8 bytes for the 1K
#define CONFIG_REG	   0x3A
#endif

#define SRAM_START_REG 0xF8
#define SRAM_END_REG   0xFB     // just the first 8 bytes

class NT3H1101_C {
 private:
        unsigned int _address;
 public:
         NT3H1101_C(void):_address(NXPNFC_ADDRESS) {
        };

        /*
         * Read the manufacturing data of the NT3H1101
         */
        bool readManufacturingData(uint8_t nfcPageBuffer[]);

        /*
         * Read the 7-byte serial number (UID) of the NT3H1101
         */
        bool readUID(uint8_t nfcPageBuffer[]);

        /*
         * Read the a page within the space reserved for the user
         *
         *  userPagePtr = 0 for the first page 0x37 for the last page
         */
        bool readUserPage(uint8_t userPagePtr, uint8_t nfcPageBuffer[]);

        /*
         * write a page within the space reserved for the user
         *
         *      userPagePtr = 0 for the first page 0x37 for the last page
         */
        bool writeUserPage(uint8_t userPagePtr, const uint8_t nfcPageBuffer[]);

};

extern NT3H1101_C smeNfcDriver;

#endif

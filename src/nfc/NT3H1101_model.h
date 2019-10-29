/*
 * NT3H1101_model.h
 *
 * Created: 3/8/2015 11:37:26 AM
 * by Mik (smkk@amel-tech.com)
 *
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
#include <stdint.h>

#ifndef NT3H1101_MODEL_H_
#define NT3H1101_MODEL_H_


#define NFC_PAGE_SIZE 16
#define UID_SIZE 7

typedef enum {
    NT3HERROR_NO_ERROR,
    NT3HERROR_READ_HEADER,
    NT3HERROR_WRITE_HEADER,
    NT3HERROR_INVALID_USER_MEMORY_PAGE,
    NT3HERROR_READ_USER_MEMORY_PAGE,
    NT3HERROR_WRITE_USER_MEMORY_PAGE,
    NT3HERROR_ERASE_USER_MEMORY_PAGE,
    NT3HERROR_READ_NDEF_TEXT,
    NT3HERROR_WRITE_NDEF_TEXT,
    NT3HERROR_TYPE_NOT_SUPPORTED
}NT3HerrNo;

// structure that contains the configuration data
typedef struct {
    uint8_t nc_reg;
    uint8_t last_ndef_block;
    uint8_t sram_mirror_block;
    uint8_t wdt_ls;
    uint8_t wdt_ms;
    uint8_t i2c_clock_str;
    uint8_t reg_clock;
    uint8_t unused;
} configS;


// structure that contains the manufacturing data
typedef struct {
    uint8_t  slaveAddr;
    uint8_t  serialNumber[6];
    uint8_t  internalData[3];
    uint16_t lockBytes;
    uint32_t capabilityContainer;
} manufS;

extern uint8_t      nfcPageBuffer[NFC_PAGE_SIZE];
extern NT3HerrNo    errNo;
#endif /* NT3H1101_MODEL_H_ */

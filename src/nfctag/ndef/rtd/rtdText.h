/*
 * ndefText.h
 *
 *  Created on: Mar 24, 2015
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

#ifndef RTDTEXT_H_
#define RTDTEXT_H_

#include <stdint.h>
#include "../../../SmeNfc.h"

#define BIT_STATUS (1<<7)
#define BIT_RFU	   (1<<6)


#define MASK_STATUS 0x80
#define MASK_RFU    0x40
#define MASK_IANA   0b00111111

typedef struct {
    char *body;
    uint8_t bodyLength;
}RtdTextUserPayload;

typedef struct {
    uint8_t     status;
    uint8_t     language[2];
    RtdTextUserPayload rtdPayload;
}RtdTextTypeStr;


uint8_t addRtdText(RtdTextTypeStr *typeStr);

void prepareText(NDEFDataStr *data, RecordPosEnu position, const char *text);
#endif /* NDEFTEXT_H_ */

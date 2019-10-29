/*
 * Nfc.h
 *
 *  Created on: Apr 27, 2015
 *  by Mik (smkk@amel-tech.com)
 *
 * License Information
 * -------------------
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

#ifndef NFC_H_
#define NFC_H_

#include <stdint.h>
#include "nfc/NT3H1101.h"

typedef enum {
        NDEFFirstPos,
        NDEFMiddlePos,
        NDEFLastPos
} RecordPosEnu;

typedef struct {
        RecordPosEnu ndefPosition;
        uint8_t rtdType;
        uint8_t *rtdPayload;
        uint8_t rtdPayloadlength;
        void *specificRtdData;
} NDEFDataStr;

class SmeNfc {
 public:
        SmeNfc();
        virtual ~ SmeNfc();

    /**
     * Write in the NT3H a new URI Rtd of the requested type at the
     * required position. This function examines the given URI to determine
     * if it is a complete URI (contains ://) or not, in which case it
     * assumes https://www. should be prefixed.
     *
     * param:
     *      position: where add the record
     *      uri:      the address to write
     *
     */
        bool storeUri(RecordPosEnu position, const char *uri);

    /**
     * Write in the NT3H a new Text Rtd at the required position
     *
     * param:
     *      position: where add the record
     *      text:     the text to write
     *
     */
        bool storeText(RecordPosEnu position, const char *text);
};

extern SmeNfc smeNfc;
#endif                          /* NFC_H_ */

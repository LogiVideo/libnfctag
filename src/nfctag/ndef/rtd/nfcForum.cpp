/*
 * nfcForum.c
 *
 * Created: 3/23/2015 10:30:07 PM
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
 */

#include "nfcForum.h"
#include <string.h>

static void rtdHeader(uint8_t type, NDEFRecordStr *ndefRecord, uint8_t *I2CMsg) {
    ndefRecord->header |= 1;
    ndefRecord->header |= BIT_SR;
    I2CMsg[0] = ndefRecord->header;

    ndefRecord->typeLength = 1;
    I2CMsg[1] = ndefRecord->typeLength;


    ndefRecord->type.typeCode=type;
    I2CMsg[3] = ndefRecord->type.typeCode;
}


uint8_t composeRtdText(const NDEFDataStr *ndef, NDEFRecordStr *ndefRecord, uint8_t *I2CMsg) {
    uint8_t retLen;

    rtdHeader(RTD_TEXT, ndefRecord, I2CMsg);

    uint8_t payLoadLen = addRtdText(&ndefRecord->type.typePayload.text);
    memcpy(&I2CMsg[4], &ndefRecord->type.typePayload.text, payLoadLen);

    ndefRecord->payloadLength = ndef->rtdPayloadlength+payLoadLen; // added the typePayload
    I2CMsg[2]=ndefRecord->payloadLength;

    retLen = 3 + /*sizeof(ndefRecord->header) +
                   sizeof(ndefRecord->typeLength) +
                   sizeof(ndefRecord->payloadLength) +*/
            3 + //sizeof(RTDTextTypeStr)-sizeof(TextExtraDataStr)
            1   /*sizeof(ndefRecord->type.typeCode)*/;

    return retLen;
}


uint8_t composeRtdUri(const NDEFDataStr *ndef, NDEFRecordStr *ndefRecord, uint8_t *I2CMsg) {

    rtdHeader(RTD_URI, ndefRecord, I2CMsg);

    uint8_t payLoadLen = addRtdUriRecord(ndef, &ndefRecord->type.typePayload.uri);
    memcpy(&I2CMsg[4], &ndefRecord->type.typePayload.uri, payLoadLen);

    ndefRecord->payloadLength = ndef->rtdPayloadlength+payLoadLen; // added the typePayload
    I2CMsg[2]=ndefRecord->payloadLength;

    return 5;
    /* retLen = sizeof(ndefRecord->header) +
                sizeof(ndefRecord->typeLength) +
                sizeof(ndefRecord->payloadLength) +
                sizeof(1) + //ndefRecord->type.typePayload.uri.type
                sizeof(ndefRecord->type.typeCode);
     */

}

void composeNDEFMBME(bool isFirstRecord, bool isLastRecord, NDEFRecordStr *ndefRecord) {
    if (isFirstRecord)
        ndefRecord->header |= BIT_MB;
    else
        ndefRecord->header &= ~MASK_MB;

    if (isLastRecord)
        ndefRecord->header |= BIT_ME;
    else
        ndefRecord->header &= ~MASK_ME;
}

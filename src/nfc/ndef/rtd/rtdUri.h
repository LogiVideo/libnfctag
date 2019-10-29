/*
 * ndefUri.h
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

#ifndef RTDURI_H_
#define RTDURI_H_

#include "../../../SmeNfc.h"

typedef enum {
    freeForm,   //0x00     No prepending is done ... the entire URI is contained in the URI Field
    httpWWW,    //0x01     http://www.
    httpsWWW,   //0x02     https://www.
    http,       //0x03     http://
    https,      //0x04     https://
    tel,        //0x05     tel:
    mailto,     //0x06     mailto:
    ftpAnonymous,//0x07     ftp://anonymous:anonymous@
    ftpFtp,     //0x08     ftp://ftp.
    ftps,       //0x09     ftps://
    sftp,       //0x0A     sftp://
    smb,        //0x0B     smb://
    nfs,        //0x0C     nfs://
    ftp,        //0x0D     ftp://
    dav,        //0x0E     dav://
    news,       //0x0F     news:
    telnet,     //0x10     telnet://
    imap,       //0x11     imap:
    rtps,       //0x12     rtsp://
    urn,        //0x13     urn:
    /*
        0x14     pop:
        0x15     sip:
        0x16     sips:
        0x17     tftp:
        0x18     btspp://
        0x19     btl2cap://
        0x1A     btgoep://
        0x1B     tcpobex://
        0x1C     irdaobex://
        0x1D     file://
        0x1E     urn:epc:id:
        0x1F     urn:epc:tag:
        0x20     urn:epc:pat:
        0x21     urn:epc:raw:
        0x22     urn:epc:
        0x23     urn:nfc:
     */
}UriTypeE;

typedef struct {
    char     *body;
    uint8_t  bodyLength;
    void     *extraData; // herre should be stored specific URI msgs
}RtdUriUserPayload;

typedef struct {
    UriTypeE            type;
    RtdUriUserPayload   userPayload; // here should be stored specific URI msgs
}RTDUriTypeStr;

uint8_t addRtdUriRecord(const NDEFDataStr *ndef, RTDUriTypeStr *typeStr);

void prepareUri(NDEFDataStr *data, RecordPosEnu position, const char *text, const UriTypeE uritype=httpWWW);


#endif /* RTDURI_H_ */

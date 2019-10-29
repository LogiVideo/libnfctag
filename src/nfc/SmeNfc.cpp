/*
 * Nfc.cpp
 *
 *  Created on: Apr 27, 2015
 *  by Mik (smkk@amel-tech.com)
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

#include "SmeNfc.h"
#include "NT3H1101.h"
#include "ndef/rtd/rtdUri.h"
#include "ndef/rtd/rtdText.h"
#include "ndef/ndef.h"

#include <cstring>

SmeNfc::SmeNfc()
{
    // TODO Auto-generated constructor stub

}

SmeNfc::~SmeNfc()
{
    // TODO Auto-generated destructor stub
}

bool
SmeNfc::storeUri(RecordPosEnu position, const char *uri)
{
    NDEFDataStr data;
    UriTypeE type = httpsWWW;

    if (std::strstr(uri, "://") == nullptr) {
            type = freeForm;
    }
    prepareUri(&data, position, uri, type);
    return   NT3HwriteRecord( &data );
}

bool
SmeNfc::storeText(RecordPosEnu position, const char *text)
{
    NDEFDataStr data;

    prepareText(&data, position, text);
    return NT3HwriteRecord( &data );
}

uint8_t      nfcPageBuffer[NFC_PAGE_SIZE];
NT3HerrNo    errNo;

SmeNfc smeNfc;

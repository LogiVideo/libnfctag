/*
 * ndefUri.c
 *
 *  Created on: Mar 28, 2015
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
#include <stdint-gcc.h>
#include "rtdUri.h"
#include <string.h>
#include "rtdTypes.h"


    RTDUriTypeStr uri;

uint8_t addRtdUriRecord(const NDEFDataStr *ndef, RTDUriTypeStr *uriType) {


    uriType->type=((RTDUriTypeStr*) ndef->specificRtdData)->type;

    return 1;
}

void
prepareUri(NDEFDataStr *data, RecordPosEnu position, const char *text, const UriTypeE uriType)
{
        data->ndefPosition = position;
        data->rtdType = RTD_URI;
        data->rtdPayload = (uint8_t *) text;
        data->rtdPayloadlength = strlen((const char *)text);;

        uri.type = uriType;
        data->specificRtdData = &uri;
}


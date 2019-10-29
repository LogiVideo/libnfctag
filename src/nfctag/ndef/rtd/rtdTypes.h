/*
 * ndefTypes.h
 *
 *  Created on: Mar 24, 2015
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
 *
 */

#ifndef RTDTYPES_H_
#define RTDTYPES_H_

#include "rtdText.h"
#include "rtdUri.h"


#define RTD_TEXT 'T'
#define RTD_URI  'U'

typedef union {
	RtdTextTypeStr text;
	RTDUriTypeStr uri;
} RTDTypeUnion;

typedef struct {
	uint8_t typeCode;
	RTDTypeUnion typePayload;
}RTDTypeStr;

#endif /* RTDTYPES_H_ */

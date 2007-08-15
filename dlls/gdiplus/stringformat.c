/*
 *
 * Copyright (C) 2007 Google (Evan Stade)
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

#include <stdarg.h>

#include "windef.h"
#include "winbase.h"
#include "wingdi.h"
#include "winnls.h"

#include "objbase.h"

#include "gdiplus.h"
#include "gdiplus_private.h"

GpStatus WINGDIPAPI GdipCreateStringFormat(INT attr, LANGID lang,
    GpStringFormat **format)
{
    if(!format)
        return InvalidParameter;

    *format = GdipAlloc(sizeof(GpStringFormat));
    if(!*format)   return OutOfMemory;

    (*format)->attr = attr;
    (*format)->lang = lang;

    return Ok;
}

GpStatus WINGDIPAPI GdipGetStringFormatAlign(GpStringFormat *format,
    StringAlignment *align)
{
    if(!format || !align)
        return InvalidParameter;

    *align = format->align;

    return Ok;
}

GpStatus WINGDIPAPI GdipGetStringFormatTrimming(GpStringFormat *format,
    StringTrimming *trimming)
{
    if(!format || !trimming)
        return InvalidParameter;

    *trimming = format->trimming;

    return Ok;
}

GpStatus WINGDIPAPI GdipSetStringFormatAlign(GpStringFormat *format,
    StringAlignment align)
{
    if(!format)
        return InvalidParameter;

    format->align = align;

    return Ok;
}

GpStatus WINGDIPAPI GdipSetStringFormatTrimming(GpStringFormat *format,
    StringTrimming trimming)
{
    if(!format)
        return InvalidParameter;

    format->trimming = trimming;

    return Ok;
}

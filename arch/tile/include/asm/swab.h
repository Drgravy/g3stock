/*
 * Copyright 2010 Tilera Corporation. All Rights Reserved.
 *
 *   This program is free software; you can redistribute it and/or
 *   modify it under the terms of the GNU General Public License
 *   as published by the Free Software Foundation, version 2.
 *
 *   This program is distributed in the hope that it will be useful, but
 *   WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE, GOOD TITLE or
 *   NON INFRINGEMENT.  See the GNU General Public License for
 *   more details.
 */

#ifndef _ASM_TILE_SWAB_H
#define _ASM_TILE_SWAB_H

/*                                                         */
#define __arch_swab32(x) __builtin_bswap32(x)
#define __arch_swab64(x) __builtin_bswap64(x)
#define __arch_swab16(x) (__builtin_bswap32(x) >> 16)

#endif /*                  */

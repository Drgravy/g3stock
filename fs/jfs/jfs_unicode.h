/*
 *   Copyright (C) International Business Machines Corp., 2000-2002
 *   Portions Copyright (C) Christoph Hellwig, 2001-2002
 *
 *   This program is free software;  you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY;  without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See
 *   the GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program;  if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */
#ifndef _H_JFS_UNICODE
#define _H_JFS_UNICODE

#include <linux/slab.h>
#include <asm/byteorder.h>
#include "jfs_types.h"

typedef struct {
	wchar_t start;
	wchar_t end;
	signed char *table;
} UNICASERANGE;

extern signed char UniUpperTable[512];
extern UNICASERANGE UniUpperRange[];
extern int get_UCSname(struct component_name *, struct dentry *);
extern int jfs_strfromUCS_le(char *, const __le16 *, int, struct nls_table *);

#define free_UCSname(COMP) kfree((COMP)->name)

/*
                            
 */
static inline wchar_t *UniStrcpy(wchar_t * ucs1, const wchar_t * ucs2)
{
	wchar_t *anchor = ucs1;	/*                                 */

	while ((*ucs1++ = *ucs2++));
	return anchor;
}



/*
                                                   
 */
static inline __le16 *UniStrncpy_le(__le16 * ucs1, const __le16 * ucs2,
				  size_t n)
{
	__le16 *anchor = ucs1;

	while (n-- && *ucs2)	/*                  */
		*ucs1++ = *ucs2++;

	n++;
	while (n--)		/*                */
		*ucs1++ = 0;
	return anchor;
}

/*
                                                                          
 */
static inline int UniStrncmp_le(const wchar_t * ucs1, const __le16 * ucs2,
				size_t n)
{
	if (!n)
		return 0;	/*                        */
	while ((*ucs1 == __le16_to_cpu(*ucs2)) && *ucs1 && --n) {
		ucs1++;
		ucs2++;
	}
	return (int) *ucs1 - (int) __le16_to_cpu(*ucs2);
}

/*
                                                                          
 */
static inline __le16 *UniStrncpy_to_le(__le16 * ucs1, const wchar_t * ucs2,
				       size_t n)
{
	__le16 *anchor = ucs1;

	while (n-- && *ucs2)	/*                  */
		*ucs1++ = cpu_to_le16(*ucs2++);

	n++;
	while (n--)		/*                */
		*ucs1++ = 0;
	return anchor;
}

/*
                                                                              
 */
static inline wchar_t *UniStrncpy_from_le(wchar_t * ucs1, const __le16 * ucs2,
					  size_t n)
{
	wchar_t *anchor = ucs1;

	while (n-- && *ucs2)	/*                  */
		*ucs1++ = __le16_to_cpu(*ucs2++);

	n++;
	while (n--)		/*                */
		*ucs1++ = 0;
	return anchor;
}

/*
                                                         
 */
static inline wchar_t UniToupper(wchar_t uc)
{
	UNICASERANGE *rp;

	if (uc < sizeof(UniUpperTable)) {	/*                  */
		return uc + UniUpperTable[uc];	/*                 */
	} else {
		rp = UniUpperRange;	/*                  */
		while (rp->start) {
			if (uc < rp->start)	/*                       */
				return uc;	/*                   */
			if (uc <= rp->end)	/*          */
				return uc + rp->table[uc - rp->start];
			rp++;	/*                */
		}
	}
	return uc;		/*                 */
}


/*
                                          
 */
static inline wchar_t *UniStrupr(wchar_t * upin)
{
	wchar_t *up;

	up = upin;
	while (*up) {		/*                    */
		*up = UniToupper(*up);
		up++;
	}
	return upin;		/*                      */
}

#endif				/*                 */

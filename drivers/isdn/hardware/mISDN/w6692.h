/*
 * Winbond W6692 specific defines
 *
 * Author       Karsten Keil <keil@isdn4linux.de>
 *		based on the w6692 I4L driver from Petr Novak <petr.novak@i.cz>
 *
 * Copyright 2009  by Karsten Keil <keil@isdn4linux.de>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 */

/*                                   */

#define W_D_RFIFO	0x00	/*   */
#define W_D_XFIFO	0x04	/*   */
#define W_D_CMDR	0x08	/*   */
#define W_D_MODE	0x0c	/*     */
#define W_D_TIMR	0x10	/*     */
#define W_ISTA		0x14	/*       */
#define W_IMASK		0x18	/*     */
#define W_D_EXIR	0x1c	/*       */
#define W_D_EXIM	0x20	/*     */
#define W_D_STAR	0x24	/*   */
#define W_D_RSTA	0x28	/*   */
#define W_D_SAM		0x2c	/*     */
#define W_D_SAP1	0x30	/*     */
#define W_D_SAP2	0x34	/*     */
#define W_D_TAM		0x38	/*     */
#define W_D_TEI1	0x3c	/*     */
#define W_D_TEI2	0x40	/*     */
#define W_D_RBCH	0x44	/*   */
#define W_D_RBCL	0x48	/*   */
#define W_TIMR2		0x4c	/*   */
#define W_L1_RC		0x50	/*     */
#define W_D_CTL		0x54	/*     */
#define W_CIR		0x58	/*   */
#define W_CIX		0x5c	/*   */
#define W_SQR		0x60	/*   */
#define W_SQX		0x64	/*   */
#define W_PCTL		0x68	/*     */
#define W_MOR		0x6c	/*   */
#define W_MOX		0x70	/*     */
#define W_MOSR		0x74	/*       */
#define W_MOCR		0x78	/*     */
#define W_GCR		0x7c	/*     */

#define	W_B_RFIFO	0x80	/*   */
#define	W_B_XFIFO	0x84	/*   */
#define	W_B_CMDR	0x88	/*   */
#define	W_B_MODE	0x8c	/*     */
#define	W_B_EXIR	0x90	/*       */
#define	W_B_EXIM	0x94	/*     */
#define	W_B_STAR	0x98	/*   */
#define	W_B_ADM1	0x9c	/*     */
#define	W_B_ADM2	0xa0	/*     */
#define	W_B_ADR1	0xa4	/*     */
#define	W_B_ADR2	0xa8	/*     */
#define	W_B_RBCL	0xac	/*   */
#define	W_B_RBCH	0xb0	/*   */

#define W_XADDR		0xf4	/*     */
#define W_XDATA		0xf8	/*     */
#define W_EPCTL		0xfc	/*   */

/*                     */

#define	W_D_CMDR_XRST	0x01
#define	W_D_CMDR_XME	0x02
#define	W_D_CMDR_XMS	0x08
#define	W_D_CMDR_STT	0x10
#define	W_D_CMDR_RRST	0x40
#define	W_D_CMDR_RACK	0x80

#define	W_D_MODE_RLP	0x01
#define	W_D_MODE_DLP	0x02
#define	W_D_MODE_MFD	0x04
#define	W_D_MODE_TEE	0x08
#define	W_D_MODE_TMS	0x10
#define	W_D_MODE_RACT	0x40
#define	W_D_MODE_MMS	0x80

#define W_INT_B2_EXI	0x01
#define W_INT_B1_EXI	0x02
#define W_INT_D_EXI	0x04
#define W_INT_XINT0	0x08
#define W_INT_XINT1	0x10
#define W_INT_D_XFR	0x20
#define W_INT_D_RME	0x40
#define W_INT_D_RMR	0x80

#define W_D_EXI_WEXP	0x01
#define W_D_EXI_TEXP	0x02
#define W_D_EXI_ISC	0x04
#define W_D_EXI_MOC	0x08
#define W_D_EXI_TIN2	0x10
#define W_D_EXI_XCOL	0x20
#define W_D_EXI_XDUN	0x40
#define W_D_EXI_RDOV	0x80

#define	W_D_STAR_DRDY	0x10
#define	W_D_STAR_XBZ	0x20
#define	W_D_STAR_XDOW	0x80

#define W_D_RSTA_RMB	0x10
#define W_D_RSTA_CRCE	0x20
#define W_D_RSTA_RDOV	0x40

#define W_D_CTL_SRST	0x20

#define W_CIR_SCC	0x80
#define W_CIR_ICC	0x40
#define W_CIR_COD_MASK	0x0f

#define W_PCTL_PCX	0x01
#define W_PCTL_XMODE	0x02
#define W_PCTL_OE0	0x04
#define W_PCTL_OE1	0x08
#define W_PCTL_OE2	0x10
#define W_PCTL_OE3	0x20
#define W_PCTL_OE4	0x40
#define W_PCTL_OE5	0x80

#define	W_B_CMDR_XRST	0x01
#define	W_B_CMDR_XME	0x02
#define	W_B_CMDR_XMS	0x04
#define	W_B_CMDR_RACT	0x20
#define	W_B_CMDR_RRST	0x40
#define	W_B_CMDR_RACK	0x80

#define	W_B_MODE_FTS0	0x01
#define	W_B_MODE_FTS1	0x02
#define	W_B_MODE_SW56	0x04
#define	W_B_MODE_BSW0	0x08
#define	W_B_MODE_BSW1	0x10
#define	W_B_MODE_EPCM	0x20
#define	W_B_MODE_ITF	0x40
#define	W_B_MODE_MMS	0x80

#define	W_B_EXI_XDUN	0x01
#define	W_B_EXI_XFR	0x02
#define	W_B_EXI_RDOV	0x10
#define	W_B_EXI_RME	0x20
#define	W_B_EXI_RMR	0x40

#define	W_B_STAR_XBZ	0x01
#define	W_B_STAR_XDOW	0x04
#define	W_B_STAR_RMB	0x10
#define	W_B_STAR_CRCE	0x20
#define	W_B_STAR_RDOV	0x40

#define	W_B_RBCH_LOV	0x20

/*                       */

#define	W_L1CMD_ECK	0x00
#define W_L1CMD_RST	0x01
#define W_L1CMD_SCP	0x04
#define W_L1CMD_SSP	0x02
#define W_L1CMD_AR8	0x08
#define W_L1CMD_AR10	0x09
#define W_L1CMD_EAL	0x0a
#define W_L1CMD_DRC	0x0f

/*                          */

#define W_L1IND_CE	0x07
#define W_L1IND_DRD	0x00
#define W_L1IND_LD	0x04
#define W_L1IND_ARD	0x08
#define W_L1IND_TI	0x0a
#define W_L1IND_ATI	0x0b
#define W_L1IND_AI8	0x0c
#define W_L1IND_AI10	0x0d
#define W_L1IND_CD	0x0f

/*                 */
#define W_D_FIFO_THRESH	64
#define W_B_FIFO_THRESH	64

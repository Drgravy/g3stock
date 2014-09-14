/**
 * Marvell BT-over-SDIO driver: SDIO interface related definitions
 *
 * Copyright (C) 2009, Marvell International Ltd.
 *
 * This software file (the "File") is distributed by Marvell International
 * Ltd. under the terms of the GNU General Public License Version 2, June 1991
 * (the "License").  You may use, redistribute and/or modify this File in
 * accordance with the terms and conditions of the License, a copy of which
 * is available by writing to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA or on the
 * worldwide web at http://www.gnu.org/licenses/old-licenses/gpl-2.0.txt.
 *
 *
 * THE FILE IS DISTRIBUTED AS-IS, WITHOUT WARRANTY OF ANY KIND, AND THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE
 * ARE EXPRESSLY DISCLAIMED.  The License provides additional details about
 * this warranty disclaimer.
 *
 **/

#define SDIO_HEADER_LEN			4

/*                                                                        */
/*                                     */
#define SDIO_BLOCK_SIZE			64

/*                                        */
#define FIRMWARE_TRANSFER_NBLOCK	2

/*                                      */
#define FW_EXTRA_LEN			36

#define MRVDRV_SIZE_OF_CMD_BUFFER       (2 * 1024)

#define MRVDRV_BT_RX_PACKET_BUFFER_SIZE \
	(HCI_MAX_FRAME_SIZE + FW_EXTRA_LEN)

#define ALLOC_BUF_SIZE	(((max_t (int, MRVDRV_BT_RX_PACKET_BUFFER_SIZE, \
			MRVDRV_SIZE_OF_CMD_BUFFER) + SDIO_HEADER_LEN \
			+ SDIO_BLOCK_SIZE - 1) / SDIO_BLOCK_SIZE) \
			* SDIO_BLOCK_SIZE)

/*                                                    */
#define MAX_POLL_TRIES			100

/*                                 */
#define MAX_WRITE_IOMEM_RETRY		2

/*                   */
#define HOST_POWER_UP				BIT(1)
#define HOST_CMD53_FIN				BIT(2)

#define HIM_DISABLE				0xff
#define HIM_ENABLE				(BIT(0) | BIT(1))

#define UP_LD_HOST_INT_STATUS			BIT(0)
#define DN_LD_HOST_INT_STATUS			BIT(1)

#define DN_LD_CARD_RDY				BIT(0)
#define CARD_IO_READY				BIT(3)

#define FIRMWARE_READY				0xfedc


struct btmrvl_sdio_card_reg {
	u8 cfg;
	u8 host_int_mask;
	u8 host_intstatus;
	u8 card_status;
	u8 sq_read_base_addr_a0;
	u8 sq_read_base_addr_a1;
	u8 card_revision;
	u8 card_fw_status0;
	u8 card_fw_status1;
	u8 card_rx_len;
	u8 card_rx_unit;
	u8 io_port_0;
	u8 io_port_1;
	u8 io_port_2;
};

struct btmrvl_sdio_card {
	struct sdio_func *func;
	u32 ioport;
	const char *helper;
	const char *firmware;
	const struct btmrvl_sdio_card_reg *reg;
	u16 sd_blksz_fw_dl;
	u8 rx_unit;
	struct btmrvl_private *priv;
};

struct btmrvl_sdio_device {
	const char *helper;
	const char *firmware;
	const struct btmrvl_sdio_card_reg *reg;
	u16 sd_blksz_fw_dl;
};


/*                                 */
#define BTSDIO_DMA_ALIGN		8

/*                                  */
#define ALIGN_SZ(p, a)	\
	(((p) + ((a) - 1)) & ~((a) - 1))

/*                                     */
#define ALIGN_ADDR(p, a)	\
	((((unsigned long)(p)) + (((unsigned long)(a)) - 1)) & \
					~(((unsigned long)(a)) - 1))

/*
 * Copyright (c) 2005-2010 Brocade Communications Systems, Inc.
 * All rights reserved
 * www.brocade.com
 *
 * Linux driver for Brocade Fibre Channel Host Bus Adapter.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License (GPL) Version 2 as
 * published by the Free Software Foundation
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 */

/*
                                                                
 */

#ifndef __BFI_REG_H__
#define __BFI_REG_H__

#define HOSTFN0_INT_STATUS		0x00014000	/*       */
#define HOSTFN1_INT_STATUS		0x00014100	/*       */
#define HOSTFN2_INT_STATUS		0x00014300	/*     */
#define HOSTFN3_INT_STATUS		0x00014400	/*     */
#define HOSTFN0_INT_MSK			0x00014004	/*       */
#define HOSTFN1_INT_MSK			0x00014104	/*       */
#define HOSTFN2_INT_MSK			0x00014304	/*     */
#define HOSTFN3_INT_MSK			0x00014404	/*     */

#define HOST_PAGE_NUM_FN0		0x00014008	/*       */
#define HOST_PAGE_NUM_FN1		0x00014108	/*       */
#define HOST_PAGE_NUM_FN2		0x00014308	/*     */
#define HOST_PAGE_NUM_FN3		0x00014408	/*     */

#define APP_PLL_LCLK_CTL_REG		0x00014204	/*       */
#define __P_LCLK_PLL_LOCK		0x80000000
#define __APP_PLL_LCLK_SRAM_USE_100MHZ	0x00100000
#define __APP_PLL_LCLK_RESET_TIMER_MK	0x000e0000
#define __APP_PLL_LCLK_RESET_TIMER_SH	17
#define __APP_PLL_LCLK_RESET_TIMER(_v)	((_v) << __APP_PLL_LCLK_RESET_TIMER_SH)
#define __APP_PLL_LCLK_LOGIC_SOFT_RESET	0x00010000
#define __APP_PLL_LCLK_CNTLMT0_1_MK	0x0000c000
#define __APP_PLL_LCLK_CNTLMT0_1_SH	14
#define __APP_PLL_LCLK_CNTLMT0_1(_v)	((_v) << __APP_PLL_LCLK_CNTLMT0_1_SH)
#define __APP_PLL_LCLK_JITLMT0_1_MK	0x00003000
#define __APP_PLL_LCLK_JITLMT0_1_SH	12
#define __APP_PLL_LCLK_JITLMT0_1(_v)	((_v) << __APP_PLL_LCLK_JITLMT0_1_SH)
#define __APP_PLL_LCLK_HREF		0x00000800
#define __APP_PLL_LCLK_HDIV		0x00000400
#define __APP_PLL_LCLK_P0_1_MK		0x00000300
#define __APP_PLL_LCLK_P0_1_SH		8
#define __APP_PLL_LCLK_P0_1(_v)		((_v) << __APP_PLL_LCLK_P0_1_SH)
#define __APP_PLL_LCLK_Z0_2_MK		0x000000e0
#define __APP_PLL_LCLK_Z0_2_SH		5
#define __APP_PLL_LCLK_Z0_2(_v)		((_v) << __APP_PLL_LCLK_Z0_2_SH)
#define __APP_PLL_LCLK_RSEL200500	0x00000010
#define __APP_PLL_LCLK_ENARST		0x00000008
#define __APP_PLL_LCLK_BYPASS		0x00000004
#define __APP_PLL_LCLK_LRESETN		0x00000002
#define __APP_PLL_LCLK_ENABLE		0x00000001
#define APP_PLL_SCLK_CTL_REG		0x00014208	/*       */
#define __P_SCLK_PLL_LOCK		0x80000000
#define __APP_PLL_SCLK_RESET_TIMER_MK	0x000e0000
#define __APP_PLL_SCLK_RESET_TIMER_SH	17
#define __APP_PLL_SCLK_RESET_TIMER(_v)	((_v) << __APP_PLL_SCLK_RESET_TIMER_SH)
#define __APP_PLL_SCLK_LOGIC_SOFT_RESET	0x00010000
#define __APP_PLL_SCLK_CNTLMT0_1_MK	0x0000c000
#define __APP_PLL_SCLK_CNTLMT0_1_SH	14
#define __APP_PLL_SCLK_CNTLMT0_1(_v)	((_v) << __APP_PLL_SCLK_CNTLMT0_1_SH)
#define __APP_PLL_SCLK_JITLMT0_1_MK	0x00003000
#define __APP_PLL_SCLK_JITLMT0_1_SH	12
#define __APP_PLL_SCLK_JITLMT0_1(_v)	((_v) << __APP_PLL_SCLK_JITLMT0_1_SH)
#define __APP_PLL_SCLK_HREF		0x00000800
#define __APP_PLL_SCLK_HDIV		0x00000400
#define __APP_PLL_SCLK_P0_1_MK		0x00000300
#define __APP_PLL_SCLK_P0_1_SH		8
#define __APP_PLL_SCLK_P0_1(_v)		((_v) << __APP_PLL_SCLK_P0_1_SH)
#define __APP_PLL_SCLK_Z0_2_MK		0x000000e0
#define __APP_PLL_SCLK_Z0_2_SH		5
#define __APP_PLL_SCLK_Z0_2(_v)		((_v) << __APP_PLL_SCLK_Z0_2_SH)
#define __APP_PLL_SCLK_RSEL200500	0x00000010
#define __APP_PLL_SCLK_ENARST		0x00000008
#define __APP_PLL_SCLK_BYPASS		0x00000004
#define __APP_PLL_SCLK_LRESETN		0x00000002
#define __APP_PLL_SCLK_ENABLE		0x00000001
#define __ENABLE_MAC_AHB_1		0x00800000	/*     */
#define __ENABLE_MAC_AHB_0		0x00400000	/*     */
#define __ENABLE_MAC_1			0x00200000	/*     */
#define __ENABLE_MAC_0			0x00100000	/*     */

#define HOST_SEM0_REG			0x00014230	/*       */
#define HOST_SEM1_REG			0x00014234	/*       */
#define HOST_SEM2_REG			0x00014238	/*       */
#define HOST_SEM3_REG			0x0001423c	/*       */
#define HOST_SEM4_REG			0x00014610	/*       */
#define HOST_SEM5_REG			0x00014614	/*       */
#define HOST_SEM6_REG			0x00014618	/*       */
#define HOST_SEM7_REG			0x0001461c	/*       */
#define HOST_SEM0_INFO_REG		0x00014240	/*       */
#define HOST_SEM1_INFO_REG		0x00014244	/*       */
#define HOST_SEM2_INFO_REG		0x00014248	/*       */
#define HOST_SEM3_INFO_REG		0x0001424c	/*       */
#define HOST_SEM4_INFO_REG		0x00014620	/*       */
#define HOST_SEM5_INFO_REG		0x00014624	/*       */
#define HOST_SEM6_INFO_REG		0x00014628	/*       */
#define HOST_SEM7_INFO_REG		0x0001462c	/*       */

#define HOSTFN0_LPU0_CMD_STAT		0x00019000	/*       */
#define HOSTFN0_LPU1_CMD_STAT		0x00019004	/*       */
#define HOSTFN1_LPU0_CMD_STAT		0x00019010	/*       */
#define HOSTFN1_LPU1_CMD_STAT		0x00019014	/*       */
#define HOSTFN2_LPU0_CMD_STAT		0x00019150	/*     */
#define HOSTFN2_LPU1_CMD_STAT		0x00019154	/*     */
#define HOSTFN3_LPU0_CMD_STAT		0x00019160	/*     */
#define HOSTFN3_LPU1_CMD_STAT		0x00019164	/*     */
#define LPU0_HOSTFN0_CMD_STAT		0x00019008	/*       */
#define LPU1_HOSTFN0_CMD_STAT		0x0001900c	/*       */
#define LPU0_HOSTFN1_CMD_STAT		0x00019018	/*       */
#define LPU1_HOSTFN1_CMD_STAT		0x0001901c	/*       */
#define LPU0_HOSTFN2_CMD_STAT		0x00019158	/*     */
#define LPU1_HOSTFN2_CMD_STAT		0x0001915c	/*     */
#define LPU0_HOSTFN3_CMD_STAT		0x00019168	/*     */
#define LPU1_HOSTFN3_CMD_STAT		0x0001916c	/*     */

#define PSS_CTL_REG			0x00018800	/*       */
#define __PSS_I2C_CLK_DIV_MK		0x007f0000
#define __PSS_I2C_CLK_DIV_SH		16
#define __PSS_I2C_CLK_DIV(_v)		((_v) << __PSS_I2C_CLK_DIV_SH)
#define __PSS_LMEM_INIT_DONE		0x00001000
#define __PSS_LMEM_RESET		0x00000200
#define __PSS_LMEM_INIT_EN		0x00000100
#define __PSS_LPU1_RESET		0x00000002
#define __PSS_LPU0_RESET		0x00000001
#define PSS_ERR_STATUS_REG		0x00018810	/*       */
#define ERR_SET_REG			0x00018818	/*       */
#define PSS_GPIO_OUT_REG		0x000188c0	/*       */
#define __PSS_GPIO_OUT_REG		0x00000fff
#define PSS_GPIO_OE_REG			0x000188c8	/*       */
#define __PSS_GPIO_OE_REG		0x000000ff

#define HOSTFN0_LPU_MBOX0_0		0x00019200	/*       */
#define HOSTFN1_LPU_MBOX0_8		0x00019260	/*       */
#define LPU_HOSTFN0_MBOX0_0		0x00019280	/*       */
#define LPU_HOSTFN1_MBOX0_8		0x000192e0	/*       */
#define HOSTFN2_LPU_MBOX0_0		0x00019400	/*     */
#define HOSTFN3_LPU_MBOX0_8		0x00019460	/*     */
#define LPU_HOSTFN2_MBOX0_0		0x00019480	/*     */
#define LPU_HOSTFN3_MBOX0_8		0x000194e0	/*     */

#define HOST_MSIX_ERR_INDEX_FN0		0x0001400c	/*     */
#define HOST_MSIX_ERR_INDEX_FN1		0x0001410c	/*     */
#define HOST_MSIX_ERR_INDEX_FN2		0x0001430c	/*     */
#define HOST_MSIX_ERR_INDEX_FN3		0x0001440c	/*     */

#define MBIST_CTL_REG			0x00014220	/*     */
#define __EDRAM_BISTR_START		0x00000004
#define MBIST_STAT_REG			0x00014224	/*     */
#define ETH_MAC_SER_REG			0x00014288	/*     */
#define __APP_EMS_CKBUFAMPIN		0x00000020
#define __APP_EMS_REFCLKSEL		0x00000010
#define __APP_EMS_CMLCKSEL		0x00000008
#define __APP_EMS_REFCKBUFEN2		0x00000004
#define __APP_EMS_REFCKBUFEN1		0x00000002
#define __APP_EMS_CHANNEL_SEL		0x00000001
#define FNC_PERS_REG			0x00014604	/*     */
#define __F3_FUNCTION_ACTIVE		0x80000000
#define __F3_FUNCTION_MODE		0x40000000
#define __F3_PORT_MAP_MK		0x30000000
#define __F3_PORT_MAP_SH		28
#define __F3_PORT_MAP(_v)		((_v) << __F3_PORT_MAP_SH)
#define __F3_VM_MODE			0x08000000
#define __F3_INTX_STATUS_MK		0x07000000
#define __F3_INTX_STATUS_SH		24
#define __F3_INTX_STATUS(_v)		((_v) << __F3_INTX_STATUS_SH)
#define __F2_FUNCTION_ACTIVE		0x00800000
#define __F2_FUNCTION_MODE		0x00400000
#define __F2_PORT_MAP_MK		0x00300000
#define __F2_PORT_MAP_SH		20
#define __F2_PORT_MAP(_v)		((_v) << __F2_PORT_MAP_SH)
#define __F2_VM_MODE			0x00080000
#define __F2_INTX_STATUS_MK		0x00070000
#define __F2_INTX_STATUS_SH		16
#define __F2_INTX_STATUS(_v)		((_v) << __F2_INTX_STATUS_SH)
#define __F1_FUNCTION_ACTIVE		0x00008000
#define __F1_FUNCTION_MODE		0x00004000
#define __F1_PORT_MAP_MK		0x00003000
#define __F1_PORT_MAP_SH		12
#define __F1_PORT_MAP(_v)		((_v) << __F1_PORT_MAP_SH)
#define __F1_VM_MODE			0x00000800
#define __F1_INTX_STATUS_MK		0x00000700
#define __F1_INTX_STATUS_SH		8
#define __F1_INTX_STATUS(_v)		((_v) << __F1_INTX_STATUS_SH)
#define __F0_FUNCTION_ACTIVE		0x00000080
#define __F0_FUNCTION_MODE		0x00000040
#define __F0_PORT_MAP_MK		0x00000030
#define __F0_PORT_MAP_SH		4
#define __F0_PORT_MAP(_v)		((_v) << __F0_PORT_MAP_SH)
#define __F0_VM_MODE			0x00000008
#define __F0_INTX_STATUS		0x00000007
enum {
	__F0_INTX_STATUS_MSIX = 0x0,
	__F0_INTX_STATUS_INTA = 0x1,
	__F0_INTX_STATUS_INTB = 0x2,
	__F0_INTX_STATUS_INTC = 0x3,
	__F0_INTX_STATUS_INTD = 0x4,
};

#define OP_MODE				0x0001460c	/*     */
#define __APP_ETH_CLK_LOWSPEED		0x00000004
#define __GLOBAL_CORECLK_HALFSPEED	0x00000002
#define __GLOBAL_FCOE_MODE		0x00000001
#define FW_INIT_HALT_P0			0x000191ac	/*     */
#define __FW_INIT_HALT_P		0x00000001
#define FW_INIT_HALT_P1			0x000191bc	/*     */
#define PMM_1T_RESET_REG_P0		0x0002381c	/*     */
#define __PMM_1T_RESET_P		0x00000001
#define PMM_1T_RESET_REG_P1		0x00023c1c	/*     */

/* 
                              
 */
#define CT2_PCI_CPQ_BASE		0x00030000
#define CT2_PCI_APP_BASE		0x00030100
#define CT2_PCI_ETH_BASE		0x00030400

/*
                      
 */
#define CT2_HOSTFN_INT_STATUS		(CT2_PCI_APP_BASE + 0x00)
#define CT2_HOSTFN_INTR_MASK		(CT2_PCI_APP_BASE + 0x04)
#define CT2_HOSTFN_PERSONALITY0		(CT2_PCI_APP_BASE + 0x08)
#define __PME_STATUS_			0x00200000
#define __PF_VF_BAR_SIZE_MODE__MK	0x00180000
#define __PF_VF_BAR_SIZE_MODE__SH	19
#define __PF_VF_BAR_SIZE_MODE_(_v)	((_v) << __PF_VF_BAR_SIZE_MODE__SH)
#define __FC_LL_PORT_MAP__MK		0x00060000
#define __FC_LL_PORT_MAP__SH		17
#define __FC_LL_PORT_MAP_(_v)		((_v) << __FC_LL_PORT_MAP__SH)
#define __PF_VF_ACTIVE_			0x00010000
#define __PF_VF_CFG_RDY_		0x00008000
#define __PF_VF_ENABLE_			0x00004000
#define __PF_DRIVER_ACTIVE_		0x00002000
#define __PF_PME_SEND_ENABLE_		0x00001000
#define __PF_EXROM_OFFSET__MK		0x00000ff0
#define __PF_EXROM_OFFSET__SH		4
#define __PF_EXROM_OFFSET_(_v)		((_v) << __PF_EXROM_OFFSET__SH)
#define __FC_LL_MODE_			0x00000008
#define __PF_INTX_PIN_			0x00000007
#define CT2_HOSTFN_PERSONALITY1		(CT2_PCI_APP_BASE + 0x0C)
#define __PF_NUM_QUEUES1__MK		0xff000000
#define __PF_NUM_QUEUES1__SH		24
#define __PF_NUM_QUEUES1_(_v)		((_v) << __PF_NUM_QUEUES1__SH)
#define __PF_VF_QUE_OFFSET1__MK		0x00ff0000
#define __PF_VF_QUE_OFFSET1__SH		16
#define __PF_VF_QUE_OFFSET1_(_v)	((_v) << __PF_VF_QUE_OFFSET1__SH)
#define __PF_VF_NUM_QUEUES__MK		0x0000ff00
#define __PF_VF_NUM_QUEUES__SH		8
#define __PF_VF_NUM_QUEUES_(_v)		((_v) << __PF_VF_NUM_QUEUES__SH)
#define __PF_VF_QUE_OFFSET_		0x000000ff
#define CT2_HOSTFN_PAGE_NUM		(CT2_PCI_APP_BASE + 0x18)
#define CT2_HOSTFN_MSIX_VT_INDEX_MBOX_ERR	(CT2_PCI_APP_BASE + 0x38)

/*
                                 
 */
#define CT2_HOSTFN_LPU0_MBOX0		(CT2_PCI_CPQ_BASE + 0x00)
#define CT2_HOSTFN_LPU1_MBOX0		(CT2_PCI_CPQ_BASE + 0x20)
#define CT2_LPU0_HOSTFN_MBOX0		(CT2_PCI_CPQ_BASE + 0x40)
#define CT2_LPU1_HOSTFN_MBOX0		(CT2_PCI_CPQ_BASE + 0x60)
#define CT2_HOSTFN_LPU0_CMD_STAT	(CT2_PCI_CPQ_BASE + 0x80)
#define CT2_HOSTFN_LPU1_CMD_STAT	(CT2_PCI_CPQ_BASE + 0x84)
#define CT2_LPU0_HOSTFN_CMD_STAT	(CT2_PCI_CPQ_BASE + 0x88)
#define CT2_LPU1_HOSTFN_CMD_STAT	(CT2_PCI_CPQ_BASE + 0x8c)
#define CT2_HOSTFN_LPU0_READ_STAT	(CT2_PCI_CPQ_BASE + 0x90)
#define CT2_HOSTFN_LPU1_READ_STAT	(CT2_PCI_CPQ_BASE + 0x94)
#define CT2_LPU0_HOSTFN_MBOX0_MSK	(CT2_PCI_CPQ_BASE + 0x98)
#define CT2_LPU1_HOSTFN_MBOX0_MSK	(CT2_PCI_CPQ_BASE + 0x9C)
#define CT2_HOST_SEM0_REG		0x000148f0
#define CT2_HOST_SEM1_REG		0x000148f4
#define CT2_HOST_SEM2_REG		0x000148f8
#define CT2_HOST_SEM3_REG		0x000148fc
#define CT2_HOST_SEM4_REG		0x00014900
#define CT2_HOST_SEM5_REG		0x00014904
#define CT2_HOST_SEM6_REG		0x00014908
#define CT2_HOST_SEM7_REG		0x0001490c
#define CT2_HOST_SEM0_INFO_REG		0x000148b0
#define CT2_HOST_SEM1_INFO_REG		0x000148b4
#define CT2_HOST_SEM2_INFO_REG		0x000148b8
#define CT2_HOST_SEM3_INFO_REG		0x000148bc
#define CT2_HOST_SEM4_INFO_REG		0x000148c0
#define CT2_HOST_SEM5_INFO_REG		0x000148c4
#define CT2_HOST_SEM6_INFO_REG		0x000148c8
#define CT2_HOST_SEM7_INFO_REG		0x000148cc

#define CT2_APP_PLL_LCLK_CTL_REG	0x00014808
#define __APP_LPUCLK_HALFSPEED		0x40000000
#define __APP_PLL_LCLK_LOAD		0x20000000
#define __APP_PLL_LCLK_FBCNT_MK		0x1fe00000
#define __APP_PLL_LCLK_FBCNT_SH		21
#define __APP_PLL_LCLK_FBCNT(_v)	((_v) << __APP_PLL_SCLK_FBCNT_SH)
enum {
	__APP_PLL_LCLK_FBCNT_425_MHZ = 6,
	__APP_PLL_LCLK_FBCNT_468_MHZ = 4,
};
#define __APP_PLL_LCLK_EXTFB		0x00000800
#define __APP_PLL_LCLK_ENOUTS		0x00000400
#define __APP_PLL_LCLK_RATE		0x00000010
#define CT2_APP_PLL_SCLK_CTL_REG	0x0001480c
#define __P_SCLK_PLL_LOCK		0x80000000
#define __APP_PLL_SCLK_REFCLK_SEL	0x40000000
#define __APP_PLL_SCLK_CLK_DIV2		0x20000000
#define __APP_PLL_SCLK_LOAD		0x10000000
#define __APP_PLL_SCLK_FBCNT_MK		0x0ff00000
#define __APP_PLL_SCLK_FBCNT_SH		20
#define __APP_PLL_SCLK_FBCNT(_v)	((_v) << __APP_PLL_SCLK_FBCNT_SH)
enum {
	__APP_PLL_SCLK_FBCNT_NORM = 6,
	__APP_PLL_SCLK_FBCNT_10G_FC = 10,
};
#define __APP_PLL_SCLK_EXTFB		0x00000800
#define __APP_PLL_SCLK_ENOUTS		0x00000400
#define __APP_PLL_SCLK_RATE		0x00000010
#define CT2_PCIE_MISC_REG		0x00014804
#define __ETH_CLK_ENABLE_PORT1		0x00000010
#define CT2_CHIP_MISC_PRG		0x000148a4
#define __ETH_CLK_ENABLE_PORT0		0x00004000
#define __APP_LPU_SPEED			0x00000002
#define CT2_MBIST_STAT_REG		0x00014818
#define CT2_MBIST_CTL_REG		0x0001481c
#define CT2_PMM_1T_CONTROL_REG_P0	0x0002381c
#define __PMM_1T_PNDB_P			0x00000002
#define CT2_PMM_1T_CONTROL_REG_P1	0x00023c1c
#define CT2_WGN_STATUS			0x00014990
#define __A2T_AHB_LOAD			0x00000800
#define __WGN_READY			0x00000400
#define __GLBL_PF_VF_CFG_RDY		0x00000200
#define CT2_NFC_CSR_CLR_REG		0x00027420
#define CT2_NFC_CSR_SET_REG		0x00027424
#define __HALT_NFC_CONTROLLER		0x00000002
#define __NFC_CONTROLLER_HALTED		0x00001000
#define CT2_RSC_GPR15_REG		0x0002765c
#define CT2_CSI_FW_CTL_REG		0x00027080
#define CT2_CSI_FW_CTL_SET_REG		0x00027088
#define __RESET_AND_START_SCLK_LCLK_PLLS 0x00010000

#define CT2_CSI_MAC0_CONTROL_REG	0x000270d0
#define __CSI_MAC_RESET			0x00000010
#define __CSI_MAC_AHB_RESET		0x00000008
#define CT2_CSI_MAC1_CONTROL_REG	0x000270d4
#define CT2_CSI_MAC_CONTROL_REG(__n)	\
	(CT2_CSI_MAC0_CONTROL_REG +	\
	(__n) * (CT2_CSI_MAC1_CONTROL_REG - CT2_CSI_MAC0_CONTROL_REG))

/*
                                          
 */
#define BFA_IOC0_HBEAT_REG		HOST_SEM0_INFO_REG
#define BFA_IOC0_STATE_REG		HOST_SEM1_INFO_REG
#define BFA_IOC1_HBEAT_REG		HOST_SEM2_INFO_REG
#define BFA_IOC1_STATE_REG		HOST_SEM3_INFO_REG
#define BFA_FW_USE_COUNT		HOST_SEM4_INFO_REG
#define BFA_IOC_FAIL_SYNC		HOST_SEM5_INFO_REG

/*
                                           
 */
#define CT2_BFA_IOC0_HBEAT_REG		CT2_HOST_SEM0_INFO_REG
#define CT2_BFA_IOC0_STATE_REG		CT2_HOST_SEM1_INFO_REG
#define CT2_BFA_IOC1_HBEAT_REG		CT2_HOST_SEM2_INFO_REG
#define CT2_BFA_IOC1_STATE_REG		CT2_HOST_SEM3_INFO_REG
#define CT2_BFA_FW_USE_COUNT		CT2_HOST_SEM4_INFO_REG
#define CT2_BFA_IOC_FAIL_SYNC		CT2_HOST_SEM5_INFO_REG

#define CPE_Q_NUM(__fn, __q)	(((__fn) << 2) + (__q))
#define RME_Q_NUM(__fn, __q)	(((__fn) << 2) + (__q))

/*
                                                            
 */
#define __HFN_INT_CPE_Q0	0x00000001U
#define __HFN_INT_CPE_Q1	0x00000002U
#define __HFN_INT_CPE_Q2	0x00000004U
#define __HFN_INT_CPE_Q3	0x00000008U
#define __HFN_INT_CPE_Q4	0x00000010U
#define __HFN_INT_CPE_Q5	0x00000020U
#define __HFN_INT_CPE_Q6	0x00000040U
#define __HFN_INT_CPE_Q7	0x00000080U
#define __HFN_INT_RME_Q0	0x00000100U
#define __HFN_INT_RME_Q1	0x00000200U
#define __HFN_INT_RME_Q2	0x00000400U
#define __HFN_INT_RME_Q3	0x00000800U
#define __HFN_INT_RME_Q4	0x00001000U
#define __HFN_INT_RME_Q5	0x00002000U
#define __HFN_INT_RME_Q6	0x00004000U
#define __HFN_INT_RME_Q7	0x00008000U
#define __HFN_INT_ERR_EMC	0x00010000U
#define __HFN_INT_ERR_LPU0	0x00020000U
#define __HFN_INT_ERR_LPU1	0x00040000U
#define __HFN_INT_ERR_PSS	0x00080000U
#define __HFN_INT_MBOX_LPU0	0x00100000U
#define __HFN_INT_MBOX_LPU1	0x00200000U
#define __HFN_INT_MBOX1_LPU0	0x00400000U
#define __HFN_INT_MBOX1_LPU1	0x00800000U
#define __HFN_INT_LL_HALT	0x01000000U
#define __HFN_INT_CPE_MASK	0x000000ffU
#define __HFN_INT_RME_MASK	0x0000ff00U
#define __HFN_INT_ERR_MASK	\
	(__HFN_INT_ERR_EMC | __HFN_INT_ERR_LPU0 | __HFN_INT_ERR_LPU1 | \
	 __HFN_INT_ERR_PSS | __HFN_INT_LL_HALT)
#define __HFN_INT_FN0_MASK	\
	(__HFN_INT_CPE_Q0 | __HFN_INT_CPE_Q1 | __HFN_INT_CPE_Q2 | \
	 __HFN_INT_CPE_Q3 | __HFN_INT_RME_Q0 | __HFN_INT_RME_Q1 | \
	 __HFN_INT_RME_Q2 | __HFN_INT_RME_Q3 | __HFN_INT_MBOX_LPU0)
#define __HFN_INT_FN1_MASK	\
	(__HFN_INT_CPE_Q4 | __HFN_INT_CPE_Q5 | __HFN_INT_CPE_Q6 | \
	 __HFN_INT_CPE_Q7 | __HFN_INT_RME_Q4 | __HFN_INT_RME_Q5 | \
	 __HFN_INT_RME_Q6 | __HFN_INT_RME_Q7 | __HFN_INT_MBOX_LPU1)

/*
                                               
 */
#define __HFN_INT_MBOX_LPU0_CT2	0x00010000U
#define __HFN_INT_MBOX_LPU1_CT2	0x00020000U
#define __HFN_INT_ERR_PSS_CT2	0x00040000U
#define __HFN_INT_ERR_LPU0_CT2	0x00080000U
#define __HFN_INT_ERR_LPU1_CT2	0x00100000U
#define __HFN_INT_CPQ_HALT_CT2	0x00200000U
#define __HFN_INT_ERR_WGN_CT2	0x00400000U
#define __HFN_INT_ERR_LEHRX_CT2	0x00800000U
#define __HFN_INT_ERR_LEHTX_CT2	0x01000000U
#define __HFN_INT_ERR_MASK_CT2	\
	(__HFN_INT_ERR_PSS_CT2 | __HFN_INT_ERR_LPU0_CT2 | \
	 __HFN_INT_ERR_LPU1_CT2 | __HFN_INT_CPQ_HALT_CT2 | \
	 __HFN_INT_ERR_WGN_CT2 | __HFN_INT_ERR_LEHRX_CT2 | \
	 __HFN_INT_ERR_LEHTX_CT2)
#define __HFN_INT_FN0_MASK_CT2	\
	(__HFN_INT_CPE_Q0 | __HFN_INT_CPE_Q1 | __HFN_INT_CPE_Q2 | \
	 __HFN_INT_CPE_Q3 | __HFN_INT_RME_Q0 | __HFN_INT_RME_Q1 | \
	 __HFN_INT_RME_Q2 | __HFN_INT_RME_Q3 | __HFN_INT_MBOX_LPU0_CT2)
#define __HFN_INT_FN1_MASK_CT2	\
	(__HFN_INT_CPE_Q4 | __HFN_INT_CPE_Q5 | __HFN_INT_CPE_Q6 | \
	 __HFN_INT_CPE_Q7 | __HFN_INT_RME_Q4 | __HFN_INT_RME_Q5 | \
	 __HFN_INT_RME_Q6 | __HFN_INT_RME_Q7 | __HFN_INT_MBOX_LPU1_CT2)

/*
                   
 */
#define PSS_SMEM_PAGE_START		0x8000
#define PSS_SMEM_PGNUM(_pg0, _ma)	((_pg0) + ((_ma) >> 15))
#define PSS_SMEM_PGOFF(_ma)		((_ma) & 0x7fff)

#endif /*               */

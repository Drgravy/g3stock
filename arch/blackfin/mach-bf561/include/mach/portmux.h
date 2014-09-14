/*
 * Copyright 2007-2009 Analog Devices Inc.
 *
 * Licensed under the GPL-2 or later.
 */

#ifndef _MACH_PORTMUX_H_
#define _MACH_PORTMUX_H_

#define MAX_RESOURCES	MAX_BLACKFIN_GPIOS

#define P_PPI0_CLK	(P_DONTCARE)
#define P_PPI0_FS1	(P_DONTCARE)
#define P_PPI0_FS2	(P_DONTCARE)
#define P_PPI0_FS3	(P_DONTCARE)
#define P_PPI0_D15	(P_DEFINED | P_IDENT(GPIO_PF47))
#define P_PPI0_D14	(P_DEFINED | P_IDENT(GPIO_PF46))
#define P_PPI0_D13	(P_DEFINED | P_IDENT(GPIO_PF45))
#define P_PPI0_D12	(P_DEFINED | P_IDENT(GPIO_PF44))
#define P_PPI0_D11	(P_DEFINED | P_IDENT(GPIO_PF43))
#define P_PPI0_D10	(P_DEFINED | P_IDENT(GPIO_PF42))
#define P_PPI0_D9	(P_DEFINED | P_IDENT(GPIO_PF41))
#define P_PPI0_D8	(P_DEFINED | P_IDENT(GPIO_PF40))
#define P_PPI0_D0	(P_DONTCARE)
#define P_PPI0_D1	(P_DONTCARE)
#define P_PPI0_D2	(P_DONTCARE)
#define P_PPI0_D3	(P_DONTCARE)
#define P_PPI0_D4	(P_DONTCARE)
#define P_PPI0_D5	(P_DONTCARE)
#define P_PPI0_D6	(P_DONTCARE)
#define P_PPI0_D7	(P_DONTCARE)
#define P_PPI1_CLK	(P_DONTCARE)
#define P_PPI1_FS1	(P_DONTCARE)
#define P_PPI1_FS2	(P_DONTCARE)
#define P_PPI1_FS3	(P_DONTCARE)
#define P_PPI1_D15	(P_DEFINED | P_IDENT(GPIO_PF39))
#define P_PPI1_D14	(P_DEFINED | P_IDENT(GPIO_PF38))
#define P_PPI1_D13	(P_DEFINED | P_IDENT(GPIO_PF37))
#define P_PPI1_D12	(P_DEFINED | P_IDENT(GPIO_PF36))
#define P_PPI1_D11	(P_DEFINED | P_IDENT(GPIO_PF35))
#define P_PPI1_D10	(P_DEFINED | P_IDENT(GPIO_PF34))
#define P_PPI1_D9	(P_DEFINED | P_IDENT(GPIO_PF33))
#define P_PPI1_D8	(P_DEFINED | P_IDENT(GPIO_PF32))
#define P_PPI1_D0	(P_DONTCARE)
#define P_PPI1_D1	(P_DONTCARE)
#define P_PPI1_D2	(P_DONTCARE)
#define P_PPI1_D3	(P_DONTCARE)
#define P_PPI1_D4	(P_DONTCARE)
#define P_PPI1_D5	(P_DONTCARE)
#define P_PPI1_D6	(P_DONTCARE)
#define P_PPI1_D7	(P_DONTCARE)
#define P_SPORT1_TSCLK	(P_DEFINED | P_IDENT(GPIO_PF31))
#define P_SPORT1_RSCLK	(P_DEFINED | P_IDENT(GPIO_PF30))
#define P_SPORT0_TSCLK	(P_DEFINED | P_IDENT(GPIO_PF29))
#define P_SPORT0_RSCLK	(P_DEFINED | P_IDENT(GPIO_PF28))
#define P_UART0_RX	(P_DEFINED | P_IDENT(GPIO_PF27))
#define P_UART0_TX	(P_DEFINED | P_IDENT(GPIO_PF26))
#define P_SPORT1_DRSEC	(P_DEFINED | P_IDENT(GPIO_PF25))
#define P_SPORT1_RFS	(P_DEFINED | P_IDENT(GPIO_PF24))
#define P_SPORT1_DTPRI	(P_DEFINED | P_IDENT(GPIO_PF23))
#define P_SPORT1_DTSEC	(P_DEFINED | P_IDENT(GPIO_PF22))
#define P_SPORT1_TFS	(P_DEFINED | P_IDENT(GPIO_PF21))
#define P_SPORT1_DRPRI	(P_DONTCARE)
#define P_SPORT0_DRSEC	(P_DEFINED | P_IDENT(GPIO_PF20))
#define P_SPORT0_RFS	(P_DEFINED | P_IDENT(GPIO_PF19))
#define P_SPORT0_DTPRI	(P_DEFINED | P_IDENT(GPIO_PF18))
#define P_SPORT0_DTSEC	(P_DEFINED | P_IDENT(GPIO_PF17))
#define P_SPORT0_TFS	(P_DEFINED | P_IDENT(GPIO_PF16))
#define P_SPORT0_DRPRI	(P_DONTCARE)
#define P_TMRCLK	(P_DEFINED | P_IDENT(GPIO_PF15))
#define P_SPI0_SSEL7	(P_DEFINED | P_IDENT(GPIO_PF7))
#define P_SPI0_SSEL6	(P_DEFINED | P_IDENT(GPIO_PF6))
#define P_SPI0_SSEL5	(P_DEFINED | P_IDENT(GPIO_PF5))
#define P_SPI0_SSEL4	(P_DEFINED | P_IDENT(GPIO_PF4))
#define P_SPI0_SSEL3	(P_DEFINED | P_IDENT(GPIO_PF3))
#define P_SPI0_SSEL2	(P_DEFINED | P_IDENT(GPIO_PF2))
#define P_SPI0_SSEL1	(P_DEFINED | P_IDENT(GPIO_PF1))
#define P_SPI0_SS	(P_DEFINED | P_IDENT(GPIO_PF0))
#define P_TMR11		(P_DONTCARE)
#define P_TMR10		(P_DONTCARE)
#define P_TMR9		(P_DONTCARE)
#define P_TMR8		(P_DONTCARE)
#define P_TMR7		(P_DEFINED | P_IDENT(GPIO_PF7))
#define P_TMR6		(P_DEFINED | P_IDENT(GPIO_PF6))
#define P_TMR5		(P_DEFINED | P_IDENT(GPIO_PF5))
#define P_TMR4		(P_DEFINED | P_IDENT(GPIO_PF4))
#define P_TMR3		(P_DEFINED | P_IDENT(GPIO_PF3))
#define P_TMR2		(P_DEFINED | P_IDENT(GPIO_PF2))
#define P_TMR1		(P_DEFINED | P_IDENT(GPIO_PF1))
#define P_TMR0		(P_DEFINED | P_IDENT(GPIO_PF0))
#define P_SPI0_MOSI	(P_DONTCARE)
#define P_SPI0_MISO	(P_DONTCARE)
#define P_SPI0_SCK	(P_DONTCARE)
#define GPIO_DEFAULT_BOOT_SPI_CS GPIO_PF2
#define P_DEFAULT_BOOT_SPI_CS P_SPI0_SSEL2

#endif /*                  */

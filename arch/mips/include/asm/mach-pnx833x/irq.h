/*
 *  irq.h: IRQ mappings for PNX833X.
 *
 *  Copyright 2008 NXP Semiconductors
 *	  Chris Steel <chris.steel@nxp.com>
 *    Daniel Laird <daniel.j.laird@nxp.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ifndef __ASM_MIPS_MACH_PNX833X_IRQ_H
#define __ASM_MIPS_MACH_PNX833X_IRQ_H
/*
                                            
  
                                                                   
                                                                            
                                                
  
                                                                 
                                                                   
                                                  
                                                                            
                                                
  
 */
#if defined(CONFIG_SOC_PNX8335)
	#define PNX833X_PIC_NUM_IRQ			58
#else
	#define PNX833X_PIC_NUM_IRQ			37
#endif

#define MIPS_CPU_NUM_IRQ				8
#define PNX833X_GPIO_NUM_IRQ			16

#define MIPS_CPU_IRQ_BASE				0
#define PNX833X_PIC_IRQ_BASE			(MIPS_CPU_IRQ_BASE + MIPS_CPU_NUM_IRQ)
#define PNX833X_GPIO_IRQ_BASE			(PNX833X_PIC_IRQ_BASE + PNX833X_PIC_NUM_IRQ)
#define NR_IRQS							(MIPS_CPU_NUM_IRQ + PNX833X_PIC_NUM_IRQ + PNX833X_GPIO_NUM_IRQ)

#endif

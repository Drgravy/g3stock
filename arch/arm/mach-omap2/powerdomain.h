/*
 * OMAP2/3/4 powerdomain control
 *
 * Copyright (C) 2007-2008, 2010 Texas Instruments, Inc.
 * Copyright (C) 2007-2011 Nokia Corporation
 *
 * Paul Walmsley
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * XXX This should be moved to the mach-omap2/ directory at the earliest
 * opportunity.
 */

#ifndef __ARCH_ARM_MACH_OMAP2_POWERDOMAIN_H
#define __ARCH_ARM_MACH_OMAP2_POWERDOMAIN_H

#include <linux/types.h>
#include <linux/list.h>

#include <linux/atomic.h>

#include <plat/cpu.h>

#include "voltage.h"

/*                                */
#define PWRDM_POWER_OFF		0x0
#define PWRDM_POWER_RET		0x1
#define PWRDM_POWER_INACTIVE	0x2
#define PWRDM_POWER_ON		0x3

#define PWRDM_MAX_PWRSTS	4

/*                                       */
#define PWRSTS_ON		(1 << PWRDM_POWER_ON)
#define PWRSTS_INACTIVE		(1 << PWRDM_POWER_INACTIVE)
#define PWRSTS_RET		(1 << PWRDM_POWER_RET)
#define PWRSTS_OFF		(1 << PWRDM_POWER_OFF)

#define PWRSTS_OFF_ON		(PWRSTS_OFF | PWRSTS_ON)
#define PWRSTS_OFF_RET		(PWRSTS_OFF | PWRSTS_RET)
#define PWRSTS_RET_ON		(PWRSTS_RET | PWRSTS_ON)
#define PWRSTS_OFF_RET_ON	(PWRSTS_OFF_RET | PWRSTS_ON)


/*                   */
#define PWRDM_HAS_HDWR_SAR	(1 << 0) /*                                   */
#define PWRDM_HAS_MPU_QUIRK	(1 << 1) /*                                   
                                        
                          
       */
#define PWRDM_HAS_LOWPOWERSTATECHANGE	(1 << 2) /*
                                      
                                      
                                     
                     
        */

/*
                                                                       
                
 */
#define PWRDM_MAX_MEM_BANKS	5

/*
                                                                            
                                              
 */
#define PWRDM_MAX_CLKDMS	9

/*                                                             */
#define PWRDM_TRANSITION_BAILOUT 100000

struct clockdomain;
struct powerdomain;

/* 
                                        
                          
                                                     
                                                       
                                                                            
                                             
                                                                         
                            
                                                                           
                                                                          
                                                                  
                                                  
                                            
                                                                      
          
                  
          
                
  
                                                                        
 */
struct powerdomain {
	const char *name;
	union {
		const char *name;
		struct voltagedomain *ptr;
	} voltdm;
	const s16 prcm_offs;
	const u8 pwrsts;
	const u8 pwrsts_logic_ret;
	const u8 flags;
	const u8 banks;
	const u8 pwrsts_mem_ret[PWRDM_MAX_MEM_BANKS];
	const u8 pwrsts_mem_on[PWRDM_MAX_MEM_BANKS];
	const u8 prcm_partition;
	struct clockdomain *pwrdm_clkdms[PWRDM_MAX_CLKDMS];
	struct list_head node;
	struct list_head voltdm_node;
	int state;
	unsigned state_counter[PWRDM_MAX_PWRSTS];
	unsigned ret_logic_off_counter;
	unsigned ret_mem_off_counter[PWRDM_MAX_MEM_BANKS];

#ifdef CONFIG_PM_DEBUG
	s64 timer;
	s64 state_timer[PWRDM_MAX_PWRSTS];
#endif
};

/* 
                                                            
                                                             
                                                                   
                                                          
                                                                      
                                                              
                                                           
                                                             
                                                                
                                                                              
                                                                
                                                               
                                                                             
                                                               
                                                                               
                                                                          
                                                                          
                                                                                
                                                                     
 */
struct pwrdm_ops {
	int	(*pwrdm_set_next_pwrst)(struct powerdomain *pwrdm, u8 pwrst);
	int	(*pwrdm_read_next_pwrst)(struct powerdomain *pwrdm);
	int	(*pwrdm_read_pwrst)(struct powerdomain *pwrdm);
	int	(*pwrdm_read_prev_pwrst)(struct powerdomain *pwrdm);
	int	(*pwrdm_set_logic_retst)(struct powerdomain *pwrdm, u8 pwrst);
	int	(*pwrdm_set_mem_onst)(struct powerdomain *pwrdm, u8 bank, u8 pwrst);
	int	(*pwrdm_set_mem_retst)(struct powerdomain *pwrdm, u8 bank, u8 pwrst);
	int	(*pwrdm_read_logic_pwrst)(struct powerdomain *pwrdm);
	int	(*pwrdm_read_prev_logic_pwrst)(struct powerdomain *pwrdm);
	int	(*pwrdm_read_logic_retst)(struct powerdomain *pwrdm);
	int	(*pwrdm_read_mem_pwrst)(struct powerdomain *pwrdm, u8 bank);
	int	(*pwrdm_read_prev_mem_pwrst)(struct powerdomain *pwrdm, u8 bank);
	int	(*pwrdm_read_mem_retst)(struct powerdomain *pwrdm, u8 bank);
	int	(*pwrdm_clear_all_prev_pwrst)(struct powerdomain *pwrdm);
	int	(*pwrdm_enable_hdwr_sar)(struct powerdomain *pwrdm);
	int	(*pwrdm_disable_hdwr_sar)(struct powerdomain *pwrdm);
	int	(*pwrdm_set_lowpwrstchange)(struct powerdomain *pwrdm);
	int	(*pwrdm_wait_transition)(struct powerdomain *pwrdm);
};

int pwrdm_register_platform_funcs(struct pwrdm_ops *custom_funcs);
int pwrdm_register_pwrdms(struct powerdomain **pwrdm_list);
int pwrdm_complete_init(void);

struct powerdomain *pwrdm_lookup(const char *name);

int pwrdm_for_each(int (*fn)(struct powerdomain *pwrdm, void *user),
			void *user);
int pwrdm_for_each_nolock(int (*fn)(struct powerdomain *pwrdm, void *user),
			void *user);

int pwrdm_add_clkdm(struct powerdomain *pwrdm, struct clockdomain *clkdm);
int pwrdm_del_clkdm(struct powerdomain *pwrdm, struct clockdomain *clkdm);
int pwrdm_for_each_clkdm(struct powerdomain *pwrdm,
			 int (*fn)(struct powerdomain *pwrdm,
				   struct clockdomain *clkdm));
struct voltagedomain *pwrdm_get_voltdm(struct powerdomain *pwrdm);

int pwrdm_get_mem_bank_count(struct powerdomain *pwrdm);

int pwrdm_set_next_pwrst(struct powerdomain *pwrdm, u8 pwrst);
int pwrdm_read_next_pwrst(struct powerdomain *pwrdm);
int pwrdm_read_pwrst(struct powerdomain *pwrdm);
int pwrdm_read_prev_pwrst(struct powerdomain *pwrdm);
int pwrdm_clear_all_prev_pwrst(struct powerdomain *pwrdm);

int pwrdm_set_logic_retst(struct powerdomain *pwrdm, u8 pwrst);
int pwrdm_set_mem_onst(struct powerdomain *pwrdm, u8 bank, u8 pwrst);
int pwrdm_set_mem_retst(struct powerdomain *pwrdm, u8 bank, u8 pwrst);

int pwrdm_read_logic_pwrst(struct powerdomain *pwrdm);
int pwrdm_read_prev_logic_pwrst(struct powerdomain *pwrdm);
int pwrdm_read_logic_retst(struct powerdomain *pwrdm);
int pwrdm_read_mem_pwrst(struct powerdomain *pwrdm, u8 bank);
int pwrdm_read_prev_mem_pwrst(struct powerdomain *pwrdm, u8 bank);
int pwrdm_read_mem_retst(struct powerdomain *pwrdm, u8 bank);

int pwrdm_enable_hdwr_sar(struct powerdomain *pwrdm);
int pwrdm_disable_hdwr_sar(struct powerdomain *pwrdm);
bool pwrdm_has_hdwr_sar(struct powerdomain *pwrdm);

int pwrdm_wait_transition(struct powerdomain *pwrdm);

int pwrdm_state_switch(struct powerdomain *pwrdm);
int pwrdm_clkdm_state_switch(struct clockdomain *clkdm);
int pwrdm_pre_transition(void);
int pwrdm_post_transition(void);
int pwrdm_set_lowpwrstchange(struct powerdomain *pwrdm);
int pwrdm_get_context_loss_count(struct powerdomain *pwrdm);
bool pwrdm_can_ever_lose_context(struct powerdomain *pwrdm);

extern void omap242x_powerdomains_init(void);
extern void omap243x_powerdomains_init(void);
extern void omap3xxx_powerdomains_init(void);
extern void omap44xx_powerdomains_init(void);

extern struct pwrdm_ops omap2_pwrdm_operations;
extern struct pwrdm_ops omap3_pwrdm_operations;
extern struct pwrdm_ops omap4_pwrdm_operations;

/*                                                  */
extern u32 omap2_pwrdm_get_mem_bank_onstate_mask(u8 bank);
extern u32 omap2_pwrdm_get_mem_bank_retst_mask(u8 bank);
extern u32 omap2_pwrdm_get_mem_bank_stst_mask(u8 bank);

extern struct powerdomain wkup_omap2_pwrdm;
extern struct powerdomain gfx_omap2_pwrdm;


#endif

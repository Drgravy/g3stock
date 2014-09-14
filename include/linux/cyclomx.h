#ifndef	_CYCLOMX_H
#define	_CYCLOMX_H
/*
* cyclomx.h	Cyclom 2X WAN Link Driver.
*		User-level API definitions.
*
* Author:	Arnaldo Carvalho de Melo <acme@conectiva.com.br>
*
* Copyright:	(c) 1998-2003 Arnaldo Carvalho de Melo
*
* Based on wanpipe.h by Gene Kozin <genek@compuserve.com>
*
*		This program is free software; you can redistribute it and/or
*		modify it under the terms of the GNU General Public License
*		as published by the Free Software Foundation; either version
*		2 of the License, or (at your option) any later version.
* ============================================================================
* 2000/07/13    acme		remove crap #if KERNEL_VERSION > blah
* 2000/01/21    acme            rename cyclomx_open to cyclomx_mod_inc_use_count
*                               and cyclomx_close to cyclomx_mod_dec_use_count
* 1999/05/19	acme		wait_queue_head_t wait_stats(support for 2.3.*)
* 1999/01/03	acme		judicious use of data types
* 1998/12/27	acme		cleanup: PACKED not needed
* 1998/08/08	acme		Version 0.0.1
*/

#include <linux/wanrouter.h>
#include <linux/spinlock.h>

#ifdef	__KERNEL__
/*                  */

#include <linux/cycx_drv.h>	/*                                          */
#include <linux/cycx_cfm.h>	/*                                       */
#ifdef CONFIG_CYCLOMX_X25
#include <linux/cycx_x25.h>
#endif

/*                    
                                                                       
                           
 */
struct cycx_device {
	char devname[WAN_DRVNAME_SZ + 1];/*           */
	struct cycx_hw hw;		/*                        */
	struct wan_device wandev;	/*                       */
	u32 state_tick;			/*                      */
	spinlock_t lock;
	char in_isr;			/*                           */
	char buff_int_mode_unbusy;      /*                                */
	wait_queue_head_t wait_stats;  /*                                  */
	void __iomem *mbox;			/*            */
	void (*isr)(struct cycx_device* card);	/*                           */
	int (*exec)(struct cycx_device* card, void* u_cmd, void* u_data);
	union {
#ifdef CONFIG_CYCLOMX_X25
		struct { /*                    */
			u32 lo_pvc;
			u32 hi_pvc;
			u32 lo_svc;
			u32 hi_svc;
			struct cycx_x25_stats stats;
			spinlock_t lock;
			u32 connection_keys;
		} x;
#endif
	} u;
};

/*                  */
void cycx_set_state(struct cycx_device *card, int state);

#ifdef CONFIG_CYCLOMX_X25
int cycx_x25_wan_init(struct cycx_device *card, wandev_conf_t *conf);
#endif
#endif	/*            */
#endif	/*            */

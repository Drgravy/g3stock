/*
 * Userspace API for hardware time stamping of network packets
 *
 * Copyright (C) 2008,2009 Intel Corporation
 * Author: Patrick Ohly <patrick.ohly@intel.com>
 *
 */

#ifndef _NET_TIMESTAMPING_H
#define _NET_TIMESTAMPING_H

#include <linux/socket.h>   /*                     */

/*                                                                     */
enum {
	SOF_TIMESTAMPING_TX_HARDWARE = (1<<0),
	SOF_TIMESTAMPING_TX_SOFTWARE = (1<<1),
	SOF_TIMESTAMPING_RX_HARDWARE = (1<<2),
	SOF_TIMESTAMPING_RX_SOFTWARE = (1<<3),
	SOF_TIMESTAMPING_SOFTWARE = (1<<4),
	SOF_TIMESTAMPING_SYS_HARDWARE = (1<<5),
	SOF_TIMESTAMPING_RAW_HARDWARE = (1<<6),
	SOF_TIMESTAMPING_MASK =
	(SOF_TIMESTAMPING_RAW_HARDWARE - 1) |
	SOF_TIMESTAMPING_RAW_HARDWARE
};

/* 
                                                    
  
                                                   
                                 
                                            
  
                                                                    
                                                               
                                                              
                                                                      
                                           
 */
struct hwtstamp_config {
	int flags;
	int tx_type;
	int rx_filter;
};

/*                                              */
enum hwtstamp_tx_types {
	/*
                                                        
                                                         
                               
  */
	HWTSTAMP_TX_OFF,

	/*
                                                        
                                                    
                                                         
                              
  */
	HWTSTAMP_TX_ON,

	/*
                                                      
                                                              
                                                              
                                                               
          
  */
	HWTSTAMP_TX_ONESTEP_SYNC,
};

/*                                                */
enum hwtstamp_rx_filters {
	/*                                      */
	HWTSTAMP_FILTER_NONE,

	/*                                */
	HWTSTAMP_FILTER_ALL,

	/*                                                                 */
	HWTSTAMP_FILTER_SOME,

	/*                                       */
	HWTSTAMP_FILTER_PTP_V1_L4_EVENT,
	/*                          */
	HWTSTAMP_FILTER_PTP_V1_L4_SYNC,
	/*                               */
	HWTSTAMP_FILTER_PTP_V1_L4_DELAY_REQ,
	/*                                       */
	HWTSTAMP_FILTER_PTP_V2_L4_EVENT,
	/*                          */
	HWTSTAMP_FILTER_PTP_V2_L4_SYNC,
	/*                               */
	HWTSTAMP_FILTER_PTP_V2_L4_DELAY_REQ,

	/*                                             */
	HWTSTAMP_FILTER_PTP_V2_L2_EVENT,
	/*                                */
	HWTSTAMP_FILTER_PTP_V2_L2_SYNC,
	/*                                     */
	HWTSTAMP_FILTER_PTP_V2_L2_DELAY_REQ,

	/*                                                     */
	HWTSTAMP_FILTER_PTP_V2_EVENT,
	/*                                        */
	HWTSTAMP_FILTER_PTP_V2_SYNC,
	/*                                             */
	HWTSTAMP_FILTER_PTP_V2_DELAY_REQ,
};

#endif /*                     */

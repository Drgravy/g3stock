#ifndef __BNX2FC_DEBUG__
#define __BNX2FC_DEBUG__

/*                    */
#define LOG_IO		0x01	/*                         */
#define LOG_TGT		0x02	/*                              */
#define LOG_HBA		0x04	/*                               */
#define LOG_ELS		0x08	/*          */
#define LOG_MISC	0x10	/*                           */
#define LOG_ALL		0xff	/*                  */

extern unsigned int bnx2fc_debug_level;

#define BNX2FC_CHK_LOGGING(LEVEL, CMD)					\
	do {								\
		if (unlikely(bnx2fc_debug_level & LEVEL))		\
			do {						\
				CMD;					\
			} while (0);					\
	} while (0)

#define BNX2FC_ELS_DBG(fmt, arg...)					\
	BNX2FC_CHK_LOGGING(LOG_ELS,					\
			   printk(KERN_INFO PFX fmt, ##arg))

#define BNX2FC_MISC_DBG(fmt, arg...)					\
	BNX2FC_CHK_LOGGING(LOG_MISC,					\
			   printk(KERN_INFO PFX fmt, ##arg))

#define BNX2FC_IO_DBG(io_req, fmt, arg...)				\
	do {								\
		if (!io_req || !io_req->port || !io_req->port->lport ||	\
		    !io_req->port->lport->host)				\
			BNX2FC_CHK_LOGGING(LOG_IO,			\
			   printk(KERN_INFO PFX "NULL " fmt, ##arg));	\
		else							\
			BNX2FC_CHK_LOGGING(LOG_IO,			\
			   shost_printk(KERN_INFO,			\
				   (io_req)->port->lport->host,		\
				   PFX "xid:0x%x " fmt,			\
				   (io_req)->xid, ##arg));		\
	} while (0)

#define BNX2FC_TGT_DBG(tgt, fmt, arg...)				\
	do {								\
		if (!tgt || !tgt->port || !tgt->port->lport ||		\
		    !tgt->port->lport->host || !tgt->rport)		\
			BNX2FC_CHK_LOGGING(LOG_TGT,			\
			   printk(KERN_INFO PFX "NULL " fmt, ##arg));	\
		else							\
			BNX2FC_CHK_LOGGING(LOG_TGT,			\
			   shost_printk(KERN_INFO,			\
				   (tgt)->port->lport->host,		\
				   PFX "port:%x " fmt,			\
				   (tgt)->rport->port_id, ##arg));	\
	} while (0)


#define BNX2FC_HBA_DBG(lport, fmt, arg...)				\
	do {								\
		if (!lport || !lport->host)				\
			BNX2FC_CHK_LOGGING(LOG_HBA,			\
			   printk(KERN_INFO PFX "NULL " fmt, ##arg));	\
		else							\
			BNX2FC_CHK_LOGGING(LOG_HBA,			\
			   shost_printk(KERN_INFO, lport->host,	\
				   PFX fmt, ##arg));			\
	} while (0)

#endif

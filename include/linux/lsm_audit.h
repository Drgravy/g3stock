/*
                               
                                      
  
                                                      
  
                                                         
                                                           
 */
#ifndef _LSM_COMMON_LOGGING_
#define _LSM_COMMON_LOGGING_

#include <linux/stddef.h>
#include <linux/errno.h>
#include <linux/kernel.h>
#include <linux/kdev_t.h>
#include <linux/spinlock.h>
#include <linux/init.h>
#include <linux/audit.h>
#include <linux/in6.h>
#include <linux/path.h>
#include <linux/key.h>
#include <linux/skbuff.h>

struct lsm_network_audit {
	int netif;
	struct sock *sk;
	u16 family;
	__be16 dport;
	__be16 sport;
	union {
		struct {
			__be32 daddr;
			__be32 saddr;
		} v4;
		struct {
			struct in6_addr daddr;
			struct in6_addr saddr;
		} v6;
	} fam;
};

/*                                                       */
struct common_audit_data {
	char type;
#define LSM_AUDIT_DATA_PATH	1
#define LSM_AUDIT_DATA_NET	2
#define LSM_AUDIT_DATA_CAP	3
#define LSM_AUDIT_DATA_IPC	4
#define LSM_AUDIT_DATA_TASK	5
#define LSM_AUDIT_DATA_KEY	6
#define LSM_AUDIT_DATA_NONE	7
#define LSM_AUDIT_DATA_KMOD	8
#define LSM_AUDIT_DATA_INODE	9
#define LSM_AUDIT_DATA_DENTRY	10
	struct task_struct *tsk;
	union 	{
		struct path path;
		struct dentry *dentry;
		struct inode *inode;
		struct lsm_network_audit *net;
		int cap;
		int ipc_id;
		struct task_struct *tsk;
#ifdef CONFIG_KEYS
		struct {
			key_serial_t key;
			char *key_desc;
		} key_struct;
#endif
		char *kmod_name;
	} u;
	/*                                       */
	union {
#ifdef CONFIG_SECURITY_SMACK
		struct smack_audit_data *smack_audit_data;
#endif
#ifdef CONFIG_SECURITY_SELINUX
		struct selinux_audit_data *selinux_audit_data;
#endif
#ifdef CONFIG_SECURITY_APPARMOR
		struct apparmor_audit_data *apparmor_audit_data;
#endif
	}; /*                            */
};

#define v4info fam.v4
#define v6info fam.v6

int ipv4_skb_to_auditdata(struct sk_buff *skb,
		struct common_audit_data *ad, u8 *proto);

int ipv6_skb_to_auditdata(struct sk_buff *skb,
		struct common_audit_data *ad, u8 *proto);

/*                                         */
#define COMMON_AUDIT_DATA_INIT(_d, _t) \
	{ memset((_d), 0, sizeof(struct common_audit_data)); \
	 (_d)->type = LSM_AUDIT_DATA_##_t; }

void common_lsm_audit(struct common_audit_data *a,
	void (*pre_audit)(struct audit_buffer *, void *),
	void (*post_audit)(struct audit_buffer *, void *));

#endif

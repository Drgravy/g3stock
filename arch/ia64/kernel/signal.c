/*
 * Architecture-specific signal handling support.
 *
 * Copyright (C) 1999-2004 Hewlett-Packard Co
 *	David Mosberger-Tang <davidm@hpl.hp.com>
 *
 * Derived from i386 and Alpha versions.
 */

#include <linux/errno.h>
#include <linux/kernel.h>
#include <linux/mm.h>
#include <linux/ptrace.h>
#include <linux/tracehook.h>
#include <linux/sched.h>
#include <linux/signal.h>
#include <linux/smp.h>
#include <linux/stddef.h>
#include <linux/tty.h>
#include <linux/binfmts.h>
#include <linux/unistd.h>
#include <linux/wait.h>

#include <asm/intrinsics.h>
#include <asm/uaccess.h>
#include <asm/rse.h>
#include <asm/sigcontext.h>

#include "sigframe.h"

#define DEBUG_SIG	0
#define STACK_ALIGN	16		/*                                     */
#define _BLOCKABLE	(~(sigmask(SIGKILL) | sigmask(SIGSTOP)))

#if _NSIG_WORDS > 1
# define PUT_SIGSET(k,u)	__copy_to_user((u)->sig, (k)->sig, sizeof(sigset_t))
# define GET_SIGSET(k,u)	__copy_from_user((k)->sig, (u)->sig, sizeof(sigset_t))
#else
# define PUT_SIGSET(k,u)	__put_user((k)->sig[0], &(u)->sig[0])
# define GET_SIGSET(k,u)	__get_user((k)->sig[0], &(u)->sig[0])
#endif

asmlinkage long
sys_sigaltstack (const stack_t __user *uss, stack_t __user *uoss, long arg2,
		 long arg3, long arg4, long arg5, long arg6, long arg7,
		 struct pt_regs regs)
{
	return do_sigaltstack(uss, uoss, regs.r12);
}

static long
restore_sigcontext (struct sigcontext __user *sc, struct sigscratch *scr)
{
	unsigned long ip, flags, nat, um, cfm, rsc;
	long err;

	/*                                                              */
	current_thread_info()->restart_block.fn = do_no_restart_syscall;

	/*                                                                        */
	err  = __get_user(flags, &sc->sc_flags);
	err |= __get_user(nat, &sc->sc_nat);
	err |= __get_user(ip, &sc->sc_ip);			/*                     */
	err |= __get_user(cfm, &sc->sc_cfm);
	err |= __get_user(um, &sc->sc_um);			/*           */
	err |= __get_user(rsc, &sc->sc_ar_rsc);
	err |= __get_user(scr->pt.ar_unat, &sc->sc_ar_unat);
	err |= __get_user(scr->pt.ar_fpsr, &sc->sc_ar_fpsr);
	err |= __get_user(scr->pt.ar_pfs, &sc->sc_ar_pfs);
	err |= __get_user(scr->pt.pr, &sc->sc_pr);		/*            */
	err |= __get_user(scr->pt.b0, &sc->sc_br[0]);		/*         */
	err |= __get_user(scr->pt.b6, &sc->sc_br[6]);		/*    */
	err |= __copy_from_user(&scr->pt.r1, &sc->sc_gr[1], 8);	/*    */
	err |= __copy_from_user(&scr->pt.r8, &sc->sc_gr[8], 4*8);	/*        */
	err |= __copy_from_user(&scr->pt.r12, &sc->sc_gr[12], 2*8);	/*         */
	err |= __copy_from_user(&scr->pt.r15, &sc->sc_gr[15], 8);	/*     */

	scr->pt.cr_ifs = cfm | (1UL << 63);
	scr->pt.ar_rsc = rsc | (3 << 2); /*           */

	/*                                    */
	scr->pt.cr_iip = ip & ~0x3UL;
	ia64_psr(&scr->pt)->ri = ip & 0x3;
	scr->pt.cr_ipsr = (scr->pt.cr_ipsr & ~IA64_PSR_UM) | (um & IA64_PSR_UM);

	scr->scratch_unat = ia64_put_scratch_nat_bits(&scr->pt, nat);

	if (!(flags & IA64_SC_FLAG_IN_SYSCALL)) {
		/*                                                      */
		err |= __get_user(scr->pt.ar_ccv, &sc->sc_ar_ccv);		/*        */
		err |= __get_user(scr->pt.b7, &sc->sc_br[7]);			/*    */
		err |= __get_user(scr->pt.r14, &sc->sc_gr[14]);			/*     */
		err |= __copy_from_user(&scr->pt.ar_csd, &sc->sc_ar25, 2*8); /*                 */
		err |= __copy_from_user(&scr->pt.r2, &sc->sc_gr[2], 2*8);	/*       */
		err |= __copy_from_user(&scr->pt.r16, &sc->sc_gr[16], 16*8);	/*         */
	}

	if ((flags & IA64_SC_FLAG_FPH_VALID) != 0) {
		struct ia64_psr *psr = ia64_psr(&scr->pt);

		err |= __copy_from_user(current->thread.fph, &sc->sc_fr[32], 96*16);
		psr->mfh = 0;	/*                                       */
		preempt_disable();
		if (psr->dfh)
			ia64_drop_fpu(current);
		else {
			/*                                                                  */
			__ia64_load_fpu(current->thread.fph);
			ia64_set_local_fpu_owner(current);
		}
		preempt_enable();
	}
	return err;
}

int
copy_siginfo_to_user (siginfo_t __user *to, siginfo_t *from)
{
	if (!access_ok(VERIFY_WRITE, to, sizeof(siginfo_t)))
		return -EFAULT;
	if (from->si_code < 0) {
		if (__copy_to_user(to, from, sizeof(siginfo_t)))
			return -EFAULT;
		return 0;
	} else {
		int err;

		/*
                                                                         
                                                                          
                                                                       
                           
   */
		err = __put_user(from->si_signo, &to->si_signo);
		err |= __put_user(from->si_errno, &to->si_errno);
		err |= __put_user((short)from->si_code, &to->si_code);
		switch (from->si_code >> 16) {
		      case __SI_FAULT >> 16:
			err |= __put_user(from->si_flags, &to->si_flags);
			err |= __put_user(from->si_isr, &to->si_isr);
		      case __SI_POLL >> 16:
			err |= __put_user(from->si_addr, &to->si_addr);
			err |= __put_user(from->si_imm, &to->si_imm);
			break;
		      case __SI_TIMER >> 16:
			err |= __put_user(from->si_tid, &to->si_tid);
			err |= __put_user(from->si_overrun, &to->si_overrun);
			err |= __put_user(from->si_ptr, &to->si_ptr);
			break;
		      case __SI_RT >> 16:	/*                                         */
		      case __SI_MESGQ >> 16:
			err |= __put_user(from->si_uid, &to->si_uid);
			err |= __put_user(from->si_pid, &to->si_pid);
			err |= __put_user(from->si_ptr, &to->si_ptr);
			break;
		      case __SI_CHLD >> 16:
			err |= __put_user(from->si_utime, &to->si_utime);
			err |= __put_user(from->si_stime, &to->si_stime);
			err |= __put_user(from->si_status, &to->si_status);
		      default:
			err |= __put_user(from->si_uid, &to->si_uid);
			err |= __put_user(from->si_pid, &to->si_pid);
			break;
		}
		return err;
	}
}

long
ia64_rt_sigreturn (struct sigscratch *scr)
{
	extern char ia64_strace_leave_kernel, ia64_leave_kernel;
	struct sigcontext __user *sc;
	struct siginfo si;
	sigset_t set;
	long retval;

	sc = &((struct sigframe __user *) (scr->pt.r12 + 16))->sc;

	/*
                                                                               
                                                                                  
                                                                               
                       
  */
	retval = (long) &ia64_leave_kernel;
	if (test_thread_flag(TIF_SYSCALL_TRACE)
	    || test_thread_flag(TIF_SYSCALL_AUDIT))
		/*
                                                                          
                                                                      
                                                                 
                 
   */
		retval = (long) &ia64_strace_leave_kernel;

	if (!access_ok(VERIFY_READ, sc, sizeof(*sc)))
		goto give_sigsegv;

	if (GET_SIGSET(&set, &sc->sc_mask))
		goto give_sigsegv;

	sigdelsetmask(&set, ~_BLOCKABLE);

	spin_lock_irq(&current->sighand->siglock);
	{
		current->blocked = set;
		recalc_sigpending();
	}
	spin_unlock_irq(&current->sighand->siglock);

	if (restore_sigcontext(sc, scr))
		goto give_sigsegv;

#if DEBUG_SIG
	printk("SIG return (%s:%d): sp=%lx ip=%lx\n",
	       current->comm, current->pid, scr->pt.r12, scr->pt.cr_iip);
#endif
	/*
                                                               
                              
  */
	do_sigaltstack(&sc->sc_stack, NULL, scr->pt.r12);
	return retval;

  give_sigsegv:
	si.si_signo = SIGSEGV;
	si.si_errno = 0;
	si.si_code = SI_KERNEL;
	si.si_pid = task_pid_vnr(current);
	si.si_uid = current_uid();
	si.si_addr = sc;
	force_sig_info(SIGSEGV, &si, current);
	return retval;
}

/*
                                                           
                                                                     
                                                               
                                                                 
 */
static long
setup_sigcontext (struct sigcontext __user *sc, sigset_t *mask, struct sigscratch *scr)
{
	unsigned long flags = 0, ifs, cfm, nat;
	long err = 0;

	ifs = scr->pt.cr_ifs;

	if (on_sig_stack((unsigned long) sc))
		flags |= IA64_SC_FLAG_ONSTACK;
	if ((ifs & (1UL << 63)) == 0)
		/*                                                                         */
		flags |= IA64_SC_FLAG_IN_SYSCALL;
	cfm = ifs & ((1UL << 38) - 1);
	ia64_flush_fph(current);
	if ((current->thread.flags & IA64_THREAD_FPH_VALID)) {
		flags |= IA64_SC_FLAG_FPH_VALID;
		err = __copy_to_user(&sc->sc_fr[32], current->thread.fph, 96*16);
	}

	nat = ia64_get_scratch_nat_bits(&scr->pt, scr->scratch_unat);

	err |= __put_user(flags, &sc->sc_flags);
	err |= __put_user(nat, &sc->sc_nat);
	err |= PUT_SIGSET(mask, &sc->sc_mask);
	err |= __put_user(cfm, &sc->sc_cfm);
	err |= __put_user(scr->pt.cr_ipsr & IA64_PSR_UM, &sc->sc_um);
	err |= __put_user(scr->pt.ar_rsc, &sc->sc_ar_rsc);
	err |= __put_user(scr->pt.ar_unat, &sc->sc_ar_unat);		/*         */
	err |= __put_user(scr->pt.ar_fpsr, &sc->sc_ar_fpsr);		/*         */
	err |= __put_user(scr->pt.ar_pfs, &sc->sc_ar_pfs);
	err |= __put_user(scr->pt.pr, &sc->sc_pr);			/*            */
	err |= __put_user(scr->pt.b0, &sc->sc_br[0]);			/*         */
	err |= __put_user(scr->pt.b6, &sc->sc_br[6]);			/*    */
	err |= __copy_to_user(&sc->sc_gr[1], &scr->pt.r1, 8);		/*    */
	err |= __copy_to_user(&sc->sc_gr[8], &scr->pt.r8, 4*8);		/*        */
	err |= __copy_to_user(&sc->sc_gr[12], &scr->pt.r12, 2*8);	/*         */
	err |= __copy_to_user(&sc->sc_gr[15], &scr->pt.r15, 8);		/*     */
	err |= __put_user(scr->pt.cr_iip + ia64_psr(&scr->pt)->ri, &sc->sc_ip);

	if (!(flags & IA64_SC_FLAG_IN_SYSCALL)) {
		/*                                                                           */
		err |= __put_user(scr->pt.ar_ccv, &sc->sc_ar_ccv);		/*        */
		err |= __put_user(scr->pt.b7, &sc->sc_br[7]);			/*    */
		err |= __put_user(scr->pt.r14, &sc->sc_gr[14]);			/*     */
		err |= __copy_to_user(&sc->sc_ar25, &scr->pt.ar_csd, 2*8); /*                 */
		err |= __copy_to_user(&sc->sc_gr[2], &scr->pt.r2, 2*8);		/*       */
		err |= __copy_to_user(&sc->sc_gr[16], &scr->pt.r16, 16*8);	/*         */
	}
	return err;
}

/*
                                                                           
 */
static inline int
rbs_on_sig_stack (unsigned long bsp)
{
	return (bsp - current->sas_ss_sp < current->sas_ss_size);
}

static long
force_sigsegv_info (int sig, void __user *addr)
{
	unsigned long flags;
	struct siginfo si;

	if (sig == SIGSEGV) {
		/*
                                                             
                                         
                                                          
                                                       
                                                            
                                                            
          
   */
		spin_lock_irqsave(&current->sighand->siglock, flags);
		current->sighand->action[sig - 1].sa.sa_handler = SIG_DFL;
		spin_unlock_irqrestore(&current->sighand->siglock, flags);
	}
	si.si_signo = SIGSEGV;
	si.si_errno = 0;
	si.si_code = SI_KERNEL;
	si.si_pid = task_pid_vnr(current);
	si.si_uid = current_uid();
	si.si_addr = addr;
	force_sig_info(SIGSEGV, &si, current);
	return 0;
}

static long
setup_frame (int sig, struct k_sigaction *ka, siginfo_t *info, sigset_t *set,
	     struct sigscratch *scr)
{
	extern char __kernel_sigtramp[];
	unsigned long tramp_addr, new_rbs = 0, new_sp;
	struct sigframe __user *frame;
	long err;

	new_sp = scr->pt.r12;
	tramp_addr = (unsigned long) __kernel_sigtramp;
	if (ka->sa.sa_flags & SA_ONSTACK) {
		int onstack = sas_ss_flags(new_sp);

		if (onstack == 0) {
			new_sp = current->sas_ss_sp + current->sas_ss_size;
			/*
                                                          
                                                    
                                                         
                                                           
    */
			if (!rbs_on_sig_stack(scr->pt.ar_bspstore))
				new_rbs = ALIGN(current->sas_ss_sp,
						sizeof(long));
		} else if (onstack == SS_ONSTACK) {
			unsigned long check_sp;

			/*
                                                       
                                                        
                                          
    */
			check_sp = (new_sp - sizeof(*frame)) & -STACK_ALIGN;
			if (!likely(on_sig_stack(check_sp)))
				return force_sigsegv_info(sig, (void __user *)
							  check_sp);
		}
	}
	frame = (void __user *) ((new_sp - sizeof(*frame)) & -STACK_ALIGN);

	if (!access_ok(VERIFY_WRITE, frame, sizeof(*frame)))
		return force_sigsegv_info(sig, frame);

	err  = __put_user(sig, &frame->arg0);
	err |= __put_user(&frame->info, &frame->arg1);
	err |= __put_user(&frame->sc, &frame->arg2);
	err |= __put_user(new_rbs, &frame->sc.sc_rbs_base);
	err |= __put_user(0, &frame->sc.sc_loadrs);	/*                    */
	err |= __put_user(ka->sa.sa_handler, &frame->handler);

	err |= copy_siginfo_to_user(&frame->info, info);

	err |= __put_user(current->sas_ss_sp, &frame->sc.sc_stack.ss_sp);
	err |= __put_user(current->sas_ss_size, &frame->sc.sc_stack.ss_size);
	err |= __put_user(sas_ss_flags(scr->pt.r12), &frame->sc.sc_stack.ss_flags);
	err |= setup_sigcontext(&frame->sc, set, scr);

	if (unlikely(err))
		return force_sigsegv_info(sig, frame);

	scr->pt.r12 = (unsigned long) frame - 16;	/*                   */
	scr->pt.ar_fpsr = FPSR_DEFAULT;			/*                               */
	scr->pt.cr_iip = tramp_addr;
	ia64_psr(&scr->pt)->ri = 0;			/*                               */
	ia64_psr(&scr->pt)->be = 0;			/*                                */
	/*
                                                                            
                                                                                   
                                                                                
                                                                                
                                                                                   
                                                                         
  */
	scr->pt.cr_ifs = (1UL << 63);

	/*
                                                                               
                                            
  */
	scr->scratch_unat = 0; /*                                 */

#if DEBUG_SIG
	printk("SIG deliver (%s:%d): sig=%d sp=%lx ip=%lx handler=%p\n",
	       current->comm, current->pid, sig, scr->pt.r12, frame->sc.sc_ip, frame->handler);
#endif
	return 1;
}

static long
handle_signal (unsigned long sig, struct k_sigaction *ka, siginfo_t *info, sigset_t *oldset,
	       struct sigscratch *scr)
{
	if (!setup_frame(sig, ka, info, oldset, scr))
		return 0;

	spin_lock_irq(&current->sighand->siglock);
	sigorsets(&current->blocked, &current->blocked, &ka->sa.sa_mask);
	if (!(ka->sa.sa_flags & SA_NODEFER))
		sigaddset(&current->blocked, sig);
	recalc_sigpending();
	spin_unlock_irq(&current->sighand->siglock);

	/*
                                                       
  */
	tracehook_signal_handler(sig, info, ka, &scr->pt,
				 test_thread_flag(TIF_SINGLESTEP));

	return 1;
}

/*
                                                                                   
                                                                          
 */
void
ia64_do_signal (struct sigscratch *scr, long in_syscall)
{
	struct k_sigaction ka;
	sigset_t *oldset;
	siginfo_t info;
	long restart = in_syscall;
	long errno = scr->pt.r8;

	/*
                                                                                 
                                                                                 
                         
  */
	if (!user_mode(&scr->pt))
		return;

	if (current_thread_info()->status & TS_RESTORE_SIGMASK)
		oldset = &current->saved_sigmask;
	else
		oldset = &current->blocked;

	/*
                                                                                  
                                          
  */
	while (1) {
		int signr = get_signal_to_deliver(&info, &ka, &scr->pt, NULL);

		/*
                                                                          
                                                                          
                                                                        
                             
   */
		if ((long) scr->pt.r10 != -1)
			/*
                                                                       
                                                                         
                                                                      
                                                                   
    */
			restart = 0;

		if (signr <= 0)
			break;

		if (unlikely(restart)) {
			switch (errno) {
			      case ERESTART_RESTARTBLOCK:
			      case ERESTARTNOHAND:
				scr->pt.r8 = EINTR;
				/*                                 */
				break;

			      case ERESTARTSYS:
				if ((ka.sa.sa_flags & SA_RESTART) == 0) {
					scr->pt.r8 = EINTR;
					/*                                 */
					break;
				}
			      case ERESTARTNOINTR:
				ia64_decrement_ip(&scr->pt);
				restart = 0; /*                                                 */
			}
		}

		/*
                                                                            
                                                                      
   */
		if (handle_signal(signr, &ka, &info, oldset, scr)) {
			/*
                                                    
                                                        
                                                         
                                        
    */
			current_thread_info()->status &= ~TS_RESTORE_SIGMASK;
			return;
		}
	}

	/*                                 */
	if (restart) {
		/*                                               */
		if (errno == ERESTARTNOHAND || errno == ERESTARTSYS || errno == ERESTARTNOINTR
		    || errno == ERESTART_RESTARTBLOCK)
		{
			/*
                                                          
                                                            
                                               
    */
			ia64_decrement_ip(&scr->pt);
			if (errno == ERESTART_RESTARTBLOCK)
				scr->pt.r15 = __NR_restart_syscall;
		}
	}

	/*                                                               
         */
	if (current_thread_info()->status & TS_RESTORE_SIGMASK) {
		current_thread_info()->status &= ~TS_RESTORE_SIGMASK;
		sigprocmask(SIG_SETMASK, &current->saved_sigmask, NULL);
	}
}

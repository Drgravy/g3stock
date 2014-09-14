/*
                     
 */
#ifndef _ASM_IRQFLAGS_H
#define _ASM_IRQFLAGS_H

#ifndef __ASSEMBLY__
/*
                                                     
 */
#include <asm/hw_irq.h>

#else
#ifdef CONFIG_TRACE_IRQFLAGS
#ifdef CONFIG_IRQSOFF_TRACER
/*
                                                              
                                                                
                                   
 */
#define TRACE_WITH_FRAME_BUFFER(func)		\
	mflr	r0;				\
	stdu	r1, -32(r1);			\
	std	r0, 16(r1);			\
	stdu	r1, -32(r1);			\
	bl func;				\
	ld	r1, 0(r1);			\
	ld	r1, 0(r1);
#else
#define TRACE_WITH_FRAME_BUFFER(func)		\
	bl func;
#endif

/*
                                                                     
                                                                 
                         
 */
#define TRACE_ENABLE_INTS	TRACE_WITH_FRAME_BUFFER(.trace_hardirqs_on)
#define TRACE_DISABLE_INTS	TRACE_WITH_FRAME_BUFFER(.trace_hardirqs_off)

/*
                                                           
 */
#define SOFT_DISABLE_INTS(__rA, __rB)		\
	lbz	__rA,PACASOFTIRQEN(r13);	\
	lbz	__rB,PACAIRQHAPPENED(r13);	\
	cmpwi	cr0,__rA,0;			\
	li	__rA,0;				\
	ori	__rB,__rB,PACA_IRQ_HARD_DIS;	\
	stb	__rB,PACAIRQHAPPENED(r13);	\
	beq	44f;				\
	stb	__rA,PACASOFTIRQEN(r13);	\
	TRACE_DISABLE_INTS;			\
44:

#else
#define TRACE_ENABLE_INTS
#define TRACE_DISABLE_INTS

#define SOFT_DISABLE_INTS(__rA, __rB)		\
	lbz	__rA,PACAIRQHAPPENED(r13);	\
	li	__rB,0;				\
	ori	__rA,__rA,PACA_IRQ_HARD_DIS;	\
	stb	__rB,PACASOFTIRQEN(r13);	\
	stb	__rA,PACAIRQHAPPENED(r13)
#endif
#endif

#endif

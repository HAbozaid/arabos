#ifndef _ASM_H
#define	_ASM_H

#include "timer.h"

#ifdef __cplusplus
extern "C" {
#endif

#define ASM __asm__ __volatile__

#define rebp(ebp) ASM ( "movl %%ebp,%0" : "=a" (ebp));

#define lgdt(gdt_ptr) ASM("lgdt %0" :: "m" (gdt_ptr)) 
#define lidt(idt_ptr) ASM("lidt %0" :: "m" (idt_ptr))

#define lgs(gs) ASM("movw %%ax,%%gs" :: "a" (gs))
#define lfs(fs) ASM("movw %%ax,%%fs" :: "a" (fs))
#define les(es) ASM("movw %%ax,%%es" :: "a" (es))
#define lds(ds) ASM("movw %%ax,%%ds" :: "a" (ds))
#define lss(ss) ASM("movw %%ax,%%ss" :: "a" (ss))
#define lcs(cs) ASM("ljmp %0,$1f\n 1:\n" :: "i" (cs))

#define resp(esp) ASM("movl %%esp,%0" : "=a" (esp))
#define lesp(esp) ASM("movl %0,%%esp" :: "a" (esp))

#define reax(eax) ASM("movl %%eax,%0" : "=a" (eax))
#define leax(eax) ASM("movl %0,%%eax" :: "a" (eax))
    
#define rcr0(cr0) ASM ( "movl %%cr0,%0" : "=a" (cr0));
#define lcr0(cr0) ASM ( "movl %0,%%cr0" :: "a" (cr0));
    
#define rcr1(cr1) ASM ( "movl %%cr1,%0" : "=a" (cr1));
#define lcr1(cr1) ASM ( "movl %0,%%cr1" :: "a" (cr1));
    
#define rcr2(cr2) ASM ( "movl %%cr2,%0" : "=a" (cr2));
#define lcr2(cr2) ASM ( "movl %0,%%cr2" :: "a" (cr2));
    
#define rcr3(cr3) ASM ( "movl %%cr3,%0" : "=a" (cr3));
#define lcr3(cr3) ASM ( "movl %0,%%cr3" :: "a" (cr3));
    
#define rcr4(cr4) ASM ( "movl %%cr4,%0" : "=a" (cr4));
#define lcr4(cr4) ASM ( "movl %0,%%cr4" :: "a" (cr4));

#define hlt() ASM("hlt"); while(1)

#define cli() ASM("cli")
#define sti() ASM("sti")

#define invlpg(vaddr) ASM("invlpg %0" :: "m"(vaddr))
    
// val must be 64 bits long
#define rdtscll(val) ASM("rdtsc" : "=A" (val))

//;printk("\n--:%i\n",scheduling_started)
#define block_timer() --scheduling_started 
//;printk("\n++:%i\n",scheduling_started)
#define unmask_timer() ++scheduling_started 
    
void cpuid_check();
    
#ifdef __cplusplus    
}
#endif

#endif	/* _ASM_H */    

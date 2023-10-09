#include "stdint.h"
#include "stdbool.h"
#include "armcpu.h"
#include "dispatch.h"
#include "task.h"

extern tcb_t* running_tcb;
extern tcb_t* next_tcb;

/*
__attribute__ ((naked)) creates raw assembly
*/
__attribute__ ((naked)) void dispatcher(void)
{
    /*context switch*/
    __asm__ ("B save_context");
    __asm__ ("B restore_context");
}

/*save the context of running task*/
__attribute__ ((naked)) void save_context(void)
{
    /*
    save link register (not program counter)
    lr stored dispatcher's return address
    */
    __asm__ ("PUSH {lr}");

    /*save GPR*/
    __asm__ ("PUSH {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12}"); /*ARMv7 does not support the push {r0-r12} syntax.*/

    /*move cpsr -> r0*/
    __asm__ ("MRS r0, cpsr");
    __asm__ ("PUSH {r0}");

    /*r0 = pointer to pointer to running_tcb*/
    __asm__ ("LDR r0, =running_tcb");

    /*r0 = pointer to running_tcb*/
    __asm__ ("LDR r0, [r0]");

    /*
    cf. store multiple increment after
    save stack pointer
    */
    __asm__ ("STMIA r0!, {sp}");

}

/*restore the context of next task*/
__attribute__ ((naked)) void restore_context(void)
{
    /*r0 = pointer to pointer to next_tcb*/
    __asm__ ("LDR r0, =next_tcb");

    /*r0 = pointer to next_tcb*/
    __asm__ ("LDR r0, [r0]");

    /*restore the stack pointer*/
    __asm__ ("LDMIA r0!, {sp}");

    /*pop cpsr*/
    __asm__ ("POP {r0}");

    /*restore cpsr*/
    __asm__ ("MSR cpsr, r0");

    /*restore GPR*/
    __asm__ ("POP {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12}");

    /*restore program counter*/
    /*
    program counter changes immediately
    */
    __asm__ ("POP  {pc}");
}

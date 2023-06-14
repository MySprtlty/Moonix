#include "ARMv7AR.h"
#include "MemoryMap.h"

/*text section*/
.text
    .code 32

    .global vector_start /*extern label*/
    .global vector_end /*extern label*/

    vector_start:
        /*exception vector table*/
        LDR PC, reset_handler_addr /*jump to reset interrupt handler*/
        LDR PC, undef_handler_addr
        LDR PC, svc_handler_addr
        LDR PC, pftch_abt_handler_addr
        LDR PC, data_abt_handler_addr
        B   . /*jump to current location*/
        LDR PC, irq_handler_addr /*jump to reset irq handler*/
        LDR PC, fiq_handler_addr /*jump to reset fiq handler*/

        /*variable declaration*/
        reset_handler_addr:     .word reset_handler
        undef_handler_addr:     .word todo_handler
        svc_handler_addr:       .word todo_handler
        pftch_abt_handler_addr: .word todo_handler
        data_abt_handler_addr:  .word todo_handler
        irq_handler_addr:       .word Irq_Handler
        fiq_handler_addr:       .word Fiq_Handler
    vector_end:

    /*reset interrupt handler*/
    reset_handler:
        MRS r0, cpsr /*Move System Register(CPSR) to Register*/
        BIC r1, r0, #0x1F /*Bit clear*/
        ORR r1, r1, #ARM_MODE_BIT_SVC /*change mode to SVC*/
        MSR cpsr, r1 /*move Resiter to System Register*/
        LDR sp, =SVC_STACK_TOP /*init stack pointer*/

        MRS r0, cpsr
        BIC r1, r0, #0x1F
        ORR r1, r1, #ARM_MODE_BIT_IRQ /*change mode to IRQ*/
        MSR cpsr, r1
        LDR sp, =IRQ_STACK_TOP

        MRS r0, cpsr
        BIC r1, r0, #0x1F
        ORR r1, r1, #ARM_MODE_BIT_FIQ /*change mode to FIQ*/
        MSR cpsr, r1
        LDR sp, =FIQ_STACK_TOP

        MRS r0, cpsr
        BIC r1, r0, #0x1F
        ORR r1, r1, #ARM_MODE_BIT_ABT /*change mode to ABT*/
        MSR cpsr, r1
        LDR sp, =ABT_STACK_TOP

        MRS r0, cpsr
        BIC r1, r0, #0x1F
        ORR r1, r1, #ARM_MODE_BIT_UND /*change mode to UND*/
        MSR cpsr, r1
        LDR sp, =UND_STACK_TOP

        MRS r0, cpsr
        BIC r1, r0, #0x1F
        ORR r1, r1, #ARM_MODE_BIT_SYS /*change mode to SYS*/
        MSR cpsr, r1
        LDR sp, =USRSYS_STACK_TOP

        BL  main

    todo_handler:
        B .
.end

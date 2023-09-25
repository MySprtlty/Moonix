#ifndef TASK_H
#define TASK_H

#include "MemoryMap.h"

#define FULL_TASK_NUM 0xFFFFFFFF
#define USR_TASK_STACK_SIZE 0x80000 /*2^19 Byte*/
#define MAX_TASK_NUM (TASK_STACK_SIZE / USR_TASK_STACK_SIZE) /*128*/
#define PADDING 4

typedef struct taskContext_t
{
	uint32_t spsr, r[13], pc;
} task_context_t;

typedef struct tcb_t
{
	uint32_t sp;
	uint8_t *stack_base;
	uint8_t nice; /*priority*/
} tcb_t;

typedef void (*taskFunc_t)(void);

void task_init(void);
uint32_t task_create(taskFunc_t taskFunc);

#endif /*TASK_H*/

#include "stdint.h"
#include "stdbool.h"
#include "ARMv7AR.h"
#include "task.h"

/*task info*/
static tcb_t task_list[MAX_TASK_NUM]; /*128*/
static uint32_t task_list_top_index; 
static uint32_t running_tcb_index; /*running task*/

/*scheduler*/
extern tcb_t *sched_round_robin(uint32_t* const, const uint32_t*, tcb_t*); /*temporary scheduler*/
extern tcb_t *sched_priority_based(uint32_t* const, const uint32_t*, tcb_t*);

/*init task_list (array of tcb)*/
void task_init(void)
{
    uint32_t i = 0;
    task_list_top_index = 0;
    task_context_t *ptc = (void *)0;

    for(i = 0; i < MAX_TASK_NUM; i++)
    {
        task_list[i].stack_base = (uint8_t *)(TASK_STACK_START + i * USR_TASK_STACK_SIZE);
        task_list[i].sp = (uint32_t)task_list[i].stack_base + USR_TASK_STACK_SIZE - PADDING;

        task_list[i].sp -= sizeof (task_context_t);
        ptc = (task_context_t *)task_list[i].sp;
        ptc->pc = 0;
        ptc->spsr = ARM_MODE_BIT_SYS;
    }

    return;
}

#if 0
uint32_t task_create(task_func_t task_func)
{

}
#endif
 


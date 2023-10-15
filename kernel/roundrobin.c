/*
    temporary scheduler
*/

#include "stdint.h"
#include "stdbool.h"
#include "ARMv7AR.h"
#include "task.h"

extern tcb_t task_list[MAX_TASK_NUM]; /*128*/
extern uint32_t task_list_top_index; 
extern uint32_t running_tcb_index; /*running task*/

tcb_t *sched_round_robin(void)
{
    running_tcb_index++;
    running_tcb_index %= task_list_top_index;

    return &task_list[running_tcb_index];
}
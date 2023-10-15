/*
    temporary scheduler
*/

#include "stdint.h"
#include "stdbool.h"
#include "ARMv7AR.h"
#include "task.h"

extern tcb_t task_list[MAX_TASK_NUM];
extern uint32_t task_list_top_index; 
extern tcb_t *running_tcb;

tcb_t *sched_priority_based(void)
{
    uint32_t i = 0;
    for(i = 0; i < task_list_top_index; i++)
    {
        tcb_t *next_tcb = &task_list[i];
        if(next_tcb != running_tcb)
        {
            if (next_tcb->nice <= running_tcb->nice)
            {
                return next_tcb;
            }
        }
    }
    return running_tcb;
}
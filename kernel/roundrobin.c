/*
    temporary scheduler
*/

#include "task.h"
#include "stdint.h"

/*round robin sched*/
tcb_t *sched_round_robin(uint32_t* const running, const uint32_t *top, tcb_t* list)
{
    (*running)++;
    *running = *running % *top;

    return &list[*running];
}
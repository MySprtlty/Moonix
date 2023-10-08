/*
    temporary scheduler
*/

#include "stdint.h"
#include "stdbool.h"
#include "ARMv7AR.h"
#include "task.h"

/*round robin sched*/
tcb_t *sched_round_robin(uint32_t* const running, const uint32_t *top, tcb_t* list)
{
    (*running)++;
    *running = *running % *top;

    return &list[*running];
}
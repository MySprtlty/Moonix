#include "stdint.h"
#include "stdbool.h"
#include "HalTimer.h"

static uint32_t start, stop;

void sleep(uint32_t ms)
{
    uint32_t target = Hal_timer_get_1ms_counter() + ms;

    while(target != Hal_timer_get_1ms_counter());
}

/*to measure tasks' cpu time*/
void start_user_timer(void)
{
    start = Hal_timer_get_1ms_counter();
}

uint32_t stop_user_timer(void)
{
    stop = Hal_timer_get_1ms_counter();
    int64_t interval = stop - start;

    if(interval >= 0)
    {
        return interval;
    }

    /*if interval < 0, it indicates that the hardware timer count underwent a modulo operation.*/
    return UINT32_MAX + interval;
}
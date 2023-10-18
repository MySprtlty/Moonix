#include "stdint.h"
#include "stdbool.h"
#include "stdio.h"
#include "event.h"

static uint32_t kernel_event_flag;

void event_flag_init(void)
{
    kernel_event_flag = 0;
}

void event_flag_set(event_flag_t event)
{
    kernel_event_flag |= (uint32_t)event;
}

void event_flag_clear(event_flag_t event)
{
    kernel_event_flag &= ~((uint32_t)event);
}

bool event_flag_check(event_flag_t event)
{
    if(kernel_event_flag & (uint32_t)event)
    {
        event_flag_clear(event);
        return true;
    }
    return false;
}
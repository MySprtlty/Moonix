/*
    Kernel API
*/

#include "stdint.h"
#include "stdbool.h"
#include "stdlib.h"

#include "kernel.h"

void kernel_yield_cpu(void)
{
    task_scheduler();
}

void kernel_start(void)
{   
    print_moonix(3000);
    task_start();
}

/*--------------------------------------------*/
/*Semaphore API*/
void kernel_semaphore_lock(resource_t resource)
{   
    while(!semaphore_signal(resource))
    {
        kernel_yield_cpu();
    }
}

void kernel_semaphore_unlock(resource_t resource)
{
    semaphore_wait(resource);
}

/*--------------------------------------------*/
/*
    Events API
    set the event flag using the bitwise OR operation.
    ex) EVENT_FLAG_Reserved03 | EVENT_FLAG_Reserved13 | EVENT_FLAG_Reserved22
*/
void kernel_trigger_events(uint32_t events) 
{
    event_flag_t event_buf = EVENT_FLAG_NULL; /*0x00000000*/

    for (uint32_t i = 0 ; i < 32 ; i++)
    {
        if ((events >> i) & 0x1)
        {
            SET_BIT(event_buf, i); /*set the bit at the current position.*/
            event_flag_set(event_buf);
        }
    }
}

event_flag_t kernel_monitor_events(uint32_t events) /*set the event flag using the bitwise OR operation.*/
{
    event_flag_t event_buf = EVENT_FLAG_NULL; /*0x00000000*/

    for (uint32_t i = 0 ; i < 32 ; i++)
    {
        if ((events >> i) & 0x1)
        {
            SET_BIT(event_buf, i); /*set the bit at the current position.*/

            if (event_flag_check(event_buf))
            {
                return event_buf;
            }
        }
    }

    return EVENT_FLAG_NULL;
}
/*
    Kernel API
*/

#include "stdint.h"
#include "stdbool.h"
#include "stdlib.h"
#include "CtrlBit.h"

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
/*
    Semaphore API
*/
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

/*--------------------------------------------*/
/*
    Message API
*/
bool kernel_send_msg(msgQ_task_t q_name, uint8_t* data, uint32_t count)
{
    uint32_t rear = 0 , front = 0, msgQ_count = 0;

    if(msgQ_get_rear(q_name, &rear) && msgQ_get_front(q_name, &front))
    {
        msgQ_count = rear - front;
    }
    else /*invalid q_name*/
    {
        return false;
    }

	if (count > (MSGQ_SIZE - msgQ_count))
	{
		return false;
	}

    for (uint32_t i = 0 ; i < count ; i++, data++)
    {
        if (!msgQ_enQ(q_name, *data))
        {
            return false;
        }
    }

    return true;
}

uint32_t kernel_recv_msg(msgQ_task_t q_name, uint8_t* data, uint32_t count)
{
    for (uint32_t i = 0 ; i < count ; i++, data++)
    {
        if (!msgQ_deQ(q_name, data))
        {
            return i;
        }
    }

    return count;
}
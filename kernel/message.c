#include "stdint.h"
#include "stdbool.h"
#include "stdlib.h"
#include "message.h"

static cirQ_t msgQ[MSGQ_TASK_NUM];

bool msgQ_is_valid(const msgQ_task_t q_name)
{
    if(q_name < MSGQ_TASK_NUM)
    {
        return true;
    }
    return false;
}

void msgQ_init(void)
{
    uint32_t size = 0 ;
    uint8_t *pq = (void *)0;
    for(uint32_t i = 0; i < MSGQ_TASK_NUM; i++)
    {
        size = MSGQ_SIZE;
        pq = msgQ[i].queue; /*decay array to pointer*/
        msgQ[i].front = 0;
        msgQ[i].rear = 0;
        while(size--)
        {
            *pq++ = 0;
        }
    }
}
bool msgQ_is_empty(const msgQ_task_t q_name)
{   
    if(msgQ_is_valid(q_name))
    {
        return false;
    }
    if(msgQ[q_name].front == msgQ[q_name].rear)
    {
        return true;
    }
    return false;
}

bool msgQ_is_full(msgQ_task_t q_name)
{
    if(msgQ_is_valid(q_name))
    {
        return false;
    }
    if(((msgQ[q_name].rear + 1) % MSGQ_SIZE) == msgQ[q_name].front)
    {
        return true;
    }
    return false;
}


bool msgQ_is_enQ(msgQ_task_t q_name, uint8_t d)
{
    if(msgQ_is_valid(q_name))
    {
        return false;
    }
    if(msgQ_is_full(q_name))
    {
        return false;
    }
    msgQ[q_name].rear++;
    msgQ[q_name].rear %= MSGQ_SIZE; /*for preventing overflow*/

    uint32_t rear = msgQ[q_name].rear;
    msgQ[q_name].queue[rear] = d;

    return true;
}

bool msgQ_is_deQ(msgQ_task_t q_name, uint8_t* d)
{
    if(msgQ_is_valid(q_name))
    {
        return false;
    }
    if(msgQ_is_empty(q_name))
    {
        return false;
    }

    msgQ[q_name].front++;
    msgQ[q_name].front %= MSGQ_SIZE; /*for preventing overflow*/
    uint32_t front = msgQ[q_name].front;
    *d = msgQ[q_name].queue[front];

    return true;
}

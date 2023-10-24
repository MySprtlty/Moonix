#ifndef MSG_H_
#define MSG_H_

#define MSGQ_SIZE 1024

/*type for designating the task's message queue*/
typedef enum msgQ_task_t
{
    MSGQ_TASK000,
    MSGQ_TASK001,
    MSGQ_TASK002,
    MSGQ_TASK003,
    MSGQ_TASK004,
    MSGQ_TASK005,
    MSGQ_TASK006,
    MSGQ_TASK007,
    MSGQ_TASK008,
    MSGQ_TASK009,
    MSGQ_TASK010,
    MSGQ_TASK011,
    MSGQ_TASK012,
    MSGQ_TASK013,
    MSGQ_TASK014,
    MSGQ_TASK015,
    /*...*/
    MSGQ_TASK_NUM /*the number of message queue*/
} msgQ_task_t;

/*circular queue*/
typedef struct cirQ_t
{
    uint32_t front;
    uint32_t rear;
    uint8_t queue[MSGQ_SIZE];
} cirQ_t;

bool msgQ_is_valid(const msgQ_task_t); /*is the queue name valid*/

bool msgQ_get_rear(msgQ_task_t, uint32_t * const); /*Get rear element of msgQ*/
bool msgQ_get_front(msgQ_task_t, uint32_t * const); /*Get front element of msgQ*/

void msgQ_init(void); /*init*/
bool msgQ_is_empty(const msgQ_task_t); /*is empty*/
bool msgQ_is_full(const msgQ_task_t); /*is full*/

bool msgQ_enQ(const msgQ_task_t, uint8_t); /*enqueue*/
bool msgQ_deQ(const msgQ_task_t, uint8_t*); /*dequeue*/

#endif
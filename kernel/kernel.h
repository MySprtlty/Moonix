#ifndef KERNEL_H_
#define KERNEL_H_

#include "task.h"
#include "semaphore.h"
#include "event.h"
#include "message.h"

void yield_cpu(void);
void kernel_start(void);

/*Semaphore API*/
void kernel_semaphore_lock(resource_t);
void kernel_semaphore_unlock(resource_t);

/*Event API*/
void kernel_trigger_events(uint32_t);
event_flag_t kernel_monitor_events(uint32_t);

/*Message API*/
bool kernel_send_msg(msgQ_task_t, uint8_t *, uint32_t);
uint32_t kernel_recv_msg(msgQ_task_t, uint8_t *, uint32_t);

#endif /* KERNEL_H_ */
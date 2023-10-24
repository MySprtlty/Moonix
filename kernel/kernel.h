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

#endif /* KERNEL_H_ */
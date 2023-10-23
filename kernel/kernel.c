/*
    Kernel API
*/

#include "stdint.h"
#include "stdbool.h"
#include "stdlib.h"
#include "semaphore.h"

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
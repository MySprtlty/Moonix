#include "stdint.h"
#include "stdbool.h"

#include "kernel.h"

void yield_cpu(void)
{
    task_scheduler();
}

void kernel_start(void)
{
    task_start();
}
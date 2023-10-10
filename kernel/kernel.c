#include "stdint.h"
#include "stdbool.h"
#include "stdlib.h"

#include "kernel.h"

void yield_cpu(void)
{
    task_scheduler();
}

void kernel_start(void)
{   
    print_moonix(3000);
    task_start();
}
#include "stdint.h"
#include "stdbool.h"

#include "HalUart.h"
#include "HalInterrupt.h"
#include "HalTimer.h"
#include "stdio.h"

#include "kernel.h"

static void Hw_init(void);
static void user_task0(void);
static void user_task1(void);
static void user_task2(void);
static void kernel_init(void);

void main(void)
{
    Hw_init();

    uint32_t i = 100;

    my_printf("%s\n", "my_printf works well!");
    putstr("Hello World!\n");

    kernel_init();
    while(true);
}

static void Hw_init(void)
{
    Hal_interrupt_init();
    Hal_uart_init();
    Hal_timer_init();
}

static void kernel_init(void)
{
    task_init();

    /*create tasks*/
    if(task_create(user_task0) == FULL_TASK_NUM)
    {
        my_printf("error: create user_task0\n");
    }

    if(task_create(user_task1) == FULL_TASK_NUM)
    {
        my_printf("error: create user_task1\n");
    }

    if(task_create(user_task2) == FULL_TASK_NUM)
    {
        my_printf("error: create user_task2\n");
    }
    
    kernel_start();
}

static void user_task0(void)
{
    while(true)
    {
        my_printf("user_task0 is running.\n");
        yield_cpu();
    }

}

static void user_task1(void)
{
    while(true)
    {
        my_printf("user_task1 is running.\n");
        yield_cpu();
    }
}

static void user_task2(void)
{
    while(true)
    {
        my_printf("user_task2 is running.\n");
        yield_cpu();
    }
}

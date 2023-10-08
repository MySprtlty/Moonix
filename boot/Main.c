#include "stdint.h"
#include "stdbool.h"

#include "HalUart.h"
#include "HalInterrupt.h"
#include "stdio.h"

#include "task.h"

static void Hw_init(void);
static void user_task0(void);
static void user_task1(void);
static void user_task2(void);

void main(void)
{
    Hw_init();

    uint32_t i = 100;

    my_printf("%s\n", "my_printf works well!");
    putstr("Hello World!\n");

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
        my_printf("error: create user_task0");
    }

    if(task_create(user_task1) == FULL_TASK_NUM)
    {
        my_printf("error: create user_task1");
    }

    if(task_create(user_task2) == FULL_TASK_NUM)
    {
        my_printf("error: create user_task2");
    }
}

static void user_task0(void)
{
    my_printf("user_task0 is running.");
}

static void user_task1(void)
{
    my_printf("user_task1 is running.");
}

static void user_task2(void)
{
    my_printf("user_task2 is running.");
}

#include "stdint.h"
#include "stdbool.h"
#include "stdlib.h"

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
        my_printf("task0] running\n");
        start_user_timer();
        /*factorial*/

        uint32_t i = 0;   
        uint32_t num = rand_range_int(4, 10);
        uint32_t result = 1;

        for (i = 1; i <= num; i++) 
        {
            result *= i;
        }
        my_printf("task0] %u! == %u\n", num, result);
        /*fatrial end*/

        sleep(rand_int(5000));
        my_printf("task0] cpu time: %ums\n",stop_user_timer());
        my_printf("task0] yielding the CPU\n");

        yield_cpu();
    }

}

static void user_task1(void)
{
    while(true)
    {
        my_printf("task1] running\n");
        start_user_timer();

        /*find prime*/
        uint32_t n = rand_range_int(4, 100);
        uint32_t num = 0;
        uint32_t i = 0;
        my_printf("task1] prime numbers up to %u\n", n);

        my_printf("task1] ");
        for (num = 2; num <= n; num++) {
            bool isPrime = true;

            for (i = 2; i * i <= num; i++) {
                if (num % i == 0) {
                    isPrime = false;
                    break;
                }
            }

            if (isPrime) {
                my_printf("%u ", num);
            }
        }
        my_printf("\n");
        /*find prime end*/

        sleep(rand_int(5000));
        my_printf("task1] cpu time: %ums\n",stop_user_timer());
        my_printf("task1] yielding the CPU\n");
        
        yield_cpu();
    }
}

static void user_task2(void)
{
    while(true)
    {
        my_printf("task2] running\n");
        start_user_timer();
        
        /*fibonacci*/
        uint32_t n = rand_range_int(3, 10), i = 0, t1 = 0, t2 = 1, nextTerm;

        my_printf("task2] first %u terms of fibonacci sequence\n", n);
        my_printf("task2] ");
        for (i = 1; i <= n; ++i) {
            my_printf("%u ", t1);
            nextTerm = t1 + t2;
            t1 = t2;
            t2 = nextTerm;
        }
        my_printf("\n");
        /*fibonacci end*/

        sleep(rand_int(5000));
        my_printf("task2] cpu time: %ums\n",stop_user_timer());
        my_printf("task2] yielding the CPU\n");

        yield_cpu();
    }
}

#include "stdint.h"
#include "Timer.h"
#include "HalTimer.h"
#include "HalInterrupt.h"

extern volatile Timer_t* Timer;
static uint32_t sInternal_1ms_counter;

static void timer_interrupt_handler(void);

void Hal_timer_init(void)
{
    // register reset
    Timer->timerxcontrol.bits.TimerEn = 0; /*Timer OFF*/
    Timer->timerxcontrol.bits.TimerMode = 0; /*free-running*/
    Timer->timerxcontrol.bits.OneShot = 0; 
    Timer->timerxcontrol.bits.TimerSize = 0;
    Timer->timerxcontrol.bits.TimerPre = 0;
    Timer->timerxcontrol.bits.IntEnable = 1;
    Timer->timerxload = 0;
    Timer->timerxvalue = 0xFFFFFFFF;

    // set periodic mode
    Timer->timerxcontrol.bits.TimerMode = TIMER_PERIOIC; 
    Timer->timerxcontrol.bits.TimerSize = TIMER_32BIT_COUNTER; /*32bit*/
    Timer->timerxcontrol.bits.OneShot = 0;
    Timer->timerxcontrol.bits.TimerPre = 0;
    Timer->timerxcontrol.bits.IntEnable = 1; /*interrupt ON*/

    uint32_t interval_1ms = TIMER_1MZ_INTERVAL / 1000;

    Timer->timerxload = interval_1ms;
    Timer->timerxcontrol.bits.TimerEn = 1; /*Timer ON*/

    sInternal_1ms_counter = 0;

    // Register Timer interrupt handler
    Hal_interrupt_enable(TIMER_INTERRUPT);
    Hal_interrupt_register_handler(timer_interrupt_handler, TIMER_INTERRUPT);
}

uint32_t Hal_timer_get_1ms_counter(void)
{
    return sInternal_1ms_counter;
}

/*every 1ms*/
static void timer_interrupt_handler(void)
{
    sInternal_1ms_counter++;
    Timer->timerxintclr = 1; /*interrupt handler completed*/
}

#include "stdint.h"
#include "stdbool.h"
#include "stdio.h"
#include "event.h"

static defEH defEH_list[32]; /*array of 32 pointer to default event handler*/
static uint32_t kernel_event_flag;

void event_flag_init(void)
{
    kernel_event_flag = 0;
    for(uint32_t i = 0; i < 32; i++)
    {
        defEH_list[i] = (void *)0;
    }
}

void event_flag_set(event_flag_t event)
{
    kernel_event_flag |= (uint32_t)event;
}

void event_flag_clear(event_flag_t event)
{
    kernel_event_flag &= ~((uint32_t)event);
}

bool event_flag_check(event_flag_t event)
{
    if(kernel_event_flag & (uint32_t)event)
    {
        event_flag_clear(event);
        return true;
    }
    return false;
}

uint32_t event_flag_to_index(event_flag_t event) {
    for (uint32_t i = 0; i < 32; i++) {
        if (event >> i & 0x1) {
            return i;
        }
    }
    return 31;
}

/*register the default event handler*/
void register_defEH(event_flag_t event, defEH func)
{
    defEH_list[event_flag_to_index(event)] = func;
}

/*remove the default event handler*/
void remove_defEH(event_flag_t event)
{
    defEH_list[event_flag_to_index(event)] = (void *)0;
}
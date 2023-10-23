#include "stdint.h"
#include "stdbool.h"
#include "semaphore.h"

static int32_t semaphore_max;
static int32_t semaphore_list[RESOURCE_MAX];

void semaphore_init(void)
{
    for(uint32_t i = 0; i < RESOURCE_MAX; i++)
    {   
        semaphore_list[i] = DEFAULT_SEM_MAX;
    }
}

bool semaphore_redefine(resource_t resource, uint32_t max)
{   
    if(resource < 0) /*invalid resource name*/
    {
        return false;
    }
    if(max <= 0)
    {
        return false;
    }
    semaphore_list[resource] = max;
    return true;
}

bool semaphore_signal(resource_t resource)
{   
    if(resource < 0) /*invalid resource name*/
    {
        return false;
    }
    if(semaphore_list[resource] <= 0)
    {
        return false;
    }
    semaphore_list[resource]--;
    
    return true;
}

bool semaphore_wait(resource_t resource)
{
    if(resource < 0) /*invalid resource name*/
    {
        return false;
    }
    semaphore_list[resource]++;

    return true;
}
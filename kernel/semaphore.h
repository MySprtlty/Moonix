#ifndef SEMAPHORE_H_
#define SEMAPHORE_H_

#define DEFAULT_SEM_MAX 5

/*type for designating the resource*/
typedef enum resource_t
{
    RESOURCE_Reserved00,
    RESOURCE_Reserved01,
    RESOURCE_Reserved02,
    RESOURCE_Reserved03,
    RESOURCE_Reserved04,
    RESOURCE_Reserved05,
    RESOURCE_Reserved06,
    RESOURCE_Reserved07,
    RESOURCE_MAX
}resource_t;

void semaphore_init(void);
bool semaphore_redefine(resource_t, uint32_t);
bool semaphore_signal(resource_t); /*semaphore--*/
bool semaphore_wait(resource_t); /*semaphore++*/


#endif /*SEMAPHORE_H_*/
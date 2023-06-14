#include "stdint.h"
#include "Uart.h"
#include "Interrupt.h"

/*pointer to HW object*/
volatile PL011_t* const Uart    = (PL011_t*)UART_BASE_ADDRESS0;
volatile GicCput_t* const GicCpu  = (GicCput_t*)GIC_CPU_BASE;
volatile GicDist_t* const GicDist = (GicDist_t*)GIC_DIST_BASE;


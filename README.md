![Moonix2](https://github.com/MySprtlty/Moonix/assets/89295517/b0c79c48-20e1-4c4e-aacd-4c8542097e5d)
# Moonix
- A Real-Time Operating System(RTOS) targeted for the ARM Cortex-A8 board.

## 1. Links
- Detailed Description: [Moonix](https://night-skink-d1c.notion.site/Moonix-121db89b5df24ce09b86fdcafa1b1611)

## 2. Key Features
- Non-Preemptive Scheduling
- Configuration and management of Timer, UART, and Interrupt Controller.
- Interrupt and Exception Handling
- Inter-Process Communication (IPC)
- Synchronization Mechanism

## 3. Development Environment
| Category | Tool/Technology |
|:---|:---|
| Languages | C, ARMv7-A Assembly |
| Editor | vim |
| Build Tools | gcc-ARM-none-eabi |
| Other Tools | git, make, shell scripts, gdb, qemu |

## 4. Design
- Selection of operational modes for ARM to optimize performance.
- Utilized HAL to enhance code portability across different hardware platforms.
- Designed the memory structure.
- Designed kernel data structures for Tasks, Interrupts/Exceptions, and IPC.
- Chose Non-Preemptive Scheduling to manage process execution priorities.
- Developed mechanisms for task synchronization within the kernel.
- Designed kernel API functions to facilitate interaction with the OS functionalities.

## 5. Implementation
- Conducted initial hardware setup upon power-up of the ARM core.
- Differentiated and processed various types of interrupts using the Interrupt Controller.
- Developed kernel API functions and essential libraries.
- Implemented context switching and designed scheduler/dispatcher
- Developed IPC mechanisms using message queues and event flags.
- Implemented semaphores as a synchronization tool to manage access to resources.

## 6. Directory Structure
```text
moonix
├── boot
│ ├── Entry.S //  Contains the exception vector table.
│ ├── Handler.c // Defines IRQ and FIQ exception handlers.
│ └── Main.c
├── hal // Hardware Abstraction Layer
│ ├── HalInterrupt.h // Common API functions for interrupts.
│ ├── HalTimer.h // Common API functions for timer management.
│ ├── HalUart.h // Common API functions for UART.
│ ├── rvpb // Machine-specific code for RealView PB.
│ │ ├── Interrupt.c // Interrupt-specific common API functions.
│ │ ├── Interrupt.h // Interrupt controller structure declaration.
│ │ ├── ISP1761.h // USB structure declaration.
│ │ ├── Regs.c // Variables for hardware access.
│ │ ├── Timer.c // Timer-specific common API functions.
│ │ ├── Timer.h // Timer structure declaration.
│ │ ├── Uart.c // UART-specific common API functions.
│ │ └── Uart.h // UART structure declaration.
│ └── versatilepb // Machine-specific code for Versatile PB.
│ └── nuri // Machine-specific code for Nuri.
├── include
│ ├── ARMv7AR.h // Macros for operating modes.
│ ├── CtrlBit.h // Bit manipulation macros.
│ ├── MemoryMap.h // Memory mapping macros.
│ ├── stdarg.h // Variable arguments macros.
│ ├── stdbool.h
│ └── stdint.h // Primitive system data types (C99).
├── kernel
│ ├── message.c // Message queue.
│ ├── message.h
│ ├── event.c // Event flag.
│ ├── event.h
│ ├── kernel.c // Kernel API.
│ ├── kernel.h
│ ├── priorityBased.c // Priority scheduling.
│ ├── roundrobin.c // Round-robin scheduling.
│ ├── task.c // Task creation and initialization, TCB.
│ └── task.h // TCB and task context structures.
├── lib
│ ├── armcpu.c // Code to enable/disable IRQ and FIQ.
│ ├── armcpu.h
│ ├── dispatch.c // Context switching.
│ ├── dispatch.h
│ ├── stdio.c // Defines the printf function.
│ └── stdio.h
│ └── stdlib.c // Defines library functions.
│ └── stdlib.h
├── Makefile
├── moonix.ld // Linker script.
└── README.md
```
## 7. References
- [ARM info center](https://developer.arm.com/documentation/dui0417/d/?lang=en)
### 7-1. Timer (SP804)
- [Summary of registers](https://developer.arm.com/documentation/ddi0271/d/programmer-s-model/summary-of-registers)
- [Interface reset](https://developer.arm.com/documentation/ddi0271/d/functional-overview/functional-description/interface-reset?lang=en)

### 7-2. Philips ISP1761 controller
- [Data sheet](https://pdf1.alldatasheet.co.kr/datasheet-pdf/view/103865/PHILIPS/ISP1761.html)
- [USB interface](https://developer.arm.com/documentation/dui0417/d/programmer-s-reference/usb-interface?lang=en)

### 7-3. UART (PL011) 
- [Summary of registers](https://developer.arm.com/documentation/ddi0183/g/programmers-model/summary-of-registers?lang=en)
- [UARTDR](https://developer.arm.com/documentation/ddi0183/g/programmers-model/register-descriptions/data-register--uartdr?lang=en)
- [UART base address](https://developer.arm.com/documentation/dui0417/d/programmer-s-reference/uart?lang=en)

### 7-4. GIC
- [GIC registers](https://developer.arm.com/documentation/dui0417/d/programmer-s-reference/generic-interrupt-controller--gic/generic-interrupt-controller-registers?lang=en)
- [GIC-interput signal](https://velog.io/write?id=936cb7da-2d0d-48c5-8fd1-477b70b46bbe)

### 7-5. RealView PB
- [SYS_ID](https://developer.arm.com/documentation/dui0417/d/programmer-s-reference/status-and-system-control-registers/id-register--sys-id?lang=en)


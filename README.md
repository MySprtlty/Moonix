![Moonix](https://github.com/MySprtlty/Moonix/assets/89295517/12f41d4a-4b50-48a6-8ae0-a819ea486f28)
# Moonix
- RTOS for ARM Cortex-A8 processor board (RealView PB)
- Uses Non Preemptive Priority Scheduling
- Manages various hardware
- Interrupt/Exception handling
- Supports IPC (Inter-Process Communication)
- Synchronization mechanism (semaphore)

## 1. Development Environment
|구분|내용|
|:---|:---|
|OS|Linux Mint|
|Emulator|qemu|
|Lang|C99, ARMv7-A Assembly|
|Editor|vim|
|Tool-chain|gcc-ARM-none-eabi|
|etc|git, make, shell script, gdb|

## 2. Architecture
### 1) tree
```text
moonix
├── boot
│ ├── Entry.S // exception vector table이 포함되어 있다.
│ ├── Handler.c // IRQ, FIQ exception handler가 정의되어 있다.
│ └── Main.c
├── hal // hal 계층
│ ├── HalInterrupt.h // interrupt 공용 API 함수
│ ├── HalTimer.h // Timer처리 공용 API 함수
│ ├── HalUart.h // UART 공용 API 함수
│ ├── rvpb // machine RealView PB에 종속적인 코드
│ │ ├── Interrupt.c // interrupt 공용 API 함수를 rvpb에 종속적으로 정의
│ │ ├── Interrupt.h // rvpb의 interrupt controller 구조체 선언
│ │ ├── ISP1761.h // rvpb의 usb 구조체 선언
│ │ ├── Regs.c // 하드웨어에 접근하는 변수 정의
│ │ ├── Timer.c // Timer 공용 API 함수를 rvpb에 종속적으로 정의
│ │ ├── Timer.h // rvpb의 Timer 구조체 선언
│ │ ├── Uart.c // UART 공용 API 함수를 rvpb에 종속적으로 정의
│ │ └── Uart.h // rvpb의 UART 구조체 선언
│ └── versatilepb // machine versatilepb에 종속적인 코드
│ └── nuri // machine nuri에 종속적인 코드
├── include
│ ├── ARMv7AR.h // 동작 mode 관련 매크로 정의
│ ├── CtrlBit.h // 비트 조작 매크로 정의
│ ├── MemoryMap.h // 메모리 관련 매크로 정의
│ ├── stdarg.h // 가변 인자 관련 매크로 정의
│ ├── stdbool.h
│ └── stdint.h // Primitive System Data Type (C99)
├── kernel
│ ├── message.c // message queue
│ ├── message.h
│ ├── event.c // event flag
│ ├── event.h
│ ├── kernel.c // kernel API
│ ├── kernel.h
│ ├── priorityBased.c // priority scheduling
│ ├── roundrobin.c // RR scheduling (temporary scheduler)
│ ├── task.c // TCB와 task 생성 및 초기화 코드
│ └── task.h // TCB와 task의 context 구조체 정의
├── lib
│ ├── armcpu.c // IRQ, FIQ를 enable 또는 disable하는 코드
│ ├── armcpu.h
│ ├── dispatch.c // context switching
│ ├── dispatch.h
│ ├── stdio.c // printf함수 정의
│ └── stdio.h
│ └── stdlib.c // 라이브러리 함수 정의
│ └── stdlib.h
├── Makefile
├── moonix.ld // linker script
└── README.md
```
### 2) Memory Structure
![Moonix's Memory  500KB](https://github.com/MySprtlty/Moonix/assets/89295517/4c6c6145-590a-40e4-82b7-26b6e6d4877f)

### 3) TCB
![Moonix's TCB](https://github.com/MySprtlty/Moonix/assets/89295517/58482a58-4e04-4e1c-862b-c22a7afc2dde)

### 4) Library function
- 편의를 위해 구현한 라이브러리 함수다.

|Identifier|Comment|
|:---|:---|
|`void start_user_timer(void)`| task의 cpu time을 측정하기 위한 user timer 시작점|
|`uint32_t stop_user_timer(void)`| task의 cpu time을 측정하기 위한 user timer 종료지점|
|`uint32_t rand_int(const uint32_t)`|무작위 정수 반환|
|`uint32_t rand_range_int(const uint32_t, const uint32_t)`|무작위 정수 반환 (범위 지정)|
|`void print_moonix(const uint32_t)`|Moonix logo 출력|
|`void sleep(uint32_t)`|지정한 시간 만큼 지연시킨다.|

---
## 3. DataSheet
- [arm info center](https://developer.arm.com/documentation/dui0417/d/?lang=en)
### 1) Timer (SP804)
- [Summary of registers](https://developer.arm.com/documentation/ddi0271/d/programmer-s-model/summary-of-registers)
- [Interface reset](https://developer.arm.com/documentation/ddi0271/d/functional-overview/functional-description/interface-reset?lang=en)

### 2) Philips ISP1761 controller
- [Data sheet](https://pdf1.alldatasheet.co.kr/datasheet-pdf/view/103865/PHILIPS/ISP1761.html)
- [USB interface](https://developer.arm.com/documentation/dui0417/d/programmer-s-reference/usb-interface?lang=en)

### 3) UART (PL011) 
- [Summary of registers](https://developer.arm.com/documentation/ddi0183/g/programmers-model/summary-of-registers?lang=en)
- [UARTDR](https://developer.arm.com/documentation/ddi0183/g/programmers-model/register-descriptions/data-register--uartdr?lang=en)
- [UART base address](https://developer.arm.com/documentation/dui0417/d/programmer-s-reference/uart?lang=en)

### 4) GIC
- [GIC Registers](https://developer.arm.com/documentation/dui0417/d/programmer-s-reference/generic-interrupt-controller--gic/generic-interrupt-controller-registers?lang=en)
- [GIC-Interput Signal](https://velog.io/write?id=936cb7da-2d0d-48c5-8fd1-477b70b46bbe)

### 5) RealView PB
- [SYS_ID](https://developer.arm.com/documentation/dui0417/d/programmer-s-reference/status-and-system-control-registers/id-register--sys-id?lang=en)
---
## 4. Interrupt signals
|INT ID|Interrupt|Source|Description|
|:---:|:---:|:---:|:---:|
|61|**USB**|PB-A8| Interrupt from USB controller IC|
|60|**Ethernet**|PB-A8|Interrupt from Ethernet controller IC|
|44|**UART0**|Southbridge|UART0|
|36|**Timer 0-1**|Southbridge|Timers 0 and 1|
- [arm info](https://developer.arm.com/documentation/dui0417/d/programmer-s-reference/generic-interrupt-controller--gic/interrupt-signals?lang=en)

# Moonix
- RTOS
- Non Preemptive Priority Scheduling

## 1. Architecture
### 1) Memory Structure
![Moonix's Memory  500KB](https://github.com/MySprtlty/Moonix/assets/89295517/4c6c6145-590a-40e4-82b7-26b6e6d4877f)

### 2) TCB
![Moonix's TCB](https://github.com/MySprtlty/Moonix/assets/89295517/58482a58-4e04-4e1c-862b-c22a7afc2dde)

---

## 2. DataSheet
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
- 
---

## 3. Qemu emlulation
### 1) USB emulation
- name "usb-storage", bus usb-bus

### 2) Ethernet emulation

---

## 4. Interrupt signals
|INT ID|Interrupt|Source|Description|
|:---:|:---:|:---:|:---:|
|61|**USB**|PB-A8| Interrupt from USB controller IC|
|60|**Ethernet**|PB-A8|Interrupt from Ethernet controller IC|
|44|**UART0**|Southbridge|UART0|
|36|**Timer 0-1**|Southbridge|Timers 0 and 1|
- [arm info](https://developer.arm.com/documentation/dui0417/d/programmer-s-reference/generic-interrupt-controller--gic/interrupt-signals?lang=en)

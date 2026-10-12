# Bare-Metal Embedded OS & Smart Electric Water Heater Controller

A production-grade, highly deterministic **Smart Electric Water Heater Control System** implemented from scratch on the **ATmega32 (8-bit AVR MCU)**. This project demonstrates advanced **Bare-Metal Software Development**, featuring a custom **Time-Triggered OS Scheduler**, dynamic peripheral configurations, and strict layer decoupling compliant with automotive and industrial firmware best practices.

---

## 🛠️ Architectural Highlight & System Design

Instead of relying on blocking delays (`TIM0_Delayms()`) or heavy RTOS overheads inside critical path tasks, this system is designed using a **SOLID SDK Layered Architecture** powered by a lightweight, deterministic **cooperative time-triggered scheduler** driven by a 16-bit hardware timer. 

To maximize system throughput and input responsiveness, user interactions and physical switch debouncing are processed inside the foreground loop using sequential non-blocking state checks, while timing-critical display frames and closed-loop temperature control loops run deterministically in the background under periodic timer ticks.

### Core Technical Pillars:
* **Custom Interrupt Infrastructure:** Bypassed `avr-libc` completely. Implemented a proprietary vector table hardware mapping (`VECTOR_TABLE_INTERRUPT.h`) to handle atomic ISR dispatching using naked compiler attributes (`__attribute__((signal))`).
* **Non-Blocking OS Scheduler:** Built a Task Control Block (TCB) scheduler driven by a precise **1ms Timer1 CTC Tick**, isolating execution boundaries for asynchronous dynamic task execution.
* **Full-Port Display Optimization:** Optimized the dual 7-Segment BCD interface to operate over a unified 8-bit port (`PORTB`) connected to `7SEG-BCD` direct decoders, completely eliminating legacy multiplexing delay latencies and ghosting vulnerabilities from the software layer.
* **Fixed-Point Thermal Scaling:** Realized highly accurate sensor tracking without floating-point math libraries, protecting memory-constrained stack spaces via long-word fixed-point algebraic shifting (`* 500UL / 1023UL`).

---

## 📂 Repository Architecture

```text
├── LIB/                        # Infrastructure & Utility Layer
│   ├── STD_TYPES.h             # Standardized bit-width definitions (u8, u16, u32)
│   ├── BIT_MATH.h              # High-performance bit manipulation macros
│   ├── PLATFORM.h              # Global hardware system clock constraints (16MHz)
│   └── VECTOR_TABLE_INTERRUPT.h # Proprietary hardware vector table abstraction
├── MCAL/                       # Microcontroller Abstraction Layer (Registers & Bit-Fields)
│   ├── DIO/                    # Digital Input/Output Driver
│   ├── ADC/                    # Analog-to-Digital Converter Driver
│   ├── TWI/                    # Two-Wire Interface (I2C) 400kHz Driver (Dynamic TWBR Formula)
│   └── TIM1/                   # 16-bit Timer1 System Tick Engine (CTC Mode)
├── HAL/                        # Hardware Abstraction Layer (External Appliances)
│   ├── SSD/                    # Non-blocking Full-Port BCD 7-Segment Display Module
│   ├── LM35/                   # Linear Analog Temperature Sensor Driver
│   ├── OVEN/                   # Transistor-Driven Heating Element Abstraction
│   ├── PELTIER/                # Transistor-Driven Dynamic Cooling Unit Driver
│   └── EEPROM/                 # I2C External Storage Driver (NM24C08F Data Persistence)
├── SERVICES/                   # Real-Time OS Services Layer
│   └── SCHEDULER/              # Cooperative Time-Triggered Task Scheduler Engine
└── APP/
    ├── main.c                  # Application Orchestration & Async State Machine
    └── main.h                  # Global Module Inclusions
```

---

## 📊 Thread Model & Dynamic Task Distribution

The system runtime execution relies on static synchronous task matrices executing directly under hardware timer ticks to ensure microsecond-level determinism:

| Task Component | Periodicity | Execution Priority | Responsibility |
| :--- | :--- | :--- | :--- |
| `App_Task_SSD_Display` | **10 ms** | High | Dynamic asynchronous dual-digit rendering (Live vs. Target Temperature) |
| `App_Task_Temp_Control`| **100 ms**| High | Closed-loop bang-bang controller parsing ADC outputs against target setpoints |
| `App_Task_LED_Blink`   | **200 ms**| Low | Visual system heartbeat toggle and high-frequency display flashing |
| `Foreground Loop`      | **Continuous** | Real-Time | Asynchronous button scanning, sequential 30ms debounce tracking, and edge lock protection |

---

## ⚡ Closed-Loop Control Logic & Interface Behavior

The thermal algorithm operates under a multi-state conditional engine guarding user limits between **35°C and 75°C**:
* **Heating Phase:** Triggered explicitly if \(T_{current} < (T_{set} - 5^\circ\text{C})\) via Pin `PC3`.
* **Cooling Phase:** Triggered explicitly if \(T_{current} > (T_{set} + 5^\circ\text{C})\) via Pin `PC4`.
* **Parameter Adjustment Flashing:** Adjusting the target temperature automatically engages a 5-second asynchronous timeout window. The display flashes the current setting at 2.5Hz (via `0xFF` blanking outputs) to provide clear user feedback without breaking background temperature regulation tasks.

---

## 🛠️ Pin Mapping & Hardware Topology

The schematic hardware layers are mapped directly as follows to align firmware register spaces with physical pins:
* **Data Port (PORTB):** Pins `PB0`-`PB3` drive the Units display decoder; Pins `PB4`-`PB7` drive the Tens display decoder (`7SEG-BCD`).
* **Control Port (PORTC):** Pin `PC3` drives the Heating element (`OVEN`), Pin `PC4` drives the Cooling element (`PELTIER` / `FAN-DC`), and Pin `PC5` drives the system status `LED-RED`.
* **Input Port (PORTD):** Pin `PD0` is mapped to the `POWER` key, Pin `PD1` to the `UP` key, and Pin `PD2` to the `DOWN` key (All configured with internal pull-ups and active-low topologies).
* **Analog Port (PORTA):** Pin `PA0` (ADC Channel 0) captures the continuous voltage frames outputted by the precision `LM35` sensor.

---
### 👨‍💻 Developed By
* **Engineer:** Zyad Hussein  
* **Role:** Embedded Firmware Architect  

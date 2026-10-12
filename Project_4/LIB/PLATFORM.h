/*
 * PLATFORM.h
 *
 * Created: 10/5/2026 7:47:58 AM
 *  Author: Eltawel
 */ 


#ifndef PLATFORM_H_
#define PLATFORM_H_

/************************************************************************/
/* 

 this file defines platform-specific configuration constants
 used across the project (MCAL/HAL/APP layers), mainly the
 CPU clock frequency.

 F_CPU: CPU clock frequency in Hz, used for:
 - timing calculations in TIM0 (delay) and TIM1 (scheduler)
 - any future UART baud rate calculations
 - util/delay.h functions if used anywhere

 IMPORTANT: this value MUST match the actual oscillator source
 used (internal RC / external crystal), otherwise all timing
 across the project will be inaccurate.
                                                                     */
/************************************************************************/

#ifndef	F_SYSTEM
	#define F_SYSTEM	16000000UL
#endif

#endif /* PLATFORM_H_ */
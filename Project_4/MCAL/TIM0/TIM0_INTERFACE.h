/*
 * TIM0_INTERFACE.h
 *
 * Created: 10/7/2026 12:23:46 AM
 *  Author: Eltawel
 */ 


#ifndef TIM0_INTERFACE_H_
#define TIM0_INTERFACE_H_

/************************************************************************/
/* 

 this file is the interface (prototypes) for the TIM0 driver.

 TIM0 (Timer0, 8-bit) is used in this project only as a BLOCKING
 millisecond delay, instead of using any ready-made delay library.
 periodic jobs (100ms sensing, 1s blinking, 5s timeout) are NOT done
 here, they are handled by TIM1 and the scheduler.

 usage: call TIM0_Init() once at startup, then call TIM0_Delayms()
 wherever a delay is needed.

 NOTE: the delay accuracy depends on F_CPU (PLATFORM.h) being equal
 to the real clock source of the MCU.
                                                                     */
/************************************************************************/

/**
 *@brief	Configure the Timer0 registers (mode, prescaler) used by the delay function
 *@param	none
 *@return	STD_RET: E_OK on success, E_NOK on failure
 *@note		Must be called once before TIM0_Delayms()
*/
STD_RET TIM0_Init(void);

/**
 *@brief	Blocking delay for the given time in milliseconds
 *@param	delay: delay time in milliseconds (0 to 65535)
 *@return	STD_RET: E_OK when the delay is completed, E_NOK on invalid input
 *@note		The calling code is blocked until the time elapses, so do not
 *			call it inside an ISR
*/
STD_RET TIM0_Delayms(u16 delay);

#endif /* TIM0_INTERFACE_H_ */
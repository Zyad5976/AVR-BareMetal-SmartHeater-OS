/*
 * TIM1_CFG.h
 *
 * Created: 10/12/2026 2:02:17 AM
 *  Author: Eltawel
 */ 


#ifndef TIM1_CFG_H_
#define TIM1_CFG_H_

/************************************************************************/
/* 
 
 this file is the configuration header for the MCAL Timer1 driver.

 it defines:
 - TWI_PRESCALER_t: clock select options for Timer1 to scale input frequencies.
 - static parameters to calculate the 16-bit OCR1A compare value dynamically.

 NOTE: For a 16MHz F_SYSTEM clock, choosing a prescaler of 8 gives a 2MHz 
 internal timer clock, resolving a perfect integer for 1ms tick targets.
                                                                     */
/************************************************************************/

/*-------------------------------------------*/

#include "../../LIB/PLATFORM.h"

/*-------------------------------------------*/

/* Clock Prescaler Options */
typedef enum
{
	TIM1_NO_CLOCK = 0,
	TIM1_PRESCALER_1,
	TIM1_PRESCALER_8,
	TIM1_PRESCALER_64,
	TIM1_PRESCALER_256,
	TIM1_PRESCALER_1024
}TIM1_PRESCALER_t;

/* Selected Global Prescaler Mode */
#define TIM1_CLK_SELECT			TIM1_PRESCALER_8

/* Target Scheduler Tick Frequency in Hz (1000Hz = 1ms Tick Interval) */
#define TIM1_TICK_FREQ			1000UL

/* Dynamic 16-bit Compare Match Calculation: ((16MHz / 8) / 1000Hz) - 1 = 1999 */
#define TIM1_OCR1A_VAL			(u16)(((F_SYSTEM / 8UL) / TIM1_TICK_FREQ) - 1UL)

#endif /* TIM1_CFG_H_ */
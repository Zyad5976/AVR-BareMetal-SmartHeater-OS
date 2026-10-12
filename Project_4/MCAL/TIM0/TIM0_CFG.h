/*
 * TIM0_CFG.h
 *
 * Created: 10/8/2026 11:49:02 PM
 *  Author: Eltawel
 */ 


#ifndef TIM0_CFG_H_
#define TIM0_CFG_H_

/************************************************************************/
/* 
 
 this file is the configuration of the TIM0 driver.

 it defines:
 - TIM0_WGM_t: waveform generation mode. the enum values are the 2-bit
 WGM01:WGM00 encoding of the datasheet, NOT the register bit positions.
 WGM00 is bit 6 and WGM01 is bit 3 in TCCR0, so the driver must split
 the value before writing it.
 - TIM0_CLK_t: clock select (prescaler). the enum values are the
 CS02:CS01:CS00 encoding of the datasheet, they map directly to the
 3 low bits of TCCR0.
 - the selected mode, prescaler and 1ms compare value used by the
 delay function.

 WARNING: do not change the order or the values of the enum items, they
 must match the datasheet encoding.

 NOTE: the external clock modes on pin T0 (CS = 110, 111) are not defined
 because this project does not use them.
                                                                     */
/************************************************************************/

/*-------------------------------------------*/

#include "../../LIB/PLATFORM.h"

/*-------------------------------------------*/

/* Wave Generation Mode */
typedef enum
{
	TIM0_NORMAL = 0,
	TIM0_PWM_PHASECORRECT,
	TIM0_CTC,
	TIM0_FASTPWM
}TIM0_WGM_t;


/* Clock Select */
typedef enum
{
	TIM0_NO_CLK_SRC = 0,
	TIM0_NO_PRESCALING,
	TIM0_8_CLK,
	TIM0_64_CLK,
	TIM0_256_CLK,
	TIM0_1024_CLK,
}TIM0_CLK_t;

/* selected configuration for the delay function */
#define TIM0_MODE		TIM0_CTC
#define TIM0_CLK		TIM0_64_CLK

/* compare value for a 1ms tick = (F_CPU / prescaler / 1000) - 1
   must fit in 8 bits. examples: 16MHz with /64 -> 249, 1MHz with /8 -> 124
   if you change TIM0_CLK, change the 64 here to match */
#define TIM0_OCR_VAL			((F_SYSTEM / 64UL / 1000UL) - 1UL)

#endif /* TIM0_CFG_H_ */
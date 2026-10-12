/*
 * TIM1_PROG.c
 *
 * Created: 10/12/2026 2:02:42 AM
 *  Author: Eltawel
 */ 
/************************************************************************/
/* 
 this file contains the implementation of the MCAL Timer1 driver.
 It sets up Mode 4 (CTC) to establish a structured, synchronous time-base, 
 handling safe hardware Interrupt Service Routine (ISR) callbacks via the 
 custom vector table macro.
                                                                     */
/************************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/VECTOR_TABLE_INTERRUPT.h"
#include "TIM1_REG.h"
#include "TIM1_CFG.h"
#include "TIM1_INTERFACE.h"

/*-------------------------------------------*/

static void (*TIM1_pvCallBackNotification)(void) = null;

/*-------------------------------------------*/

STD_RET TIM1_Init(void)
{
	STD_RET ret = E_OK;
	
	TCCR1A_REG.WGM10_BIT = 0;
	TCCR1A_REG.WGM11_BIT = 0;
	TCCR1B_REG.WGM12_BIT = 1;
	TCCR1B_REG.WGM13_BIT = 0;
	
	OCR1A_REG = TIM1_OCR1A_VAL;
	
	TIM1_TIMSK_REG.OCIE1A_BIT = 1;
	
	TCCR1B_REG.CS10_BIT = 0;
	TCCR1B_REG.CS11_BIT = 1;
	TCCR1B_REG.CS12_BIT = 0;
	
	return ret;
}

STD_RET TIM1_SetCallBack(void (*Copy_pvCallBackFunc)(void))
{
	STD_RET ret = E_OK;
	
	if(Copy_pvCallBackFunc == null)
	{
		ret = E_NOK;
	}
	else
	{
		TIM1_pvCallBackNotification = Copy_pvCallBackFunc;
	}
	
	return ret;
}

/*-------------------------------------------*/

ISR(TIMER1_COMP_A)
{
	if(TIM1_pvCallBackNotification != null)
	{
		TIM1_pvCallBackNotification();
	}
}
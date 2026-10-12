/*
 * TIM0_PROG.c
 *
 * Created: 10/7/2026 12:24:00 AM
 *  Author: Eltawel
 *
 ************************************************************************
 *

 this file is the implementation (.c) of the TIM0 driver declared in
 TIM0_INTERFACE.h.

 TIM0 is used as a polling-based millisecond time base (no interrupts):
 the timer runs in CTC mode and the compare match flag (OCF0) is raised
 every 1ms. the mode, prescaler and compare value come from TIM0_CFG.h.

 NOTE: OCF0 is cleared by writing 1 to it, so TIFR_REG is written with a
 direct assignment, never with SET_BIT (read-modify-write would also
 clear the flags of the other timers that share this register).

                                                                     
 ************************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/PLATFORM.h"
#include "../../MCAL/DIO/DIO_INTERFACE.h"
#include "TIM0_CFG.h"
#include "TIM0_INTERFACE.h"
#include "TIM0_REG.h"

STD_RET TIM0_Init(void)
{
	STD_RET ret = E_OK;
	
	/* Enable Force Output Compare Match --> FOC0 */
		TCCR0_REG.FOC0_BIT = 1;
		
	/* Select Waveform Generation Mode --> CTC */
		TCCR0_REG.WGM00_BIT = 0;
		TCCR0_REG.WGM01_BIT = 1;
		
	/* Select Prescaler --> TIM0_64_CLK */
		TCCR0_REG.CS00_BIT = 1;
		TCCR0_REG.CS01_BIT = 1;
		TCCR0_REG.CS02_BIT = 0;
	
	/* Select OCR Val */
		OCR0_REG = TIM0_OCR_VAL;
		
	return ret;
}

STD_RET TIM0_Delayms(u16 delay)
{
	STD_RET ret = E_OK;
	
	TCNT0_REG = 0;
	
	while(delay > 0)
	{
		while(TIFR_REG.OCF0_BIT == 0)
		{
			
		}
		
		TIFR_REG.OCF0_BIT =1;
		
		delay--;
	}
	
	
	return ret;
}
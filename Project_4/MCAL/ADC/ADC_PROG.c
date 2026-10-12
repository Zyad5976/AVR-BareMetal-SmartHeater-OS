/*
 * ADC_PROG.c
 *
 * Created: 10/11/2026 3:36:36 AM
 *  Author: Eltawel
 */ 

/************************************************************************/
/* 
 this file contains the implementation of the MCAL ADC driver.
 It handles synchronous conversion sequences via polling mechanisms, mapping 
 dynamic sampling requests onto structural bit fields representing the internal 
 conversion machinery.
                                                                     */
/************************************************************************/

/************************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "ADC_CFG.h"
#include "ADC_INTERFACE.h"
#include "ADC_REG.h"

/*-------------------------------------------*/

STD_RET ADC_Init(void)
{
	STD_RET ret = E_OK;
	
	/* select mode */
		ADMUX_REG.REFS0_BIT = 1;
		ADMUX_REG.REFS1_BIT = 0;
		
	/* Right Adjust */
		ADMUX_REG.ADLAR_BIT = 0;
		
	/* Select Prescaler */
		ADCSRA_REG.ADPS0_BIT = 0;
		ADCSRA_REG.ADPS1_BIT = 1;
		ADCSRA_REG.ADPS2_BIT = 1;
		
	/* ADC Enable */
		ADCSRA_REG.ADEN_BIT = 1;
	
	
	return ret;
}

u16 ADC_ReadChannel(u8 channel)
{
	/* Select Channel */
		ADMUX_REG.MUX0_BIT = (channel & 0x01);
		ADMUX_REG.MUX1_BIT = ((channel >> 1) & 0x01);
		ADMUX_REG.MUX2_BIT = ((channel >> 2) & 0x01);
		ADMUX_REG.MUX3_BIT = 0;
		ADMUX_REG.MUX4_BIT = 0;
		
	/* Start COnversion */
		ADCSRA_REG.ADSC_BIT = 1;
		
	while(ADCSRA_REG.ADIF_BIT == 0)
	{
		
	}
	
	ADCSRA_REG.ADIF_BIT = 1;
	
	return ADCL_REG;
}
/*
 * LM35_PROG.c
 *
 * Created: 10/11/2026 12:41:39 PM
 *  Author: Eltawel
 */ 

/************************************************************************/
/* 
 this file contains the implementation of the LM35 Temperature Sensor HAL driver.
 It encapsulates the mathematical conversion required to translate digital 
 voltage steps collected from the MCAL ADC peripheral into actual physical 
 Celsius degrees.
                                                                     */
/************************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/ADC/ADC_INTERFACE.h"
#include "LM35_INTERFACE.h"

STD_RET LM35_GetTemp(u8 Channel, u8 *Temp)
{
	STD_RET ret = E_OK;
	u16 ADC_res = 0;
	u32 Temp_calc = 0;
	
	if(Temp == null)
	{
		ret = E_NOK;
	}
	else
	{
		ADC_res = ADC_ReadChannel(Channel);
		
		Temp_calc = ((u32)ADC_res * 500UL) / 1023UL;
		
		*Temp = (u8)Temp_calc;
	}
	
	return ret;
}
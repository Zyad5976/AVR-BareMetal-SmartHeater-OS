/*
 * FAN_PROG.c
 *
 * Created: 10/10/2026 4:14:01 PM
 *  Author: Eltawel
 *
 * 
 this file contains the implementation of the Fan HAL driver.
 It interfaces with the MCAL DIO layer to manipulate the physical pins 
 connected to the fan driving circuit, isolating the application layer 
 from direct hardware control.
                                                                     
************************************************************************/

/*-------------------------------------------*/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_INTERFACE.h"
#include "FAN_CFG.h"
#include "FAN_INTERFACE.h"

/*-------------------------------------------*/

STD_RET FAN_Init(const FAN_CFG_t *obj)
{
	STD_RET ret = E_OK;
	DIO_CFG_t dio_fan;
	
	if(obj == null)
	{
		ret = E_NOK;
	}
	else
	{
		dio_fan.port = obj->fan_port;
		dio_fan.pin = obj->fan_pin;
		dio_fan.dir = DIO_OUTPUT;
		dio_fan.val = DIO_LOW;
		
		DIO_SetPinDir(&dio_fan);
		DIO_SetPinVal(&dio_fan);
	}
	
	return ret;
}


STD_RET FAN_SetON(const FAN_CFG_t *obj)
{
	STD_RET ret = E_OK;
	DIO_CFG_t dio_fan;
	
	if(obj == null)
	{
		ret = E_NOK;
	}
	else
	{
		dio_fan.port = obj->fan_port;
		dio_fan.pin = obj->fan_pin;
		dio_fan.dir = DIO_OUTPUT;
		
		DIO_SetPinDir(&dio_fan);
		
		if(obj->fan_state == FAN_ON)
		{
			dio_fan.val = DIO_HIGH;
		}
		else
		{
			dio_fan.val = DIO_LOW;
		}
		
		DIO_SetPinVal(&dio_fan);
	}
	return ret;
}

STD_RET FAN_SetOFF(const FAN_CFG_t *obj)
{
	STD_RET ret = E_OK;
	DIO_CFG_t dio_fan;
	
	if(obj == null)
	{
		ret = E_NOK;
	}
	else
	{
		dio_fan.port = obj->fan_port;
		dio_fan.pin = obj->fan_pin;
		dio_fan.dir = DIO_OUTPUT;
		
		DIO_SetPinDir(&dio_fan);
		
		if(obj->fan_state == FAN_OFF)
		{
			dio_fan.val = DIO_LOW;
		}
		else
		{
			dio_fan.val = DIO_HIGH;
		}
		
		DIO_SetPinVal(&dio_fan);
	}
	return ret;
}

STD_RET FAN_Toggle(const FAN_CFG_t *obj)
{
	STD_RET ret = E_OK;
	DIO_CFG_t dio_fan;
	
	if(obj == null)
	{
		ret = E_NOK;
	}
	else
	{
		dio_fan.port = obj->fan_port;
		dio_fan.pin = obj->fan_pin;
		dio_fan.dir = DIO_OUTPUT;
		
		DIO_SetPinDir(&dio_fan);
		DIO_TogglePin(&dio_fan);
	}
		
	return ret;
}
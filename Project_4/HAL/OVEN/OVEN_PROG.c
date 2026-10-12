/*
 * OVEN_PROG.c
 *
 * Created: 10/11/2026 2:13:32 AM
 *  Author: Eltawel
 */ 

/************************************************************************/
/* 
 this file contains the implementation of the Oven HAL driver.
 It drives the digital output pin connected to the heater relay circuit, 
 ensuring clear abstraction between system application logic and direct GPIO lines.
                                                                     */
/************************************************************************/

/*-------------------------------------------*/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_INTERFACE.h"
#include "OVEN_CFG.h"
#include "OVEN_INTERFACE.h"

/*-------------------------------------------*/

STD_RET OVEN_Init(const OVEN_CFG_t *obj)
{
	STD_RET ret = E_OK;
	DIO_CFG_t dio_oven;
	
	if(obj == null)
	{
		ret = E_NOK;
	}
	else
	{
		dio_oven.port = obj->oven_port;
		dio_oven.pin = obj->oven_pin;
		dio_oven.dir = DIO_OUTPUT;
		dio_oven.val = DIO_LOW;
		
		ret = DIO_SetPinDir(&dio_oven);
		ret = DIO_SetPinVal(&dio_oven);
	}
	return ret;
}

STD_RET OVEN_SetON(const OVEN_CFG_t *obj)
{
	STD_RET ret = E_OK;
	DIO_CFG_t dio_oven;
	
	if(obj == null)
	{
		ret = E_NOK;
	}
	else
	{
		dio_oven.port = obj->oven_port;
		dio_oven.pin = obj->oven_pin;
		dio_oven.dir = DIO_OUTPUT;
		dio_oven.val = DIO_HIGH;
		
		ret = DIO_SetPinVal(&dio_oven);
	}
	return ret;
}

STD_RET OVEN_SetOFF(const OVEN_CFG_t *obj)
{
	STD_RET ret = E_OK;
	DIO_CFG_t dio_oven;
	
	if(obj == null)
	{
		ret = E_NOK;
	}
	else
	{
		dio_oven.port = obj->oven_port;
		dio_oven.pin = obj->oven_pin;
		dio_oven.dir = DIO_OUTPUT;
		dio_oven.val = DIO_LOW;
		
		ret = DIO_SetPinVal(&dio_oven);
	}
	return ret;
}
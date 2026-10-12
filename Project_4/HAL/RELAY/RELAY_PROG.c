/*
 * RELAY_PROG.c
 *
 * Created: 10/9/2026 11:57:04 PM
 *  Author: Eltawel
 *
 * 
 this file contains the implementation of the Relay HAL driver.
 It maps the generic high-level state (RELAY_ON / RELAY_OFF) to the actual 
 GPIO physical voltage levels (HIGH / LOW) depending on whether the hardware 
 configuration is set to ACTIVE_HIGH or ACTIVE_LOW.
                                                                     
************************************************************************/

/*-------------------------------------------*/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_INTERFACE.h"
#include "RELAY_CFG.h"
#include "RELAY_INTERFACE.h"

/*-------------------------------------------*/

STD_RET RELAY_Init(const RELAY_CFG_t *obj)
{
	STD_RET ret = E_OK;
	DIO_CFG_t dio_relay;
	
	if(obj == null)
	{
		ret = E_NOK;
	}
	else
	{
		dio_relay.port = obj->port;
		dio_relay.pin = obj->pin;
		dio_relay.dir = DIO_OUTPUT;
		
		if(obj->connection == RELAY_ACTIVE_LOW)
		{
			dio_relay.val = DIO_HIGH;
		}
		else
		{
			dio_relay.val = DIO_LOW;
		}
		
		DIO_SetPinDir(&dio_relay);
		DIO_SetPinVal(&dio_relay);
	}
	
	return ret;
}

STD_RET RELAY_SetState(const RELAY_CFG_t *obj, const RELAY_STATE_t state)
{
	STD_RET ret = E_OK;
	DIO_CFG_t dio_relay;
	
	if(obj == null)
	{
		ret = E_NOK;
	}
	else
	{
		dio_relay.port = obj->port;
		dio_relay.pin = obj->pin;
		dio_relay.dir = DIO_OUTPUT;
		
		if(state == RELAY_ON)
		{
			if(obj->connection == RELAY_ACTIVE_HIGH)
			{
				dio_relay.val = DIO_HIGH;
			}
			else
			{
				dio_relay.val = DIO_LOW;
			}
		}
		else
		{
			if(obj->connection == RELAY_ACTIVE_HIGH)
			{
				dio_relay.val = DIO_LOW;
			}
			else
			{
				dio_relay.val = DIO_HIGH;
			}
			
		}
		
		DIO_SetPinVal(&dio_relay);
	}
		
	return ret;
}

STD_RET RELAY_Toggle(const RELAY_CFG_t *obj)
{
	STD_RET ret = E_OK;
	DIO_CFG_t dio_relay;
	
	if(obj == null)
	{
		ret = E_NOK;
	}
	else
	{
		dio_relay.port = obj->port;
		dio_relay.pin = obj->pin;
		dio_relay.dir = DIO_OUTPUT;
		
		DIO_TogglePin(&dio_relay);
	}
	
	return ret;
}
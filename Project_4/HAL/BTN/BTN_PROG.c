/*
 * BTN_PROG.c
 *
 * Created: 10/9/2026 6:46:19 AM
 *  Author: Eltawel
 *
 
* 
 * @file        BTN_PROG.c
 * @brief       Implementation file for the Button (BTN) HAL driver.
 * @details     This file contains the logic for initializing digital input 
 *              buttons and reading their states, handling configuration 
 *              mapping to the underlying MCAL DIO layer.
                                                                     
************************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_INTERFACE.h"
#include "BTN_CFG.h"
#include "BTN_INTERFACE.h"

STD_RET BTN_Init(const BTN_CFG_t *obj)
{
	STD_RET ret = E_OK;
	DIO_CFG_t dio_BTN;
	
	if(obj == null)
	{
		ret = E_NOK;
	}
	else
	{
		dio_BTN.port = obj->port;
		dio_BTN.pin = obj->pin;
		dio_BTN.dir = DIO_INPUT;
		
		if(obj->connection == BTN_ACTIVE_LOW)
		{
			dio_BTN.val = DIO_HIGH;
		}
		else
		{
			dio_BTN.val = DIO_LOW;
		}
		
		DIO_SetPinDir(&dio_BTN);
		DIO_SetPinVal(&dio_BTN);
	}
	
	return ret;
}

STD_RET BTN_Status(const BTN_CFG_t *obj, BTN_STATE_t *state)
{
	STD_RET ret = E_OK;
	DIO_VAL_t pin_val = DIO_LOW;
	DIO_CFG_t dio_BTN;
	
	if((obj	== null) || (state == null))
	{
		ret = E_NOK;
	}
	else
	{	
		
		dio_BTN.port = obj->port;
		dio_BTN.pin = obj->pin;
		dio_BTN.dir = DIO_INPUT;
		
		pin_val = DIO_ReadPinVal(&dio_BTN);
		
		if(obj->connection == BTN_ACTIVE_HIGH)
		{
			if(pin_val == DIO_HIGH)
			{
				*state = BTN_PRESSED;
			}
			else
			{
				*state = BTN_RELEASED;
			}
		}
		else
		{
			if(pin_val == DIO_LOW)
			{
				*state = BTN_PRESSED;
			}
			else
			{
				*state = BTN_RELEASED;
			}
		}
	}
	
	return ret;
}
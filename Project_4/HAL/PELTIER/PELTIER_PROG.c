/*
 * PELTIER_PROG.c
 *
 * Created: 10/11/2026 12:22:29 AM
 *  Author: Eltawel
 */

/************************************************************************/
/* 
 this file contains the implementation of the Peltier Cooler HAL driver.
 It interacts with the MCAL DIO layer to manipulate the physical pins 
 connected to the transistor switch circuit, isolating the upper control logic
 from direct hardware configuration.
                                                                     */
/************************************************************************/

/*-------------------------------------------*/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_INTERFACE.h"
#include "PELTIER_CFG.h"
#include "PELTIER_INTERFACE.h"

/*-------------------------------------------*/

STD_RET PELTIER_Init(const PELTIER_CFG_t *obj)
{
	STD_RET ret = E_OK;
	DIO_CFG_t dio_peltier;
	
	if(obj == null)
	{
		ret = E_NOK;
	}
	else
	{
		dio_peltier.port = obj->peltier_port;
		dio_peltier.pin = obj->peltier_pin;
		dio_peltier.dir = DIO_OUTPUT;
		dio_peltier.val = DIO_LOW;
		
		DIO_SetPinDir(&dio_peltier);
		DIO_SetPinVal(&dio_peltier);
	}
	
	return ret;
}

STD_RET PELTIER_SetON(const PELTIER_CFG_t *obj)
{
	STD_RET ret = E_OK;
	DIO_CFG_t dio_peltier;
	
	if(obj == null)
	{
		ret = E_NOK;
	}
	else
	{
		dio_peltier.port = obj->peltier_port;
		dio_peltier.pin = obj->peltier_pin;
		dio_peltier.dir = DIO_OUTPUT;
		dio_peltier.val = DIO_HIGH;
		
		DIO_SetPinVal(&dio_peltier);
	}
	
	return ret;
}

STD_RET PELTIER_SetOFF(const PELTIER_CFG_t *obj)
{
	STD_RET ret = E_OK;
	DIO_CFG_t dio_peltier;
	
	if(obj == null)
	{
		ret = E_NOK;
	}
	else
	{
		dio_peltier.port = obj->peltier_port;
		dio_peltier.pin = obj->peltier_pin;
		dio_peltier.dir = DIO_OUTPUT;
		dio_peltier.val = DIO_LOW;
		
		DIO_SetPinVal(&dio_peltier);
	}
	
	return ret;
}
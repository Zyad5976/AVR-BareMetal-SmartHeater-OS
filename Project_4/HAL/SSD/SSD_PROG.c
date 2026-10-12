/*
 * SSD_PROG.c
 *
 * Created: 10/6/2026 8:21:56 AM
 *  Author: Eltawel
 */ 


/************************************************************************/
/* 
 this file contains the implementation of the Seven Segment Display (SSD) HAL driver.
 It utilizes direct 8-bit register mapping to drive two independent BCD 
 decoders simultaneously, eliminating ghosting and timing synchronization blocks.
                                                                     */
/************************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_INTERFACE.h"
#include "SSD_CFG.h"
#include "SSD_INTERFACE.h"

/*-------------------------------------------*/

STD_RET SSD_Init(const SSD_CFG_t *obj)
{
	STD_RET ret = E_OK;
	DIO_CFG_t dio_setup;
	u8 pin_counter;
	
	if(obj == null)
	{
		ret = E_NOK;
	}
	else
	{
		
		for(pin_counter = 0; pin_counter < 8; pin_counter++)
		{
			dio_setup.port = obj->data_port;
			dio_setup.pin  = pin_counter;
			dio_setup.dir  = DIO_OUTPUT;
			dio_setup.val  = DIO_LOW;
			
			DIO_SetPinDir(&dio_setup);
			DIO_SetPinVal(&dio_setup);
		}
	}
	return ret;
}

STD_RET SSD_WriteTwoDigits(const SSD_CFG_t *obj, u8 copy_u8Number)
{
	STD_RET ret = E_OK;
	DIO_CFG_t dio_data;
	u8 tens = copy_u8Number / 10;
	u8 units = copy_u8Number % 10;
	u8 pin_counter;
	
	
	u8 total_bcd_frame = (units & 0x0F) | ((tens & 0x0F) << 4);
	
	if((obj == null) || (copy_u8Number > 99))
	{
		return E_NOK;
	}
	else
	{
		
		for(pin_counter = 0; pin_counter < 8; pin_counter++)
		{
			dio_data.port = obj->data_port;
			dio_data.pin  = pin_counter;
			dio_data.dir  = DIO_OUTPUT;
			dio_data.val  = (total_bcd_frame >> pin_counter) & 0x01;
			
			DIO_SetPinVal(&dio_data);
		}
	}
	return ret;
}
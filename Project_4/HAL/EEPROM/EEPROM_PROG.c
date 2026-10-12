/*
 * EEPROM_PROG.c
 *
 * Created: 10/12/2026 1:47:42 AM
 *  Author: Eltawel
 */ 

/************************************************************************/
/* 
 this file contains the implementation of the External EEPROM HAL driver.
 It translates generic read/write byte requests into ordered sequential TWI bus 
 events, orchestrating SLA addresses, byte boundaries, and data line handshakes.
                                                                     */
/************************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/TWI/TWI_INTERFACE.h"
#include "../../MCAL/TIM0/TIM0_INTERFACE.h"
#include "EEPROM_CFG.h"
#include "EEPROM_INTERFACE.h"

/*-------------------------------------------*/


STD_RET EEPROM_Init(void)
{
	return TWI_Init();
}

STD_RET EEPROM_WriteByte(const EEPROM_CFG_t *obj, u16 memoryAddress, u8 data)
{
	STD_RET ret = E_OK;
	u8 local_u8DeviceAddressMask = 0;
	
	if((obj == null) || (memoryAddress > 1023))
	{
		return E_NOK;
	}
	
	local_u8DeviceAddressMask = (obj->device_address) | (((memoryAddress >> 8) & 0x03) << 1);
	local_u8DeviceAddressMask &= ~0x01;
	

	if(TWI_SendStart() == E_OK)
	{
		if(TWI_WriteByte(local_u8DeviceAddressMask) == E_OK)
		{
			if(TWI_WriteByte((u8)memoryAddress) == E_OK)
			{
				if(TWI_WriteByte(data) == E_OK)
				{
					TWI_SendStop();
					
					TIM0_Delayms(10);
				}
				else { ret = E_NOK; }
			}
			else { ret = E_NOK; }
		}
		else { ret = E_NOK; }
	}
	else { ret = E_NOK; }
	
	return ret;
}

STD_RET EEPROM_ReadByte(const EEPROM_CFG_t *obj, u16 memoryAddress, u8 *data)
{
	STD_RET ret = E_OK;
	u8 local_u8DeviceAddressMask = 0;
	
	if((obj == null) || (data == null) || (memoryAddress > 1023))
	{
		return E_NOK;
	}
	

	local_u8DeviceAddressMask = (obj->device_address) | (((memoryAddress >> 8) & 0x03) << 1);
	local_u8DeviceAddressMask &= ~0x01; 
	
	if(TWI_SendStart() == E_OK)
	{
		if(TWI_WriteByte(local_u8DeviceAddressMask) == E_OK)
		{
			if(TWI_WriteByte((u8)memoryAddress) == E_OK)
			{

				if(TWI_SendRepeatedStart() == E_OK)
				{

					local_u8DeviceAddressMask |= 0x01;
					
					if(TWI_WriteByte(local_u8DeviceAddressMask) == E_OK)
					{

						if(TWI_ReadByteWithNACK(data) == E_OK)
						{
							TWI_SendStop();
						}
						else { ret = E_NOK; }
					}
					else { ret = E_NOK; }
				}
				else { ret = E_NOK; }
			}
			else { ret = E_NOK; }
		}
		else { ret = E_NOK; }
	}
	else { ret = E_NOK; }
	
	return ret;
}
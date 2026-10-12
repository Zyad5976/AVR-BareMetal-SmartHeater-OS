/*
 * TWI_PROG.c
 *
 * Created: 10/11/2026 9:16:09 PM
 *  Author: Eltawel
 */ 

/************************************************************************/
/* 
 this file contains the implementation of the MCAL TWI (I2C) driver.
 It manages synchronous master transmission and reception frames by polling 
 the hardware Interrupt Flag (TWINT), executing sequence control for status 
 verifications based on the ATmega32 hardware architecture.
                                                                     */
/************************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "TWI_REG.h"
#include "TWI_CFG.h"
#include "TWI_INTERFACE.h"

/*-------------------------------------------*/

STD_RET TWI_Init(void)
{
	STD_RET ret = E_OK;
	
	
	TWBR_REG = TWI_TWBR_VAL;
	
	
	TWSR_REG.TWPS1_BIT = 0;
	TWSR_REG.TWPS0_BIT = 0;
	
	
	TWCR_REG.TWEN_BIT = 1;
	
	return ret;
}

STD_RET TWI_SendStart(void)
{
	STD_RET ret = E_OK;
	
	
	TWCR_REG.TWSTA_BIT = 1;
	TWCR_REG.TWEN_BIT  = 1;
	TWCR_REG.TWINT_BIT = 1;
	
	
	while(TWCR_REG.TWINT_BIT == 0)
	{
		
	}
	
	return ret;
}

STD_RET TWI_SendRepeatedStart(void)
{
	STD_RET ret = E_OK;
	
	
	TWCR_REG.TWSTA_BIT = 1;
	TWCR_REG.TWEN_BIT  = 1;
	TWCR_REG.TWINT_BIT = 1;
	
	while(TWCR_REG.TWINT_BIT == 0)
	{
		
	}
	
	return ret;
}

void TWI_SendStop(void)
{
	
	TWCR_REG.TWSTO_BIT = 1;
	TWCR_REG.TWEN_BIT  = 1;
	TWCR_REG.TWINT_BIT = 1;
}

STD_RET TWI_WriteByte(u8 data)
{
	STD_RET ret = E_OK;
	
	
	TWDR_REG = data;
	
	
	TWCR_REG.TWSTA_BIT = 0;
	TWCR_REG.TWEN_BIT  = 1;
	TWCR_REG.TWINT_BIT = 1;
	
	
	while(TWCR_REG.TWINT_BIT == 0)
	{
		
	}
	
	return ret;
}

STD_RET TWI_ReadByteWithACK(u8 *data)
{
	STD_RET ret = E_OK;
	
	if(data == null)
	{
		ret = E_NOK;
	}
	else
	{
		
		TWCR_REG.TWEA_BIT  = 1;
		TWCR_REG.TWEN_BIT  = 1;
		TWCR_REG.TWINT_BIT = 1;
		
		
		while(TWCR_REG.TWINT_BIT == 0)
		{
			
		}
		
		
		*data = TWDR_REG;
	}
	
	return ret;
}

STD_RET TWI_ReadByteWithNACK(u8 *data)
{
	STD_RET ret = E_OK;
	
	if(data == null)
	{
		ret = E_NOK;
	}
	else
	{
		
		TWCR_REG.TWEA_BIT  = 0;
		TWCR_REG.TWEN_BIT  = 1;
		TWCR_REG.TWINT_BIT = 1;
		
		
		while(TWCR_REG.TWINT_BIT == 0)
		{
			
		}
		
		*data = TWDR_REG;
	}
	
	return ret;
}
/*
 * TWI_REG.h
 *
 * Created: 10/11/2026 9:15:13 PM
 *  Author: Eltawel
 */ 


#ifndef TWI_REG_H_
#define TWI_REG_H_

/************************************************************************/
/* 
 
 this file defines the Two-Wire Serial Interface (TWI/I2C) registers for ATmega32.
 It maps control, status, and data hardware registers using precise Bit-Fields 
 to enable master/slave bus initialization, address filtering, and state polling.

 Register Map Reference: ATmega32 Datasheet - TWI Peripheral (Pages 178-182)
                                                                     */
/************************************************************************/

/*-------------------------------------------------------*/

#include "../../LIB/STD_TYPES.h"

/*-------------------------------------------------------*/


/* TWI Control Register Bits (TWCR - Address 0x56) */
typedef struct
{
	u8 TWIE_BIT	 : 1;	/* Bit 0: TWI Interrupt Enable */
	u8 RESERVED	 : 1;	/* Bit 1: Reserved Bit */
	u8 TWEN_BIT	 : 1;	/* Bit 2: TWI Enable Bit */
	u8 TWWC_BIT  : 1;	/* Bit 3: TWI Write Collision Flag */
	u8 TWSTO_BIT : 1;	/* Bit 4: TWI Stop Condition Bit */
	u8 TWSTA_BIT : 1;	/* Bit 5: TWI Start Condition Bit */
	u8 TWEA_BIT  : 1;	/* Bit 6: TWI Enable Acknowledge Bit */
	u8 TWINT_BIT : 1;	/* Bit 7: TWI Interrupt Flag (Cleared by writing 1) */
}TWCR_BITS_t;


/* TWI Status Register Bits (TWSR - Address 0x21) */
typedef struct
{
	u8 TWPS0_BIT : 1;	/* Bit 0: TWI Prescaler Bit 0 */
	u8 TWPS1_BIT : 1;	/* Bit 1: TWI Prescaler Bit 1 */
	u8 RESERVED  : 1;	/* Bit 2: Reserved Bit */
	u8 TWS3_BIT  : 1;	/* Bit 3: TWI Status Bit 3 */
	u8 TWS4_BIT  : 1;	/* Bit 4: TWI Status Bit 4 */
	u8 TWS5_BIT  : 1;	/* Bit 5: TWI Status Bit 5 */
	u8 TWS6_BIT	 : 1;	/* Bit 6: TWI Status Bit 6 */
	u8 TWS7_BIT  : 1;	/* Bit 7: TWI Status Bit 7 */
}TWSR_BITS_t;

/*----------------------------------------------------------------------*/

#define TWBR_REG			(*((volatile u8*)0x20))

#define TWCR_REG			(*((volatile TWCR_BITS_t*)0x56))

#define TWSR_REG			(*((volatile TWSR_BITS_t*)0x21))
							  
#define TWDR_REG			(*((volatile u8*)0x23))

#define TWAR_REG			(*((volatile u8*)0x22))

#endif /* TWI_REG_H_ */
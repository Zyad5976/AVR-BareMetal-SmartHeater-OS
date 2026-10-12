/*
 * TWI_CFG.h
 *
 * Created: 10/11/2026 9:15:24 PM
 *  Author: Eltawel
 */ 


#ifndef TWI_CFG_H_
#define TWI_CFG_H_

/************************************************************************/
/* 
 
 this file is the configuration header for the MCAL TWI (I2C) driver.

 it defines:
 - TWI_PRESCALER_t: binary division factors mapped onto TWPS1:TWPS0 bits 
   inside the TWSR status register to scale the internal bit-rate clock.
 - core static configuration macros required to generate the dynamic 
   bus master clock frequency based on F_SYSTEM.

 WARNING: ensure that the calculated TWI_TWBR_VAL fits within 8 bits (0-255), 
 otherwise the clock generation configuration will overflow.
                                                                     */
/************************************************************************/

/*-------------------------------------------*/

#include "../../LIB/PLATFORM.h"

/*-------------------------------------------*/

/* TWI Prescaler Bit-Mapping Options (Matches TWSR Datasheet values 0 to 3) */
typedef enum
{
	TWI_CLK_1 = 0,
	TWI_CLK_4,
	TWI_CLK_16,
	TWI_CLK_64
}TWI_PRESCALER_t;


/* Selected Prescaler configuration for stable master generation */
#define TWI_PRESCALER		TWI_CLK_1

/* Target TWI Bus Speed in Hz (400kHz Fast Mode) */
#define TWI_SCL_FREQ		400000UL

/* 
 * Dynamic Bit Rate Equation: TWBR = ((F_SYSTEM / TWI_SCL_FREQ) - 16) / (2 * Prescaler)
 * For 16MHz and 400kHz: ((16000000 / 400000) - 16) / (2 * 1) = 12
 */
#define TWI_TWBR_VAL		(u8)(((F_SYSTEM / TWI_SCL_FREQ) - 16UL) / (2UL * 1UL))

#endif /* TWI_CFG_H_ */
/*
 * EEPROM_CFG.h
 *
 * Created: 10/12/2026 1:47:09 AM
 *  Author: Eltawel
 */ 


#ifndef EEPROM_CFG_H_
#define EEPROM_CFG_H_

/************************************************************************/
/* 
 this file is the configuration header for the External EEPROM (NM24C08F) HAL driver.

 it defines:
 - EEPROM_CFG_t: configuration structure encapsulating the hardware 
   fixed device packet address based on I2C hardware pin strapping (A0, A1, A2).

 NOTE: NM24C08F is an 8Kbit device divided into 4 internal blocks of 256 bytes each.
 The dynamic block selection bits are embedded directly inside the SLA address frame.
                                                                     */
/************************************************************************/

#include "../../LIB/STD_TYPES.h"

/*-------------------------------------------*/

/* EEPROM Object Structure */
typedef struct
{
	u8 device_address;  /* Base I2C 7-bit hardware address (Standard is 0xA0) */
}EEPROM_CFG_t;

#endif /* EEPROM_CFG_H_ */
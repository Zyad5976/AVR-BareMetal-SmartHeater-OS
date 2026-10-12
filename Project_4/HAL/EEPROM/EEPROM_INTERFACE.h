/*
 * EEPROM_INTERFACE.h
 *
 * Created: 10/12/2026 1:47:31 AM
 *  Author: Eltawel
 */ 


#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

/************************************************************************/
/* 
 this file is the interface (prototypes) for the External EEPROM (NM24C08F) HAL driver.

 it provides standard byte-level non-volatile memory storage APIs:
 - EEPROM_Init: initializes the underlying MCAL TWI serial bus infrastructure.
 - EEPROM_WriteByte: saves a single byte of data into a specific memory address location.
 - EEPROM_ReadByte: retrieves a single byte of data from a specific memory address location.

 usage: call EEPROM_Init once during boot setup, then invoke Write/ReadByte 
 to load or store system critical values like the target Set Temperature.
                                                                     */
/************************************************************************/

#include "EEPROM_CFG.h"

/*-------------------------------------------*/

/**
 * @brief  Initialize the EEPROM hardware module interface by spinning up the MCAL TWI clock.
 * @param  void
 * @return STD_RET: E_OK on successful bus configuration sequence.
 */
STD_RET EEPROM_Init(void);

/**
 * @brief  Write a single byte of data into a specific 8-bit memory address inside the EEPROM.
 * @param  obj: Pointer to a constant configuration structure holding the EEPROM device info.
 * @param  memoryAddress: The targeted internal cell address (0 to 1023).
 * @param  data: The data byte payload ready to be saved permanently.
 * @return STD_RET: E_OK on successful write cycle execution, E_NOK on failure.
 */
STD_RET EEPROM_WriteByte(const EEPROM_CFG_t *obj, u16 memoryAddress, u8 data);

/**
 * @brief  Read a single byte of data from a specific 8-bit memory address inside the EEPROM.
 * @param  obj: Pointer to a constant configuration structure holding the EEPROM device info.
 * @param  memoryAddress: The targeted internal cell address (0 to 1023).
 * @param  data: Pointer to store the collected incoming saved byte payload.
 * @return STD_RET: E_OK on successful synchronous read frame execution, E_NOK on failure.
 */
STD_RET EEPROM_ReadByte(const EEPROM_CFG_t *obj, u16 memoryAddress, u8 *data);


#endif /* EEPROM_INTERFACE_H_ */
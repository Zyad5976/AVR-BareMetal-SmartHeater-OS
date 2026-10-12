/*
 * TWI_INTERFACE.h
 *
 * Created: 10/11/2026 9:15:57 PM
 *  Author: Eltawel
 */ 


#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_

/************************************************************************/
/* 

 this file is the interface (prototypes) for the MCAL TWI (I2C) driver.

 it provides standard master-mode bus orchestration functions:
 - TWI_Init: configures the dynamic 400kHz SCL clock and enables hardware.
 - TWI_SendStart / TWI_SendRepeatedStart: issues bus capture requests.
 - TWI_SendStop: releases the serial lines to Idle state.
 - TWI_WriteByte: transmits 8-bit payloads (Address or Data) onto the bus.
 - TWI_ReadByteWithACK: collects a byte and requests more data from slave.
 - TWI_ReadByteWithNACK: collects the final byte, telling slave to stop sending.

 usage: call TWI_Init once during boot up, then use start, write, and read 
 sequence chains inside your external HAL EEPROM driver to store parameters.
                                                                     */
/************************************************************************/

#include "../../LIB/STD_TYPES.h"

/*-------------------------------------------*/

/**
 * @brief  Initialize the TWI peripheral clock bit rate and globally enable the module.
 * @param  void
 * @return STD_RET: E_OK on successful initialization sequence.
 */
STD_RET TWI_Init(void);

/**
 * @brief  Generate a secure START condition to capture control of the I2C serial bus.
 * @param  void
 * @return STD_RET: E_OK on successful start, E_NOK on arbitration loss or failure.
 */
STD_RET TWI_SendStart(void);

/**
 * @brief  Generate a REPEATED START condition for multi-byte secure message switching.
 * @param  void
 * @return STD_RET: E_OK on successful execution, E_NOK on bus error.
 */
STD_RET TWI_SendRepeatedStart(void);

/**
 * @brief  Generate a STOP condition to release bus lines back to the global Idle state.
 * @param  void
 * @return none
 */
void TWI_SendStop(void);

/**
 * @brief  Transmit a single 8-bit packet (Slave Address or Data payload) onto the bus.
 * @param  Data: The data byte or SLA+W/R frame ready for transmission.
 * @return STD_RET: E_OK on successful byte transfer and Acknowledge (ACK) collection.
 */
STD_RET TWI_WriteByte(u8 Data);

/**
 * @brief  Read an incoming byte from the slave device and respond with an ACK pulse.
 * @param  Data: Pointer to store the collected incoming byte payload.
 * @return STD_RET: E_OK on successful read frame execution.
 */
STD_RET TWI_ReadByteWithACK(u8 *Data);

/**
 * @brief  Read the final incoming byte from the slave and respond with a NACK pulse.
 * @param  Data: Pointer to store the collected final byte payload.
 * @return STD_RET: E_OK on successful read frame execution.
 */
STD_RET TWI_ReadByteWithNACK(u8 *Data);

#endif /* TWI_INTERFACE_H_ */
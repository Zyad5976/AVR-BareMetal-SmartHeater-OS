/*
 * SSD_INTERFACE.h
 *
 * Created: 10/6/2026 8:20:03 AM
 *  Author: Eltawel
 */ 


#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

/************************************************************************/
/* 
 this file is the interface (prototypes) for the Seven Segment Display (SSD) driver.

 it provides two clean encapsulated APIs to initialize and update data paths:
 - SSD_Init: configures the whole 8-bit port direction as output.
 - SSD_WriteTwoDigits: splits a number (0-99) into BCD and flushes it to the port.

 usage: create an SSD_CFG_t object, call SSD_Init once at startup, 
 then dynamically pass values directly inside the non-blocking control loops.
                                                                     */
/************************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "SSD_CFG.h"

/*-------------------------------------------*/

/**
 * @brief  Initialize the entire 8-bit port direction as output for the SSD decoders.
 * @param  obj: Pointer to a constant configuration structure holding the SSD object.
 * @return STD_RET: E_OK on successful initialization, E_NOK if NULL pointer is passed.
 */
STD_RET SSD_Init(const SSD_CFG_t *obj);

/**
 * @brief  Display a complete double-digit number (0-99) instantly without multiplexing delays.
 * @param  obj: Pointer to a constant configuration structure holding the SSD object.
 * @param  copy_u8Number: The total combined integer value (0 to 99) to display.
 * @return STD_RET: E_OK on successful write, E_NOK on bounds error or NULL pointer.
 */
STD_RET SSD_WriteTwoDigits(const SSD_CFG_t *obj, u8 copy_u8Number);

#endif /* SSD_INTERFACE_H_ */
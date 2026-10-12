/*
 * OVEN_INTERFACE.h
 *
 * Created: 10/11/2026 2:13:22 AM
 *  Author: Eltawel
 */ 


#ifndef OVEN_INTERFACE_H_
#define OVEN_INTERFACE_H_

/************************************************************************/
/* 

 this file is the interface (prototypes) for the Oven (Heater) HAL driver.

 it provides functions to configure and toggle the heating state:
 - OVEN_Init: configures the control pin as output and forces a safe initial OFF state.
 - OVEN_SetON: explicitly forces the heater to start heating.
 - OVEN_SetOFF: explicitly forces the heater to stop heating.

 usage: create an OVEN_CFG_t object, initialize it at system startup, 
 then trigger SetON/OFF based on the temperature controller logic.
                                                                     */
/************************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "OVEN_CFG.h"

/*-------------------------------------------*/

/**
 * @brief  Initialize the Oven pin direction to output and clear it.
 * @param  obj: Pointer to a constant Oven configuration object.
 * @return STD_RET: E_OK on success, E_NOK on NULL pointer.
 */
STD_RET OVEN_Init(const OVEN_CFG_t *obj);

/**
 * @brief  Turn the Oven heating element ON.
 * @param  obj: Pointer to a constant Oven configuration object.
 * @return STD_RET: E_OK on success, E_NOK on NULL pointer.
 */
STD_RET OVEN_SetON(const OVEN_CFG_t *obj);

/**
 * @brief  Turn the Oven heating element OFF.
 * @param  obj: Pointer to a constant Oven configuration object.
 * @return STD_RET: E_OK on success, E_NOK on NULL pointer.
 */
STD_RET OVEN_SetOFF(const OVEN_CFG_t *obj);

#endif /* OVEN_INTERFACE_H_ */
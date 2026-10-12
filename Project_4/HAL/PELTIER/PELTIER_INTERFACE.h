/*
 * PELTIER_INTERFACE.h
 *
 * Created: 10/11/2026 12:22:13 AM
 *  Author: Eltawel
 */ 

#ifndef PELTIER_INTERFACE_H_
#define PELTIER_INTERFACE_H_

/************************************************************************/
/* 

 this file is the interface (prototypes) for the Peltier Cooler HAL driver.

 it provides functions to fully configure and drive the thermoelectric cooling unit:
 - PELTIER_Init: configures the control pin direction as output and ensures safe OFF state.
 - PELTIER_SetON: explicitly forces the Peltier module to activate cooling.
 - PELTIER_SetOFF: explicitly forces the Peltier module to deactivate cooling.

 usage: instantiate a PELTIER_CFG_t structure object, call PELTIER_Init once 
 during main system startup, then invoke SetON/OFF inside the dynamic control loops.
                                                                     */
/************************************************************************/

/*-------------------------------------------*/

#include "../../LIB/STD_TYPES.h"
#include "PELTIER_CFG.h"

/*-------------------------------------------*/

/**
 * @brief  Initialize the Peltier hardware pin by setting its direction to output.
 * @param  obj: Pointer to a constant configuration structure holding the Peltier object info.
 * @return STD_RET: E_OK on successful initialization, E_NOK if a NULL pointer is passed.
 */
STD_RET PELTIER_Init(const PELTIER_CFG_t *obj);

/**
 * @brief  Turn the Peltier cooling module ON by applying a high voltage level to the control pin.
 * @param  obj: Pointer to a constant configuration structure holding the Peltier object info.
 * @return STD_RET: E_OK on successful operation, E_NOK if a NULL pointer is passed.
 */
STD_RET PELTIER_SetON(const PELTIER_CFG_t *obj);

/**
 * @brief  Turn the Peltier cooling module OFF by applying a low voltage level to the control pin.
 * @param  obj: Pointer to a constant configuration structure holding the Peltier object info.
 * @return STD_RET: E_OK on successful operation, E_NOK if a NULL pointer is passed.
 */
STD_RET PELTIER_SetOFF(const PELTIER_CFG_t *obj);

#endif /* PELTIER_INTERFACE_H_ */
/*
 * FAN_INTERFACE.h
 *
 * Created: 10/10/2026 4:13:51 PM
 *  Author: Eltawel
 */ 


#ifndef FAN_INTERFACE_H_
#define FAN_INTERFACE_H_

/************************************************************************/
/* 

 this file is the interface (prototypes) for the Fan HAL driver.

 it provides functions to fully initialize and control the DC fan hardware:
 - FAN_Init: configures the fan hardware pin as an output channel.
 - FAN_SetON: explicitly forces the fan motor to start spinning.
 - FAN_SetOFF: explicitly forces the fan motor to stop spinning.
 - FAN_Toggle: reverses the current operational state of the fan motor.

 usage: instantiate a FAN_CFG_t configuration object, call FAN_Init once 
 at startup, then control the motor using the SetON/OFF or Toggle APIs.
                                                                     */
/************************************************************************/

/*-------------------------------------------*/

#include "../../LIB/STD_TYPES.h"
#include "FAN_CFG.h"

/*-------------------------------------------*/

/**
 * @brief  Initialize the fan hardware pin by setting its direction to output.
 * @param  obj: Pointer to a constant configuration structure holding the fan object info.
 * @return STD_RET: E_OK on successful initialization, E_NOK if a NULL pointer is passed.
 */
STD_RET FAN_Init(const FAN_CFG_t *obj);

/**
 * @brief  Turn the fan motor ON by applying a high voltage level to the control pin.
 * @param  obj: Pointer to a constant configuration structure holding the fan object info.
 * @return STD_RET: E_OK on successful operation, E_NOK if a NULL pointer is passed.
 */
STD_RET FAN_SetON(const FAN_CFG_t *obj);

/**
 * @brief  Turn the fan motor OFF by applying a low voltage level to the control pin.
 * @param  obj: Pointer to a constant configuration structure holding the fan object info.
 * @return STD_RET: E_OK on successful operation, E_NOK if a NULL pointer is passed.
 */
STD_RET FAN_SetOFF(const FAN_CFG_t *obj);

/**
 * @brief  Toggle the current state of the fan motor (turns OFF if ON, and vice versa).
 * @param  obj: Pointer to a constant configuration structure holding the fan object info.
 * @return STD_RET: E_OK on successful operation, E_NOK if a NULL pointer is passed.
 */
STD_RET FAN_Toggle(const FAN_CFG_t *obj);

#endif /* FAN_INTERFACE_H_ */
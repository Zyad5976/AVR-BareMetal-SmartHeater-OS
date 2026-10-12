/*
 * RELAY_INTERFACE.h
 *
 * Created: 10/9/2026 11:56:48 PM
 *  Author: Eltawel
 */ 


#ifndef RELAY_INTERFACE_H_
#define RELAY_INTERFACE_H_

/************************************************************************/
/* 

 this file is the interface (prototypes) for the Relay HAL driver.

 it provides three functions to control the external relay module:
 - RELAY_Init: configures the relay GPIO pin as output and switches it 
   to the default safe OFF state based on its connection type.
 - RELAY_SetState: explicitly forces the relay to switch ON or OFF, 
   automatically handling the ACTIVE_LOW/HIGH inversion logic.
 - RELAY_Toggle: flips the current status of the relay, which is highly 
   useful when binding a toggle button to control an appliance.

 usage: create a RELAY_CFG_t object, pass it to RELAY_Init once at startup,
 then call RELAY_SetState or RELAY_Toggle within your app logic.
                                                                     */
/************************************************************************/

/*-------------------------------------------*/

#include "RELAY_CFG.h"

/*-------------------------------------------*/

STD_RET RELAY_Init(const RELAY_CFG_t *obj);

STD_RET RELAY_SetState(const RELAY_CFG_t *obj, const RELAY_STATE_t state);

STD_RET RELAY_Toggle(const RELAY_CFG_t *obj);


#endif /* RELAY_INTERFACE_H_ */
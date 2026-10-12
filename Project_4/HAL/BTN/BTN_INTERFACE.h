/*
 * BTN_INTERFACE.h
 *
 * Created: 10/9/2026 6:46:08 AM
 *  Author: Eltawel
 */ 


#ifndef BTN_INTERFACE_H_
#define BTN_INTERFACE_H_

/************************************************************************/
/* 

 this file is the interface (prototypes) for the Button (BTN) HAL driver.

 it provides two functions to control and monitor button states:
 - BTN_Init: configures the target GPIO pin direction as input and 
   handles internal pull-up activation if ACTIVE_LOW is selected.
 - BTN_Status: reads the real hardware logic value through the MCAL layer 
   and translates it to a structured state (PRESSED or RELEASED).

 usage: create a BTN_CFG_t object, pass its reference to BTN_Init once 
 at startup, then pass it to BTN_Status inside your application loop.
                                                                     */
/************************************************************************/

/************************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "BTN_CFG.h"

/************************************************************************/

/**
 * @brief  Initialize the button pin direction and pull-up configuration.
 * @param  Config: Pointer to the button configuration structure (Object).
 * @return STD_RET: E_OK on success, E_NOK on failure.
 */
STD_RET BTN_Init(const BTN_CFG_t *obj);

/**
 * @brief  Read the current state of the button (Pressed or Released).
 * @param  Config: Pointer to the button configuration structure (Object).
 * @param  State: Pointer to store the returned state (BTN_PRESSED / BTN_RELEASED).
 * @return STD_RET: E_OK on success, E_NOK on failure.
 */
STD_RET BTN_Status(const BTN_CFG_t *obj, BTN_STATE_t *state);


#endif /* BTN_INTERFACE_H_ */
/*
 * BTN_CFG.h
 *
 * Created: 10/9/2026 6:56:16 AM
 *  Author: Eltawel
 */ 


#ifndef BTN_CFG_H_
#define BTN_CFG_H_

/************************************************************************/
/* 
 
 this file is the configuration of the Button (BTN) HAL driver.

 it defines:
 - BTN_CONNECTION_t: electrical connection type of the button. 
   ACTIVE_LOW represents pull-up configuration (pressed reads 0), 
   while ACTIVE_HIGH represents pull-down configuration (pressed reads 1).
 - BTN_STATE_t: logical state of the button, mapping the physical 
   voltage levels to either PRESSED or RELEASED.
 - BTN_CFG_t: configuration structure that combines port, pin, and 
   connection type to easily instantiate multiple button objects.

 WARNING: make sure the connection type matches your hardware layout, 
 otherwise the button state logic in BTN_Status will be inverted.
                                                                     */
/************************************************************************/

/*-------------------------------------------*/

#include "../../MCAL/DIO/DIO_INTERFACE.h"

/*-------------------------------------------*/

/* Button Connection Type */
typedef enum
{
	BTN_ACTIVE_HIGH = 0,
	BTN_ACTIVE_LOW
}BTN_CONNECTION_t;

/* Button Logical State */
typedef enum
{
	BTN_RELEASED = 0,
	BTN_PRESSED
}BTN_STATE_t;

/* Button Object Configuration */
typedef struct
{
	DIO_PORT_t port;
	DIO_PIN_t pin;
	BTN_CONNECTION_t connection;
}BTN_CFG_t;


#endif /* BTN_CFG_H_ */
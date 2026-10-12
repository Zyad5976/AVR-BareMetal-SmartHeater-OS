/*
 * RELAY_CFG.h
 *
 * Created: 10/9/2026 11:56:31 PM
 *  Author: Eltawel
 */ 


#ifndef RELAY_CFG_H_
#define RELAY_CFG_H_

/************************************************************************/
/* 
 
 this file is the configuration of the Relay HAL driver.

 it defines:
 - RELAY_CONNECTION_t: electrical connection type of the relay module.
   RELAY_ACTIVE_LOW represents modules that trigger on a low voltage (0V),
   while RELAY_ACTIVE_HIGH represents modules that trigger on a high voltage (5V).
 - RELAY_STATE_t: control commands to switch the relay either ON or OFF.
 - RELAY_CFG_t: configuration structure that maps the target GPIO port, 
   pin, and connection type to handle multiple relay instances easily.

 WARNING: make sure the connection type matches your relay hardware module,
 otherwise the ON/OFF switching logic will be inverted.
                                                                     */
/************************************************************************/

/*-------------------------------------------*/

#include "../../MCAL/DIO/DIO_INTERFACE.h"

/*-------------------------------------------*/

/* Relay Connection Type  */
typedef enum
{
	RELAY_ACTIVE_LOW = 0,
	RELAY_ACTIVE_HIGH
}RELAY_CONNECTION_t;

/* Relay Control Status */
typedef enum
{
	RELAY_OFF = 0,
	RELAY_ON
}RELAY_STATE_t;

/* Relay Object */
typedef struct
{
	DIO_PORT_t port;
	DIO_PIN_t pin;
	RELAY_CONNECTION_t connection;
}RELAY_CFG_t;

#endif /* RELAY_CFG_H_ */
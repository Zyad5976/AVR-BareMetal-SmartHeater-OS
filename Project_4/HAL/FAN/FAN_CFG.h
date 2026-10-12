/*
 * FAN_CFG.h
 *
 * Created: 10/10/2026 4:13:40 PM
 *  Author: Eltawel
 */ 


#ifndef FAN_CFG_H_
#define FAN_CFG_H_

/************************************************************************/
/* 
 
 this file is the configuration of the Fan HAL driver.

 it defines:
 - FAN_STATE_t: logical state tracking components for the fan module,
   representing whether the fan motor is running (ON) or stopped (OFF).
 - FAN_CFG_t: configuration structure that encapsulates the target GPIO 
   port and pin connected to the fan driver circuit (e.g., DC Motor / Relay).

 WARNING: ensure that the fan pin is connected to a proper power driver 
 (like a transistor or H-bridge) since the MCU pin cannot drive a motor directly.
                                                                     */
/************************************************************************/

/*-------------------------------------------*/

#include "../../MCAL/DIO/DIO_INTERFACE.h"

/*-------------------------------------------*/

/* Fan Operational State */
typedef enum
{
	FAN_OFF = 0,
	FAN_ON
}FAN_STATE_t;

/* Fan Object Configuration */
typedef struct
{
	DIO_PORT_t fan_port;
	DIO_PIN_t fan_pin;
	FAN_STATE_t fan_state;
}FAN_CFG_t;


#endif /* FAN_CFG_H_ */
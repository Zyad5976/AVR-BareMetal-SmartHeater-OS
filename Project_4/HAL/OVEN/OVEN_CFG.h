/*
 * OVEN_CFG.h
 *
 * Created: 10/11/2026 2:13:10 AM
 *  Author: Eltawel
 */ 


#ifndef OVEN_CFG_H_
#define OVEN_CFG_H_

/************************************************************************/
/* 
 
 this file is the configuration of the Oven (Heater) HAL driver.

 it defines:
 - OVEN_STATE_t: control commands to switch the heating element ON or OFF.
 - OVEN_CFG_t: configuration structure that maps the target GPIO port 
   and pin connected to the relay that drives the Oven hardware component.

 WARNING: the Oven model in Proteus simulates thermal mass; it will take 
 some time to heat up or cool down, which is normal for heating simulations.
                                                                     */
/************************************************************************/

/*-------------------------------------------*/

#include "../../MCAL/DIO/DIO_INTERFACE.h"

/*-------------------------------------------*/

/* Oven Control Status */
typedef enum
{
	OVEN_OFF = 0,
	OVEN_ON
}OVEN_STATE_t;

/* Oven Object Structure */
typedef struct
{
	DIO_PORT_t oven_port;
	DIO_PIN_t oven_pin;
	OVEN_STATE_t oven_state;
}OVEN_CFG_t;


#endif /* OVEN_CFG_H_ */
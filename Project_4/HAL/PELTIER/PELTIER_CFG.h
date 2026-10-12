/*
 * PELTIER_CFG.h
 *
 * Created: 10/11/2026 12:22:02 AM
 *  Author: Eltawel
 */ 


#ifndef PELTIER_CFG_H_
#define PELTIER_CFG_H_

/************************************************************************/
/* 
 
 this file is the configuration of the Peltier Cooler HAL driver.

 it defines:
 - PELTIER_STATE_t: logical state tracking components for the thermoelectric 
   cooler module, representing whether cooling is running (ON) or stopped (OFF).
 - PELTIER_CFG_t: configuration structure that encapsulates the target GPIO 
   port and pin connected to the external transistor driving the Peltier module.

 WARNING: ensure that the thermal nodes (QC, QH) and diagnostic pins (SM, RM, KM) 
 in Proteus are handled correctly; diagnostic pins must be left completely floating.
                                                                     */
/************************************************************************/

/*-------------------------------------------*/

#include "../../MCAL/DIO/DIO_INTERFACE.h"

/*-------------------------------------------*/

typedef enum
{
	PELTIER_OFF = 0,
	PELTIER_ON
}PELTIER_STATE_t;

typedef struct
{
	DIO_PORT_t peltier_port;
	DIO_PIN_t peltier_pin;
	PELTIER_STATE_t peltier_state;
}PELTIER_CFG_t;


#endif /* PELTIER_CFG_H_ */
/*
 * SSD_CFG.h
 *
 * Created: 10/6/2026 8:19:38 AM
 *  Author: Eltawel
 */ 


#ifndef SSD_CFG_H_
#define SSD_CFG_H_

/************************************************************************/
/* 
 this file is the configuration for the Seven Segment Display (SSD) HAL driver.

 it defines:
 - SSD_CFG_t: configuration structure that encapsulates the single 8-bit 
   GPIO data port used to drive both displays simultaneously.
   (Pins 0 to 3 = Units Decoder, Pins 4 to 7 = Tens Decoder).

 NOTE: by using a full port design, all hardware enable pins, latching, 
 and multi-plexing delays are completely removed from the software layer.
                                                                     */
/************************************************************************/

/*-------------------------------------------*/

#include "../../MCAL/DIO/DIO_INTERFACE.h"

/*-------------------------------------------*/

/* SSD Hardware Object Structure */
typedef struct
{
	DIO_PORT_t data_port;  /* Target GPIO Port connected to both BCD decoders */
}SSD_CFG_t;



#endif /* SSD_CFG_H_ */
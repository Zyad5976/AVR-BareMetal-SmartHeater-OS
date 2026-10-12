/*
 * LM35_INTERFACE.h
 *
 * Created: 10/11/2026 12:41:26 PM
 *  Author: Eltawel
 */ 


#ifndef LM35_INTERFACE_H_
#define LM35_INTERFACE_H_

/************************************************************************/
/* 

 this file is the interface (prototypes) for the LM35 Temperature Sensor HAL driver.

 it provides one main core function:
 - LM35_u8GetTemp: reads the raw analog data from the specified ADC channel, 
   applies the mathematical scaling formula, and returns the temperature in Celsius.

 usage: call LM35_u8GetTemp inside your application periodic task (e.g., every 100ms) 
 passing the ADC channel where the sensor output pin is hardware-wired.
                                                                     */
/************************************************************************/

#include "../../LIB/STD_TYPES.h"

/*-------------------------------------------*/

/**
 * @brief  Read the current temperature in Celsius from the LM35 sensor.
 * @param  Channel: The ADC channel index (0 to 7) connected to the sensor.
 * @param  Temp: Pointer to store the output temperature value (0 to 150 °C).
 * @return STD_RET: E_OK on successful reading, E_NOK if a NULL pointer is passed.
 */
STD_RET LM35_GetTemp(u8 Channel, u8 *Temp);


#endif /* LM35_INTERFACE_H_ */
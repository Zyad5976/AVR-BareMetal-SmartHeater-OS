/*
 * ADC_INTERFACE.h
 *
 * Created: 10/11/2026 3:36:16 AM
 *  Author: Eltawel
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

/************************************************************************/
/* 

 this file is the interface (prototypes) for the MCAL ADC driver.

 it provides two key APIs to handle analog data conversion:
 - ADC_Init: configures the digital peripheral global state, reference voltage, 
   and timing prescalers during the main firmware boot sequence.
 - ADC_ReadChannel: dynamic channel scanning function that starts a single-ended 
   conversion on a selected pin and blocks until the digital output is locked.

 usage: call ADC_Init once during boot up, then poll ADC_ReadChannel passing 
 the targeted channel identifier (0 to 7) to collect hardware voltage frames.
                                                                     */
/************************************************************************/

#include "../../LIB/STD_TYPES.h"

/*-------------------------------------------*/

/**
 * @brief  Initialize the peripheral ADC module registers based on configuration parameters.
 * @param  void
 * @return STD_RET: E_OK on successful initialization sequence.
 */
STD_RET ADC_Init(void);

/**
 * @brief  Perform a synchronous blocking read of a single-ended analog channel.
 * @param  channel: Target single-ended input channel index (Valid ranges: 0 to 7).
 * @return u16: 10-bit digital sample resolved from the processed input analog wave (0 to 1023).
 */
u16 ADC_ReadChannel(u8 channel);

#endif /* ADC_INTERFACE_H_ */
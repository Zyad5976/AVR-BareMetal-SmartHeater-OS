/*
 * TIM1_INTERFACE.h
 *
 * Created: 10/12/2026 2:02:31 AM
 *  Author: Eltawel
 */ 


#ifndef TIM1_INTERFACE_H_
#define TIM1_INTERFACE_H_


/************************************************************************/
/* 
 this file is the interface (prototypes) for the MCAL Timer1 driver.

 it provides APIs to handle background timing interrupts for the OS Scheduler:
 - TIM1_Init: configures the 16-bit timer to run in CTC mode with a 1ms match.
 - TIM1_SetCallBack: registers the application layer scheduler execution loop 
   pointer to be processed inside the hardware ISR vector.

 usage: call TIM1_Init once at system boot, set the CallBack destination frame, 
 then enable Global Interrupts to fire the engine.
                                                                     */
/************************************************************************/

#include "../../LIB/STD_TYPES.h"

/*-------------------------------------------*/

/**
 * @brief  Initialize Timer1 in CTC Mode 4 (Compare Match on OCR1A) to trigger every 1ms.
 * @param  void
 * @return STD_RET: E_OK on successful initialization sequence.
 */
STD_RET TIM1_Init(void);

/**
 * @brief  Register a custom function (Callback) to execute periodically inside the Timer1 ISR.
 * @param  Copy_pvCallBackFunc: Pointer to a void function representing the scheduler framework.
 * @return STD_RET: E_OK on successful callback injection, E_NOK if NULL pointer is passed.
 */
STD_RET TIM1_SetCallBack(void (*Copy_pvCallBackFunc)(void));

#endif /* TIM1_INTERFACE_H_ */
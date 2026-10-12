/*
 * GI_INTERFACE.h
 *
 * Created: 10/9/2026 6:22:29 AM
 *  Author: Eltawel
 */ 


#ifndef GI_INTERFACE_H_
#define GI_INTERFACE_H_

/************************************************************************/
/* 

 this file contains the interface (prototypes) for the Global Interrupt
 (GI) driver. It provides control over the MCU's global interrupt enable
 flag (I-bit in SREG).

 Usage:
 - Call GI_Enable() to allow the MCU to service any peripheral interrupts.
 - Call GI_Disable() to temporarily mask all interrupts (Critical Sections).
                                                                     */
/************************************************************************/


/*
 * @brief  Enable global interrupts by setting the I-bit in the Status Register (SREG).
 * @param  void
 * @return STD_RET: E_OK on success, E_NOK on failure.
 * @note   This function executes the assembly instruction (SEI).
*/
STD_RET GI_Enable(void);

/*
 *@brief  Disable global interrupts by clearing the I-bit in the Status Register (SREG).
 * @param  void
 * @return STD_RET: E_OK on success, E_NOK on failure.
 * @note   This function executes the assembly instruction (CLI).
*/
STD_RET GI_Disable(void);


#endif /* GI_INTERFACE_H_ */
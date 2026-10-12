/*
 * GI_REG.h
 *
 * Created: 10/9/2026 6:41:18 AM
 *  Author: Eltawel
 */ 


#ifndef GI_REG_H_
#define GI_REG_H_

/************************************************************************/
/* 
 this file defines the Global Interrupt configuration register for ATmega32.
 It maps the AVR Status Register (SREG) using Bit-Fields to allow structured 
 bit access, specifically for the Global Interrupt Enable bit (I-bit).

 Register Map Reference: ATmega32 Datasheet - Status Register (SREG)
                                                                     */
/************************************************************************/

/**
 * @brief Bit-Field structure representing the Status Register (SREG).
 * @note  Only the I-bit (Bit 7) is defined here as it is the only bit
 *        controlled by the GI driver. Bits 0 to 6 are reserved for ALU flags.
 */
typedef struct
{
	u8 I : 1;
}SREG_BITS_t;

/*----------------------------------------------------------------------*/

/* Status Register Memory Map Address (0x5F) */
#define SREG_REG			(*(volatile SREG_BITS_t)0x5F)


#endif /* GI_REG_H_ */
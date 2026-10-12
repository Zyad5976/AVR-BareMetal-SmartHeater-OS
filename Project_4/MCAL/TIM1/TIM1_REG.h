/*
 * TIM1_REG.h
 *
 * Created: 10/12/2026 2:02:04 AM
 *  Author: Eltawel
 */ 


#ifndef TIM1_REG_H_
#define TIM1_REG_H_

/************************************************************************/
/* 
 this file defines the 16-bit Timer/Counter1 (TIM1) registers for ATmega32.
 It maps control registers A and B using precise Bit-Fields, and defines 
 the 16-bit data registers (TCNT1, OCR1A) for direct atomic access.

 Register Map Reference: ATmega32 Datasheet - Timer1 Peripheral (Pages 109-112)
                                                                     */
/************************************************************************/

#include "../../LIB/STD_TYPES.h"

/* Timer1 Control Register A Bits (TCCR1A - Address 0x4F) */
typedef struct
{
	u8 WGM10_BIT  : 1;	/* Bit 0: Waveform Generation Mode Bit 0 */
	u8 WGM11_BIT  : 1;	/* Bit 1: Waveform Generation Mode Bit 1 */
	u8 FOC1B_BIT  : 1;	/* Bit 2: Force Output Compare for Channel B */
	u8 FOC1A_BIT  : 1;	/* Bit 3: Force Output Compare for Channel A */
	u8 COM1B0_BIT : 1;	/* Bit 4: Compare Output Mode for Channel B Bit 0 */
	u8 COM1B1_BIT : 1;	/* Bit 5: Compare Output Mode for Channel B Bit 1 */
	u8 COM1A0_BIT : 1;	/* Bit 6: Compare Output Mode for Channel A Bit 0 */
	u8 COM1A1_BIT : 1;	/* Bit 7: Compare Output Mode for Channel A Bit 1 */
}TCCR1A_BITS_t;

/* Timer1 Control Register B Bits (TCCR1B - Address 0x4E) */
typedef struct
{
	u8 CS10_BIT   : 1;	/* Bit 0: Clock Select Bit 0 */
	u8 CS11_BIT   : 1;	/* Bit 1: Clock Select Bit 1 */
	u8 CS12_BIT   : 1;	/* Bit 2: Clock Select Bit 2 */
	u8 WGM12_BIT  : 1;	/* Bit 3: Waveform Generation Mode Bit 2 (CTC) */
	u8 WGM13_BIT  : 1;	/* Bit 4: Waveform Generation Mode Bit 3 */
	u8 RESERVED   : 1;	/* Bit 5: Reserved Bit */
	u8 ICES1_BIT  : 1;	/* Bit 6: Input Capture Edge Select */
	u8 ICNC1_BIT  : 1;	/* Bit 7: Input Capture Noise Canceler */
}TCCR1B_BITS_t;

/* TIMSK Interrupt Mask Register Bits (Shared Register - Address 0x59) */
typedef struct
{
	u8 TOIE0_BIT  : 1;	/* Timer0 Overflow Interrupt Enable */
	u8 OCIE0_BIT  : 1;	/* Timer0 Compare Match Interrupt Enable */
	u8 TOIE1_BIT  : 1;	/* Bit 2: Timer1 Overflow Interrupt Enable */
	u8 OCIE1B_BIT : 1;	/* Bit 3: Timer1 Output Compare Match B Interrupt Enable */
	u8 OCIE1A_BIT : 1;	/* Bit 4: Timer1 Output Compare Match A Interrupt Enable */
	u8 TICIE1_BIT : 1;	/* Bit 5: Timer1 Input Capture Interrupt Enable */
	u8 TOIE2_BIT  : 1;	/* Timer2 Overflow Interrupt Enable */
	u8 OCIE2_BIT  : 1;	/* Timer2 Compare Match Interrupt Enable */
}TIM1_TIMSK_BITS_t;

/*----------------------------------------------------------------------*/

/* Control Registers Definitions */
#define TCCR1A_REG			(*((volatile TCCR1A_BITS_t*)0x4F))
#define TCCR1B_REG			(*((volatile TCCR1B_BITS_t*)0x4E))
#define TIM1_TIMSK_REG		(*((volatile TIM1_TIMSK_BITS_t*)0x59))

/* 16-bit Counter Register Pointer (Base Address 0x2C: TCNT1L + TCNT1H) */
#define TCNT1_REG			(*((volatile u16*)0x2C))

/* 16-bit Output Compare Register A Pointer (Base Address 0x2A: OCR1AL + OCR1AH) */
#define OCR1A_REG			(*((volatile u16*)0x2A))

#endif /* TIM1_REG_H_ */
/*
 * ADC_REG.h
 *
 * Created: 10/11/2026 3:36:04 AM
 *  Author: Eltawel
 */ 


#ifndef ADC_REG_H_
#define ADC_REG_H_

/************************************************************************/
/* 
 
 this file defines the Analog-to-Digital Converter (ADC) registers for ATmega32.
 It maps ADMUX and ADCSRA control registers using precise Bit-Fields to allow 
 structured configuration of voltage reference, channels, and clock prescalers.

 Register Map Reference: ATmega32 Datasheet - ADC Peripheral Registers (0x27, 0x26, 0x24)
                                                                     */
/************************************************************************/

/*-------------------------------------*/

#include "../../LIB/STD_TYPES.h"

/*-------------------------------------*/

/* Multiplexer Selection Register Bits */
typedef struct
{
	u8 MUX0_BIT  : 1;	/* Analog Channel and Gain Selection Bit */
	u8 MUX1_BIT  : 1;	/* Analog Channel and Gain Selection Bit */
	u8 MUX2_BIT  : 1;	/* Analog Channel and Gain Selection Bit */
	u8 MUX3_BIT  : 1;	/* Analog Channel and Gain Selection Bit */
	u8 MUX4_BIT  : 1;	/* Analog Channel and Gain Selection Bit */
	u8 ADLAR_BIT : 1;	/* ADC Left Adjust Result */
	u8 REFS0_BIT : 1;	/* Reference Selection Bit */
	u8 REFS1_BIT : 1;	/* Reference Selection Bit */
}ADMUX_BITS_t;

/* Control and Status Register A Bits */
typedef struct
{
	u8 ADPS0_BIT : 1;	/* ADC Prescaler Select Bits */
	u8 ADPS1_BIT : 1;	/* ADC Prescaler Select Bits */
	u8 ADPS2_BIT : 1;	/* ADC Prescaler Select Bits */
	u8 ADIE_BIT  : 1;	/* ADC Interrupt Enable (Cleared by writing 1) */
	u8 ADIF_BIT  : 1;	/* ADC Interrupt Flag */
	u8 ADATE_BIT : 1;	/* ADC Auto Trigger Enable */
	u8 ADSC_BIT  : 1;	/* ADC Start Convention */
	u8 ADEN_BIT  : 1;	/* ADC Enable */
}ADCSRA_BITS_t;

/*----------------------------------------------------------------------*/

#define ADMUX_REG			(*((volatile ADMUX_BITS_t*)0x27))

#define ADCSRA_REG			(*((volatile ADCSRA_BITS_t*)0x26))

#define ADCL_REG			(*((volatile u16*)0x24))

#endif /* ADC_REG_H_ */
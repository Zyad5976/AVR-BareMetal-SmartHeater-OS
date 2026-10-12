/*
 * TIM0_REG.h
 *
 * Created: 10/7/2026 12:23:29 AM
 *  Author: Eltawel
 */ 


#ifndef TIM0_REG_H_
#define TIM0_REG_H_

/************************************************************************/
/* 

 this file defines the Timer0 registers of the ATmega32: the address of
 each register and the bit positions used by the TIM0 driver
 (source: ATmega32 datasheet).
 the registers are:
 
	-TCCR0_REG	--> 0x53
		------------------------------------------------------------
		FOC0_BIT	WGM00_BIT	COM01_BIT	COM00_BIT	WGM01_BIT	CS02_BIT	CS01_BIT	CS00_BIT
			7			6			5		  4				3			2			1			0
		 
	-TIMSK_REG	--> 0x59
	--------------------
		 OCIE0_BIT	TOIE0_BIT
			 1			0
		   
	-TIFR_REG	--> 0x58
	--------------------
		OCF0_BIT	TOV0_BIT
			1			0
		  
	-TCNT0_REG	--> 0X52
	--------------------
	
	-OCR0_REG	--> 0X5C
		   
                                                                     */
/************************************************************************/

/* Register Bits */

/* TCCR0_BITS */
typedef struct
{
	u8 CS00_BIT	 :  1;		/* CLock Select */
	u8 CS01_BIT	 :  1;		/* CLock Select */
	u8 CS02_BIT	 :  1;		/* CLock Select */
	u8 WGM01_BIT :	1;		/* Wave Generation Mode */
	u8 COM00_BIT :	1;		/* Compare Match Output Mode */
	u8 COM01_BIT :	1;		/* Compare Match Output Mode */
	u8 WGM00_BIT :	1;		/* Wave Generation Mode */
	u8 FOC0_BIT  :	1;		/* Force Output Compare */
}TCCR0_BITS_t;


/* TIMSK_BITS */
typedef struct
{
	u8 TOIE0_BIT : 1;	/* Timer/Counter0 Overflow Interrupt Enable */
	u8 OCIE0_BIT : 1;	/* Timer/Counter0 Output Compare Match Interrupt Enable */
}TIMSK_BITS_t;	
	

/* TIFR_BITS */
typedef struct
{
	u8 TOV0_BIT : 1;		/* Output Compare Flag 0 */
	u8 OCF0_BIT	: 1;		/* Timer/Counter0 Overflow Flag */
}TIFR_BITS_t;

/* Registers */
#define TCCR0_REG				(*((volatile TCCR0_BITS_t*)0x53))

#define TIMSK_REG				(*((volatile TIMSK_BITS_t*)0x59))

#define TIFR_REG				(*((volatile TIFR_BITS_t*)0x58))

#define TCNT0_REG				(*((volatile u8*)0x52))

#define OCR0_REG				(*((volatile u8*)0x5C))

/*------------------------------------------------------*/

#endif /* TIM0_REG_H_ */
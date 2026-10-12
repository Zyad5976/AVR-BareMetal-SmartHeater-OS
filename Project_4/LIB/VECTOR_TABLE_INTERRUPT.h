/*
 * VECTOR_TABLE_INTERRUPT.h
 *
 * Created: 10/5/2026 7:48:27 AM
 *  Author: Eltawel
 */ 


#ifndef VECTOR_TABLE_INTERRUPT_H_
#define VECTOR_TABLE_INTERRUPT_H_

/************************************************************************/
/* 

 tthis file defines the ATmega32 interrupt vector table from scratch,
 without relying on avr-libc's <avr/interrupt.h>.

 it provides:
 - readable names for each interrupt vector (e.g. TIMER1_OVF
 instead of __vector_9), matching the vector numbers in the
 ATmega32 datasheet interrupt vector table.
 - an ISR(x) macro that expands to a correctly-attributed
 function definition, used exactly like:

 ISR(TIMER1_OVF)
 {
	 // handler code here
 }

 NOTE: this is a direct, self-written alternative to avr-libc's
 interrupt handling (no external library/header is used anywhere
 in this project).
                                                                     */
/************************************************************************/

#define ISR(__vector_num)		void __vector_num( void ) __attribute__((signal)); \
							void __vector_num(void)
							

#define INT0					__vector_1
#define INT1					__vector_2
#define INT2					__vector_3
#define TIMER2_COMP				__vector_4
#define TIMER2_OVF				__vector_5
#define TIMER1_CAPT				__vector_6
#define TIMER1_COMP_A			__vector_7
#define TIMER1_COMP_B			__vector_8
#define TIMER1_OVF				__vector_9
#define TIMER0_COMP				__vector_10
#define TIMER0_OVF				__vector_11
#define SPI_STC					__vector_12
#define USART_RXC				__vector_13
#define USART_UDRE				__vector_14
#define USART_TXC				__vector_15
#define ADC						__vector_16
#define EE_RDY					__vector_17
#define ANA_COMP				__vector_18
#define TWI						__vector_19
#define SPM_RDY					__vector_20

#endif /* VECTOR_TABLE_INTERRUPT_H_ */
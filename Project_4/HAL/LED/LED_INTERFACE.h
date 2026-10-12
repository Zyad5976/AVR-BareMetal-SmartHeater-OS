/*
 * LED_INTERFACE.h
 *
 * Created: 10/5/2026 8:07:08 PM
 *  Author: Eltawel
 */ 


#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

/************************************************************************/
/* 

 this file consists of LED Functions --> void LED_ON(port, pin)
										 void LED_OFF(port, pin)
										 void LED_TOGGLE(port, pin)
                                                                     */
/************************************************************************/

/*
 *@brief:		turn led on --> dir == output, val == high
 *@param:		DIO_PORT_t port: enum consists of number of ports
				DIO_PIN_t pin :  enum consists of number of pins
 *@return:		none
*/
void LED_voidON(DIO_PORT_t port, DIO_PIN_t pin);

/*
 *@brief:		turn led off --> dir == output, val == low
 *@param:		DIO_PORT_t port: enum consists of number of ports
				DIO_PIN_t pin :  enum consists of number of pins
 *@return:		none
*/
void LED_voidOFF(DIO_PORT_t port, DIO_PIN_t pin);

/*
 *@brief:		turn led toggle --> dir == output
 *@param:		DIO_PORT_t port: enum consists of number of ports
				DIO_PIN_t pin :  enum consists of number of pins
 *@return:		none
*/
void LED_voidTOGGLE(DIO_PORT_t port, DIO_PIN_t pin);


#endif /* LED_INTERFACE_H_ */
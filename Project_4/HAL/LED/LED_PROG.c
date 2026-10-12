/*
 * LED_PROG.c
 *
 * Created: 10/5/2026 8:07:21 PM
 *  Author: Eltawel
 */ 

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_INTERFACE.h"
#include "LED_INTERFACE.h"

void LED_voidON(DIO_PORT_t port, DIO_PIN_t pin)
{
	DIO_CFG_t led_1 = {.port = port, .pin = pin, .dir = DIO_OUTPUT, .val = DIO_HIGH};
		
	DIO_SetPinDir(&led_1);
	DIO_SetPinVal(&led_1);
}

void LED_voidOFF(DIO_PORT_t port, DIO_PIN_t pin)
{
	DIO_CFG_t led_1 = {.port = port, .pin = pin, .dir = DIO_OUTPUT, .val = DIO_LOW};
	
	DIO_SetPinDir(&led_1);
	DIO_SetPinVal(&led_1);
}

void LED_voidTOGGLE(DIO_PORT_t port, DIO_PIN_t pin)
{
	DIO_CFG_t led_1 = {.port = port, .pin = pin, .dir = DIO_OUTPUT};
	
	DIO_SetPinDir(&led_1);
	DIO_TogglePin(&led_1);
}
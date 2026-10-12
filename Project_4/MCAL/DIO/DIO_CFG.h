/*
 * DIO_CFG.h
 *
 * Created: 10/5/2026 12:12:18 PM
 *  Author: Eltawel
 */ 


#ifndef DIO_CFG_H_
#define DIO_CFG_H_

/************************************************************************/
/* 

 this file is the configuration of ports, pins, direction and value if ports and pins
 it's consists of enums and struct
 
 we have enum for direction , enum for value , enum for ports, enum for pins and struct 
 combines port, pin, direction and value 
 
 this struct to ease selection which port, pin, what do you want from direction (INPUT or OUTPUT)
 and what do you from value (HIGH or LOW)
                                                                     */
/************************************************************************/


/* select direction */
typedef enum
{
	DIO_INPUT = 0,
	DIO_OUTPUT
}DIO_DIR_t;


/* select value */
typedef enum
{
	DIO_LOW = 0,
	DIO_HIGH = 1,
	DIO_VAL_err
}DIO_VAL_t;


/* select port */
typedef enum
{
	DIO_PORTA = 0,
	DIO_PORTB,
	DIO_PORTC,
	DIO_PORTD
}DIO_PORT_t;


/* select pin */
typedef enum
{
	DIO_PIN0 = 0,
	DIO_PIN1,
	DIO_PIN2,
	DIO_PIN3,
	DIO_PIN4,
	DIO_PIN5,
	DIO_PIN6,
	DIO_PIN7
}DIO_PIN_t;


/* combine selection */
typedef struct
{
	DIO_PORT_t port;
	DIO_PIN_t pin;
	DIO_DIR_t dir;
	DIO_VAL_t val;
}DIO_CFG_t;

#endif /* DIO_CFG_H_ */
/*
 * DIO_PROG.c
 *
 * Created: 10/5/2026 12:12:55 PM
 *  Author: Eltawel
 */ 

/************************************************************************/
/* 

 this file is the implementation (.c) of the DIO driver declared in
 DIO_INTERFACE.h.

 it implements both pin-level functions (SetPinDir, SetPinVal,
 TogglePin, ReadPinVal) using the DIO_CFG_t struct, and port-level
 functions (SetPortDir, SetPortVal) that write a full 8-bit value
 directly to DDRx/PORTx.

 all pin-level functions validate the pointer against NULL and the
 port value against the known DIO_PORT_t cases before touching any
 register, returning E_NOK on any invalid input instead of causing
 undefined behavior.

                                                                     */
/************************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "DIO_CFG.h"
#include "DIO_INTERFACE.h"
#include "DIO_REG.h"

STD_RET DIO_SetPinDir(const DIO_CFG_t *obj)
{
	STD_RET ret = E_OK;
	
	if(obj == null)
	{
		ret = E_NOK;
	}
	else
	{
		switch(obj->port)
		{
			case DIO_PORTA:
					if(obj->dir == DIO_OUTPUT)
					{
						SET_BIT(DDRA_REG, obj->pin);
					}
					else if(obj->dir == DIO_INPUT)
					{
						CLEAR_BIT(DDRA_REG, obj->pin);
					}
					break;
					
			case DIO_PORTB:
					if(obj->dir == DIO_OUTPUT)
					{
						SET_BIT(DDRB_REG, obj->pin);
					}
					else if(obj->dir == DIO_INPUT)
					{
						CLEAR_BIT(DDRB_REG, obj->pin);
					}
					break;
					
			case DIO_PORTC:
					if(obj->dir == DIO_OUTPUT)
					{
						SET_BIT(DDRC_REG, obj->pin);
					}
					else if(obj->dir == DIO_INPUT)
					{
						CLEAR_BIT(DDRC_REG, obj->pin);
					}
					break;
					
			case DIO_PORTD:
					if(obj->dir == DIO_OUTPUT)
					{
						SET_BIT(DDRD_REG, obj->pin);
					}
					else if(obj->dir == DIO_INPUT)
					{
						CLEAR_BIT(DDRD_REG, obj->pin);
					}
					break;
					
				default:
					ret = E_NOK;
					break;
		}
	}
	
	return ret;
}

STD_RET DIO_SetPinVal(const DIO_CFG_t *obj_1)
{
	STD_RET ret = E_OK;
	
	if(obj_1 == null)
	{
		ret = E_NOK;
	}
	else
	{
		switch(obj_1->port)
		{
			case DIO_PORTA:
					if(obj_1->val == DIO_HIGH)
					{
						SET_BIT(PORTA_REG, obj_1->pin);
					}
					else if(obj_1->val == DIO_LOW)
					{
						CLEAR_BIT(PORTA_REG, obj_1->pin);
					}
					break;
					
			case DIO_PORTB:
					if(obj_1->val == DIO_HIGH)
					{
						SET_BIT(PORTB_REG, obj_1->pin);
					}
					else if(obj_1->val == DIO_LOW)
					{
						CLEAR_BIT(PORTB_REG, obj_1->pin);
					}
					break;
					
			case DIO_PORTC:
					if(obj_1->val == DIO_HIGH)
					{
						SET_BIT(PORTC_REG, obj_1->pin);
					}
					else if(obj_1->val == DIO_LOW)
					{
						CLEAR_BIT(PORTC_REG, obj_1->pin);
					}
					break;
					
			case DIO_PORTD:
					if(obj_1->val == DIO_HIGH)
					{
						SET_BIT(PORTD_REG, obj_1->pin);
					}
					else if(obj_1->val == DIO_LOW)
					{
						CLEAR_BIT(PORTD_REG, obj_1->pin);
					}
					break;
					
			default:
				ret = E_NOK;
				break;
		}
	}
	
	return ret;
}

STD_RET DIO_TogglePin(const DIO_CFG_t *obj_1)
{
	STD_RET ret = E_OK;
	
	if(obj_1 == null)
	{
		ret = E_NOK;
	}
	else
	{
		switch(obj_1->port)
		{
			case DIO_PORTA:		TOGGLE_BIT(PORTA_REG, obj_1->pin);	break;
			case DIO_PORTB:		TOGGLE_BIT(PORTB_REG, obj_1->pin);	break;
			case DIO_PORTC:		TOGGLE_BIT(PORTC_REG, obj_1->pin);	break;
			case DIO_PORTD:		TOGGLE_BIT(PORTD_REG, obj_1->pin);	break;
			
			default:
				ret = E_NOK;	break;
		}
	}
	
	return ret;
}

DIO_VAL_t DIO_ReadPinVal(const DIO_CFG_t *obj_1)
{
	DIO_VAL_t ret;
	
	if(obj_1 == null)
	{
		ret = DIO_VAL_err;
	}
	else
	{
		switch(obj_1->port)
		{
			case DIO_PORTA:	ret = GET_BIT(PINA_REG, obj_1->pin);	break;
			case DIO_PORTB:	ret = GET_BIT(PINB_REG, obj_1->pin);	break;
			case DIO_PORTC:	ret = GET_BIT(PINC_REG, obj_1->pin);	break;
			case DIO_PORTD:	ret = GET_BIT(PIND_REG, obj_1->pin);	break;
			
			default: ret = DIO_VAL_err;	break;
		}
	}
	
	return ret;
}

void DIO_SetPortDir(DIO_PORT_t copy_e8port, u8 copy_u8dir)
{
	switch(copy_e8port)
	{
		case DIO_PORTA:	DDRA_REG = copy_u8dir;	break;
		case DIO_PORTB:	DDRB_REG = copy_u8dir;	break;
		case DIO_PORTC:	DDRC_REG = copy_u8dir;	break;
		case DIO_PORTD:	DDRD_REG = copy_u8dir;	break;
	}
}

void DIO_SetPortVal(DIO_PORT_t copy_e8port, u8 copy_u8val)
{
	switch(copy_e8port)
	{
		case DIO_PORTA:	PORTA_REG = copy_u8val;	break;
		case DIO_PORTB:	PORTB_REG = copy_u8val;	break;
		case DIO_PORTC:	PORTC_REG = copy_u8val;	break;
		case DIO_PORTD:	PORTD_REG = copy_u8val;	break;
	}
}
/*
 * BIT_MATH.h
 *
 * Created: 10/5/2026 7:47:41 AM
 *  Author: Eltawel
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

/************************************************************************/
/* 

 this file provides generic bit-manipulation macros (set, clear,
 toggle, get) that work on any 8-bit or 16-bit register/variable.

 usage: SET_BIT(REGISTER, BIT_NUMBER)
 e.g. SET_BIT(PORTA, 3);   -> sets bit 3 in PORTA

 NOTE: REG and BIT must be side-effect-free expressions
 (do NOT pass function calls or i++ as arguments),
 since REG may be evaluated more than once internally.
                                                                     */
/************************************************************************/

/* bit mask */
#define BIT_MASK					1U

/* set */
#define SET_BIT(REG,BIT)			((REG) |= (BIT_MASK << (BIT)))

/* clear */
#define CLEAR_BIT(REG,BIT)			((REG) &= ~(BIT_MASK << (BIT)))

/* toggle */
#define TOGGLE_BIT(REG,BIT)			((REG) ^= (BIT_MASK << (BIT)))

/* get */
#define GET_BIT(REG,BIT)			(((REG) >> (BIT)) & BIT_MASK)

#endif /* BIT_MATH_H_ */
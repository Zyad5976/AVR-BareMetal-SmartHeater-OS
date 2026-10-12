/*
 * STD_TYPES.h
 *
 * Created: 10/5/2026 7:47:26 AM
 *  Author: Eltawel
 */ 


#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/************************************************************************/
/*

 *this file for define any data type that used in this project (Electric Heater)
 you can use this file at any project as a data type for your project
 

 u --> unsigned
 s --> signed
 f --> float
 
 so we write the data type by number of it's bit
 
 char		--> 1 byte == 8 bit
 short		--> 2 byte == 16 bit
 int		--> 2 byte == 16 bit
 long		--> 4 byte == 32 bit 
 long long	--> 8 byte == 64 bit 
  
...
..
.. 
and so on 

 example on it:
 
 if we want to write -> unsigned char var;
 we can write        -> u8 var;
 
 another example:
 
 if we want to write -> unsigned int var;
 we can write        -> u32 var;

 and we do this in signed

 lets start...
                                                                     */
/************************************************************************/


/* unsigned */
typedef unsigned char			u8;
typedef unsigned int			u16;
typedef unsigned long			u32;
typedef unsigned long long		u64;


/* signed */
typedef signed char				s8;
typedef signed int				s16;
typedef signed long				s32;
typedef unsigned long long		s64;


/* float */
typedef float					f32;
typedef double					f64;


/* null -> text buffer */
#define nul						'\0'


/* NULL PTR */
#define null					((void *)0)

/* RETURN TYPE */
typedef u8						STD_RET;

/* err_state */
#define E_OK					0
#define E_NOK					1

#endif /* STD_TYPES_H_ */
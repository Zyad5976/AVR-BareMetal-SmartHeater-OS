/*
 * GI_PROG.c
 *
 * Created: 10/9/2026 6:22:40 AM
 *  Author: Eltawel
 *
  
 this file contains the implementation of the Global Interrupt (GI) driver.
 It utilizes inline assembly instructions (SEI / CLI) for optimal execution 
 speed (1 instruction cycle), which is critical for entering and exiting 
 atomic/critical sections in embedded systems.
                                                                     
************************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "GI_INTERFACE.h"

STD_RET GI_Enable(void)
{
	STD_RET ret = E_OK;
	
	__asm__ __volatile__("sei" ::);
	
	return ret;
}

STD_RET GI_Disable(void)
{
	STD_RET ret = E_OK;
	
	__asm__ __volatile__("cli"::);
	
	return ret;
}
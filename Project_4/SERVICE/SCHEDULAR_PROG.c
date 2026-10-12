/*
 * SCHEDULAR.c
 *
 * Created: 10/5/2026 9:09:08 AM
 *  Author: Eltawel
 */ 
/************************************************************************/
/* 
 this file contains the implementation of the OS Scheduler Service.
 It orchestrates periodic execution blocks via precise countdown tracking, 
 running directly under the hardware microsecond Timer1 interrupt engine.
                                                                     */
/************************************************************************/

#include "../LIB/STD_TYPES.h"
#include "../MCAL/TIM1/TIM1_INTERFACE.h"
#include "SCHEDULAR_CFG.h"
#include "SCHEDULAR_INTERFACE.h"

/*-------------------------------------------*/


static SysTask_t System_Tasks_Matrix[SYSTEM_TASKS_COUNT];

/*-------------------------------------------*/

STD_RET SCHEDULER_CreateTask(TASKS_NUM_t copy_eTaskID, void (*copy_pvFunc)(void), u16 copy_u16Periodicity)
{
	STD_RET ret = E_OK;
	
	if((copy_eTaskID >= SYSTEM_TASKS_COUNT) || (copy_pvFunc == null))
	{
		ret = E_NOK;
	}
	else
	{

		System_Tasks_Matrix[copy_eTaskID].FuncPointer  = copy_pvFunc;
		System_Tasks_Matrix[copy_eTaskID].Periodicity  = copy_u16Periodicity;
		System_Tasks_Matrix[copy_eTaskID].TickCounter  = copy_u16Periodicity;
	}
	return ret;
}

STD_RET SCHEDULER_Start(void)
{

	TIM1_SetCallBack(SCHEDULER_TickHandler);
	

	return TIM1_Init();
}

void SCHEDULER_TickHandler(void)
{
	u8 counter = 0;
	

	for(counter = 0; counter < SYSTEM_TASKS_COUNT; counter++)
	{
		if(System_Tasks_Matrix[counter].FuncPointer != null)
		{

			System_Tasks_Matrix[counter].TickCounter--;
			

			if(System_Tasks_Matrix[counter].TickCounter == 0)
			{

				System_Tasks_Matrix[counter].FuncPointer();
				

				System_Tasks_Matrix[counter].TickCounter = System_Tasks_Matrix[counter].Periodicity;
			}
		}
	}
}
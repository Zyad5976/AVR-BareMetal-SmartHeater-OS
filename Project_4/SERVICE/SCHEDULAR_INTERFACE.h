/*
 * SCHEDULAR.h
 *
 * Created: 10/5/2026 9:08:55 AM
 *  Author: Eltawel
 */ 


#ifndef SCHEDULAR_H_
#define SCHEDULAR_H_

/************************************************************************/
/* 
 this file is the interface (prototypes) for the OS Scheduler Service.

 it provides framework management APIs:
 - SCHEDULER_CreateTask: registers a function pointer with static timings.
 - SCHEDULER_Start: initialises hardware ticks and enters execution paths.
 - SCHEDULER_TickHandler: the core engine driven by the Timer Interrupt.

 usage: initialize hardware components, create tasks in the main structure, 
 set the hardware callback, then launch the scheduler engine.
                                                                     */
/************************************************************************/

#include "../LIB/STD_TYPES.h"
#include "SCHEDULAR_CFG.h"

/*-------------------------------------------*/

/* Task Control Block (TCB) structure definition */
typedef struct
{
	void (*FuncPointer)(void);  /* Pointer to the function layout */
	u16 Periodicity;            /* How often the task should run in ms */
	u16 TickCounter;            /* Internal runtime down-counter */
}SysTask_t;

/*-------------------------------------------*/

/**
 * @brief  Register a system task into the scheduler configuration matrix.
 * @param  copy_eTaskID: The unique task identifier index from TASKS_NUM_t.
 * @param  copy_pvFunc: Pointer to the executable void task function.
 * @param  copy_u16Periodicity: Executing time interval in milliseconds.
 * @return STD_RET: E_OK on success, E_NOK on invalid inputs or bounds.
 */
STD_RET SCHEDULER_CreateTask(TASKS_NUM_t copy_eTaskID, void (*copy_pvFunc)(void), u16 copy_u16Periodicity);

/**
 * @brief  Start the scheduler clock engine by activating Timer1 time-base.
 * @param  void
 * @return STD_RET: E_OK on successful engine ignition.
 */
STD_RET SCHEDULER_Start(void);

/**
 * @brief  The core execution engine called inside the Timer ISR to handle scheduling logic.
 * @param  void
 * @return none
 */
void SCHEDULER_TickHandler(void);

#endif /* SCHEDULAR_H_ */
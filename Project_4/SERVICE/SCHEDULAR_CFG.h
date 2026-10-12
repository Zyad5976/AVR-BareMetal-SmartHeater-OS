/*
 * SCHEDULER_CFG.h
 *
 * Created: 10/12/2026 2:41:52 AM
 *  Author: Eltawel
 */ 


#ifndef SCHEDULER_CFG_H_
#define SCHEDULER_CFG_H_

/************************************************************************/
/* 
 this file contains the configuration for the OS Scheduler Service.

 it defines:
 - TASKS_NUM_t: enumeration tracking total system periodic tasks.
 - selected configuration limits for the scheduler execution engine.
                                                                     */
/************************************************************************/

/* Total number of periodic tasks managed by the OS Scheduler */
typedef enum
{
	TASK_SSD_DISPLAY = 0,   /* Task to refresh the 7-Segment displays */
	TASK_BUTTON_SCAN,       /* Task to scan inputs and handle debouncing */
	TASK_TEMP_CONTROL,      /* Task to read LM35 and control heating/cooling */
	TASK_LED_BLINK,         /* Task to toggle the system status LED */
	SYSTEM_TASKS_COUNT      /* Total count identifier */
}TASKS_NUM_t;

#endif /* SCHEDULER_CFG_H_ */
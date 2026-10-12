/*
 * main.h
 *
 * Created: 10/3/2026 7:05:28 PM
 *  Author: Eltawel
 */ 


#ifndef MAIN_H_
#define MAIN_H_

/* LIB */
#include "../LIB/PLATFORM.h"
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../LIB/VECTOR_TABLE_INTERRUPT.h"

/* MCAL */
#include "../MCAL/DIO/DIO_INTERFACE.h"
#include "../MCAL/TIM0/TIM0_INTERFACE.h"
#include "../MCAL/GI/GI_INTERFACE.h"
#include "../MCAL/ADC/ADC_INTERFACE.h"
#include "../MCAL/TWI/TWI_INTERFACE.h"
#include "../MCAL/TIM1/TIM1_INTERFACE.h"


/* HAL */
#include "../HAL/LED/LED_INTERFACE.h"
#include "../HAL/SSD/SSD_INTERFACE.h"
#include "../HAL/SSD/SSD_CFG.h"
#include "../HAL/BTN/BTN_INTERFACE.h"
#include "../HAL/BTN/BTN_CFG.h"
#include "../HAL/RELAY/RELAY_INTERFACE.h"
#include "../HAL/RELAY/RELAY_CFG.h"
#include "../HAL/FAN/FAN_INTERFACE.h"
#include "../HAL/FAN/FAN_CFG.h"
#include "../HAL/PELTIER/PELTIER_INTERFACE.h"
#include "../HAL/PELTIER/PELTIER_CFG.h"
#include "../HAL/OVEN/OVEN_INTERFACE.h"
#include "../HAL/OVEN/OVEN_CFG.h"
#include "../HAL/LM35/LM35_INTERFACE.h"

/* Service */
#include "../SERVICE/SCHEDULAR_INTERFACE.h"
#include "../SERVICE/SCHEDULAR_CFG.h"


#endif /* MAIN_H_ */
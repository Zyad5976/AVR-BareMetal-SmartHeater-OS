/*
 * Project_4.c
 *
 * Created: 10/3/2026 7:03:11 PM
 * Author : Eltawel
 */ 

#include "main.h"

/*----------------------------------------------------------------------*/
/* 1. Hardware Objects Initialization Configurations                   */
/*----------------------------------------------------------------------*/
const SSD_CFG_t Heater_SSD = {.data_port = DIO_PORTB};

const BTN_CFG_t Btn_Power = {.port = DIO_PORTD, .pin = DIO_PIN0, .connection = BTN_ACTIVE_LOW};
const BTN_CFG_t Btn_Up    = {.port = DIO_PORTD, .pin = DIO_PIN1, .connection = BTN_ACTIVE_LOW};
const BTN_CFG_t Btn_Down  = {.port = DIO_PORTD, .pin = DIO_PIN2, .connection = BTN_ACTIVE_LOW};

OVEN_CFG_t    Heater_Oven    = {.oven_port = DIO_PORTC, .oven_pin = DIO_PIN3, .oven_state = OVEN_OFF};
PELTIER_CFG_t Cooler_Peltier = {.peltier_port = DIO_PORTC, .peltier_pin = DIO_PIN4, .peltier_state = PELTIER_OFF};
DIO_CFG_t     Status_LED     = {.port = DIO_PORTC, .pin = DIO_PIN5, .dir = DIO_OUTPUT, .val = DIO_LOW};

/*----------------------------------------------------------------------*/
/* 2. Global Shared Application Variables                              */
/*----------------------------------------------------------------------*/
static volatile u8 g_u8CurrentTemperature  = 0;
static volatile u8 g_u8SetTemperature      = 60;
static volatile u8 g_u8SystemPowerState    = 0;  /* Starts OFF by default */

/* Setting Mode State Machine Variables */
static volatile u8  g_u8SettingModeFlag     = 0;
static volatile u16 g_u16SettingTimeout     = 0;
static volatile u8  g_u8DisplayBlinkToggle  = 0;

/*----------------------------------------------------------------------*/
/* 3. Periodic OS Tasks Prototypes                                      */
/*----------------------------------------------------------------------*/
void App_Task_SSD_Display(void);
void App_Task_Temp_Control(void);
void App_Task_LED_Blink(void);

/*----------------------------------------------------------------------*/
/* 4. Main Program Application Entry                                    */
/*----------------------------------------------------------------------*/
int main(void)
{
	BTN_STATE_t power_btn_state = BTN_RELEASED;
	BTN_STATE_t up_btn_state    = BTN_RELEASED;
	BTN_STATE_t down_btn_state  = BTN_RELEASED;
	
	GI_Disable();
	
	ADC_Init();
	TIM0_Init(); /* Used exclusively for debouncing delays */
	SSD_Init(&Heater_SSD);
	OVEN_Init(&Heater_Oven);
	PELTIER_Init(&Cooler_Peltier);
	
	BTN_Init(&Btn_Power);
	BTN_Init(&Btn_Up);
	BTN_Init(&Btn_Down);
	
	DIO_SetPinDir(&Status_LED);
	
	OVEN_SetOFF(&Heater_Oven);
	PELTIER_SetOFF(&Cooler_Peltier);
	Status_LED.val = DIO_LOW;
	DIO_SetPinVal(&Status_LED);
	
	/* Creation of OS background Tasks (Button Scan is removed from here) */
	SCHEDULER_CreateTask(TASK_SSD_DISPLAY, App_Task_SSD_Display, 10);
	SCHEDULER_CreateTask(TASK_TEMP_CONTROL, App_Task_Temp_Control, 100);
	SCHEDULER_CreateTask(TASK_LED_BLINK, App_Task_LED_Blink, 200);      /* Set to 200ms for sharp, responsive flashing */
	
	SCHEDULER_Start();
	GI_Enable();
	
	while (1)
	{
		/* Handle Button Scanning using your precise sequential 'while' logic */
		BTN_Status(&Btn_Power, &power_btn_state);
		BTN_Status(&Btn_Up, &up_btn_state);
		BTN_Status(&Btn_Down, &down_btn_state);
		
		/* 1. Power Button Execution */
		if(power_btn_state == BTN_PRESSED)
		{
			TIM0_Delayms(30); /* Hardware debounce guard */
			BTN_Status(&Btn_Power, &power_btn_state);
			if(power_btn_state == BTN_PRESSED)
			{
				g_u8SystemPowerState ^= 1;
				g_u8SettingModeFlag = 0;
				
				if(g_u8SystemPowerState == 0)
				{
					OVEN_SetOFF(&Heater_Oven);
					PELTIER_SetOFF(&Cooler_Peltier);
					Status_LED.val = DIO_LOW;
					DIO_SetPinVal(&Status_LED);
				}
				
				/* Trap execution lock until user releases the key */
				while(power_btn_state == BTN_PRESSED)
				{
					BTN_Status(&Btn_Power, &power_btn_state);
				}
			}
		}
		
		/* 2. Temperature Tuning Adjustments */
		if(g_u8SystemPowerState == 1)
		{
			/* UP Button Input Processing */
			if(up_btn_state == BTN_PRESSED)
			{
				TIM0_Delayms(30);
				BTN_Status(&Btn_Up, &up_btn_state);
				if(up_btn_state == BTN_PRESSED)
				{
					g_u8SettingModeFlag = 1;
					g_u16SettingTimeout = 5000;
					if(g_u8SetTemperature < 75)
					{
						g_u8SetTemperature += 5;
					}
					
					while(up_btn_state == BTN_PRESSED)
					{
						BTN_Status(&Btn_Up, &up_btn_state);
					}
				}
			}
			
			/* DOWN Button Input Processing */
			if(down_btn_state == BTN_PRESSED)
			{
				TIM0_Delayms(30);
				BTN_Status(&Btn_Down, &down_btn_state);
				if(down_btn_state == BTN_PRESSED)
				{
					g_u8SettingModeFlag = 1;
					g_u16SettingTimeout = 5000;
					if(g_u8SetTemperature > 35)
					{
						g_u8SetTemperature -= 5;
					}
					
					while(down_btn_state == BTN_PRESSED)
					{
						BTN_Status(&Btn_Down, &down_btn_state);
					}
				}
			}
			
			/* 3. Handle Setting Mode Timeout natively inside background loop */
			if(g_u8SettingModeFlag == 1)
			{
				TIM0_Delayms(1); /* Smooth decrement step */
				if(g_u16SettingTimeout > 0)
				{
					g_u16SettingTimeout--;
				}
				else
				{
					g_u8SettingModeFlag = 0; /* Return to Normal Mode */
				}
			}
		}
	}
}

/*----------------------------------------------------------------------*/
/* 5. OS Scheduler Periodic Tasks Implementation                       */
/*----------------------------------------------------------------------*/

void App_Task_SSD_Display(void)
{
	if(g_u8SystemPowerState == 1)
	{
		if(g_u8SettingModeFlag == 1)
		{
			if(g_u8DisplayBlinkToggle == 1)
			{
				SSD_WriteTwoDigits(&Heater_SSD, g_u8SetTemperature);
			}
			else
			{
				/* Force complete display blanking during the OFF phase of the blink */
				/* Writing an invalid out-of-range BCD number like 0xFF forces the 7SEG-BCD to turn off completely */
				SSD_WriteTwoDigits(&Heater_SSD, 0xFF);
			}
		}
		else
		{
			SSD_WriteTwoDigits(&Heater_SSD, g_u8CurrentTemperature);
		}
	}
	else
	{
		SSD_WriteTwoDigits(&Heater_SSD, 0xFF); /* Keep displays completely dark when system is OFF */
	}
}

void App_Task_Temp_Control(void)
{
	if((g_u8SystemPowerState == 1) && (g_u8SettingModeFlag == 0))
	{
		LM35_GetTemp(0, (u8 *)&g_u8CurrentTemperature);
		
		if(g_u8CurrentTemperature < (g_u8SetTemperature - 5))
		{
			OVEN_SetON(&Heater_Oven);
			PELTIER_SetOFF(&Cooler_Peltier);
		}
		else if(g_u8CurrentTemperature > (g_u8SetTemperature + 5))
		{
			OVEN_SetOFF(&Heater_Oven);
			PELTIER_SetON(&Cooler_Peltier);
		}
	}
}

void App_Task_LED_Blink(void)
{
	if(g_u8SystemPowerState == 1)
	{
		/* Standard high-frequency toggle for crisp display flashing (200ms) */
		g_u8DisplayBlinkToggle ^= 1;
		
		if(g_u8SettingModeFlag == 0)
		{
			Status_LED.val ^= 1;
			DIO_SetPinVal(&Status_LED);
		}
	}
}
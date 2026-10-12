/*
 * ADC_CFG.h
 *
 * Created: 10/11/2026 3:36:26 AM
 *  Author: Eltawel
 */ 


#ifndef ADC_CFG_H_
#define ADC_CFG_H_

/************************************************************************/
/* 
 
 this file is the configuration of the MCAL ADC driver.

 it defines:
 - ADC_AREF_t: voltage reference configuration options mapping REFS1:REFS0.
 - ADC_PRESCALER_t: division factor values between the XTAL frequency 
   and the internal ADC clock (ADC clock must stay between 50kHz and 200kHz).
 - selected macros used by the core driver initialization process.

 WARNING: changing the prescaler to a low value at high system clocks 
 will degrade the resolution of analog sampling.
                                                                     */
/************************************************************************/

/* Voltage Reference Selection options */
typedef enum
{
	ADC_INTERNAL_VREF_ON = 0,
	ADC_AVCC_WITH_EXT_CAP,
	ADC_RESERVED,
	ADC_INTERNAL_256V_WITH_EXT_CAP
}ADC_AREF_t;

/* Division Factor options (Correction: Indexed from 0 to sync perfectly with datasheet) */
typedef enum
{
	ADC_CLK_DIV_2 = 0,             /* Division factor 2 */
	ADC_CLK_DIV_2_ALT,             /* Division factor 2 alternative */
	ADC_CLK_DIV_4,				   /* Division factor 4 */
	ADC_CLK_DIV_8,				   /* Division factor 8 */
	ADC_CLK_DIV_16,				   /* Division factor 16 */
	ADC_CLK_DIV_32,				   /* Division factor 32 */
	ADC_CLK_DIV_64,				   /* Division factor 64 */
	ADC_CLK_DIV_128				   /* Division factor 128 */
}ADC_PRESCALER_t;

/* Selected operational hardware configurations */
#define ADC_MODE		ADC_AVCC_WITH_EXT_CAP
#define ADC_CLK			ADC_CLK_64

#endif /* ADC_CFG_H_ */
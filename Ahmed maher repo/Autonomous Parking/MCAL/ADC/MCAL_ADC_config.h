

/*preprocessor file guard */
#ifndef MCAL_ADC_CONFIG_H_
#define MCAL_ADC_CONFIG_H_

/*Selectable Referance Voltage*/
#define REF_SELECT 		AREF_AVCC

/*Configuration of the value register*/
#define VALUE_REG_CONFIG	STORE_10BIT

/*Configuration of the Prescaler */
#define ADC_PRESCALER	 	DIVISON_BY_128

/*
 * Define the time out*/

#define ADC_LIMIT_WAITING 			10000UL

#define Active_ADC_PORT    			0b00000001

#endif

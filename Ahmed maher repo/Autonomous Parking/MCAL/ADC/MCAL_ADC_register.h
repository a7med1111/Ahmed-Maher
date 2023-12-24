
/*preprocessor file guard */
#ifndef MCAL_ADC_REGISTER_H_
#define MCAL_ADC_REGISTER_H_
/*
 * ADMUC -> "Analog to Digital Conversion MUlipliexier Control "*/
#define	ADMUX            		*((volatile u8 *) 0x27)
#define ADMUX_REFS1				7           // Reference Selection Bit 1
#define ADMUX_REFS0				6			// Reference Selection Bit 1
#define ADMUX_ADLAR				5			//Left adjust result
/*
 * ADCSRA -> "Analog to Digital Conversion Control Status Register A"*/
#define	ADCSRA                	*((volatile u8 *) 0x26)
#define ADCSRA_ADEN				7			//Enable
#define ADCSRA_ADSC				6           //Start conversion
#define ADCSRA_ADATE			5           //Auto trigger enable
#define ADCSRA_ADIF				4           //Interrupt flag
#define ADCSRA_ADIE				3           //Interrupt enable

/*
 * ADCH -> "Analog to Digital Conversion Upper"*/
#define ADCH                	*((volatile u8 *) 0x25)    //Data high register

#define ADCL					*((volatile u8 *) 0x24)	   //Data low register

#define ADC						*((volatile u16 *)0x24)


#endif



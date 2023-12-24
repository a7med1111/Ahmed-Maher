
#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_

/******************************************************************************/
/***************************** TIMER 0 REGISTERS*******************************/
/******************************************************************************/
//Timer0 control register
#define TCCR0 					*((volatile u8*)0x53)
#define TCCR0_FOC0				7
#define TCCR0_WGM00				6		/*****Waveform generation******/
#define TCCR0_WGM01				3		/***********MODE bits**********/

#define TCCR0_COM01				5		/*****Copmare&match Output*****/
#define TCCR0_COM00				4		/***********MODE bits**********/

#define TCCR0_CS02				2		/******************************/
#define TCCR0_CS01				1		/*******CLOCK SELECT bits******/
#define TCCR0_CS00				0		/******************************/

//Timer0 register
#define TCNT0		*((volatile u8*)0x52)
//Output Compare0 register(CM MODE)
#define OCR0  		*((volatile u8*)0x5C)

/******************************************************************************/
/***************************** TIMER 1 REGISTERS*******************************/
/******************************************************************************/
//Timer1 control register
#define TCCR1A		*((volatile u8*)0x4F)

#define WGM11		1		/*****Waveform generation*******/
#define WGM10		0       /***********MODE bits***********/

#define COM1A1		7		/*******************************/
#define COM1A0		6       /*****Copmare&match Output******/
#define COM1B1		5		/***********MODE bits***********/
#define COM1B0		4		/*******************************/
//Timer1 control register
#define TCCR1B		*((volatile u8*)0x4E)

#define WGM13		4		/*****Waveform Generation*******/
#define WGM12		3       /***********MODE bits***********/

#define ICNC1		7		/**Input Capture Noise Cancler**/
#define ICES1		6		/***Input Capture Edge Select***/

#define CS12		2		/*******************************/
#define CS11		1       /*******CLOCK SELECT bits*******/
#define CS10		0       /*******************************/

//Timer1 register					
#define TCNT1			*((volatile u16*)0x4C)

//Output Compare1A register
#define OCR1A			*((volatile u16*)0x4A)

//Output Compare1B register
#define OCR1B			*((volatile u16*)0x48)

//Input Capture1 register
#define ICR1			*((volatile u16*)0x46)

/******************************************************************************/
/***************************** TIMER 2 REGISTERS*******************************/
/******************************************************************************/
//Timer2 control register
#define TCCR2			*((volatile u8*)0x45)
#define TCCR2_WGM20		6		/*****Waveform Generation*******/
#define TCCR2_WGM21		3       /***********MODE bits***********/

#define TCCR2_COM21		5		/*****Copmare&match Output*****/
#define TCCR2_COM20		4       /***********MODE bits**********/

#define TCCR2_CS22		2		/******************************/
#define TCCR2_CS21		1       /*******CLOCK SELECT bits******/
#define TCCR2_CS20		0       /******************************/

//Timer2 register
#define TCNT2			*((volatile u8*)0x44)
//Output Compare2 register(CM MODE)
#define OCR2			*((volatile u8*)0x43)


/******************************************************************************/
/********************* TIMER INTERRUPT ENABLE REGISTERS************************/
/******************************************************************************/
//Timer Interrupt Mask register
#define TIMSK 			*((volatile u8*)0x59)
#define TIMSK_OCIE2		7		/****  Output2 Compare Match Interrupt Enable     *****/
#define TIMSK_TOIE2		6		/****  Timer2 Overflow Interrupt Enable           *****/
#define TIMSK_TICIE1	5		/****  Timer1 Input Capture Interrupt Enable      *****/
#define TIMSK_OCIE1A	4		/****  Output1 Compare A Match Interrupt Enable   *****/
#define TIMSK_OCIE1B	3		/****  Output1 Compare B Match Interrupt Enable   *****/
#define TIMSK_TOIE1		2		/****  Timer1 Overflow Interrupt Enable           *****/
#define TIMSK_OCIE0		1		/****  Output0 Compare Match Interrupt Enable     *****/
#define TIMSK_TOIE0		0		/****  Timer0 Overflow Interrupt Enable           *****/

//Timer Interrupt Flag register
#define TIFR  			*((volatile u8*)0x58)
#define TIFR_OCF2		7
#define TIFR_TOV2		6
#define TIFR_ICF1		5
#define TIFR_OCF1A		4
#define TIFR_OCF1B		3
#define TIFR_TOV1		2
#define TIFR_OCF0		1
#define TIFR_TOV0		0


/******************************************************************************/
/*****************************  WATCHDOG REGISTERS  ***************************/
/******************************************************************************/

#define WDTCR 			*((volatile u8*)0x41)
#define WDTCR_WDTOE		4
#define WDTCR_WDE		3




#endif





#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_


/*******************************Waveform Generation Mode Selection****************************/

#define NORMAL						1
#define PWM_PHASE_CORRECT			2
#define CTC							3
#define FAST_PWM					4


/*******************************CTC Output MODE ****************************/
/*options:*/
#define NO_OPERATION				1
#define TOGGLE						2
#define CLR							3
#define SET							4

/****************************TOP Selection*************************/
/*options:*/
#define OCR							1
#define ICR							2
#define BIT8 						3
#define BIT9 						4
#define BIT10						5

/*******************************PWM output MODE ****************************/
/*options:*/
#define NO_OPERATION				1
#define TOGGLE_OC1A					2
#define NON_INVERTED				3
#define INVERTED					4


/*******************************CLock Select MODE Selection****************************/
#define CLK_MASK0					TCCR0  & 0b1111000
#define CLK_MASK1					TCCR1B & 0b1111000
#define CLK_MASK2					TCCR2  & 0b1111000

#define OFF            				0
#define CLK            				1
#define CLK8           				2
#define CLK64          				3
#define CLK256         				4
#define CLK1024        				5
#define COUNTER_FALLING				6
#define COUNTER_RISING 				7

/*******************************WatchDog MASK****************************/
#define WDTCR_MASK					WDTCR & 0b1111000


#endif

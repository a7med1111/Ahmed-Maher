


#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_


/******************************************************************************************/
/*********************************** TIMER 0 CONFIGS***************************************/
/******************************************************************************************/


/*************************Waveform Generation Mode Selection************************/
/*options:
 * 			1-NORMAL
 * 			2-PWM_PHASE_CORRECT
 * 			3-CTC
 * 			4-FAST_PWM
 * 						*/
#define TIMER0_WAVE_GENERATION_SENSE		FAST_PWM


/****************************Compare Output  MODE Selection*************************/
/*options:
 * 			1-NO_OPERATION
 * 			2-TOGGLE
 * 			3-CLR
 * 			4-SET
 * 						*/
#define TIMER0_CTC_SENSE		NO_OPERATION

/*******************************FAST PWM  MODE Selection****************************/
/*options:
 * 			1-NO_OPERATION
 * 			2-NON_INVERTED
 * 			3-INVERTED
 * 						*/
#define TIMER0_PWM_SENSE		NON_INVERTED


/************************************ Clock Select **********************************/
/*options:
 * 			1-OFF
 * 			2-CLK
 * 			3-CLK8
 * 			4-CLK64
 * 			5-CLK256
 * 			6-CLK1024
 * 			7-COUNTER_FALLING
 * 			8-COUNTER_RISING
 * 						*/

#define TIMER0_CLOCK_SELECT_SENSE				CLK8



/******************************************************************************************/
/*********************************** TIMER 1 CONFIGS***************************************/
/******************************************************************************************/


/*************************Waveform Generation Mode Selection************************/
/*options:
 * 			1-NORMAL
 * 			2-PWM_PHASE_CORRECT
 * 			3-CTC
 * 			4-FAST_PWM
 * 						*/
#define TIMER1_WAVE_GENERATION_SENSE		NORMAL

/****************************TOP Selection*************************/
/*options:
 * for CTC mode use *OCR and *ICR options only
 * 			1-OCR
 * 			2-ICR
 * 			3-BIT8
 * 			4-BIT9
 * 			5-BIT10
 * 						*/
#define TIMER1_TOP_SENSE				ICR
/****************************CTC output MODE *************************/
/*options:
 * 			1-NO_OPERATION
 * 			2-TOGGLE
 * 			3-CLR
 * 			4-SET
 * 						*/
#define TIMER1_CTC_SENSE					NO_OPERATION

/*******************************PWM  MODE Selection****************************/
/*options:
 * 			1-NO_OPERATION
 * 			2-TOGGLE_OC1A
 * 			3-NON_INVERTED
 * 			4-INVERTED
 * 						*/
#define TIMER1_PWM_SENSE				NON_INVERTED


/************************************ Clock Select **********************************/
/*options:
 * 			1-OFF
 * 			2-CLK
 * 			3-CLK8
 * 			4-CLK64
 * 			5-CLK256
 * 			6-CLK1024
 * 			7-COUNTER_FALLING
 * 			8-COUNTER_RISING
 * 						*/

#define TIMER1_CLOCK_SELECT_SENSE				CLK8

/************************************ ICU Enable/Disable **********************************/
/*options:
 * 			1-ENABLE
 * 			2-DISABLE
 * 						*/
#define TIMER1_ICU_SENSE						ENABLE

/************************************ ICU Edge Mode **********************************/
/*options:
 * 			1-FALLING_EDGE
 * 			2-RISING_EDGE
 * 						*/
#define TIMER1_ICU_EDGE_SENSE					FALLING_EDGE


/******************************************************************************************/
/*********************************** TIMER 2 CONFIGS***************************************/
/******************************************************************************************/


/*************************Waveform Generation Mode Selection************************/
/*options:
 * 			1-NORMAL
 * 			2-PWM_PHASE_CORRECT
 * 			3-CTC
 * 			4-FAST_PWM
 * 						*/
#define TIMER2_WAVE_GENERATION_SENSE		FAST_PWM


/****************************Compare Output  MODE Selection*************************/
/*options:
 * 			1-NO_OPERATION
 * 			2-TOGGLE
 * 			3-CLR
 * 			4-SET
 * 						*/
#define TIMER2_CTC_SENSE		NO_OPERATION

/******************************* PWM  MODE Selection****************************/
/*options:
 * 			1-NO_OPERATION
 * 			2-NON_INVERTED
 * 			3-INVERTED
 * 						*/
#define TIMER2_PWM_SENSE		NON_INVERTED


/************************************ Clock Select **********************************/
/*options:
 * 			1-OFF
 * 			2-CLK
 * 			3-CLK8
 * 			4-CLK64
 * 			5-CLK256
 * 			6-CLK1024
 * 			7-COUNTER_FALLING
 * 			8-COUNTER_RISING
 * 						*/

#define TIMER2_CLOCK_SELECT_SENSE				CLK64
#endif

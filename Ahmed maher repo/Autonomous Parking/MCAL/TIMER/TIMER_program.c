

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER_register.h"
#include "TIMER_interface.h"
#include "TIMER_private.h"
#include "TIMER_config.h"

/************************************************************************************************************************************************************/
/*********************************************************			GLOBAL VARIABLES			  ***********************************************************/
/************************************************************************************************************************************************************/
void (*TIMER_pvTimer0OVFFunc)(void) = NULL;
void (*TIMER_pvTimer0CompFunc)(void) = NULL;

void (*TIMER_pvTimer1OVFFunc)(void) = NULL;
void (*TIMER_pvTimer1CompAFunc)(void) = NULL;
void (*TIMER_pvTimer1CompBFunc)(void) = NULL;
void (*TIMER_pvIcuFunc)(void) = NULL;

void (*TIMER_pvTimer2OVFFunc)(void) = NULL;
void (*TIMER_pvTimer2CompFunc)(void) = NULL;
void (*TIMER_pvTimer2Func)(void) = NULL;


/************************************************************************************************************************************************************/
/*********************************************************			TIMER 0 Functions			  ***********************************************************/
/************************************************************************************************************************************************************/

void TIMER0_voidInit(void)
{
	/**********************************************************************/
	/*****************Set Timer0 Waveform Generation MODE******************/
	/**********************************************************************/

	/***************Normal Overflow Mode************/
#if TIMER0_WAVE_GENERATION_SENSE == NORMAL
	CLR_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);
	SET_BIT(TIMSK,TIMSK_TOIE0);
	/**************PWM Phase Correct Mode************/
#elif TIMER0_WAVE_GENERATION_SENSE == PWM_PHASE_CORRECT
	CLR_BIT(TCCR0,TCCR0_WGM01);
	SET_BIT(TCCR0,TCCR0_WGM00);
	/********************************CTC Mode**********************/
#elif TIMER0_WAVE_GENERATION_SENSE == CTC
	CLR_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);
	SET_BIT(TIMSK,TIMSK_OCIE0);
	/*****************Set Compare Output MODE******************/
#if TIMER0_CTC_SENSE == NO_OPERATION
	CLR_BIT(TCCR0,TCCR0_COM01);
	CLR_BIT(TCCR0,TCCR0_COM00);
#elif TIMER0_CTC_SENSE == TOGGLE
	CLR_BIT(TCCR0,TCCR0_COM01);
	SET_BIT(TCCR0,TCCR0_COM00);
#elif TIMER0_CTC_SENSE == CLR
	SET_BIT(TCCR0,TCCR0_COM01);
	CLR_BIT(TCCR0,TCCR0_COM00);
#elif TIMER0_CTC_SENSE == SET
	SET_BIT(TCCR0,TCCR0_COM00);
	SET_BIT(TCCR0,TCCR0_COM01);
#else
#error "Wrong TIMER0_CTC_SENSE configuration option"
#endif
	/***************************Fast PWM Mode**********************/
#elif TIMER0_WAVE_GENERATION_SENSE == FAST_PWM
	SET_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);
#else
#error "Wrong WAVE_GENERATION_SENSE configuration option"
#endif
	/*****************Set Timer0 PWM output  MODE******************/
#if ( (TIMER0_WAVE_GENERATION_SENSE == PWM_PHASE_CORRECT) || (TIMER0_WAVE_GENERATION_SENSE == FAST_PWM) )
#if TIMER0_PWM_SENSE == NO_OPERATION
	CLR_BIT(TCCR0,TCCR0_COM01);
	CLR_BIT(TCCR0,TCCR0_COM00);
#elif TIMER0_PWM_SENSE == NON_INVERTED
	SET_BIT(TCCR0,TCCR0_COM01);
	CLR_BIT(TCCR0,TCCR0_COM00);
#elif TIMER0_PWM_SENSE == INVERTED
	SET_BIT(TCCR0,TCCR0_COM00);
	SET_BIT(TCCR0,TCCR0_COM01);
#else
#error "Wrong TIMER0_PWM_SENSE configuration option"
#endif
#else
#endif

	/**********************************************************************/
	/************************Set Timer0 Clock Select***********************/
	/**********************************************************************/
	TCCR0 = (CLK_MASK0) | (TIMER0_CLOCK_SELECT_SENSE);

}

/**********************************************************************/
/***********************POST BUILD CONFIGURATION***********************/
/**********************************************************************/
void TIMER0_voidSetCompMatchValue(u8 Copy_u8Value)
{
	OCR0 = Copy_u8Value;
}

void TIMER0_voidSetTimerValue(u8 Copy_u8Value)
{
	TCNT0 = Copy_u8Value;
}

/**********************************************************************/
/*****************Timer0 OverFlow interrupt Handling*******************/
/**********************************************************************/

u8 TIMER0_u8OVFSetCallBack(void (*Copy_pvTimer0OVFFunc)(void))
{
	u8 Local_u8ErrorState = OK;
	if(Copy_pvTimer0OVFFunc != NULL)
	{
		TIMER_pvTimer0OVFFunc = Copy_pvTimer0OVFFunc;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}
	return Local_u8ErrorState;
}

void __vector_11(void) __attribute__((signal));

void __vector_11(void)
{
	if(TIMER_pvTimer0OVFFunc != NULL)
	{
		TIMER_pvTimer0OVFFunc();
	}
	else
	{
		/*Do Nothing*/
	}
}

/**********************************************************************/
/*****************Timer0 OverFlow interrupt Handling*******************/
/**********************************************************************/

u8 TIMER0_u8CompSetCallBack(void (*Copy_pvTimer0CompFunc)(void))
{
	u8 Local_u8ErrorState = OK;
	if(Copy_pvTimer0CompFunc != NULL)
	{
		TIMER_pvTimer0CompFunc = Copy_pvTimer0CompFunc;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}
	return Local_u8ErrorState;
}

void __vector_10(void) __attribute__((signal));

void __vector_10(void)
{
	if(TIMER_pvTimer0CompFunc != NULL)
	{
		TIMER_pvTimer0CompFunc();
	}
	else
	{
		/*Do Nothing*/
	}
}

/************************************************************************************************************************************************************/
/*********************************************************			TIMER 1 Functions			  ***********************************************************/
/************************************************************************************************************************************************************/

void TIMER1_voidInit(void)
{
	/****************************************  Wave Generation Modes selection  ************************************/

	/****************************************************************************************************/
	/****************************************  Normal Overflow Mode  ************************************/
	/****************************************************************************************************/
#if	TIMER1_WAVE_GENERATION_SENSE == NORMAL
	CLR_BIT(TCCR1A,WGM10);
	CLR_BIT(TCCR1A,WGM11);
	CLR_BIT(TCCR1B,WGM12);
	CLR_BIT(TCCR1B,WGM13);
	SET_BIT(TIMSK,TIMSK_TOIE1);

	/****************************************************************************************************/
	/******************************************  CTC Mode  **********************************************/
	/****************************************************************************************************/

#elif TIMER1_WAVE_GENERATION_SENSE == CTC

	/**************CTC TOP Mode************/

#if TIMER1_TOP_SENSE == OCR
	CLR_BIT(TCCR1A,WGM10);
	CLR_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	CLR_BIT(TCCR1B,WGM13);
#elif TIMER1_TOP_SENSE == ICR
	CLR_BIT(TCCR1A,WGM10);
	CLR_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
#else
#error "Wrong TIMER1_TOP_SENSE configuration option"
#endif
	SET_BIT(TIMSK,TIMSK_OCIE1A);
	SET_BIT(TIMSK,TIMSK_OCIE1B);

	/****************************************************************************************************/
	/****************************************  PWM Phase Correct Mode  **********************************/
	/****************************************************************************************************/

#elif TIMER1_WAVE_GENERATION_SENSE == PWM_PHASE_CORRECT

	/************PWM Phase Correct TOP Mode**********/

#if TIMER1_TOP_SENSE == OCR
	SET_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	CLR_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
#elif TIMER1_TOP_SENSE == ICR
	CLR_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	CLR_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
#elif TIMER1_TOP_SENSE == 8BIT
	SET_BIT(TCCR1A,WGM10);
	CLR_BIT(TCCR1A,WGM11);
	CLR_BIT(TCCR1B,WGM12);
	CLR_BIT(TCCR1B,WGM13);
#elif TIMER1_TOP_SENSE == 9BIT
	CLR_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	CLR_BIT(TCCR1B,WGM12);
	CLR_BIT(TCCR1B,WGM13);
#elif TIMER1_TOP_SENSE == 10BIT
	SET_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	CLR_BIT(TCCR1B,WGM12);
	CLR_BIT(TCCR1B,WGM13);
#else
#error "Wrong TIMER1_TOP_SENSE configuration option"
#endif

	/****************************************************************************************************/
	/*********************************  PWM Phase&frequency Correct Mode  *******************************/
	/****************************************************************************************************/

#elif TIMER1_WAVE_GENERATION_SENSE == PWM_PHASE&FREQUENCY_CORRECT

	/************PWM Phase&frequency Correct TOP Mode**********/

#if TIMER1_TOP_SENSE == OCR
	SET_BIT(TCCR1A,WGM10);
	CLR_BIT(TCCR1A,WGM11);
	CLR_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
#elif TIMER1_TOP_SENSE == ICR
	CLR_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	CLR_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
#else
#error "Wrong TIMER1_TOP_SENSE configuration option"
#endif

	/****************************************************************************************************/
	/****************************************  FAST PWM  Mode  ******************************************/
	/****************************************************************************************************/

#elif TIMER1_WAVE_GENERATION_SENSE == FAST_PWM

	/************FAST PWM TOP Mode**********/

#if TIMER1_TOP_SENSE == OCR
	SET_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
#elif TIMER1_TOP_SENSE == ICR
	CLR_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
#elif TIMER1_TOP_SENSE == 8BIT
	SET_BIT(TCCR1A,WGM10);
	CLR_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	CLR_BIT(TCCR1B,WGM13);
#elif TIMER1_TOP_SENSE == 9BIT
	CLR_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	CLR_BIT(TCCR1B,WGM13);
#elif TIMER1_TOP_SENSE == 10BIT
	SET_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	CLR_BIT(TCCR1B,WGM13);
#else
#error "Wrong TIMER1_TOP_SENSE configuration option"
#endif
#else
#error "Wrong TIMER1_WAVE_GENERATION_SENSE configuration option"
#endif

	/*****************Set Timer1 PWM output  MODE******************/
#if ( (TIMER1_WAVE_GENERATION_SENSE == PWM_PHASE_CORRECT) || (TIMER1_WAVE_GENERATION_SENSE == FAST_PWM) || (TIMER1_WAVE_GENERATION_SENSE == PWM_PHASE&FREQUENCY_CORRECT) )
#if TIMER1_PWM_SENSE == NO_OPERATION
	CLR_BIT(TCCR1,TCCR1_COM1A1);
	CLR_BIT(TCCR1,TCCR1_COM1A0);
	CLR_BIT(TCCR1,TCCR1_COM1B1);
	CLR_BIT(TCCR1,TCCR1_COM1B0);
#elif TIMER1_PWM_SENSE == TOGGLE_OC1A
	CLR_BIT(TCCR1,TCCR1_COM1A1);
	SET_BIT(TCCR1,TCCR1_COM1A0);
	CLR_BIT(TCCR1,TCCR1_COM1B1);
	SET_BIT(TCCR1,TCCR1_COM1B0);
#elif TIMER1_PWM_SENSE == NON_INVERTED
	SET_BIT(TCCR1,TCCR1_COM1A1);
	CLR_BIT(TCCR1,TCCR1_COM1A0);
	SET_BIT(TCCR1,TCCR1_COM1B1);
	CLR_BIT(TCCR1,TCCR1_COM1B0);
#elif TIMER1_PWM_SENSE == INVERTED
	SET_BIT(TCCR1,TCCR1_COM1A1);
	SET_BIT(TCCR1,TCCR1_COM1A0);
	SET_BIT(TCCR1,TCCR1_COM1B1);
	SET_BIT(TCCR1,TCCR1_COM1B0);
#else
#error "Wrong TIMER1_PWM_SENSE configuration option"
#endif
#else
#endif

	/**********************************************************************/
	/************************Set Timer1 Clock Select***********************/
	/**********************************************************************/

	TCCR1B = (CLK_MASK1)|(TIMER1_CLOCK_SELECT_SENSE);
}


/*Set Timer Value Function*/
void TIMER1_voidSetTimerValue(u16 Copy_u16Value)
{
	TCNT1 = Copy_u16Value;
}
/*Get Timer Value Function*/
u16  TIMER1_voidGetTimerValue(void)
{
	return TCNT1;
}
/*Set Comp1A Match Value Function*/
void TIMER1_voidSetCompMatchAValue(u8 Copy_u8Value)
{
	OCR1A = Copy_u8Value;
}
/*Set Comp1B Match Value Function*/
void TIMER1_voidSetCompMatchBValue(u8 Copy_u8Value)
{
	OCR1B = Copy_u8Value;
}
/*Set Top Value Function*/
void TIMER1_voidSetCompMatchTopValue(u8 Copy_u8Value)
{
	ICR1 = Copy_u8Value;
}

/**********************************************************************/
/*****************Timer1 OverFlow interrupt Handling*******************/
/**********************************************************************/

u8 TIMER1_u8OVFSetCallBack(void (*Copy_pvTimerOVFFunc)(void))
{
	u8 Local_u8ErrorState = OK;
	if(Copy_pvTimerOVFFunc != NULL)
	{
		TIMER_pvTimer1OVFFunc = Copy_pvTimerOVFFunc;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}
	return Local_u8ErrorState;
}

void __vector_9(void) __attribute__((signal));

void __vector_9(void)
{
	if(TIMER_pvTimer1OVFFunc != NULL)
	{
		TIMER_pvTimer1OVFFunc();
	}
	else
	{
		/*Do Nothing*/
	}
}

/**********************************************************************/
/**************Timer1 Comp & Match A interrupt Handling****************/
/**********************************************************************/

u8 TIMER1_u8CompASetCallBack(void (*Copy_pvTimerCompFunc)(void))
{
	u8 Local_u8ErrorState = OK;
	if(Copy_pvTimerCompFunc != NULL)
	{
		TIMER_pvTimer1CompAFunc = Copy_pvTimerCompFunc;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}
	return Local_u8ErrorState;
}

void __vector_7(void) __attribute__((signal));

void __vector_7(void)
{
	if(TIMER_pvTimer1CompAFunc != NULL)
	{
		TIMER_pvTimer1CompAFunc();
	}
	else
	{
		/*Do Nothing*/
	}
}
/**********************************************************************/
/***************Timer1 Comp&Mtach B interrupt Handling*****************/
/**********************************************************************/

u8 TIMER1_u8CompBSetCallBack(void (*Copy_pvTimerCompFunc)(void))
{
	u8 Local_u8ErrorState = OK;
	if(Copy_pvTimerCompFunc != NULL)
	{
		TIMER_pvTimer1CompBFunc = Copy_pvTimerCompFunc;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}
	return Local_u8ErrorState;
}

void __vector_8(void) __attribute__((signal));

void __vector_8(void)
{
	if(TIMER_pvTimer1CompBFunc != NULL)
	{
		TIMER_pvTimer1CompBFunc();
	}
	else
	{
		/*Do Nothing*/
	}
}

/************************************************************************************************************************************************************/
/*********************************************************			ICU Functions			  ***********************************************************/
/************************************************************************************************************************************************************/

void ICU_voidInit(void)
{
	#if TIMER1_ICU_SENSE == ENABLE
	#if TIMER1_ICU_EDGE_SENSE == FALLING_EDGE
	CLR_BIT(TCCR1B,ICES1);
	#elif TIMER1_ICU_EDGE_SENSE == RISING_EDGE
	SET_BIT(TCCR1B,ICES1);
	#else
	#error "Wrong TIMER1_ICU_EDGE_SENSE configuration option"
	#endif
	SET_BIT(TIMSK,TIMSK_TICIE1);
	#elif TIMER1_ICU_SENSE == DISABLE
	CLR_BIT(TIMSK,TIMSK_TICIE1);
	#else
	#error "Wrong TIMER1_ICU_SENSE configuration option"
	#endif
}

u8 ICU_voidSetTriggerEdge(u8 Copy_u8Edge)
{
	u8 Local_u8ErrorState = OK;
	if(Copy_u8Edge == FALLING_EDGE)
	{
		CLR_BIT(TCCR1B,ICES1);
	}
	else if(Copy_u8Edge == RISING_EDGE)
	{
		SET_BIT(TCCR1B,ICES1);
	}
	else
	{
		Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;
}
u8 ICU_voidInterruptMode(u8 Copy_u8Mode)
{
	u8 Local_u8ErrorState = OK;
	if(Copy_u8Mode == ENABLE)
	{
		SET_BIT(TIMSK,TIMSK_TICIE1);
	}
	else if(Copy_u8Mode == DISABLE)
	{
		CLR_BIT(TIMSK,TIMSK_TICIE1);
	}
	else
	{
		Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;
}
u16 ICU_voidGetValue(void)
{
	return ICR1;
}

/**********************************************************************/
/********************** ICU interrupt Handling*************************/
/**********************************************************************/
u8 ICU_u8SetCallBack(void (*Copy_pvIcuFunc)(void))
{
	u8 Local_u8ErrorState = OK;
	if(Copy_pvIcuFunc != NULL)
	{
		TIMER_pvIcuFunc = Copy_pvIcuFunc;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}
	return Local_u8ErrorState;
}

void __vector_6(void) __attribute__((signal));

void __vector_6(void)
{
	if(TIMER_pvIcuFunc != NULL)
	{
		TIMER_pvIcuFunc();
	}
	else
	{
		/*Do Nothing*/
	}
}


/************************************************************************************************************************************************************/
/*********************************************************			TIMER 2 Functions			  ***********************************************************/
/************************************************************************************************************************************************************/

void TIMER2_init(void)
{
	/**********************************************************************/
	/*****************Set Timer2 Waveform Generation MODE******************/
	/**********************************************************************/

	/***************Normal Overflow Mode************/
#if TIMER2_WAVE_GENERATION_SENSE == NORMAL
	CLR_BIT(TCCR2,TCCR2_WGM20);
	CLR_BIT(TCCR2,TCCR2_WGM21);
	SET_BIT(TIMSK,TIMSK_TOIE2);
	/**************PWM Phase Correct Mode***********/
#elif TIMER2_WAVE_GENERATION_SENSE == PWM_PHASE_CORRECT
	CLR_BIT(TCCR2,TCCR2_WGM21);
	SET_BIT(TCCR2,TCCR2_WGM20);
	/******************CTC Mode*********************/
#elif TIMER2_WAVE_GENERATION_SENSE == CTC
	CLR_BIT(TCCR2,TCCR2_WGM20);
	SET_BIT(TCCR2,TCCR2_WGM21);
	SET_BIT(TIMSK,TIMSK_OCIE2);
	/*****************Set CTC Output  MODE******************/
#if TIMER2_CTC_SENSE == NO_OPERATION
	CLR_BIT(TCCR2,TCCR2_COM21);
	CLR_BIT(TCCR2,TCCR2_COM20);
#elif TIMER2_CTC_SENSE == CLR
	SET_BIT(TCCR2,TCCR2_COM21);
	CLR_BIT(TCCR2,TCCR2_COM20);
#elif TIMER2_CTC_SENSE == SET
	SET_BIT(TCCR2,TCCR2_COM20);
	SET_BIT(TCCR2,TCCR2_COM21);
#else
#error "Wrong TIMER2_CTC_SENSE configuration option"
#endif
	/***************************Fast PWM Mode**********************/
#elif TIMER2_WAVE_GENERATION_SENSE == FAST_PWM
	SET_BIT(TCCR2,TCCR2_WGM20);
	SET_BIT(TCCR2,TCCR2_WGM21);
#else
#error "Wrong WAVE_GENERATION_SENSE configuration option"
#endif
	if( (TIMER2_WAVE_GENERATION_SENSE == PWM_PHASE_CORRECT) || (TIMER2_WAVE_GENERATION_SENSE == FAST_PWM) )
	{
		/*****************Set PWM Output  MODE******************/
#if TIMER2_PWM_SENSE == NO_OPERATION
		CLR_BIT(TCCR2,TCCR2_COM21);
		CLR_BIT(TCCR2,TCCR2_COM20);
#elif TIMER2_PWM_SENSE == NON_INVERTED
		SET_BIT(TCCR2,TCCR2_COM21);
		CLR_BIT(TCCR2,TCCR2_COM20);
#elif TIMER2_PWM_SENSE == INVERTED
		SET_BIT(TCCR2,TCCR2_COM20);
		SET_BIT(TCCR2,TCCR2_COM21);
#else
#error "Wrong TIMER2_PWM_SENSE configuration option"
#endif
	}

	/**********************************************************************/
	/************************Set Timer2 Clock Select***********************/
	/**********************************************************************/
	TCCR2 = (CLK_MASK2) | TIMER2_CLOCK_SELECT_SENSE;
}

/**********************************************************************/
/***********************POST BUILD CONFIGURATION***********************/
/**********************************************************************/
void TIMER2_voidSetCompMatchValue(u8 Copy_u8Value)
{
	OCR2 = Copy_u8Value;
}

void TIMER2_voidSetTimerValue(u8 Copy_u8Value)
{
	TCNT2 = Copy_u8Value;
}


/**********************************************************************/
/*****************Timer2 OverFlow interrupt Handling*******************/
/**********************************************************************/
u8 TIMER2_u8OVFSetCallBack(void (*Copy_pvTimer2OVFFunc)(void))
{
	u8 Local_u8ErrorState = OK;
	if(Copy_pvTimer2OVFFunc != NULL)
	{
		TIMER_pvTimer2OVFFunc = Copy_pvTimer2OVFFunc;
		return Local_u8ErrorState;
	}
	else
	{
		return Local_u8ErrorState = NULL_POINTER;
	}
}

void __vector_5(void) __attribute__((signal));

void __vector_5(void)
{
	if(TIMER_pvTimer2OVFFunc != NULL)
	{
		TIMER_pvTimer2OVFFunc();
	}
	else
	{
		/*Do Nothing*/
	}
}

/**********************************************************************/
/**************Timer2 Compare&Match interrupt Handling*****************/
/**********************************************************************/


u8 TIMER2_u8CompSetCallBack(void (*Copy_pvTimer2CompFunc)(void))
{
	u8 Local_u8ErrorState = OK;
	if(Copy_pvTimer2CompFunc != NULL)
	{
		TIMER_pvTimer2CompFunc = Copy_pvTimer2CompFunc;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}
	return Local_u8ErrorState;
}

void __vector_4(void) __attribute__((signal));

void __vector_4(void)
{
	if(TIMER_pvTimer2CompFunc != NULL)
	{
		TIMER_pvTimer2CompFunc();
	}
	else
	{
		/*Do Nothing*/
	}
}


/************************************************************************************************************************************************************/
/*********************************************************			WatchDog Functions			  ***********************************************************/
/************************************************************************************************************************************************************/

u8  WTD_voidSleep(u8 Copy_u8WDValue)
{
	u8 Local_u8ErrorState = OK;
	if(Copy_u8WDValue < T2p1S)
	{
		WDTCR = (WDTCR_MASK) |  Copy_u8WDValue;
		SET_BIT(WDTCR,WDTCR_WDE);
	}
	else
	{
		Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;

}
void WTD_voidDisable(void)
{
	WDTCR = (1<<WDTCR_WDE) | (1<<WDTCR_WDE);
	WDTCR = 0x00;
}



#include "STD_TYPES.h"
#include "BIT_MATH.h"



#include "MCAL_ADC_config.h"
#include "MCAL_ADC_interface.h"
#include "MCAL_ADC_private.h"
#include "MCAL_ADC_register.h"




/*use the  static because use the pointer in this file only */
u16*ADC_Result = NULL;
static void (*ADC_PvNotification)(void) =NULL ;

/*Global flag is indicated the ADC Work or Not */
u8 ADC_u8State = IDLE ;

/*its indicate the Number of active thhe adc peripherial*/
u8 Local_u8CounterLoop ;
/*global pointer to indicate the result of the adc*/
u16* ADC_Res;




void ADC_void_Init (void)
{

	/*The Selectable Referance Voltage :
	 * Options :1-AREF_EXT : Access AREF by External Voltage
	 * 			2-AREF_AVCC: Access AREF by AVCC
	 * 			3-AREF_DEFAULT: Access AREF by Internal Voltage
	 * */
#if REF_SELECT==AREF_EXT
	CLR_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
#elif REF_SELECT==AREF_AVCC
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
#elif REF_SELECT==AREF_DEFAULT
	SET_BIT(ADMUX,ADMUX_REFS0);
	SET_BIT(ADMUX,ADMUX_REFS1);
#else
#error "REF Selectable is WRONG"
#endif

	/*The Configuration of Upper and Lower Register
	 * Options :	1-Left_adjust :"when use 8 -bit Only"
	 * 				2-Right_adjust "When use 10-bit "*/
#if VALUE_REG_CONFIG == STORE_8BIT
	SET_BIT(ADMUX,ADMUX_ADLAR);
#elif VALUE_REG_CONFIG ==STORE_10BIT
	CLR_BIT(ADMUX,ADMUX_ADLAR);
#else
#error "WRONG IN CONFIGURATION VALUE REGISTER"
#endif

	/*Configuration The Prescaler Division
	 * Options : 1-DIVISON_BY_2
	 * 			 2-DIVISON_BY_2
	 * 			 3-DIVISON_BY_4
	 * 			 4-DIVISON_BY_8
	 * 			 5-DIVISON_BY_16
	 * 			 6-DIVISON_BY_32
	 * 			 7-DIVISON_BY_64
	 * 			 8-DIVISON_BY_128
	 * */
	ADCSRA &= 0b11111000;   // Clear first 3 bits in ADCSRA register
	ADCSRA|=ADC_PRESCALER;	// Set required configuration

	/*Configuration Of The State Of ADC
	 * Options : 1-ENABLE
	 * 			 2-DISABLE
	 * 			 */

#if ADC_STATE==ENABLE
	SET_BIT(ADCSRA,ADCSRA_ADEN);
#elif ADC_STATE==DISABLE
	CLR_BIT(ADCSRA,ADCSRA_ADEN);
#else
#error "WRONG IN THE ADC STAE"
#endif

}

/*Sych Start Conversion is used in the critical instructions*/


u8 ADC_u8_StartSingleConversionSyn (ADC_t *singleSync )
{
	/*the indication the operation is execute or not
	 * Options :1 - OK  : the Function is successed
	 * 			2- NOK : the Function is not successed
	 * 			3- NULL_Pointer :the Pointer not indicate any location in memory
	 * 																				*/
	u8 Local_u8ErrorState = OK;

	u32 Local_u32CounterLimit =0 ;

	if (singleSync->Result !=NULL)
	{
		if (ADC_u8State ==IDLE)
		{
			ADC_u8State =BUSY;
			/*Clear the channel Code*/
			ADMUX &= MUX_CLEAR ;
			/*Set the Channel Code */
			ADMUX |= singleSync->Channel_ID ;
			/*Start Conversion*/
			SET_BIT(ADCSRA,ADCSRA_ADSC);
			/* Busy waiting (polling) until the conversion is complete */
			while ((GET_BIT(ADCSRA,ADCSRA_ADIF)==0)&&(Local_u32CounterLimit <ADC_LIMIT_WAITING))
			{
				Local_u32CounterLimit++;
			}
			if (Local_u32CounterLimit ==ADC_LIMIT_WAITING)
			{
				Local_u8ErrorState = TIMEOUT_STATE ;
			}
			else
			{
				/*clear the interrupt flag*/
				SET_BIT(ADCSRA,ADCSRA_ADIF);

#if VALUE_REG_CONFIG == STORE_8BIT
				*(singleSync->Result) =ADCH ;
#elif VALUE_REG_CONFIG == STORE_10BIT
				*singleSync->Result =ADC ;
#else
#error "WRONG IN VALUE_REG_CONFIG"
#endif


			}
			ADC_u8State = IDLE ;
		}

		else
		{
			Local_u8ErrorState = BUSY_STATE ;
		}
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}

	return Local_u8ErrorState ;


}

u8 ADC_u8_StartSingleConversionAsyn (ADC_t *singleAsync)
{
	u8 Local_u8ErrorState =OK;
	if ((singleAsync->Result !=NULL)&&(singleAsync->Copy_PvNotification!=NULL))
	{
		if (ADC_u8State ==IDLE)
		{
			ADC_u8State =BUSY ;
			/*convert the result to the global variable*/
			ADC_Result=singleAsync->Result  ;
			/*convert the pointer of the function to global */
			ADC_PvNotification =singleAsync->Copy_PvNotification;

			/*Clear the Channel Code */
			ADMUX &= MUX_CLEAR;
			/*Set the channel Code*/
			ADMUX |= singleAsync->Channel_ID;
			/*Star tConversion */
			SET_BIT(ADCSRA,ADCSRA_ADSC);
			/*enable the adc interrupt*/
			SET_BIT(ADCSRA,ADCSRA_ADIE);
		}
		else
		{
			Local_u8ErrorState =BUSY_STATE ;
		}
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}
	return Local_u8ErrorState;
}



void __vector_16 (void)			__attribute__((signal));
void __vector_16 (void)
{

#if VALUE_REG_CONFIG == STORE_8BIT
	 *(singleAsync->Result) =ADCH ;
#elif VALUE_REG_CONFIG == STORE_10BIT
	 *singleAsync->Result =ADC ;
#else
#error "WRONG IN VALUE_REG_CONFIG"
#endif

		ADC_u8State =IDLE;
		ADC_PvNotification();

		CLR_BIT(ADCSRA,ADCSRA_ADIE);







}



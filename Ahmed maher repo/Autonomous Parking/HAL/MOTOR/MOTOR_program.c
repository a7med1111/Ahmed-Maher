
 


#include "DIO_interface.h"
#include "TIMER_interface.h"
#include "MOTOR__Interface.h"
#include "MOTOR_config.h"
#include "MOTOR_private.h"


void MOTOR_vd_CCW(MOTOR_t *motor)
{
	MCAL_DIO_u8_SetPinValue(PORT_MOTOR, motor->Pin1_ID, PIN_LOW);
	MCAL_DIO_u8_SetPinValue(PORT_MOTOR, motor->Pin2_ID, PIN_HIGH);

	if(motor->TimerName == TIMER0)
	{
		TIMER0_voidSetCompMatchValue(motor->Speed);
	}
	else if(motor->TimerName == TIMER2)
	{
		TIMER2_voidSetCompMatchValue(motor->Speed);
	}
	else
	{
		/*Do Nothing*/
	}
}

void MOTOR_vd_CW(MOTOR_t *motor)
{
	MCAL_DIO_u8_SetPinValue(PORT_MOTOR, motor->Pin1_ID, PIN_HIGH);
	MCAL_DIO_u8_SetPinValue(PORT_MOTOR, motor->Pin2_ID, PIN_LOW);
	if(motor->TimerName == TIMER0)
	{
		TIMER0_voidSetCompMatchValue(motor->Speed);
	}
	else if(motor->TimerName == TIMER2)
	{
		TIMER2_voidSetCompMatchValue(motor->Speed);
	}
	else
	{
		/*Do Nothing*/
	}
}

void MOTOR_vd_stop(MOTOR_t *motor)
{
	MCAL_DIO_u8_SetPinValue(PORT_MOTOR, motor->Pin1_ID, PIN_LOW);
	MCAL_DIO_u8_SetPinValue(PORT_MOTOR, motor->Pin2_ID, PIN_LOW);
	if(motor->TimerName == TIMER0)
	{
		TIMER0_voidSetCompMatchValue(motor->Speed);
	}
	else if(motor->TimerName == TIMER2)
	{
		TIMER2_voidSetCompMatchValue(motor->Speed);
	}
	else
	{
		/*Do Nothing*/
	}
}

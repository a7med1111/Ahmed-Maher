#include "STD_TYPES.h"
#include "DIO_register.h"
#include "DIO_config.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "BIT_MATH.h"



ErrorState_t  MCAL_DIO_u8_SetPinDirection(Dio_ConfigPin *Pset)
{
	ErrorState_t  Local_u8ErrorState= E_OK;
	if (Pset->Pin_Id <= PIN7)
	{
		if (Pset->dir == PIN_INPUT)
		{
			switch (Pset->Port_Id)
			{
			case PORTA_ID:
				CLR_BIT(DDRA, Pset->Pin_Id);
				break;
			case PORTB_ID:
				CLR_BIT(DDRB, Pset->Pin_Id);
				break;
			case PORTC_ID:
				CLR_BIT(DDRC, Pset->Pin_Id);
				break;
			case PORTD_ID:
				CLR_BIT(DDRD, Pset->Pin_Id);
				break;
			default:
				Local_u8ErrorState = E_NOK;
				break;
			}
		}
	}
	else if (Pset->dir == PIN_OUTPUT)
	{
		switch (Pset->Port_Id)
		{
		case PORTA_ID:
			SET_BIT(DDRA, Pset->Pin_Id);
			break;
		case PORTB_ID:
			SET_BIT(DDRB, Pset->Pin_Id);
			break;
		case PORTC_ID:
			SET_BIT(DDRC, Pset->Pin_Id);
			break;
		case PORTD_ID:
			SET_BIT(DDRD, Pset->Pin_Id);
			break;
		default:
			Local_u8ErrorState = E_NOK;
			break;
		}
	}
	else
	{
		Local_u8ErrorState = E_NOK;
	}

	return Local_u8ErrorState;
}

ErrorState_t MCAL_DIO_u8_SetPortDirection(Dio_ConfigPin *Pset)
{
	u8 Local_u8ErrorState = E_OK;

	switch (Pset->Port_Id) {
	case PORTA_ID :
		DDRA = Pset->dir;
		break;
	case PORTB_ID :
		DDRB = Pset->dir;
		break;
	case PORTC_ID :
		DDRC = Pset->dir;
		break;
	case PORTD_ID :
		DDRD = Pset->dir;
		break;
	default:
		Local_u8ErrorState = E_NOK;
	}

	return Local_u8ErrorState;
}

ErrorState_t MCAL_DIO_u8_SetPinValue(Dio_ConfigPin *Pset)
{
	u8 Local_u8ErrorState = E_OK;

	if (Pset->Pin_Id <= PIN7) {
		if (Pset->level == PIN_LOW) {
			switch (Pset->Port_Id) {
			case PORTA_ID:
				CLR_BIT(PORTA, Pset->Pin_Id);
				break;
			case PORTB_ID:
				CLR_BIT(PORTB, Pset->Pin_Id);
				break;
			case PORTC_ID:
				CLR_BIT(PORTC, Pset->Pin_Id);
				break;
			case PORTD_ID:
				CLR_BIT(PORTD, Pset->Pin_Id);
				break;
			default:
				Local_u8ErrorState = E_NOK;
				break;
			}
		} else if (Pset->level == PIN_HIGH) {
			switch (Pset->Port_Id) {
			case PORTA_ID:
				SET_BIT(PORTA, Pset->Pin_Id);
				break;
			case PORTB_ID:
				SET_BIT(PORTB, Pset->Pin_Id);
				break;
			case PORTC_ID:
				SET_BIT(PORTC, Pset->Pin_Id);
				break;
			case PORTD_ID:
				SET_BIT(PORTD, Pset->Pin_Id);
				break;
			default:
				Local_u8ErrorState = E_NOK;
				break;
			}
		} else {
			Local_u8ErrorState = E_NOK;
		}
	} else {
		Local_u8ErrorState = E_NOK;
	}

	return Local_u8ErrorState;
}

ErrorState_t MCAL_DIO_u8_SetPortValue(Dio_ConfigPin *Pset)
{
	u8 Local_u8ErrorState = E_OK;

	switch (Pset->Port_Id) {
	case PORTA_ID :
		PORTA = Pset->level;
		break;
	case PORTB_ID :
		PORTB = Pset->level;
		break;
	case PORTC_ID :
		PORTC = Pset->level;
		break;
	case PORTD_ID :
		PORTD = Pset->level;
		break;
	default:
		Local_u8ErrorState = E_NOK;
	}

	return Local_u8ErrorState;
}



ErrorState_t MCAL_DIO_u8_GetPinValue(Dio_ConfigPin *Pset)
{
	u8 Local_u8ErrorState = E_OK;

	if (( Pset->Pret_value!= NULL) && (Pset->Pin_Id <= PIN7)) {
		switch (Pset->Port_Id) {
		case PORTA_ID :
			Pset->Pret_value = GET_BIT(PINA, Pset->Pin_Id);
			break;
		case PORTB_ID :
			Pset->Pret_value = GET_BIT(PINB, Pset->Pin_Id);
			break;
		case PORTC_ID :
			Pset->Pret_value = GET_BIT(PINC, Pset->Pin_Id);
			break;
		case PORTD_ID :
			Pset->Pret_value = GET_BIT(PIND, Pset->Pin_Id);
			break;
		default:
			Local_u8ErrorState = E_NOK;
		}
	} else {
		Local_u8ErrorState = E_NOK;
	}
	return Local_u8ErrorState;
}

ErrorState_t MCAL_DIO_u8_TogglePinValue(Dio_ConfigPin *Pset)
{
	u8 Local_u8ErrorState = E_OK;
	switch (Pset->Port_Id) {
	case PORTA_ID:
		TOGGLE_BIT(PORTA, Pset->Pin_Id);
		break;
	case PORTB_ID:
		TOGGLE_BIT(PORTB, Pset->Pin_Id);
		break;
	case PORTC_ID:
		TOGGLE_BIT(PORTC, Pset->Pin_Id);
		break;
	case PORTD_ID:
		TOGGLE_BIT(PORTD, Pset->Pin_Id);
		break;
	default:
		Local_u8ErrorState = E_NOK;
		break;
	}
	return Local_u8ErrorState;
}






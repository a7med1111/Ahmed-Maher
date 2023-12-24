#include "LED_interface.h"
#include "LED_config.h"
#include "LED_private.h"
#include "../../MCAL/DIO/DIO_interface.h"

LED_Invalid_Initialization HAL_LED_u8_Init (Dio_ConfigPin Pin_Config){
	//Initialize the Error state = NOK (1)
	u8 Local_u8_ErrorStatus = NOK;
	// check For Initialization of Port
	if(Pin_Config.Port_Id <= PORTD_ID){
		// Check for initialization of Pin
		if(Pin_Config.Pin_Id <= PIN7){
			//Set Pin Direction & return its error state
			Local_u8_ErrorStatus = MCAL_DIO_u8_SetPinDirection(Pin_Config);
		}
		else{
			//DO Nothing
		}
	}
	else{
			//DO Nothing
	}
	//return Error state of function
	return Local_u8_ErrorStatus;
}

LED_Invalid_Initialization HAL_LED_u8_LedOn (Dio_ConfigPin Pin_Config){
	//Initialize the Error state = NOK (1)
	u8 Local_u8_ErrorStatus = NOK;
	// check For Initialization of Port
	if(Pin_Config.Port_Id <= PORTD_ID){
		// Check for initialization of Pin
		if(Pin_Config.Pin_Id <= PIN7){
			//Set Pin Value & return its error state
			Local_u8_ErrorStatus = MCAL_DIO_u8_SetPinValue(Pin_Config);
		}
		else{
			//DO Nothing
		}
	}
	else{
			//DO Nothing
	}
	//return Error state of function
	return Local_u8_ErrorStatus;

}

LED_Invalid_Initialization HAL_LED_u8_LedOff (Dio_ConfigPin Pin_Config){
	//Initialize the Error state = NOK (1)
	u8 Local_u8_ErrorStatus = NOK;
	// check For Initialization of Port
	if(Pin_Config.Port_Id <= PORTD_ID){
		// Check for initialization of Pin
		if(Pin_Config.Pin_Id <= PIN7){
			//Set Pin Value & return its error state
			Local_u8_ErrorStatus = MCAL_DIO_u8_SetPinValue(Pin_Config);
		}
		else{
			//DO Nothing
		}
	}
	else{
			//DO Nothing
	}
	//return Error state of function
	return Local_u8_ErrorStatus;
}

LED_Invalid_Initialization HAL_LED_u8_LedToggle (Dio_ConfigPin Pin_Config){
	//Initialize the Error state = NOK (1)
	u8 Local_u8_ErrorStatus = NOK;
	// check For Initialization of Port
	if(Pin_Config.Port_Id <= PORTD_ID){
		// Check for initialization of Pin
		if(Pin_Config.Pin_Id <= PIN7){
			//toggle Pin Value & return its error state
			Local_u8_ErrorStatus = MCAL_DIO_u8_TogglePinValue(Pin_Config);
		}
		else{
			//DO Nothing
		}
	}
	else{
			//DO Nothing
	}
	//return Error state of function
	return Local_u8_ErrorStatus;
}

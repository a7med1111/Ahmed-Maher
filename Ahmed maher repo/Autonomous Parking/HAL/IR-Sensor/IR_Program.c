
 
#include "IR_Config.h"
#include "IR_Interface.h"
#include "IR_Private.h"
#include "../../MCAL/DIO/DIO_interface.h"




IR_Invalid_Initialization HAL_IR_Void_Init(){
//Initialization of IR Output Signal structure (Port , Pin , Direction)
	Dio_ConfigPin Pin_Config;
	// Member contains the ID of the Port that this pin belongs to
	Pin_Config.Port_Id = IR_SIGNAL_PORT;
	// Member contains the ID of the Pin
	Pin_Config.Pin_Id = IR_SIGNAL_PIN;
	// Member contains the State of the Port-bit that this pin belongs to
	Pin_Config.dir = PIN_INPUT;
//Initiallization of Error State = Not Ok (1)
	u8 Local_u8_ErrorStatus = NOK;
	if(Pin_Config.Port_Id <= PORTD_ID){
		if(Pin_Config.Pin_Id <= PIN7){
			Local_u8_ErrorStatus = MCAL_DIO_u8_Init_Direction(Pin_Config.Port_Id , Pin_Config.Pin_Id , Pin_Config.dir);
		}
		else{
			//Do Nothing
		}
	}
	else{
		//DO Nothing
	}
	return Local_u8_ErrorStatus;
}

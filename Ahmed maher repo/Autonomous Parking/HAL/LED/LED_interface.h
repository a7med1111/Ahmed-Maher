
 
 

#include "LED_config.h"
#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

/********************************Description************************************
 * LED or Light Emitting Diode is alow-voltage, low-current semiconductor device
  that can emit when current flows through it.
 ***********************Function Prototypes*************************************
 1)HAL_LED_u8_Init
 2)HAL_LED_u8_LedOn
 2)HAL_LED_u8_LedOff
 2)HAL_LED_u8_LedToggle
 ******************************************************************************/


/*************************************************************************************
 * Function Name: HAL_LED_u8_Init
 * Parameters (in): (struct)Dio_ConfigPin
 * Parameters (out): None
 * Return value:(Error State)-LED_Invalid_Initialization.
 * Description: Function to Initialize the LED module.
 ************************************************************************************/
LED_Invalid_Initialization HAL_LED_u8_Init (Dio_ConfigPin Pin_Config);

/*************************************************************************************
 * Function Name: HAL_LED_u8_LedOn
 * Parameters (in): (struct)Dio_ConfigPin
 * Parameters (out): None
 * Return value:(Error State)-LED_Invalid_Initialization.
 * Description: Function to Set Led On.
 ************************************************************************************/
LED_Invalid_Initialization HAL_LED_u8_LedOn (Dio_ConfigPin Pin_Config);

/*************************************************************************************
 * Function Name: HAL_LED_u8_LedOff
 * Parameters (in): (struct)Dio_ConfigPin
 * Parameters (out): None
 * Return value:(Error State)-LED_Invalid_Initialization
 * Description: Function to Set Led Off.
 ************************************************************************************/
LED_Invalid_Initialization HAL_LED_u8_LedOff (Dio_ConfigPin Pin_Config);

/*************************************************************************************
 * Function Name: HAL_LED_u8_LedToggle
 * Parameters (in): (struct)Dio_ConfigPin
 * Parameters (out): None
 * Return value:(Error State)-LED_Invalid_Initialization
 * Description: Function to Toggle Led.
 ************************************************************************************/
LED_Invalid_Initialization HAL_LED_u8_LedToggle (Dio_ConfigPin);



#endif /* LED_INTERFACE_H_ */

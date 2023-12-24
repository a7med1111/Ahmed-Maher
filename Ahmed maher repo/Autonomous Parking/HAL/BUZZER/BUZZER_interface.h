
 

#include "BUZZER_config.h"

#ifndef BUZZER_BUZZER_INTERFACE_H_
#define BUZZER_BUZZER_INTERFACE_H_

/********************************Description************************************
 * Buzzer is an audio signaling device, which may be mechanical, electromechanical,
   or piezoelectric material
 ***********************Function Prototypes*************************************
 1)HAL_BUZZER_u8_Init
 2)HAL_BUZZER_u8_LedOn
 2)HAL_BUZZER_u8_LedOff
 2)HAL_BUZZER_u8_LedToggle
 ******************************************************************************/

Buzzer_Invalid_Initialization HAL_BUZZER_u8_Init (Dio_ConfigPin Pin_Config);
Buzzer_Invalid_Initialization HAL_BUZZER_u8_BuzzerOn (Dio_ConfigPin Pin_Config);
Buzzer_Invalid_Initialization HAL_BUZZER_u8_BuzzerOff (Dio_ConfigPin Pin_Config);
Buzzer_Invalid_Initialization HAL_Buzzer_u8_BuzzerToggle (Dio_ConfigPin Pin_Config);


#endif /* BUZZER_BUZZER_INTERFACE_H_ */

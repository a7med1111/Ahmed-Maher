

 

#ifndef IR_DRIVER_IR_INTERFACE_H_
#define IR_DRIVER_IR_INTERFACE_H_


/********************************Description******************************************
 * An infrared or IR sensor is an electrical device that measures a distance between
   itself and an object placed within a certain distance, by emitting infrared waves
   and recieving the reflected waves.
 ****************************Function Prototypes**************************************
 1)HAL_IR_Void_Init
 *************************************************************************************/


/**************************************************************************************
 * Function Name: HAL_IR_Void_Init
 * Parameters (in): None
 * Parameters (input): None
 * Parameters (out): None
 * Return value:(Error State)-IR_Invalid_Initialization.
 * Description: Function to Initialize the IR-Sensor module.
 ************************************************************************************/
IR_Invalid_Initialization HAL_IR_Void_Init();


#endif /* IR_DRIVER_IR_INTERFACE_H_ */

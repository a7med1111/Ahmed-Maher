#include "STD_TYPES.h"

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_


#define DIO_INITIALIZED                (1U)
#define DIO_NOT_INITIALIZED            (0U)


#define PIN_OUTPUT			1
#define PIN_INPUT			0

#define PIN_HIGH			1
#define PIN_LOW				0

#define PORT_OUTPUT			0xFF
#define PORT_INPUT			0

#define PORT_HIGH 			0xFF
#define PORT_LOW  			0

#define PORTA_ID				0
#define PORTB_ID				1
#define PORTC_ID				2
#define PORTD_ID				3

#define PIN0					0
#define PIN1					1
#define PIN2					2
#define PIN3					3
#define PIN4					4
#define PIN5					5
#define PIN6					6
#define PIN7					7


/*
#define    PIN_A_0         0  // 0
#define    PIN_A_1         1  // 1
#define    PIN_A_2         2  // 2
#define    PIN_A_3         3  // 3
#define    PIN_A_4         4  // 4
#define    PIN_A_5         5  // 5
#define    PIN_A_6         6  // 6
#define    PIN_A_7         7  // 7
#define    PIN_B_0         8  // 0
#define    PIN_B_1         9  // 1
#define    PIN_B_2         10 // 2
#define    PIN_B_3         11 // 3
#define    PIN_B_4         12 // 4
#define    PIN_B_5         13 // 5
#define    PIN_B_6         14 // 6
#define    PIN_B_7         15 // 7
#define    PIN_C_0         16 // 0
#define    PIN_C_1         17 // 1
#define    PIN_C_2         18 // 2
#define    PIN_C_3         19 // 3
#define    PIN_C_4         20 // 4
#define    PIN_C_5         21 // 5
#define    PIN_C_6         22 // 6
#define    PIN_C_7         23 // 7
#define    PIN_D_0         24 // 0
#define    PIN_D_1         25 // 1
#define    PIN_D_2         26 // 2
#define    PIN_D_3         27 // 3
#define    PIN_D_4         28 // 4
#define    PIN_D_5         29 // 5
#define    PIN_D_6         30 // 6
#define    PIN_D_7         31 // 7
 */

typedef struct Dio_ConfigPin {
	u8 Port_Id;
	u8 Pin_Id;
	u8 dir;
	u8 level;
	u8*Pret_value;
} Dio_ConfigPin;









ErrorState_t  MCAL_DIO_u8_SetPinDirection(Dio_ConfigPin *Pset);

ErrorState_t MCAL_DIO_u8_SetPortDirection(Dio_ConfigPin *Pset);

ErrorState_t MCAL_DIO_u8_SetPinValue(Dio_ConfigPin *Pset);

ErrorState_t MCAL_DIO_u8_SetPortValue(Dio_ConfigPin *Pset);

ErrorState_t MCAL_DIO_u8_GetPinValue(Dio_ConfigPin *Pset);

ErrorState_t MCAL_DIO_u8_TogglePinValue(Dio_ConfigPin *Pset);


#endif

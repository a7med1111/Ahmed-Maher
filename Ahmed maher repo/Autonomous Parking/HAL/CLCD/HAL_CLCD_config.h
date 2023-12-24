


#ifndef HAL_CLCD_CONFIG_H_
#define HAL_CLCD_CONFIG_H_



//  select the port which will send data on

#define CLCD_DATA_PORT		PORTA_ID

#define CLCD_MODE_4_BIT_PIN0		PIN7
#define CLCD_MODE_4_BIT_PIN1		PIN6
#define CLCD_MODE_4_BIT_PIN2		PIN5
#define CLCD_MODE_4_BIT_PIN3		PIN4

//	select the port which will have control pins
#define CLCD_CTRL_PORT		PORTB_ID
//	select the pins of Rs , Rw , En
#define CLCD_RS_PIN			PIN0
#define CLCD_RW_PIN			PIN1
#define CLCD_E_PIN			PIN2

#define MODE_8_BIT		1

#define MODE_4_BIT   	2





/*Selectable the mode of the Lcd
 * OptionS :
 * 			1- 8_BIT  MODE:MODE_8_BIT
 * 			2- 4_BIT MODE:MODE_4_BIT*/

#define CLCD_MODE		MODE_4_BIT
// function set



#endif

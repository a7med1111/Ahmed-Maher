

//library
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>

//mcal layer
#include "DIO_interface.h"

//LCD FILES
#include "HAL_CLCD_interface.h"
#include "HAL_CLCD_config.h"
#include "HAL_CLCD_private.h"



void HAL_CLCD_void_SendCommand (u8 Copy_u8Command)//1001 0100
{
	//set the register select to zero to active command mode
	MCAL_DIO_u8_SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,PIN_LOW);
	 //set RW to zero to active the effect command on the lcd
	MCAL_DIO_u8_SetPinValue (CLCD_CTRL_PORT,CLCD_RW_PIN,PIN_LOW);

#if CLCD_MODE==MODE_8_BIT
	 MCAL_DIO_u8_SetPortValue(CLCD_DATA_PORT,Copy_u8Command);
	 //read the command by enable pin
	 MCAL_DIO_u8_SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,PIN_HIGH);
	 _delay_ms (2);
	 MCAL_DIO_u8_SetPinValue (CLCD_CTRL_PORT,CLCD_E_PIN,PIN_LOW);
#elif CLCD_MODE==MODE_4_BIT
	 MCAL_DIO_u8_SetPinValue(CLCD_DATA_PORT,CLCD_MODE_4_BIT_PIN0,GET_BIT(Copy_u8Command,7));
	 MCAL_DIO_u8_SetPinValue(CLCD_DATA_PORT,CLCD_MODE_4_BIT_PIN1,GET_BIT(Copy_u8Command,6));
	 MCAL_DIO_u8_SetPinValue(CLCD_DATA_PORT,CLCD_MODE_4_BIT_PIN2,GET_BIT(Copy_u8Command,5));
	 MCAL_DIO_u8_SetPinValue(CLCD_DATA_PORT,CLCD_MODE_4_BIT_PIN3,GET_BIT(Copy_u8Command,4));

	 MCAL_DIO_u8_SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,PIN_HIGH);
	 _delay_ms (2);
	 MCAL_DIO_u8_SetPinValue (CLCD_CTRL_PORT,CLCD_E_PIN,PIN_LOW);

	 MCAL_DIO_u8_SetPinValue(CLCD_DATA_PORT,CLCD_MODE_4_BIT_PIN0,GET_BIT(Copy_u8Command,3));
	 MCAL_DIO_u8_SetPinValue(CLCD_DATA_PORT,CLCD_MODE_4_BIT_PIN1,GET_BIT(Copy_u8Command,2));
	 MCAL_DIO_u8_SetPinValue(CLCD_DATA_PORT,CLCD_MODE_4_BIT_PIN2,GET_BIT(Copy_u8Command,1));
	 MCAL_DIO_u8_SetPinValue(CLCD_DATA_PORT,CLCD_MODE_4_BIT_PIN3,GET_BIT(Copy_u8Command,0));

	 MCAL_DIO_u8_SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,PIN_HIGH);
	 _delay_ms (2);
	 MCAL_DIO_u8_SetPinValue (CLCD_CTRL_PORT,CLCD_E_PIN,PIN_LOW);


#else
#error "WRONG IN SEND COMMAND"
#endif
}
void HAL_CLCD_void_SendData (u8 Copy_u8Data)
{
	//set the register select to one to active command mode
	MCAL_DIO_u8_SetPinValue (CLCD_CTRL_PORT,CLCD_RS_PIN,PIN_HIGH);
	 //set RW to zero to active the effect command on the lcd
	MCAL_DIO_u8_SetPinValue (CLCD_CTRL_PORT,CLCD_RW_PIN,PIN_LOW);


#if CLCD_MODE==MODE_8_BIT
	//put data on the data port
	MCAL_DIO_u8_SetPortValue(CLCD_DATA_PORT,Copy_u8Data);
	 //read the data by enable pin
	MCAL_DIO_u8_SetPinValue (CLCD_CTRL_PORT,CLCD_E_PIN,PIN_HIGH);
	_delay_ms (2);
	MCAL_DIO_u8_SetPinValue (CLCD_CTRL_PORT,CLCD_E_PIN,PIN_LOW);
#elif CLCD_MODE==MODE_4_BIT
	     MCAL_DIO_u8_SetPinValue(CLCD_DATA_PORT,CLCD_MODE_4_BIT_PIN0,GET_BIT(Copy_u8Data,7));
		 MCAL_DIO_u8_SetPinValue(CLCD_DATA_PORT,CLCD_MODE_4_BIT_PIN1,GET_BIT(Copy_u8Data,6));
		 MCAL_DIO_u8_SetPinValue(CLCD_DATA_PORT,CLCD_MODE_4_BIT_PIN2,GET_BIT(Copy_u8Data,5));
		 MCAL_DIO_u8_SetPinValue(CLCD_DATA_PORT,CLCD_MODE_4_BIT_PIN3,GET_BIT(Copy_u8Data,4));

		 MCAL_DIO_u8_SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,PIN_HIGH);
		 _delay_ms (2);
		 MCAL_DIO_u8_SetPinValue (CLCD_CTRL_PORT,CLCD_E_PIN,PIN_LOW);

		 MCAL_DIO_u8_SetPinValue(CLCD_DATA_PORT,CLCD_MODE_4_BIT_PIN0,GET_BIT(Copy_u8Data,3));
		 MCAL_DIO_u8_SetPinValue(CLCD_DATA_PORT,CLCD_MODE_4_BIT_PIN1,GET_BIT(Copy_u8Data,2));
		 MCAL_DIO_u8_SetPinValue(CLCD_DATA_PORT,CLCD_MODE_4_BIT_PIN2,GET_BIT(Copy_u8Data,1));
		 MCAL_DIO_u8_SetPinValue(CLCD_DATA_PORT,CLCD_MODE_4_BIT_PIN3,GET_BIT(Copy_u8Data,0));

		 MCAL_DIO_u8_SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,PIN_HIGH);
		 _delay_ms (2);
		 MCAL_DIO_u8_SetPinValue (CLCD_CTRL_PORT,CLCD_E_PIN,PIN_LOW);

#else
#error "WRONG IN SEND DATA"
#endif

}
void HAL_CLCD_void_Init (void)
{
#if CLCD_MODE==MODE_8_BIT
	_delay_ms (40);
#elif CLCD_MODE==MODE_4_BIT
	_delay_ms (40);
//set the register select to zero to active command mode
 MCAL_DIO_u8_SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,PIN_LOW);
 //set RW to zero to active the effect command on the lcd
 MCAL_DIO_u8_SetPinValue (CLCD_CTRL_PORT,CLCD_RW_PIN,PIN_LOW);
 //put command on the command port

MCAL_DIO_u8_SetPinValue(CLCD_DATA_PORT,CLCD_MODE_4_BIT_PIN0,0);
MCAL_DIO_u8_SetPinValue(CLCD_DATA_PORT,CLCD_MODE_4_BIT_PIN1,0);
MCAL_DIO_u8_SetPinValue(CLCD_DATA_PORT,CLCD_MODE_4_BIT_PIN2,1);
MCAL_DIO_u8_SetPinValue(CLCD_DATA_PORT,CLCD_MODE_4_BIT_PIN3,0);

MCAL_DIO_u8_SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,PIN_HIGH);
_delay_ms (2);
MCAL_DIO_u8_SetPinValue (CLCD_CTRL_PORT,CLCD_E_PIN,PIN_LOW);
#else
#error "WRONG IN INITIALIZATION"
#endif

	// wait for more than 30 ms

	//function set Set command 2lines , font =5*7
HAL_CLCD_void_SendCommand(0b00000010);
_delay_ms (40);

HAL_CLCD_void_SendCommand(0b00101000);
_delay_us(45);
HAL_CLCD_void_SendCommand(0b00001100);
_delay_us(45);
HAL_CLCD_void_SendCommand(0b00000110);
_delay_us(45);
HAL_CLCD_void_SendCommand(1);
_delay_ms(2);

	//HAL_CLCD_void_SendCommand(0b00000110);





}


void HAL_CLCD_void_SendString(const char * Copy_phString )
{
   u8 Local_LoopCounter;
   for (Local_LoopCounter=0;(*(Copy_phString+Local_LoopCounter))!=0;Local_LoopCounter++)
   {
	   HAL_CLCD_void_SendData(*(Copy_phString+Local_LoopCounter));

   }
}
void HAL_CLCD_void_SendNumber (u32 Copy_u32Number)
{
	u8 Local_u8Counter=0;
	u8 Local_u8Counter1=0;
	u8 Local_u8Counter3 ;
	u32 Local_u8Temp =Copy_u32Number;
	u32 Local_u8Temp2 =Copy_u32Number;
	u32 Local_u8result;
	do {
		Local_u8Temp /=10 ;
		Local_u8Counter++;
}while(Local_u8Temp !=0);
	Local_u8Counter3 =Local_u8Counter;
for (Local_u8Counter1 =0;Local_u8Counter1<Local_u8Counter;Local_u8Counter1++)
{
do
{
	Local_u8result =Local_u8Temp2 %10;
	Local_u8Temp2 /=10 ;
	Local_u8Counter3--;
}
while (Local_u8Counter3>Local_u8Counter1);
Local_u8Counter3 = Local_u8Counter;
Local_u8Temp2 =Copy_u32Number;
HAL_CLCD_void_SendData('0'+Local_u8result);

}

}


void HAL_CLCD_void_GotoXY (u8 Copy_u8PosX ,u8 Copy_u8PosY)
{

	u8 Local_u8DDRAMAddress ;

	if (Copy_u8PosY == 0)
	{
		Local_u8DDRAMAddress =Copy_u8PosX;
	}
	else
	{
		Local_u8DDRAMAddress =Copy_u8PosX;
	}

	HAL_CLCD_void_SendCommand(Local_u8DDRAMAddress +128);
}







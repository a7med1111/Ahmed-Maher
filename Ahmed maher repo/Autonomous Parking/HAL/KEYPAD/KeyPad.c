

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "KeyPad_Cfg.h"
#include "KeyPad_interface.h"
#include "KeyPad_private.h"

u8 HALL_KPD_u8GetPressedKey(u8* Copy_pu8_pressedkey)
{
	 u8 Local_u8ErrorState = OK;
	u8 Local_u8PressedKey = KPD_NO_PRESSED_KEY,Local_u8ColumnIdx,Local_u8RowIdx,Local_u8PinState;

	static u8 Local_u8KPDArr[ROW_NUM][COLUMN_NUM]= KPD_ARR_VAL;
	static u8 Local_u8KPDColumnArr[COLUMN_NUM]={KPD_COLUMN0_PIN,KPD_COLUMN1_PIN,KPD_COLUMN2_PIN,KPD_COLUMN3_PIN};
	static u8 Local_u8KPDRowArr[ROW_NUM]={KPD_ROW0_PIN,KPD_ROW1_PIN,KPD_ROW2_PIN,KPD_ROW3_PIN};

	for(Local_u8ColumnIdx=0;Local_u8ColumnIdx<COLUMN_NUM;Local_u8ColumnIdx++)
	{
		//Activate current column
		Local_u8ErrorState |= MCAL_DIO_u8_SetPinValue(KPDCOL_PORT,Local_u8KPDColumnArr[Local_u8ColumnIdx],PIN_LOW	);
		if(Local_u8ErrorState !=OK)
		{
			break;
		}
		else{

		for(Local_u8RowIdx=0;Local_u8RowIdx<COLUMN_NUM;Local_u8RowIdx++)
		{
			//Read current row
			Local_u8ErrorState |= MCAL_DIO_u8_GetPinValue(KPDROW_PORT,Local_u8KPDRowArr[Local_u8RowIdx],&Local_u8PinState);

			//check if switch is pressed
			if (Local_u8PinState == PIN_LOW)
			{
				Local_u8PressedKey=Local_u8KPDArr[Local_u8RowIdx][Local_u8ColumnIdx];

				while(Local_u8PinState == PIN_LOW)
				{
					Local_u8ErrorState |= MCAL_DIO_u8_GetPinValue(KPDROW_PORT,Local_u8KPDRowArr[Local_u8RowIdx],&Local_u8PinState);
				}
				*Copy_pu8_pressedkey = Local_u8PressedKey;
			}
		}
		Local_u8ErrorState |= MCAL_DIO_u8_SetPinValue(KPDCOL_PORT,Local_u8KPDColumnArr[Local_u8ColumnIdx],PIN_HIGH);
		}
	}

	return Local_u8ErrorState;
}


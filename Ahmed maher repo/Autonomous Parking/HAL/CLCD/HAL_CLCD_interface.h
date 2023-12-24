


/*preprocessor file guard */

#ifndef HAL_CLCD_INTERFACE_H_
#define HAL_CLCD_INTERFACE_H_

/*
#define X_POS  	7
#define Y_POS	0*/


// function to send the command to the lcd
void HAL_CLCD_void_SendCommand (u8 Copy_u8Command);

//function to send the data to the lcd
void HAL_CLCD_void_SendData (u8 Copy_u8Data);

//function to initilaize mode of the lcd
void HAL_CLCD_void_Init (void);

// function to send string to the lcd
void HAL_CLCD_void_SendString(const char * Copy_phString );
// function to send number to the lcd
void HAL_CLCD_void_SendNumber (u32 Copy_u32Number);
// function to go to specific location in the lcd
void HAL_CLCD_void_GotoXY (u8 Copy_u8PosX ,u8 Copy_u8PosY);


#endif

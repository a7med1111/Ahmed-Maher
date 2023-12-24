/********************		Author: HEX CLAN    	**************/
/********************		Layer: MCAL				**************/
/********************		SWC: USART				**************/
/********************		Version: 2.1			**************/
/********************		Date: 6-11-2023			**************/
/*****************************************************************/
/*****************************************************************/
#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

// Function to initialize the USART communication
void USART_voidInit(void);

// Function to send a single byte of data over USART
void USART_voidSend(u8 Copy_u8data);

// Function to receive a single byte of data from USART
u8 USART_u8Receive(void);

// Function to set a callback function for handling received data (used with interrupts)
void USART_voidRecieveSetCallBack(void (*Copy_pvRecieveFunc)(u8 copy_u8received));

// Function to send a string over USART
void USART_voidSendString(u8 *str);

// Function to receive a string until a newline character and store it in 'str'
void UARTGetString(u8 *str);

// Function to send a single-digit number (0-9) over USART
void UART_voidSendSingleNumber(u8 Copy_u8number);

// Function to send a multi-digit number (32-bit) over USART
void UART_voidSendNumber(u32 Copy_u8number);

#endif

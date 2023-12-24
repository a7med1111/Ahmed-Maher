/********************		Author: HEX CLAN    	**************/
/********************		Layer: MCAL				**************/
/********************		SWC: USART				**************/
/********************		Version: 2.1			**************/
/********************		Date: 6-11-2023			**************/
/*****************************************************************/
/*****************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_register.h"
#include "USART_interface.h"
#include "USART_config.h"

/* Global pointer to function to hold receive ISR address */
void (*USART_pvReceiveFunc)(u8 copy_u8received) = NULL;

void USART_voidInit(void)
{
    if (INTERRUPT == UART_WITH_INTERRUPT)
    {
        u8 Local_u8UCSRCValue = 0;
        /* Enable interrupt for Receive Complete */
        SET_BIT(UCSRB, UCSR_B_RXCIE);
        /* Enable interrupt for transmit Complete (currently commented out) */

        // We cannot use get and set bit with UCSRC, so we will create a variable for it.

        // To use UCSRC
        SET_BIT(Local_u8UCSRCValue, UCSRC_URSEL);

        // Set to 8-bit data for both send and receive
        CLR_BIT(UCSRB, UCSR_B_UCSZ2);
        SET_BIT(Local_u8UCSRCValue, UCSRC_UCSZ1);
        SET_BIT(Local_u8UCSRCValue, UCSRC_UCSZ0);

        /* Mode select:
           1 - Synchronous
           2 - Asynchronous
           Here, it's set to Asynchronous */
        CLR_BIT(Local_u8UCSRCValue, UCSRC_UMSEL);

        // Set the value in UCSRC
        UCSRC = Local_u8UCSRCValue;

        // Baud rate set to 9600 with a system clock of 8MHz
        UBRRL = UART_BOUDRATE;

        // Enable pins for receive and transmit
        SET_BIT(UCSRB, UCSR_B_TXEN);
        SET_BIT(UCSRB, UCSR_B_RXEN);
    }
    else if (INTERRUPT == UART_WITHOUT_INTERRUPT)
    {
        // We cannot use set bit or clear bit here because it must happen at the same time, so we create a variable.
        u8 Local_u8UCSRCValue = 0;
        SET_BIT(Local_u8UCSRCValue, UCSRC_URSEL); // To use UCSRC
        // Set to 8-bit data for both send and receive
        CLR_BIT(UCSRB, UCSR_B_UCSZ2);
        SET_BIT(Local_u8UCSRCValue, UCSRC_UCSZ1);
        SET_BIT(Local_u8UCSRCValue, UCSRC_UCSZ0);
        // Set the value in UCSRC
        UCSRC = Local_u8UCSRCValue;
        // Baud rate set to 9600 with a system clock of 8MHz
        UBRRL = UART_BOUDRATE;
        // Enable transmit and receive
        SET_BIT(UCSRB, UCSR_B_TXEN); // Transmit enable
        SET_BIT(UCSRB, UCSR_B_RXEN); // Receive enable
    }
}

// Function to receive data (8-bit)
u8 USART_u8Receive(void)
{
    // Wait until the receive buffer is not empty (data is received)
    while (GET_BIT(UCSRA, UCSRA_RXC) == 0);
    // Return the received data
    return UDR;
}

void USART_voidSend(u8 Copy_u8data)
{
    // Wait until the transmit buffer is empty (ready to send)
    while (GET_BIT(UCSRA, UCSRA_UDRE) == 0);
    UDR = Copy_u8data; // Transmit data
}

void UART_voidSendSingleNumber(u8 Copy_u8number)
{
    // Send the corresponding character for the given number
    switch (Copy_u8number)
    {
    case 0: USART_voidSend('0'); break;
    case 1: USART_voidSend('1'); break;
    case 2: USART_voidSend('2'); break;
    case 3: USART_voidSend('3'); break;
    case 4: USART_voidSend('4'); break;
    case 5: USART_voidSend('5'); break;
    case 6: USART_voidSend('6'); break;
    case 7: USART_voidSend('7'); break;
    case 8: USART_voidSend('8'); break;
    case 9: USART_voidSend('9'); break;
    }
}

void UART_voidSendNumber(u32 Copy_u8number)
{
    if (Copy_u8number < 10)
    {
        UART_voidSendSingleNumber(Copy_u8number);
    }
    else
    {
        UART_voidSendNumber(Copy_u8number / 10);
        UART_voidSendSingleNumber(Copy_u8number % 10);
    }
}

// Send a string
void USART_voidSendString(u8 *str)
{
    u8 i;
    for (i = 0; i < 100; i++)
    {
        if (*(str + i) == '\0')
        {
            break;
        }
        USART_voidSend(*(str + i));
    }
}

// Get a string
void UARTGetString(u8 *str)
{
    u8 i = 0;
    str[i] = USART_u8Receive();
    while (str[i] != '\n')
    {
        i++;
        str[i] = USART_u8Receive();
    }
    str[i] = '\0';
}

/* Part of interrupt */

void USART_voidRecieveSetCallBack(void (*Copy_pvRecieveFunc)(u8 copy_u8received))
{
    if (Copy_pvRecieveFunc != NULL)
    {
        USART_pvReceiveFunc = Copy_pvRecieveFunc;
    }
    else
    {
        /* Do nothing */
    }
}

// USART Receive Interrupt Service Routine
void __vector_13(void) __attribute__((signal));
void __vector_13(void)
{
    if (USART_pvReceiveFunc != NULL)
    {
        // Call the callback function and pass the received data
        USART_pvReceiveFunc(UDR);
    }
    else
    {
        /* Do nothing */
    }
}

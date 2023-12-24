#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>

#include "ULTRASONIC_interface.h"
#include "ULTRASONIC_config.h"
#include "ULTRASONIC_private.h"

#include "DIO_interface.h"
#include "TIMER_interface.h"

u8 flag = 0; // Flag to detect rising or falling edge
u32 ontime = 0; // Time duration between rising and falling edges
u32 rising = 0; // Time at the rising edge
u8 ticktime = 32; // Time increment in microseconds

void Capture() // Interrupt Service Routine (ISR) for input capture interrupt
{
    if (flag == 0) // If a rising edge is detected
    {
        flag = 1; // Set the flag to 1
        TIMER1_voidSetTimerValue(0); // Reset the timer1 counter
        TIMER1_voidSetCompMatchTopValue(0);
        rising = ICU_voidGetValue(); // Record the time at the rising edge
        ICU_voidSetTriggerEdge(FALLING_EDGE); // Set input capture edge select to falling edge
    }
    else // If a falling edge is detected
    {
        flag = 0; // Set the flag to 0
        ontime = (ICU_voidGetValue() - rising) * ticktime; // Calculate the time duration between rising and falling edges
        ICU_voidSetTriggerEdge(RISING_EDGE); // Set input capture edge select to rising edge for the next measurement
    }
}

void ultrasonic_init() {
    TIMER1_voidInit(); // Initialize Timer1
    ICU_voidInit(); // Initialize Input Capture Unit
    ICU_u8SetCallBack(Capture); // Set the callback function to handle input capture events
}

void ultrasonic_triger(u8 Copy_Ultrasonic_Type) {
    MCAL_DIO_u8_SetPinValue(Copy_Ultrasoic_Port, Copy_Ultrasonic_Type, PIN_HIGH); // Trigger the ultrasonic sensor by setting a pin high
    _delay_us(15); // Delay for 15 microseconds
    MCAL_DIO_u8_SetPinValue(Copy_Ultrasoic_Port, Copy_Ultrasonic_Type, PIN_LOW); // Reset the trigger pin
}

void ultrasonic_Distance_Value(u32 *Copy_Value) {
    *Copy_Value = ontime * 343 / 20000; // Calculate the distance value using the speed of sound
}

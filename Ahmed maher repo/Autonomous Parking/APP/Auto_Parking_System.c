/*
 * File:     Auto_Parking_System.c
 * Author:   Hex Clan
 /* Date:     7/11/2023
 *	version:  1.0
 *
 * Description:
 * This C code is the application of [auto parking system project].
 *
 */


#include "STD_TYPES.h" // Include the header file for standard data types
#include "BIT_MATH.h" // Include the header file for bit manipulation functions
#include "DIO_interface.h" // Include the header file for digital input/output interface
#include "TIMER_interface.h" // Include the header file for timer interface
#include "USART_interface.h" // Include the header file for USART interface
#include "ULTRASONIC_interface.h" // Include the header file for ultrasonic sensor interface
#include "MOTOR__Interface.h" // Include the header file for motor interface
#include "util/delay.h" // Include the header file for delay functions

#define PARK_MAX_WIDTH            80 // Define the maximum width of the parking space in cm
#define PARK_MIN_WIDTH            30 // Define the minimum width of the parking space in cm

#define WALL_MAX            10 // Define the maximum distance from the wall in cm


volatile u32 pDistance = 0,ppDistance = 0,cDistance = 0,test =0;
volatile u32 B_Distance=0;
u8 possibleDistance = 1, parkingSpace = 0,startParking = 0,confirmChar = 0; // Declare and initialize some global variables for storing the distances and flags
// Declare and initialize a global variable for indicating the start of parking

MOTOR_t m1 = {PIN0, PIN1, TIMER0, 200};
MOTOR_t m2 = {PIN2, PIN3, TIMER0, 200};
void measureTime(void);

void Forward_Car(void)
{
    // Make both motors rotate in the counter-clockwise (CCW) direction to move the car forward
	MOTOR_vd_CCW(&m1);
	MOTOR_vd_CCW(&m2);
}

void stop_Car(void)
{
    // Stop both motors to halt the car

    MOTOR_vd_stop(&m1);
    MOTOR_vd_stop(&m2);

}
void Backward_Car(void)
{
    // Make both motors rotate in the clockwise (CW) direction to move the car backward
    MOTOR_vd_CW(&m1);
    MOTOR_vd_CW(&m2);

}
void Right_Forward_Car(void)
{
    // Stop m1
    MOTOR_vd_stop(&m1);
    // Make m2 rotate in the counter-clockwise (CCW) direction
    MOTOR_vd_CCW(&m2);

}
void Left_Forward_Car(void)
{
    // Make m1 rotate in the counter-clockwise (CCW) direction
    MOTOR_vd_CCW(&m1);
    // Stop m2
    MOTOR_vd_stop(&m2);

}
void Right_Backward_Car(void)
{
    // Make m1 rotate in the clockwise (CW) direction
    MOTOR_vd_CW(&m1);
    // Stop m2
    MOTOR_vd_stop(&m2);

}
void Left_Backward_Car(void)
{
    // Make m1 rotate in the clockwise (CW) direction
    MOTOR_vd_CW(&m1);
    // Stop m2
    MOTOR_vd_stop(&m2);

}
void startparking(void){
	confirmChar = 'p';
// Make m1 rotate in the clockwise (CW) direction
            Right_Backward_Car();
        	_delay_ms(500);
        	stop_Car();
        	_delay_ms(480);
        	// Make both motors rotate in the clockwise (CW) direction
        	while(1){
        		ultrasonic_triger(Ultrasonic0); // Trigger the ultrasonic sensor 0
        	    ultrasonic_Distance_Value(&B_Distance); // Get the distance value from the sensor 0 and store it in ppDistance
                Backward_Car();
        		USART_voidSendNumber(B_Distance);
        		if(B_Distance<=17)
        			break;

        	}
        	USART_voidSendString("DONE ");
            stop_Car();
        	 _delay_ms(500);
            Right_Forward_Car();
         	_delay_ms(505);
             stop_Car();
        	USART_voidSendString("COMPLETE ");

}
//
void Control_Car_with_Bluetooth(u8 data) {
    MOTOR_t m1 = {PIN0, PIN1, TIMER0, 200};  // motor speed
    MOTOR_t m2 = {PIN2, PIN3, TIMER0, 200};

    switch (data) {
        case 'w':
            // Move forward
            Forward_Car();
            break;

        case 'a':
            // Move left F
            Left_Forward_Car();
            break;

        case 'd':
            // Move right F
            Right_Forward_Car();
            break;

        case 's':
            // Move backward
            Backward_Car();
            break;

        case 'e':
            // Move right B
            Right_Backward_Car();
            break;
        case 'q':
        	// Move left B
            Left_Backward_Car();
        	break;
//        case 'y': // Parking car
//        	startparking();
//        	break;
        case 'x':
            // Stop both motors
            stop_Car();

            break;
    }
}

void main(void)
{

	GIE_voidEnableGlobal(); // Enable the global interrupt
	// Initialize the pins and ports
	MCAL_DIO_u8_SetPortDirection( PORTA_ID,PORT_OUTPUT);
	MCAL_DIO_u8_SetPortDirection( PORTB_ID,PORT_OUTPUT);
	MCAL_DIO_u8_SetPortDirection( PORTC_ID,PORT_OUTPUT);
	MCAL_DIO_u8_SetPinDirection( PORTD_ID,PIN7,PIN_OUTPUT);
	MCAL_DIO_u8_SetPinDirection( PORTD_ID,PIN1,PIN_OUTPUT);  //tx
	MCAL_DIO_u8_SetPinDirection( PORTD_ID,PIN0,PIN_INPUT);	//rx
	MCAL_DIO_u8_SetPinValue(PORTD_ID,PIN0,PIN_HIGH);
	MCAL_DIO_u8_SetPinValue(PORTA_ID,PIN4,PIN_HIGH);
	MCAL_DIO_u8_SetPinDirection(PORTD_ID,PIN6,PIN_INPUT); //icu


	USART_voidInit(); // Initialize the USART module
	ultrasonic_init(); // Initialize the ultrasonic sensor module
	USART_voidRecieveSetCallBack(&Control_Car_with_Bluetooth);
	TIMER0_voidInit();
	TIMER2_u8OVFSetCallBack(&measureTime); // Set the timer 2 overflow callback function to measureTime
	TIMER2_voidInit(); // Initialize the timer 2 module
	TIMER2_voidInterruptDisable();



	while(1) // Start an infinite loop
	{
		USART_voidSendString("Starting"); // Send a string to the user via USART
		//		USART_voidSendString("press 'm' to start APS"); // Send a string to the user via USART
		USART_voidSendString("WALL:  ");
		ultrasonic_triger(Ultrasonic1);
		ultrasonic_Distance_Value(&test);
		USART_voidSendNumber(test);
		//		if(USART_u8Receive() == 'm') // Check if the user has pressed 'm'
		//		{
		//	_delay_ms(2000);
		USART_voidSendString("ok");
		while(possibleDistance) // Start a loop while there is a possible distance
		{
			 // Move the car forward
			ultrasonic_triger(Ultrasonic1); // Trigger the ultrasonic sensor 1
			ultrasonic_Distance_Value(&cDistance); // Get the distance value from the sensor 1 and store it in ppDistance
			USART_voidSendString("cD");
			USART_voidSendNumber(cDistance);
			_delay_ms(1); // Wait for 5 milliseconds
			if(cDistance < PARK_MAX_WIDTH && cDistance > PARK_MIN_WIDTH)
			{
				USART_voidSendString("StartDetected");
				possibleDistance = 0; // Set the possible distance flag to 0
				TIMER2_voidSetTimerValue(56);//Set preload Value
				TIMER2_voidInterruptEnable();
			}
			else
			{
				/*Do Nothing*/
			}
		}
		while(parkingSpace) // Start a loop while there is a parking space
		{
			//TIMER2_voidInterruptDisable();
			stop_Car(); // Stop the car
			USART_voidSendString("Confirm This parking space press 'y' or press 'n' to find another spot"); // Send a string to the user via USART
			confirmChar =USART_u8Receive();
			if (confirmChar == 'y') // Check if the user has pressed 'y'
			{
				//TIMER2_voidInterruptDisable();
				//possibleDistance=0;
				USART_voidSendString("yes "); // Send a string to the user via USART
				startParking = 1; // Set the start parking flag to 1
				parkingSpace = 0;
			}
			else if(confirmChar == 'n') // Check if the user has pressed 'n'
			{
				USART_voidSendString("no "); // Send a string to the user via USART
				possibleDistance = 1; // Set the possible distance flag to 1
				parkingSpace = 0;
			}
			else
			{
				/*Do Nothing*/
			}
			while(startParking==1)
			{
				confirmChar = 'k';
				startparking();
				startParking = 0;
			}


		}

	}

}

void measureTime(void) // Define a function to measure the time
{
	USART_voidSendString("InTIMER  ");
	static counter = 0; // Declare and initialize a static variable for counting the timer 2 overflows
	counter++; // Increment the counter
	TIMER2_voidSetTimerValue(56); // Set the timer 2 value to 56
	ultrasonic_triger(Ultrasonic1); // Trigger the ultrasonic sensor 1
	ultrasonic_Distance_Value(&cDistance); // Get the distance value from the sensor 1 and store it in cDistance
	if(cDistance < WALL_MAX) // Check if the current distance is less than the maximum distance from the wall
	{
		parkingSpace = 0; // Set the parking space flag to 0
		possibleDistance = 1; // Set the possible distance flag to 1
		counter = 0; // Reset the counter
	}
	else
	{
		/*Do nothing*/
	}
	if(counter == 75) // Check if the counter has reached 39
	{
		USART_voidSendString("TimerDone");
		counter = 0; // Reset the counter
		possibleDistance = 0;
		parkingSpace = 1; // Set the parking space flag to 1
		TIMER2_voidInterruptDisable();
	}
	else
	{
		/*Do Nothing*/
	}
}

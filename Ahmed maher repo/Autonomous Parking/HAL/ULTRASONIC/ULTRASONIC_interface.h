#ifndef ULTRASONIC_INTERFACE_H_
#define ULTRASONIC_INTERFACE_H_

// Define symbolic names for ultrasonic sensor pins
#define Ultrasonic0 PIN0
#define Ultrasonic1 PIN1
#define Ultrasonic2 PIN2
#define Ultrasonic3 PIN3

// Function to initialize the ultrasonic sensor
void ultrasonic_init(void);

// Function to trigger the ultrasonic sensor for distance measurement
void ultrasonic_triger(u8 Copy_Ultrasonic_Type);

// Function to get the distance value measured by the ultrasonic sensor
void ultrasonic_Distance_Value(u32* Copy_Value);

#endif

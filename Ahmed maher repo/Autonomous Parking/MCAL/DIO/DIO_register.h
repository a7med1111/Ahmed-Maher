

#ifndef DIO_REGISTER_H_
#define DIO_REGISTER_H_





typedef union PORT_Union{
volatile u8 Register;

 struct BitField {
	volatile	u8 PIN_0:1;
	volatile	u8 PIN_1:1;
	volatile	u8 PIN_2:1;
	volatile	u8 PIN_3:1;
	volatile	u8 PIN_4:1;
	volatile	u8 PIN_5:1;
	volatile	u8 PIN_6:1;
	volatile	u8 PIN_7:1;
	}BitField;
}PORT_Union;






#define PORTA 		*((volatile u8*)0x3b)
#define DDRA 		*((volatile u8*)0x3a)
#define PINA 		*((volatile u8*)0x39)

#define PORTB 		*((volatile u8*)0x38)
#define DDRB 		*((volatile u8*)0x37)
#define PINB 		*((volatile u8*)0x36)

#define PORTC 		*((volatile u8*)0x35)
#define DDRC 		*((volatile u8*)0x34)
#define PINC 		*((volatile u8*)0x33)

#define PORTD 		*((volatile u8*)0x32)
#define DDRD 		*((volatile u8*)0x31)
#define PIND 		*((volatile u8*)0x30)

#endif


#include"STD_TYPES.h"

#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H

/**********************************  ICU Enable/Disable  ******************************/
/*******  options for TIMER1_voidIcuMode  *******/
#define ENABLE				1
#define DISABLE				2

/***********************************  ICU Edge Mode  **********************************/
/*******  options for TIMER1_voidIcSetEdge  *******/
#define FALLING_EDGE		1
#define RISING_EDGE			2

/*******************************WatchDog  Selection****************************/
/*******  options WatchDog Sleep time  *******/
#define T16p3MS						0			/****  TimeOut = 16.3ms   *****/
#define T32p5MS						1           /****  TimeOut = 32.5ms   *****/
#define T65MS						2           /****  TimeOut = 65ms   *****/
#define T0p13S						3           /****  TimeOut = 0.13s   *****/
#define T0p26S						4           /****  TimeOut = 0.26s   *****/
#define T0p52S						5           /****  TimeOut = 0.52s   *****/
#define T1S							6           /****  TimeOut = 1s   *****/
#define T2p1S						7           /****  TimeOut = 2.1s   *****/



/**********************************  TIMER 0 Functions  *******************************/
void TIMER0_voidInit(void);
void TIMER0_voidSetCompMatchValue(u8 Copy_u8Value);
void TIMER0_voidSetTimerValue(u8 Copy_u8Value);
u8 TIMER0_u8OVFSetCallBack(void (*Copy_pvTimer0OVFFunc)(void));
u8 TIMER0_u8CompSetCallBack(void (*Copy_pvTimer0CompFunc)(void));

/**********************************  TIMER 1 Functions  *******************************/
void TIMER1_voidInit(void);
void TIMER1_voidSetTimerValue(u16 Copy_u16Value);
u16  TIMER1_voidGetTimerValue(void);
void TIMER1_voidSetCompMatchAValue(u8 Copy_u8Value);
void TIMER1_voidSetCompMatchBValue(u8 Copy_u8Value);
void TIMER1_voidSetCompMatchTopValue(u8 Copy_u8Value);
u8 TIMER1_u8OVFSetCallBack(void (*Copy_pvTimerOVFFunc)(void));
u8 TIMER1_u8CompASetCallBack(void (*Copy_pvTimerCompFunc)(void));
u8 TIMER1_u8CompBSetCallBack(void (*Copy_pvTimerCompFunc)(void));
/**********************************  ICU functions  ***********************************/
void ICU_voidInit(void);
u8 ICU_voidSetTriggerEdge(u8 Copy_u8Edge);
u8 ICU_voidInterruptMode(u8 Copy_u8Mode);
u16 ICU_voidGetValue(void);
u8 ICU_u8SetCallBack(void (*Copy_pvTimer1IcuFunc)(void));

/**********************************  TIMER 2 Functions  *******************************/
void TIMER2_init(void);
void TIMER2_voidSetCompMatchValue(u8 Copy_u8Value);
void TIMER2_voidSetTimerValue(u8 Copy_u8Value);
u8 TIMER2_u8OVFSetCallBack(void (*Copy_pvTimerOVFFunc)(void));
u8 TIMER2_u8CompSetCallBack(void (*Copy_pvTimer2CompFunc)(void));


/**********************************  WatchDog Functions  ******************************/

u8  WTD_voidSleep(u8 Copy_u8WDValue);
void WTD_voidDisable(void);

#endif

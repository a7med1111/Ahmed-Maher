#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef unsigned char  u8 ;
typedef signed char s8 ;

typedef unsigned short int u16 ;
typedef unsigned long int u32 ;

typedef signed short int s16 ;
typedef signed long int s32 ;

typedef float f32 ;

typedef double f64 ;
typedef long double f80 ;

#define OK 					0
#define NOK 				1
#define TIMEOUT_STATE 		1
#define BUSY_STATE 			2
#define NULL_POINTER	    3

#define STD_HIGH        0x01U       /* Standard HIGH */
#define STD_LOW         0x00U       /* Standard LOW */

#define NULL				 2
#define NULL_PTR          ((void *)0)
#endif

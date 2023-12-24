/*
 * GIE_program.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: AHMED
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "GIE_interface.h"

#define SREG    *((volatile u8*)0x5F)

void MCAL_GIE_voidGlobalInterruptEnable(void)
{
	SET_BIT(SREG,7);
}

void MCAL_GIE_voidGlobalInterruptDisable(void)
{
	CLR_BIT(SREG,7);
}



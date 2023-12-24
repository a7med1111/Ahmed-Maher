

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "EXTINT_interface.h"
#include "EXTINT_private.h"

#include "EXTINT_reg.h"


//Global Pointer to function

static void (*EXTINT_ApfuncEXTINT[3])(void);

void MCAL_EXTINT_voidEnable(u8 Copy_u8ExtIntNum , u8 Copy_u8EdgeIntSource)
{
	switch(Copy_u8ExtIntNum)
	{
	case EXTINT_INT0:
		switch(Copy_u8EdgeIntSource)
		{
		case EXTINT_ANY_LOGICAL_CHANGE:
			CLR_BIT(MCUCR,MCUCR_ISC01);
			SET_BIT(MCUCR,MCUCR_ISC00);
			break;
		case EXTINT_FALLING_EDGE:
			SET_BIT(MCUCR,MCUCR_ISC01);
			CLR_BIT(MCUCR,MCUCR_ISC00);
			break;
		case EXTINT_RAISING_EDGE:
			SET_BIT(MCUCR,MCUCR_ISC01);
			SET_BIT(MCUCR,MCUCR_ISC00);
			break;
		case EXTINT_LOW_LEVEL:
			CLR_BIT(MCUCR,MCUCR_ISC01);
			CLR_BIT(MCUCR,MCUCR_ISC00);
			break;
		}
		/* Enable Ext Int 0 */
		SET_BIT(GICR,GICR_INT0);
		break;
		case EXTINT_INT1:
			switch(Copy_u8EdgeIntSource)
			{
			case EXTINT_ANY_LOGICAL_CHANGE:
				CLR_BIT(MCUCR,MCUCR_ISC11);
				SET_BIT(MCUCR,MCUCR_ISC10);

				break;
			case EXTINT_FALLING_EDGE:
				SET_BIT(MCUCR,MCUCR_ISC11);
				CLR_BIT(MCUCR,MCUCR_ISC10);
				break;
			case EXTINT_RAISING_EDGE:
				SET_BIT(MCUCR,MCUCR_ISC11);
				SET_BIT(MCUCR,MCUCR_ISC10);
				break;
			case EXTINT_LOW_LEVEL:
				CLR_BIT(MCUCR,MCUCR_ISC11);
				CLR_BIT(MCUCR,MCUCR_ISC10);
				break;
			}
			/* Enable Ext Int 1 */
			SET_BIT(GICR,GICR_INT1);
			break;
			case EXTINT_INT2:
				switch(Copy_u8EdgeIntSource)
				{
				case EXTINT_FALLING_EDGE:
					CLR_BIT(MCUCSR,MCUCSR_ISC2);
					break;
				case EXTINT_RAISING_EDGE:
					SET_BIT(MCUCSR,MCUCSR_ISC2);
					break;
				}
				/* Enable Ext Int 2 */
				SET_BIT(GICR,GICR_INT2);
				break;


	}
}

void MCAL_EXTINT_voidDisable(u8 Copy_u8ExtIntNum)
{
	switch (Copy_u8ExtIntNum)
	{
	case EXTINT_INT0:
		CLR_BIT(GICR,GICR_INT0);
		break;
	case EXTINT_INT1:
		CLR_BIT(GICR,GICR_INT1);
		break;
	case EXTINT_INT2:
		CLR_BIT(GICR,GICR_INT2);
		break;
	}
}

void	(void(*Copy_pfun)(void),u8 Copy_u8ExtIntIndex)
{
	EXTINT_ApfuncEXTINT[Copy_u8ExtIntIndex] = Copy_pfun;
}

/* ISR Function for External Interrupt 0 */
void __vector_1(void)  __attribute__((signal));
void __vector_1(void)
{
	EXTINT_ApfuncEXTINT[EXTINT_INT0]();
}
/* ISR Function for External Interrupt 0 */
void __vector_2(void)  __attribute__((signal));
void __vector_2(void)
{
	EXTINT_ApfuncEXTINT[EXTINT_INT1]();
}
/* ISR Function for External Interrupt 0 */
void __vector_3(void)  __attribute__((signal));
void __vector_3(void)
{
	EXTINT_ApfuncEXTINT[EXTINT_INT2]();
}







#include "STD_TYPES.h"
#include "BIT_MATH"

void GIE_voidEnableGlobal(void)
{
	SET_BIT(SREG,SREG_I);
}
void GIE_voidDisableGlobal(void)
{
	
	CLR_BIT(SREG,SREG_I);
}
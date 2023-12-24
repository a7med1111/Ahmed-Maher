/*
 * EXTINT_reg.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: AHMED
 */

#ifndef EXTERNAL_INTERRUPT_EXTINT_REG_H_
#define EXTERNAL_INTERRUPT_EXTINT_REG_H_
#define MCUCR     *((volatile u8*)0x55)
#define MCUCSR    *((volatile u8*)0x54)
#define GICR      *((volatile u8*)0x5B)
#define GIFR      *((volatile u8*)0x5A)


#endif /* EXTERNAL_INTERRUPT_EXTINT_REG_H_ */

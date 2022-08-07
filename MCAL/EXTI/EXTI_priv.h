/*
 * EXTI_priv.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Nader
 */

#ifndef MCAL_EXTI_EXTI_PRIV_H_
#define MCAL_EXTI_EXTI_PRIV_H_

#define EXTI0			0
#define EXTI1			1
#define EXTI2			2

#define low_level		11
#define any_logical 	12
#define rising_edge		13
#define falling_edge	14

#define enabled			15
#define pooling			16

#define MCUCR		*((volatile u8*)0x55)      // interrupt 0,1 status
#define MCUCSR		*((volatile u8*)0x54)      // interrupt 2   status
#define GICR		*((volatile u8*)0x5B)      // Peripheral interrupt control enable  int1,int0,int2
#define GIFR		*((volatile u8*)0x5A)      // interrupt flag enable

#endif /* MCAL_EXTI_EXTI_PRIV_H_ */

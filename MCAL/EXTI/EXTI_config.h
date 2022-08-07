/*
 * EXTU_confige.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Nader
 */

#ifndef MCAL_EXTI_EXTI_CONFIG_H_
#define MCAL_EXTI_EXTI_CONFIG_H_

#define intr_num    1


typedef struct{

u8 EXTI_pin;
u8 EXTI_mode;
u8 EXTI_status;

}EXTI_t;

EXTI_t  intr[intr_num];


#endif /* MCAL_EXTI_EXTI_CONFIG_H_ */

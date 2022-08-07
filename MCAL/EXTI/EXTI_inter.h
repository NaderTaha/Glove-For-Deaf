/*
 * EXTI_inter.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Nader
 */

#ifndef MCAL_EXTI_EXTI_INTER_H_
#define MCAL_EXTI_EXTI_INTER_H_


ES_t EXTI_init(EXTI_t *copy_A);
ES_t EXTI_enable(EXTI_t *copy_A);
ES_t EXTI_disable(EXTI_t *copy_A);
ES_t EXTI_statues(EXTI_t *copy_A,u8 status);
ES_t EXTI_mode(EXTI_t *copy_A,u8 mode);

void callback_EXTI0 (void(*ptr_callback)(void));
void callback_EXTI1 (void(*ptr_callback)(void));
void callback_EXTI2 (void(*ptr_callback)(void));

#endif /* MCAL_EXTI_EXTI_INTER_H_ */


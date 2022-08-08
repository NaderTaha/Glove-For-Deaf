/*
 * EXTI_program.c

 *
 *  Created on: ??þ/??þ/????
 *      Author: Nader
 */
#include "../../LIBRARY/stdTypes.h"
#include "../../LIBRARY/errorState.h"

#include "EXTI_config.h"
#include "EXTI_priv.h"

static void(*ptr_globalEXTI[3])(void) = {NULL,NULL,NULL};

ES_t EXTI_init(EXTI_t *copy_A){

u8 error_state = ES_NOK;

if (copy_A != NULL){
	error_state = ES_OK;
	for(u8 i=0;i<intr_num;i++){
		if(copy_A[i].EXTI_pin == EXTI0)
			GICR |= (1<<6);
		else if(copy_A[i].EXTI_pin == EXTI1)
			GICR |= (1<<7);
		else if(copy_A[i].EXTI_pin == EXTI2)
			GICR |= (1<<5);
		else
			{error_state = ES_OUT_OF_RANGE;
			break;}
		if(copy_A[i].EXTI_mode == enabled)
			GIFR |= (1<<6);
		else if(copy_A[i].EXTI_mode == pooling)
			GIFR &=~ (1<<6);
		else
				{error_state = ES_OUT_OF_RANGE;
				break;}
		if(copy_A[i].EXTI_pin == EXTI0 && copy_A[i].EXTI_status == low_level)
			MCUCR &=~ (3<<0);
		else if(copy_A[i].EXTI_pin == EXTI0 && copy_A[i].EXTI_status == any_logical)
			MCUCR |= (1<<0);
		else if(copy_A[i].EXTI_pin == EXTI0 && copy_A[i].EXTI_status == rising_edge)
			MCUCR |= (3<<0);
		else if(copy_A[i].EXTI_pin == EXTI0 && copy_A[i].EXTI_status == falling_edge)
			MCUCR |= (2<<0);
		else
				{error_state = ES_OUT_OF_RANGE;
				break;}

		if(copy_A[i].EXTI_pin == EXTI1 && copy_A[i].EXTI_status == low_level)
			MCUCR &=~ (3<<2);
		else if(copy_A[i].EXTI_pin == EXTI1 && copy_A[i].EXTI_status == any_logical)
			MCUCR |= (1<<2);
		else if(copy_A[i].EXTI_pin == EXTI1 && copy_A[i].EXTI_status == rising_edge)
			MCUCR |= (3<<2);
		else if(copy_A[i].EXTI_pin == EXTI1 && copy_A[i].EXTI_status == falling_edge)
			MCUCR |= (2<<2);
		else
				{error_state = ES_OUT_OF_RANGE;
				break;}

		if(copy_A[i].EXTI_pin == EXTI2 && copy_A[i].EXTI_status == falling_edge)
			MCUCSR &=~ (1<<6);
		else if(copy_A[i].EXTI_pin == EXTI2 && copy_A[i].EXTI_status == rising_edge)
			MCUCSR |= (1<<6);
		else
				{error_state = ES_OUT_OF_RANGE;
				break;}
		}
		}
				return error_state;

}

ES_t EXTI_enable(EXTI_t *copy_A){

	u8 error_state = ES_NOK;
if(copy_A != NULL){
		error_state = ES_OK;
		if(copy_A->EXTI_pin == EXTI0)
			GICR |= (1<<6);
		else if(copy_A->EXTI_pin == EXTI1)
			GICR |= (1<<7);
		else if(copy_A->EXTI_pin == EXTI2)
			GICR |= (1<<5);
		else error_state = ES_OUT_OF_RANGE;
	}
		return error_state;
	}

ES_t EXTI_disable(EXTI_t *copy_A){

	u8 error_state =ES_NOK;
	if(copy_A != NULL){
			error_state = ES_OK;
			if(copy_A->EXTI_pin == EXTI0)
				GICR &=~ (1<<6);
			else if(copy_A->EXTI_pin == EXTI1)
				GICR &=~ (1<<7);
			else if(copy_A->EXTI_pin == EXTI2)
				GICR &=~ (1<<5);
			else error_state = ES_OUT_OF_RANGE;
	}
		return error_state;
	}

ES_t EXTI_statues(EXTI_t *copy_A,u8 status){

	u8 error_state =ES_NOK;
if(copy_A != NULL)
	error_state = ES_OK;
		if(copy_A ->EXTI_pin== EXTI0)
			switch(status){
			case low_level:
				MCUCR &=~ (3<<0);
				break;

			case any_logical:
				MCUCR |= (1<<0);
				break;

			case rising_edge:
				MCUCR |= (3<<0);
				break;

			case falling_edge:
				MCUCR |= (2<<0);
				break;
			default : error_state = ES_OUT_OF_RANGE;
			}
		else if(copy_A ->EXTI_pin== EXTI1)
			switch(status){
			case low_level:
				MCUCR &=~ (3<<2);
				break;

			case any_logical:
				MCUCR |= (1<<2);
				break;

			case rising_edge:
				MCUCR |= (3<<2);
				break;

			case falling_edge:
				MCUCR |= (2<<2);
				break;
			default : error_state = ES_OUT_OF_RANGE;
			}
		else if(copy_A ->EXTI_pin == EXTI2)
			switch(status){

			case rising_edge:
				MCUCSR |= (1<<6);
				break;

			case falling_edge:
				MCUCSR &=~ (1<<6);
				break;
			default : error_state = ES_OUT_OF_RANGE;
			}
			else error_state = ES_OUT_OF_RANGE;

		return error_state;
}
/*ES_t EXTI_mode(EXTI_t *copy_A,u8 mode){

	if(copy_A[i].EXTI_mode == enabled)
			GIFR |= (1<<6);
		else if(copy_A[i].EXTI_mode == pooling)
			GIFR &=~ (1<<6);
		else
				{error_state = ES_OUT_OF_RANGE;
} */

void callback_EXTI0 (void(*ptr_callback)(void)){

		ptr_globalEXTI[0] = ptr_callback;
	}

void callback_EXTI1 (void(*ptr_callback)(void)){

		ptr_globalEXTI[1] = ptr_callback;
	}

void callback_EXTI2 (void(*ptr_callback)(void)){

		ptr_globalEXTI[2] = ptr_callback;
	}

	void __vector_1(void)__attribute__((signal));
	void __vector_2(void)__attribute__((signal));
	void __vector_3(void)__attribute__((signal));

void __vector_1(void){
	if(ptr_globalEXTI[0] != NULL)
	ptr_globalEXTI[0]();
}

void __vector_2(void){
	if(ptr_globalEXTI[1] != NULL)
	ptr_globalEXTI[1]();
}
void __vector_3(void){
	if(ptr_globalEXTI[2] != NULL)
	ptr_globalEXTI[2]();
}


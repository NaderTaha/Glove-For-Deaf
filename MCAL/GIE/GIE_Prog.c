/*
 * GIE_Prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Nader
 */
#include "../../LIBRARY/errorState.h"
#include "../../LIBRARY/stdTypes.h"

#include "GIE_int.h"


ES_t GIE_enuinit(){
	//SREG &= ~ (1<<7);
	asm("CLI");
	return ES_OK;
}
ES_t GIE_enuEnable(){
	//SREG |= (1<<7);
	asm("SEI");
	return ES_OK;
}

ES_t GIE_enuDisable(){

	//SREG &= ~ (1<<7);
	asm("CLI");
	return ES_OK;
}

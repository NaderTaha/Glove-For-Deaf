/*
 * EXTI_config.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Nader
 */

#include "../../LIBRARY/stdTypes.h"
#include "../../LIBRARY/errorState.h"

#include "EXTI_config.h"
#include "EXTI_priv.h"



EXTI_t  intr[intr_num] = {

	{EXTI0,
	enabled,
	falling_edge}

};





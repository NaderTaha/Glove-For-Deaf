/*
 * GIE_int.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Nader
 */

#ifndef MCAL_GIE_GIE_INT_H_
#define MCAL_GIE_GIE_INT_H_

#define SREG 		*((volatile u8*)0x5f)

ES_t GIE_enuinit();
ES_t GIE_enuEnable();
ES_t GIE_enuDisable();



#endif /* MCAL_GIE_GIE_INT_H_ */

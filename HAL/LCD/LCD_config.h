/*
 * config.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Nader
 */

#ifndef HAL_LCD_LCD_CONFIG_H_
#define HAL_LCD_LCD_CONFIG_H_

#define LCD_MODE    FOUR_BIT		//EIGHT_BIT

// control pins
#define RS_GRP DIO_u8GROUP_B
#define RS_PIN DIO_u8PIN1

#define RW_GRP DIO_u8GROUP_B
#define RW_PIN DIO_u8PIN2

#define EN_GRP DIO_u8GROUP_B
#define EN_PIN DIO_u8PIN3

//data pins
#define D7_GRP DIO_u8GROUP_C
#define D7_PIN DIO_u8PIN7

#define D6_GRP DIO_u8GROUP_C
#define D6_PIN DIO_u8PIN6

#define D5_GRP DIO_u8GROUP_C
#define D5_PIN DIO_u8PIN5

#define D4_GRP DIO_u8GROUP_C
#define D4_PIN DIO_u8PIN4

#define D3_GRP DIO_u8GROUP_C
#define D3_PIN DIO_u8PIN3

#define D2_GRP DIO_u8GROUP_C
#define D2_PIN DIO_u8PIN2

#define D1_GRP DIO_u8GROUP_C
#define D1_PIN DIO_u8PIN1

#define D0_GRP DIO_u8GROUP_C
#define D0_PIN DIO_u8PIN0

#endif /* HALL_LCD_CONFIG
_H_ */

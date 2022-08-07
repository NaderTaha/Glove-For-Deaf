/*
 * int.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Nader
 */

#ifndef HAL_LCD_LCD_INT_H_
#define HAL_LCD_LCD_INT_H_


ES_t LCD_INIT(void);
ES_t LCD_enuwritelatch(u8 copy_u88byte);
ES_t LCD_enusend_cmd(u8 copy_u8cmd);
ES_t LCD_enusend_data(u8 copy_u8data);
ES_t LCD_enusend_string(const char *copy_string);
ES_t LCD_enuGoToPosition(u8 Copy_u8Row , u8 Copy_u8Column);
ES_t LCD_enuSendIntegerNum (s32 Copy_s32Num);
//ES_t LCD_enuSendFloatNum (f32 Copy_s32Num);

#endif /* HAL_LCD_LCD_INT_H_ */

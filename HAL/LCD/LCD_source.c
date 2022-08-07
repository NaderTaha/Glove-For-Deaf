/*
 * source.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Nader
 */
#include "../../LIBRARY/stdTypes.h"
#include "../../LIBRARY/errorState.h"

#include "../../MCAL/DIO/DIO_int.h"


#include <util/delay.h>
#include "LCD_config.h"
#include "LCD_private.h"

ES_t LCD_enuwritelatch(u8 Copy_u8Byte){

	u8 error_state = ES_NOK;

if (LCD_MODE == FOUR_BIT){

		DIO_enuSetPinValue(D7_GRP,D7_PIN,((Copy_u8Byte>>7)&1));
		DIO_enuSetPinValue(D6_GRP,D6_PIN,((Copy_u8Byte>>6)&1));
		DIO_enuSetPinValue(D5_GRP,D5_PIN,((Copy_u8Byte>>5)&1));
		DIO_enuSetPinValue(D4_GRP,D4_PIN,((Copy_u8Byte>>4)&1));

		DIO_enuSetPinValue(EN_GRP,EN_PIN,DIO_u8HIGH);
		DIO_enuSetPinValue(EN_GRP,EN_PIN,DIO_u8LOW);

		DIO_enuSetPinValue(D7_GRP,D7_PIN,((Copy_u8Byte>>3)&1));
		DIO_enuSetPinValue(D6_GRP,D6_PIN,((Copy_u8Byte>>2)&1));
		DIO_enuSetPinValue(D5_GRP,D5_PIN,((Copy_u8Byte>>1)&1));
		DIO_enuSetPinValue(D4_GRP,D4_PIN,((Copy_u8Byte>>0)&1));

		DIO_enuSetPinValue(EN_GRP,EN_PIN,DIO_u8HIGH);
		_delay_ms (5);
		DIO_enuSetPinValue(EN_GRP,EN_PIN,DIO_u8LOW);
		_delay_ms (5);
		error_state = ES_OK;
}

else if (LCD_MODE == EIGHT_BIT){
		DIO_enuSetPinValue(D7_GRP,D7_PIN,((Copy_u8Byte>>7)&1));
		DIO_enuSetPinValue(D6_GRP,D6_PIN,((Copy_u8Byte>>6)&1));
		DIO_enuSetPinValue(D5_GRP,D5_PIN,((Copy_u8Byte>>5)&1));
		DIO_enuSetPinValue(D4_GRP,D4_PIN,((Copy_u8Byte>>4)&1));
		DIO_enuSetPinValue(D3_GRP,D3_PIN,((Copy_u8Byte>>3)&1));
		DIO_enuSetPinValue(D2_GRP,D2_PIN,((Copy_u8Byte>>2)&1));
		DIO_enuSetPinValue(D1_GRP,D1_PIN,((Copy_u8Byte>>1)&1));
		DIO_enuSetPinValue(D0_GRP,D0_PIN,((Copy_u8Byte>>0)&1));

		DIO_enuSetPinValue(EN_GRP,EN_PIN,DIO_u8HIGH);
		_delay_ms (5);
		DIO_enuSetPinValue(EN_GRP,EN_PIN,DIO_u8LOW);
		_delay_ms (5);
		error_state = ES_OK;
}
else error_state = ES_OUT_OF_RANGE;

		return error_state;
}

ES_t LCD_INIT(void){

		_delay_ms(35);
		DIO_enuSetPinDirection(RS_GRP,RS_PIN,DIO_u8OUTPUT);
		DIO_enuSetPinDirection(RW_GRP,RW_PIN,DIO_u8OUTPUT);
		DIO_enuSetPinDirection(EN_GRP,EN_PIN,DIO_u8OUTPUT);

		DIO_enuSetPinDirection(D7_GRP,D7_PIN,DIO_u8OUTPUT);
		DIO_enuSetPinDirection(D6_GRP,D6_PIN,DIO_u8OUTPUT);
		DIO_enuSetPinDirection(D5_GRP,D5_PIN,DIO_u8OUTPUT);
		DIO_enuSetPinDirection(D4_GRP,D4_PIN,DIO_u8OUTPUT);

		DIO_enuSetPinValue(RS_GRP,RS_PIN,DIO_u8LOW);
		DIO_enuSetPinValue(RW_GRP,RW_PIN,DIO_u8LOW);
		DIO_enuSetPinValue(EN_GRP,EN_PIN,DIO_u8LOW);


#if LCD_MODE == FOUR_BIT

			DIO_enuSetPinValue(D7_GRP , D7_PIN ,  0 );
			DIO_enuSetPinValue(D6_GRP , D6_PIN ,  0 );
			DIO_enuSetPinValue(D5_GRP , D5_PIN ,  1 );
			DIO_enuSetPinValue(D4_GRP , D4_PIN ,  0 );

			DIO_enuSetPinValue(EN_GRP , EN_PIN ,  DIO_u8HIGH );
			_delay_ms (5);
			DIO_enuSetPinValue(EN_GRP , EN_PIN ,  DIO_u8LOW );
			_delay_ms (5);
		LCD_enuwritelatch(0x28); // FOUR_BIT_MODE_SET

#elif LCD_MODE  == EIGHT_BIT

		DIO_enuSetPinDirection(D3_GRP,D3_PIN,DIO_u8OUTPUT);
		DIO_enuSetPinDirection(D2_GRP,D2_PIN,DIO_u8OUTPUT);
		DIO_enuSetPinDirection(D1_GRP,D1_PIN,DIO_u8OUTPUT);
		DIO_enuSetPinDirection(D0_GRP,D0_PIN,DIO_u8OUTPUT);

		LCD_enuwritelatch(0x38); // EIGHT_BIT_MODE_SET

#else
#error "LCD MODE IS WRONG"
#endif

		LCD_enuwritelatch(0x0f);   //display control
		LCD_enuwritelatch(0x01);   //clear
		LCD_enuwritelatch(0x06);   //display set
		_delay_ms(5);

return ES_OK;

}

ES_t LCD_enusend_cmd(u8 copy_u8cmd){

	 DIO_enuSetPinValue(RS_GRP,RS_PIN,DIO_u8LOW);
     LCD_enuwritelatch(copy_u8cmd);

     return ES_OK;
}
ES_t LCD_enusend_data(u8 copy_u8data){

      DIO_enuSetPinValue(RS_GRP,RS_PIN,DIO_u8HIGH);
      LCD_enuwritelatch(copy_u8data);

      return ES_OK;
}

ES_t LCD_enusend_string(const char *copy_string){
		while(*copy_string){
	  DIO_enuSetPinValue(RS_GRP,RS_PIN,DIO_u8HIGH);
	  LCD_enuwritelatch(*copy_string++);
		}
	  return ES_OK;

}
ES_t LCD_enuGoToPosition(u8 Copy_u8Row , u8 Copy_u8Column){

	ES_t error_state = ES_NOK;
		if(Copy_u8Row>0 && Copy_u8Row<=2 && Copy_u8Column>0 && Copy_u8Column<=16){
			DIO_enuSetPinValue(RS_GRP,RS_PIN,DIO_u8LOW);
		    LCD_enuwritelatch((0x80)+(Copy_u8Column-1)+((0x40)*(Copy_u8Row-1)));
		    error_state = ES_OK;
	}
		return error_state;
}
ES_t LCD_enuSendIntegerNum (u16 Copy_s16Num){

	ES_t error_state = ES_NOK;

		if(Copy_s16Num != 0){
			if(Copy_s16Num<0){
				Copy_s16Num = Copy_s16Num*-1;
			DIO_enuSetPinValue(RS_GRP,RS_PIN,DIO_u8HIGH);
						    LCD_enuwritelatch('-');
			}
				u8 digit=0;
				s16 reminder = Copy_s16Num;
				while(Copy_s16Num){
					Copy_s16Num /=10;
						digit++;}
				u8 int_num[digit];
			while(digit){
				int_num[digit-1]=reminder%10 +'0';
				reminder/=10;
				digit--;
			}
			while(int_num[digit]){
				LCD_enusend_data(int_num[digit++]);
			}
			error_state = ES_OK;
			}
			else {
				LCD_enusend_data('0');
			    error_state = ES_OK;
			}
			return error_state;

/*ES_t LCD_Go_To_CG_RAM(){

		LCD_enusend_cmd(0x40);
			return ES_OK;
	}

ES_t LCD_enusend_SPECIAL_Char(char *copy_SPEC){

			while(*copy_SPEC){
			LCD_enusend_cmd(*copy_SPEC);
			copy_SPEC++;
			}
			LCD_enusend_data(0);

			return ES_OK;*/
}




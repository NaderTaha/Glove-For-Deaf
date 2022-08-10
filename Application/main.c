/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Nader
 */
#include "../LIBRARY/stdTypes.h"
#include "../LIBRARY/errorState.h"

#include "../MCAL/GIE/GIE_int.h"
#include "../MCAL/DIO/DIO_int.h"

#include "../MCAL/EXTI/EXTI_config.h"
#include "../MCAL/EXTI/EXTI_inter.h"

#include "../MCAL/ADC/ADC_config.h"
#include "../MCAL/ADC/ADC_int.h"

#include "../HAL/LCD/LCD_config.h"
#include "../HAL/LCD/LCD_int.h"

#include <util/delay.h>

#define Open      < 800
#define Hold      > 800


int main(){

	u8 i;
	ADC_INIT();
	LCD_INIT();
	LCD_enusend_cmd(0x0c);

	u16  THUMB,INDEX,MIDDLE,RING,LITTLE;

	char smile[]={ 0x00,0x00,0x0a,0x0a,0x00,0x11,0x0e,0x00};

	LCD_enuGoToPosition(1,1);
	LCD_enusend_string("                  HELLO, SIR   ");
	LCD_enusend_cmd(0x40);

	for(i=0;i<8;i++)
		LCD_enusend_data(smile[i]);
	LCD_enuGoToPosition(1,31);
	LCD_enusend_data(0);
	LCD_enusend_cmd(0x80);
	LCD_enuGoToPosition(2,1);
	LCD_enusend_string("                START YOUR SIGN");
	for(i=0;i<15;i++){
		LCD_enusend_cmd(0x18);
			_delay_ms(200);
		}

	_delay_ms(2500);
	for(i=0;i<15;i++){
			LCD_enusend_cmd(0x18);
			_delay_ms(200);
	}

	LCD_enusend_cmd(0x01);
	_delay_ms(2000);

	while(1){

	ADC_START_CONVERSION(0);
	ADC_GET_RESULT(&THUMB);
	_delay_ms(50);
	ADC_START_CONVERSION(1);
	ADC_GET_RESULT(&INDEX);
	_delay_ms(50);
	ADC_START_CONVERSION(2);
	ADC_GET_RESULT(&MIDDLE);
	_delay_ms(50);
	ADC_START_CONVERSION(3);
	ADC_GET_RESULT  (&RING);
	_delay_ms(50);
	ADC_START_CONVERSION(4);
	ADC_GET_RESULT(&LITTLE);
	_delay_ms(50);


	if	   (THUMB Hold && INDEX Hold && MIDDLE Hold && RING Hold && LITTLE Hold)
	{
			LCD_enusend_string("    I  AGREE    ");
			LCD_enuGoToPosition(2,1);
			LCD_enusend_string("                ");
	}

	else if(THUMB Hold && INDEX Open && MIDDLE Open && RING Hold && LITTLE Hold)
	{
			LCD_enusend_string("   QUOTATION    ");
			LCD_enuGoToPosition(2,1);
			LCD_enusend_string("                ");
	}

	else if(THUMB Open && INDEX Open && MIDDLE Hold && RING Hold && LITTLE Open)
	{
			LCD_enusend_string("   I LOVE YOU   ");
			LCD_enuGoToPosition(2,1);
			LCD_enusend_string("                ");
	}

	else if(THUMB Open && INDEX Open && MIDDLE Open && RING Hold && LITTLE Open)
	{
			LCD_enusend_string("I'M REALLY LOVE ");
			LCD_enuGoToPosition(2,1);
			LCD_enusend_string("      YOU       ");
	}

	else if(THUMB Hold && INDEX Open && MIDDLE Hold && RING Hold && LITTLE Open)
	{
			LCD_enusend_string("THIS IS TERRIBLE");
			LCD_enuGoToPosition(2,1);
			LCD_enusend_string("                ");
	}

	else if(THUMB Open && INDEX Open && MIDDLE Open && RING Open && LITTLE Open){
			LCD_enusend_string("   I WISH YOU   ");
			LCD_enuGoToPosition(2,1);
			LCD_enusend_string("  A HAPPY LIFE  ");}

	else if(THUMB Open && INDEX Hold && MIDDLE Hold  && RING Hold && LITTLE Hold)
	{
			LCD_enusend_string("    GOOD JOB    ");
			LCD_enuGoToPosition(2,1);
			LCD_enusend_string("       		    ");
	}

	else if(THUMB Open && INDEX Hold && MIDDLE Hold && RING Hold && LITTLE Open)
	{
			LCD_enusend_string("  I'M NOT SURE  ");
			LCD_enuGoToPosition(2,1);
			LCD_enusend_string("                ");
	}

	else if(THUMB Open && INDEX Hold && MIDDLE Open && RING Open && LITTLE Open)
	{
			LCD_enusend_string("    EXCELLENT   ");
			LCD_enuGoToPosition(2,1);
			LCD_enusend_string("                ");
	}

	else if(THUMB Hold && INDEX Hold && MIDDLE Hold && RING Hold && LITTLE Open)
	{
			LCD_enusend_string("       ME       ");
			LCD_enuGoToPosition(2,1);
			LCD_enusend_string("                ");
	}

	else if(THUMB Open && INDEX Open && MIDDLE Hold && RING Hold && LITTLE Hold)
	{
			LCD_enusend_string(" SEE YOU LATER  ");
			LCD_enuGoToPosition(2,1);
			LCD_enusend_string("                ");
	}

	else if(THUMB Hold && INDEX Open && MIDDLE Open && RING Open && LITTLE Open)
	{
			LCD_enusend_string("   THANK  YOU   5");
			LCD_enuGoToPosition(2,1);
			LCD_enusend_string("                ");
	}

	else if(THUMB Open && INDEX Open && MIDDLE Open && RING Hold && LITTLE Hold)
	{
			LCD_enusend_string("    VICTORY     ");
			LCD_enuGoToPosition(2,1);
			LCD_enusend_string("                ");
	}

	else if(THUMB Open && INDEX Open && MIDDLE Open && RING Open && LITTLE Hold)
	{
			LCD_enusend_string("   LETTER (W)   ");
			LCD_enuGoToPosition(2,1);
			LCD_enusend_string("                ");
	}

	else if(THUMB Open && INDEX Open && MIDDLE Hold && RING Open && LITTLE Open)
	{
			LCD_enusend_string("  NUMBER EIGHT  ");
			LCD_enuGoToPosition(2,1);
			LCD_enusend_string("       (8)      ");
	}

		_delay_ms(500);
		LCD_enuGoToPosition(1,1);
    }
}


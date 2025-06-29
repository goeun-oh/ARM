/*
 * led_contrl.c
 *
 *  Created on: Jun 29, 2025
 *      Author: goeun
 */

#include "led_contrl.h"

static uint8_t data = 0x01;




void SHIFT_LEFT(){
	data = (((data <<1) | (data >>7))& 0xFF);
	LedBar_Write(data);
}
void SHIFT_RIGHT(){
	data = (((data >>1) | (data <<7))& 0xFF);
	LedBar_Write(data);
}

void LED_OFF(){
	LedBar_Write(0x00);
}


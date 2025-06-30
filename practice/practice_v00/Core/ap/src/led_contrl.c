/*
 * led_contrl.c
 *
 *  Created on: Jun 29, 2025
 *      Author: goeun
 */

#include "led_contrl.h"

extern inputData_TypeDef controlData;

static led_t ledBar = {LED_OFF_ALL, 0x01};

void SHIFT_LEFT(){
	ledBar.ledData = (((ledBar.ledData <<1) | (ledBar.ledData>>7))& 0xFF);
	LedBar_Write(ledBar.ledData);
}
void SHIFT_RIGHT(){
	ledBar.ledData = (((ledBar.ledData >>1) | (ledBar.ledData<<7))& 0xFF);
	LedBar_Write(ledBar.ledData);
}

void LED_OFF(){
	LedBar_Write(0x00);
}

void LED_Excute(){
	switch(ledBar.ledState){
	case LED_OFF_ALL:
		if(controlData.id == LED){
			controlData.id = NO_CONTROL;
			ledBar.ledState = LED_SHIFT_LEFT;
		}
		break;
	case LED_SHIFT_LEFT:
		if(controlData.id == LED){
			controlData.id = NO_CONTROL;
			ledBar.ledState = LED_SHIFT_RIGHT;
		}
		break;
	case LED_SHIFT_RIGHT:
		if(controlData.id == LED){
			controlData.id = NO_CONTROL;
			ledBar.ledState = LED_OFF_ALL;
		}
		break;
	}
	Presenter_LED_OutData(ledBar);
}

/*
 * Controller.c
 *
 *  Created on: Jun 29, 2025
 *      Author: goeun
 */


#include "Controller.h"

inputData_TypeDef controlData = {0};



static ledState_t ledState = LED_OFF_ALL;
static void Controller_Mode();

void Controller_Execute(){
	Controller_Mode();
}

void Controller_SetInputData(inputData_TypeDef inputData){
	if(inputData.id == LED){
		controlData.id = LED;
	}
}

void Controller_Mode(){
	switch(ledState){
	case LED_OFF_ALL:
		if(controlData.id == LED){
			controlData.id = NO_CONTROL;
			ledState = LED_SHIFT_LEFT;
		}
		break;
	case LED_SHIFT_LEFT:
		if(controlData.id == LED){
			controlData.id = NO_CONTROL;
			ledState = LED_SHIFT_RIGHT;
		}
		break;
	case LED_SHIFT_RIGHT:
		if(controlData.id == LED){
			controlData.id = NO_CONTROL;
			ledState = LED_OFF_ALL;
		}
		break;
	}
}

ledState_t Controller_GetLedState(){
	return ledState;
}

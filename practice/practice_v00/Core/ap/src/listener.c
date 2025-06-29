/*
 * Listener.c
 *
 *  Created on: Jun 29, 2025
 *      Author: goeun
 */

#include "Listener.h"

static void Listener_Execute();
static void Listener_CheckButton();


void Listener_Init(){
	Button_Init(&hBtn0, hBtn0 -> GPIOx, hBtn0->pinNum, hBtn0->prevState);
}

void Listener_Execute(){
	Listener_CheckButton();
}

void Listener_CheckButton(){
	inputData_TypeDef inputData;

	if(Button_GetState(&hBtn0) == ACT_PUSHED){
		inputData.id = LED;
		Controller_SetInputData(inputData);
	}
}

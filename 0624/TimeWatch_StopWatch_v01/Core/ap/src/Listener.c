/*
 * Listener.c
 *
 *  Created on: Jun 24, 2025
 *      Author: kccistc
 */


#include "Listener.h"


static void Listener_CheckButton();


void Listener_Init()
{
	Button_Init(&hBtnMode, GPIOB, GPIO_PIN_5);
	Button_Init(&hBtnRunStop, GPIOB, GPIO_PIN_3);
	Button_Init(&hBtnClear, GPIOA, GPIO_PIN_10);
}

void Listener_Execute()
{
    Listener_CheckButton();
}

void Listener_CheckButton()
{
	inputData_TypeDef inputData;

	if (Button_GetState(&hBtnMode) == ACT_RELEASED) {
		inputData.id = MODE;
		inputData.data = MODE_ACT;
		Controller_SetInputData(inputData);

	}
	else if (Button_GetState(&hBtnRunStop) == ACT_PUSHED) {
		inputData.id = STOPWATCH_RUN_STOP;
		inputData.data = STOPWATCH_ACT;
		Controller_SetInputData(inputData);

	}
	else if (Button_GetState(&hBtnClear) == ACT_PUSHED) {
		inputData.id = STOPWATCH_CLEAR;
		inputData.data = STOPWATCH_ACT;
		Controller_SetInputData(inputData);
	}
}


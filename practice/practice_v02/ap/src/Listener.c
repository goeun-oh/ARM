/*
 * Listener.c
 *
 *  Created on: Jun 29, 2025
 *      Author: goeun
 */

#include "Listener.h"
#include "usart.h"

static void Listener_CheckButton();
static void Listener_CheckUart();

static uint8_t rcvData =0;
static Que_TypeDef uartRxQue;

void Listener_Init(){
	Button_Init(&hBtn0, GPIOB, GPIO_PIN_5);
	Button_Init(&hBtnMode, GPIOB, GPIO_PIN_3);
	Button_Init(&hBtnRUN, GPIOA, GPIO_PIN_10);

	Que_Init(&uartRxQue);
	HAL_UART_Receive_IT(&huart2, &rcvData, 1);
}

void Listener_Execute(){
	Listener_CheckButton();
	Listener_CheckUart();
}

void Listener_CheckButton(){
	static uint32_t prevChkBtnTime =0;

	uint32_t curTick = HAL_GetTick();

	if (curTick - prevChkBtnTime < 100){
		return;
	}
	prevChkBtnTime = curTick;

	inputData_TypeDef inputData;

	if(Button_GetState(&hBtn0) == ACT_PUSHED){
		inputData.id = LED;
		Controller_SetInputData(inputData);
	}else if(Button_GetState(&hBtnMode) == ACT_PUSHED){
		inputData.id = MODE;
		Controller_SetInputData(inputData);
	}else if(Button_GetState(&hBtnRUN) == ACT_PUSHED){
		inputData.id = STOPWATCH_RUN_STOP;
		Controller_SetInputData(inputData);
	}
}

void Listener_UartCallBack(){
	enQue(&uartRxQue, rcvData);
	HAL_UART_Receive_IT(&huart2, &rcvData, 1);
}


void Listener_CheckUart(){

	if (isQueEmpty(&uartRxQue)){
		return;
	}
	int uartRxData = deQue(&uartRxQue);

	inputData_TypeDef inputData;

	if (uartRxData == 'm'){
		inputData.id = MODE;
		Controller_SetInputData(inputData);
	}else if (uartRxData == 'r'){
		inputData.id = STOPWATCH_RUN_STOP;
		Controller_SetInputData(inputData);
	}else if (uartRxData == 's'){
		inputData.id = STOPWATCH_RUN_STOP;
		Controller_SetInputData(inputData);
	}else if (uartRxData == 'c'){
		inputData.id = STOPWATCH_CLEAR;
		Controller_SetInputData(inputData);
	}
}

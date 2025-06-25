/*
 * Listener.c
 *
 *  Created on: Jun 24, 2025
 *      Author: kccistc
 */


#include "Listener.h"

static void Listener_CheckButton();
static void Listener_CheckUart();
static uint8_t rcvData = 0;

extern Que_TypeDef uartRxQue;

void Listener_Init()
{
	Button_Init(&hBtnMode, GPIOB, GPIO_PIN_5);
	Button_Init(&hBtnRunStop, GPIOB, GPIO_PIN_3);
	Button_Init(&hBtnClear, GPIOA, GPIO_PIN_10);
	Que_Init(&uartRxQue);
	HAL_UART_Receive_IT(&huart2, &rcvData, 1); //인터럽트 enable
}

void Listener_Execute()
{
    Listener_CheckButton();
    Listener_CheckUart();
}

void Listener_CheckButton()
{
	static uint32_t prevChkBtnTime =0;
	uint32_t curTick = HAL_GetTick();//1ms 간격으로 1씩 증가

	if (curTick - prevChkBtnTime < 100){
		return;
	}
	prevChkBtnTime = curTick;

	//100ms 간격으로 아래 코드가 실행

	inputData_TypeDef inputData;

	if (Button_GetState(&hBtnMode) == ACT_RELEASED ) {
		inputData.id = MODE;
		inputData.data = MODE_ACT;
		Controller_SetInputData(inputData);

	}
	else if (Button_GetState(&hBtnRunStop) == ACT_PUSHED ) {
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

void Listener_CheckUart(){
	if (isQueEmpty(&uartRxQue)){
		return;
	}

	int uartRxData = deQue(&uartRxQue);

	inputData_TypeDef inputData;
	if (uartRxData == 'm') {
		inputData.id = MODE;
		inputData.data = MODE_ACT;
		Controller_SetInputData(inputData);

	}
	else if (uartRxData == 'r') {
		inputData.id = STOPWATCH_RUN_STOP;
		inputData.data = STOPWATCH_ACT;
		Controller_SetInputData(inputData);

	}
	else if (uartRxData == 's') {
		inputData.id = STOPWATCH_RUN_STOP;
		inputData.data = STOPWATCH_ACT;
		Controller_SetInputData(inputData);
	}
	else if (uartRxData == 'c') {
		inputData.id = STOPWATCH_CLEAR;
		inputData.data = STOPWATCH_ACT;
		Controller_SetInputData(inputData);
	}
}

void Listener_UartCallBack(){
	enQue(&uartRxQue, rcvData);
	HAL_UART_Receive_IT(&huart2, &rcvData, 1);
}

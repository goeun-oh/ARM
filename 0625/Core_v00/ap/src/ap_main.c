/*
 * ap_main.c
 *
 *  Created on: Jun 19, 2025
 *      Author: kccistc
 */

#include "ap_main.h"

//typedef enum {TIME_WATCH, STOP_WATCH} watch_state_t;


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == TIM2) {
		FND_DispDataCallBack();

		TimeWatch_IncTimeCallBack();
		StopWatch_IncTimeCallBack();
	}
}


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if (huart -> Instance == USART2){
		Listener_UartCallBack();
	}
}


int ap_main()
{
//	watch_state_t modeState = TIME_WATCH;

	HAL_TIM_Base_Start_IT(&htim2);
	LCD_writeStringXY(0, 0, "Hello World!");
	LCD_writeStringXY(1, 0, "Hello STM32!");

	while (1)
	{
		Listener_Execute();
		Controller_Excute();
		Presenter_Excute();
	}

	return 0;
}

void ap_init()
{
	Listener_Init();
	Presenter_Init();
}




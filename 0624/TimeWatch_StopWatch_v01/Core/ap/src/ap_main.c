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


int ap_main()
{
//	watch_state_t modeState = TIME_WATCH;

	HAL_TIM_Base_Start_IT(&htim2);
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
}




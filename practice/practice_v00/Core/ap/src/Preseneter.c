/*
 * Preseneter.c
 *
 *  Created on: Jun 29, 2025
 *      Author: goeun
 */


#include "Presenter.h"
static void RUN_LED();

void Presenter_Execute(){
	RUN_LED();
}

void RUN_LED(){

	ledState_t ledState = Controller_GetLedState();

	switch (ledState){
	case LED_SHIFT_LEFT:
		SHIFT_LEFT();
		break;
	case LED_SHIFT_RIGHT:
		SHIFT_RIGHT();
		break;

	case LED_OFF_ALL:
		LED_OFF();
		break;
	}
	HAL_Delay(100);
}

/*
 * Preseneter.c
 *
 *  Created on: Jun 29, 2025
 *      Author: goeun
 */


#include "Presenter.h"
#include <string.h>


watch_t dispData = {TIME_WATCH, 12, 0,0,0};
led_t dispLedData = {LED_OFF_ALL, 0x01};

static void Presenter_DispFndTimeWatch(watch_t watchData);
static void Presenter_DispFndStopWatch(watch_t watchData);
static void Presenter_LED(led_t ledData);

void Presenter_Execute(){
	if(dispData.id == STOP_WATCH){
		Presenter_DispFndStopWatch(dispData);
	}else{
		Presenter_DispFndTimeWatch(dispData);
	}
	static uint32_t prevTime =0;
	uint32_t curTick = HAL_GetTick();
	if (curTick - prevTime <100){
		return;
	}
	prevTime = curTick;
	Presenter_LED(dispLedData);
}


void Presenter_OutData(watch_t watchData){
	memcpy(&dispData, &watchData, sizeof(watch_t));
}


void Presenter_LED_OutData(led_t ledOutData){
	memcpy(&dispLedData, &ledOutData, sizeof(led_t));
}


void Presenter_DispFndTimeWatch(watch_t watchData)
{
	FND_WriteData(watchData.hour*100 + watchData.min);

	FND_WriteDp(FND_DP_1000|FND_DP_10|FND_DP_1, FND_DP_OFF);

	if (watchData.msec < 500) {
		FND_WriteDp(FND_DP_100, FND_DP_ON);
	}
	else {
		FND_WriteDp(FND_DP_100, FND_DP_OFF);
	}
}

void Presenter_DispFndStopWatch(watch_t watchData){
	FND_WriteData((watchData.min % 10 * 1000) + (watchData.sec * 10) + (watchData.msec/100));

	FND_WriteDp(FND_DP_100|FND_DP_1, FND_DP_OFF);

	if(watchData.msec%100 < 50){
		FND_WriteDp(FND_DP_10, FND_DP_ON);
	}else{
		FND_WriteDp(FND_DP_10, FND_DP_OFF);
	}
	if(watchData.msec < 500){
		FND_WriteDp(FND_DP_1000, FND_DP_ON);
	}else{
		FND_WriteDp(FND_DP_1000, FND_DP_OFF);
	}

}

void Presenter_LED(led_t ledData){
	switch(ledData.ledState){
	case LED_OFF_ALL:
		LED_OFF();
		break;
	case LED_SHIFT_LEFT:
		SHIFT_LEFT();
		break;
	case LED_SHIFT_RIGHT:
		SHIFT_RIGHT();
		break;
	}
}

/*
 * Controller.c
 *
 *  Created on: Jun 29, 2025
 *      Author: goeun
 */


#include "Controller.h"

inputData_TypeDef controlData = {0};

typedef enum {S_TIME_WATCH=0, S_STOP_WATCH} watchModeState_t;

static watchModeState_t modeState = S_TIME_WATCH;
static void Controller_Mode();

void Controller_Execute(){
	Controller_Mode();
}

void Controller_SetInputData(inputData_TypeDef inputData){
	if(inputData.id == LED){
		controlData.id = LED;
	}else if(inputData.id == MODE){
		controlData.id = MODE;
	}else if(inputData.id == STOPWATCH_RUN_STOP){
		controlData.id = STOPWATCH_RUN_STOP;
	}else if(inputData.id == STOPWATCH_CLEAR){
		controlData.id = STOPWATCH_CLEAR;
	}
}

void Controller_Mode(){
	switch(modeState){
	case S_TIME_WATCH:
		if(controlData.id == MODE){
			controlData.id = NO_CONTROL;
			modeState = S_STOP_WATCH;
		}
		TimeWatch_Execute();
		break;
	case S_STOP_WATCH:
		if(controlData.id == MODE){
			controlData.id = NO_CONTROL;
			modeState = S_TIME_WATCH;
		}
		StopWatch_Excute();
		break;
	}
	LED_Excute();
}


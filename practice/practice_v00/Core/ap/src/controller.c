/*
 * Controller.c
 *
 *  Created on: Jun 29, 2025
 *      Author: goeun
 */


#include "Controller.h"

inputData_TypeDef controlData = {0};

void Controller_Execute(){
	Controller_Mode();
}

void Controller_SetInputData(inputData_TypeDef inputData){
	if(inputData.id == LED){
		controlData.id = LED;
	}
}

void Controller_Mode(){
	if (controlData.id == LED){
		controlData.id = NO_CONTROL;
	}
}

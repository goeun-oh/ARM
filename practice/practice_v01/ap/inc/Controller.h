/*
 * Controller.h
 *
 *  Created on: Jun 29, 2025
 *      Author: goeun
 */

#ifndef AP_INC_CONTROLLER_H_
#define AP_INC_CONTROLLER_H_

#include "Model_Watch.h"
#include "timeWatch.h"
#include "stopWatch.h"

enum {NO_CONTROL=0, LED, MODE, STOPWATCH_RUN_STOP, STOPWATCH_CLEAR};

typedef struct{
	int id;
}inputData_TypeDef;

void Controller_Execute();
void Controller_SetInputData(inputData_TypeDef inputData);

#endif /* AP_INC_CONTROLLER_H_ */

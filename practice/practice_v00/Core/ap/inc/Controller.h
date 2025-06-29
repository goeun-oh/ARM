/*
 * Controller.h
 *
 *  Created on: Jun 29, 2025
 *      Author: goeun
 */

#ifndef AP_INC_CONTROLLER_H_
#define AP_INC_CONTROLLER_H_
#include "led_contrl.h"

enum {NO_CONTROL=0, LED};

typedef enum {LED_SHIFT_LEFT=0, LED_SHIFT_RIGHT, LED_OFF_ALL} ledState_t;
typedef struct{
	int id;
}inputData_TypeDef;

ledState_t Controller_GetLedState();
void Controller_Execute();
void Controller_SetInputData(inputData_TypeDef inputData);

#endif /* AP_INC_CONTROLLER_H_ */

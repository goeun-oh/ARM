/*
 * ap_clock.h
 *
 *  Created on: Jun 22, 2025
 *      Author: goeun
 */

#ifndef AP_TIMEWATCH_H_
#define AP_TIMEWATCH_H_
#include "stm32f4xx_hal.h"
#include "Button.h"
#include "FND.h"
typedef struct{
	uint16_t msec;
	uint8_t sec;
	uint8_t min;
	uint8_t hour;
}timeWatch_t;
void TimeWatch_IncTimeCallBack();

void TimeWatch_Excute();

#endif /* AP_TIMEWATCH_H_ */

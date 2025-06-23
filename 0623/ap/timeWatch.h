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
void TimeWatch_IncTimeCallBack();
void TimeWatch_dotCallBack();
void TimeWatch_Excute();

#endif /* AP_TIMEWATCH_H_ */

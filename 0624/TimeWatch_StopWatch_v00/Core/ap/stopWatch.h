/*
 * ap_stopwatch.h
 *
 *  Created on: Jun 22, 2025
 *      Author: goeun
 */

#ifndef AP_STOPWATCH_H_
#define AP_STOPWATCH_H_
#include "stm32f4xx_hal.h"
#include "Button.h"
#include "FND.h"
extern Button_Handler_t hBtnMode;
extern Button_Handler_t hBtnRunStop;
extern Button_Handler_t hBtnClear;
//Interrupt에서 사용하는 함수
void StopWatch_IncTimeCallBack();
void StopWatch_IncTime();
void StopWatch_Excute();
void StopWatch_Stop();

void StopWatch_Run();

void StopWatch_Clear();

#endif /* AP_STOPWATCH_H_ */

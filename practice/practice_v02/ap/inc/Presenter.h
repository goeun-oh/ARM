/*
 * Presenter.h
 *
 *  Created on: Jun 29, 2025
 *      Author: goeun
 */

#ifndef AP_INC_PRESENTER_H_
#define AP_INC_PRESENTER_H_

#include "led_contrl.h"
#include "led_type.h"
#include "Model_Watch.h"
#include "fnd.h"
#include "lcd.h"
void Presenter_Init();
void Presenter_OutData(watch_t watchData);
void Presenter_LED_OutData(led_t ledOutData);
void Presenter_Execute();
void Presenter_lcdOutTimeWatchData(watch_t watchData);
void Presenter_lcdOutStopWatchData(watch_t watchData);

#endif /* AP_INC_PRESENTER_H_ */

/*
 * ap_main.h
 *
 *  Created on: Jun 19, 2025
 *      Author: kccistc
 */

#ifndef AP_AP_MAIN_H_
#define AP_AP_MAIN_H_

#include "FND.h"
#include "GPIO.h"
#include "LedBar.h"
#include "SystemClock.h"
#include "Button.h"
#include "TIM.h"
#include "SysTick.h"
#include "ap_clock.h"
#include "ap_stopwatch.h"
#include "core_cm4.h"
int ap_main();
void ap_init();

#endif /* AP_AP_MAIN_H_ */

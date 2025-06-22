/*
 * ap_clock.h
 *
 *  Created on: Jun 22, 2025
 *      Author: goeun
 */

#ifndef AP_AP_CLOCK_H_
#define AP_AP_CLOCK_H_
#include "TIM.h"
#include "SysTick.h"
void clock_init();
uint16_t clock_update();
int show_dp();
#endif /* AP_AP_CLOCK_H_ */

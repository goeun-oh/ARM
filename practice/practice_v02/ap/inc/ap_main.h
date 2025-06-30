/*
 * ap_main.h
 *
 *  Created on: Jun 29, 2025
 *      Author: goeun
 */

#ifndef AP_INC_AP_MAIN_H_
#define AP_INC_AP_MAIN_H_

#include "stm32f4xx_hal.h"
#include "Listener.h"
#include "Controller.h"
#include "Presenter.h"
#include "tim.h"
#include "usart.h"
int ap_main();

void ap_init();
#endif /* AP_INC_AP_MAIN_H_ */

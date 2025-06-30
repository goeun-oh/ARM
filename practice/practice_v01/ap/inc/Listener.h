/*
 * Listener.h
 *
 *  Created on: Jun 29, 2025
 *      Author: goeun
 */

#ifndef AP_INC_LISTENER_H_
#define AP_INC_LISTENER_H_

#include "btn.h"
#include "Controller.h"
#include "stm32f4xx_hal.h"
#include "queue.h"

void Listener_Init();
void Listener_Execute();
void Listener_UartCallBack();

#endif /* AP_INC_LISTENER_H_ */

/*
 * led_type.h
 *
 *  Created on: Jun 30, 2025
 *      Author: kccistc
 */

#ifndef AP_INC_LED_TYPE_H_
#define AP_INC_LED_TYPE_H_

#include "stm32f4xx_hal.h"
enum {LED_SHIFT_LEFT=0, LED_SHIFT_RIGHT, LED_OFF_ALL};

typedef struct{
	uint8_t ledState;
	uint8_t ledData;
}led_t;


#endif /* AP_INC_LED_TYPE_H_ */

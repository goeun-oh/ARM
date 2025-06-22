/*
 * ap_stopwatch.h
 *
 *  Created on: Jun 22, 2025
 *      Author: goeun
 */

#ifndef AP_AP_STOPWATCH_H_
#define AP_AP_STOPWATCH_H_
#include "TIM.h"


typedef enum {
    STOPWATCH_RUN =0,
    STOPWATCH_STOP,
    STOPWATCH_CLEAR
} StopwatchCmd_t;

typedef struct{
	StopwatchCmd_t state;
	uint16_t ms;
	uint16_t sec;
	uint16_t min;
	uint16_t digit;
	uint8_t blink[4];
}StopWatch_TypeDef;


void stopwatch_init(StopWatch_TypeDef *STx);
void stopwatch_update(StopWatch_TypeDef *STx);
void stopwatch_show_dp(StopWatch_TypeDef *STx);

#endif /* AP_AP_STOPWATCH_H_ */

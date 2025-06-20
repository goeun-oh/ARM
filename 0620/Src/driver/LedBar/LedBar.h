/*
 * LedBar.h
 *
 *  Created on: Jun 18, 2025
 *      Author: kccistc
 */

#ifndef LEDBAR_LEDBAR_H_
#define LEDBAR_LEDBAR_H_
#include <stdint.h>
#include "stm32f411xe.h"
#include "GPIO.h"
void LedBar_Init();
void LedBar_Write(uint8_t data);

#endif /* LEDBAR_LEDBAR_H_ */

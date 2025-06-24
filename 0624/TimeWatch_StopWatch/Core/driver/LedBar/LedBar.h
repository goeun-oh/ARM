/*
 * LedBar.h
 *
 *  Created on: Jun 18, 2025
 *      Author: kccistc
 */

#ifndef LEDBAR_LEDBAR_H_
#define LEDBAR_LEDBAR_H_

#include "stm32f4xx_hal.h"
typedef struct{
    GPIO_TypeDef *GPIOx;
    uint16_t pinNum;
}LedBar_TypeDef;
void LedBar_Write(uint8_t data);

#endif /* LEDBAR_LEDBAR_H_ */

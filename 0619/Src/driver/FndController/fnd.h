/*
 * fnd.h
 *
 *  Created on: Jun 19, 2025
 *      Author: kccistc
 */

#ifndef DRIVER_FNDCONTROLLER_FND_H_
#define DRIVER_FNDCONTROLLER_FND_H_
#include <stdint.h>
#include "GPIO.h"
typedef struct {
    GPIO_TypeDef *GPIOx;
    uint32_t pinNum;
} Fnd_TypeDef;



void Fnd_Init();
void FndCom(uint32_t Com);
void Fnd_Write(uint32_t num);

#endif /* DRIVER_FNDCONTROLLER_FND_H_ */

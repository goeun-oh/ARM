/*
 * btn.h
 *
 *  Created on: Jun 29, 2025
 *      Author: goeun
 */

#ifndef DRIVER_BTN_BTN_H_
#define DRIVER_BTN_BTN_H_

#include "stm32f4xx_hal.h"
typedef struct{
	GPIO_TypeDef *GPIOx;
	uint16_t pinNum;
	uint32_t prevState;
}Btn_Handler_t;

extern Btn_Handler_t hBtn0;
extern Btn_Handler_t hBtnMode;
extern Btn_Handler_t hBtnRUN;

typedef enum {NO_ACT, ACT_PUSHED, ACT_RELEASED} Btn_State_t;

void Button_Init(Btn_Handler_t *hbtnx,GPIO_TypeDef *GPIOx, uint16_t pinNum);
Btn_State_t Button_GetState(Btn_Handler_t *hbtnx);

#endif /* DRIVER_BTN_BTN_H_ */

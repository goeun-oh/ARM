/*
 * btn.c
 *
 *  Created on: Jun 29, 2025
 *      Author: goeun
 */


#include "btn.h"


enum {PUSHED=0, RELEASED};
Btn_Handler_t hBtn0;

void Button_Init(Btn_Handler_t *hbtnx,GPIO_TypeDef *GPIOx, uint16_t pinNum){
	hbtnx -> GPIOx  = GPIOx;
	hbtnx -> pinNum = pinNum;
	hbtnx -> prevState = RELEASED;
}

Btn_State_t Button_GetState(Btn_Handler_t *hbtnx){
	uint32_t curState;
	curState = HAL_GPIO_ReadPin(hbtnx ->GPIOx, hbtnx->pinNum);
	if(hbtnx->prevState == RELEASED && curState == PUSHED){
		HAL_Delay(2);
		hbtnx->prevState = PUSHED;
		return ACT_PUSHED;
	}else if (hbtnx -> prevState == PUSHED && curState == RELEASED){
		HAL_Delay(2);
		hbtnx->prevState = RELEASED;
		return ACT_RELEASED;
	}
	return NO_ACT;
}


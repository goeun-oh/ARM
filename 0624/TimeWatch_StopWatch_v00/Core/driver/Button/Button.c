/*
 * Button.c
 *
 *  Created on: Jun 19, 2025
 *      Author: kccistc
 */


#include "Button.h"

enum{
	PUSHED =0,
	RELEASED
};




void Button_Init(Button_Handler_t *BTNx, GPIO_TypeDef *GPIOx, uint16_t pinNum){
	BTNx -> GPIOx = GPIOx;
	BTNx -> pinNum = pinNum;
	BTNx -> prevState = RELEASED;
}

button_state_t Button_GetState(Button_Handler_t *BTNx){
	uint32_t curState;
//	curState= GPIO_ReadPin(BTNx-> GPIOx, BTNx-> pinNum);
	curState = HAL_GPIO_ReadPin(BTNx -> GPIOx, BTNx-> pinNum);
	//처음 누른 경우
	if ((BTNx -> prevState == RELEASED) && (curState == PUSHED)){
		HAL_Delay(2);
		BTNx -> prevState = PUSHED;
		return ACT_PUSHED;
	} else if ((BTNx -> prevState == PUSHED) &&(curState == RELEASED)){
		HAL_Delay(2); //debounce
		BTNx->prevState = RELEASED;
		return ACT_RELEASED;
	}
	return NO_ACT;
}

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




void Button_Init(Button_Handler_t *BTNx, GPIO_TypeDef *GPIOx, uint32_t pinNum){
	BTNx -> GPIOx = GPIOx;
	BTNx -> pinNum = pinNum;
	BTNx -> prevState = RELEASED;
	GPIO_Init(BTNx->GPIOx, BTNx->pinNum, INPUT);
}

button_state_t Button_GetState(Button_Handler_t *BTNx){
	uint32_t curState;
	curState= GPIO_ReadPin(BTNx-> GPIOx, BTNx-> pinNum);

	//처음 누른 경우
	if ((BTNx -> prevState == RELEASED) && (curState == PUSHED)){
		delay(2); //debounce
		BTNx -> prevState = PUSHED;
		return ACT_PUSHED;
	} else if ((BTNx -> prevState == PUSHED) &&(curState == RELEASED)){
		delay(2); //debounce
		BTNx->prevState = RELEASED;
		return ACT_RELEASED;
	}
	return NO_ACT;
}

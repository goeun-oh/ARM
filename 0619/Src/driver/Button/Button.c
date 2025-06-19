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




void Button_Init(){
	GPIO_Init(GPIOC, 13, INPUT);
}

button_state_t Button_GetState(){
	static uint32_t prevState = RELEASED; //전원을 처음에 넣으면 초기값이 HIGH
	uint32_t curState;
	curState= GPIO_ReadPin(GPIOC, 13);

	//처음 누른 경우
	if ((prevState == RELEASED) && (curState == PUSHED)){
		delay(2); //debounce
		prevState = PUSHED;
		return ACT_PUSHED;
	} else if ((prevState == PUSHED) &&(curState == RELEASED)){
		delay(2); //debounce
		prevState = RELEASED;
		return ACT_RELEASED;
	}
	return NO_ACT;
}

/*
 * ap_main.c
 *
 *  Created on: Jun 19, 2025
 *      Author: kccistc
 */


#include "ap_main.h"

int ap_main(){
	uint8_t data =1;
	int led_state = 0;
	while(1){
		if(Button_GetState() == ACT_RELEASED){
			led_state ^=1;
		}
		switch (led_state){
			case 0:
				data = (data <<1) | (data >> 7);
				break;
			case 1:
				data = (data >> 1) | (data << 7);
				break;
		}
		LedBar_Write(data);
		delay(100);
	}
	return 0;
}


void ap_init(){
	SystemClock_Init(); //GPIO에 CLOCK을 넣어준다.
	LedBar_Init(); //LED 핀 설정 해준다.
	Button_Init();
}

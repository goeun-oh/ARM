/*
 * ap_main.c
 *
 *  Created on: Jun 19, 2025
 *      Author: kccistc
 */


#include "ap_main.h"
Button_Handler_t btn_stop, btn_run, btn_clear;




int ap_main(){
//	enum {OFF=0, LEFT, RIGHT};
//	int led_state = OFF;
	enum {STOP=0, RUN, CLEAR};
	int counter_state =STOP;
	uint8_t number =0;
	uint32_t count =0;
	int com =0;


	while(1){
		switch (counter_state){
			case STOP:
				if(Button_GetState(&btn_run) == ACT_RELEASED){
					counter_state = RUN;
				} else if (Button_GetState(&btn_clear) == ACT_RELEASED){
					counter_state = CLEAR;
				}
//				LedBar_Write(0x00);
				break;
			case RUN:
				if (Button_GetState(&btn_stop) == ACT_RELEASED){
					counter_state = STOP;
				}
				if(count == 100){
					number +=1;
					count =0;
				}else{
					count +=1;
				}
//				data = (data <<1) | (data >> 7);
//				LedBar_Write(data);
				break;
			case CLEAR:
				counter_state = STOP;
				number =0;
//				data = (data >> 1) | (data << 7);
//				LedBar_Write(data);
				break;
		}

		FndCom(com);
		switch(com){
			case 0:
				Fnd_Write((number/1000)%10);
				break;
			case 1:
				Fnd_Write((number/100)%10);
				break;
			case 2:
				Fnd_Write((number/10)%10);
				break;
			case 3:
				Fnd_Write(number%10);
				break;
		}
		com +=1;
		if(com == 4){
			com=0;
		}
		delay(10);
	}
	return 0;
}

void ap_init(){
	SystemClock_Init(); //GPIO에 CLOCK을 넣어준다.
	LedBar_Init(); //LED 핀 설정 해준다
	Button_Init(&btn_stop, GPIOB, 5);
	Button_Init(&btn_run, GPIOB, 3);
	Button_Init(&btn_clear, GPIOA, 10);
	Fnd_Init();
}

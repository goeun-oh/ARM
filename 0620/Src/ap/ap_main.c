/*
 * ap_main.c
 *
 *  Created on: Jun 19, 2025
 *      Author: kccistc
 */

#include "ap_main.h"

Button_Handler_t hBtnLeft;
Button_Handler_t hBtnRight;
Button_Handler_t hBtnOnOff;

enum {
   LEFT,
   RIGHT,
   OFF
};

void TIM2_IRQHandler(void){
	incTick();
	FND_DispData();
	TIM_ClearUIF(TIM2);
}

int ap_main()
{
   uint8_t data = 1;
   uint16_t counter =0;
   int led_state = OFF;

   uint32_t prevCounterTime =0;

   while(1)
   {
	   if(getTick() - prevCounterTime >= 1000){
		   prevCounterTime = getTick();
		   FND_WriteData(counter ++);
	   }
   }
   return 0;
}

void ap_init()
{
   SystemClock_Init();   // led clock 설정
   LedBar_Init(); // led pin 설정
   Button_Init(&hBtnLeft, GPIOB, 5);
   Button_Init(&hBtnRight, GPIOB, 3);
   Button_Init(&hBtnOnOff, GPIOA, 10);
   FND_Init();
   TIM_Init(TIM2, 16-1, 1000-1);
   TIM_CntStart(TIM2);
   TIM_UIEnable(TIM2);
   NVIC_EnableIRQ(TIM2_IRQn);

}

/*
 * ap_main.c
 *
 *  Created on: Jun 19, 2025
 *      Author: kccistc
 */

#include "ap_main.h"

Button_Handler_t mode;
Button_Handler_t run;
Button_Handler_t clear;
StopWatch_TypeDef ST;


enum {CLOCK=0, STOPWATCH};


void TIM2_IRQHandler(void){
	incTick();
	FND_DispData();
	TIM_ClearUIF(TIM2);
}

int ap_main()
{
	int ap_mode =CLOCK;

   uint16_t clock =0;
   uint8_t dp[4] ={0,0,0,0};

   while(1)
   {

	   switch(ap_mode){
	   case CLOCK:
		   if(Button_GetState(&mode) ==ACT_RELEASED){
			   ap_mode = STOPWATCH;
		   }
		   FND_WriteData(clock, dp);
		   break;
	   case STOPWATCH:
		   if(Button_GetState(&mode) == ACT_RELEASED){
			   ap_mode= CLOCK;
		   }
	   	   switch(ST.state){
			   case STOPWATCH_STOP:
				   if(Button_GetState(&run) == ACT_RELEASED){
					   ST.state = STOPWATCH_RUN;
				   }else if(Button_GetState(&clear) ==ACT_RELEASED){
					   ST.state = STOPWATCH_CLEAR;
				   }
				   break;
			   case STOPWATCH_RUN:
				   if(Button_GetState(&run) == ACT_RELEASED){
					   ST.state=STOPWATCH_STOP;
				   }
				   break;
			   case STOPWATCH_CLEAR:
				   ST.state = STOPWATCH_STOP;
				   break;
	   	   }
		   FND_WriteData(ST.digit,ST.blink);
		   break;
	   }
	   clock = clock_update();
	   dp[2] = show_dp();
	   stopwatch_update(&ST);
	   stopwatch_show_dp(&ST);
   }
   return 0;
}

void ap_init()
{
   SystemClock_Init();   // led clock 설정
   LedBar_Init(); // led pin 설정
   Button_Init(&mode, GPIOB, 5);
   Button_Init(&run, GPIOB, 3);
   Button_Init(&clear, GPIOA, 10);
   FND_Init();
   TIM_Init(TIM2, 16-1, 1000-1);
   TIM_CntStart(TIM2);
   TIM_UIEnable(TIM2);
   NVIC_EnableIRQ(TIM2_IRQn);
   clock_init();
   stopwatch_init(&ST);
}

/*
 * ap_main.c
 *
 *  Created on: Jun 19, 2025
 *      Author: kccistc
 */

#include "ap_main.h"

typedef enum {TIME_WATCH, STOP_WATCH} watch_state_t;

Button_Handler_t hBtnMode;
Button_Handler_t hBtnRunStop;
Button_Handler_t hBtnClear;

// two same name weak is not work
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
   if(htim->Instance == TIM2) {
      FND_DispDataCallBack();
      TimeWatch_IncTimeCallBack();
      StopWatch_IncTimeCallBack();
   }
}


int ap_main()
{
   watch_state_t modeState = TIME_WATCH;

   HAL_TIM_Base_Start_IT(&htim2);
   while(1)
   {
      switch(modeState)
      {
      case TIME_WATCH :
         if (Button_GetState(&hBtnMode) == ACT_RELEASED){
            modeState = STOP_WATCH;
         }
         TimeWatch_Excute();
         break;
      case STOP_WATCH:
         if (Button_GetState(&hBtnMode) == ACT_RELEASED){
             modeState = TIME_WATCH;
         }
         StopWatch_Excute();
         break;
      }
   }

   return 0;
}

void ap_init()
{
   Button_Init(&hBtnMode, GPIOB, GPIO_PIN_5);
   Button_Init(&hBtnRunStop, GPIOB, GPIO_PIN_3);
   Button_Init(&hBtnClear, GPIOA, GPIO_PIN_10);
}

#include "ap_main.h"

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim -> Instance == TIM2){
		FND_DispDataCallBack();
		TimeWatch_IncTimeCallBack();
		StopWatch_IncTimeCallBack();
	}
}

int ap_main(){

	HAL_TIM_Base_Start_IT(&htim2);

	while(1){
		Listener_Execute();
		Controller_Execute();
		Presenter_Execute();
	}
	return 0;
}

void ap_init(){
	Listener_Init();
}

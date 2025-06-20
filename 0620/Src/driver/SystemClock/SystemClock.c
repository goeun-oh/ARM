
#include "SystemClock.h"

void SystemClock_Init(){
	   RCC -> AHB1ENR |= RCC_AHB1ENR_GPIOAEN; // RCC AHB1ENR
	   RCC -> AHB1ENR |= RCC_AHB1ENR_GPIOBEN; // RCC AHB1ENR
	   RCC -> AHB1ENR |= RCC_AHB1ENR_GPIOCEN; // RCC AHB1ENR
	   RCC -> APB1ENR |= RCC_APB1ENR_TIM2EN;
}


void delay(int loop){
	for (int j=0; j<loop; j++){
		for(int i = 0; i<1000; i++){}
	}
}

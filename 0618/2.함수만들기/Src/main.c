#include <stdint.h>
#include "stm32f411xe.h"
#include "GPIO.h"
#include "LedBar.h"

void delay();
int main(void)
{
   /*1. Enable clock access to GPIOA */
   // RCC clock control
   RCC -> AHB1ENR |= (1U << 0); // RCC AHB1ENR
   RCC -> AHB1ENR |= (1U << 1); // RCC AHB1ENR
   RCC -> AHB1ENR |= (1U << 2); // RCC AHB1ENR

   GPIO_Init(GPIOA, 0, OUTPUT);
   GPIO_Init(GPIOA, 1, OUTPUT);
   GPIO_Init(GPIOA, 4, OUTPUT);
   GPIO_Init(GPIOB, 0, OUTPUT);
   GPIO_Init(GPIOC, 1, OUTPUT);
   GPIO_Init(GPIOC, 0, OUTPUT);
   GPIO_Init(GPIOC, 2, OUTPUT);
   GPIO_Init(GPIOC, 3, OUTPUT);

   uint8_t data =0x01;

   //for(;;);
   while(1)
   {
	   LedBar_Write(data);
	   data = (data <<1) | (data >>7);
	   delay();
   }
}

void delay(){
    for(int i = 0; i<100000; i++){}
}


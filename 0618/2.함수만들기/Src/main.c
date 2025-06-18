#include <stdint.h>
#include "stm32f411xe.h"
#include "driver/GPIO/GPIO.h"

void delay();

int main(void)
{
   /*1. Enable clock access to GPIOA */
   // RCC clock control
   RCC -> AHB1ENR |= (1U << 0); // RCC AHB1ENR

   GPIO_Init(GPIOA, 5, OUTPUT);

   //for(;;);
   while(1)
   {
      GPIO_WritePin(GPIOA, 5, PIN_SET);
      delay();
      GPIO_WritePin(GPIOA, 5, PIN_RESET);
      delay();
   }
}

void delay(){
    for(int i = 0; i<100000; i++){}
}

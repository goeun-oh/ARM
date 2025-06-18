#include <stdint.h>

#define RCC_AHB1ENR *(volatile uint32_t *)0x40023830
#define GPIOA_MODER *(volatile uint32_t *)0x40020000
#define GPIOA_ODR *(volatile uint32_t *)0x40020014

void delay();
int main(void)
{
   /*1. Enable clock access to GPIOA */
   // RCC clock control
   RCC_AHB1ENR |= (1U << 0); // RCC AHB1ENR

   /*2. Set PA5 as output pin */
   GPIOA_MODER |= (1U << 10);// GPIOA_MODER output mode
   GPIOA_MODER &= ~(1U << 11);// GPIOA_MODER output mode

   //for(;;);
   while(1)
   {
      /*3. Set PA5 high */
      GPIOA_ODR |= (1U <<5);
      delay();
      /*4. Set PA5 low */
      GPIOA_ODR &= ~(1U <<5);
      delay();
   }
}

void delay(){
    for(int i = 0; i<100000; i++){}
}

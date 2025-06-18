#include <stdint.h>

#define PERIPH_BASE (0x40000000UL)

#define APB1PERIPH_OFFSET (0x00000UL)
#define APB2PERIPH_OFFSET (0x10000UL)
#define AHB1PERIPH_OFFSET (0x20000UL)

#define APB1PERIPH_BASE (PERIPH_BASE + APB1PERIPH_OFFSET)
#define APB2PERIPH_BASE (PERIPH_BASE + APB2PERIPH_OFFSET)
#define AHB1PERIPH_BASE (PERIPH_BASE + AHB1PERIPH_OFFSET)

#define GPIOA_OFFSET (0x0000UL)
#define GPIOB_OFFSET (0x0400UL)
#define GPIOC_OFFSET (0x0800UL)
#define GPIOD_OFFSET (0x0C00UL)
#define RCC_OFFSET (0x3800UL)

#define GPIOA_BASE (AHB1PERIPH_BASE + GPIOA_OFFSET)
#define GPIOB_BASE (AHB1PERIPH_BASE + GPIOB_OFFSET)
#define GPIOC_BASE (AHB1PERIPH_BASE + GPIOC_OFFSET)
#define GPIOD_BASE (AHB1PERIPH_BASE + GPIOD_OFFSET)
#define RCC_BASE (AHB1PERIPH_BASE + RCC_OFFSET)
#define RCC_AHB1ENR *(volatile uint32_t *)0x40023830

/*구조체 사용 후*/
typedef struct{
   volatile uint32_t MODER;
   volatile uint32_t OTYPER;
   volatile uint32_t OSPEEDR;
   volatile uint32_t PUPDR;
   volatile uint32_t IDR;
   volatile uint32_t ODR;
   volatile uint32_t BSRR;
   volatile uint32_t LCKR;
   volatile uint32_t AFR[2]; //배열로 AFRL, AFRH 나타내기
}GPIO_TypeDef;

#define GPIOA ((GPIO_TypeDef *)(GPIOA_BASE))
#define GPIOB ((GPIO_TypeDef *)(GPIOB_BASE))
#define GPIOC ((GPIO_TypeDef *)(GPIOC_BASE))

void delay();

int main(void)
{
   /*1. Enable clock access to GPIOA */
   // RCC clock control
   RCC_AHB1ENR |= (1U << 0); // RCC AHB1ENR

   /*2. Set PA5 as output pin */
   GPIOA -> MODER |= (1U << 10);// GPIOA_MODER output mode
   GPIOA -> MODER &= ~(1U << 11);// GPIOA_MODER output mode

   //for(;;);
   while(1)
   {
      /*3. Set PA5 high */
      GPIOA->ODR |= (1U <<5);
      delay();
      /*4. Set PA5 low */
      GPIOA->ODR &= ~(1U <<5);
      delay();
   }
}

void delay(){
    for(int i = 0; i<100000; i++){}
}

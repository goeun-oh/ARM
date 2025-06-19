#include "GPIO.h"
#include "LedBar.h"
#include "stm32f411xe.h"
#include <stdint.h>

void delay();
int main(void) {
    RCC->AHB1ENR |= (1U << 0); // RCC AHB1ENR
    RCC->AHB1ENR |= (1U << 1); // RCC AHB1ENR
    RCC->AHB1ENR |= (1U << 2); // RCC AHB1ENR

    GPIO_Init(GPIOA, 0, OUTPUT);
    GPIO_Init(GPIOA, 1, OUTPUT);
    GPIO_Init(GPIOA, 4, OUTPUT);
    GPIO_Init(GPIOB, 0, OUTPUT);
    GPIO_Init(GPIOC, 1, OUTPUT);
    GPIO_Init(GPIOC, 0, OUTPUT);
    GPIO_Init(GPIOC, 2, OUTPUT);
    GPIO_Init(GPIOC, 3, OUTPUT);

    while (1) {
    }
    return 0;
}
void delay() {
    for (int i = 0; i < 100000; i++) {
    }
}

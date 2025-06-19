#include "GPIO.h"

void GPIO_Init(GPIO_TypeDef *GPIOx, uint32_t pinNum, pin_mode_t pinMode) {
    if (pinMode == OUTPUT) {
        GPIOx->MODER |= (0x1U << (pinNum * 2));
        GPIOx->MODER &= ~(0x02U << (pinNum * 2));
    } else {
        GPIOx->MODER &= ~(0x03U << (pinNum * 2));
    }
}

void GPIO_WritePin(GPIO_TypeDef *GPIOx, uint32_t pinNum, pin_state_t pinState) {
    if (pinState == PIN_SET) {
        GPIOx->ODR |= (1U << pinNum);
    } else {
        GPIOx->ODR &= ~(1U << pinNum);
    }
}

uint32_t GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint32_t pinNum) {
    return !((GPIOx->IDR & (1U << pinNum)) == 0);
}

void GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint32_t pinNum) {
    GPIOx->ODR ^= 1U << pinNum;
}


#ifndef DRIVER_GPIO_GPIO_H_
#define DRIVER_GPIO_GPIO_H_






#include <stdint.h>
#include "stm32f411xe.h"

typedef enum {PIN_RESET =0, PIN_SET =1} pin_state_t;

typedef enum {INPUT =0, OUTPUT=1}pin_mode_t;

void GPIO_Init(GPIO_TypeDef *GPIOx, uint32_t pinNum, pin_mode_t pinMode);
void GPIO_WritePin(GPIO_TypeDef *GPIOx, uint32_t pinNum, pin_state_t pinState);
uint32_t GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint32_t pinNum);
uint32_t GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint32_t pinNum);
#endif /* DRIVER_GPIO_GPIO_H_ */

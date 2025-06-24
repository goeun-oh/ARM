/*
 * LedBar.c
 *
 *  Created on: Jun 18, 2025
 *      Author: kccistc
 */

#include "LedBar.h"

typedef struct{ // GPIO와 핀번호는 항상 함께 다니기 때문에 GPIO와 핀 번호를 묶어서 해결하자
   GPIO_TypeDef *GPIOx;
   uint32_t pinNum;
}LedBar_TypeDef;

LedBar_TypeDef ledBar[8] = { //배열로 선언하여 해당 배열의 bit를 나타내도록
      {GPIOA,GPIO_PIN_0},
      {GPIOA,GPIO_PIN_1},
      {GPIOA,GPIO_PIN_4},
      {GPIOB,GPIO_PIN_0},
      {GPIOC,GPIO_PIN_1},
      {GPIOC,GPIO_PIN_0},
      {GPIOC,GPIO_PIN_2},
      {GPIOC,GPIO_PIN_3}
};

void LedBar_Write(uint8_t data)
{
   for (int i = 0; i < 8; i++) {
      if ((data & (1<<i)) == 0) {
         HAL_GPIO_WritePin(ledBar[i].GPIOx, ledBar[i].pinNum, RESET);
      }else{
         HAL_GPIO_WritePin(ledBar[i].GPIOx, ledBar[i].pinNum, SET);
      }
   }
}

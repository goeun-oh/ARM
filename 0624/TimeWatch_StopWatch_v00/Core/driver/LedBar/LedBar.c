#include "LedBar.h"


LedBar_TypeDef ledBar[8] = {
    {GPIOA, GPIO_PIN_0},
    {GPIOA, GPIO_PIN_1},
    {GPIOA, GPIO_PIN_4},
    {GPIOB, GPIO_PIN_0},
    {GPIOC, GPIO_PIN_1},
    {GPIOC, GPIO_PIN_0},
    {GPIOC, GPIO_PIN_2},
    {GPIOC, GPIO_PIN_3}
};


void LedBar_Write(uint8_t data){
    for(int i=0; i<8; i++){
        if((data & (1<<i)) ==0){
            HAL_GPIO_WritePin(ledBar[i].GPIOx, ledBar[i].pinNum, RESET);
        }else{
            HAL_GPIO_WritePin(ledBar[i].GPIOx, ledBar[i].pinNum, SET);
        }
    }
}

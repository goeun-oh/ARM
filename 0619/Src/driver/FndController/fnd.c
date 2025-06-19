#include "fnd.h"

Fnd_TypeDef FndComm[4]={{GPIOC, 8}, {GPIOC, 6}, {GPIOC, 5}, {GPIOA, 12}};
Fnd_TypeDef FndSeg[8]={
        {GPIOA, 11},
        {GPIOB, 12},
        {GPIOB, 2},
        {GPIOB, 1},
        {GPIOB, 15},
        {GPIOB, 14},
        {GPIOB, 13},
        {GPIOC, 4}
};

uint8_t Seg[10]={
    0xc0,
    0xF9,
    0xA4,
    0xB0,
    0x99,
    0x92,
    0x82,
    0xf8,
    0x80,
    0x90
};
void Fnd_Init() {
    // Common
    for (int i=0; i<4;i++){
        GPIO_Init(FndComm[i].GPIOx, FndComm[i].pinNum, OUTPUT);
    }
    //seg
    for (int i=0; i<8; i++){
        GPIO_Init(FndSeg[i].GPIOx, FndSeg[i].pinNum, OUTPUT);
    }
}

void FndCom(uint32_t Com){
    for (int i=0; i<4; i++){
        if(i == Com) GPIO_WritePin(FndComm[i].GPIOx, FndComm[i].pinNum, PIN_SET);
        else GPIO_WritePin(FndComm[i].GPIOx, FndComm[i].pinNum, PIN_RESET);
    }
}

void Fnd_Write(uint32_t num) {
    for (int i=0; i<8; i++){
        if((Seg[num] & (1<<i))==0){
            GPIO_WritePin(FndSeg[i].GPIOx, FndSeg[i].pinNum, PIN_RESET);
        }else{
            GPIO_WritePin(FndSeg[i].GPIOx, FndSeg[i].pinNum, PIN_SET);
        }
    }
}

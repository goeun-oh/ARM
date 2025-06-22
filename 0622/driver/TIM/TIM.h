/*
 * TIM.h
 *
 *  Created on: Jun 20, 2025
 *      Author: kccistc
 */


#include <stdint.h>
#include "stm32f4xx.h"


void TIM_Init(TIM_TypeDef *TIMx, uint32_t psc, uint32_t arr);

void TIM_CntStart(TIM_TypeDef *TIMx);
void TIM_CntStop(TIM_TypeDef *TIMx);

uint32_t TIM_ReadPSC(TIM_TypeDef *TIMx);
void TIM_WritePSC(TIM_TypeDef *TIMx, uint32_t psc);
uint32_t TIM_ReadARR(TIM_TypeDef *TIMx);
void TIM_WriteARR(TIM_TypeDef *TIMx, uint32_t arr);
uint32_t TIM_ReadCNT(TIM_TypeDef *TIMx);
void TIM_WriteCNT(TIM_TypeDef *TIMx, uint32_t cnt);
void TIM_UIEnable(TIM_TypeDef *TIMx);
void TIM_UIDisable(TIM_TypeDef *TIMx);

//flag를 clear시켜줘야 다시 인터럽트가 걸린다.
void TIM_ClearUIF(TIM_TypeDef *TIMx);

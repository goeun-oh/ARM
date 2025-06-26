/*
 * motor.c
 *
 *  Created on: Jun 26, 2025
 *      Author: kccistc
 */


#include "motor.h"

static MOTOR_HandleTypeDef *hmotorHandler;
static uint32_t motorChannel;

void Motor_Init(MOTOR_HandleTypeDef *hmotor, uint32_t channel){
	hmotorHandler = hmotor;
	motorChannel = channel;
}

void Motor_SetFreq(uint32_t freq){

}

void Motor_Start(){
	HAL_TIM_PWM_Start(hmotorHandler, motorChannel);

}

void Motor_Stop(){
	HAL_TIM_PWM_Stop(hmotorHandler, motorChannel);
}

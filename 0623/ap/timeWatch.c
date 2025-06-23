#include "timeWatch.h"

typedef struct{
	uint16_t msec;
	uint8_t sec;
	uint8_t min;
	uint8_t hour;
	uint8_t dp[4];
}timeWatch_t;

timeWatch_t timeWatch = {0,0,0,12, 0x00000000};

//Interrupt 함수에 들어가는 함수
void TimeWatch_IncTimeCallBack(){
	if(timeWatch.msec < 1000-1){
		timeWatch.msec++;
		return;
	}
	timeWatch.msec =0;

	if(timeWatch.sec <60-1){
		timeWatch.sec++;
		return;
	}
	timeWatch.sec =0;

	if(timeWatch.min<60-1){
		timeWatch.min++;
		return;
	}
	timeWatch.min=0;

	if(timeWatch.hour <24-1){
		timeWatch.hour++;
		return;
	}
	timeWatch.hour=0;
}

void TimeWatch_dotCallBack(){
	if((timeWatch.msec == 500-1) || (timeWatch.msec == 1000-1)){
		timeWatch.dp[2] = !timeWatch.dp[2];
	}
}

void TimeWatch_Excute(){
	FND_WriteData(timeWatch.hour*100 + timeWatch.min, timeWatch.dp);
}

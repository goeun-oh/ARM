#include "ap_clock.h"
static uint8_t min = 0;
static uint8_t sec = 0;

void clock_init(){
	min =0;
	sec =0;
}


uint16_t clock_update(){
    static uint32_t prevClockTime = 0;

    uint32_t now = getTick();


	if(now - prevClockTime >= 1000){
		prevClockTime = now;
		sec ++;
		if(sec >= 60){
			sec =0;
			min ++;
			if(min >=60) min =0;
		}
	}

	return (min*100) +sec;
}

int show_dp(){
	 static int blinkOn=1;
	 static uint32_t prevBlinkTime =0;

	 uint32_t now = getTick();

	 if (now-prevBlinkTime >= 500){
		 prevBlinkTime = now;
		 blinkOn= !blinkOn;
	 }
	 return blinkOn;
}

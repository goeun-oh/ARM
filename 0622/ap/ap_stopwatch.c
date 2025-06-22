#include "ap_stopwatch.h"

void stopwatch_init(StopWatch_TypeDef *STx){
	STx->state = STOPWATCH_STOP;
	STx->ms=0;
	STx->sec=0;
	STx->min=0;
	STx->digit =0;
	for(int i=0;i<4;i++){
		STx->blink[i]=0;
	}
}
void stopwatch_update(StopWatch_TypeDef *STx){
    static uint32_t prevTime = 0;

    uint32_t now = getTick();

    switch (STx->state){
		case(STOPWATCH_RUN):
			if(now - prevTime >= 10){
				prevTime = now;
				STx->ms ++;
				if(STx->ms >= 100){
					STx->ms =0;
					STx->sec ++;
					if(STx->sec >=60) {
						STx->sec =0;
						STx->min ++;
						if(STx->min >= 10) STx->min =0;
					}
				}
			}
		break;
		case(STOPWATCH_CLEAR):
				STx->ms =0;
				STx-> sec =0;
				STx-> min =0;
				break;
		case(STOPWATCH_STOP):
				prevTime=0;
				break;
		default: break;
    }
    STx->digit = (STx->min % 10) * 1000 + (STx->sec / 10 % 10) * 100 + (STx->sec % 10) * 10 + (STx->ms / 10 % 10);

}

void stopwatch_show_dp(StopWatch_TypeDef *STx){
	 static int blinkOn=1;
	 static uint32_t prevBlinkTime =0;

	 uint32_t now = getTick();

	 if(STx -> state == STOPWATCH_RUN){
		 if (now-prevBlinkTime >= 500){
			 prevBlinkTime = now;
			 blinkOn= !blinkOn;
		 }
		 STx-> blink[1]=blinkOn;
		 STx-> blink[3]=blinkOn;
	 }
}

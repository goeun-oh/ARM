#include "ap_main.h"



int ap_main(){
	while(1){
		Listener_Execute();
		Controller_Execute();
		Presenter_Execute();
	}
	return 0;
}

void ap_init(){
	Listener_Init();
}

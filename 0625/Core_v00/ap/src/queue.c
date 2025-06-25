#include "queue.h"
Que_TypeDef uartRxQue;
void Que_Init(Que_TypeDef *q){
	q -> front = 0;
	q -> rear = 0;
}

int isQueFull(Que_TypeDef *q){
	return q-> front == ((q->rear +1) % QUE_SIZE);
}

int isQueEmpty(Que_TypeDef *q){
	return q -> front == q -> rear;
}

void enQue(Que_TypeDef *q, int data){
	if(isQueFull(q)){
		return;
	}
	q -> queData[q->rear] = data;
	q->rear = ((q->rear +1) % QUE_SIZE);
}


int deQue(Que_TypeDef *q){
	if(isQueEmpty(q)){
		return 0;
	}
	int QueData;
	QueData = q-> queData[q->front];
	q->front = ((q->front +1) % QUE_SIZE);
	return QueData;
}


int peekQue(Que_TypeDef *q){
	if (isQueEmpty(q)){
		return 0;
	}
	return q-> queData[q->front];
}

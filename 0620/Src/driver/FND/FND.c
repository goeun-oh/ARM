#include "fnd.h"

enum {DIGIT1, DIGIT10, DIGIT100, DIGIT1000};

typedef struct {
   GPIO_TypeDef *GPIOx;
   uint32_t pinNum;
}FND_TypeDef;
/*
FND_TypeDef fndDigitCom[4] = {
      {GPIOC, 8},
      {GPIOC, 6},
      {GPIOC, 5},
      {GPIOA, 12},
};
*/
FND_TypeDef fndDigitCom[4] = {
      {GPIOA, 12},    // D4
      {GPIOC, 5},    // D3
      {GPIOC, 6},    // D2
      {GPIOC, 8}       // D1
};
FND_TypeDef fndPin[8] = {
      {GPIOA, 11},   //A
      {GPIOB, 12},    //B
      {GPIOB, 2},    //C
      {GPIOB, 1},    //D
      {GPIOB, 15},    //E
      {GPIOB, 14},    //F
      {GPIOB, 13},    //G
      {GPIOC, 4},    //Dp
};

static void FND_DispOff(int fndPos);
static void FND_DispOn(int fndPos);
static void FND_DispDigit(uint16_t digit);

// 전역변수 앞에 static을 붙이면 외부에서 접근을 못함.
static uint16_t fndDispNum = 0; // fnd main data가 된다 (이 데이터를 control해야함)

void FND_Init()
{
   for (int i=0; i<4; i++) {
      GPIO_Init(fndDigitCom[i].GPIOx, fndDigitCom[i].pinNum, OUTPUT);
   }
   for (int i=0; i<8; i++) {
      GPIO_Init(fndPin[i].GPIOx, fndPin[i].pinNum, OUTPUT);
   }
}


// write fndDispNum
void FND_WriteData(uint16_t data) //외부에서 사용
{
   fndDispNum = data;
}
// read fndDispNum
uint16_t FND_ReadData()
{
   return fndDispNum;
}
// display fndDisNum
void FND_DispData()
{
   static int digitPos = 0;
   // 인터럽트가 발생하면 한 자리씩 출력한다.
   digitPos = (digitPos+1) % 4;

   switch(digitPos)
   {
   case DIGIT1:
      //FND_DispOff(digitPos);
      FND_DIspOffAll();
      FND_DispDigit(fndDispNum%10);
      FND_DispOn(digitPos);
      break;
   case DIGIT10:
      //FND_DispOff(digitPos);
      FND_DIspOffAll();
      FND_DispDigit(fndDispNum/10%10);
      FND_DispOn(digitPos);
      break;
   case DIGIT100:
      //FND_DispOff(digitPos);
      FND_DIspOffAll();
      FND_DispDigit(fndDispNum/100%10);
      FND_DispOn(digitPos);
      break;
   case DIGIT1000:
      //FND_DispOff(digitPos);
      FND_DIspOffAll();
      FND_DispDigit(fndDispNum/1000%10);
      FND_DispOn(digitPos);
      break;
   }
}




void FND_DispOff(int fndPos)
{
   // GPIO_Write(GPIOx, Pin, SET);
   GPIO_WritePin(fndDigitCom[fndPos].GPIOx, fndDigitCom[fndPos].pinNum, PIN_RESET);
}

void FND_DispOn(int fndPos)
{
   // GPIO_Write(GPIOx, Pin, RESET);
   GPIO_WritePin(fndDigitCom[fndPos].GPIOx, fndDigitCom[fndPos].pinNum, PIN_SET);
}

void FND_DIspOffAll(){
   for(int i=0; i<4; i++){
      GPIO_WritePin(fndDigitCom[i].GPIOx, fndDigitCom[i].pinNum, PIN_RESET);
   }
}


void FND_DispDigit(uint16_t digit)
{
   const uint8_t segFont[10] = {	         0x3F, // 0 => 00111111
	                0x06, // 1 => 00000110
	                0x5B, // 2 => 01011011
	                0x4F, // 3 => 01001111
	                0x66, // 4 => 01100110
	                0x6D, // 5 => 01101101
	                0x7D, // 6 => 01111101
	                0x07, // 7 => 00000111
	                0x7F, // 8 => 01111111
	                0x6F  // 9 => 01101111
   };
   for (int i=0; i<8; i++){
      if (!(segFont[digit] & (1<<i))){
         GPIO_WritePin(fndPin[i].GPIOx, fndPin[i].pinNum, PIN_SET);
      }
      else {
         GPIO_WritePin(fndPin[i].GPIOx, fndPin[i].pinNum, PIN_RESET);
      }
   }
}








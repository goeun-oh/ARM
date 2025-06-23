#include "FND.h"

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
      {GPIOA, GPIO_PIN_12},    // D4
      {GPIOC, GPIO_PIN_5},    // D3
      {GPIOC, GPIO_PIN_6},    // D2
      {GPIOC, GPIO_PIN_8}       // D1
};
FND_TypeDef fndPin[8] = {
      {GPIOA, GPIO_PIN_11},   //A
      {GPIOB, GPIO_PIN_12},    //B
      {GPIOB, GPIO_PIN_2},    //C
      {GPIOB, GPIO_PIN_1},    //D
      {GPIOB, GPIO_PIN_15},    //E
      {GPIOB, GPIO_PIN_14},    //F
      {GPIOB, GPIO_PIN_13},    //G
      {GPIOC, GPIO_PIN_4},    //Dp
};

static void FND_DispOn(int fndPos);
static void FND_DispDigit(uint16_t digit, uint8_t show_dp);
static void FND_DispOffAll();

// 전역변수 앞에 static을 붙이면 외부에서 접근을 못함.
static uint16_t fndDispNum = 0; // fnd main data가 된다 (이 데이터를 control해야함)
static uint8_t show_dp[4] ={0,0,0,0};

// write fndDispNum
void FND_WriteData(uint16_t data, const uint8_t dp[4]) //외부에서 사용
{
   fndDispNum = data;
   for (int i=0; i<4;i++){
	   show_dp[i]=dp[i];
   }
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
   uint8_t digit=0;
   switch(digitPos)
   {
   case DIGIT1:
      FND_DispOffAll();
      digit = fndDispNum%10;
      break;
   case DIGIT10:
      FND_DispOffAll();
      digit=fndDispNum/10%10;
      break;
   case DIGIT100:
      FND_DispOffAll();
      digit = fndDispNum/100%10;
      break;
   case DIGIT1000:
      FND_DispOffAll();
      digit = fndDispNum/1000%10;
      break;
   }
  FND_DispDigit(digit, show_dp[digitPos]);
  FND_DispOn(digitPos);
}



void FND_DispOn(int fndPos)
{
   // GPIO_Write(GPIOx, Pin, RESET);
   HAL_GPIO_WritePin(fndDigitCom[fndPos].GPIOx, fndDigitCom[fndPos].pinNum, SET);
}

void FND_DispOffAll(){
   for(int i=0; i<4; i++){
      HAL_GPIO_WritePin(fndDigitCom[i].GPIOx, fndDigitCom[i].pinNum, RESET);
   }
}


void FND_DispDigit(uint16_t digit, uint8_t show_dp)
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
   uint8_t seg =segFont[digit];
   if(show_dp) seg |= (1<<7);

   for (int i=0; i<8; i++){
      if (!(seg & (1<<i))){
         HAL_GPIO_WritePin(fndPin[i].GPIOx, fndPin[i].pinNum, SET);
      }
      else {
         HAL_GPIO_WritePin(fndPin[i].GPIOx, fndPin[i].pinNum, RESET);
      }
   }
}








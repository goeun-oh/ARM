# 시계 + StopWatch 모듈 구성

## 정확한 시간은 어떻게 구현할까?

Timer/Counter Peripheral(주변장치)  

- 1ms마다 Interrupt 발생 (HW적으로 Interrupt 발생)
- main에서 실행하다가 Interrupt 발생 시 ISR()로 Jump 한다.
- Interrupt가 처리되면 다시 main으로 복귀한다.

**인터럽트 핸들링 개념**  
[인터럽트 핸들링](./Interrupt_Handling.md)  

**컴파일하기위한 프로그램 설치**  
[컴파일하기위한 프로그램 설치](./Complie_Program.md)

**컴파일과정**  
![](image-8.png)

## FSM

![]({DC6296D3-0326-4729-85C2-92D7A387F5CA}.png)


## 환경구성
이제 Empty Project 말고 STM32CubeIDE에서 제공하는 걸 이용해서 개발을 진행한다.  

### 1. RCC 설정  
![](image-1.png)
- HSE를 사용
- HSE를 8MHz로 설정


HSI: 16MHz 로 고정 (내부 클럭)
HSE: 외부 클럭 (8MHz, 우리가 사용하는 보드 외부 클럭은 8MHz)

해당 clock이 PLL 회로로 들어가 클럭을 100MHz로 뻥튀기한다.

HCLK이 APB Prescaler를 거쳐 Peripheral Clock이 된다.  
- Timer는 100MHz로 설정된다.  

![](image-2.png)

### 2. Debuging 설정
Debuging 용 Wire를 Serial Wire로 설정한다.  

![](image-3.png)

### 3. GPIO 설정
다음과 같이 GPIO를 설정한다.  
![]({EAF31B8D-8800-478B-8202-5B7206C3FE05}.png)  

설정된 모습  
![]({029A8A1D-15A5-4883-BF37-56B66B5AEA89}.png)


### 4. Timer 설정
다음과 같이 Timer를 설정한다.  
![](image-4.png)  
Timer Interrupt를 활성화하기위해 NVIC를 활성화한다.  
![](image-5.png)  


### 5. project manager 설정
code generator에서 Generate peripheral initialization as a pair of '.c/.h' files per peripheral를 선택한다.  
-> 관련 파일이 각각 따로 만들어져 보기 편하다고 한다.  
![](image-6.png)  



다했으면 톱니바퀴 아이콘을 눌러서 프로젝트를 생성한다.  
![](image-7.png)  



# 프로젝트 Layer
![]({B62210FE-08B1-4DE9-82D7-486FB68AEB10}.png)  

HAL Driver:
MCU의 주변장치를 제어하는 등의 동작은 HAL 레벨에서 이루어진다.
이를 위해 HAL 레벨에는 여러 개의 파일이 있는데, 이 파일의 묶음을 HAL Driver라고 한다.

**우리가 만들 프로젝트의 Layer**  
![]({753DC8B8-6789-4F79-B970-567076953D7F}.png)


## 생성된 파일들

![]({0A578745-B0C4-4B1B-98F6-B55137A99123}.png)  

`stm32f4xx_it.c` 인터럽트 핸들링을 위한 소스파일   
`stm32f4xx_hal_msp.c` HAL 레벨에서 MCU의 주변장치를 제어하기 위한 소스파일  
`stm32f4xx_hal_conf.h` HAL 레벨에서 MCU의 주변장치를 제어하기 위한 설정 파일  


## HAL에 정의된 함수들

**HAL_TIM_PeriodElapsedCallback()**  

![]({F374ED04-824A-40E3-967C-6E9589E09CF2}.png)

주기적으로 호출되는 콜백함수.

- 콜백이란?  
main함수에서 다른 함수를 부르는형태를 **콜백**이라고 한다.


## compile 하면 생기는 파일

`~.elf` 파일이 보드에 다운로드 된다.  
![](image-9.png)  

`make clean`으로 기존에 만들어진 실행관련 파일을 다 지우자

`make all`을 하면 컴파일을 진행한다.

![](image-10.png)

**그 다음 분석하기**  

**object file의 size**를 확인가능하다.

    arm-none-eabi-size ap_main.o

![]({854A088A-B2D9-4FD1-8398-CAA0D8FC83A6}.png)

(text, data, bss 영역의 크기를 확인할 수 있다.)

> ![]({4A1A5D0F-5015-4F52-B532-E5A28EA1C048}.png)  
ap_main.o가 위와같은 section으로 나뉘어져있다.


**assmebly어 생성하는 명령어**

    arm-none-eabi-objdump -d ap_main.o > ap_main.d

`ap_main.d` 파일을 열어보면 어셈블리어로 변환된 코드를 볼 수 있다.  
![]({BC0CB748-1D9A-4A26-AC94-3C2C965CFAED}.png)

특징을 살펴보면 함수 이름 옆에 주소가 다 0으로 되어있다.  

> 이유는 아직 컴파일러가 최적화를 하지 않았기 때문이다.

**`ap_main.nm` 파일 생성**

    arm-none-eabi-nm -nS ap_main.o > ap_main.nm


![](image-11.png)

`ap_main.nm`파일이 생성되었다!

ap_main.nm 파일은 심볼을 출력하는 파일이다.

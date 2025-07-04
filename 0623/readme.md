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

[STM32 환경구성](./stm32_환경구성.md)


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

링크 되어있지 않은 object 파일은 함수에 대해 주소가 모두 0으로 할당된다.
변수 또한 0으로 할당된다.

> **Why?**  
object파일은 여러 개 일 수 있다.  
object 파일은 주소 할당이 되어있지 않고, 단지 심볼(`section`)만 나뉘어져있다.

***Object 파일은 섹션 정보의 묶음이다.***  

***Object파일을 묶어서 Linker가 주소할당을 해준다.***


**`ap_main.nm` 파일 생성**

    arm-none-eabi-nm -nS ap_main.o > ap_main.nm


![](image-11.png)

`ap_main.nm`파일이 생성되었다!

ap_main.nm 파일은 심볼을 출력하는 파일이다.
(함수명, 변수명 심볼 출력)

- 심볼?  
    `.bss`, `.data`, `.text`를 의미한다.

![]({B99A8D3B-7903-421B-925D-9C31631141C1}.png)

`B`: BSS 영역  
`D`: Data 영역  
`T`: Text 영역  

![]({6EA0A4FE-CCB6-4F5F-A7DE-58ECBEF95335}.png)  
`hBtnMode`는 전역변수인데 초기화되지 않은 변수이므로 `.bss` 영역에 저장된다.


![](image-12.png)  


`.bss`: 전역변수인데 초기화되지 않은 변수  
`.data`: 전역변수인데 초기화된 변수  
`.text`: 함수, 코드가 저장되는 영역  

## STM32 컴파일 과정

[STM32 컴파일 과정](./stm32_compile.md)



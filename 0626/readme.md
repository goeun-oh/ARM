# MVC

이런형태로 구현하는걸 MVC 패턴이라고한다.

![](ap_MVC.png)  


timewatch, stopwatch 입장에서는 출력을 신경쓰지 않을 수 있도록 위와 같이 구현하자.

# 부저 추가하기

![]({E564AE07-7224-401D-ABD2-CA6F0371278C}.png)

## 타이머

**PWM을 만들어보자.**

![]({92DEE4F9-17CB-4BDD-87A1-31134E2B5417}.png)

`CNT`를 중심으로 생각하자

***주파수 변경하기***

![]({C380EC89-B23A-47CE-98D4-31AD8ACB1984}.png)

ARR(TOP) 값을 조절하여 주파수를 변경하자.

***PWM 적용을 위해 Duty Cycle을 변경할 수 있다.***  
임의의 기준값을 설정한 후, 기준값 보다 CNT 값이 작으면 출력을 `HIGH`, 크다면 `LOW`로 설정해주면 된다.

> **Capture Compare Register**  
이떄 임의의 기준은 `CCR(Capture Compare Register)` 가 된다.

![]({E6D39EC2-1153-46A7-8D87-457C48AE7936}.png)


- **PWM**
    - **주파수:** `ARR`
    - **Duty Cycle:** `CCR`


***High 신호를 길게하고 싶다면 `CCR`을 올리면 된다.***

![](image.png)  

![]({5E0CA769-C2CB-43E9-8FEB-E653AC01A9E4}.png)

Auto-reload preload 값을 `Enable`로 설정해놓으면, ARR 값 변경 시 ARR 값이 CNT 값과 같아진 이후에 ARR 값을 바꾸기 때문에 CNT 값이 ARR 값과 같아지는 타이밍을 놓쳐 CNT 값이 overflow되는 현상을 방지 가능하다.


### 타이머 추가하기
TIM3, TIM_CHANNEL_1

![](image-1.png)  
![]({F7A7B911-9684-4457-9FD2-54637422DA73}.png)  

```c
//ap_main.c
int ap_main()
{
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
}
```


### SW Stack  

![]({62ACB850-0B31-4DD3-AD45-7820302C0BAB}.png)


# DC Motor 추가

![]({8886F301-015B-4A68-B718-A9131713AF2B}.png)

- 주파수 고정 (10kHz)
- duty cycle 변경 (0~100%)
- Dc Motor Driver (초기화, 속도조절, Start, Stop)

# 온습도센서 추가

![]({5F7862E4-169A-40D8-A2A4-9BDC7C93FC11}.png)

![]({BF472857-0083-4504-B6BA-62D410ACE6CF}.png)

![]({798DA0C5-F215-4467-AE83-A95538ABE1C3}.png)

# 발표 자료에 들어가야할 내용
- Object Diagram  

    ![]({2D8758C4-AA11-400B-819B-302674765111}.png)

    이 네모가 object
- SW Stack

- Sequence Diagram

    ![]({C54C2209-75FB-42E8-82AB-0EC3F250E429}.png)



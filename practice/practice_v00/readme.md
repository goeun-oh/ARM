# BTN LED 제어

[GPIO구조](./GPIO.md)

### BTN을 사용하기 위해 아래와 같이 pin을 mapping 하자

![](image-1.png)  
BTN은 총 3개를 사용한다.


![](image-2.png)

회로는 다음과 같이 구성한다.  

![](image-3.png)  

pull up 저항을 달아서 BTN이 눌리지 않았을 때는 `1`이다.


![](<스크린샷 2025-06-29 14-26-40.png>)

- `PB5` : BTN 1
- `PB3` : BTN 2
- `PB10`: BTN 3



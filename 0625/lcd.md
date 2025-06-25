# LCD Driver 만들기

![]({4626E4DA-61A0-4FC6-B6FF-E56F945E8B32}.png)  

쪽보드가 있어 I2C 통신으로 제어 가능한 LCD  

LCD Driver 만들고 app 에서 띄우는 것이 목표  



![]({F71560C2-050A-428C-9C15-A15C87FCC97C}.png)

## pcf8574 

LCD 쪽보드에 달려있는 chip   
I2C Interface에서 data가 들어오면 8bit port로 내보내준다.

### Slave Address  

![]({50C788AC-2B39-4A32-9EB3-09557D01F8D6}.png)

Slave Address: 0100_`A2`_`A1`_`A0`_`R/W`  

**A2,A1,A0 은 VCC로 Pull up 되어있다.**  
![]({3A26EB5B-0B34-4FD8-A70A-4E8D9730CC2B}.png)

***따라서 slave Address는 010_0111 -> `0x27`***

A0,A1,A2를 short 시켜서 HW 주소를 변경 가능하다.  

![]({A94A8974-44E2-4DC7-8935-2AE46F996455}.png)



### Write mode  
![]({4103AD85-A129-4338-913D-84AC97C11C39}.png)
- **RS :**
    
    Data/Register
    Valid Data 값이
    - Data: 글자인지
    - Register: 내부 명령어인지  

    를 의미 

    `RS: 0`: command (명령어 모드)  
    `RS= 1`: data (글자 모드)

    ![]({01A091D5-DFE3-4055-BFDB-0D7468F9B76B}.png)  

- **R/W :**  
    `1` : Read
    `0` : Write

- **E :**  
    Enable이 Falling edge일때 LCD에 Data가 적용된다.



![]({DE29C5FB-0C31-41CE-B69F-983A7BFC44D8}.png)

two type data operation이 존재 (4bit, 8bit)

- 4bit mpu to interface 사용시 2번 전송이 요구됨
    - 첫번째: 상위 4bit, 두번째: 하위 4bit 전송

![](image-1.png)  

![](image-2.png)


## I2C 연결하기
ioc 파일에서 설정해주기

![]({AE02D46F-0632-44DE-BFFD-33F2FF6ABB8D}.png)
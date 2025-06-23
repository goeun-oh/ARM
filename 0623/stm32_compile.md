## STM32 컴파일 과정

    .c → (전처리) → .i → (컴파일) → .s → (어셈블) → .o → (링킹) → .elf

**1. 전처리 (Preprocessing)**  
- 생성파일 : `*.i`
-  `#include, #define`을 해석하고, 헤더 파일을 붙여넣는 과정  

**2. 컴파일 (Compiling)**
- 생성파일 : `*.s`	
- 전처리된 코드를 어셈블리어로 변환하는 과정

**3. 어셈블 (Assembling)**	
- 생성파일: `*.o`	
- 어셈블리어를 기계어로 바꾸는 과정, 오브젝트 파일 생성

<details>

<summary> assembling 단계에서 쓸 수 있는 명령어들 </summary>
    <details>   
    <summary> size 분석 </summary>

**object file의 size**를 확인가능하다.

    arm-none-eabi-size ap_main.o
</details>

<details>

<summary>disassembly해서 사람이 볼 수 있도록하는 파일</summary>
    
    arm-none-eabi-objdump -d ap_main.o > ap_main.d

</details>
</details>

**4. 링킹 (Linking)**	
- 생성파일: `*.elf`	
- 여러 오브젝트 파일을 합쳐서 최종 실행 파일 생성  


        main.c       ap_main.c       Button.c       FND.c       ...
        │             │               │             │
        ▼             ▼               ▼             ▼
        main.o      ap_main.o       Button.o       FND.o       ...
        └──────────┬───────────────┬──────────────┘
                   │               │
                   ▼               ▼
                   [    링커 (Linker)    ]
                    │               │
                    ▼               ▼
                stopwatch.elf (실행 파일)
    
    ***링커가 주소할당을 해준다***  


    > 링커는 RAM, FLASH, ROM 등의 size가 어떻게 할당되어있는지 알고 주소할당을 수행하는걸까?

    ![]({75CE2B8E-1BD7-4153-9407-EB40843E6E00}.png)

    Linker는 **Memory Section 정보가 있는 Script 파일**을 참고하여 주소할당을 수행한다.

    해당 파일을 `Linker Secript`파일이라하며 다음과 같이 존재한다.  
    ![]({670198D9-79A3-456B-B99C-7FDCFA6C59F1}.png)

    위 파일을 까보면,
        
        MEMORY
        {
        RAM    (xrw)    : ORIGIN = 0x20000000,   LENGTH = 128K
        FLASH    (rx)    : ORIGIN = 0x8000000,   LENGTH = 512K
        }
    
    RAM 시작주소가 0x2000~, 길이가 128K등 임을 알 수 있다.

        /* Highest address of the user mode stack */
        _estack = ORIGIN(RAM) + LENGTH(RAM); /* end of "RAM" Ram type memory */

    `estack`은 RAM의 꼭대기 주소이다.
    
    - RAM 시작주소 + RAM 크기

    ![]({B87D6649-2571-44BF-AD95-730B3EB17B7E}.png)

    makefile에서 아래 처럼 정의된 것을 볼 수 있다.
    ![]({AEF2B361-8324-46AB-B117-D0D4E25D3F3E}.png)

    `-T"C:\Users\kccistc\STM32\20250623_TimeWatch_StopWatch\STM32F411RETX_FLASH.ld"`   
    Linker Script 이걸 참고해라!


**5. 후처리 (옵션)**	
- 생성파일: `*.bin, *.hex`	
- STM32에 업로드 가능한 바이너리 혹은 HEX 파일 생성

---
## 링커 스크립트란?

***링커에게 메모리를 어떻게 배치할지 알려주는 설계도***

컴파일러는 그냥 `.o` 파일을 만들 뿐임(section을 나누기만 한다.)

링커는 `.o`만 보고는 어디에 무엇을 배치할지 모른다.

따라서 링커 스크립트를 보고 메모리 주소를 배정한다.

***링커 스크립트는 section들의 주소 범위를 링커에게 알려준다.***

---
# 링커스크립트 까보기  

[](./linker_script.md)

---

이제 링킹과정을 거친 후, object 파일에서는 할당되어있지 않았던 주소가 할당되었음을 알 수 있다.

    arm-none-eabi-objdump -d 20250623_TimeWatch_StopWatch.elf >stopwatch.d

![](image-13.png)


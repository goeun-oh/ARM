# GPIO 버튼 추가
## Schematic
![](image.png)  

- C언어 코드만으로는 edge detect 하는게 없다
    - C언어로 CLK edge 동기화를 할 수 없으니까

기존에 구현했던건 버튼을 누르고 있을 때 LED가 멈추는 문제가 있었음  
-> 이렇게하면 안된다함

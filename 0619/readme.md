# GPIO 버튼 추가

**Schematic**  

![](image.png)  

- C언어 코드만으로는 edge detect 하는게 없다
  - C언어로 CLK edge 동기화를 할 수 없으니까

기존에 구현했던건 버튼을 누르고 있을 때 LED가 멈추는 문제가 있었음  
-> 이렇게하면 안된다함

Application에서 바로 GPIO(Interface)로 접근하는건 지양해야한다.  

- GPIO는 하드웨어에 가까운 부분이기 때문에, Application에서 직접 접근하는건 좋지 않다  
- 단지 Driver만 수정하면 되는 것이 Interface까지 수정해야되어 번거로워진다.  
![]({237EF5FA-4218-4683-8031-73F87911D2AB}.png)  

**인접한 Layer를 통해 메시지를 송수신해야한다**  
Application에서 인접한 Layer는 Driver이다.  

인터넷에 'software stack' 검색  

- 예시  
    ![]({C210C9A6-E664-471B-8447-DBD93432D92B}.png)  
  - Application에서 바로 MAC이나 PHY에 접근하지 않는다.

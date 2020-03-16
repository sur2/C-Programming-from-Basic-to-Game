# C-Programming-from-Basic-to-Game
[인프런] 나도코딩님의 'C 프로그래밍 - 입문부터 게임 개발까지' 강좌

## 디버깅 폴더의 .exe 파일을 찾을 수 없다.
**사용자 계정의 AppData - Local - Microsoft의 MSBuild 폴더 삭제로 해결**



## 난수 구현

#### srand() : 전달인자를 기반으로 난수를 초기화하는 함수

#### rand() : srand로 선언된 난수를 반환하는 함수(10자리)

#### srand의 전달인자로 time 함수를 사용하여 매 시간마다 새로 생성된 난수를 rand함수로 호출한다. 

n과 a를 통해 난수의 범위 설정

```
srand(time(nuLL));
int number = rand() % n + a;
```



### 프로세스 종료

```
exit(0); // 프로세스 종료(예상한 상황)
exit(1); // 프로세스 종료(예기치 못한 상황)
// 파라메터가 가리키는 숫자는 OS에서 시작해 부모 프로세스로부터 반환된 상태값
```
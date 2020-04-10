# C-Programming-from-Basic-to-Game
[인프런] 나도코딩님의 'C 프로그래밍 - 입문부터 게임 개발까지' 강좌

## 디버깅 폴더의 .exe 파일을 찾을 수 없다.
**사용자 계정의 AppData - Local - Microsoft의 MSBuild 폴더 삭제로 해결**



### 난수 구현

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



### 문자열 초기화

문자열 초기화 시 마지막 배열에 NULL문자인 \0가 들어가야한다.

```
char string[5] = {'s', 'i', 'z', 'e', '\0'};
```



### 포인터

포인터 변수는 변수의 메모리 주소로 초기화 할 수 있다. 

*를 사용해 메모리주소를 가리켜 변수 값을  변경할 수 있다.

```
int n = 10;
int* ptr = &n;
printf("%d %d\n", n, *ptr); // 10 10
printf("%p %p\n", &n, ptr); // 메모리주소 메모리주소
*ptr = 20;
printf("%d\n", n); // 20
```

배열 값은 자체가 주소를 가리킨다.

*를 사용해 배열의 원소 값을 초기화 할 수 있다.

```
int arr[] = { 0, 1, 2 };
int* ap = arr;
*arr = 100;
*(arr + 1) = 200;
*(arr + 2) = 300;
printf("%d %d %d\n", arr[0], arr[1], arr[2]); // 100 200 300
```



### clock()

현재 시간을 millisecond (1000분의 1초) 단위로 반환

```
#include <time.h>
long timt = clock();
```



### 구조체

구조체 선언

```
struct gameInfo {
	char* name;
	int year;
	int price;
	char* company;
};
```

구조체 초기화

```
struct gameInfo game1;
game1.name = "1번게임";
game1.year = 2020;
game1.price = 1000;
game1.company = "com";

struct gameInfo game2 = {"2번게임", 2020, 500, "com"};

struct gameInfo gameArray[2] = {
	{"3번 게임", 2020, 1000, "com"},
	{"4번 게임", 2020, 5000, "com"}
};
	



```


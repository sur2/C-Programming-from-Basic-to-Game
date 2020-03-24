#include <stdio.h>
#include <time.h>

// 물고기가 6마리가 있다
// 이들은 어항에 살고 있는데, 사막이다
// 사막이 너무 덥고, 건조해서 아주 빨리 물이 증발한다
// 물이 다 증발하기 전에 부지런히 어항에 물을 줘서 물고기를 살려야한다
// 물고기는 시간이 지날수록 점점 커져서... 나중에는 잡아먹는다 ^^

int level;
int arrayFish[6];
int* cursor;

void initData();
void printFishes();
void decreaseWater(long elapsedTime);
int checkFishAlive();

int main_pointer()
{
	long startTime = 0; // 게임 시작 시간
	long totalElapsedTime = 0; // 총 경과 시간
	long prevElapsedTime = 0; // 직전 경과 시간 (최근에 물을 준 시간 간격)

	int num; // 몇 번 어항에 물을 줄 것인지, 사용자 입력
	initData();

	cursor = arrayFish; // cursor[0], cursor[1], ... cursor[6]

	startTime = clock(); // 현재 시간을 millisecond (1000분의 1초) 단위로 반환, include time.h
	while (1)
	{
		printFishes();
		printf("몇 번 어항에 물을 주시겠어요? ");
		scanf_s("%d", &num);

		// 입력값 체크 : 오작동 방지
		if (num < 1 || num > 6)
		{
			printf("\n입력값이 잘못되었습니다. %d\n", num);
			continue;
		}

		// 총 경과 시간
		totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC;
		printf("총 경과 시간 : %ld 초\n", totalElapsedTime);

		// 직전에 물을 준 시간(마지막으로 물을 준 시간) 이후로 흐른 시간
		prevElapsedTime = totalElapsedTime - prevElapsedTime;
		printf("최근 경과 시간 : %ld 초\n", prevElapsedTime);

		// 어항의 물을 감소(증발)
		decreaseWater(prevElapsedTime);

		// 사용자가 입력한 어항에 물을 준다
		// 1. 어항의 물이 0 이면? 물을 주지 않는다 ... 이미 물고기가 죽었기 때문
		if (cursor[num - 1] <= 0)
		{
			printf("%d 번 물고기는 이미 죽었습니다.. 물을 주지 않습니다.\n", num);
		}
		// 2. 어항의 물이 0 이 아닌 경우? 물을 준다! 다만 100을 넘지 않는지 체크
		else if (cursor[num - 1] + 1 <= 100)
		{
			// 물을 준다
			printf("%d 번 어항에 물을 준다\n\n", num);
			cursor[num - 1] += 1; // cursor[num - 1] = cursor[num - 1] + 1
		}

		// 레벨업을 한 것인지 확인(20초마다 레벨업 실행)
		if (totalElapsedTime / 20 > level - 1)
		{
			level++; 
			printf("*** 축 레벨업 ! 기존 %d 레벨에서 %d 레벨로 업그레이드 ***\n\n", level - 1, level);
		
			// 최종 레벨 : 5
			if (level == 5)
			{
				printf("\n\n축하합니다. 최고 레벨을 달성했습니다. 게임을 종료합니다.\n");
				exit(0);
			}
		}

		// 물고기가 죽었는지 확인
		if (checkFishAlive() == 0)
		{
			// 물고기 모두 죽음
			printf("모든 물고기가 죽었습니다.\n당신의 레벨은 %d입니다.\n- END -\n", level);
			exit(0);
		}
		else
		{
			// 최소 한 마리 이상의 물고기는 살아있음
			printf("물고기가 아직 살아있습니다.\n");
		}
		// 10s -> 15s (prev : 5s -> total : 15s) -> 25s (prev : 15s) 
		prevElapsedTime = totalElapsedTime;
	}	

	return 0;
}

void initData()
{
	level = 1; // 게임 레벨(1~5)
	for (int i = 0; i < 6; i++)
	{
		arrayFish[i] = 100; // 어항의 물 높이 (0~100)
	}
}

void printFishes()
{
	printf("%3d번 %3d번 %3d번 %3d번 %3d번 %3d번\n", 1, 2, 3, 4, 5, 6);
	for (int i = 0; i < 6; i++)
	{
		printf(" %4d ", arrayFish[i]);
	}
	printf("\n\n");
}

void decreaseWater(long elapsedTime)
{
	for (int i = 0; i < 6; i++)
	{
		arrayFish[i] -= (level * 3 * (int)elapsedTime); // 3 : 난이도 조절을 위한 값
		if (arrayFish[i] < 0)
		{
			arrayFish[i] = 0;
		}
	}
}

int checkFishAlive()
{
	for (int i = 0; i < 6; i++)
	{
		if (arrayFish[i] > 0)
		{
			return 1;
		}
	}
	return 0;
}

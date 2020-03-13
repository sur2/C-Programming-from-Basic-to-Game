#include<stdio.h>

// main함수 정의 후 사용
int main_loof(void)
{
	// 피라미드 쌓기
	int floor = 0;
	printf("몇 층으로 쌓겠습니까?\n");
	scanf_s("%d", &floor);
	for (int i = 0; i < floor; i++)
	{
		for (int j = i; j < floor - 1; j++)
		{
			printf(" ");
		}
		for (int j = 0; j < i*2+1; j++)
		{
			printf("*");
		}
		printf("\n");
	}


	return 0;
}
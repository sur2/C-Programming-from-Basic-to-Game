#include <stdio.h>

int getRandomNumber(int level);
void showQuestion(int level, int num1, int num2);
void success();
void fail();

int main_func(void)
{
	// 문이 5개가 있고, 각 문마다 점점 어려운 수식 퀴즈가 출제 (랜덤)
	// 맞히면 통과, 틀리면 실패

	srand(time(NULL));
	int count = 0;
	for (int i = 1; i <= 5; i++)
	{
		int num1 = getRandomNumber(i);
		int num2 = getRandomNumber(i);
		
		int answer = -1;
		showQuestion(i, num1, num2);
		scanf_s("%d", &answer);
		if (answer == -1)
		{
			printf("프로그램을 종료합니다.\n");
			// 프로세스 종료
			exit(0);
		}
		else if (answer == num1 * num2)
		{
			success();
			count++;
		}
		else
		{
			fail();
		}
	}

	printf("\n\n당신은 총 %d개 맞췄습니다.\n", count);

	return 0;
}

int getRandomNumber(int level)
{
	return rand() % (level * 7) + 1;
}

void showQuestion(int level, int num1, int num2)
{
	printf("\n\n\n########## %d번째 비밀번호 ##########\n", level);
	printf("\n\t%d x %d 는?\n\n", num1, num2);
	printf("##############################\n");
	printf("\n비밀번호를 입력하세요 (종료 : -1) >> ");
}

void success()
{
	printf("Good!\n");
}

void fail()
{
	printf("Fail...\n");
}
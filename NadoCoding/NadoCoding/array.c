#include <stdio.h>

int main_array(void)
{
	srand(time(NULL));
	printf("\n\n === 아빠는 대머리 게임 === \n\n");
	// 사용자 입력
	int answer;
	// 0~3까지 난수
	int treatment = rand() % 4;

	// 현재 게임에 보여줄 병의 개수
	int cntShowBottle = 0;
	// 이전 게임에 보여준 병의 개수
	int prevCntShowBottle = 0;
	// 서로 보여주는 병의 개수를 다르게 하여 답을 유추하도록 함

	// 총 3번의 기회를 줄 때
	for (int i = 0; i < 3; i++)
	{
		int bottle[] = { 0, 0, 0, 0 };

		do {
			// 2 ~ 3
			cntShowBottle = rand() % 2 + 2;
		}
		// 현재 병의 개수가 이전과 다르면 그만둬
		while (cntShowBottle == prevCntShowBottle);
		prevCntShowBottle = cntShowBottle;
		// 보여줄 병 중에 발모제가 포함되었는지 여부
		int isIncluded = 0;
		printf(" > %d번째 시도 : ", i);

		// 보여줄 병 종류 선택
		for (int j = 0; j < cntShowBottle; j++)
		{
			// 0 ~ 3
			int randBottle = rand() % 4;

			// 아직 선택되지 않은 병일 경우 선택 처리
			if (bottle[randBottle] == 0)
			{
				bottle[randBottle] = 1;
				if (randBottle == treatment)
				{
					isIncluded = 1;
				}
			}
			// 이미 선택된 병이면 다시 선택
			else
			{
				j--;
			}
		}

		// 사용자에게 문제 표시
		for (int k = 0; k < 4; k++)
		{
			if (bottle[k] == 1)
			{
				printf("%d ", k + 1);
			}
		}
		printf("물약을 머리에 바릅니다.\n\n");

		if (isIncluded == 1)
		{
			printf(" >> 성공 ! 머리가 났어요 !!\n");
		}
		else
		{
			printf(" >> 실패 ! 머리가 나지 않았어요..\n");
		}

		printf("\n... 계속하려면 아무키나 누르세요...\n\n");
		// 입력 받기 전 까지 대기
		getchar();
	}

	printf("\n\n발모제는 몇 번일까요? ");
	scanf_s("%d", &answer);

	if (answer == treatment + 1)
	{
		printf("\n >> 정답입니다!\n");
	}
	else
	{
		printf("\n >> 땡! 틀렸어요. 정답은 %d입니다.\n", treatment + 1);
	}
	return 0;
}
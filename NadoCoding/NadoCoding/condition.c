#include <stdio.h>

// main함수 정의 후 사용
int main_condition()
{	
	// Up and Down
	srand(time(NULL));
	// 1 ~ 100까지의 난수
	int num = rand() % 100 + 1;
	printf("숫자 : %d\n", num);
	// 입력되는 값
	int answer = 0;
	// 주어진 기회 값
	int chance = 5;
	while (chance)
	{
		printf("남은 기회 %d 번 \n", chance--);
		printf("숫자를 맞춰보세요 ");
		scanf_s("%d", &answer);

		if (answer > num) {
			printf("입력한 숫자는 정답보다 큽니다.\n");
		}
		if (answer < num) {
			printf("입력한 숫자는 정답보다 작습니다.\n");
		}
		if (answer == num) {
			printf("정답입니다.\n");
			break;
		}
		if (!chance) {
			printf("꽝! 모든 기회를 소모했습니다.\n");
			break;
		}
	}
	return 0;
}
#include <stdio.h>

// main�Լ� ���� �� ���
int main_condition()
{	
	// Up and Down
	srand(time(NULL));
	// 1 ~ 100������ ����
	int num = rand() % 100 + 1;
	printf("���� : %d\n", num);
	// �ԷµǴ� ��
	int answer = 0;
	// �־��� ��ȸ ��
	int chance = 5;
	while (chance)
	{
		printf("���� ��ȸ %d �� \n", chance--);
		printf("���ڸ� ���纸���� ");
		scanf_s("%d", &answer);

		if (answer > num) {
			printf("�Է��� ���ڴ� ���亸�� Ů�ϴ�.\n");
		}
		if (answer < num) {
			printf("�Է��� ���ڴ� ���亸�� �۽��ϴ�.\n");
		}
		if (answer == num) {
			printf("�����Դϴ�.\n");
			break;
		}
		if (!chance) {
			printf("��! ��� ��ȸ�� �Ҹ��߽��ϴ�.\n");
			break;
		}
	}
	return 0;
}
#include<stdio.h>

// main�Լ� ���� �� ���
int main_loof(void)
{
	// �Ƕ�̵� �ױ�
	int floor = 0;
	printf("�� ������ �װڽ��ϱ�?\n");
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
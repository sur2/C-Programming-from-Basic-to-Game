#include <stdio.h>

int main_array(void)
{
	srand(time(NULL));
	printf("\n\n === �ƺ��� ��Ӹ� ���� === \n\n");
	// ����� �Է�
	int answer;
	// 0~3���� ����
	int treatment = rand() % 4;

	// ���� ���ӿ� ������ ���� ����
	int cntShowBottle = 0;
	// ���� ���ӿ� ������ ���� ����
	int prevCntShowBottle = 0;
	// ���� �����ִ� ���� ������ �ٸ��� �Ͽ� ���� �����ϵ��� ��

	// �� 3���� ��ȸ�� �� ��
	for (int i = 0; i < 3; i++)
	{
		int bottle[] = { 0, 0, 0, 0 };

		do {
			// 2 ~ 3
			cntShowBottle = rand() % 2 + 2;
		}
		// ���� ���� ������ ������ �ٸ��� �׸���
		while (cntShowBottle == prevCntShowBottle);
		prevCntShowBottle = cntShowBottle;
		// ������ �� �߿� �߸����� ���ԵǾ����� ����
		int isIncluded = 0;
		printf(" > %d��° �õ� : ", i);

		// ������ �� ���� ����
		for (int j = 0; j < cntShowBottle; j++)
		{
			// 0 ~ 3
			int randBottle = rand() % 4;

			// ���� ���õ��� ���� ���� ��� ���� ó��
			if (bottle[randBottle] == 0)
			{
				bottle[randBottle] = 1;
				if (randBottle == treatment)
				{
					isIncluded = 1;
				}
			}
			// �̹� ���õ� ���̸� �ٽ� ����
			else
			{
				j--;
			}
		}

		// ����ڿ��� ���� ǥ��
		for (int k = 0; k < 4; k++)
		{
			if (bottle[k] == 1)
			{
				printf("%d ", k + 1);
			}
		}
		printf("������ �Ӹ��� �ٸ��ϴ�.\n\n");

		if (isIncluded == 1)
		{
			printf(" >> ���� ! �Ӹ��� ����� !!\n");
		}
		else
		{
			printf(" >> ���� ! �Ӹ��� ���� �ʾҾ��..\n");
		}

		printf("\n... ����Ϸ��� �ƹ�Ű�� ��������...\n\n");
		// �Է� �ޱ� �� ���� ���
		getchar();
	}

	printf("\n\n�߸����� �� ���ϱ��? ");
	scanf_s("%d", &answer);

	if (answer == treatment + 1)
	{
		printf("\n >> �����Դϴ�!\n");
	}
	else
	{
		printf("\n >> ��! Ʋ�Ⱦ��. ������ %d�Դϴ�.\n", treatment + 1);
	}
	return 0;
}
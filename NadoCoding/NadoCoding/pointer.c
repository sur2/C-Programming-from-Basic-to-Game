#include <stdio.h>
#include <time.h>

// ����Ⱑ 6������ �ִ�
// �̵��� ���׿� ��� �ִµ�, �縷�̴�
// �縷�� �ʹ� ����, �����ؼ� ���� ���� ���� �����Ѵ�
// ���� �� �����ϱ� ���� �������� ���׿� ���� �༭ ����⸦ ������Ѵ�
// ������ �ð��� �������� ���� Ŀ����... ���߿��� ��ƸԴ´� ^^

int level;
int arrayFish[6];
int* cursor;

void initData();
void printFishes();
void decreaseWater(long elapsedTime);
int checkFishAlive();

int main_pointer()
{
	long startTime = 0; // ���� ���� �ð�
	long totalElapsedTime = 0; // �� ��� �ð�
	long prevElapsedTime = 0; // ���� ��� �ð� (�ֱٿ� ���� �� �ð� ����)

	int num; // �� �� ���׿� ���� �� ������, ����� �Է�
	initData();

	cursor = arrayFish; // cursor[0], cursor[1], ... cursor[6]

	startTime = clock(); // ���� �ð��� millisecond (1000���� 1��) ������ ��ȯ, include time.h
	while (1)
	{
		printFishes();
		printf("�� �� ���׿� ���� �ֽðھ��? ");
		scanf_s("%d", &num);

		// �Է°� üũ : ���۵� ����
		if (num < 1 || num > 6)
		{
			printf("\n�Է°��� �߸��Ǿ����ϴ�. %d\n", num);
			continue;
		}

		// �� ��� �ð�
		totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC;
		printf("�� ��� �ð� : %ld ��\n", totalElapsedTime);

		// ������ ���� �� �ð�(���������� ���� �� �ð�) ���ķ� �帥 �ð�
		prevElapsedTime = totalElapsedTime - prevElapsedTime;
		printf("�ֱ� ��� �ð� : %ld ��\n", prevElapsedTime);

		// ������ ���� ����(����)
		decreaseWater(prevElapsedTime);

		// ����ڰ� �Է��� ���׿� ���� �ش�
		// 1. ������ ���� 0 �̸�? ���� ���� �ʴ´� ... �̹� ����Ⱑ �׾��� ����
		if (cursor[num - 1] <= 0)
		{
			printf("%d �� ������ �̹� �׾����ϴ�.. ���� ���� �ʽ��ϴ�.\n", num);
		}
		// 2. ������ ���� 0 �� �ƴ� ���? ���� �ش�! �ٸ� 100�� ���� �ʴ��� üũ
		else if (cursor[num - 1] + 1 <= 100)
		{
			// ���� �ش�
			printf("%d �� ���׿� ���� �ش�\n\n", num);
			cursor[num - 1] += 1; // cursor[num - 1] = cursor[num - 1] + 1
		}

		// �������� �� ������ Ȯ��(20�ʸ��� ������ ����)
		if (totalElapsedTime / 20 > level - 1)
		{
			level++; 
			printf("*** �� ������ ! ���� %d �������� %d ������ ���׷��̵� ***\n\n", level - 1, level);
		
			// ���� ���� : 5
			if (level == 5)
			{
				printf("\n\n�����մϴ�. �ְ� ������ �޼��߽��ϴ�. ������ �����մϴ�.\n");
				exit(0);
			}
		}

		// ����Ⱑ �׾����� Ȯ��
		if (checkFishAlive() == 0)
		{
			// ����� ��� ����
			printf("��� ����Ⱑ �׾����ϴ�.\n����� ������ %d�Դϴ�.\n- END -\n", level);
			exit(0);
		}
		else
		{
			// �ּ� �� ���� �̻��� ������ �������
			printf("����Ⱑ ���� ����ֽ��ϴ�.\n");
		}
		// 10s -> 15s (prev : 5s -> total : 15s) -> 25s (prev : 15s) 
		prevElapsedTime = totalElapsedTime;
	}	

	return 0;
}

void initData()
{
	level = 1; // ���� ����(1~5)
	for (int i = 0; i < 6; i++)
	{
		arrayFish[i] = 100; // ������ �� ���� (0~100)
	}
}

void printFishes()
{
	printf("%3d�� %3d�� %3d�� %3d�� %3d�� %3d��\n", 1, 2, 3, 4, 5, 6);
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
		arrayFish[i] -= (level * 3 * (int)elapsedTime); // 3 : ���̵� ������ ���� ��
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

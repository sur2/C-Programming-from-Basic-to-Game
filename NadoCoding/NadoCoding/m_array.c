#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 10������ ���� �ٸ� ���� (�� ī�� 2�徿)
// ����ڷκ��� 2���� �Է°��� �޾Ƽ� ���� ������ ã���� ī�� ������
// ��� ���� ���� ã���� ���� ����
// �� ���� Ƚ�� �˷��ֱ�


int arrayAnimal[4][5]; // ī�� ���� (4*5=20��)
int checkAnimal[4][5]; // ���������� ���� Ȯ��
char* strAnimal[10];

void initAnimalArray();
void initAnimalName();
void shuffleAnimal();
int getEmptyPosition();
int conv_pos_x(int x);
int conv_pos_y(int y);
void printAnimals();
void printQuestion();
int foundAllAnimals();

int main_m_array(void)
{
	srand((unsigned)time(NULL));

	initAnimalArray();
	initAnimalName();

	shuffleAnimal();

	// ���� Ƚ��
	int failCount = 0;

	while (1) {
		// ����ڰ� ������ ù ��° ��
		int select1 = 0;
		// ����ڰ� ������ �� ��° ��
		int select2 = 0;

		// ���� ��ġ ���
		printAnimals();
		// ���� ��� (ī�� ����)
		printQuestion();
		printf("������ ī�带 2�� ��������");
		scanf_s("%d %d", &select1, &select2);

		// ���� ī�� ���� �� ��ȿ
		if (select1 == select2)
		{
			continue;
		}

		// ��ǥ�� �ش��ϴ� ī�带 ������ ���� ������ �Ȱ����� Ȯ��
		// ���� ��ǥ�� (x, y)�� ��ȯ
		int firstSelect_x = conv_pos_x(select1);
		int firstSelect_y = conv_pos_y(select1);

		int secondSelect_x = conv_pos_x(select2);
		int secondSelect_y = conv_pos_y(select2);

		// ���� ������ ���
		if (
			(checkAnimal[firstSelect_x][firstSelect_y] == 0
				&& checkAnimal[secondSelect_x][secondSelect_y] == 0)
			&&
			(arrayAnimal[firstSelect_x][firstSelect_y]
				== arrayAnimal[secondSelect_x][secondSelect_y])
			)
		{
			printf("\n\n����! : %s �߰�\n\n", strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
			checkAnimal[firstSelect_x][firstSelect_y] = 1;
			checkAnimal[secondSelect_x][secondSelect_y] = 1;
		}
		// �ٸ� ������ ���
		else
		{
			printf("\n\n ��!! (Ʋ�Ȱų�, �̹� ������ ī���Դϴ�.)\n");
			printf("%d : %s\n", select1, strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
			printf("%d : %s\n", select2, strAnimal[arrayAnimal[secondSelect_x][secondSelect_y]]);
			printf("\n\n");

			failCount++;
		}

		// ��� ������ ã�Ҵ��� ����, 1 : ��, 0 : ����
		if (foundAllAnimals() == 1)
		{
			printf("\n\n �����մϴ�! ��� ������ �� ã�ҳ׿�. \n");
			printf("���ݱ��� �� %d �� �Ǽ��Ͽ����ϴ�.\n", failCount);
			break;
		}
	}

	return 0;
}

void initAnimalArray()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			arrayAnimal[i][j] = -1;
		}
	}
}

void initAnimalName()
{
	strAnimal[0] = "������";
	strAnimal[1] = "�ϸ�";
	strAnimal[2] = "������";
	strAnimal[3] = "������";
	strAnimal[4] = "����";

	strAnimal[5] = "�ڳ���";
	strAnimal[6] = "�⸰";
	strAnimal[7] = "��Ÿ";
	strAnimal[8] = "Ÿ��";
	strAnimal[9] = "ȣ����";
}

void shuffleAnimal()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			int pos = getEmptyPosition();
			int x = conv_pos_x(pos);
			int y = conv_pos_y(pos);

			arrayAnimal[x][y] = i;
		}
	}
}

// ��ǥ���� �� ���� ã��
int getEmptyPosition()
{
	while (1)
	{
		int randPos = rand() % 20; // 0 ~ 19������ ����
		// 19 -> (3, 4)
		int x = conv_pos_x(randPos);
		int y = conv_pos_y(randPos);

		if (arrayAnimal[x][y] == -1)
		{
			return randPos;
		}
	}
	return 0;
}

int conv_pos_x(int x)
{
	return x / 5;
}
int conv_pos_y(int y)
{
	return y % 5;
}

void printAnimals()
{
	printf("\n=== ��! ����ε� ���� �����帲 ���� ===\n\n");
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%8s", strAnimal[arrayAnimal[i][j]]);
		}
		printf("\n");
	}
	printf("=======================================\n\n");
}
// ���� ���(ī�� ����)
void printQuestion()
{
	printf("\n\n(����)\n");
	int seq = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			// ī�带 ����� ������ �������� '���� �̸�'
			if (checkAnimal[i][j] != 0)
			{
				printf("%8s", strAnimal[arrayAnimal[i][j]]);
			}
			// ���� ������ �������� (������ ����������) �޸� -> ��ġ�� ��Ÿ���� ����
			else
			{
				printf("%8d", seq);
			}
			seq++;
		}
		printf("\n");
	}
}

int foundAllAnimals()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (checkAnimal[i][j] == 0)
			{
				return 0;
			}
		}
	}
	return 1;
}
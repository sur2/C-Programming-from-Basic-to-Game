#include<stdio.h>

// main ���� �� ���
int main_printf_scanf()
{
	// ����, ���, �����

	// ����
	// �������� �������� ������ �Լ�(���� �ۼ�)
	// �̸�? ����? ������? Ű? ���˸�?

	char name[256];
	printf("�̸��� �����Դϱ�?\n");
	scanf_s("%s", name, sizeof(name));
	
	int age;
	printf("�� ���Դϱ�?\n");
	scanf_s("%d", &age);
	
	float weight;
	printf("�����Դ� �� kg�Դϱ�?\n");
	scanf_s("%f", &weight);

	double height;
	printf("Ű�� �� cm�Դϱ�?\n");
	scanf_s("%lf", &height);
	
	char what[256];
	printf("� ���˸� ���������ϱ�?\n");
	scanf_s("%s", what, sizeof(what));
	
	// ���� ���� ���
	printf("\n\n--- ������ ���� ---\n\n");
	printf("�̸�		: %s\n", name);
	printf("����		: %d\n", age);
	printf("������		: %0.2f\n", weight);
	printf("Ű		: %.2lf\n", height);
	printf("����		: %s\n", what);

	return 0;
}
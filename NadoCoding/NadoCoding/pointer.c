#include <stdio.h>

int main()
{
	int n = 10;
	int* ptr = &n;
	printf("%d %d\n", n, *ptr); // 10 10
	printf("%p %p\n", &n, ptr); // �޸��ּ� �޸��ּ�
	*ptr = 20;
	printf("%d\n", n); // 20
	return 0;
}
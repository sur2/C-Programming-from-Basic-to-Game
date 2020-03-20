#include <stdio.h>

int main()
{
	
	
	int arr[] = { 0, 1, 2 };
	int* ap = arr;
	*arr = 100;
	*(arr + 1) = 200;
	*(arr + 2) = 300;
	printf("%d %d %d\n", arr[0], arr[1], arr[2]);
	return 0;
}
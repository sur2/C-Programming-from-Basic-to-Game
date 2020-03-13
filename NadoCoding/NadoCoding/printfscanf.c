#include<stdio.h>

// main 정의 후 사용
int main_printf_scanf()
{
	// 변수, 상수, 입출력

	// 질문
	// 경찰관이 범죄자의 정보를 입수(조서 작성)
	// 이름? 나이? 몸무게? 키? 범죄명?

	char name[256];
	printf("이름이 무엇입니까?\n");
	scanf_s("%s", name, sizeof(name));
	
	int age;
	printf("몇 살입니까?\n");
	scanf_s("%d", &age);
	
	float weight;
	printf("몸무게는 몇 kg입니까?\n");
	scanf_s("%f", &weight);

	double height;
	printf("키는 몇 cm입니까?\n");
	scanf_s("%lf", &height);
	
	char what[256];
	printf("어떤 범죄를 저질렀습니까?\n");
	scanf_s("%s", what, sizeof(what));
	
	// 조서 내용 출력
	printf("\n\n--- 범죄자 정보 ---\n\n");
	printf("이름		: %s\n", name);
	printf("나이		: %d\n", age);
	printf("몸무게		: %0.2f\n", weight);
	printf("키		: %.2lf\n", height);
	printf("범죄		: %s\n", what);

	return 0;
}
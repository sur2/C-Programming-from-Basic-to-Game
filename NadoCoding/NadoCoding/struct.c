#include<stdio.h>

struct gameInfo {
	char* name;
	int year;
	int price;
	char* company;

	struct gameInfo* friendGame; // 구조체 속 변수로 구조체 선언
};

int main(void)
{
	struct gameInfo game1;
	game1.name = "1번게임";
	game1.year = 2020;
	game1.price = 1000;
	game1.company = "com";

	struct gameInfo game2 = { "2번게임", 2020, 500, "com" };

	printf("%s, %d, %d, %s\n", game1.name, game1.year, game1.price, game1.company);
	printf("%s, %d, %d, %s\n", game2.name, game2.year, game2.price, game2.company);

	struct gameInfo gameArray[2] = {
		{"3번 게임", 2020, 1000, "com"},
		{"4번 게임", 2020, 5000, "com"}
	};

	printf("%s, %d, %d, %s\n", gameArray[0].name, gameArray[0].year, (*gameArray).price, (*gameArray).company);
	printf("%s, %d, %d, %s\n", gameArray[1].name, gameArray[1].year, (*(gameArray + 1)).price, (*(gameArray + 1)).company);


	struct gameInfo* gamePtr;
	gamePtr = &game1;
	(*gamePtr).name = "새로운 1번 게임";
	gamePtr->year = 2020;
	gamePtr[0].price = 3300;
	gamePtr->company = "com";

	printf("%s, %d, %d, %s\n", game1.name, game1.year, game1.price, game1.company);

	game1.friendGame = &game2;
	printf("%s, %d, %d, %s\n", game1.friendGame->name, game1.friendGame->year, game1.friendGame->price, game1.friendGame->company);



	return 0;
}
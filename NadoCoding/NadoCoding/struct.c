#include<stdio.h>

struct gameInfo {
	char* name;
	int year;
	int price;
	char* company;

	struct gameInfo* friendGame; // ����ü �� ������ ����ü ����
};

int main(void)
{
	struct gameInfo game1;
	game1.name = "1������";
	game1.year = 2020;
	game1.price = 1000;
	game1.company = "com";

	struct gameInfo game2 = { "2������", 2020, 500, "com" };

	printf("%s, %d, %d, %s\n", game1.name, game1.year, game1.price, game1.company);
	printf("%s, %d, %d, %s\n", game2.name, game2.year, game2.price, game2.company);

	struct gameInfo gameArray[2] = {
		{"3�� ����", 2020, 1000, "com"},
		{"4�� ����", 2020, 5000, "com"}
	};

	printf("%s, %d, %d, %s\n", gameArray[0].name, gameArray[0].year, (*gameArray).price, (*gameArray).company);
	printf("%s, %d, %d, %s\n", gameArray[1].name, gameArray[1].year, (*(gameArray + 1)).price, (*(gameArray + 1)).company);


	struct gameInfo* gamePtr;
	gamePtr = &game1;
	(*gamePtr).name = "���ο� 1�� ����";
	gamePtr->year = 2020;
	gamePtr[0].price = 3300;
	gamePtr->company = "com";

	printf("%s, %d, %d, %s\n", game1.name, game1.year, game1.price, game1.company);

	game1.friendGame = &game2;
	printf("%s, %d, %d, %s\n", game1.friendGame->name, game1.friendGame->year, game1.friendGame->price, game1.friendGame->company);



	return 0;
}
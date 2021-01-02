#include "GameStatus.h"
char PrintGameStatus(int currentAmountOfCoins, islandPointer currentIsland)
{
	printf("Status coina: %d\n", currentAmountOfCoins);
	printf("Putujemo na iduci otok!\n");
	printf("Imaj na umu da bi ti se skuplje putovanje moglo isplatiti!\n");
	printf("Lijevo $ %d $ coina!\t Desno $ %d $ coina!\n", currentIsland->leftNext->coins, currentIsland->rightNext->coins);
	printf("Lijevo - unesi 'L'\t Desno - unesi 'D'\n");
	char choice;
	scanf(" %c", &choice);
	return choice;
}
int GameOver()
{
	printf("### GAME OVER ###\n");
	return 0;
}
char PlayAgain()
{
	char choice;
	printf("Ako zelis ponovno igrati unesi D!\n");
	scanf(" %c", &choice);
	return choice;
}
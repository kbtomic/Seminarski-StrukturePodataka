#include "Flow.h"
#include "NumberOfIslands.h"
#include "GameStatus.h"
#include "Travels.h"
#include "CoinCalculator.h"
#include "MainPrize.h"
#include "Print.h"
int Game(islandPointer islandsWithClue, islandPointer islandsWithoutClue, islandPointer start, stackPointer stackHead, int numberOfIslands)
{
	system("cls");
	printf("### TREASURE HUNT GAME ###\n");
	int numberOfFoundClues = 0;
	int flagForGameOver = 0;
	unsigned int currentAmountOfCoins = MAX_AMOUNT_OF_COINS;
	islandPointer currentIsland = start;
	while (numberOfFoundClues != numberOfIslands && !flagForGameOver)
	{
		islandPointer parentIsland = currentIsland;
		PrintCurrentPath(currentIsland, stackHead);
		char choice = PrintGameStatus(currentAmountOfCoins, currentIsland);
		system("cls");
		if (toupper(choice) == 'L')
		{
			currentIsland = TravelToLeftIsland(&currentAmountOfCoins, &numberOfFoundClues, start, currentIsland, stackHead, &flagForGameOver);
		}
		else if (toupper(choice) == 'D')
		{
			currentIsland = TravelToRightIsland(&currentAmountOfCoins, &numberOfFoundClues, start, currentIsland, stackHead, &flagForGameOver);
		}
		else
			printf("Pogresan unos!\n");
	}
	if (numberOfFoundClues == numberOfIslands)
	{
		printf("Cestitam, pronasao si sve tragove!!!\n");
		if (HaveEnoughCoins(currentAmountOfCoins, COINS_AMOUNT_FOR_RESPAWN_OR_MAIN_PRIZE))
		{
			OpenMainPrize(islandsWithClue, stackHead);
		}
		else
		{
			DontOpenMainPrize(currentAmountOfCoins, &numberOfFoundClues, stackHead);
		}
	}
	return 0;
}
#include "MainPrize.h"
#include "Stack.h"
int OpenMainPrize(islandPointer islandsWithClue, stackPointer stackHead)
{
	while (islandsWithClue)
	{
		printf("Znak je: %c\n", islandsWithClue->clue);
		islandsWithClue = islandsWithClue->next;
	}
	printf("Konacno rjesenje je: HAVAJI!!!");
	CleanStack(stackHead);
	return 0;
}
int DontOpenMainPrize(int currentAmountOfCoins, int* numberOfFoundClues, stackPointer stackHead)
{
	printf("Trenutno imas %d coina, a nazalost nedostaje ti %d coina da saznas konacno rjesenje :(!\n", currentAmountOfCoins, COINS_AMOUNT_FOR_RESPAWN_OR_MAIN_PRIZE - currentAmountOfCoins);
	*numberOfFoundClues = 0;
	CleanStack(stackHead);
	return 0;
}
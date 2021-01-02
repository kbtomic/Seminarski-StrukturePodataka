#include "Coins.h"
#include "RandomGenerator.h"
int ReadCoinsFromFile(islandPointer islandsWithClue, islandPointer islandsWithoutClue, char* nameOfFile)
{
	FILE* fp = NULL;
	fp = fopen(nameOfFile, "r");
	if (fp == NULL)
	{
		printf("Neuspjesno otvaranje datoteke!\n");
		return fp;
	}
	int lowerBoundWithClue = 0, upperBoundWithClue = 0, lowerBoundWithoutClue = 0, upperBoundWithoutClue = 0;
	while (!feof(fp))
	{
		fscanf(fp, "%d %d\n", &lowerBoundWithClue, &upperBoundWithClue);
		fscanf(fp, "%d %d\n", &lowerBoundWithoutClue, &upperBoundWithoutClue);
	}
	SetCoinsToIslands(islandsWithClue, lowerBoundWithClue, upperBoundWithClue);
	SetCoinsToIslands(islandsWithoutClue, lowerBoundWithoutClue, upperBoundWithoutClue);
	return 0;
}
int SetCoinsToIslands(islandPointer island, int lowerBound, int upperBound)
{
	while (island)
	{
		island->coins = GenerateRandom(lowerBound, upperBound);
		island = island->next;
	}
	return 0;
}
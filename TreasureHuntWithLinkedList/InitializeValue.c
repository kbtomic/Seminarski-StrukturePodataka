#include "InitializeValue.h"
#include "ReadIslands.h"
#include "ReadLevel.h"
#include "StartIsland.h"
#include "ShuffleIslands.h"
#include "NumberOfIslands.h"
#include "Generator.h"
#include "Stack.h"
#include "PointersOfDeathlyIslands.h"
#include "Coins.h"
#include "Flow.h"
int InitializeGame(filePointer currentLevel)
{
	islandPointer start = CreateStartIsland();
	stackPointer stackHead = CreateStackHead();
	PushStack(start, stackHead);
	islandPointer headOfIslandsWithClue = CreateStartIsland();
	islandPointer headOfIslandsWithoutClue = CreateStartIsland();
	islandPointer islandsWithClue = CreateListOfIslands(currentLevel->nameOfFile, headOfIslandsWithClue);
	islandPointer islandsWithoutClue = CreateListOfIslands(currentLevel->next->nameOfFile, headOfIslandsWithoutClue);
	SetPointersOfDeathlyIslands(islandsWithoutClue->next, start);
	ReadCoinsFromFile(islandsWithClue->next, islandsWithoutClue->next, currentLevel->next->next->nameOfFile);
	int numberOfIslands = CountNumberOfIslands(islandsWithClue);
	Shuffle(islandsWithClue, numberOfIslands);
	Shuffle(islandsWithoutClue, numberOfIslands);
	GeneratePath(islandsWithClue->next, islandsWithoutClue->next, start, numberOfIslands);
	Game(islandsWithClue->next, islandsWithoutClue->next, start, stackHead, numberOfIslands);
	return 0;
}
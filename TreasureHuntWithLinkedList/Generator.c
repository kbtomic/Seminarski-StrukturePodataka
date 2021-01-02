#include "Generator.h"
#include "RandomGenerator.h"
int GeneratePath(islandPointer islandsWithClue, islandPointer islandsWithoutClue, islandPointer start, int numberOfIslands)
{
	for (int i = 0; i < numberOfIslands; i++)
	{
		if (GenerateRandom(1, 2) == 1) {
			start->leftNext = islandsWithClue;
			start->rightNext = islandsWithoutClue;
			start = start->leftNext;
		}
		else
		{
			start->rightNext = islandsWithClue;
			start->leftNext = islandsWithoutClue;
			start = start->rightNext;
		}
		islandsWithClue = islandsWithClue->next;
		islandsWithoutClue = islandsWithoutClue->next;
	}
	return 0;
}
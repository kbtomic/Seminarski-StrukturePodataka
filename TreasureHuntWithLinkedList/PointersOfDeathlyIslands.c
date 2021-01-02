#include "PointersOfDeathlyIslands.h"

int SetPointersOfDeathlyIslands(islandPointer currentIsland, islandPointer start)
{
	while (currentIsland)
	{
		if (currentIsland->clue == 'X')
		{
			currentIsland->leftNext = start;
			currentIsland->rightNext = start;
		}
		currentIsland = currentIsland->next;
	}
	return 0;
}
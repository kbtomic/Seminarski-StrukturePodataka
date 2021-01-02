#include "IslandType.h"
int isClueIsland(islandPointer currentIsland)
{
	return currentIsland->hasClue;
}
int isDeathlyIsland(islandPointer currentIsland, islandPointer start)
{
	if (currentIsland->leftNext == start && currentIsland->rightNext == start)
		return 1;
	else
		return 0;
}
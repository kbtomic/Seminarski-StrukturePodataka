#include "NumberOfIslands.h"
int CountNumberOfIslands(islandPointer headIsland)
{
	int numberOfIslands = 0;
	while (headIsland->next != NULL)
	{
		numberOfIslands++;
		headIsland = headIsland->next;
	}
	return numberOfIslands;
}
#include "StartIsland.h"
#include "AllocateMemory.h"

islandPointer CreateStartIsland()
{
	islandPointer start = AllocateMemoryForIsland();
	strcpy(start->islandName, "Start");
	start->index = 0;
	return start;
}
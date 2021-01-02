#include "ReadIslands.h"
#include "AllocateMemory.h"

islandPointer CreateListOfIslands(char* nameOfFile, islandPointer start)
{
	FILE* fp = fopen(nameOfFile, "r");
	if (!fp)
	{
		printf("Neuspjesno otvaranje datoteke!\n");
		return fp;
	}
	islandPointer current = start;
	while (!feof(fp))
	{
		islandPointer nextIsland = AllocateMemoryForIsland();
		fscanf(fp, "%d %d %c %s %[^\n]\n", &nextIsland->index, &nextIsland->hasClue, &nextIsland->clue, nextIsland->islandName, nextIsland->description);
		current->next = nextIsland;
		current = current->next;
	}
	fclose(fp);
	return start;
}
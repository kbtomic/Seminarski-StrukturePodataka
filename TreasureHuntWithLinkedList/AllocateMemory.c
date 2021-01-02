#include "AllocateMemory.h"

filePointer AllocateMemoryForFile()
{
	filePointer file = (filePointer)malloc(sizeof(FileElement));
	if (!file)
	{
		printf("Neuspjesna alokacija memorije!\n");
		return file;
	}
	file->next = NULL;
	return file;
}
islandPointer AllocateMemoryForIsland()
{
	islandPointer island = (islandPointer)malloc(sizeof(Island));
	if (!island)
	{
		printf("Neuspjesna alokacija memorije!\n");
		return island;
	}
	island->leftNext = NULL;
	island->rightNext = NULL;
	island->next = NULL;
	return island;
}
stackPointer AllocateMemoryForStack()
{
	stackPointer newStackElement = (stackPointer)malloc(sizeof(Stack));
	if (!newStackElement)
	{
		printf("Can not allocate memory!\n");
	}
	return newStackElement;
}
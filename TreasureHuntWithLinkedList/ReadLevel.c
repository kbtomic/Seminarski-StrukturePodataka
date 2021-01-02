#include "ReadLevel.h"
#include "AllocateMemory.h"
#include <string.h>

filePointer CreateListOfFilesForLevel(char* nameOfFile)
{
	FILE* fp = fopen(nameOfFile, "r");
	if (!fp)
	{
		printf("Neuspjesno otvaranje datoteke!\n");
		return fp;
	}
	filePointer headFile = AllocateMemoryForFile();
	filePointer currentFile = headFile;
	while (!feof(fp))
	{
		filePointer newFile = AllocateMemoryForFile();
		fscanf(fp, "%[^\n]\n", newFile->nameOfFile);
		currentFile->next = newFile;
		currentFile = currentFile->next;
	}
	fclose(fp);
	return headFile->next;
}

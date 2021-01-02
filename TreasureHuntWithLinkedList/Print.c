#include "Print.h"
int PrintCurrentPath(islandPointer current, stackPointer stackHead)
{
	printf("Mapa: ");
	stackPointer start = stackHead->next;
	char stringToPrint[MAX_STRING_LENGTH] = "";
	while (start)
	{
		strcat(stringToPrint, start->data->islandName);
		strcat(stringToPrint, "->");
		start = start->next;
	}
	strcat(stringToPrint, "...");
	printf("%s\n", stringToPrint);
	return 0;
}
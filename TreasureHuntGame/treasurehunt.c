#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<ctype.h>

#define MAX_ISLAND_NAME_LENGTH 100
#define MAX_DESCRIPTION_LENGTH 256
#define NUMBER_OF_CLUE_ISLANDS 6
#define INDEX_OF_CLUE_ISLAND 2
#define INDEX_OF_NON_CLUE_ISLAND 1

typedef struct island* islandPointer;
typedef struct stack* stackPointer;
typedef struct island {
	char islandName[MAX_ISLAND_NAME_LENGTH];
	islandPointer leftNext;
	islandPointer rightNext;
	char description[MAX_DESCRIPTION_LENGTH];
	int hasClue;
	char clue;
}Island;

typedef struct stack {
	islandPointer data;
	stackPointer next;
} Stack;

int GeneratePath(islandPointer, islandPointer, islandPointer);
int ShuffleIsland(islandPointer islands);
int GenerateRandom(int, int);
int StartGame(islandPointer, islandPointer, islandPointer, stackPointer);
int PushStack(islandPointer, stackPointer);
stackPointer AllocateMemoryForStack();
islandPointer PopStack(stackPointer);
int CleanStack(stackPointer);
int PrintCurrentPath(islandPointer, stackPointer);
int main()
{
	srand(time(NULL));

	Island start;
	strcpy(start.islandName, "Start");
	start.leftNext = NULL;
	start.rightNext = NULL;

	Stack stackHead;
	stackHead.data = NULL;
	stackHead.next = NULL;

	PushStack(&start, &stackHead);

	Island hula;
	strcpy(hula.islandName, "Hula");
	strcpy(hula.description, "Zaplesimo zajedno jer si dosao na hula otok plesa. Uz to nabaci i osmijeh jer si pronasao novi trag!");
	hula.hasClue = 1;
	hula.clue = 'H';

	Island akvarij;
	strcpy(akvarij.islandName, "Akvarij");
	strcpy(akvarij.description, "Dobrodosao na otok akvarija. Zaplivaj s ribicama i nabaci osmijeh jer si pronasao novi trag!");
	akvarij.hasClue = 1;
	akvarij.clue = 'A';

	Island vulkan;
	strcpy(vulkan.islandName, "Vulkan");
	strcpy(vulkan.description, "Dobrodosao na otok vulkana. Cuvaj glavu da ne bi ostao bez nje! Riskirati zivot se isplati jer si pronasao novi trag!");
	vulkan.clue = 'V';

	Island ananas;
	strcpy(ananas.islandName, "Ananas");
	strcpy(ananas.description, "Pripremi se za obilnu gozbu jer si dosao na otok ananasa. Uzivaj u ananasima i razveseli se dodatno jer si pronasao novi trag!");
	ananas.hasClue = 1;
	ananas.clue = 'A';

	Island jezero;
	strcpy(jezero.islandName, "Jezero");
	strcpy(jezero.description, "Zaplivajmo zajedno jer si dosao na otok jezera. Bistra jezera ti donose novi trag!");
	jezero.hasClue = 1;
	jezero.clue = 'J';

	Island istina;
	strcpy(istina.islandName, "Istina");
	strcpy(istina.description, "Dobrodosao na otok istine. Istina je da si pronasao novi trag!");
	istina.hasClue = 1;
	istina.clue = 'I';

	Island islandsWithClue[NUMBER_OF_CLUE_ISLANDS] = { hula, akvarij, vulkan, ananas, jezero, istina };

	Island smrt;
	strcpy(smrt.islandName, "Smrt");
	strcpy(smrt.description, "Dosao si na otok smrti i nazalost za tebe je igra gotova!");
	smrt.hasClue = 0;
	smrt.leftNext = &start;
	smrt.rightNext = &start;

	Island pirat;
	strcpy(pirat.islandName, "Pirat");
	strcpy(pirat.description, "Dosao si na otok pirata i nazalost za tebe je igra gotova!");
	pirat.hasClue = 0;
	pirat.leftNext = &start;
	pirat.rightNext = &start;

	Island surfer;
	strcpy(surfer.islandName, "Surfer");
	strcpy(surfer.description, "Pripremi se na valove jer si dosao na otok surfera! Nazalost, ovdje neces pronaci novi trag!");
	surfer.hasClue = 0;
	surfer.leftNext = NULL;
	surfer.rightNext = NULL;

	Island rat;
	strcpy(rat.islandName, "Rat");
	strcpy(rat.description, "Dobrodosao na ratni otok! Nazalost, ovdje neces pronaci novi trag!");
	rat.hasClue = 0;
	rat.leftNext = NULL;
	rat.rightNext = NULL;

	Island cvijece;
	strcpy(cvijece.islandName, "Cvijece");
	strcpy(cvijece.description, "Pomirisi miris divnog cvijeca jer si dosao na otok cvijeca. Nazalost, ovdje neces pronaci novi trag!");
	cvijece.hasClue = 0;
	cvijece.leftNext = NULL;
	cvijece.rightNext = NULL;

	Island plaza;
	strcpy(plaza.islandName, "Plaza");
	strcpy(plaza.description, "Zavali se i upij zraku sunca jer si dosao na otok pjescanih plazi. Prava prilika je za odmor bez potrage za tragom jer ga nema!");
	plaza.hasClue = 0;
	plaza.leftNext = NULL;
	plaza.rightNext = NULL;

	Island islandsWithoutClue[NUMBER_OF_CLUE_ISLANDS] = { smrt, pirat, surfer, rat, cvijece, plaza };
	char choice;
	do {
		StartGame(islandsWithClue, islandsWithoutClue, &start, &stackHead);
		printf("Ako zelis ponovno igrati unesi D!\n");
		choice = fgetc(stdin);
		getchar();
	} while (tolower(choice) == 'd');


	return 0;
}
int StartGame(islandPointer islandsWithClue, islandPointer islandsWithoutClue, islandPointer start, stackPointer stackHead)
{
	ShuffleIsland(islandsWithClue);
	ShuffleIsland(islandsWithoutClue);
	GeneratePath(islandsWithClue, islandsWithoutClue, start);
	int numberOfFoundClues = 0;
	islandPointer currentIsland = start;
	while (numberOfFoundClues != NUMBER_OF_CLUE_ISLANDS)
	{
		islandPointer parentIsland = currentIsland;
		PrintCurrentPath(currentIsland, stackHead);
		printf("Putujemo na iduci otok! Izaberi L ako zelis otici lijevo, a D ako zelis otici desno!\n");
		char choice = fgetc(stdin);
		getchar();
		if (toupper(choice) == 'L')
		{
			currentIsland = currentIsland->leftNext;
			PushStack(currentIsland, stackHead);
			printf("%s\n", currentIsland->description);
			if (currentIsland->hasClue)
			{
				printf("Clue is: %c\n", currentIsland->clue);
				numberOfFoundClues++;
			}
			else if (currentIsland->leftNext == start && currentIsland->rightNext == start)
			{
				currentIsland = start;
				CleanStack(stackHead);
				break;
			}
			else
			{
				PrintCurrentPath(currentIsland, stackHead);
				printf("Vracamo se na prethodni otok: %s kako bi nastavio svoje putovanje u drugom smjeru\n", parentIsland->islandName);
				PopStack(stackHead);
				currentIsland = parentIsland;
			}
		}
		else if (toupper(choice) == 'D')
		{
			currentIsland = currentIsland->rightNext;
			PushStack(currentIsland, stackHead);
			printf("%s\n", currentIsland->description);
			if (currentIsland->hasClue)
			{
				printf("Clue is: %c\n", currentIsland->clue);
				numberOfFoundClues++;
			}
			else if (currentIsland->leftNext == start && currentIsland->rightNext == start)
			{
				currentIsland = start;
				CleanStack(stackHead);
				break;
			}
			else
			{
				printf("Vracamo se na prethodni otok: %s kako bi nastavio svoje putovanje u drugom smjeru\n", parentIsland->islandName);
				PopStack(stackHead);
				currentIsland = parentIsland;
			}
		}
		else
			printf("Pogresan unos!\n");
	}
	if (numberOfFoundClues == NUMBER_OF_CLUE_ISLANDS)
	{
		printf("Cestitam, pronasao si sve znakove!!!");
		for (int i = 0; i < NUMBER_OF_CLUE_ISLANDS; i++)
		{
			printf("Znak je: %c\n", islandsWithClue[i].clue);
		}
		printf("Konacno rjesenje je: HAVAJI!!!");
		CleanStack(stackHead);
	}

	return 0;
}
int PrintCurrentPath(islandPointer current, stackPointer stackHead)
{
	stackPointer start = stackHead->next;
	char stringToPrint[MAX_ISLAND_NAME_LENGTH] = "";
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
int GeneratePath(islandPointer islandsWithClue, islandPointer islandsWithoutClue, islandPointer start)
{
	for (int i = 0; i < NUMBER_OF_CLUE_ISLANDS; i++)
	{
		if (GenerateRandom(INDEX_OF_CLUE_ISLAND, INDEX_OF_NON_CLUE_ISLAND) == INDEX_OF_CLUE_ISLAND) {
			start->leftNext = &islandsWithClue[i];
			start->rightNext = &islandsWithoutClue[i];
			start = start->leftNext;
		}
		else
		{
			start->rightNext = &islandsWithClue[i];
			start->leftNext = &islandsWithoutClue[i];
			start = start->rightNext;
		}
	}
	return 0;
}
int GenerateRandom(int upperBound, int lowerBound)
{
	return rand() % ((upperBound - lowerBound + 1) + lowerBound);
}
int ShuffleIsland(islandPointer islands)
{
	for (int i = 0; i < NUMBER_OF_CLUE_ISLANDS; i++)
	{
		Island temp = islands[i];
		int randomIndex = rand() % NUMBER_OF_CLUE_ISLANDS;

		islands[i] = islands[randomIndex];
		islands[randomIndex] = temp;
	}
	return 0;
}
islandPointer PopStack(stackPointer stackHead)
{
	stackPointer tempStackElement = stackHead->next, prev = stackHead->next;
	if (!tempStackElement->next)
		return NULL;
	while (tempStackElement->next)
	{
		prev = tempStackElement;
		tempStackElement = tempStackElement->next;
	}
	islandPointer island = tempStackElement->data;
	prev->next = tempStackElement->next;
	free(tempStackElement);
	return island;
}
int CleanStack(stackPointer stackHead)
{
	stackPointer prev = stackHead->next, top = stackHead->next;
	stackHead = stackHead->next;
	while (top->next)
	{
		while (stackHead->next)
		{
			prev = stackHead;
			stackHead = stackHead->next;
		}
		free(stackHead);
		prev->next = NULL;
		stackHead = top->next;
		prev = top;
	}
	return 0;
}
int PushStack(islandPointer current, stackPointer stackHead)
{
	stackPointer newStackElement;
	stackPointer tempStackElement = stackHead;
	if (newStackElement = AllocateMemoryForStack())
	{
		while (tempStackElement->next)
			tempStackElement = tempStackElement->next;
		newStackElement->next = tempStackElement->next;
		tempStackElement->next = newStackElement;
		newStackElement->data = current;
		return 0;
	}
	else
		return 1;
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

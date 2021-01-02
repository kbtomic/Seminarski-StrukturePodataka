#include "functions.h"
int numberOfIslands = 0;
int GeneratorForTheGame()
{
	islandPointer start = CreateStartIsland();
	stackPointer stackHead = CreateStackHead();
	PushStack(start, stackHead);
	islandPointer islandsWithClue = CreateIslands("IslandsWithClue.txt");
	islandPointer islandsWithoutClue = CreateIslands("IslandsWithoutClue.txt");
	SetPointersOfIslandsWithoutClue(islandsWithoutClue, start);
	SetCoins(islandsWithClue, islandsWithoutClue);
	ShuffleIsland(islandsWithClue);
	ShuffleIsland(islandsWithoutClue);
	GeneratePath(islandsWithClue, islandsWithoutClue, start);
	StartGame(islandsWithClue, islandsWithoutClue, start, stackHead);

	return 0;
}
int StartGame(islandPointer islandsWithClue, islandPointer islandsWithoutClue, islandPointer start, stackPointer stackHead)
{
	system("cls");
	printf("### TREASURE HUNT GAME ###\n");
	int numberOfFoundClues = 0;
	unsigned int currentAmountOfCoins = START_AMOUNT_OF_COINS;
	islandPointer currentIsland = start;
	while (numberOfFoundClues != numberOfIslands)
	{
		islandPointer parentIsland = currentIsland;
		PrintCurrentPath(currentIsland, stackHead);
		printf("Status coina: %d\n", currentAmountOfCoins);
		printf("Putujemo na iduci otok!\n");
		printf("Imaj na umu da bi ti se skuplje putovanje moglo isplatiti!\n");
		printf("Lijevo $ %d $ coina!\t Desno $ %d $ coina!\n", currentIsland->leftNext->coins, currentIsland->rightNext->coins);
		printf("Lijevo - unesi 'L'\t Desno - unesi 'D'\n");
		char choice = fgetc(stdin);
		getchar();
		system("cls");
		if (toupper(choice) == 'L')
		{
			if (currentAmountOfCoins >= currentIsland->leftNext->coins)
			{
				currentAmountOfCoins -= currentIsland->leftNext->coins;
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
					if (currentAmountOfCoins > COINS_AMOUNT_FOR_RESPAWN_OR_MAIN_PRIZE)
					{
						printf("Ipak, nudim ti jos jednu sansu - ako zelis utrositi %d coinsa za uskrsnuti unesi D!\n", COINS_AMOUNT_FOR_RESPAWN_OR_MAIN_PRIZE);
						printf("Status coina: %d\n", currentAmountOfCoins);
						choice = fgetc(stdin);
						getchar();
						system("cls");
						if (tolower(choice) == 'd')
						{
							currentAmountOfCoins -= COINS_AMOUNT_FOR_RESPAWN_OR_MAIN_PRIZE;
							PrintCurrentPath(currentIsland, stackHead);
							printf("Status coina: %d\n", currentAmountOfCoins);
							printf("Uskrsnuo si! Vracamo se na prethodni otok: %s kako bi nastavio svoje putovanje u drugom smjeru\n", parentIsland->islandName);
							PopStack(stackHead);
							currentIsland = parentIsland;
						}
						else
						{
							currentIsland = start;
							CleanStack(stackHead);
							break;
						}
					}
					else 
					{
						currentIsland = start;
						CleanStack(stackHead);
						break;
					}
				}
				else
				{
					PrintCurrentPath(currentIsland, stackHead);
					printf("Vracamo se na prethodni otok: %s kako bi nastavio svoje putovanje u drugom smjeru\n", parentIsland->islandName);
					PopStack(stackHead);
					currentIsland = parentIsland;
				}
			}
			else {
				printf("Nazalost presiromasan si za daljnja putovanja :(!\n");
				break;
			}
		}
		else if (toupper(choice) == 'D')
		{
			if (currentAmountOfCoins >= currentIsland->rightNext->coins)
			{
				currentAmountOfCoins -= currentIsland->leftNext->coins;
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
					if (currentAmountOfCoins > COINS_AMOUNT_FOR_RESPAWN_OR_MAIN_PRIZE)
					{
						printf("Ipak, nudim ti jos jednu sansu - ako zelis utrositi %d coinsa za uskrsnuti unesi D!\n", COINS_AMOUNT_FOR_RESPAWN_OR_MAIN_PRIZE);
						printf("Status coina: %d\n", currentAmountOfCoins);
						choice = fgetc(stdin);
						getchar();
						system("cls");
						if (tolower(choice) == 'd')
						{
							currentAmountOfCoins -= COINS_AMOUNT_FOR_RESPAWN_OR_MAIN_PRIZE;
							PrintCurrentPath(currentIsland, stackHead);
							printf("Status coina: %d\n", currentAmountOfCoins);
							printf("Uskrsnuo si! Vracamo se na prethodni otok: %s kako bi nastavio svoje putovanje u drugom smjeru\n", parentIsland->islandName);
							PopStack(stackHead);
							currentIsland = parentIsland;
						}
						else
						{
							currentIsland = start;
							CleanStack(stackHead);
							break;
						}
					}
					else
					{
						currentIsland = start;
						CleanStack(stackHead);
						break;
					}
				}
				else
				{
					printf("Vracamo se na prethodni otok: %s kako bi nastavio svoje putovanje u drugom smjeru\n", parentIsland->islandName);
					PopStack(stackHead);
					currentIsland = parentIsland;
				}
			}
			else 
			{
				printf("Nazalost presiromasan si za daljnja putovanja :(!\n");
				break;
			}
		}
		else
			printf("Pogresan unos!\n");
	}
	if (numberOfFoundClues == numberOfIslands)
	{
		printf("Cestitam, pronasao si sve znakove!!!\n");
		if (currentAmountOfCoins >= COINS_AMOUNT_FOR_RESPAWN_OR_MAIN_PRIZE)
		{
			for (int i = 0; i < numberOfIslands; i++)
			{
				printf("Znak je: %c\n", islandsWithClue[i].clue);
			}
			printf("Konacno rjesenje je: HAVAJI!!!");
			CleanStack(stackHead);
		}
		else
		{
			printf("Nazalost nedostaje ti %d coina da saznas konacno rjesenje :(!\n", COINS_AMOUNT_FOR_RESPAWN_OR_MAIN_PRIZE - currentAmountOfCoins);
			numberOfFoundClues = 0;
			CleanStack(stackHead);
		}
	}
	return 0;
}
islandPointer CreateStartIsland()
{
	islandPointer start = AllocateMemoryForIslands(1);
	strcpy(start->islandName, "Start");
	start->leftNext = NULL;
	start->rightNext = NULL;
	return start;
}
stackPointer CreateStackHead()
{
	stackPointer stackHead = AllocateMemoryForStack();
	stackHead->data = NULL;
	stackHead->next = NULL;
	return stackHead;
}
islandPointer AllocateMemoryForIslands(int numberOfIslands)
{
	islandPointer islandsWithClue = (islandPointer)malloc(numberOfIslands * sizeof(Island));
	if (!islandsWithClue)
	{
		printf("Can not allocate memory!\n");
	}
	return islandsWithClue;
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
islandPointer CreateIslands(char* nameOfFile)
{
	FILE* fp = NULL;
	fp = fopen(nameOfFile, "r");
	if (fp == NULL)
	{
		printf("Neuspjesno otvaranje datoteke!\n");
		return NULL;
	}
	islandPointer islands = NULL;
	fscanf(fp, "%d", &numberOfIslands);
	islands = AllocateMemoryForIslands(numberOfIslands);
	if (!islands)
		return NULL;
	for (int i = 0; i < numberOfIslands; i++)
	{
		fscanf(fp, "%d %c %s %[^\n]", &islands[i].hasClue, &islands[i].clue, islands[i].islandName, islands[i].description);
	}
	return islands;
}
int SetPointersOfIslandsWithoutClue(islandPointer islandsWithoutClue, islandPointer start)
{
	for (int i = 0; i < numberOfIslands; i++)
	{
		if (islandsWithoutClue[i].clue == 'X')
		{
			islandsWithoutClue[i].leftNext = start;
			islandsWithoutClue[i].rightNext = start;
		}
		else
		{
			islandsWithoutClue[i].leftNext = NULL;
			islandsWithoutClue[i].rightNext = NULL;
		}
	}
	return 0;
}
int SetCoins(islandPointer islandsWithClue, islandPointer islandsWithoutClue)
{
	FILE* fp = NULL;
	fp = fopen("Values.txt", "r");
	if (fp == NULL)
	{
		printf("Neuspjesno otvaranje datoteke!\n");
		return 1;
	}
	int lowerBound, upperBound;
	fscanf(fp, "%d %d", &lowerBound, &upperBound);
	for (int i = 0; i < numberOfIslands; i++)
		islandsWithClue[i].coins = GenerateRandom(upperBound, lowerBound);
	while (fgetc(fp) != '\n')
		fgetc(fp);
	fscanf(fp, "%d %d", &lowerBound, &upperBound);
	for (int i = 0; i < numberOfIslands; i++)
		islandsWithoutClue[i].coins = GenerateRandom(upperBound, lowerBound);
	return 0;
}
int ShuffleIsland(islandPointer islands)
{
	for (int i = 0; i < numberOfIslands; i++)
	{
		Island temp = islands[i];
		int randomIndex = rand() % numberOfIslands;

		islands[i] = islands[randomIndex];
		islands[randomIndex] = temp;
	}
	return 0;
}
int GeneratePath(islandPointer islandsWithClue, islandPointer islandsWithoutClue, islandPointer start)
{
	for (int i = 0; i < numberOfIslands; i++)
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
int PrintCurrentPath(islandPointer current, stackPointer stackHead)
{
	printf("Mapa: ");
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
int GenerateRandom(int upperBound, int lowerBound)
{
	return (rand() % (upperBound - lowerBound + 1)) + lowerBound;
}
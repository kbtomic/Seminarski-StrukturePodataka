#include "ReadLevel.h"
#include "InitializeValue.c"
#include "GameStatus.h"
#include <string.h>
#include <time.h>
int main()
{
	srand(time(NULL));
	char choice;
	filePointer currentLevel = CreateListOfFilesForLevel("level1.txt");
	do {
		InitializeGame(currentLevel);
		choice = PlayAgain();
	} while (tolower(choice) == 'd');
	system("cls");
	GameOver();
	return 0;

}
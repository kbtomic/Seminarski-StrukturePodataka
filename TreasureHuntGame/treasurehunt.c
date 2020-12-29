#include "functions.h"
int main()
{
	srand(time(NULL));
	char choice;
	do {
		GeneratorForTheGame();
		printf("Ako zelis ponovno igrati unesi D!\n");
		choice = fgetc(stdin);
		getchar();
	} while (tolower(choice) == 'd');
	printf("### GAME OVER ###\n");
	return 0;
}

#include "Respawn.h"
#include "Structures.h"
char RespawnPrint(int currentAmountOfCoins) {
	printf("Ipak, nudim ti jos jednu sansu - ako zelis utrositi %d coinsa za uskrsnuti unesi D!\n", COINS_AMOUNT_FOR_RESPAWN_OR_MAIN_PRIZE);
	printf("Status coina: %d\n", currentAmountOfCoins);
	char choice;
	scanf(" %c", &choice);
	return choice;
}
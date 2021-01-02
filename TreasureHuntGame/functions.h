#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<ctype.h>

#define MAX_ISLAND_NAME_LENGTH 100
#define MAX_DESCRIPTION_LENGTH 256
#define INDEX_OF_CLUE_ISLAND 2
#define INDEX_OF_NON_CLUE_ISLAND 1
#define START_AMOUNT_OF_COINS 1000
#define COINS_AMOUNT_FOR_RESPAWN_OR_MAIN_PRIZE 200

typedef struct island* islandPointer;
typedef struct stack* stackPointer;
typedef struct island {
	char islandName[MAX_ISLAND_NAME_LENGTH];
	islandPointer leftNext;
	islandPointer rightNext;
	char description[MAX_DESCRIPTION_LENGTH];
	int hasClue;
	char clue;
	int coins;
} Island;

typedef struct stack {
	islandPointer data;
	stackPointer next;
} Stack;

int GeneratorForTheGame(); /*funkcija u kojoj je sadrzana logika igrice - kreiraju se otoci i generira se ruta*/
int StartGame(islandPointer, islandPointer, islandPointer, stackPointer); /*funkcija koja korisniku omogucuje igranje igrice*/
islandPointer CreateStartIsland(); /*funkcija za kreiranje pocetnog otoka*/
stackPointer CreateStackHead(); /*funkcija za kreiranje vrha stoga*/
islandPointer AllocateMemoryForIslands(int); /*funkcija koja alocira memoriju za otoke*/
stackPointer AllocateMemoryForStack(); /*funkcija koja alocira memoriju za element(otok) stoga*/
islandPointer PopStack(stackPointer); /*funckija koja skida element(otok) sa stoga*/
int PushStack(islandPointer, stackPointer); /*funckija koja stavlja element(otok) na stog*/
int CleanStack(stackPointer); /*funkcija koja cisti elemente(otoke) sa stoga*/
islandPointer CreateIslands(char*); /*funkcija koja iz datoteke cita podatke o otocima*/
int SetPointersOfIslandsWithoutClue(islandPointer, islandPointer); /*funkcija koja postavlja odgovarajuce pokazivace otocima koji nemaju tragove*/
int SetCoins(islandPointer, islandPointer); /*funkcija koja postavlja cijenu(coine) svakom otoku*/
int ShuffleIsland(islandPointer); /*funkcija koja randomly razmjesta otoke*/
int GeneratePath(islandPointer, islandPointer, islandPointer); /*funkcija u kojoj se generira ruta*/
int PrintCurrentPath(islandPointer, stackPointer); /*funkcija koja ispisuje korisniku na kojem se otoku trenutno nalazi, funkcionira kao stog*/
int GenerateRandom(int, int); /*funkcija koja generira random broj izmedu gornje i donje granice*/
#endif
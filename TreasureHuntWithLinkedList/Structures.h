#ifndef STRUCTURES_H
#define STRUCTURES_H

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define MAX_STRING_LENGTH 256
#define MAX_AMOUNT_OF_COINS 1000
#define COINS_AMOUNT_FOR_RESPAWN_OR_MAIN_PRIZE 200

typedef struct island* islandPointer;
typedef struct stack* stackPointer;
typedef struct fileElement* filePointer;
typedef struct island {
	int index;
	char islandName[MAX_STRING_LENGTH];
	islandPointer next;
	islandPointer leftNext;
	islandPointer rightNext;
	char description[MAX_STRING_LENGTH];
	int hasClue;
	char clue;
	int coins;
} Island;

typedef struct stack {
	islandPointer data;
	stackPointer next;
} Stack;

typedef struct fileElement {
	char nameOfFile[MAX_STRING_LENGTH];
	filePointer next;
} FileElement;
#endif
#ifndef COINS_H
#define COINS_H
#include "Structures.h"
int ReadCoinsFromFile(islandPointer, islandPointer, char*); /*funkcija koja iz datoteke cita odgovarajuce vrijednosti coina i poziva donju*/
int SetCoinsToIslands(islandPointer, int, int); /*funkcija koja postavlja randomly vrijednost coina svakom otoku*/
#endif
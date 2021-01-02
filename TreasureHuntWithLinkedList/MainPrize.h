#ifndef MAINPRIZE_H
#define MAINPRIZE_H
#include "Structures.h"
int OpenMainPrize(islandPointer, stackPointer); /*funkcija koja otkriva konacno rjesenje*/
int DontOpenMainPrize(int, int*, stackPointer); /*funkcija koja sluzi da se ne otvori konacno rjesenje ako korisnik nema dovoljno coinsa*/
#endif

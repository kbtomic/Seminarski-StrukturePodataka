#ifndef TRAVELS_H
#define TRAVELS_H
#include "Structures.h"
islandPointer TravelToLeftIsland(int*, int*, islandPointer, islandPointer, stackPointer, int*); /*funkcija kojom se korisnik pomice na lijevi otok*/
islandPointer TravelToPrevIsland(islandPointer, islandPointer, stackPointer); /*funkcija kojom se korisnik pomice na prethodni otok*/
islandPointer TravelToStartIsland(islandPointer, islandPointer, stackPointer); /*funkcija kojom se korisnik pomice na pocetni otok*/
islandPointer TravelToRightIsland(int*, int*, islandPointer, islandPointer, stackPointer, int*); /*funkcija kojom se korisnik pomice na desni otok*/
#endif 

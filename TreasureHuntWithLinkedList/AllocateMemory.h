#ifndef ALLOCATEMEMORY_H
#define ALLOCATEMEMORY_H
#include "Structures.h"
#include<stdlib.h>

filePointer AllocateMemoryForFile(); /*funkcija koja alocira memoriju za datoteku*/
islandPointer AllocateMemoryForIsland(); /*funkcija koja alocira memoriju za otok*/
stackPointer AllocateMemoryForStack(); /*funkcija koja alocira memoriju za element(otok) stoga*/
#endif

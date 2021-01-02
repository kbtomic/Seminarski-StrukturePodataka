#ifndef STACK_H
#define STACK_H
#include "Structures.h"
islandPointer PopStack(stackPointer); /*funckija koja skida element(otok) sa stoga*/
int PushStack(islandPointer, stackPointer); /*funckija koja stavlja element(otok) na stog*/
int CleanStack(stackPointer); /*funkcija koja cisti elemente(otoke) sa stoga*/
stackPointer CreateStackHead(); /*funkcija za kreiranje vrha stoga*/
#endif
#ifndef GAMESTATUS_H
#define GAMESTATUS_H
#include "Structures.h"
char PrintGameStatus(int, islandPointer); /*funkcija koja korisniku ispisuje trenutno stanje podataka, a vraca izbor o daljnjem putovanju*/
int GameOver(); /*funkcija koja ispisuje da je igrica zavrsena*/
char PlayAgain(); /*funkcija koja nudi korisniku mogucnost ponovnog igranja igrice, vraca izbor korisnika*/
#endif 

#include "RandomGenerator.h"
int GenerateRandom(int lowerBound, int upperBound)
{
	return (rand() % (upperBound - lowerBound + 1)) + lowerBound;
}
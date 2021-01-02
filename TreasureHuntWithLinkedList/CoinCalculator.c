#include "CoinCalculator.h"
int HaveEnoughCoins(int currentAmount, int islandCost)
{
	if (currentAmount >= islandCost)
		return 1;
	else
		return 0;
}
int SpendCoins(int currentAmount, int islandCost)
{
	return (currentAmount -= islandCost);
}
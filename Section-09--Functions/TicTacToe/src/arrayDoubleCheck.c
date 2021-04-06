#include <stdio.h>
#include "gameData.h"

// **********************************************************************/
// arrayDoubleCheck - completes two arrayChecks
// **********************************************************************/
int arrayDoubleCheck(int spot1, int spot2, char *gameArray, char playerMark)
{
	return arrayCheck(spot1, gameArray, playerMark) == 1 && arrayCheck(spot2, gameArray, playerMark) == 1 ? 1 : 0;
}
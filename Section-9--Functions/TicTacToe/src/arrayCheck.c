#include <stdio.h>
#include "gameData.h"

// **********************************************************************/
// arrayCheck - checks to see if the value can be entered
// **********************************************************************/
int arrayCheck(int spotValue, char *gameArray, char playerMark)
{
	return gameArray[spotValue] == playerMark ? 1 : 0;
}
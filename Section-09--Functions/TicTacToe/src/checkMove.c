#include <stdio.h>
#include "gameData.h"

// **********************************************************************/
// checkMove  - checks the player's move to see if it is valid
// **********************************************************************/
int checkMove(int value, char *gameArray)
{
	int proceed = 0;

	if (*(gameArray + value) == value + 48)
	{
		proceed = 1;
	}
	return proceed;
}
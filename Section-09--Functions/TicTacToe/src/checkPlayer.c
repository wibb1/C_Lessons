#include <stdio.h>
#include "gameData.h"

// **********************************************************************/
// checkPlayer - determines the active player
// **********************************************************************/
int checkPlayer(int turn)
{
	int player;
	if (turn % 2 == 0)
	{
		player = 2;
	}
	else
	{
		player = 1;
	}
	return player;
} /* end checkPlayer */
#include <stdio.h>
#include "gameData.h"

// **********************************************************************/
// getPlayerMark - determines which mark to use for the current player
// **********************************************************************/
char getPlayerMark(int turn)
{
	return checkPlayer(turn) == 1 ? 'X' : 'O';
}
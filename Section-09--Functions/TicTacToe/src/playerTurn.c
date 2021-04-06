#include <stdio.h>
#include "gameData.h"

// **********************************************************************/
// playerTurn - consolidates the actions for a single player's turn
// **********************************************************************/
int playerTurn(int turn, char *gameArray)
{
	int winningPlayer = 0;

	int move = getMove(turn, gameArray);
	markBoard(move, turn, gameArray);
	if (turn > 4)
	{
		winningPlayer = checkForWin(turn, gameArray);
	}
	return winningPlayer;
}

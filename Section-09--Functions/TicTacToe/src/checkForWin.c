#include <stdio.h>
#include "gameData.h"

// **********************************************************************/
// checkForWin - checks to see if a player has won or the game is a draw
// **********************************************************************/
int checkForWin(int turn, char *gameArray)
{
	int checked = 0;
	int playerNumber = checkPlayer(turn);
	char playerMark = getPlayerMark(turn);
	if (arrayCheck(5, gameArray, playerMark) == 1) /* check center */
	{
		for (int i = 0; i < 4; i++)
		{
			if (arrayDoubleCheck((i + 1), (9 - i), gameArray, playerMark) == 1) // checks all that pass through center
			{
				checked = playerNumber;
			}
		}
	}
	if (arrayCheck(7, gameArray, playerMark) == 1) // checks opposite corner
	{
		if (arrayDoubleCheck(4, 1, gameArray, playerMark) == 1) // checks adjacent cell and opposite corner
		{
			checked = playerNumber;
		}

		if (arrayDoubleCheck(8, 9, gameArray, playerMark) == 1) // checks adjacent cell and opposite corner
		{
			checked = playerNumber;
		}
	}
	if (arrayCheck(3, gameArray, playerMark) == 1) // check opposite corner
	{
		if (arrayDoubleCheck(2, 1, gameArray, playerMark) == 1) // checks adjacent cell and opposite corner
		{
			checked = playerNumber;
		}
		if (arrayDoubleCheck(6, 9, gameArray, playerMark) == 1) // checks adjacent cell and opposite corner
		{
			checked = playerNumber;
		}
	}
	return checked;
} /* end of checkForWin */
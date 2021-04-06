#include <stdio.h>
#include "gameData.h"

// **********************************************************************/
// markBoard - sends the players selection to the board
// **********************************************************************/
void markBoard(int value, int turn, char *gameArray)
{
	char playerMark = checkPlayer(turn) == 1 ? 'X' : 'O';
	*(gameArray+value) == (value + 48) ? *(gameArray+value) = playerMark : printf("Error in assignment");
}
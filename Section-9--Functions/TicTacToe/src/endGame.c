#include <stdio.h>
#include "gameData.h"

// **********************************************************************/
// endGame - prints out the final message of a game
// **********************************************************************/
void endGame(int result, char *gameArray)
{
	if (result > 0)
	{
		drawBoard(gameArray);
		printf("\nCongratulations Player %d, YOU WON!\n\n", result);
	}
	else
	{
		drawBoard(gameArray);
		printf("\nIt's a draw, imagine that!\n\n");
	}
}
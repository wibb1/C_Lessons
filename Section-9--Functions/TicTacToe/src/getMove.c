#include <stdio.h>
#include "gameData.h"

// **********************************************************************/
// getMove - asks the player for their move
// **********************************************************************/
char getMove(int turn, char *gameArray)
{
	int move;
	int player = checkPlayer(turn);
	int testValue = 1;
	do
	{
		drawBoard(gameArray);
		if (testValue != 1)
		{
			printf("\nInvalid move! Please select again...\n");
		}
		printf("\nEnter a number in the board to move there.\n");
		printf("\nPlayer %d, its your turn...\n", player);
		scanf(" %d", &move);
		testValue = checkMove(move, gameArray);
	} while (testValue == 0);
	return move;
} // End of getMove
#include <stdio.h>
#include <stdlib.h>
#include "gameData.h"

// **********************************************************************/
// drawBoard - redraws the board for each turn
// **********************************************************************/
void drawBoard(char *gameArray)
{
	system("clear");

	printf("\n\n\tTic Tac Toe\n\n");
	printf("Player 1 (X) - Player 2 (O)\n\n\n");
	printf(VERTICAL_LINE);
	printf(VALUE_LINE, gameArray[7], gameArray[8], gameArray[9]);

	printf(HORIZONTAL_LINE);
	printf(VERTICAL_LINE);

	printf(VALUE_LINE, gameArray[4], gameArray[5], gameArray[6]);

	printf(HORIZONTAL_LINE);
	printf(VERTICAL_LINE);

	printf(VALUE_LINE, gameArray[1], gameArray[2], gameArray[3]);

	printf(VERTICAL_LINE);
} // End of drawBoard
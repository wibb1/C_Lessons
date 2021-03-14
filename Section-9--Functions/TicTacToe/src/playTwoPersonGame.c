#include <stdio.h>
#include "gameData.h"

// **********************************************************************/
// playTwoPersonGame - controlls a round of play for two players
// **********************************************************************/
void playTwoPersonGame()
{
	char gameArray[] = {"0123456789"};
	int gameStatus = 0;
	for (int i = 1; i < 10 && gameStatus <= 0; i++)
	{

		gameStatus = playerTurn(i, gameArray);
		if (gameStatus > 0)
		{
			endGame(gameStatus, gameArray);
			break;
		}
		else if (i >= 9)
		{
			endGame(0, gameArray);
		}
	}
} // End of playGame
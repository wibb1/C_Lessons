#include <stdio.h>
#include "gameData.h"

//**********************************************************************/
//
//  Name: Will Campbell
//
// Program: Tic Tac Toe
//
// Date: 3/14/2021
//
// Description: Tic Tac Toe game for two players
//
// **********************************************************************/
int main() /* Start of main */
{
	do
	{
		playTwoPersonGame();
	} while (requestReplay() == 1);

	return 0;
} /* End of main */
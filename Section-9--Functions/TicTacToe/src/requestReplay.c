#include <stdio.h>
#include "gameData.h"

// **********************************************************************/
// requestReplay - requests if you would like to play another game
// **********************************************************************/
int requestReplay()
{
	int continuePlay;
	do
	{
		printf("Please enter only either \"1\" to play again or \"0\" to quit.\n");
		scanf(" %i", &continuePlay);
	} while (continuePlay != 0 && continuePlay != 1);
	return continuePlay;
}
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define VERTICAL_LINE "     |     |     \n"
#define HORIZONTAL_LINE "_____|_____|_____\n"
#define VALUE_LINE "  %c  |  %c  |  %c \n"

void playGame(char *gameArray);																								 // controlls a round of play
void drawBoard(char *gameArray);																							 // redraws the board for each player turn
char getMove(int turn, char *gameArray);																			 // gets the players move
int checkMove(int value, char *gameArray);																		 // checks to see if a move is a valid one
int checkPlayer(int turn);																										 // checks the player that is currently selected
void markBoard(int value, int turn, char *gameArray);													 // feeds newdata to array
int checkForWin(int turn, char *gameArray);																		 // checks if a player has won the game or the game is a draw
bool arrayCheck(int spotValue, char *gameArray, char playerMark);							 // checks the existing value of the selected move
void endGame(int result, char *gameArray);																		 // ends the game
void *startGame(char *gameArray);																							 // starts the game delivering a clear board
int playerTurn(int turn, char *gameArray);																		 // sets the order of calls for a single player turn
char getPlayerMark(int turn);																									 // gets the current players mark
bool arrayDoubleCheck(int spot1, int spot2, char *gameArray, char playerMark); // performs two arrayChecks at the same time
int requestReplay();																													 // requests if you would like to play another game

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
		char gameArray[] = {"0123456789"};
		playGame(gameArray);
	} while (requestReplay() == 1);

	return 0;
} /* End of main */

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

// **********************************************************************/
// playGame - controlls a round of play
// **********************************************************************/
void playGame(char *gameArray)
{
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

// **********************************************************************/
// checkMove  - checks the player's move to see if it is valid
// **********************************************************************/
int checkMove(int value, char *gameArray)
{
	int proceed = 0;

	if (*(gameArray + value) == value + 48)
	{
		proceed = 1;
	}
	return proceed;
}

// **********************************************************************/
// checkPlayer - determines the active player
// **********************************************************************/
int checkPlayer(int turn)
{
	int player;
	if (turn % 2 == 0)
	{
		player = 2;
	}
	else
	{
		player = 1;
	}
	return player;
} /* end checkPlayer */

// **********************************************************************/
// markBoard - sends the players selection to the board
// **********************************************************************/
void markBoard(int value, int turn, char *gameArray)
{
	char playerMark = checkPlayer(turn) == 1 ? 'X' : 'O';
	gameArray[value] == (value + 48) ? gameArray[value] = playerMark : printf("Error in assignment");
}

// **********************************************************************/
// checkForWin - checks to see if a player has won or the game is a draw
// **********************************************************************/
int checkForWin(int turn, char *gameArray)
{
	int checked = 0;
	int playerNumber = checkPlayer(turn);
	char playerMark = getPlayerMark(turn);
	if (gameArray[5] == playerMark) /* check center */
	{
		for (int i = 0; i < 4; i++)
		{
			if (arrayDoubleCheck((i + 1), (9 - i), gameArray, playerMark)) // checks all that pass through center
			{
				checked = playerNumber;
			}
		}
	}
	if (arrayCheck(7, gameArray, playerMark)) // checks opposite corner
	{
		if (arrayDoubleCheck(4, 1, gameArray, playerMark)) // checks adjacent cell and opposite corner
		{
			checked = playerNumber;
		}

		if (arrayDoubleCheck(8, 9, gameArray, playerMark)) // checks adjacent cell and opposite corner
		{
			checked = playerNumber;
		}
	}
	if (arrayCheck(3, gameArray, playerMark)) // check opposite corner
	{
		if (arrayDoubleCheck(2, 1, gameArray, playerMark)) // checks adjacent cell and opposite corner
		{
			checked = playerNumber;
		}
		if (arrayDoubleCheck(6, 9, gameArray, playerMark)) // checks adjacent cell and opposite corner
		{
			checked = playerNumber;
		}
	}
	return checked;
} /* end of checkForWin */

// **********************************************************************/
// getPlayerMark - determines which mark to use for the current player
// **********************************************************************/
char getPlayerMark(int turn)
{
	return checkPlayer(turn) == 1 ? 'X' : 'O';
}

// **********************************************************************/
// arrayCheck - checks to see if the value can be entered
// **********************************************************************/
bool arrayCheck(int spotValue, char *gameArray, char playerMark)
{
	return gameArray[spotValue] == playerMark;
}

bool arrayDoubleCheck(int spot1, int spot2, char *gameArray, char playerMark)
{
	return arrayCheck(spot1, gameArray, playerMark) && arrayCheck(spot2, gameArray, playerMark);
}

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
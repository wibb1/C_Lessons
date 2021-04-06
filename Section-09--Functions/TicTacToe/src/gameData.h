
// Define Constants
#define VERTICAL_LINE "     |     |     \n"
#define HORIZONTAL_LINE "_____|_____|_____\n"
#define VALUE_LINE "  %c  |  %c  |  %c \n"

void playTwoPersonGame();                                                     // controlls a round of play for two players
void drawBoard(char *gameArray);                                              // redraws the board for each player turn
char getMove(int turn, char *gameArray);                                      // gets the players move
int checkMove(int value, char *gameArray);                                    // checks to see if a move is a valid one
int checkPlayer(int turn);                                                    // checks the player that is currently selected
void markBoard(int value, int turn, char *gameArray);                         // feeds newdata to array
int checkForWin(int turn, char *gameArray);                                   // checks if a player has won the game or the game is a draw
int arrayCheck(int spotValue, char *gameArray, char playerMark);              // checks the existing value of the selected move
void endGame(int result, char *gameArray);                                    // ends the game
void *startGame(char *gameArray);                                             // starts the game delivering a clear board
int playerTurn(int turn, char *gameArray);                                    // sets the order of calls for a single player turn
char getPlayerMark(int turn);                                                 // gets the current players mark
int arrayDoubleCheck(int spot1, int spot2, char *gameArray, char playerMark); // performs two arrayChecks at the same time
int requestReplay();                                                          // requests if you would like to play another game
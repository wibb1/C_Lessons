#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* program generates random number between LOWNUMBER and HIGHNUMBER */
#define LOWNUMBER 0		/* lowest number in set */
#define HIGHNUMBER 20 /* highest number in set */
#define NUMBERTRIES 5 /* The player only gets NUMBERTRIES tries to guess the number */

/* program takes the number and determines it is higher, lower or equal to the number */

int main()
{
	time_t t; /* seed value for random number generator */
	srand((unsigned) time(&t)); /* Random Numbers are not "random" */
	int programNumber = rand() % (HIGHNUMBER - LOWNUMBER + 1) + LOWNUMBER; /* Random Numbers are not "random" */
	int playerNumber = -1; /* player number must be set outside the allowed number for the while loop */
	printf("\n\nWelcome to the GUESSING GAME\n");
	printf("You only get FIVE tries so make it a good guess!\n");
	for (int i = 0; i < NUMBERTRIES; i++) /* initiates and tracks the NUMBERTRIES */
	{
		while (playerNumber < LOWNUMBER || playerNumber > HIGHNUMBER) /* user guesses random number LOWNUMBER and HIGHNUMBER */
		{
			printf("Please guess a number from %u to %u\n", LOWNUMBER, HIGHNUMBER); /* program checks the user has entered a number from LOWNUMBER to HIGHNUMBER */
			scanf("%u", &playerNumber);
		}
		if (playerNumber < programNumber) /* guess is too low */
		{
			printf("Your number is too low, you have %i guesses left\n", NUMBERTRIES - i);/* if higher prints number is too low */
			playerNumber = -1; /* player number must be set outside the allowed number for the while loop */
		}
		else if (playerNumber > programNumber) /* guess is too high */
		{
			printf("Your number is too high, you have %i guesses left\n", NUMBERTRIES - i);/* if lower prints number is too high */
			playerNumber = -1; /* player number must be set outside the allowed number for the while loop */
		}
		else
		{
			printf("Your number is Just Right!\n"); /* if exact prints number is just right*/ 
			break;
		}
	}
	if (playerNumber == programNumber) /* guess = random number */
	{
		printf("CONGRATULATIONS!!! YOU WON!!!\n"); /* YOU WON! */
	}
	else /* guess != random number */
	{
		printf("Sorry you Lost. My number was %u\n", programNumber); /* YOU LOST! */
	}
	return (0);
}
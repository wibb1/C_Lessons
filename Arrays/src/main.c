/* C program that finds prime numbers between 3-100 2 and 3 are hardcoded */
/* no input to the program */
/* output will be each prime number seperated by a single space on a single line */
/* use an array that will store the number as it is generated */
/* use loops to find only prime numbers up to 100 and a oop to print the array */
/* make the array 100 to ensure you have enough room */
/* prime number - not evenly divisible by any of the previous prime numbers */

/* exit condition for the loop -- p/primes[i]>=primes[i] -- test to ensure that the value of p does not exceed the square route of primes[i] */

/* should only look at odd numbers since even numbers are always divisible by 2 */

#include <stdio.h>
#include <stdbool.h>

int main()
{
	int p;
	int i;

	int primes[50] = {2, 3}; /* initiates array with 1, 2 and 3 already entered */
	int primeIndex = 2;

	bool isPrime;								 /* designates if a number is a prime number */
	for (p = 5; p <= 100; p = p + 2) /* initiates outer loop using i as the loop variable */
	{
		isPrime = true;

		for (i = 1; primes[i] > 0 && i <= 100; i++) /* initiates a loop to determine if the number is a prime number */
		{																			 
			if (p % primes[i] == 0) /* check for prime number */
			{
				isPrime = false; /* if divisable by another prime number then it is false */
			}
		}
		if (isPrime) /* if statement checks if value is false */
		{
			primes[primeIndex] = p; /* if isPrime = true then assigns the number to the array */
			primeIndex++; /* increments the counter for the array index */
		}
	}

	for(i = 0; i < primeIndex; i++){
		printf("%i ", primes[i]);
	}
	printf("\n");

	return (0);
}
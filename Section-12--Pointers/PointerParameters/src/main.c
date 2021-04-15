#include <stdio.h>

void square(long *number)
{
  *number = *number * *number;
}

int main()
{
  long number = 2;
  for (int i = 0; i < 5; i++)
  {
    printf("The square of %ld", number);
    square(&number);
    printf(" is %ld\n", number);
  }

  printf("The End!\n");

  return (0);
}
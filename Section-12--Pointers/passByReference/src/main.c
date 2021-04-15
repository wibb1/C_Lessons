#include <stdio.h>

void swap1(int x, int y)
{
  int temp;
  temp = x; // save the value x
  x = y;    //put y into x
  y = temp; // put temp into y
}

void swap2(int *x, int *y)
{
  int temp;
  temp = *x; // save the value x
  *x = *y;   //put y into x
  *y = temp; // put temp into y
}

int main()
{
  // local varioable definition

  int a = 100;
  int b = 200;

  printf("Before swap1, value of a: %d\n", a);
  printf("Before swap1, value of b: %d\n", b);

  //calling the function to swap the values
  swap1(a, b);

  printf("After swap1, value of a: %d\n", a);
  printf("After swap1, value of b: %d\n", b);

  printf("Before swap2, value of a: %d\n", a);
  printf("Before swap2, value of b: %d\n", b);

  //calling the function to swap the values
  swap2(&a, &b);

  printf("After swap2, value of a: %d\n", a);
  printf("After swap2, value of b: %d\n", b);

  return (0);
}
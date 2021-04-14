#include <stdio.h>

int main()
{

  //create integer variable and a pointer, assign to pointer then print out address of number, address of the pointer, value of the pointer, and the value of number that pointer is pointing too
  int number = 10;
  int *pNumber = NULL;

  pNumber = &number; // same as *pNumber = number;

  printf("Value of the number's address is %p\n", &number);

  printf("Value of the pointer's address is %p\n", &pNumber);

  printf("Value of the pointer is %p\n", pNumber);

  printf("Value of the number the pointer is pointing to is %d\n", *pNumber);

  return (0);
}
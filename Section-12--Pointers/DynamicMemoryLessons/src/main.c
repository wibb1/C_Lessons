#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void example()
{
  char *str;

  //Initial memory allocation
  str = (char *)malloc(15*sizeof(char));
  strcpy(str, "jason");
  printf("Address = %u, String = %s\n", str, str);

  //Reallocate memory
  str = (char *)realloc(str, 25*sizeof(char));
  strcat(str, ".com");
  printf("Address = %u, String = %s\n", str, str);

  free(str);
}

int main()
{
  /*
  int *pBadNumber = NULL, *pNumber = NULL;
  pBadNumber = (int *)malloc(100); // although it works it changes based on the bits of the system used
  // malloc = Memory Allocation
  pNumber = (int *)malloc(25 * sizeof(int)); // better to do this so the code is portable to other systems
  // you have to cast the malloc because it is returning a void pointer

  // malloc returns NULL when there is a problem
  if (!pNumber)
  {
    //code to deal with failed memory allocation
    printf("Memory allocation failed");
    exit(0);
  }
  // always release the memory when you are done with it!
  free(pNumber);

  //calloc = Contiguous Allocation
  pNumber = (int *)calloc(75, sizeof(int));
  //calloc initializes all of the ints to 0
  // return value will be NULL just like malloc so
  if (!pNumber)
  {
    //code to deal with failed memory allocation
    printf("Memory allocation failed");
    exit(0);
  }
  pNumber = (int *)realloc(pNumber, 25);
  //realloc = Reallocation of Memory
  //realloc allows you to allocate additiional memory where not enough was allocated initially with calloc or malloc
  //requires 2 arguments - a pointer previously allocated memory using malloc or calloc - the size in bytes of the new memory you want to allocate
  // transfers the ammount of memory previously allocated to the new allocation and returns a null pointer same as malloc and calloc
  return (0);
*/
  example();
}
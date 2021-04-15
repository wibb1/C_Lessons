#include <stdio.h>


struct intPtrs //intPtrs is not a pointer itself just a structure that contains pointers
{
  int *p1;
  int *p2;
};

//comparison of the two methods to create a struct
struct Names {
  char first[20];
  char last[20];
};

// OR

struct pNames {
  char * first;
  char * last;
};

int StructPointers()
{
  struct intPtrs pointers;
  int i1 = 100, i2;

// because the structure is not a pointer this is how you reference them.
  pointers.p1 = &i1;
  pointers.p2 = &i2;
  *pointers.p2 = -97;

  printf("i1 = %i, *pointers.p1 = %i\n", i1, *pointers.p1);
  printf("i2 = %i, *pointers.p2 = %i\n", i2, *pointers.p2);

  struct Names veep = {"Talia", "Summers"}; 
  //strings are stored inside the structure allocating 40 bytes to hold 2 names
  struct pNames treas = {"Brad", "Fallingjaw"};
  //strings are stored whereever the complier holds string constants taking 16 bytes (8 for each pointer address).  The struct itself does not hold any data and can only be used with strings that have been allocated space elsewhere - such as string constants or strings in arrays
  //typically you would malloc the pointers to allocate memory 
  printf("%s and %s\n", veep.first, treas.first);
  return(0);
}
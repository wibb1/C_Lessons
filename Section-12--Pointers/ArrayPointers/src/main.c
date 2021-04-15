#include <stdio.h>
#include <string.h>

void arrayPointers1()
{
  char values[] = "abcdefghijklmnopqrstuvwxyz";
  char *pValues = values; // set to first value in the array.  values is the same as saying values[0]
  printf("The first value in values is %c\n", values[0]);
  printf("*pValues is pointing to %c\n", *pValues);
  pValues += 1; //second value in the array
  printf("The second value in values is %c\n", values[1]);
  printf("After calling 'pValues =+ 1;' the value of *pValues is %c\n", *pValues);
  //fourth value in the array
  printf("The fifth value in values is %c\n", values[4]);
  printf("The value of *(pValues+3) is %c\n", *(pValues + 3));
}

int arraySum1(int array[], const int n)
{
  int sum = 0, *ptr;
  int *const arrayEnd = array + n;
  for (ptr = array; ptr < arrayEnd; ++ptr)
  {
    sum += *ptr;
  }
  return sum;
}

int arraySum2(int *ptr, const int n)
{
  int sum = 0;
  int *const arrayEnd = ptr + n;
  for (; ptr < arrayEnd; ++ptr)
  {
    sum += *ptr;
  }
  return sum;
}

void pointerArithmatic1()
{
  char multiple[] = "a string";
  char *p = multiple;
  for (int i = 0; i < strlen(multiple); ++i)
  {
    printf(" multiple[%d] = '%c' : *(p + %d) = '%c' : &multiple[%d] = %p : p + %d = %p \n", i, multiple[i], i, *(p + i), i, &multiple[i], i, p + i);
  }
}

void pointerArithmatic2()
{
  long multiple[] = {15L, 25L, 35L, 45L};
  long *p = multiple;
  for (int i = 0; i < sizeof(multiple) / sizeof(multiple[0]); ++i)
  {
    printf(" multiple[%d] = %ld : *(p + %d) = %ld : &multiple[%d] = %p : p + %d = %p \n", i, multiple[i], i, *(p + i), i, &multiple[i], i, p + i);
  }
}

void copyString1(char to[], char from[])
{
  int i;
  for (i = 0; from[i] != '\0'; ++i)
  {
    to[i] = from[i];
  }
  to[i] = '\0';
}

void copyString2(char *to, char *from)
{
  while (*from)
  {
    *to++ = *from++;
  }
  *to = '\0';
}

int main()
{
  printf("\n------------ ArrayPointers1 ------------\n");
  arrayPointers1();
  printf("\n--------------- arraySum ---------------\n");
  int values[10] = {3, 7, -9, 3, 6, -1, 7, 9, 1, -5};
  printf("The sum using arrays converted to pointers inside the function is %i\n", arraySum1(values, 10));
  printf("The sum using arrays fed to pointers inside the function is %i\n", arraySum1(values, 10));
  printf("\n---------- pointerArithmatic1 ----------\n");
  pointerArithmatic1();
  printf("\n---------- pointerArithmatic2 ----------\n");
  pointerArithmatic2();
  printf("\n--------- parameter differences --------\n");
  char from1[] = "first string";
  char to1[25];
  copyString1(to1, from1);
  printf("%s\n", to1);
  printf("%s\n", from1);
  
  char from2[] = "second string";
  char to2[25];
  copyString2(to2, from2);
  printf("%s\n", to2);
  printf("%s\n", from2);
}

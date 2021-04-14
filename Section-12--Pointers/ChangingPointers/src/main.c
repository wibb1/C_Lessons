#include <stdio.h>

void printingPointers()
{
  long num1, num2;
  long *pNum = NULL;
  num1 = 0L;
  num2 = 0L;

  pNum = &num1;
  *pNum = 2L;
  ++num2;
  num2 += *pNum;
  pNum = &num2;
  ++*pNum;

  printf("num1 = %ld, num2 = %ld, *pNum = %ld, *pNum + num2 = %ld \n", num1, num2, *pNum, *pNum + num2);
}

void testForNull()
{
  int *pValue = NULL;
  printf("%s\n", !pValue ? "NULL" : "not NULL");
  int value = 10;
  pValue = &value; //*pValue = value and *pValue = 10 both crash with segmentation fault
  printf("%s\n", !pValue ? "NULL" : "not NULL");
}

void constWithPointers()
{
  //const before type declaration
  long value = 9999L;
  const long *pValue = &value; // defines pointer pointed to a constanct (i.e. value must not change)
  printf("First *pValue = %ld\n", *pValue);
  //*pValue =8888L will not work
  value = 8888L; //this will work
  printf("Second *pValue = %ld\n", *pValue);
  long number = 7777L;
  pValue = &number; //this will work, you have changed the value pointed to but not the number through the pointer - changing the address is ok, still cant change the value through the pointer
  printf("Third *pValue = %ld\n", *pValue);
  //const after type declaration
  int count = 43;
  int *const pCount = &count; //defines a pointer that will not change the reference address (i.e. will always reference count)
  printf("First *pCount = %d\n", *pCount);

  //pCount = &item; //will generate error at build
  *pCount = 6; // allowed - the constant is the address not the value within the address
  printf("Second *pCount = %d\n", *pCount);

  //double const
  int item = 43;
  const int *const p2Count = &item; //both address and value are constants - can't change either one using the pointer
  printf("First *p2Count = %d\n", *p2Count);
  item = 5; //still allowed since item is not a const
  printf("Second *p2Count = %d\n", *p2Count);
}

void voidPointers()
{
  //pointer that can contain any type of variable.
  //must supply a specific cast to return the vaiable to
  int i = 0;
  float f = 2.34;
  char ch = 'k';

  void *vPtr;

  vPtr = &i;
  printf("Value of i = %d\n", *(int *)vPtr);

  vPtr = &f;
  printf("Value of i = %.2f\n", *(float *)vPtr);

  vPtr = &ch;
  printf("Value of i = %c\n", *(char *)vPtr);
}

int main()
{

  printingPointers();

  testForNull();

  constWithPointers();

  voidPointers();

  return (0);
}
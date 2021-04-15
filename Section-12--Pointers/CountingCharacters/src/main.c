#include <stdio.h>
#include <string.h>

int stringLength(const char *pointer)
{
  const char *pointerc;
  pointerc = pointer;
  while(*pointer)
  {
    ++pointer;
  }
  return pointer - pointerc;
}

int main()
{
  char string[] = "This is a string";
	printf("16 = %d\n", stringLength(string));
  char string2[] = "This is another string";
  printf("22 = %d\n", stringLength(string2));
char string3[] = "This is a third string!";
  printf("23 = %d\n", stringLength(string3));
	return (0);
}
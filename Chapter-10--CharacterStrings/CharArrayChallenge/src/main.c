#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int StringLength(char string[]);
void ConcatenateStrings(char result[], const char str1[], const char str2[]);
_Bool StringCompare(const char str1[], const char str2[]);


int main()
{
  char str1[] = "Hello my name is, ";
  char str2[] = "Slim Shady";

  char str3[100];
  ConcatenateStrings(str3, str1, str2);
  printf("%s\n", str3);
  char s1[] = "Hellow";
  char s2[] = "Hellow";
  printf(StringCompare(s1,s2) ? "true" : "false");
}

int StringLength(char string[])
{
  int i = 0;
  while (string[i] != '\0')
  {
    i++;
  }
  return i;
}

void ConcatenateStrings(char result[], const char str1[], const char str2[])
{
  int i, j;
  for (i = 0; str1[i] != '\0'; i++)
  {
    result[i] = str1[i];
  }
  for (j = 0; str2[j] != '\0'; j++)
  {
    result[i + j] = str2[j];
  }
  result[j + i] = '\0';
}

_Bool StringCompare(const char str1[], const char str2[])
{
  bool returnValue = true;
  for (int i = 0; i < StringLength(str1); i++)
  {
    if (str1[i] != str2[i]){
      returnValue = false;
    }
  }
  return returnValue;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 25

void StringReverse(const char str1[])
{
  int i = strlen(str1) - 1, j = 0, len = strlen(str1);
  char returnStr[len];
  for (; i >= 0; i--)
  {
    returnStr[j] = str1[i];
    j++;
  }
  returnStr[j + 1] = '\0';
  printf("%s\n\n", returnStr);
}

void sortStrings(int n, char arr[])
{
  char temp[MAX + 1];
  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j < i - 1; j++)
    {
      if (strcmp(&arr[j], &arr[j + 1]) > 0)
      {
        strncpy(temp, &arr[j], sizeof(temp) - 1);
        strncpy(&arr[j], &arr[j + 1], sizeof(arr[j]) - 1);
        strncpy(&arr[j + 1], temp, sizeof(arr[j] + 1) - 1);
      }
    }
  }
}

int main()
{
  int n;
  char string[25];

  printf("Enter a string to reverse:\n");
  scanf("%s", string);

  StringReverse(string);

  printf("Enter the number of strings\n");
  scanf("%d", &n);
  char array[n][MAX + 1];
  for (int i = 0; i < n; i++)
  {
    printf("Enter a string with < %d characters and no spaces: \n", MAX);
    scanf("%s", array[i]);
  }

  sortStrings(n, array[n]);

  for (int h = 0; h < n; h++)
  {
    printf("%s\n", array[h]);
  }

  return (0);
}

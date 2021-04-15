#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int n;
  char *str = NULL;
  printf("Enter the number of characters: \n");
  scanf("%d", &n);
  str = (char *)malloc((n+1) * sizeof(char));
  if (str != NULL)
  {
    printf("Enter your string: \n");
    scanf(" ");
    gets(str);
  }

  printf("%s\n", str);

  free(str);
  str = NULL;
  return (0);
}
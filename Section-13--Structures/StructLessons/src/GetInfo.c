#include <stdio.h>
/*/

void GetInfo(struct namect *pst) 
{
  char temp[SLEN];
  printf("Please enter you first name.\n");
  s_gets(temp, SLEN);

  //alocate memory to hold name
  pst->fname = (char*) malloc(strlen(temp)+1);

  //copy name to allocated memory
  strcpy(pst->fanme, temp);
  printf("Please enter your last name.\n");
  s_gets(temp, SLEN);
  pst->lname = (char *) malloc(strlen(temp) + 1);
  strcpy(pst->lname, temp);
}

/*/
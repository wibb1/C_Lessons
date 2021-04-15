#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Family
{
  char name[20];
  int age;
  char father[20];
  char mother[20];
};

bool siblings(struct Family member1, struct Family member2)
{
  return (strcmp(member1.mother, member2.mother) == 0) ? true : false;
}

bool siblingsRefactor(struct Family const *pMember1, struct Family const *pMember2) // const prevents modification within function - good idea where  no mod is intended
{
  return (strcmp(pMember1->mother, pMember2->mother) == 0) ? true : false;
}

void StructureAsArgument()
{
  struct Family son = { "son", 20, "dad", "mom"};
  struct Family daughter = { "daughter", 25, "dad", "mom"};

  siblingsRefactor(&son, &daughter);
}
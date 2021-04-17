#include <stdio.h>
#include <stdlib.h>

struct Date
{
  int month;
  int day;
  int year;
};

struct Employee
{
  char name[20];
  struct Date hireDate;
  float salary;
};

void fillEmployee(struct Employee *ptr)
{

  printf("Enter the employees first name: \n");
  scanf("%s", ptr->name); //& not required with strings
  printf("Enter their hire date (mm/dd/yyyy): \n");
  scanf("%2i/%2i/%4i", &ptr->hireDate.month, &ptr->hireDate.day, &ptr->hireDate.year);
  printf("Enter their salary\n");
  scanf("%f", &ptr->salary);
  printf("\n\n");
}

void printEmployee(struct Employee *ptr)
{
  printf("Name: %s\n", ptr->name);
  printf("Hire Date: %i/%i/%i\n", ptr->hireDate.month, ptr->hireDate.day, ptr->hireDate.year);
  printf("Salary: $%.2f\n\n\n", ptr->salary);
}

int main()
{
  struct Employee first = {.name = "name1", .hireDate.month = 4, .hireDate.day = 15, .hireDate.year = 2021, .salary = 120000.f};
  struct Employee second;
  fillEmployee(&second);
  printEmployee(&first);
  printEmployee(&second);
  return (0);
}

/*

* write a program that declares a structure and prints out it's contents
  * create an employee structure with 3 members
  * name (character array)
  * hireDate (int)
  * salary (float)

* declare and initialize an instance from the conslod and store it in a struction of the type employee

* read in a second employee from the console and stor it in a structure f type employee

* print out the contents of each employee


*/
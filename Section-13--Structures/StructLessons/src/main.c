#include <stdio.h>

// structs are similar to objects created in other languages
// they cannot contain functions, there is not a "this." designation
// but you are able to access the data very similarly => "today.day;"
// structs can contain a function pointer, which can be similar to a function but not identical
// structs can contain variables or pointers - called members or fields

struct Date
{ //inside the brackets are the members/fields defined within the struct
  int month;
  int day;
  int year;
} tomorrow; // creates the tomorrow struct at the start of the program - no need for "struct Date tomorrow;"

struct Month
{
  int numberOfDays;
  char name[3];
};

struct Time
{
  int hours;
  int minutes;
  int seconds;
};

struct DateTime
{
  struct Date date;
  struct Time time;
};

struct DateWithTime
{
  int month;
  int day;
  int year;
  struct TimeInDate 
  { //can not create a TimeInDate except by creating a DateWithTime
    int hours;
    int minutes;
    int seconds;
  };
};

void structInitialization()
{
  int century;
  struct Date today;
  // structure declaration can also be done like
  // struct Date today = { 4, 15, 2021 }; // need the correct order
  // struct Date today = { .year = 2021, .month = 4, .day = 15 }; //no need to remember order

  today.day = 15;
  today.month = 4;
  today.year = 2021;
  // today = (struct Date) { 4, 15, 2021 }; //another acceptable method to fill DO NOT declare
  // today = (struct Date) { .day=15, .year=2021, .month=4 } //another method w/o knowing order

  // don't have to include all the member definitions at the start, some can be blank

  century = today.year / 100 + 1; //members are treated just like variables

  tomorrow.day = today.day + 1; // do not need to initialize tomorrow - its done in struct declaration

  printf("Todays date is %i/%i/%.2i.\n", today.month, today.day, today.year);
}

void arrayOfStructures()
{
  struct Date myDates[10]; // creates array of 10 Date structs
  // struct Date myDates[3] = { {4, 14, 2021}, {4, 15, 2021}, {4, 16, 2021} } //this is better
  // struct Date myDates[3] = {4, 14, 2021, 4, 15, 2021, 4, 16, 2021} //compiler would understand this

  // struct Date myDates[5] = {[2]={4,15,2021}}; //initializes the second array value to 4/15/2021
  // struct Date myDates[5] = {[1].month=4, [1].year=2021}//initializes and sets just selected values

  // initializing values
  myDates[1].month = 4;
  myDates[1].day = 15;
  myDates[1].year = 2021;
  // myDates[1] = (struct Date) { 4, 15, 2021 }; //another acceptable method to fill DO NOT declare
  // myDates[1] = (struct Date) { .day=15, .year=2021, .month=4 } //another method w/o knowing order
}

void arrayInStruct()
{
  struct Month aMonth;
  aMonth.numberOfDays = 31;
  aMonth.name[0] = 'J';
  aMonth.name[0] = 'a';
  aMonth.name[0] = 'n';
  //have to use strcpy to feed the entire string at once into the char array

  // struct Month aMonth = {31, {'J','a','n'}} is acceptable

  struct Month months[12]; //creates an array of 12 Month structs
}

void nestedStructs()
{
  struct DateTime event;
  struct Date tDate = {4, 15, 2021};
  event.date = tDate;
  event.date = (struct Date){4, 15, 2021};
  event.date.month = 4;
  event.date.month++;

  struct DateTime event2 = {{4, 15, 2021}, {3, 30, 30}};
  struct DateTime event3 = {{.month = 4, .day = 15, .year = 2021}, {.hours = 3, .minutes = 30, .seconds = 30}};

  struct DateTime events[100]; //declares an array of 100 DateTime events
  //set the first event time to noon
  events[0].time.hours = 12;
  events[0].time.minutes = 0;
  events[0].time.seconds = 0;

  // can also use all the methods that are detailed above
}

void PointersToStructures()
{
  //Pointers to structures are very usefull
  //1. pointers to structures are easier to manipulate that the structure themselves
  //2. passing a structure to a function creates a copy of the sturcture - passing a pointer doesn't .
  struct Date today = {4, 15, 2021};
  struct Date *pDate = NULL; //creates a pointer - no memory allocated at this point
  pDate = &today;
  printf("Today's date is %i/%i/%.2i.\n", pDate->month, pDate->day, pDate->year);
  (*pDate).day = 21; //changes the day to 21 - parentheses are required because the . takes precedence over the * so the compiler would apply the . (member operator) before the * (indirection operator) and it wouldn't know how to handle it
  printf("Today's date is %i/%i/%.2i.\n", pDate->month, pDate->day, pDate->year);
  pDate->day = 15; // changes the day to 15 - more efficient way to assign the value - more likely to use and see this method
  printf("Today's date is %i/%i/%.2i.\n", pDate->month, pDate->day, pDate->year);
}

int StructPointers();

int main()
{
  printf("Welcome to Structures\n\n");
  structInitialization();
  arrayOfStructures();
  arrayInStruct();
  nestedStructs();
  PointersToStructures();
  StructPointers();
  return (0);
}
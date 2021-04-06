#include <stdio.h>

int main()
{
	/* designates int variables for minutes, days, years, and number of minutes left*/
	int minutes;
	double years;
	double days;
	double minutesLeft; 

	printf("Enter the number of minutes\n");
	scanf("%d", &minutes);

	years = (minutes / 525600);
	days = (minutes % 525600) / 1440;
	minutesLeft = (minutes % 525600) % 1440;

	printf("There are %.0f years, %.0f days, and %.0f minutes in %d minutes.", years, days, minutesLeft, minutes);
	return (0);
}

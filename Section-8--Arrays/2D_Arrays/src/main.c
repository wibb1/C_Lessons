#include <stdio.h>

int main()
{
#define YEARS 5				 /* number of years */
#define MONTHS 12			 /* Number of months */
#define STARTYEAR 2010 /* defines the first year of the data */

	/* creates two dimensional array that will be used in the exercise representing monthly rainfall over 5 years */
	float rainfall[5][12] =
			{
					{8.70, 2.74, 3.93, 4.55, 2.34, 7.11, 6.76, 7.11, 3.28, 5.58, 3.20, 7.98},
					{4.44, 7.20, 5.34, 8.85, 3.86, 5.72, 7.70, 5.60, 2.54, 6.49, 4.50, 2.53},
					{6.08, 5.94, 2.11, 7.66, 5.69, 4.71, 2.27, 7.58, 2.43, 6.35, 5.53, 6.89},
					{3.41, 2.23, 3.64, 6.05, 8.63, 3.37, 5.51, 4.05, 6.69, 6.79, 7.80, 7.62},
					{7.30, 2.23, 8.27, 7.20, 8.53, 7.25, 2.33, 7.79, 4.81, 8.21, 5.79, 3.13}
			};

	float totalRainfall[5];		 /* total rainfall by year */
	float monthlyRainfall[12]; /* monthly rainfall by year */
	int monthsRainfall;				 /* single month's rainfall */
	float annualRainfall;			 /*single year's rainfall */

	for (int y = 0; y < YEARS; y++)
	{
		for (int m = 0; m < MONTHS; m++)
		{
			annualRainfall += rainfall[y][m];
		}
		totalRainfall[y] = annualRainfall;
	}

	for (int m = 0; m < MONTHS; m++)
	{
		monthsRainfall = 0;
		for (int y = 0; y < YEARS; y++)
		{
			monthsRainfall += rainfall[y][m];
		}
		monthlyRainfall[m] = monthsRainfall;
	}
	printf("\n\n\t     Annual Averages:\n\n");
	printf("Year\tTotal Rain (in)\t     Average Rain (in)\n");
	for (int y = 0; y < YEARS; y++)
	{
		printf("%i\t%9.2f\t     %9.2f\n", y + STARTYEAR, totalRainfall[y], totalRainfall[y] / 12);
	}

	printf("\n\nMonthly Averages:\n");
	printf("   Jan   Feb   Mar   Apr   May   Jun   Jul   Aug   Sep   Oct   Nov   Dec\n");
	for (int m = 0; m < MONTHS; m++)
	{
	printf("  %3.1f", monthlyRainfall[m]);
	}
	printf("\n\n\n");
	return (0);
}
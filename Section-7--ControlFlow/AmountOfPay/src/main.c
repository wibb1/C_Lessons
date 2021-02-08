#include <stdio.h>
#include <stdlib.h>

#define PAYRATE 12.00 /* hourly wage */
#define OVERTIME 40.00 /* greater than this number of hours overtime rates apply */
#define OVERTIMEMULT 1.5 /* Overtime multiplier */
#define TIER1 300.00 /* first tier of tiered tax rate */
#define TIER2 450.00 /* second tier of tiered tax rate */
#define TAXRATE_TIER1 0.75 /* pay multiplier for after taxes pay < TIER1 */
#define TAXRATE_TIER2 0.80 /* pay multiplier for after taxes pay > TIER1 and < TIER2 */
#define TAXRATE_REST 0.85 /* pay multiplier for after taxes pay > TIER2 */
#define OVERTIER1 300.00 * TAXRATE_TIER1 /* taxes when greater that tier 1 tax rate */
#define OVERTIER2 150.00 * TAXRATE_TIER2 /* taxes when greater that tier 2 tax rate */

int main()
{
	double grossPay = 0.0; /* total earnings received from hours worked */
	double taxes = 0.0;		 /* total tax paid based on earnings */
	double hours = 0.0;		 /* total hours worked */
	double netPay = 0.0;	 /* pay received after taxes */

	/* get inputs */
	printf("Please enter your hours worked: ");
	scanf("%lf", &hours);

	if (hours <= 40) /* if no overtime */
	{
		grossPay = hours * PAYRATE;
	}
	else
	{
		grossPay = OVERTIME * PAYRATE;
		grossPay += (hours - OVERTIME) * (PAYRATE * OVERTIMEMULT); /* pay for hours over OVERTIME */
	}
	/* tax rate is calculated based on 15% for first $300, 20% for next $150, and 25% for the remainder */

	if (grossPay <= TIER1)
	{
		netPay = grossPay * TAXRATE_TIER1;
	}
	else if (grossPay > TIER1 && grossPay <= TIER2)
	{
		netPay = OVERTIER1 + (grossPay - TIER1) * TAXRATE_TIER2;
	}
	else
	{
		netPay = OVERTIER1 + OVERTIER2 + (grossPay - TIER2) * TAXRATE_REST;
	}
	taxes = grossPay - netPay;

	printf("Gross pay: %.2f\nTotal tax: %.2f\nAfter Tax pay: %.2f\n", grossPay, taxes, netPay);
	return (0);
}
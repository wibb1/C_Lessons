#include <stdio.h>
#include <math.h>

int gcd(int n1, int n2);
float absoluteFloatValue(float value);
float squareRoot(float x);

int main()
{
	int n1;
	int n2;

	float f1 = -15.5;
	float f2 = 20.0;
	float f3 = -5.0;
	int i1 = -716;

	float s1 = 65.35;
	float s2 = f1;
	float s3 = f2;

	n1 = 150;
	n2 = 35;
	printf("The gcd of %d and %d is %d\n", n1, n2, gcd(n1, n2));
	n1 = 1026;
	n2 = 405;
	printf("The gcd of %d and %d is %d\n", n1, n2, gcd(n1, n2));
	n1 = 83;
	n2 = 240;
	printf("The gcd of %d and %d is %d\n", n1, n2, gcd(n1, n2));
	printf("\n\n\n");

	printf("The absolute float value of %.2f is %.2f\n", f1, absoluteFloatValue(f1));
	printf("The absolute float value of %.2f is %.2f\n", f2, absoluteFloatValue(f2));
	printf("The absolute float value of %.2f is %.2f\n", f3, absoluteFloatValue(f3));
	printf("The absolute float value of %.2f is %.2f\n", (float)i1, absoluteFloatValue((float)i1));

	printf("\n\n\n");
	printf("The square route of %.2f is %.2f\n", s1, squareRoot(s1));
	printf("The square route of %.2f is %.2f\n", s2, squareRoot(s2));
	printf("The square route of %.2f is %.2f\n", s3, squareRoot(s3));

	return (0);
}

float absoluteFloatValue(float value)
{
	return (value < 0) ? -value : value;
}

int gcd(int n1, int n2)
{
	int gcd;
	for (int i = 1; i <= n1 && i <= n2; i++)
	{
		if (n1 % i == 0 && n2 % i == 0)
		{
			gcd = i;
		}
	}
	return gcd;
}

float squareRoot(float x)
{
	const float epsilon = .00001;
	float guess = 1.0;

	float returnValue = 0.0;

	if (x < 0)
	{
		printf("Error: Called square root on negative number\n");
		returnValue = -1.0;
	}
	else
	{
		while (absoluteFloatValue(guess * guess - x) >= epsilon)
		{
			guess = (x / guess + guess) / 2.0;
		}
		returnValue = guess;
	}

	return returnValue;
}
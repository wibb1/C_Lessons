#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *outputfileptr;			 /* pointer to the output file */
	float width, height, area; /* width, height and area of rectangle */
	int counter = 0;					 /* counter for the while loop */

	/* open a file called home1.txt */
	if ((outputfileptr = fopen("home1.txt", "w")) == (FILE *)NULL)
	{
		fprintf(stderr, "Error, Unable to open file\n"); /* stderr will print to the screen */
		exit(1);
	}

	fprintf(outputfileptr, "Triangle Area Calculations\n\n");
	fprintf(outputfileptr, "Height\t Width\t  Area\n");

	/* get width from the comand line */
	printf("Enter the width of your rectangle\n");
	scanf("%f", &width);
	while (width > 0)
	{
		/* get height from the comand line */
		printf("Enter the height of your rectangle\n");
		scanf("%f", &height);

		/* calculate area */
		area = width * height;

		/* print output to text file */
		fprintf(outputfileptr, "%6.1f\t%6.1f\t%6.1f\n", width, height, area);

		counter++;

		/* get width from the comand line */
		printf("Enter the width of your rectangle\n");
		scanf("%f", &width);
	}
	return (0);
}
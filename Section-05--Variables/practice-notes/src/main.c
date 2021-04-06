#include <stdio.h>

int main()
{

	/* NOTES ON ENUM
			enum primaryColor {red, yellow, blue};  can only be assigned red, yellow or blue 

			enum primaryColor myColor, gregsColor;  defines the two variables myColor and gregsColor to be of type primaryColor => only red, yellow and blue 

			myColor = red;  acceptable 

			gregsColor = purple;  is not defined 

			enums are recognized by the number of their index red = 0; yellow = 1; blue = 2 

			enum direction {up, down, left = 10, right};   in this case the index would be up=0; down = 1, left = 10; right = 11 

	*/

	/* NOTES ON CHAR
			anything inside single quotes is a char.  can be unsigned => not negative. 

			char broiled; -- variable of broiled of type char
				broiled = 'T'; -- valid
				broiled = T; -- nope thinks T is variable
				broiled = "T"; -- nope "T" is a string
				broiled = 65; -- C will accept (will be converted to ASCII) but is poor style

				escape characters (i.e. \t or \n) which are actually single characters to C
				broiled = '\n'; -- this is acceptable but would not print \n it would do a new line
	*/

		enum gender {male, female};

		enum gender myGender;

		myGender = male;  /*correct */

		myGender = 44;  /* compiles but not really helpfull */

		myGender = "something else"; /* compile error */

		enum gender anotherGender;
		anotherGender = female;

		
}
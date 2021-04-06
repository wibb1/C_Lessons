#include <stdio.h>

int main()
{
	enum company {GOOGLE, FACEBOOK, XEROX, YAHOO, EBAY, MICROSOFT};
	enum company google =GOOGLE;
	enum company xerox =XEROX;
	enum company ebay =EBAY;

	printf("%d\n", (int)xerox);
	printf("%d\n", (int)google);
	printf("%d\n", (int)ebay);
	
	return (0);
}
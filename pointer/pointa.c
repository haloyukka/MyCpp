#include <stdio.h>

int main(void)
{
	char st[10] = "ABCDEFG";
	char *p1 , *p2;
	
	p1 = st;
	printf("%c" , *p1);
	printf("%c" , *(p1 + 1));
	printf("%c" , *(p1 + 2));
	printf("%c" , *(p1 + 5));
	
	p2 = st;
	printf("%c" , *p2);
	++p2;
	printf("%c" , *p2);
	++p2;
	printf("%c" , *p2);
	return 0;
}

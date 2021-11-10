#include <stdio.h>
void main()
{
	char str[50];
	int Sleng(char *);

	while(1){
		scanf("%s" , str);
		printf("[%s] --> %d\n\n" , str , Sleng(str));
	}
}

int Sleng(char *s)
{
	if(!*s) return 0;
	return(Sleng(++s) + 1);
}

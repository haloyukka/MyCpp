#include <stdio.h>

void func_A(void);

extern short s_sdata;

void main()
{
	char ret;

	while(1) {
		func_A();	// ˆ—‚`ŽÀs
		printf("func_A s_sdata = %d\n",s_sdata);

		printf("end ('y') ===>");
		scanf(" %c", &ret);
		if( ret == 'y' ) {
			break;
		}
	}
}

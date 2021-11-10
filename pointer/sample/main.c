#include <stdio.h>

short func_A(short data1, short data2);

void main()
{
	char ret;
	short sdata1,sdata2,add_data;

	sdata1 = 1;
	sdata2 = 1;
	while(1) {
		add_data = func_A(sdata1,sdata2);	// ˆ—‚`ŽÀs

		printf("add data = %d\n",add_data);
		sdata1++;
		sdata2++;

		printf("end ('y') ===>");
		scanf(" %c", &ret);
		if( ret == 'y' ) {
			break;
		}
	}
}

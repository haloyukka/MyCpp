#include <stdio.h>

void main()
{
	char ret;
	char cdata_min = 0x80;
	char cdata_max = 0x7F;
	short sdata_min = 0x8000;
	short sdata_max = 0x7FFF;
	int idata_min = 0x80000000;
	int idata_max = 0x7FFFFFFF;
	long ldata_min = 0x80000000;
	long ldata_max = 0x7FFFFFFF;
	float fdata_min = 0x80000000;
	float fdata_max = 0x7FFFFFFF;
	double ddata_min = 0x8000000000000000;
	double ddata_max = 0x7FFFFFFFFFFFFFFF;




	printf("%d‚Æ%d\n",cdata_min,cdata_max);
	printf("%d‚Æ%d\n",sdata_min,sdata_max);
	printf("%d‚Æ%d\n",idata_min,idata_max);
	printf("%d‚Æ%d\n",ldata_min,ldata_max);
	printf("%10.2f‚Æ%10.2f\n",fdata_min,fdata_max);
	printf("%f‚Æ%f\n",ddata_min,ddata_max);

	while(1) {
		printf("end ('y') ===>");
		scanf(" %c", &ret);
		if( ret == 'y' ) {
			break;
		}
	}

}
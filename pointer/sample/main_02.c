#include <stdio.h>

void main()
{
	char ret;
	unsigned char cdata_min = 0x00;
	unsigned char cdata_max = 0xFF;
	unsigned short sdata_min = 0x0000;
	unsigned short sdata_max = 0xFFFF;
	unsigned int idata_min = 0x0000;
	unsigned int idata_max = 0xFFFF;
	unsigned long ldata_min = 0x00000000;
	unsigned long ldata_max = 0xFFFFFFFF;
	float fdata_min = 0x80000000;
	float fdata_max = 0x3F800000;
	double ddata_min = 0x8000000000000000;
	double ddata_max = 0x7FFFFFFFFFFFFFFF;




	printf("char:   %d‚Æ%d\n",cdata_min,cdata_max);
	printf("short:  %d‚Æ%d\n",sdata_min,sdata_max);
	printf("int:    %d‚Æ%d\n",idata_min,idata_max);
	printf("long:   %lu‚Æ%lu\n",ldata_min,ldata_max);
	printf("float:  %f‚Æ%f\n",fdata_min,fdata_max);
	printf("double: %f‚Æ%f\n",ddata_min,ddata_max);

	while(1) {
		printf("end ('y') ===>");
		scanf(" %c", &ret);
		if( ret == 'y' ) {
			break;
		}
	}

}
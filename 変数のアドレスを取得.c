#include <stdio.h>

void main(){
	int a = 100;		// int�^�̕ϐ�
	double b = 123.4;	// double�^�̕ϐ�
	float c = 123.4f;	// float�^�̕ϐ�(���l�̌���f����)
	char d = 'a';		// char�^�̕ϐ�

	printf("a�̒l��%d�A�傫����%dbyte�A�A�h���X��0x%x?n",a,sizeof(int),&a);
	printf("b�̒l��%f�A�傫����%dbyte�A�A�h���X��0x%x?n",b,sizeof(double),&b);
	printf("c�̒l��%f�A�傫����%dbyte�A�A�h���X��0x%x?n",c,sizeof(float),&c);
	printf("d�̒l��%c�A�傫����%dbyte�A�A�h���X��0x%x?n",d,sizeof(char),&d);
}

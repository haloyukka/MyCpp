/******************************************************
C������K���Eif��������
 http://www9.plala.or.jp/sgwr-t/c_sub/index_en.html
 http://wwwpat.eng.u-toyama.ac.jp/flowchart/fc_sct.html
******************************************************/
#include <stdio.h>

void main()
{
	int a,b;
	char roop;

	while(1) {

		/* a,b�̃��[�U�[���� */
		printf("Enter a ===>");
		scanf(" %d", &a);
		printf("Enter b ===>");
		scanf(" %d", &b);

		/* a�͈̔̓`�F�b�N */
		if( a > 10) {
			printf("a ��10���傫��\n");
		}
		else
			printf("a ��10�ȉ�\n");

		/* a��b�̔�r*/
		if( a == b)
			printf("a �� b �͓�����\n");

		/* b�͈̔̓`�F�b�N*/
		if( b >= 10)
			printf("b ��10�ȏ�\n");
		else
			printf("b ��10��菬����\n");


		/* �����̑��s�m�F */
		
		printf("�J��Ԃ��܂���y/n ===>");
		scanf(" %c" , &roop);
		if(roop == 'n')
		{
			break;
		}
	
	}
}



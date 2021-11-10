---------------------------------------------------------------------------------------------------
main_01.c
---------------------------------------------------------------------------------------------------
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




	printf("%d��%d\n",cdata_min,cdata_max);
	printf("%d��%d\n",sdata_min,sdata_max);
	printf("%d��%d\n",idata_min,idata_max);
	printf("%d��%d\n",ldata_min,ldata_max);
	printf("%10.2f��%10.2f\n",fdata_min,fdata_max);
	printf("%f��%f\n",ddata_min,ddata_max);

	while(1) {
		printf("end ('y') ===>");
		scanf(" %c", &ret);
		if( ret == 'y' ) {
			break;
		}
	}

}

---------------------------------------------------------------------------------------------------
main_02.c
---------------------------------------------------------------------------------------------------

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




	printf("char:   %d��%d\n",cdata_min,cdata_max);
	printf("short:  %d��%d\n",sdata_min,sdata_max);
	printf("int:    %d��%d\n",idata_min,idata_max);
	printf("long:   %lu��%lu\n",ldata_min,ldata_max);
	printf("float:  %f��%f\n",fdata_min,fdata_max);
	printf("double: %f��%f\n",ddata_min,ddata_max);

	while(1) {
		printf("end ('y') ===>");
		scanf(" %c", &ret);
		if( ret == 'y' ) {
			break;
		}
	}
}

---------------------------------------------------------------------------------------------------
main_03.c
---------------------------------------------------------------------------------------------------
#include <stdio.h>

void func_A(void);

extern short s_sdata;

void main()
{
	char ret;

	while(1) {
		func_A();	// �����`���s
		printf("func_A s_sdata = %d\n",s_sdata);

		printf("end ('y') ===>");
		scanf(" %c", &ret);
		if( ret == 'y' ) {
			break;
		}
	}
}

---------------------------------------------------------------------------------------------------
sub_03.c
---------------------------------------------------------------------------------------------------
#include <stdio.h>

short s_sdata = 0;

void  func_A(void)
{
	s_sdata++;
}

---------------------------------------------------------------------------------------------------
multiplication
---------------------------------------------------------------------------------------------------
main.c
---------------------------------------------------------------------------------------------------
//
//  main.c
//  input
//
//  Created by ���� ���� on 2014/06/23.
//  Copyright (c) 2014�N ���� ����. All rights reserved.
//



#include <stdio.h>
int i , j;	/* �O���ϐ� */
int sub(void);

int main()
{

    printf("i����͂��ĉ�����>");
    scanf("%d" , &i);
    printf("j����͂��ĉ�����>");
    scanf("%d" , &j);

	sub();	/*���̊֐��R�[��*/
    
    return 0;


}

---------------------------------------------------------------------------------------------------
sub.c
---------------------------------------------------------------------------------------------------
//
//  sub.c
//  input
//
//  Created by ���� ���� on 2014/06/23.
//  Copyright (c) 2014�N ���� ����. All rights reserved.
//



#include<stdio.h>

/*�O���Q�Ɛ錾*/
extern int i; 
extern int j; 

int sub(void)
{

    int k , l;
    
    
    for(k = 1; k <= i-1; k++)  //i�œ��͂��ꂽ���l��-1�s�܂ł�\���B
    {
        for(l = 1; l <= 9; l++ )
        {
            printf("%3d" , k*l);
        }
        printf("\n");
    }
    
    for(k = i; k <= i; k++)  //last
    {
        for(l = 1; l <= j; l++ )
        {
            printf("%3d" , k*l);
        }
        printf("\n");
    }

    
    return 0;


}

---------------------------------------------------------------------------------------------------
main_01.c
---------------------------------------------------------------------------------------------------
//
//  main.c
//  input
//
//  Created by ���� ���� on 2014/06/23.
//  Copyright (c) 2014�N ���� ����. All rights reserved.
//

#include <stdio.h>
/*int i , j;*/	/* �O���ϐ� */
int sub(int i,int j);

int main()
{
    int i,j;

    printf("i����͂��ĉ�����>");
    scanf("%d" , &i);
    printf("j����͂��ĉ�����>");
    scanf("%d" , &j);

	sub(i,j);	/*���̊֐��R�[��*/
    
    return 0;


}

---------------------------------------------------------------------------------------------------
sub_01.c
---------------------------------------------------------------------------------------------------
//
//  sub.c
//  input
//
//  Created by ���� ���� on 2014/06/23.
//  Copyright (c) 2014�N ���� ����. All rights reserved.
//



#include<stdio.h>

/*�O���Q�Ɛ錾*/
/* extern int i; */
/* extern int j; */

int sub(int i,int j)
{

    int k , l;
    
    
    for(k = 1; k <= i-1; k++)  //i�œ��͂��ꂽ���l��-1�s�܂ł�\���B
    {
        for(l = 1; l <= 9; l++ )
        {
            printf("%3d" , k*l);
        }
        printf("\n");
    }
    
    for(k = i; k <= i; k++)  //last
    {
        for(l = 1; l <= j; l++ )
        {
            printf("%3d" , k*l);
        }
        printf("\n");
    }

    
    return 0;


}
---------------------------------------------------------------------------------------------------


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




	printf("%dと%d\n",cdata_min,cdata_max);
	printf("%dと%d\n",sdata_min,sdata_max);
	printf("%dと%d\n",idata_min,idata_max);
	printf("%dと%d\n",ldata_min,ldata_max);
	printf("%10.2fと%10.2f\n",fdata_min,fdata_max);
	printf("%fと%f\n",ddata_min,ddata_max);

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




	printf("char:   %dと%d\n",cdata_min,cdata_max);
	printf("short:  %dと%d\n",sdata_min,sdata_max);
	printf("int:    %dと%d\n",idata_min,idata_max);
	printf("long:   %luと%lu\n",ldata_min,ldata_max);
	printf("float:  %fと%f\n",fdata_min,fdata_max);
	printf("double: %fと%f\n",ddata_min,ddata_max);

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
		func_A();	// 処理Ａ実行
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
//  Created by 高橋 琢磨 on 2014/06/23.
//  Copyright (c) 2014年 高橋 琢磨. All rights reserved.
//



#include <stdio.h>
int i , j;	/* 外部変数 */
int sub(void);

int main()
{

    printf("iを入力して下さい>");
    scanf("%d" , &i);
    printf("jを入力して下さい>");
    scanf("%d" , &j);

	sub();	/*九九の関数コール*/
    
    return 0;


}

---------------------------------------------------------------------------------------------------
sub.c
---------------------------------------------------------------------------------------------------
//
//  sub.c
//  input
//
//  Created by 高橋 琢磨 on 2014/06/23.
//  Copyright (c) 2014年 高橋 琢磨. All rights reserved.
//



#include<stdio.h>

/*外部参照宣言*/
extern int i; 
extern int j; 

int sub(void)
{

    int k , l;
    
    
    for(k = 1; k <= i-1; k++)  //iで入力された数値の-1行までを表示。
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
//  Created by 高橋 琢磨 on 2014/06/23.
//  Copyright (c) 2014年 高橋 琢磨. All rights reserved.
//

#include <stdio.h>
/*int i , j;*/	/* 外部変数 */
int sub(int i,int j);

int main()
{
    int i,j;

    printf("iを入力して下さい>");
    scanf("%d" , &i);
    printf("jを入力して下さい>");
    scanf("%d" , &j);

	sub(i,j);	/*九九の関数コール*/
    
    return 0;


}

---------------------------------------------------------------------------------------------------
sub_01.c
---------------------------------------------------------------------------------------------------
//
//  sub.c
//  input
//
//  Created by 高橋 琢磨 on 2014/06/23.
//  Copyright (c) 2014年 高橋 琢磨. All rights reserved.
//



#include<stdio.h>

/*外部参照宣言*/
/* extern int i; */
/* extern int j; */

int sub(int i,int j)
{

    int k , l;
    
    
    for(k = 1; k <= i-1; k++)  //iで入力された数値の-1行までを表示。
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


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
	int flag1 = 0;
	int flag2 = 0;
    int k , l;

    /*iとjの入力チェック*/
	if( (i >= 1) && (i <= 9) ) {
		flag1 = 1;
	}

	if( (j >= 1) && (j <= 9) ) {
		flag2 = 1;
	}

	/* i条件一致 かつ j条件一致 */
	if((flag1 == 1) && (flag2 == 1))
	{
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

	/* i,j条件不一致 */
	} else {

		printf("もう一度入力してください！\n");

		return 1;
	}

}


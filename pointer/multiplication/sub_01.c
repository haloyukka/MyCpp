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


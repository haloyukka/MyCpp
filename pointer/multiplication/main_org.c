//
//  main.c
//  input
//
//  Created by 高橋 琢磨 on 2014/06/23.
//  Copyright (c) 2014年 高橋 琢磨. All rights reserved.
//



#include<stdio.h>

int main()
{
    int i , j;
    int k , l;
    
    printf("iを入力して下さい>");
    scanf("%d" , &i);
    printf("jを入力して下さい>");
    scanf("%d" , &j);
    
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


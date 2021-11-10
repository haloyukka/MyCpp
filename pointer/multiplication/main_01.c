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


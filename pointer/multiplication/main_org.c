//
//  main.c
//  input
//
//  Created by ���� ���� on 2014/06/23.
//  Copyright (c) 2014�N ���� ����. All rights reserved.
//



#include<stdio.h>

int main()
{
    int i , j;
    int k , l;
    
    printf("i����͂��ĉ�����>");
    scanf("%d" , &i);
    printf("j����͂��ĉ�����>");
    scanf("%d" , &j);
    
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


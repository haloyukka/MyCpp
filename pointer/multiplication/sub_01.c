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


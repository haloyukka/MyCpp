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


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
	int ret;
	char roop;

	while(1)
	{
		printf("i����͂��ĉ�����>");
		scanf("%d" , &i);
		printf("j����͂��ĉ�����>");
		scanf("%d" , &j);

		ret = sub();	/*���̊֐��R�[��*/

		if(ret == 0)
		{
			printf("�J��Ԃ��܂���y/n ===>");
			scanf(" %c" , &roop);
			if(roop == 'n')
			{
				break;
			}
		}
	
	}

	return 0;


}


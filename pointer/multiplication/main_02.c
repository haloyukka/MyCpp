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
	int ret;
	char roop;

	while(1)
	{
		printf("iを入力して下さい>");
		scanf("%d" , &i);
		printf("jを入力して下さい>");
		scanf("%d" , &j);

		ret = sub();	/*九九の関数コール*/

		if(ret == 0)
		{
			printf("繰り返しますかy/n ===>");
			scanf(" %c" , &roop);
			if(roop == 'n')
			{
				break;
			}
		}
	
	}

	return 0;


}


//
//  sub.c
//  input
//
//  Created by ���� ���� on 2014/06/23.
//  Copyright (c) 2014�N ���� ����. All rights reserved.
//



#include<stdio.h>

/*�O���Q�Ɛ錾*/
extern int i; 
extern int j; 

int sub(void)
{
	int flag1 = 0;
	int flag2 = 0;
    int k , l;

    /*i��j�̓��̓`�F�b�N*/
	if( (i >= 1) && (i <= 9) ) {
		flag1 = 1;
	}

	if( (j >= 1) && (j <= 9) ) {
		flag2 = 1;
	}

	/* i������v ���� j������v */
	if((flag1 == 1) && (flag2 == 1))
	{
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

	/* i,j�����s��v */
	} else {

		printf("������x���͂��Ă��������I\n");

		return 1;
	}

}


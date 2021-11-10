/******************************************************
C言語練習問題・if文を扱う
 http://www9.plala.or.jp/sgwr-t/c_sub/index_en.html
 http://wwwpat.eng.u-toyama.ac.jp/flowchart/fc_sct.html
******************************************************/
#include <stdio.h>

void main()
{
	int a,b;
	char roop;

	while(1) {

		/* a,bのユーザー入力 */
		printf("Enter a ===>");
		scanf(" %d", &a);
		printf("Enter b ===>");
		scanf(" %d", &b);

		/* aの範囲チェック */
		if( a > 10) {
			printf("a は10より大きい\n");
		}
		else
			printf("a は10以下\n");

		/* aとbの比較*/
		if( a == b)
			printf("a と b は等しい\n");

		/* bの範囲チェック*/
		if( b >= 10)
			printf("b は10以上\n");
		else
			printf("b は10より小さい\n");


		/* 処理の続行確認 */
		
		printf("繰り返しますかy/n ===>");
		scanf(" %c" , &roop);
		if(roop == 'n')
		{
			break;
		}
	
	}
}



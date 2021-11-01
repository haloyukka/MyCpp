// 構造体メンバで関数ポインタを取り扱う

#include<stdio.h>
#include<string.h>

/*プロトタイプ宣言*/
void TestFunc();
void TestFunc1();

/*構造体定義*/
struct command_rec{
	char *name; //コマンド名
	void (*func)(); //コマンドに対応する関数
};

/*構造体配列の宣言*/
struct command_rec Command[] = {
	{"test",TestFunc},
	{"test1",TestFunc1},
	{NULL,NULL}
};

int main(){
	//いろいろ宣言
	struct command_rec *p;
	char str[256];
	strcpy(str, "test1");

	printf("コマンドを入力してください：");
	scanf("%s",str);
	
	//構造体配列の先頭から入力文字を比較
	for( p=Command ; p->name!=NULL ; p++ ){
		if( strcmp(p->name,str) == 0 ){
			p->func(); //コマンドに対応する関数を呼び出し
			//exit(); //コマンドが見つかったら終了
		}
	}
	
	printf("そのコマンドは存在しません。\n");
	
	return 0;
	
}

void TestFunc(){
	printf("テストコマンドを実行しました。\n");
}

void TestFunc1(){
	printf("テストコマンドを実行しようとしましたが挫折。\n");
}
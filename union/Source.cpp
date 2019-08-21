#include <stdio.h>
#include <string.h>
#include <conio.h>

union U  /* 共用体Uを定義 */
{
	double x;
	int y;
	char z[10];
	/* double, int, char[10]のいずれかを格納できる */
};

union Hoge  /* 共用体Hogeを定義：構造体の共用体 */
{
	struct Foo {
		int ifoo;
		double dfoo;
	} foo; /* 構造体Fooとメンバfooの定義 */
	struct Bar {
		int ibar;
		void *pbar;
	} bar; /* 構造体Barとメンバbarの定義 */
}; /* FooとBarの先頭メンバは同じ型(int) */

   /* 共用体を使ってみる */
int main(void) {
	union U u = { 100.0 };      /* 共用体変数の宣言と初期化 */
								/* 先頭メンバの型(double)で初期化しなければならない */
	union Hoge hoge;
	struct Hoge:: Foo f = { 3, 0.14 }; /* ※注：C++では「Hoge::Foo f = ...;」とする */

	u.y = 42;                   /* int型の値を書き込む */
	strcpy(u.z, "UnionTest");   /* charの配列を書き込む */

								/* u.y += 100; */           /* 不正：charの配列が入ったuをint型として扱っている */

	hoge.foo = f;               /* Foo構造体を書き込む */
	hoge.bar.ibar = 9;          /* OK:Barの先頭メンバとしてアクセスしても良い */
								/* hoge.bar.pbar = NULL; */ /* これはダメ：今hogeに入っているのはあくまでFoo型 */

	_getch();
	return 0;
}
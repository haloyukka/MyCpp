#include <stdio.h>
#include <string.h>
#include <conio.h>

union U  /* ���p��U���` */
{
	double x;
	int y;
	char z[10];
	/* double, int, char[10]�̂����ꂩ���i�[�ł��� */
};

union Hoge  /* ���p��Hoge���`�F�\���̂̋��p�� */
{
	struct Foo {
		int ifoo;
		double dfoo;
	} foo; /* �\����Foo�ƃ����ofoo�̒�` */
	struct Bar {
		int ibar;
		void *pbar;
	} bar; /* �\����Bar�ƃ����obar�̒�` */
}; /* Foo��Bar�̐擪�����o�͓����^(int) */

   /* ���p�̂��g���Ă݂� */
int main(void) {
	union U u = { 100.0 };      /* ���p�̕ϐ��̐錾�Ə����� */
								/* �擪�����o�̌^(double)�ŏ��������Ȃ���΂Ȃ�Ȃ� */
	union Hoge hoge;
	struct Hoge:: Foo f = { 3, 0.14 }; /* �����FC++�ł́uHoge::Foo f = ...;�v�Ƃ��� */

	u.y = 42;                   /* int�^�̒l���������� */
	strcpy(u.z, "UnionTest");   /* char�̔z����������� */

								/* u.y += 100; */           /* �s���Fchar�̔z�񂪓�����u��int�^�Ƃ��Ĉ����Ă��� */

	hoge.foo = f;               /* Foo�\���̂��������� */
	hoge.bar.ibar = 9;          /* OK:Bar�̐擪�����o�Ƃ��ăA�N�Z�X���Ă��ǂ� */
								/* hoge.bar.pbar = NULL; */ /* ����̓_���F��hoge�ɓ����Ă���̂͂����܂�Foo�^ */

	_getch();
	return 0;
}
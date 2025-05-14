#include "stdio.h"
#include "conio.h"

int main(void)
{
	double n = 1.0, s = 120.0, p = 0.05, q = 100.0;
	__asm {
		fld s
	l1:
		ffree st(1)
		ffree st(2)
		ffree st(3)
		ffree st(4)
		fld1
		fld n
		fadd st(0), st(1)
		fstp n
		fld q
		fld st(0)
		fld p
		fmul st(0), st(1)
		fadd st(0), st(1)
		fst q
		fcom s
		fstsw ax
		sahf
		jb l1
		fstp q
	}
	printf("God => %g\n", n);
	printf("Kol-vo gektarov ==> %g\n", q);
	_getch();
	return 0;
}
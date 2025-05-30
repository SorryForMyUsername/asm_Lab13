#include "stdio.h"
#include "conio.h"

int main()
{
	double x = -1.1, sum;
	__asm {
		fldz //сумма
		fld1 //х в степени
		fld1 //шаг
		fadd st(0), st(1)
		fld st(0) //начало
		fld1 //конец
		fadd st(0), st(1)
		fadd st(0), st(1)
		fadd st(0), st(0)
		fld x
	l1:
		fmul st(4), st(0)
		fmul st(4), st(0)
		fld st(4)
		fdiv st(0), st(3)
		faddp st(6), st(0)
		fxch st(2)
		fadd st(0), st(3)
		fcomi st(0), st(1)
		fxch st(2)
		jbe l1

		fxch st(5)
		fstp sum
	}
	printf(" sum = %g\n", sum);
	_getch();
	return 0;
}
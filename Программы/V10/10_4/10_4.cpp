#include "stdio.h"
#include "conio.h"

int main()
{
	int n = 10;
	double sum;
	__asm {
		fldz
		fld1
		fsubp st(1), st(0)
		fild n
		fldz //сумма
		fldz //сумма синусов
		fld1 //текущее слагаемое
		fld1 //знак
	l1:
		fmul st(0), st(5)
		fxch st(1)
		fld st(0)
		fsin
		faddp st(3), st(0)
		fld1
		fdiv st(0), st(3)
		fmul st(0), st(2)
		faddp st(4), st(0)
		fld1
		faddp st(1), st(0)
		fld st(4)
		fcomip st(0), st(1)
		fxch st(1)
		jae l1

		fxch st(3)
		fstp sum
	}
	printf(" sum = %g\n", sum);
	_getch();
	return 0;
}
#include "stdio.h"
#include "conio.h"

int main()
{
	int n = 5;
	double sum;

	__asm {
		fldz
		fld1
		fsubp st(1), st(0)
		fild n
		fldz        // сумма
		fldz        // k
		fld1        // факториал
		fld st(4)   // знак
	l1:
		fmul st(0), st(5)
		fld st(2)
		fld1
		faddp st(1), st(0)
		fmul st(0), st(1)
		fxch st(3)
		fld1
		fcomip st(0), st(1)
		jae l2
			fmul st(2), st(0)
	l2:
		fxch st(3)
		fdiv st(0), st(2)
		faddp st(4), st(0)
		
		fxch st(4)
		fxch st(1)
		fxch st(2)
		fld1
		faddp st(1), st(0)
		fcomi st(0), st(1)
		fxch st(2)
		fxch st(1)
		fxch st(4)
		jbe l1

		fxch st(3)
		fstp sum
	}
	printf(" sum = %g\n", sum);
	_getch();
	return 0;
}
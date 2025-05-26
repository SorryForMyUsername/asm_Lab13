#include "stdio.h"
#include "conio.h"

int main(void)
{
	double a = 1.3, x;
	__asm {
		fld1
		fldz
		fld a
		fld1
	l1:
		fld st(1)
		fdivr st(0), st(1)
		fadd st(0), st(2)
		fxch st(1)
		fxch st(3)
		fcomi st(0), st(1)
		fxch st(1)
		ja l2

		fstp x
	}
	printf("x = %g\n", x);
	_getch();
	return 0;
}
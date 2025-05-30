#include "stdio.h"
#include "conio.h"

int main()
{
	double a = 1.25, x;
	int divider;
	__asm {
		fld a
		fld1
		fld1
		fadd st(0), st(0)
		fadd st(0), st(1)
	l1:
		fld1
		fdiv st(0), st(1)
		fadd st(0), st(2)
		fxch st(1)
		fxch st(3)
		fcomi st(0), st(1)
		ja l2
			fxch st(3)
			fadd st(0), st(2)
			fxch st(1)
			fstp st(0)
			jmp l1
	l2:
		fxch st(3)
		fistp divider
		fstp x
	}
	printf(" x = %g (1+1/%d)\n", x, divider);
	_getch();
	return 0;
}
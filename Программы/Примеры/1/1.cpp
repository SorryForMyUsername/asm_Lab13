#include "stdio.h"
#include "conio.h"

int main(void)
{
	double x = 1.0, q = 0.5, sum = 0.0;
	int n = 3;
	__asm {
		mov ecx, n
	l1:
		fld q
		fld x
		fmul st(0), st(1)
		fstp x
		fld x
		fld sum
		fadd st(0), st(1)
		fstp sum
		loop l1
	}
	printf("sum = %f\n", sum);
	_getch();
	return 0;
}
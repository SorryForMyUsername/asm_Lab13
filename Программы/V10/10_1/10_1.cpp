#include "stdio.h"
#include "conio.h"

int main()
{
	double x = 1000, income = 1.03, moneyInTheEnd;

	int months = 12;


	double deposits[] = {
		120.5, 125, 113, 
		119.5, 118, 124, 
		145.5, 156, 115, 
		147.5, 109, 123
	};

	__asm {
		fld x
		fld income
		mov ecx, 0
		mov ebx, 0
		mov eax, months
	l1:
		fld deposits[ecx*8]
		faddp st(2), st(0)
		inc ebx
		cmp ebx, 3
		jl l2
			fmul st(1), st(0)
			mov ebx, 0
	l2:
		inc ecx
		cmp ecx, eax
		jl l1

		fstp st(0)
		fstp moneyInTheEnd
	}
	printf(" Money = %g\n", moneyInTheEnd);
	_getch();
	return 0;
}
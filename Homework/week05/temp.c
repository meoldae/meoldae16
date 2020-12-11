#include <stdio.h>

int func4(int edx, int esi, int edi){
	int eax = edx;
	eax = eax - esi;
	int ebx = eax;
	ebx = 0;
	ebx = ebx + eax;
	ebx = ebx / 2;
	ebx = ebx + esi;
	
	if (ebx > edi) {
		
		return func4(ebx-1, esi, edi)+ebx;
	}
	else if (ebx < edi) {
		
		return func4(edx, ebx+1, edi)+ebx;
	}
	else {
		return ebx;
	}
}

int main(void) {
	int x = 14;
	int y = 0;
	
	for (int i = 1; i < 14; i++) {
	printf("%d, %d\n\n", i, func4(x, y, i));
	}
	return 0;
}
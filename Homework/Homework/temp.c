#include <stdio.h>

int getByte(int x, int n) {
	int y =n << 3;
	x = x >> y;
	return x&0xff;
}

int main(void) {
	int x = 0x12345678;
	printf("%08x\n", getByte(x, 0));
	printf("%08x\n", getByte(x, 1));
	printf("%08x\n", getByte(x, 2));
	printf("%08x\n", getByte(x, 3));
	return 0;
}
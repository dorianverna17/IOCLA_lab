#include <stdio.h>

void rotate_left(int *number, int bits)
{
	/* TODO */
	__uint32_t x = -1;
	x = x << (32 - bits);
	x = x & *number;
	x = x >> (32 - bits);
	*number = (*number << bits) + x;
	printf("%d\n", *number);
}

void rotate_right(int *number, int bits)
{
	/* TODO */
	__uint32_t x = -1;
	x = x >> (32 - bits);
	x = x & *number;
	x = x << (32 - bits);
	*number = (*number >> bits) + x;
	printf("%d\n", *number);
}

int main()
{
	/* TODO: Test functions */
	int x = 0x80000000;
	rotate_left(&x, 1);
	x = 0b00000001;
	rotate_right(&x, 16);
	return 0;
}


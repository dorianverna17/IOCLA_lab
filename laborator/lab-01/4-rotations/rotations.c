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
	printf("%x\n", *number);
}

int main()
{
	/* TODO: Test functions */
	int x = 0b00010111;
	rotate_left(&x, 1);
	x = 0b00010111;
	rotate_right(&x, 1);
	return 0;
}


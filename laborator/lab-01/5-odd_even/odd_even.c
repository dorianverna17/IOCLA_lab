#include <stdio.h>
#include <stdlib.h>

void print_binary(int number, int nr_bits)
{
	/* TODO */
	int i;

	printf("0b	");
	for (i = 0; i < nr_bits; i++) {
		if ((number & (1 << (nr_bits - i - 1))) != 0)
			printf("1");
		else
			printf("0");
	}
	printf("\n");
}

void check_parity(int *numbers, int n)
{
	/* TODO */
	int i;
	__uint32_t var = 1;

	for (i = 0; i < n; i++) {
		if ((*(numbers + i) & var) == 0)
			print_binary(*(numbers + i), 8);
		else
			printf("0x%.8x\n", *(numbers + i));
	}
}

int main()
{
	/* TODO: Test functions */
	int v[] = {214, 71, 84, 134, 86};
	check_parity(v, 5);
	return 0;
}


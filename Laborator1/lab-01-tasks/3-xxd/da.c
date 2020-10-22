#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	FILE *f = fopen("binary_file", "rb");
	char da;
	fscanf(f, "%c", &da);
	printf("%c\n", da);
	fscanf(f, "%c", &da);
	printf("%c\n", da);
	fscanf(f, "%c", &da);
	printf("%c\n", da);
	fclose(f);
	return 0;
}
#include <stdio.h>

int main() {
	int v[] = {1, 2, 3, 6, 8, 6};
	int dim = 5, max = v[0], aux = 0;

label:
	if (aux <= dim) {
		if (v[aux] > max) {
			max = v[aux];
		}
		aux++;
		goto label;
	}
	printf("%d\n", max);
	return 0;
}
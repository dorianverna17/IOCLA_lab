#include <stdio.h>

int main() {
	int v[] = {2, -9, 3, 1, 3, 0, 5, 4, 7};
	int dim = 8, schimb = 0, i, aux;

label1:
	schimb = 0;
	i = 0;
label2:
	if (v[i] > v[i + 1]) {
		aux = v[i];
		v[i] = v[i + 1];
		v[i + 1] = aux;
		schimb = 1;
	}
	i++;
	if (i < dim)
		goto label2;
	if (schimb == 1)
		goto label1;

	for (i = 0; i <= dim; i++)
		printf("%d ", v[i]);
	printf("\n");

	return 0;
}

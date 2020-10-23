#include <stdio.h>

int main() {
	int v[] = {1, 2, 3, 6, 7, 8};
	int dim = 5, mid, val, start = 0;

	// cautam 7
	val = 7;
label:
	mid = (dim + start) / 2;
	if (val != v[mid]) {
		if (val < v[mid]) {
			dim = mid - 1;
			goto label;
		} else {
			if (val > v[mid]) {
				start = mid + 1;
				goto label;
			}
		}
	}

	printf("%d\n", mid);
	return 0;
}
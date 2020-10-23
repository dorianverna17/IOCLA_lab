#include <stdio.h>
#include <string.h>

int main() {
	char str1[] = "abcdefgacdcd";
	char str2[] = "cd";
	int i, aux, j;

// implementare fara goto
	for (i = 0; i < strlen(str1); i++) {
		aux = i;
		for (j = 0; j < strlen(str2); j++) {
			if (str1[aux] == str2[j]) {
				aux++;
				continue;
			}
			else
				break;
		}
		if (j == strlen(str2)) {
// Aici am comentat afisarea rezultatului
			//printf("%d\n", i);
		}
	}

// implementare cu goto
	i = 0;
label1:
	aux = i;
	j = 0;
label2:
	if (j < strlen(str2)) {
		if (str1[aux] == str2[j]) {
			aux++;
			j++;
			goto label2;
		} else {
			i++;
			goto label1;
		}
	}
	if (j == strlen(str2)) {
		printf("%d\n", i);
		if (i < strlen(str1) - strlen(str2) - 1) {
			i++;
			goto label1;
		}
	}
	return 0;
}
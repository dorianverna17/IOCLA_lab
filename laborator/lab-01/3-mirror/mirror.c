#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mirror(char *s)
{
	/* TODO */
	char aux;
	int nr = strlen(s); 
	unsigned int i = 0;

	while (i != (strlen(s) >> 1)) {
		aux = *(s + i);
		*(s + i) = *(s + nr - i - 1);
		*(s + nr - i - 1) = aux;
		i++;
	}
	printf("%s\n", s);
}

int main()
{
	/* TODO: Test function */
	char *s = malloc(100 * sizeof(char));
	strcpy(s, "qwerty");
	mirror(s);
	return 0;
}


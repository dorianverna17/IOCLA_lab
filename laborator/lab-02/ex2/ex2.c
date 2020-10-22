#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* delete_first(char *s, char *pattern) {
	char *aux = malloc(sizeof(s) - sizeof(pattern) + 1);
	char *p = strstr(s, pattern);
	strncpy(aux, s, p - s);
	strcat(aux, p + strlen(pattern));
	return aux;
}

int main(){
	char *s = "Ana are mere";
	char *pattern = "re";
	// Decomentati linia dupa ce ati implementat functia delete_first.
	printf("%s\n", delete_first(s, pattern));

	return 0;
}

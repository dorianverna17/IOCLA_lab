#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

int my_strcmp(const char *s1, const char *s2) {
	int aux = 0;
	
	while (aux < strlen(s1) && aux < strlen(s2)) {
		if (s1[aux] == s2[aux]) {
			aux++;
		} else {
			return s1[aux] - s2[aux];
		}
	}
	return 0;
}

void *my_memcpy(void *dest, const void *src, size_t n) {
	char *s1 = (char*)dest;
	char *s2 = (char*)src;

	for (int i = 0; i < n; i++) {
		s1[i] = s2[i];
	}
	return dest;
}

char *my_strcpy(char *dest, const char *src) {
	int i;

	for (i = 0; i < strlen(src); i++) {
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return dest;
}

int main() {
	char s1[] = "Abracaeabra";
	char s2[] = "Abracababra";
	char src[] = "Learn IOCLA, you must!";
	char *dest = malloc(sizeof(src));

	/*
	Decomentati pe rand cate un assert pe masura ce implementati o functie.
	Daca functia voastra este implementata corect atunci asertia se va realiza
	cu succes. In caz contrar, programul va crapa.
	*/
	assert(my_strcmp(s1, s2) == strcmp(s1, s2));
	assert(my_memcpy(dest, src, sizeof(src)) == memcpy(dest, src, sizeof(src)));
	assert(my_strcpy(dest, src) == strcpy(dest, src));
	free(dest);

	return 0;
}

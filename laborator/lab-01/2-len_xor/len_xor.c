#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_strlen(const char *str)
{
	/* TODO */
	if (*str != '\0') {
		return 1 + my_strlen(str + 1);
	}
	return 0;
}

void equality_check(const char *str)
{
	/* TODO */
	int i;

	for(i = 0; i < my_strlen(str); i++) {
		if ((*(str + i)) ^ (*(str + i + (1 << i)))) {
			continue;
		} else {
			printf("Adresa of %c: %p\n",*(str + i) , str + i);
		}
	}
}

int main(void)
{
	/* TODO: Test functions */
	char s[4];
	strcpy(s, "aac");
	printf("%d\n", my_strlen(s));
	equality_check(s);
	return 0;
}


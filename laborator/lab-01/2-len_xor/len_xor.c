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
	int i, n;

	for(i = 0; i < my_strlen(str); i++) {
		n = i + (1 << i);
		if (n >= my_strlen(str))
			n = n % my_strlen(str);
		if ((*(str + i)) ^ (*(str + n))) {
			continue;
		} else {
			printf("Adresa of %c: %p\n",*(str + i) , str + i);
		}
	}
}

int main(void)
{
	/* TODO: Test functions */
	char s[30];
	strcpy(s, "ababababacccbacbacbacbacbabc");
	printf("%d\n", my_strlen(s));
	equality_check(s);
	return 0;
}


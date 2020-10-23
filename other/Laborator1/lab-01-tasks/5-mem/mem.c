#include <stdio.h>

int main(void)
{
    unsigned int a = 4127;
    int b = -27714;
    unsigned int c = 0x12345678;
    char d[] = {'I', 'O', 'C', 'L', 'A', 'A', 'D', 'F', 'A'};
   	char s[] = "dorian";

    // TODO
    printf("%zu\n", sizeof(int));
    unsigned char *p;
    p = (unsigned char *) &a;
    printf("0x%x\n", a);
    printf("a:");
    for (int i = 0; i < sizeof(a); i++)
    	printf(" 0x%02x", p[i]);
    printf("\n");

    //pentru b
    p = (unsigned char *) &b;
    printf("0x%x\n", b);
    printf("b:");
    for (int i = 0; i < sizeof(b); i++)
    	printf(" 0x%02x", p[i]);
    printf("\n");

    //pentru c
	p = (unsigned char *) &c;
    printf("0x%x\n", c);
    printf("c:");
    for (int i = 0; i < sizeof(c); i++)
    	printf(" 0x%02x", p[i]);
    printf("\n");

    //pentry d
    printf("%zu\n", sizeof(char *));
    printf("%zu\n", sizeof(d));
	p = (unsigned char *) d;
    printf("%s\n", d);
    printf("d:");
    for (int i = 0; i < sizeof(d); i++)
    	printf(" 0x%02x", p[i]);
    printf("\n");


    p = (unsigned char *) s;
    printf("%s\n", s);
    printf("s:");
    for (int i = 0; i < sizeof(s); i++)
    	printf(" 0x%02x", p[i]);
    printf("\n");       
    return 0;
}

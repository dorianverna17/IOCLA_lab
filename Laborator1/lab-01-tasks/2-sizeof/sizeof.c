#include <stdio.h>
int main()
{
    char charT;
    short shortT;
    int integerT;	
    unsigned int unsignedIntegerT;
    long longT;
    long long longlongT;
    void * voidT;

    // TODO - use sizeof to print size of the above types

    printf("char: %zu\n", sizeof(charT));
    printf("short: %zu\n", sizeof(shortT));
    printf("unsigned int: %zu\n", sizeof(unsignedIntegerT));
    printf("long: %zu\n", sizeof(longT));
    printf("long long: %zu\n", sizeof(longlongT));
    printf("void *: %zu\n", sizeof(voidT));

    return 0;
}

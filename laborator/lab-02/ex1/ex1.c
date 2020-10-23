#include <stdio.h>

/**
 * Afisati adresele elementelor din vectorul "v" impreuna cu valorile
 * de la acestea.
 * Parcurgeti adresele, pe rand, din octet in octet,
 * din 2 in 2 octeti si apoi din 4 in 4.
 */

int main() {
    int v[] = {0xCAFEBABE, 0xDEADBEEF, 0x0B00B135, 0xBAADF00D, 0xDEADC0DE};

    unsigned char *ptr = &v;
    for (int i = 0; i < (sizeof(v) / sizeof(*v)) * sizeof(int); i++) {
    	printf("%p -> 0x%x\n", ptr, *ptr);
    	ptr++;
    }
    printf("\n");

    ptr = &v;
    for (int i = 0; i < (sizeof(v) / sizeof(*ptr)); i++) {
    	printf("%p -> 0x%x\n", ptr, *ptr);
    	ptr++;
    }

    printf("\n");
    unsigned short *p = &v;
    for (int i = 0; i < (sizeof(v) / sizeof(*v)) * sizeof(int); i += 2) {
    	printf("%p -> 0x%x\n", p, *p);
    	p++;
    }
    printf("\n");
    int *p1 = &v;
    for (int i = 0; i < (sizeof(v) / sizeof(*v)) * sizeof(int); i+=4) {
    	printf("%p -> 0x%x\n", p1, *p1);
    	p1++;
    }
    printf("\n");

    ptr = &v;
    // adunarea unui întreg n la un pointer p (p + n)
    // reprezintă de fapt p + n * sizeof(*p)
    printf("%d %d\n", v + (sizeof(v) / sizeof(*v)), v);
    while (ptr < v + (sizeof(v) / sizeof(*v))) {
    	printf("%p -> 0x%x\n", ptr, *ptr);
    	ptr++;
    }
    return 0;
}

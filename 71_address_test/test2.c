#include <stdio.h>

int main()
{
    int x = 1;
    int *p = &x;
    int *q = p;

    printf("xのアドレス: %p\n", (void *)p);
    printf("pのアドレス: %p\n", (void *)p);
    printf("qのアドレス: %p\n", (void *)q);

    printf("p-1: %d\n", *p);

    *q = 2;

    printf("p-2: %d\n", *p);

    printf("x: %d\n", x);

    return 0;
}
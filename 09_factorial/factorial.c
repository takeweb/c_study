#include <stdio.h>
#include <stdlib.h>

int factorial(int n);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "usage: %s <number>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    printf("input: %d\n", n);
    int x = factorial(n);
    printf("result: %d\n", x);
}

int factorial(int n) {
    int x = 1;
    for (int i = 2; i <= n; i++) {
        x *= i;
    }
    return x;
}


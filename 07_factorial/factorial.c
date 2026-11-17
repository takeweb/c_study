#include <stdio.h>
#include <stdlib.h>

unsigned long long factorial(int n) {
    unsigned long long result = 1;
    for (int i = n; i > 1; i--) {
        result *= i;
    }
    return result;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "usage: %s <number>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    printf("input: %d\n", n);
    unsigned long long x = factorial(n);
    printf("result: %llu\n", x);
}


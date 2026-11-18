#include <stdio.h>
#include <stdlib.h>

int sum_of_divisors(int n);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "usage: %s <number>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    if (n <= 0) {
        fprintf(stderr, "正の整数を入力してください: %s\n", argv[1]);
        return 1;
    }

    printf("input: %d\n", n);
    int x = sum_of_divisors(n);
    
    if (n == x) {
        printf("this number is a Perfect Number: %d\n", x);
    } else {
        printf("this number is not a Perfect Number: %d\n", x);
    }
}

int sum_of_divisors(int n) {
    int result = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            result += i;
        }
    }
    return result;
}

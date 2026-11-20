#include <stdio.h>

/* 
 * 入力を出力に複写: 第2版
 */
int main() {
    int c;
    while ((c = getchar()) != EOF) {
        putchar(c);
    }
}

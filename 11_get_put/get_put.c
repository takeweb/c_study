#include <stdio.h>

/* 
 * 入力を出力に複写: 第1版
 */
int main() {
    int c = getchar();
    while (c != EOF) {
        putchar(c);
        c = getchar();
    }
}

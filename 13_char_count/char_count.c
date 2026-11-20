#include <stdio.h>

/* 
 * 入力された文字数をカウント: 第1版
 */
int main() {
    long nc = 0;
    while (getchar() != EOF) {
        ++nc;
    }
    printf("Char Count: %ld\n", nc);
}

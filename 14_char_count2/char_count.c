#include <stdio.h>

/* 
 * 入力された文字数をカウント: 第2版
 */
int main() {
    double nc; 
    for (nc = 0; getchar() != EOF; nc++) {
        ;
    }
    printf("Char Count: %.0f\n", nc);
}

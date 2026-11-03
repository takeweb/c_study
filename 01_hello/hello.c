#include <stdio.h>

int main() {
    //printf("Hello, World\n");
    //char str[] = "Hello, World"; // char配列書き換え可能
    char *str = "Hello, World";    // ポインタ文字列リテラルを指しているだけで、書き換えできない
    printf("文字列:   %s\n", str);
    printf("アドレス: %p\n", (void *)str);
}

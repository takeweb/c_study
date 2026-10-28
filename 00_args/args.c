#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("引数の総数 (argc): %d\n\n", argc);

    for (int i = 0; i < argc; i++) {
        printf("argv[%d] : %s\n", i, argv[i]);
    }

    return 0;
}
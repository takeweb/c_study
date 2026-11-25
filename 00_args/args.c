#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    printf("引数の総数 (argc): %d\n\n", argc);
    if (argc < 2) {
        printf("引数がありません。\n");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < argc; i++) {
        printf("argv[%d] : %s\n", i, argv[i]);
    }

    return EXIT_SUCCESS;
}

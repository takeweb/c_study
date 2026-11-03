/**
 * @file print_binary.c
 * @brief 引数で受け取った数値を2進数で表示する
 *
 * 0〜255 は8桁、256〜65535 は16桁で表示する。
 * 65536 以上、負の数、数値でない引数はエラーメッセージを表示して次の引数へ進む。
 */
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief 数値を2進数で表示する
 *
 * 上位ビットから順に bits 桁ぶん出力し、最後に改行する。
 *
 * @param n    表示する数値
 * @param bits 表示する桁数
 */
void print_binary(unsigned int n, int bits) {
    for (int i = bits - 1; i >= 0; i--) {
        putchar((n >> i) & 1 ? '1' : '0');
    }
    putchar('\n');
}

/**
 * @brief 引数の中で最も長い文字列の長さを返す
 *
 * argv[0]（プログラム名）は対象外。
 *
 * @param argc 引数の数
 * @param argv 引数の配列
 * @return 最も長い引数の文字数（バイト数）
 */
int max_arg_width(int argc, char *argv[]) {
    int width = 0; 
    for (int i = 1; i < argc; i++) {
        int len = (int)strlen(argv[i]);
        if (len > width) {
            width = len;
        }
    }
    return width;
}

/**
 * @brief エントリポイント
 *
 * 使い方: ./print_binary 数値 [数値 ...]
 *
 * 数値は 10進（10）、16進（0x0F）、8進（017）で指定できる。
 * 表示できる範囲は 0〜65535（UINT16_MAX）。
 *
 * @param argc 引数の数
 * @param argv 引数の配列（argv[1] 以降が表示する数値）
 * @retval EXIT_SUCCESS 正常終了
 * @retval EXIT_FAILURE 引数が指定されなかった
 */
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("使い方: %s 数値 [数値 ...]\n", argv[0]);
        return EXIT_FAILURE;
    }

    // 引数の中で最も長い文字列の長さを返す
    int width = max_arg_width(argc, argv);

    for (int i = 1; i < argc; i++) {
        char *end;
        unsigned long n = strtoul(argv[i], &end, 0);
        if (*end != '\0') {
            printf("%s: 数値ではありません\n", argv[i]);
            continue;
        }

        if (n > UINT16_MAX) {
            printf("%s: 16ビットで表示できません (0〜%d)\n", argv[i], UINT16_MAX);
            continue;
        }

        int bits = (n > UINT8_MAX) ? 16 : 8;
        printf("%*s = ", width, argv[i]);
        print_binary((unsigned int)n, bits);
    }
    return EXIT_SUCCESS;
}

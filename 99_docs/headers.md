# C言語 標準ヘッダファイル 一覧

「このMacで」の列は、`#include <○○.h>` だけのプログラムを clang（`-std=c2x`）と gcc-15（`-std=c23`）でコンパイルして確認した結果。
★ は入門でよく使うもの。

## 1. よく使うヘッダ

| ヘッダ | 主な内容 | 代表的な関数・マクロ・型 |
|---|---|---|
| ★ `<stdio.h>` | 入出力 | `printf`, `scanf`, `putchar`, `getchar`, `fopen`, `fclose`, `fgets`, `EOF` |
| ★ `<stdlib.h>` | 汎用ユーティリティ | `malloc`, `free`, `exit`, `atoi`, `strtol`, `rand`, `srand`, `abs`, `qsort` |
| ★ `<string.h>` | 文字列・メモリ操作 | `strlen`, `strcpy`, `strcmp`, `strcat`, `memcpy`, `memset` |
| ★ `<math.h>` | 数学関数 | `sqrt`, `pow`, `sin`, `cos`, `fabs`, `round`, `lround`, `floor`, `ceil` |
| ★ `<ctype.h>` | 文字の種類の判定・変換 | `isdigit`, `isalpha`, `isspace`, `toupper`, `tolower` |
| ★ `<limits.h>` | 整数型の最小値・最大値 | `INT_MAX`, `INT_MIN`, `CHAR_BIT`, `LONG_MAX` |
| ★ `<float.h>` | 浮動小数点型の範囲・精度 | `DBL_MAX`, `DBL_MIN`, `DBL_EPSILON`, `FLT_DIG` |
| ★ `<stdbool.h>` | 真偽値 | `bool`, `true`, `false` |
| ★ `<stdint.h>` | サイズを指定した整数型 | `int32_t`, `uint8_t`, `int64_t`, `INT32_MAX` |
| ★ `<stddef.h>` | 基本的な型・マクロ | `size_t`, `NULL`, `ptrdiff_t`, `offsetof` |
| `<time.h>` | 日付・時刻 | `time`, `clock`, `difftime`, `strftime`, `time_t` |
| `<assert.h>` | 動作確認（アサーション） | `assert` |
| `<errno.h>` | エラー番号 | `errno`, `EINVAL`, `ERANGE` |

## 2. 全標準ヘッダ（規格のバージョン別）

| ヘッダ | 追加された規格 | 主な内容 | このMacで |
|---|---|---|---|
| `<assert.h>` | C89 | アサーション | ○ |
| `<ctype.h>` | C89 | 文字の判定・変換 | ○ |
| `<errno.h>` | C89 | エラー番号 | ○ |
| `<float.h>` | C89 | 浮動小数点型の範囲 | ○ |
| `<limits.h>` | C89 | 整数型の範囲 | ○ |
| `<locale.h>` | C89 | ロケール（地域・言語の設定） | ○ |
| `<math.h>` | C89 | 数学関数 | ○ |
| `<setjmp.h>` | C89 | 関数をまたいだジャンプ（`setjmp` / `longjmp`） | ○ |
| `<signal.h>` | C89 | シグナル処理 | ○ |
| `<stdarg.h>` | C89 | 可変長引数（`va_list`, `va_start`） | ○ |
| `<stddef.h>` | C89 | 基本的な型・マクロ | ○ |
| `<stdio.h>` | C89 | 入出力 | ○ |
| `<stdlib.h>` | C89 | 汎用ユーティリティ | ○ |
| `<string.h>` | C89 | 文字列・メモリ操作 | ○ |
| `<time.h>` | C89 | 日付・時刻 | ○ |
| `<iso646.h>` | C95 | 演算子の別名（`and`, `or`, `not`） | ○ |
| `<wchar.h>` | C95 | ワイド文字（多言語文字）の入出力・文字列 | ○ |
| `<wctype.h>` | C95 | ワイド文字の判定・変換 | ○ |
| `<complex.h>` | C99 | 複素数 | ○ |
| `<fenv.h>` | C99 | 浮動小数点の環境（丸めモードなど） | ○ |
| `<inttypes.h>` | C99 | 固定幅整数の書式マクロ（`PRId64` など） | ○ |
| `<stdbool.h>` | C99 | 真偽値 | ○ |
| `<stdint.h>` | C99 | サイズを指定した整数型 | ○ |
| `<tgmath.h>` | C99 | 型に応じて自動で選ばれる数学関数 | ○ |
| `<stdalign.h>` | C11 | メモリ配置（アラインメント） | ○ |
| `<stdatomic.h>` | C11 | アトミック操作 | ○ |
| `<stdnoreturn.h>` | C11 | 戻らない関数の指定（`noreturn`） | ○ |
| `<threads.h>` | C11 | スレッド | **×**（ファイルがない） |
| `<uchar.h>` | C11 | UTF-16 / UTF-32 文字 | **×**（ファイルがない） |
| `<stdbit.h>` | C23 | ビット操作 | **×**（ファイルがない） |
| `<stdckdint.h>` | C23 | オーバーフローを検出する計算 | ○ |

- × のヘッダは clang・gcc-15 のどちらでも `file not found` / `No such file or directory` になった。
- ヘッダが使えるかどうかは、`%b` と同じく標準ライブラリ（macOS では libSystem）側の対応で決まる部分が大きい。

## 3. 補足

- `#include <○○.h>` の `< >` は標準ライブラリなどシステムのヘッダを探す。自分で作ったヘッダは `#include "myheader.h"` のように `" "` で書く。
- `<math.h>` の関数を使うとき、Linux では `-lm` が必要なことがある（macOS では不要だった）。

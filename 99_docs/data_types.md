# C言語 データ型 一覧

値はすべて macOS（Apple Silicon / arm64）で `<limits.h>` `<float.h>` の定数と `sizeof` を実行して確認したもの。
型のサイズは環境（CPU・OS・コンパイラ）によって変わることがある。

## 1. 整数型

| 型 | サイズ | 最小値 | 最大値 | 定数名（最小 / 最大） | `printf` |
|---|---|---|---|---|---|
| `char` | 1バイト | -128 | 127 | `CHAR_MIN` / `CHAR_MAX` | `%c`, `%d` |
| `signed char` | 1バイト | -128 | 127 | `SCHAR_MIN` / `SCHAR_MAX` | `%hhd` |
| `unsigned char` | 1バイト | 0 | 255 | — / `UCHAR_MAX` | `%hhu` |
| `short` | 2バイト | -32,768 | 32,767 | `SHRT_MIN` / `SHRT_MAX` | `%hd` |
| `unsigned short` | 2バイト | 0 | 65,535 | — / `USHRT_MAX` | `%hu` |
| `int` | 4バイト | -2,147,483,648 | 2,147,483,647 | `INT_MIN` / `INT_MAX` | `%d` |
| `unsigned int` | 4バイト | 0 | 4,294,967,295 | — / `UINT_MAX` | `%u` |
| `long` | 8バイト | -9,223,372,036,854,775,808 | 9,223,372,036,854,775,807 | `LONG_MIN` / `LONG_MAX` | `%ld` |
| `unsigned long` | 8バイト | 0 | 18,446,744,073,709,551,615 | — / `ULONG_MAX` | `%lu` |
| `long long` | 8バイト | -9,223,372,036,854,775,808 | 9,223,372,036,854,775,807 | `LLONG_MIN` / `LLONG_MAX` | `%lld` |
| `unsigned long long` | 8バイト | 0 | 18,446,744,073,709,551,615 | — / `ULLONG_MAX` | `%llu` |

- 1バイトのビット数は `CHAR_BIT`（この環境では 8）。
- `char` に符号があるか（`signed` か `unsigned` か）は環境によって違う。この環境では符号ありだった。
- 符号ありの型は、最小値の絶対値が最大値より1大きい（例：`int` は -2,147,483,648 〜 2,147,483,647）。

## 2. 浮動小数点型

| 型 | サイズ | 正の最小値（正規化数） | 最大値 | 有効桁数（10進） | `printf` |
|---|---|---|---|---|---|
| `float` | 4バイト | 1.175494e-38 | 3.402823e+38 | 6桁 | `%f` |
| `double` | 8バイト | 2.225074e-308 | 1.797693e+308 | 15桁 | `%f` |
| `long double` | 8バイト | 2.225074e-308 | 1.797693e+308 | 15桁 | `%Lf` |

| 型 | 最小値の定数 | 最大値の定数 | 機械イプシロン（1 と次に表せる数の差） | 有効桁数の定数 |
|---|---|---|---|---|
| `float` | `FLT_MIN` | `FLT_MAX` | `FLT_EPSILON` = 1.192093e-07 | `FLT_DIG` |
| `double` | `DBL_MIN` | `DBL_MAX` | `DBL_EPSILON` = 2.220446e-16 | `DBL_DIG` |
| `long double` | `LDBL_MIN` | `LDBL_MAX` | `LDBL_EPSILON` = 2.220446e-16 | `LDBL_DIG` |

- `FLT_MIN` などは「0に一番近い**正**の数（正規化数）」で、マイナス側の最小値ではない。マイナス側の最小値は `-FLT_MAX`。
- 正規化数より小さい数（非正規化数）も表せる。その最小値は `FLT_TRUE_MIN` = 1.401298e-45、`DBL_TRUE_MIN` = 4.940656e-324。
- この環境（Apple Silicon）では `long double` は `double` と同じ8バイトで、範囲も精度も同じだった。
- 有効桁数が `float` は6桁しかないので、計算には普通 `double` を使う。

## 3. その他のよく使う型

| 型 | サイズ | 範囲 | ヘッダ | `printf` |
|---|---|---|---|---|
| `bool` | 1バイト | `false`（0） / `true`（1） | `<stdbool.h>` | `%d` |
| `size_t` | 8バイト | 0 〜 18,446,744,073,709,551,615（`SIZE_MAX`） | `<stddef.h>` | `%zu` |
| ポインタ（`void *` など） | 8バイト | — | — | `%p` |

## 4. 確認に使ったプログラムの例

```c
#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void) {
    printf("int: %zu バイト, %d 〜 %d\n", sizeof(int), INT_MIN, INT_MAX);
    printf("double: %zu バイト, %e 〜 %e\n", sizeof(double), DBL_MIN, DBL_MAX);
    return 0;
}
```

- `sizeof(型)` でその型のバイト数が分かる（結果は `size_t` 型なので `%zu`）。
- 最小値・最大値の定数は、整数型は `<limits.h>`、浮動小数点型は `<float.h>` にある。

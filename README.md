# c_study

C言語の学習用リポジトリです。

## ディレクトリ構成

- `NN_xxx/` … 学習テーマごとのディレクトリ（`.c` ファイルと `Makefile` を置く）
- `99_docs/` … 学習メモ・リファレンス
- `common.mk` … 各ディレクトリの `Makefile` から読み込む共通ビルドルール
- `Makefile` … 全ディレクトリをまとめてビルドするためのトップレベル `Makefile`

## ビルド方法（make）

### 全ディレクトリをまとめてビルド

リポジトリのルートで実行します。`Makefile` を持つすべてのディレクトリがビルドされます。

```sh
make          # 全ディレクトリをビルド
make clean    # 全ディレクトリの実行ファイルを削除
```

特定のディレクトリだけをルートからビルドすることもできます。

```sh
make 01_hello
```

### ディレクトリ単位でビルド

各ディレクトリに移動して実行します。ディレクトリ内の `foo.c` ごとに、同名の実行ファイル `foo` が作られます（`gcc -Wall -Wextra -g foo.c -o foo` 相当）。

```sh
cd 01_hello
make              # hello.c → hello
./hello
make clean        # 実行ファイルと .dSYM を削除
```

`make -C` を使えば、ディレクトリを移動せずに実行できます。

```sh
make -C 01_hello
```

### インストール / アンインストール

`install` / `uninstall` は各ディレクトリで実行します（トップレベルの `Makefile` にはありません）。
デフォルトでは `~/bin` にインストールされます。

```sh
cd 01_hello
make install      # ~/bin/hello にコピー
make uninstall    # ~/bin/hello を削除
```

インストール先は `PREFIX` で変更できます。

```sh
make install PREFIX=/usr/local/bin
```

> **注意:** `02_temperature_while` と `03_temperature_for` はどちらも `temp.c` から `temp` を作るため、両方をインストールすると後からインストールした方で上書きされます。

## 新しいディレクトリを追加するとき

ディレクトリを作り、次の1行だけの `Makefile` を置けば、そのディレクトリ内の `.c` ファイルがビルド対象になります。トップレベルの `make` にも自動で含まれます。

```makefile
include ../common.mk
```

## 補足

- 実行ファイル（拡張子なしのファイル）は `.gitignore` で Git の管理対象外にしています。
- コンパイラやオプションは `common.mk` の `CC` / `CFLAGS` で設定しています。

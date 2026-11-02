# 各ディレクトリの Makefile から include する共通ルール
# foo.c → gcc foo.c -o foo のように、ソースファイル名で実行ファイルを作る

CC      = gcc
CFLAGS  = -Wall -Wextra -g
PREFIX ?= $(HOME)/bin

SRCS    := $(wildcard *.c)
TARGETS := $(SRCS:.c=)

.PHONY: all install uninstall clean

all: $(TARGETS)

%: %.c
	$(CC) $(CFLAGS) $< -o $@

# ~/bin（PREFIX）に実行ファイルをコピーする
install: $(TARGETS)
	install -d $(PREFIX)
	install -m 755 $(TARGETS) $(PREFIX)/

uninstall:
	rm -f $(addprefix $(PREFIX)/,$(TARGETS))

clean:
	rm -f $(TARGETS)
	rm -rf $(addsuffix .dSYM,$(TARGETS))

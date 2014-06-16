CC=gcc
CFLAGS=-Wall -Wextra -pedantic -std=gnu11
LDFLAGS=

all:
	$(CC) $(CFLAGS) $(LDFLAGS) -o ./bin/mntns-exec ./src/mntns-exec.c

.PHONY: all clean

CC=gcc
CFLAGS=-Wall -Wextra -Werror -pedantic -std=gnu11
LDFLAGS=

all: bin ./bin/private-mntns-exec

bin:
	mkdir ./bin/

./bin/private-mntns-exec: ./bin/ctrl-flow.o ./src/private-mntns.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

./bin/ctrl-flow.o: ./src/ctrl-flow.c ./src/ctrl-flow.h
	$(CC) $(CFLAGS) -o $@ -c $<

#./bin/squashed-rootfs-exec: ./src/
#	$(CC) $(CFLAGS) $(LDFLAGS) -lmount -o ./bin/squashed-rootfs-exec \
#    ./src/squashed-rootfs-exec.c

clean:
	rm -rf ./bin/

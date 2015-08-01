.PHONY: all clean

CC=gcc
CFLAGS=-Wall -Wextra -Werror -pedantic -std=gnu11
LDFLAGS=

all: ../bin ../bin/private-mntns-exec

../bin:
	mkdir ../bin/

../bin/private-mntns-exec: \
		ctrl-flow.o \
		private-mntns.o \
		private-mntns-exec.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

private-mntns.o: \
		private-mntns.c \
		private-mntns.h \
		ctrl-flow.h
	$(CC) $(CFLAGS) -o $@ -c $<

ctrl-flow.o: \
		ctrl-flow.c \
		ctrl-flow.h
	$(CC) $(CFLAGS) -o $@ -c $<

#./bin/squashed-rootfs-exec: ./src/
#	$(CC) $(CFLAGS) $(LDFLAGS) -lmount -o ./bin/squashed-rootfs-exec \
#    ./src/squashed-rootfs-exec.c

clean:
	rm -f *.o
	rm -rf ../bin/

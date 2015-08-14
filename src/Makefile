.PHONY: all clean

CC=gcc
CFLAGS=-Wall -Wextra -Werror -pedantic -std=gnu11
LDFLAGS=

all: ../bin \
		../bin/private-mntns \
		../bin/mount-squashfs \
		../bin/pivot-root \
		../bin/init

../bin:
	mkdir ../bin/

../bin/private-mntns: \
		ctrl-flow.o \
		private-mntns.o \
		private-mntns-exec.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

../bin/mount-squashfs: \
		ctrl-flow.o \
		mount-squashfs.o \
		mount-squashfs-exec.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ -lmount

../bin/pivot-root: \
		ctrl-flow.o \
		pivot-root.o \
		pivot-root-exec.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

../bin/init: \
		ctrl-flow.o \
		init.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

private-mntns.o: \
		private-mntns.c \
		private-mntns.h \
		ctrl-flow.h
	$(CC) $(CFLAGS) -o $@ -c $<

mount-squashfs.o: \
		mount-squashfs.c \
		mount-squashfs.h \
		ctrl-flow.h
	$(CC) $(CFLAGS) -o $@ -c $<

pivot-root.o: \
		pivot-root.c \
		pivot-root.h \
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
	rm -f ../bin/*

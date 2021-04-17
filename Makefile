CC=gcc
CFLAGS=-Wall -O2
objs:=$(wildcard *.c)
targets:=$(objs:.c= )

.PHONY:all

all: $(targets)

.c:
	mkdir -p bin
	$(CC) $(CFLAGS) -o bin/$@ $<

install: $(targets)
	mkdir -p ${HOME}/.glue/bin/
	cd bin && install -m 755 $(targets) ${HOME}/.glue/bin/

uninstall:
	rm -f ${HOME}/.glue/bin/*

clean:
	cd bin && rm -f $(targets)

test: $(targets)
	./test/test_all.bash

# ref: https://hamu-tech.hatenadiary.org/entry/20121026/1351232511

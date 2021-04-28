CC=gcc
CFLAGS=-Wall -O2
objs:=$(wildcard *.c)
targets:=$(objs:.c= )

.PHONY:all

all: $(targets)

.c:
	$(CC) $(CFLAGS) -o ../bin/$@ $< 

install: $(targets)
	cd ../bin && install -m 755 $(targets) ${HOME}/.glue/bin/

uninstall:
	rm -f ${HOME}/.glue/bin/*

clean:
	cd ../bin && rm -f $(targets) 

# ref: https://hamu-tech.hatenadiary.org/entry/20121026/1351232511

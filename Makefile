all: switch12

switch12: switch12.c log2.c ignerr.c
	gcc -O3 -o switch12 -Wall switch12.c
	gcc -O3 -o log2 -Wall log2.c
	gcc -O3 -o ignerr -Wall ignerr.c

install: switch12 log2 ignerr
	mkdir -p ~/.glue/bin/
	cp switch12 log2 ignerr ~/.glue/bin/

uninstall: switch12 log2 ignerr
	rm -f ~/.glue/bin/*

clean:
	rm -f switch12 log2 ignerr

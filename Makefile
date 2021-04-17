all: switch12

switch12: switch12.c log2.c ign1.c ign2.c ign12.c ignerr.c
	gcc -O3 -o switch12 -Wall switch12.c
	gcc -O3 -o log2 -Wall log2.c
	gcc -O3 -o ign1 -Wall ign1.c
	gcc -O3 -o ign2 -Wall ign2.c
	gcc -O3 -o ign12 -Wall ign12.c
	gcc -O3 -o ignerr -Wall ignerr.c

install: switch12 log2 ign1 ign2 ign12 ignerr
	mkdir -p ${HOME}/.glue/bin/
	install -m 755 switch12 log2 ign1 ign2 ign12 ignerr ${HOME}/.glue/bin/

uninstall: switch12 log2 ign1 ign2 ign12 ignerr
	rm -f ${HOME}/.glue/bin/*

clean:
	rm -f switch12 log2 ign1 ign2 ign12 ignerr

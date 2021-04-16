all: switch12

switch12: switch12.c log2.c
	gcc -O3 -o switch12 -Wall switch12.c
	gcc -O3 -o log2 -Wall log2.c

clean:
	rm -f switch12 log2

install: switch12 
	mkdir -p /usr/local/bin/glueutils/
	cp switch12 log2 /usr/local/bin/glueutils/

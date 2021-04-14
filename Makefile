all: switch12

switch12: switch12.c
	gcc -O3 -o switch12 -Wall switch12.c

clean:
	rm -f switch12

install: switch12 
	mkdir -p /usr/local/bin/glueutils/
	cp switch12 /usr/local/bin/glueutils/

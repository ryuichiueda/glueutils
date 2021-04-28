CFLAGS=-Wall -O2

.PHONY:all

all: 
	gcc $(CFLAGS) -o ../bin/con12 con12.c -lpthread
	g++ $(CFLAGS) -o ../bin/con12safe con12safe.cpp -lpthread

install: all
	cd ../bin && install -m 755 con12 ${HOME}/.glue/bin/
	cd ../bin && install -m 755 con12safe ${HOME}/.glue/bin/

uninstall:
	rm -f ${HOME}/.glue/bin/con12*

clean:
	cd ../bin && rm -f con12 con12safe

all:
	mkdir -p bin
	$(MAKE) -C src
	$(MAKE) -C src_con12

clean:
	$(MAKE) clean -C src_con12
	$(MAKE) clean -C src
	rmdir -p bin

test: all
	./test/test_all.bash

install:
	mkdir -p bin
	mkdir -p ${HOME}/.glue/bin/
	$(MAKE) install -C src
	$(MAKE) install -C src_con12

uninstall:
	rm -f ~/.glue/bin/*

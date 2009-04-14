# $Id$
#
# This Makefile is a temporary solution.
#
# Say "make", and you will find "redfront" in the subdirectory
# corresponding to your lisp and architecture.
#
# 03/2009 - T. Sturm (sturm@redlog.eu)

BUILD = $(shell ../../scripts/findhost.sh $(shell src/config.guess))
LIBEDIT_TGZ = libedit-20090111-3.0.tar.gz

LIBEDIT = $(shell basename $(LIBEDIT_TGZ) .tar.gz)
LIBEDIT_BUILD = $(LIBEDIT)/$(BUILD)

.PHONY: all csl psl install install-csl install-psl uninstall uninstall-csl \
	uninstall-psl clean distclean maintainer-clean echo

all: csl psl

csl: libedit/$(BUILD)/include/editline/readline.h
	cd src; \
	autoconf; \
	autoheader
	mkdir -p csl/$(BUILD); \
	cd csl/$(BUILD); \
	../../src/configure --with-csl; \
	make

psl: libedit/$(BUILD)/include/editline/readline.h
	cd src; \
	autoconf; \
	autoheader
	mkdir -p psl/$(BUILD); \
	cd psl/$(BUILD); \
	../../src/configure --with-psl; \
	make

libedit/$(BUILD)/include/editline/readline.h: 
	tar xvf ../../libedit/$(LIBEDIT_TGZ)
	ln -sf $(LIBEDIT) libedit
	mkdir -p $(LIBEDIT_BUILD)
	cd $(LIBEDIT_BUILD); \
	../configure --prefix=$$(pwd) --disable-dependency-tracking; \
	make install

install: install-csl install-psl

install-csl: csl
	@cd ../../bin && \
	if test ! -e rfcsl; then \
	   echo "Creating symbolic link ../../bin/rfcsl"; \
	   ln -s ../generic/redfront/csl/$(BUILD)/redfront rfcsl; \
	else \
	   echo "File ../../bin/rfcsl already exists"; \
	fi

install-psl: psl
	@cd ../../bin && \
	if test ! -e rfpsl; then \
	   echo "Creating symbolic link ../../bin/rfpsl"; \
	   ln -s ../generic/redfront/psl/$(BUILD)/redfront rfpsl; \
	else \
	   echo "File ../../bin/rfpsl already exists"; \
	fi

uninstall: uninstall-csl uninstall-psl

uninstall-csl:
	@cd ../../bin && \
	if test ! -e rfcsl; then \
	   echo "File ../../bin/rfcsl does not exist"; \
	elif test ! -h rfcsl; then \
	   echo "File ../../bin/rfcsl is not a symbolic link"; \
	else \
	   echo "Deleting symbolic link ../../bin/rfcsl"; \
	   rm -f rfcsl; \
	fi

uninstall-psl:
	@cd ../../bin && \
	if test ! -e rfpsl; then \
	   echo "File ../../bin/rfpsl does not exist"; \
	elif test ! -h rfpsl; then \
	   echo "File ../../bin/rfpsl is not a symbolic link"; \
	else \
	   echo "Deleting symbolic link ../../bin/rfpsl"; \
	   rm -f rfpsl; \
	fi

clean:
	cd csl/$(BUILD) && make clean
	cd psl/$(BUILD) && make clean

distclean:
	/bin/rm -rf csl psl libedit*
	cd ../../bin && rm -f rfcsl rfpsl

maintainer-clean: distclean
	cd src && make -f Makefile.in maintainer-clean

echo:
	@echo $(LIBEDIT_BUILD)

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

clean:
	cd csl/$(BUILD) && make clean
	cd psl/$(BUILD) && make clean

distclean:
	/bin/rm -rf csl psl libedit*

maintainer-clean: distclean
	cd src && make -f Makefile.in maintainer-clean

echo:
	@echo $(LIBEDIT_BUILD)

# $Id$
#
# This Makefile is a temporary solution.
#
# Say "make", and you will find "redfront" in the subdirectory
# corresponding to your lisp and architecture.
#
# 03/2009 - T. Sturm (sturm@redlog.eu)

BUILD = $(shell ../../scripts/findhost.sh $(shell src/config.guess))

all: csl psl

csl:
	cd src; \
	autoconf; \
	autoheader
	mkdir -p csl/$(BUILD); \
	cd csl/$(BUILD); \
	LDFLAGS="-L/sw/lib" CFLAGS="-I/sw/include" ../../src/configure --with-csl --enable-readline; \
	make

psl:
	cd src; \
	autoconf; \
	autoheader
	mkdir -p psl/$(BUILD); \
	cd psl/$(BUILD); \
	LDFLAGS="-L/sw/lib" CFLAGS="-I/sw/include" ../../src/configure --with-psl --enable-readline; \
	make

clean:
	cd csl/$(BUILD) && make clean
	cd psl/$(BUILD) && make clean

distclean:
	/bin/rm -rf csl psl

maintainer-clean: distclean
	cd src && make -f Makefile.in maintainer-clean

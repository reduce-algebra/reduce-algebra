# $Id$
#
# This Makefile is a temporary solution.
#
# As a quick start just go "make install" and find rfcsl and rfpsl in trunk/bin.
# 
# Usage Details:
#
# make csl:              build redfront for csl. The binary will be located
#                        under csl/ in the directory corresponding to your
#                        architecture
#
# make psl:              build redfront for psl. The binary will be located
#                        under psl/ in the directory corresponding to your
#                        architecture
#
# make =                 make csl psl
#
# make install-csl:      create a suitable symbolic link rfcsl in trunk/bin
#
# make install-psl:      create a suitable symbolic link rfpsl in trunk/bin
#
# make install =         make install-csl install-psl
#
# make uninstall:        remove symbolic links rfcsl and rfpsl from trunk/bin
#
# make maintainer-clean: reset this directory to its original state. This
#                        includes uninstalling and deleting all files generated
#                        by make all.
#
# Reports bugs and problems to the Reduce Help Forum at SourceForge:
# http://sourceforge.net/forum/forum.php?forum_id=899364
# T. Sturm (sturm@redlog.eu)

BUILD = $(shell ../../scripts/findhost.sh $(shell src/config.guess))
LIBEDIT_TGZ = libedit-20090111-3.0.tar.gz

LIBEDIT = $(shell basename $(LIBEDIT_TGZ) .tar.gz)
LIBEDIT_BUILD = $(LIBEDIT)/$(BUILD)

.PHONY: all csl psl install install-csl install-psl uninstall uninstall-csl \
	uninstall-psl clean distclean maintainer-clean echo

all: csl psl

csl: csl/$(BUILD)/redfront

csl/$(BUILD)/redfront: libedit/$(BUILD)/include/editline/readline.h 
	cd src; \
	autoconf; \
	autoheader
	mkdir -p csl/$(BUILD); \
	cd csl/$(BUILD); \
	../../src/configure --with-csl; \
	make

psl: psl/$(BUILD)/redfront

psl/$(BUILD)/redfront: libedit/$(BUILD)/include/editline/readline.h
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
	if test ! -e rfcsl -a ! -h rfcsl; then \
	   echo "Creating symbolic link ../../bin/rfcsl"; \
	   ln -s ../generic/redfront/csl/$(BUILD)/redfront rfcsl; \
	else \
	   echo "File ../../bin/rfcsl already exists"; \
	fi

install-psl: psl
	@cd ../../bin && \
	if test ! -e rfpsl -a ! -h rfpsl ; then \
	   echo "Creating symbolic link ../../bin/rfpsl"; \
	   ln -s ../generic/redfront/psl/$(BUILD)/redfront rfpsl; \
	else \
	   echo "File ../../bin/rfpsl already exists"; \
	fi

uninstall: uninstall-csl uninstall-psl

uninstall-csl:
	@cd ../../bin && \
	if test ! -h rfcsl; then \
	   echo "No symbolic link ../../bin/rfcsl found"; \
	else \
	   echo "Deleting symbolic link ../../bin/rfcsl"; \
	   rm -f rfcsl; \
	fi

uninstall-psl:
	@cd ../../bin && \
	if test ! -h rfpsl; then \
	   echo "No symbolic link ../../bin/rfpsl found"; \
	else \
	   echo "Deleting symbolic link ../../bin/rfpsl"; \
	   rm -f rfpsl; \
	fi

clean:
	cd csl/$(BUILD) && make clean
	cd psl/$(BUILD) && make clean

distclean: uninstall
	/bin/rm -rf csl psl libedit*
	cd ../../bin && rm -f rfcsl rfpsl

maintainer-clean: distclean
	cd src && make -f Makefile.in maintainer-clean

echo:
	@echo $(LIBEDIT_BUILD)

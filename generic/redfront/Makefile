# $Id$
#
# This Makefile is a temporary solution.
#
# As a quick start just go "make install" and find rfcsl and rfpsl in
# trunk/bin.
#
# Usage Details:
#
# make =                 make redfront. The binary will be located in the
#                        redfront subdirectory of the directory corresponding
#                        to your architecture
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

#LIBEDIT_TGZ = libedit-20130712-3.1.tar.gz
LIBEDIT_TGZ = libedit-20140620-3.1.tar.gz
LIBEDIT = $(shell basename $(LIBEDIT_TGZ) .tar.gz)
BUILD_LIBEDIT = $(BUILD)/libedit

.PHONY: all csl psl install install-csl install-psl uninstall uninstall-csl \
	uninstall-psl clean distclean maintainer-clean echo

all: $(BUILD)/redfront/redfront

debug: $(BUILD)/redfront-debug/redfront

src/configure:
	cd src; \
	autoconf; \
	autoheader

$(BUILD)/redfront/redfront: $(BUILD)/libedit/include/editline/readline.h src/configure
	mkdir -p $(BUILD)/redfront; \
	cd $(BUILD)/redfront; \
	../../src/configure --with-libedit=$(abspath $(BUILD)/libedit); \
	make

$(BUILD)/redfront-debug/redfront: $(BUILD)/libedit/include/editline/readline.h src/configure
	mkdir -p $(BUILD)/redfront-debug; \
	cd $(BUILD)/redfront-debug; \
	../../src/configure --with-libedit=$(abspath $(BUILD)/libedit) --enable-debug; \
	make

$(LIBEDIT):
	tar xvf ../../libedit/$(LIBEDIT_TGZ)
#ln -sf $(LIBEDIT) libedit

$(BUILD)/libedit/include/editline/readline.h: $(LIBEDIT)
	mkdir -p $(BUILD_LIBEDIT)
	cd $(BUILD_LIBEDIT); \
	../../$(LIBEDIT)/configure --prefix=$$(pwd) --disable-dependency-tracking; \
	make install

install-home-bin: install-home-bin-csl install-home-bin-psl

install-home-bin-csl:
	@if test ! -e ~/bin/rfcsl -a ! -h ~/bin/rfcsl; then \
	   echo "Copying to ~/bin/rfcsl"; \
	   cp $(BUILD)/redfront/redfront ~/bin/rfcsl; \
	else \
	   echo "File ~/bin/rfcsl already exists"; \
	fi

install-home-bin-psl:
	@if test ! -e ~/bin/rfpsl -a ! -h ~/bin/rfpsl; then \
	   echo "Copying to ~/bin/rfpsl"; \
	   cp $(BUILD)/redfront/redfront ~/bin/rfpsl; \
	else \
	   echo "File ~/bin/rfpsl already exists"; \
	fi

install: install-csl install-psl

install-csl: $(BUILD)/redfront/redfront
	@cd ../../bin && \
	if test ! -e rfcsl -a ! -h rfcsl; then \
	   echo "Creating symbolic link ../../bin/rfcsl"; \
	   ln -s ../generic/redfront/$(BUILD)/redfront/redfront rfcsl; \
	else \
	   echo "File ../../bin/rfcsl already exists"; \
	fi

install-psl: $(BUILD)/redfront/redfront
	@cd ../../bin && \
	if test ! -e rfpsl -a ! -h rfpsl ; then \
	   echo "Creating symbolic link ../../bin/rfpsl"; \
	   ln -s ../generic/redfront/$(BUILD)/redfront/redfront rfpsl; \
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
	cd $(BUILD)/libedit && make clean
	cd $(BUILD)/redfront && make clean

distclean: uninstall
	/bin/rm -rf $(BUILD) csl psl libedit*
	cd ../../bin && rm -f rfcsl rfpsl

maintainer-clean: distclean
	cd src && make -f Makefile.in maintainer-clean

echo:
	@echo $(BUILD)

# Makefile for getting readt to make Windows installer package


# This version makes a "fat" binary for CSl.

all:	configure-all build-all package-win

configure-all:	clean-tree/configure configure-psl

clean-tree/configure:
	rm -rf clean-tree
	svn export .. clean-tree

build-all:	clean-tree/configure build-csl build-psl build-docs

package-win:	clean-tree/configure reduce.iss
	clean-tree/psl/saveimage.sh clean-tree/pslbuild/x86_64-pc-windows  $(abspath .) '$$reduce/lib/psl' && mv reduce.img reduce64.img
	clean-tree/psl/saveimage.sh clean-tree/pslbuild/i686-pc-windows $(abspath .) '$$reduce/lib/psl'
	@echo Please run Innosetup on winbuild/reduce.iss

configure-psl:	clean-tree/configure
	(cd clean-tree ; ./configure --with-psl ; ./configure --with-psl -with-m32)

build-csl:	clean-tree/configure
	./cslbuild.sh

build-psl:	clean-tree/configure
	make -C clean-tree psl

build-docs:	clean-tree/configure
	(cd clean-tree/doc/misc ; make)
	(cd clean-tree/doc/manual ; make)
	
reduce.iss:	reduce.iss.in
	sed -e 's#\@here\@#$(subst /,\\,$(shell cygpath -m $(abspath .)))#;s#\@srcdir\@#$(subst /,\\,$(shell cygpath -m $(abspath ./clean-tree)))#;s#\@build\@#i686-pc-windows#;s#\@build64\@#x86_64-pc-windows#' <reduce.iss.in >reduce.iss

clean:
	rm -rf *red*.exe *.img clean-tree cslwin32 cslwin64 cslcyg32 cslcyg64 \
		cslbuild log reduce.iss Output

# end of Makefile

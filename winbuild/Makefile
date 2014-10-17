# Makefile for getting readt to make Windows installer package


# This version makes a "fat" binary for CSl.

all:	configure-all build-all package-win

configure-all:	configure-psl

build-all:	build-csl build-psl build-docs

package-win:	reduce.iss
	../psl/saveimage.sh ../pslbuild/x86_64-pc-windows  $(abspath .) '$$reduce/lib/psl' && mv reduce.img reduce64.img
	../psl/saveimage.sh ../pslbuild/i686-pc-windows $(abspath .) '$$reduce/lib/psl'
	@echo Please run Innosetup on winbuild/reduce.iss

configure-psl:
	(cd .. ; ./configure --with-psl ; ./configure --with-psl -with-m32)

build-csl:
	./cslbuild.sh

build-psl:
	make -C .. psl

build-docs:
	(cd ../doc/misc ; make)
	(cd ../doc/manual ; make)
	
reduce.iss:	reduce.iss.in
	sed -e 's#\@here\@#$(subst /,\\,$(shell cygpath -m $(abspath .)))#;s#\@srcdir\@#$(subst /,\\,$(shell cygpath -m $(abspath ..)))#;s#\@build\@#i686-pc-windows#;s#\@build64\@#x86_64-pc-windows#' <reduce.iss.in >reduce.iss

# end of Makefile

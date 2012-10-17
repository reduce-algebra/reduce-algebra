
all:	configure-all build-all package-win

configure-all:	configure-csl configure-psl

build-all:	build-csl build-psl build-docs

package-win:	configure-csl reduce.iss
	../psl/saveimage.sh ../pslbuild/i686-pc-windows $(abspath .) '$reduce/lib/psl'
	@echo Please run Innosetup on winbuild/reduce.iss

configure-csl:
	(cd .. ; ./configure --with-csl )

configure-psl:
	(cd .. ; ./configure --with-psl )

build-csl:
	make -C .. csl

build-psl:
	make -C .. psl

build-docs:
	(cd ../doc/misc ; make)
	(cd ../doc/manual ; make)
	
reduce.iss:	reduce.iss.in
	sed -e 's#\@srcdir\@#$(shell cygpath -m $(abspath ..))#;s#\@build\@#i686-pc-windows#' <reduce.iss.in >reduce.iss

# end of Makefile

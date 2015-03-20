# Makefile for the C-coded interface between Reduce and Cuba.

# Cuba is fetched and unpacked.

all: libredcuba.so cuba.pdf

# The sequence of operations here is:
# (1) Set the installation path for Cuba to a sub-directory of the current location.
# (2) Fetch a copy of the Cuba sources from http://www.feynarts.de.
#     From time to time it could make sense to review this web address and the
#     version number:

cuba_ver = Cuba-4.1
# This was valid in March 2015.


# (3) Get rid of any previously unpacked copy of Cuba and unpack the new version.
# The current Cuba code has been observed building using various versions
# of clang and versions of gcc from release 4.6.x onwards. gcc 4.5.x and
# earlier will not suffice. The builds have been tested on FreeBSD 10,
# sample released of Fedora and Ubuntu, or a Macintosh (Yosemite) and using
# both 32 and 64-bit Cygwin compilers on Windows. Cuba will not build for
# native Windows (eg using i686-w64-ming32-gcc or the x86_64 equivalent)
# because the code uses fork() which is not available there - and even
# thought its configure script checks for the availability of fork() the
# code does not fall back to sequential code when it is not available.
# Note that Cuba uses features from the 2011 C standard that are supported
# from before somewhat 2011 by gcc if "-std=c99" is set, and in particular
# by some versions of gcc that support "-std=c99" but reject "-std=c11".
# Also, despite use of autoconf to direct the building of Cuba-4.1 it
# appears to be necessary to force -fPIC into CFLAGS in order that the
# library that is built is usable for the purposes needed here.
# (4) Configure it, specifying the location to be used for installation, but
#     trusting the Cuba developers and maintainers regarding all other choices.
# (5) Compile and move the resulting libraries to the right place. Note that
#     to build Cuba requires the GNU version of "make" since its own Makefile
#     is not compatible with the older style make utility present on some BSD
#     systems.
# (6) Clean up: remove the fetched and the unpacked copies of the source and
#     build files.





build_cuba cuba/lib/libcuba.a:
	wget http://www.feynarts.de/cuba/$(cuba_ver).tar.gz && \
	CUBA=`pwd`/cuba	 && \
	rm -rf $(CUBA) && \
	tar xzf $(cuba_ver).tar.gz && \
	cd $(cuba_ver) && \
	case `uname -a` in \
	*Linux* | *linux* )  \
	CC="gcc" ; CXX="g++" ; CFLAGS="-O3 -fPIC" ; mk="$(MAKE)" ; ;; \
	*Cygwin* | *CYGWIN* | *cygwin*) \
	CC="gcc" ; CXX="g++" ; CFLAGS="-O3" ; mk="$(MAKE)" ; ;; \
	*Darwin* | *darwin*) \
	CC="clang" ; CXX="clang++" ; CFLAGS="-O3 -fPIC" ; mk="$(MAKE)" ; ;; \
	*BSD* | *bsd*) \
	CC="clang" ; CXX="clang++" ; CFLAGS="-O3 -fPIC" ; mk="gmake" ; ;; \
	*) \
	printf "Unknown machine: please update the Makefile\n" ; \
	exit 1 ; ;; \
	esac && \
	./configure --prefix="$$CUBA" CC="$$CC" CFLAGS="$$CFLAGS" CXX="$$CXX" && \
	$$mk install && \
	cd .. && \
	rm -rf $(cuba_ver) $(cuba_ver).tar.gz


# The next sequence will build the code that interfaces between Cuba and
# Reduce. Because this package as whole does not use autoconf and because
# the C compiler and flags differ from platform to platform, there is some
# slighly ugly scripting here to set things up. This uses "uname -a" to
# identify the host and then has a case statement to select a compiler and
# some flags. This is intended to cover the most common cases - it detects
# Linux, BSD, OSX and Cygwin. Anybody using a different platform should
# investigate what options can support them and might then submit an
# update.
# 
# It is probable that the code here is not very fussy about what compiler is
# used so mostly the choice being made here is between gcc and clang.

libredcuba.so: redcuba.c C_call_CSL.h cuba/lib/libcuba.a
	CUBA=`pwd`/cuba	 && \
	case `uname -a` in \
	*Linux* | *linux* )  \
	CC="gcc" ; CFLAGS="-O3 -fPIC"; ;; \
	*Cygwin* | *CYGWIN* | *cygwin*) \
	CC="gcc" ; CFLAGS="-O3"; ;; \
	*BSD* | *bsd* | *Darwin* | *darwin*) \
	CC="clang" ; CFLAGS="-O3 -fPIC"; ;; \
	*) \
	printf "Unknown machine: please update the Makefile\n" ; \
	exit 1 ; ;; \
	esac && \
	$$CC $$CFLAGS -I $$CUBA/include -c redcuba.c && \
	$$CC -shared -o libredcuba.so redcuba.o -L $$CUBA/lib -lcuba && \
	rm redcuba.o  && rm -rf $$CUBA

cuba.pdf:	cuba.tex
	pdflatex cuba.tex
	pdflatex cuba.tex

# Remove built files etc. Leave cuba.pdf since it is the main
# readable documentation.

clean:
	rm -rf cuba cuba.out Cuba* *.o *.so *.log *.aux

# end of Makefile

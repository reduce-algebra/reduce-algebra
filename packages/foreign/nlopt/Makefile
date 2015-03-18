# Makefile for the C-coded interface between Reduce and NLopt.

# NLopt is fetched and unpacked

all: librednlopt.so

# The sequence of operations here is:
# (1) Set the installation path for NLopt to a sub-directory of the current location.
# (2) Fetch a copy of the NLopt sources from http://ab-initio.mit.edu/nlopt/.
#     From time to time it could make sense to review this web address and the
#     version number:

nlopt_ver = nlopt-2.4.2
# This was valid in March 2015.

# (3) Get rid of any previously unpacked copy of NLopt and unpack the new version.
# (4) Configure it, specifying the location to be used for installation, but
#     trusting the NLopt developers and maintainers regarding all other choices.
# (5) Compile and move the resulting libraries to the right place. Note that
#     to build NLopt requires the GNU version of "make" since its own Makefile
#     is not compatible with the older style make utility present on some BSD systems.
# (6) Clean up: remove the fetched and the unpacked copies of the source and
#     build files.

.PHANTOM:	build_nlopt

build_nlopt nlopt/lib/libnlopt.so:
	NLOPT=`pwd`/nlopt && \
	wget http://ab-initio.mit.edu/nlopt/$(nlopt_ver).tar.gz && \
	rm -rf $(nlopt_ver) && \
	tar xzf $(nlopt_ver).tar.gz && \
	cd $(nlopt_ver) && \
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
	./configure --prefix="$$NLOPT" --enable-shared \
		CC="$$CC" CFLAGS="$$CFLAGS" CXX="$$CXX" && \
	$$mk install && \
	cd .. && \
	rm -rf $(nlopt_ver) $(nlopt_ver).tar.gz


NLOPT = ./nlopt

# The next sequence will build the code that interfaces between NLopt and
# Reduce.  Because this package as whole does not use autoconf and because
# the C compiler and flags differ from platform to platform, there is some
# slighly ugly scripting here to set things up. This uses "uname -a" to
# identify the host and then has a case statement to select a compiler and
# some flags. This is intended to cover the most common cases - it detects
# Linux, BSD, OSX and Cygwin. Anybody using a different platform should
# investigate what options can support them and might then submit an
# update.
# 
# It is probable that the code here is not very fussy about what compiler is
# used so mostly the choice being made here is between gcc and clang. It will be
# important that the module created is compatible with the Reduce binary you use
# and the command here depends on an option of the form "-Wl,-rpath..." being
# accepted while linking the code.


librednlopt.so: rednlopt.c C_call_CSL.h nlopt/lib/libnlopt.so
	case `uname -a` in \
	*Linux* | *linux* )  \
	CC="gcc" ; CFLAGS="-O3 -fPIC -std=c99"; ;; \
	*Cygwin* | *CYGWIN* | *cygwin*) \
	CC="gcc" ; CFLAGS="-O3 -std=c99"; ;; \
	*BSD* | *bsd* | *Darwin* | *darwin*) \
	CC="clang" ; CFLAGS="-O3 -fPIC"; ;; \
	*) \
	printf "Unknown machine: please update the Makefile\n" ; \
	exit 1 ; ;; \
	esac && \
	$$CC $$CFLAGS -I $(NLOPT)/include -c rednlopt.c && \
	$$CC -shared -o librednlopt.so rednlopt.o -Wl,-rpath,$(NLOPT)/lib \
		-L $(NLOPT)/lib -lnlopt && \
	rm rednlopt.o

nlopt.pdf:	nlopt.tex
	pdflatex nlopt.tex
	pdflatex nlopt.tex

# Remove built files etc. Leave nlopt.pdf since it is the main
# readable documentation.

clean:
	rm -rf nlopt.out *.o *.so  *.log *.aux

# end of Makefile

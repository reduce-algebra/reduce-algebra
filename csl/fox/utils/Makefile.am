## Process this file with automake to produce Makefile.in

## MODIFIED BY A C NORMAN, 2008 to compile using gcc sometimes. This
## comment is here because LGPL obliges me to mark any file that is
## altered with a prominent notice.


AM_CXXFLAGS = @CXXFLAGS@ @X_CFLAGS@

LIBS=

bin_PROGRAMS	= reswrap

man_MANS        = reswrap.1

reswrap_SOURCES	= reswrap.cpp

if cygwinshell
# If I am running under the cygwin shell then file-paths created
# by and for "make" can be cygwin-style ones. In particular they may
# include cygwin links and "/cygdrive/x" drive specifications. For these
# to be processed properly it is vital that reswrap be compiled using the
# native cygwin tool-chain, and that in particular it must not use
# i686-w64-mingw-gcc etc in ways that could create a native
# windows-mode binary. So I will have defined the conditional "cygwinshell"
# when I am building for mingw-style Windows.

reswrap$(EXEEXT):	reswrap.cpp
	g++ $(srcdir)/reswrap.cpp -o reswrap.exe


else !cygwinshell
if !canrun
# Since reswrap must run on the computer I am compiling on I must take
# care if cross compiling NOT to built it using the cross compiler!

reswrap$(EXEEXT):	reswrap.cpp
	g++ $(srcdir)/reswrap.cpp -o reswrap$(EXEEXT)

endif !canrun
endif !cygwinshell

EXTRA_DIST      = $(man_MANS) \
                  maketree \
                  Makefile.bc \
                  Makefile.wc \
                  Makefile.dmc

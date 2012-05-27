## Process this file with automake to produce Makefile.in

## MODIFIED BY A C NORMAN, 2008 to compile using gcc sometimes. This
## comment is only here because LGPL obliges me to mark any file that is
## altered with a prominent notice. Somehow the GPL/LGPL people could be
## amazingly uptight at the stage that the original BSD license has an
## "obnoxious advertising clause" while not minding that they oblige me
## to incorporate something rather similar here!



AM_CXXFLAGS = @CXXFLAGS@ @X_CFLAGS@

LIBS=

bin_PROGRAMS = reswrap

reswrap_SOURCES = reswrap.cpp

man_MANS        = reswrap.1

if cygwinshell
# If I am running under the cygwin shell then file-paths created
# by and for "make" can be cygwin-style ones. In particular they may
# include cygwin links and "/cygdrive/x" drive specifications. For these
# to be processed properly it is vital that reswrap be compiled using the
# native cygwin tool-chain, and that in particular it must not use
# -mno-cygwin.

reswrap$(EXEEXT):	reswrap.cpp
	g++ $(srcdir)/reswrap.cpp -o reswrap.exe


else
if !canrun
# Since reswrap must run on the computer I am compiling on I must take
# care if cross ocmpiling NOT to built it using the cross compiler!

reswrap$(EXEEXT):	reswrap.cpp
	g++ $(srcdir)/reswrap.cpp -o reswrap$(EXEEXT)

endif
endif

EXTRA_DIST      = $(man_MANS) \
		maketree \
		Makefile.bc \
		Makefile.wc \
		Makefile.dmc

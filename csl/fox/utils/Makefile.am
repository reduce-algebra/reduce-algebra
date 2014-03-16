## Process this file with automake to produce Makefile.in

## MODIFIED BY A C NORMAN, 2008 to compile using gcc sometimes. This
## comment is here because LGPL obliges me to mark any file that is
## altered with a prominent notice.

# This segment added by Arthur Norman in a messy attempt to reduce
# trouble with autoconf and friend.

# The standard arrangment used by automake arranges to re-run aclocal,
# autoconf and automake if any of the files they generate are out of date.
# However proper behaviour there not only relies on autoconf being installed
# but sometimes on the correct version being installed. The replacement
# logic here deals with that by running my own script "autogen.sh"
# when anything needs updating. That will reconfigure using whatever
# version of autoconf is available locally, and if none is it will
# just use "touch" to reset time-stamps on files so that the ordering
# appears reasonable.

# The rules here are arranged to chain so that configure is only
# considered after aclocal.m4 has been dealt with and Makefile.in only after
# that. This is trying to follow the guidance given re "Multiple Outputs"
# in the automake manual so that even when a parallel make is used
# autogen.sh will only end up called once. However I found that (for
# reasons I do not understand so far) there was a tendancy for autogen.sh
# to get called twice. I have put what I think ought to be redundant extra
# code that  means that whena recipe is called it does a further check
# to see if it is actually needed, and that sorts things out. It may be that
# the issues I observed are to do with the very special treatment that
# make gives to the re-creation of Makefile and the files that it is
# derived from.

$(ACLOCAL_M4):  $(am__aclocal_m4_deps)
	@if test $(ACLOCAL_M4) -ot $(top_srcdir)/configure.ac; \
	then \
	  $(top_srcdir)/../../autogen.sh csl/fox ; \
	else echo Redundant attempt to remake $(ACLOCAL_M4) ; \
	fi

$(top_srcdir)/configure:  $(am__configure_deps) $(ACLOCAL_M4)
	@if test $(top_srcdir)/configure -ot $(top_srcdir)/configure.ac || \
	   test $(top_srcdir)/configure -ot $(ACLOCAL_M4) ; \
	then \
	  $(top_srcdir)/../../autogen.sh csl/fox ; \
	else echo Redundant attempt to remake configure ; \
	fi

$(srcdir)/Makefile.in:  $(srcdir)/Makefile.am  $(am__configure_deps) \
		$(top_srcdir)/configure
	@if test $(srcdir)/Makefile.in -ot $(top_srcdir)/configure.ac || \
	   test $(srcdir)/Makefile.in -ot $(ACLOCAL_M4) || \
	   test $(srcdir)/Makefile.in -ot $(top_srcdir)/configure || \
	   test $(srcdir)/Makefile.in -ot $(srcdir)/Makefile.am ; \
	then \
	  $(top_srcdir)/../../autogen.sh csl/fox ; \
	else echo Redundant attempt to remake Makefile.in ; \
	fi



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

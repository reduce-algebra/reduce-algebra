## Process this file with automake to produce Makefile.in

# The "testprogram" here is merely part ofa framework to check that
# a reasonably full set of development resources are available for
# building the CSL version of Reduce.

ACLOCAL_AMFLAGS = -I m4

lib_LTLIBRARIES = libwindow.la
libwindow_la_SOURCES = window.c

noinst_PROGRAMS = testprogram
testprogram_SOURCES = testprogram.c
testprogram_LDADD = libwindow.la

# Now some extra dependencies to keep the autoconf stuff up to
# date.

$(srcdir)/autogen.stamp:
	$(SHELL) $(srcdir)/autogen.sh

$(srcdir)/Makefile.in $(srcdir)/config.h.in:	$(srcdir)/autogen.sh

# end of Makefile.am



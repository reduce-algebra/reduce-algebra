## Process this file with automake to produce Makefile.in

# The "testprogram" here is merely part ofa framework to check that
# a reasonably full set of development resources are available for
# building the CSL version of Reduce.


lib_LIBRARIES = libwindow.a
libwindow_a_SOURCES = window.c

noinst_PROGRAMS = testprogram
testprogram_SOURCES = testprogram.c
testprogram_LDADD = libwindow.a

# Now some extra dependencies to keep the autoconf stuff up to
# date.

$(srcdir)/autogen.stamp:	$(srcdir)/autogen.sh $(srcdir)/configure.ac \
				$(srcdir)/Makefile.am
	$(SHELL) $(srcdir)/autogen.sh

$(srcdir)/Makefile.in \
 $(srcdir)/config.h.in \
 $(srcdir)/configure:	$(srcdir)/autogen.stamp

# end of Makefile.am



## Process this file with automake to produce Makefile.in

lib_LIBRARIES = libcrlibm.a

# shared libraries need libtool. We'll do it later.
#lib_LTLIBRARIES = libcrlibm.la

# I want to be able to see what gets built and why, so here is a GNU
# make trace facility.

TRACE = $(warning TRACE: $@ :: $?)

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
	@$(TRACE)if test $(ACLOCAL_M4) -ot $(top_srcdir)/configure.ac; \
	then \
	  $(top_srcdir)/../../../autogen.sh csl/cslbase/crlibm ; \
	else echo Redundant attempt to remake $(ACLOCAL_M4) ; \
	fi

$(top_srcdir)/configure:  $(am__configure_deps) $(ACLOCAL_M4)
	@$(TRACE)if test $(top_srcdir)/configure -ot $(top_srcdir)/configure.ac || \
	   test $(top_srcdir)/configure -ot $(ACLOCAL_M4) ; \
	then \
	  $(top_srcdir)/../../../autogen.sh csl/cslbase/crlibm ; \
	else echo Redundant attempt to remake configure ; \
	fi

$(srcdir)/Makefile.in:  $(srcdir)/Makefile.am  $(am__configure_deps)
	@$(TRACE)if test $(srcdir)/Makefile.in -ot $(top_srcdir)/configure.ac || \
	   test $(srcdir)/Makefile.in -ot $(ACLOCAL_M4) || \
	   test $(srcdir)/Makefile.in -ot $(top_srcdir)/configure || \
	   test $(srcdir)/Makefile.in -ot $(srcdir)/Makefile.am ; \
	then \
	  $(top_srcdir)/../../../autogen.sh csl/cslbase/crlibm ; \
	else echo Redundant attempt to remake Makefile.in ; \
	fi




# Note that at the moment, asking for intervals disables double-extended
if USE_HARDWARE_DE
libcrlibm_a_SOURCES =  \
	crlibm.h crlibm_private.h crlibm_private.c double-extended.h\
	triple-double.h triple-double.c\
	exp-td.h exp-td.c exp-td-standalone.c expm1-standalone.c  \
	expm1.h expm1.c \
	log-de.c log-de.h \
	log1p.c \
	log10-td.h log10-td.c \
	log2-td.h  log2-td.c \
	rem_pio2_accurate.h rem_pio2_accurate.c \
	trigo_fast.c trigo_fast.h trigo_accurate.c trigo_accurate.h \
	trigpi.c trigpi.h \
	asincos.h asincos.c \
	pow.h pow.c\
	atan_fast.c atan_fast.h atan_accurate.h atan_accurate.c \
	csh_fast.h csh_fast.c
else 
libcrlibm_a_SOURCES =  \
	crlibm.h crlibm_private.h crlibm_private.c \
	triple-double.h triple-double.c\
	exp-td.h exp-td.c exp-td-standalone.c expm1-standalone.c  \
	expm1.h expm1.c \
	log.c log.h \
	log1p.c \
	rem_pio2_accurate.h rem_pio2_accurate.c \
	trigo_fast.c trigo_fast.h trigo_accurate.c trigo_accurate.h \
	trigpi.c trigpi.h \
	asincos.h asincos.c \
	pow.h pow.c\
	atan_fast.c atan_fast.h atan_accurate.h atan_accurate.c \
	csh_fast.h csh_fast.c 
endif


# add all the scs_lib useful functions
libcrlibm_a_LIBADD = scs_lib/scs_private.o scs_lib/addition_scs.o  \
	scs_lib/division_scs.o scs_lib/print_scs.o\
	scs_lib/double2scs.o scs_lib/zero_scs.o\
	scs_lib/multiplication_scs.o scs_lib/scs2double.o

include_HEADERS = crlibm.h

SUBDIRS = scs_lib . tests

# Add your compiler here. Default is assumed to be gcc.
if COMPILER_ICC
# mp means maintain precision. Should be useless with std=c99, this is an ICC bug
AM_CFLAGS =  -std=c99 -mp -Qoption,cpp,--extended_float_types -IPF_fp_speculationsafe
else # default assumed to be gcc
if USE_SSE2
AM_CFLAGS = -std=c99 -Wall -msse2 -mfpmath=sse -I$(top_srcdir)
else
AM_CFLAGS = -std=c99 -Wall -O3 -I$(top_srcdir)
endif
endif

tripledoubleprocedures.pdf: docs/latex/tripledoubleprocedures.tex
	cd docs/latex; \
	pdflatex tripledoubleprocedures; bibtex tripledoubleprocedures; \
	pdflatex tripledoubleprocedures; pdflatex tripledoubleprocedures;\
	mv tripledoubleprocedures.pdf ..

crlibm.pdf: docs/latex/crlibm.tex
	cd docs/latex; pdflatex crlibm; bibtex crlibm; pdflatex crlibm; pdflatex crlibm;\
	mv crlibm.pdf .. 

doc: crlibm.pdf tripledoubleprocedures.pdf

EXTRA_DIST = VERSION TODO\
	maple/common-procedures.mpl \
	maple/double-extended.mpl maple/triple-double.mpl\
	maple/exp-td.mpl maple/csh.mpl \
	maple/log-td.mpl  maple/log-de.mpl \
	maple/log2-td.mpl maple/log10-td.mpl \
	maple/trigo.mpl maple/atan.mpl maple/atan-pentium.mpl \
	maple/asin-td.mpl maple/acos-td.mpl \
	maple/sqrt.mpl \
	maple/expm1.mpl \
	maple/gal.mpl \
	maple/pow.mpl \
	maple/atan-itanium.mpl \
	gappa/trigos/SinCosCase3.gappa gappa/trigos/TanCase2.gappa \
	gappa/trigos/TanCase2.gappa \
	gappa/trigos/SinCosCase3.gappa gappa/trigos/TanCase2.gappa \
	gappa/sqrt12.gappa gappa/sqrt13.gappa gappa/sqrt-proof.sh gappa/sqrt.sed \
	gappa/log-de/log-de-acc-index0-E0.gappa    gappa/log-de/log-de-index0-E0.gappa \
	gappa/log-de/log-de-acc-index0-E1N.gappa   gappa/log-de/log-de-index0-E1N.gappa \
	gappa/log-de/log-de-acc-index1N-E0.gappa   gappa/log-de/log-de-index1N-E0N.gappa \
	gappa/log-de/log-de-acc-index1N-E1N.gappa  gappa/log-de/README \
	gappa/log-td/log-td.gappa             gappa/log-td/log-td-E0.gappa \
	gappa/log-td/log-td-E0-logir0.gappa   gappa/log-td/log-td-accurate.gappa \
	gappa/log-td/log-td-accurate-E0.gappa gappa/log-td/log-td-accurate-E0-logir0.gappa \
	gappa/exp-td/exp-td-accurate1.gappa gappa/exp-td/exp-td-accurate2.gappa \
	gappa/exp-td/exp-td-accurate3.gappa gappa/exp-td/exp-td-accurate4.gappa \
	gappa/exp-td/exp-td-proof.sh \
	gappa/trigpi/cospi-accurate.gappa  gappa/trigpi/cospi-quick.gappa \
	gappa/trigpi/sinpi-accurate.gappa  gappa/trigpi/sinpi-quick.gappa \
	gappa/asin/asinAccuR0.gappa gappa/asin/asinAccuR1.gappa  \
	gappa/asin/asinAccuR2.gappa gappa/asin/asinAccuR3.gappa \
	gappa/asin/asinAccuR4.gappa gappa/asin/asinAccuR5.gappa \
	gappa/asin/asinAccuR6.gappa gappa/asin/asinAccuR7.gappa \
	gappa/asin/asinAccuR8.gappa gappa/asin/asinAccuR9.gappa \
	gappa/asin/asinQuickR0.gappa gappa/asin/asinQuickR1.gappa \
	gappa/asin/asinQuickR2.gappa gappa/asin/asinQuickR3.gappa \
	gappa/asin/asinQuickR4.gappa gappa/asin/asinQuickR5.gappa \
	gappa/asin/asinQuickR6.gappa gappa/asin/asinQuickR7.gappa \
	gappa/asin/asinQuickR8.gappa gappa/asin/asinQuickR9.gappa \
	docs/latex/crlibm.tex \
	docs/latex/0_intro.tex docs/latex/0_getting-started.tex\
	docs/latex/1_common.tex docs/latex/sqrt.tex \
	docs/latex/exp.tex docs/latex/expm1.tex \
	docs/latex/log.tex docs/latex/log1p.tex docs/latex/log2.tex docs/latex/log10.tex\
	docs/latex/asin.tex docs/latex/acos.tex docs/latex/atan.tex \
	docs/latex/csh.tex docs/latex/trigo.tex docs/latex/trigpi.tex \
	docs/latex/pow.tex \
	docs/latex/fig_scs docs/latex/fig_exp\
	docs/latex/elem-fun.bib\
	docs/latex/tripledoubleprocedures.tex \
	scs_lib/tests/tbx_timing.h \
	tests/testperfs.sh\
	triple-double.h double-extended.h \
	log-de.c log-de.h log-td.c log-td.h\
	atan-pentium.c atan-itanium.c 
 

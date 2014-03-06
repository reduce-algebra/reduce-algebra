## Process this file with automake to produce Makefile.in

# This segment added by Arthur Norman in a messy attempt to reduce
# trouble with autoconf and friend.

# I want to be able to see what gets built and why, so here is a GNU
# make trace facility.

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
	  $(top_srcdir)/../../autogen.sh ; \
	else echo Redundant attempt to remake $(ACLOCAL_M4) ; \
	fi

$(top_srcdir)/configure:  $(am__configure_deps) $(ACLOCAL_M4)
	@if test $(top_srcdir)/configure -ot $(top_srcdir)/configure.ac || \
	   test $(top_srcdir)/configure -ot $(ACLOCAL_M4) ; \
	then \
	  $(top_srcdir)/../../autogen.sh ; \
	else echo Redundant attempt to remake configure ; \
        fi

$(srcdir)/Makefile.in:  $(srcdir)/Makefile.am  $(am__configure_deps) \
		$(top_srcdir)/configure
	@if test $(srcdir)/Makefile.in -ot $(top_srcdir)/configure.ac || \
	   test $(srcdir)/Makefile.in -ot $(ACLOCAL_M4) || \
	   test $(srcdir)/Makefile.in -ot $(top_srcdir)/configure || \
	   test $(srcdir)/Makefile.in -ot $(srcdir)/Makefile.am ; \
	then \
	  $(top_srcdir)/../../autogen.sh ; \
	else echo Redundant attempt to remake Makefile.in ; \
	fi



AM_CFLAGS = -O0 -std=gnu99 # produces a warning, but I really need -O0 and I don't know how to get it.

if USE_INTERVAL_FUNCTIONS
bin_PROGRAMS =  crlibm_testval crlibm_soaktest crlibm_soaktest_interval crlibm_testperf crlibm_testperf_interval crlibm_blindtest crlibm_generate_test_vectors
else
bin_PROGRAMS =  crlibm_testval crlibm_soaktest crlibm_testperf  crlibm_blindtest crlibm_generate_test_vectors
endif

LDADD= $(top_builddir)/libcrlibm.a
# The last line used to set INCLUDES but was changed by A C Norman in March
# 2014 to avoid automake warning messages about that being an "old" name.
AM_CPPFLAGS=-I$(top_srcdir)
../libcrlibm.a:
	cd $(top_srcdir); make libcrlibm.a 

crlibm_testval_SOURCES = test_val.c test_common.c test_common.h
crlibm_soaktest_SOURCES = soak_test.c test_common.c test_common.h
crlibm_soaktest_interval_SOURCES = soak_test-interval.c test_common.c test_common.h
crlibm_testperf_SOURCES = test_perf.c test_common.c test_common.h  powmidpoint.h

crlibm_testperf_interval_SOURCES = test_perf-interval.c test_common.c test_common.h
crlibm_blindtest_SOURCES = blind_test.c test_common.c test_common.h
crlibm_generate_test_vectors_SOURCES = generate_test_vectors.c test_common.c test_common.h

check_exp: crlibm_blindtest
	echo ./crlibm_blindtest exp.testdata>check_exp; chmod a+rx check_exp
check_expm1: crlibm_blindtest
	echo ./crlibm_blindtest expm1.testdata>check_expm1; chmod a+rx check_expm1
check_log: crlibm_blindtest
	echo ./crlibm_blindtest log.testdata>check_log; chmod a+rx check_log
check_log2: crlibm_blindtest
	echo ./crlibm_blindtest log2.testdata>check_log2; chmod a+rx check_log2
check_log10: crlibm_blindtest
	echo ./crlibm_blindtest log10.testdata>check_log10; chmod a+rx check_log10
check_log1p: crlibm_blindtest
	echo ./crlibm_blindtest log1p.testdata>check_log1p; chmod a+rx check_log1p
check_sin: crlibm_blindtest
	echo ./crlibm_blindtest sin.testdata>check_sin; chmod a+rx check_sin
check_cos: crlibm_blindtest
	echo ./crlibm_blindtest cos.testdata>check_cos; chmod a+rx check_cos
check_tan: crlibm_blindtest
	echo ./crlibm_blindtest tan.testdata>check_tan; chmod a+rx check_tan
check_asin: crlibm_blindtest
	echo ./crlibm_blindtest asin.testdata>check_asin; chmod a+rx check_asin
check_acos: crlibm_blindtest
	echo ./crlibm_blindtest acos.testdata>check_acos; chmod a+rx check_acos
check_atan: crlibm_blindtest
	echo ./crlibm_blindtest atan.testdata>check_atan; chmod a+rx check_atan
check_asinpi: crlibm_blindtest
	echo ./crlibm_blindtest asinpi.testdata>check_asinpi; chmod a+rx check_asinpi
check_acospi: crlibm_blindtest
	echo ./crlibm_blindtest acospi.testdata>check_acospi; chmod a+rx check_acospi
check_atanpi: crlibm_blindtest
	echo ./crlibm_blindtest atanpi.testdata>check_atanpi; chmod a+rx check_atanpi
check_sinh: crlibm_blindtest
	echo ./crlibm_blindtest sinh.testdata>check_sinh; chmod a+rx check_sinh
check_cosh: crlibm_blindtest
	echo ./crlibm_blindtest cosh.testdata>check_cosh; chmod a+rx check_cosh
check_sinpi: crlibm_blindtest
	echo ./crlibm_blindtest sinpi.testdata>check_sinpi; chmod a+rx check_sinpi
check_cospi: crlibm_blindtest
	echo ./crlibm_blindtest cospi.testdata>check_cospi; chmod a+rx check_cospi
check_tanpi: crlibm_blindtest
	echo ./crlibm_blindtest tanpi.testdata>check_tanpi; chmod a+rx check_tanpi
check_pow: crlibm_blindtest
	echo ./crlibm_blindtest pow.testdata>check_pow; chmod a+rx check_pow

CRLIBM_CHECKLIST = check_exp check_expm1 check_log check_log2 check_log10 check_log1p \
check_sin check_cos check_tan check_asin check_acos check_atan  check_sinh check_cosh  \
check_sinpi check_cospi check_tanpi check_asinpi check_acospi check_atanpi check_pow

TESTS = $(CRLIBM_CHECKLIST)

EXTRA_DIST = exp.testdata expm1.testdata log.testdata log2.testdata log10.testdata log1p.testdata  \
sin.testdata cos.testdata tan.testdata asin.testdata acos.testdata atan.testdata sinh.testdata cosh.testdata \
sinpi.testdata cospi.testdata tanpi.testdata asinpi.testdata acospi.testdata atanpi.testdata pow.testdata

CLEANFILES = $(CRLIBM_CHECKLIST)

# Makefile.am

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
# code that  means that when a recipe is called it does a further check
# to see if it is actually needed, and that sorts things out. It may be that
# the issues I observed are to do with the very special treatment that
# make gives to the re-creation of Makefile and the files that it is
# derived from.

$(ACLOCAL_M4):  $(am__aclocal_m4_deps)
	@$(TRACE)if test $(ACLOCAL_M4) -ot $(top_srcdir)/configure.ac; \
	then \
	  $(top_srcdir)/../autogen.sh psl ; \
	else echo Redundant attempt to remake $(ACLOCAL_M4) ; \
	fi

$(top_srcdir)/configure:  $(am__configure_deps) $(ACLOCAL_M4)
	@$(TRACE)if test $(top_srcdir)/configure -ot $(top_srcdir)/configure.ac || \
	   test $(top_srcdir)/configure -ot $(ACLOCAL_M4) ; \
	then \
	  $(top_srcdir)/../autogen.sh psl ; \
	else echo Redundant attempt to remake configure ; \
	fi

$(srcdir)/Makefile.in:  $(srcdir)/Makefile.am  $(am__configure_deps) \
		$(top_srcdir)/configure
	@$(TRACE)if test $(srcdir)/Makefile.in -ot $(top_srcdir)/configure.ac || \
	   test $(srcdir)/Makefile.in -ot $(ACLOCAL_M4) || \
	   test $(srcdir)/Makefile.in -ot $(top_srcdir)/configure || \
	   test $(srcdir)/Makefile.in -ot $(srcdir)/Makefile.am ; \
	then \
	  $(top_srcdir)/../autogen.sh psl ; \
	else echo Redundant attempt to remake Makefile.in ; \
	fi

srcdir = @srcdir@
VPATH = @srcdir@

reducec=$(srcdir)/..
herec=$(shell pwd)

if cygpath
reduce=$(shell cygpath -m $(reducec))
here=$(shell cygpath -m $(herec))
else
reduce=$(reducec)
here=$(herec)
endif

all:
# The arrangement here is somewhat odd to try to cope with the way that this
# Makefile gets extended via created include files when it runs.
	test -d red || mkdir red; \
	if ! test -f red/bootstrap.img; \
	then $(MAKE) red/bootstrap.img; \
	     if test -f red/bootstrap.img; then $(MAKE) reduce; fi; \
	else touch red/bootstrap.img; touch red/hugo; $(MAKE) reduce; fi


force:
# Force rebuild of bootstrap.img
	$(MAKE) red/bootstrap.img
	test -f red/bootstrap.img && $(MAKE) reduce

# The dependencies here use wild-card specifications and are set up by hand
# because at the stage of bootstrapping I do not have any automatic
# scheme for dependency tracking in place

red/bootstrap.img:	psl/* \
		$(srcdir)/symget.dat $(srcdir)/bootstrap.sh \
		$(srcdir)/pslcompat.sl \
		$(srcdir)/boot.sl $(reducec)/packages/package.map \
		$(reducec)/packages/support/*.red \
		$(reducec)/packages/rlisp/*.red \
		$(reducec)/packages/alg/*.red  \
		$(reducec)/packages/poly/* \
		$(reducec)/packages/arith/*.red \
		red/mma.awk red/qepcad.awk
	$(srcdir)/bootstrap.sh $(BUILD)

# These files are needed by redlog, and putting copies of them in
# the "red" directory will mean that Reduce can find them even if the
# full set of source files are not available.

red/mma.awk:	$(reducec)/packages/redlog/mma/mma.awk
	cp $(reducec)/packages/redlog/mma/mma.awk red/mma.awk

red/qepcad.awk:	$(reducec)/packages/redlog/qepcad/qepcad.awk
	cp $(reducec)/packages/redlog/qepcad/qepcad.awk red/qepcad.awk

tryboot:
	psl/bpsl -td $(STORE2) -f red/bootstrap.img

# The process of building the bootstrap version of the reduce image
# create a set of subsidiary Makefile includes that document how to
# go further. Of course this means that make has no idea how to cope with
# these extra bits until the bootstrap step has been performed!


# Making these include files sort-of optional and merely touching them
# to bring them up to date when necessary appears to avoid some makefile
# mess that I do not really understand, like a tendancy for the bootstrap
# image to get remade multiple times.

deps/core-packages.psl-make:
	if ! test -d deps; then mkdir deps; fi
	touch deps/core-packages.psl-make

deps/core-packages.psl-depend:
	if ! test -d deps; then mkdir deps; fi
	touch deps/core-packages.psl-depend

deps/noncore-packages.psl-make:
	if ! test -d deps; then mkdir deps; fi
	touch deps/noncore-packages.psl-make

deps/noncore-packages.psl-depend:
	if ! test -d deps; then mkdir deps; fi
	touch deps/noncore-packages.psl-depend

-include deps/core-packages.psl-make
-include deps/core-packages.psl-depend
-include deps/noncore-packages.psl-make
-include deps/noncore-packages.psl-depend

red/reduce.img:  red/hugo
	if  test -f "../../psl/mkreduce" -o ! -f red/reduce.img; then rm -f ../../psl/mkreduce; \
	"$(srcdir)/reduce.img.sh" $(BUILD); \
	fi

# end of Makefile.am


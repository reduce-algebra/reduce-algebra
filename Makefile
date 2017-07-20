# This is a hand-written top-level Makefile


.PHONY: dist all csl psl install

# When debugging it may be useful to invoke scripts/make.sh in a noisy way...
# as in "make VERBOSE=-v"

# By default or with an explicit target "all" this will try to
# (re-)build all versions of Reduce thhat have been configured.

all:
	+$(SHELL) $(VERBOSE) scripts/make.sh $(MAKECMDGOALS)

# This script tries a fairly basic sanity check to see if the
# support-tools, include files and libraries needed to build the
# CSL version of Reduce are available. It is NOT a perfect test but
# may be useful in case of difficulty. See README.testprogram in the
# csl directory for further explanation and especially for how to
# run this test step by step manually.

csltest:
	if which cygcheck > /dev/null; then $(SHELL) $(VERBOSE) scripts/cygwin-sanity-check.sh ; fi
	$(SHELL) $(VERBOSE) scripts/csl-sanity-check.sh

# I have csl and psl as special targets here because those names are
# also names of top-level directories, but eg "make csl" wants to
# delegate to the build directory and does not relate to the top-level
# csl directory being up to date. When multiple copies of Reduce have
# been configured (eg a regular and a debug version, or ones with or without
# GUI, testing options, ...) "make csl" or "make psl" will build all of
# them.

csl:
	+$(SHELL) $(VERBOSE) scripts/make.sh $(MAKECMDGOALS)

psl:
	+$(SHELL) $(VERBOSE) scripts/make.sh $(MAKECMDGOALS)

# "make install" will try to install both CSL and PSL versions (if
# configured) in the same place and manner that they would have been
# installed using the platform-specific installers. This should work
# on Linux/Unix but the situation on Macintosh and Windows will be
# harder. On *ix it will honours the "--prefix" option used with configure,
# but on Windows it will probably always install in a default location.

install:
	$(SHELL) $(VERBOSE) scripts/install.sh $(MAKECMDGOALS)

uninstall:
	$(SHELL) $(VERBOSE) scripts/uninstall.sh $(MAKECMDGOALS)


%::
	+$(SHELL) $(VERBOSE) scripts/make.sh $(MAKECMDGOALS)

# end of Makefile

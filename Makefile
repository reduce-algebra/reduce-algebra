# This is a hand-written top-level Makefile
# The main usage will be
#    make       make all configured CSL and PSL versions of Reduce
#    make csl   make just the CSL versions
#    make psl   make just the PSL versions
#    make <anything> sequential
#               normally if there are both CSL and PSL versions configured
#               or if there are several variants of one of those (eg debug
#               and regular) this makes them all in parallel. That can make
#               the rebuild much faster, but it leaves the output showing
#               parts of all the builds interleaved, so if something goes
#               wrong it is unhelpful. Use "sequential" to force sequential
#               rather than parallel building if you need to keep a log for
#               debugging or diagnosis.
#
#   make csl-sanity-test
#               A simple test to ensure that there is at least a chance of
#               building the CSL version. This compiles a small test program
#               that should pop up a window.
#   [make snapshot] Work in progress to make a distributable archive relevant
#               to the current architecture.
#   [make install] Work in progress at this stage.


.PHONY: dist all csl psl csl-sanity-test profile snapshot install

# When debugging it may be useful to invoke scripts/make.sh in a noisy way...
# as in "make VERBOSE=-v"

# By default or with an explicit target "all" this will try to
# (re-)build all versions of Reduce that have been configured.

all:
	+$(SHELL) $(VERBOSE) scripts/make.sh $(MAKECMDGOALS)

# The next will re-profile Reduce. It uses the first configured version
# in the cslbuild directory.

profile:
	cd `ls -d cslbuild/*/csl | head -1` && make profile

profile-install:
	cd `ls -d cslbuild/*/csl | head -1` && make profile-install

# This script tries a fairly basic sanity check to see if the
# support-tools, include files and libraries needed to build the
# CSL version of Reduce are available. It is NOT a perfect test but
# may be useful in case of difficulty. See README.testprogram in the
# csl directory for further explanation and especially for how to
# run this test step by step manually. If the test succeeds it should
# pop up a Window with the word "Arthur" in it.

csl-sanity-test:
	if which cygcheck > /dev/null; then $(SHELL) $(VERBOSE) scripts/cygwin-sanity-check.sh ; fi
	$(SHELL) $(VERBOSE) scripts/csl-sanity-check.sh

# "make snapshot" will, when I have finished implementing support for it,
# create a file or several files in the directory "snapshots" representing
# a distributable archive for the current system. I intend to make this
# take over from the current situation where there are directories called
# debianbuild, macbuild and winbuild each with separate sets of arrangements.
# Well packing for different architectures will still involve platform-specific
# code but I will arrange that through scripts triggerable in a uniform manner
# here
snapshot:
# First build binaries for this machine.
	$(MAKE)
# Then package the resulting binaries as a .deb, .rpm, .dmg or as a windows
# installer file.
	scripts/snapshot.sh


# "make install" will try to install both CSL and PSL versions (if
# configured) in the same place and manner that they would have been
# installed using the platform-specific installers. This should work
# on Linux/Unix but the situation on Macintosh and Windows will be
# harder. On *ix it will honours the "--prefix" option used with configure,
# but on Windows it will probably always install in a default location.
# Well the "install" option is somewhjat work in progress.

install:
	$(SHELL) $(VERBOSE) scripts/install-reduce.sh $(MAKECMDGOALS)

uninstall:
	$(SHELL) $(VERBOSE) scripts/uninstall.sh $(MAKECMDGOALS)

.PHONY:	csl psl

csl psl:
	+$(SHELL) $(VERBOSE) scripts/make.sh $(MAKECMDGOALS)

%::
	+$(SHELL) $(VERBOSE) scripts/make.sh $(MAKECMDGOALS)

# end of Makefile

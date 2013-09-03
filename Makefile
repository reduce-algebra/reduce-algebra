# This is a hand-written top-level Makefile


.PHONY: dist all csl psl

VERBOSE =
# When debugging it may be useful to invole scripts/make.sh in a noisy way...
#VERBOSE = -v

all:
	+$(SHELL) $(VERBOSE) scripts/make.sh $(MAKECMDGOALS)

dist:
	$(SHELL) $(VERBOSE) scripts/dist.sh

# This script tries a fairly basic sanity check to see if the
# support-tools, include files and libraries needed to build the
# CSL version of Reduce are available. It is NOT a perfect test but
# may be useful in case of difficulty. See README.testprogram in the
# csl directory for further explanation and especially for how to
# run this test step by step manually.

csltest:
	$(SHELL) $(VERBOSE) scripts/csl-sanity-check.sh

# I have csl and psl as special targets here because those names are
# also names of top-level directories, but eg "make csl" wants to
# delegate to the build directory and does not relate to the top-level
# csl directory being up to date.

csl:
	+$(SHELL) $(VERBOSE) scripts/make.sh $(MAKECMDGOALS)

psl:
	+$(SHELL) $(VERBOSE) scripts/make.sh $(MAKECMDGOALS)

install:
	@echo No install: target yet!

%::
	+$(SHELL) $(VERBOSE) scripts/make.sh $(MAKECMDGOALS)

# end of Makefile

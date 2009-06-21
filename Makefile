# This is a hand-written top-level Makefile


.PHONY: dist all csl psl

all:
	+$(SHELL) scripts/make.sh $(MFLAGS)  $(MAKECMDGOALS)


dist:
	$(SHELL) scripts/dist.sh

# This script tries a fairly basic sanity check to see if the
# support-tools, include files and libraries needed to build the
# CSL version of Reduce are available. It is NOT a perfect test but
# may be useful in case of difficulty. See README.testprogram in the
# csl directory for further explanation and especially for how to
# run this test step by step manually.

csltest:
	$(SHELL) scripts/csl-sanity-check.sh

# I have csl and psl as special targets here because those names are
# also names of top-level directories, but eg "make csl" wants to
# delegate to the build directory and does not relate to the top-level
# csl directory being up to date.

csl:
	+$(SHELL) scripts/make.sh $(MFLAGS)  $(MAKECMDGOALS)

psl:
	+$(SHELL) scripts/make.sh $(MFLAGS)  $(MAKECMDGOALS)

%::
	+$(SHELL) scripts/make.sh $(MFLAGS)  $(MAKECMDGOALS)

# end of Makefile

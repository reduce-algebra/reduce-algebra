# This is a hand-written top-level Makefile


.PHONY: dist lgpldist all csl psl

all:
	+$(SHELL) scripts/make.sh $(MFLAGS)  $(MAKECMDGOALS)


dist:
	$(SHELL) scripts/dist.sh

-include LGPLMANIFEST.dep

LGPLMANIFEST.dep:
	touch LGPLMANIFEST.dep

lgpldist: $(LGPL)
	$(SHELL) scripts/lgpldist.sh


# I have csl and psl as special targets here because those names are
# also names of top-level directorties, but eg "make csl" wants to
# delegate to the build directory and does not relate to the top-level
# csl directory being up to date.

csl:
	+$(SHELL) scripts/make.sh $(MFLAGS)  $(MAKECMDGOALS)

psl:
	+$(SHELL) scripts/make.sh $(MFLAGS)  $(MAKECMDGOALS)

%::
	+$(SHELL) scripts/make.sh $(MFLAGS)  $(MAKECMDGOALS)

# end of Makefile

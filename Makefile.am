# Makefile.am

srcdir = @srcdir@
VPATH = @srcdir@

.PHONY:	all fox

# As at present set up this Makefile.am imagines that in a CSL build
# directory there are two sub-directories, csl and fox, and it is
# necessary to delegate make to each of them.
#
# For PSL it supposes that there will be a build directory called
# psl to delegate to.

AM_MAKEFLAGS=$(MFLAGS) $(MYFLAGS)

if csl
LISPDIR=csl
FOXDEP=include/fox-1.6/fxver.h
else
if psl
LISPDIR=psl
FOXDEP=
else
LISPDIR=unknown
FOXDEP=
endif
endif



# I have "all" as a special case here because the first target should be
# the default one.

all:	$(FOXDEP)
	echo Build all: $(MAKE) mflags=$(MFLAGS) myflags=$(MYFLAGS) all
	@cd $(LISPDIR) && $(MAKE) $(MFLAGS) $(MYFLAGS) all MYFLAGS="$(MFLAGS) $(MYFLAGS)"


if csl
fox $(FOXDEP):
	echo Build FOX: $(MAKE) mflags=$(MFLAGS) myflags=$(MYFLAGS) install
	@cd fox && $(MAKE) $(MFLAGS) $(MYFLAGS) install MYFLAGS="$(MFLAGS) $(MYFLAGS)"

# If one of the major foundations of this Makefile have a date later than that
# on fxver.h then make does a futile recursion to try to fix it and in the
# process it can do a LOT of work that I do not want done. I can at least
# arrange that that happens at most once by putting the following rules:

$(srcdir)/configure.ac:
	touch $(srcdir)/configure.ac

$(srcdir)/Makefile.am:
	touch $(srcdir)/Makefile.am

endif

%::	$(FOXDEP)
	echo $(MAKE) mflags=$(MFLAGS) myflags=$(MYFLAGS) makecmdgoals=$(MAKECMDGOALS)
	@cd $(LISPDIR) && $(MAKE) $(MFLAGS) $(MYFLAGS) $(MAKECMDGOALS) MYFLAGS="$(MFLAGS) $(MYFLAGS)"

# end of Makefile.am


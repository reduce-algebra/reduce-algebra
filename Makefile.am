# Makefile.am

srcdir = @srcdir@
VPATH = @srcdir@
ACLOCAL_AMFLAGS = -I m4

if wx
.PHONY:	all wx
else
if fox
.PHONY:	all fox
else
.PHONY:	all
endif
endif

# I want to be able to see what gets built and why, so here is a GNU
# make trace facility.

TRACE = $(warning TRACE: $@ :: $?)

# As at present set up this Makefile.am imagines that in a CSL build
# directory there are two sub-directories, csl and fox or wxWidgets, and it is
# necessary to delegate make to each of them. Well if a GUI is not needed
# or if a system version of wxWidgets is to be used then the fox/wxWidgets
# sub-directory is not used.
#
# For PSL it supposes that there will be a build directory called
# psl to delegate to.

AM_MAKEFLAGS=$(MFLAGS) $(MYFLAGS)

if csl
LISPDIR=csl
if fox
FOXDEP=include/fox-1.6/fxver.h
else
FOXDEP=
endif
if wx
WXDEP=bin/wx-config
else
WXDEP=
endif
else
if psl
LISPDIR=psl
FOXDEP=
WXDEP=
else
LISPDIR=unknown
FOXDEP=
WXDEP=
endif
endif



# I have "all" as a special case here because the first target should be
# the default one.

all:	$(FOXDEP) $(WXDEP)
	echo Build all: $(MAKE) mflags=$(MFLAGS) myflags=$(MYFLAGS) all
	cd $(LISPDIR) && $(LOCALCYG) $(MAKE) $(MFLAGS) $(MYFLAGS) all MYFLAGS="$(MFLAGS) $(MYFLAGS)"


if csl
if fox
fox $(FOXDEP):
	echo Build FOX: $(MAKE) mflags=$(MFLAGS) myflags=$(MYFLAGS) install
	cd fox && $(LOCALCYG) $(MAKE) $(MFLAGS) $(MYFLAGS) install MYFLAGS="$(MFLAGS) $(MYFLAGS)"
endif
if wx
wx $(WXDEP):
	echo Build wxWidgets: $(MAKE) mflags=$(MFLAGS) myflags=$(MYFLAGS) install
	cd wxWidgets && $(LOCALCYG) $(MAKE) $(MFLAGS) $(MYFLAGS) install MYFLAGS="$(MFLAGS) $(MYFLAGS)"
endif

# If one of the major foundations of this Makefile have a date later than that
# on fxver.h then make does a futile recursion to try to fix it and in the
# process it can do a LOT of work that I do not want done. I can at least
# arrange that that happens at most once by putting the following rules:

$(srcdir)/configure.ac:
	touch "$(srcdir)/configure.ac"

$(srcdir)/Makefile.am:
	touch "$(srcdir)/Makefile.am"

endif

%::	$(FOXDEP) $(WXDEP)
	echo $(MAKE) mflags=$(MFLAGS) myflags=$(MYFLAGS) makecmdgoals=$(MAKECMDGOALS)
	cd $(LISPDIR) && $(MAKE) $(MFLAGS) $(MYFLAGS) $(MAKECMDGOALS) MYFLAGS="$(MFLAGS) $(MYFLAGS)"

# end of Makefile.am


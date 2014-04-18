# Makefile.am

srcdir = @srcdir@
VPATH = @srcdir@

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
	  $(top_srcdir)/../../autogen.sh ; \
	else echo Redundant attempt to remake $(ACLOCAL_M4) ; \
	fi

$(top_srcdir)/configure:  $(am__configure_deps) $(ACLOCAL_M4)
	@$(TRACE)if test $(top_srcdir)/configure -ot $(top_srcdir)/configure.ac || \
	   test $(top_srcdir)/configure -ot $(ACLOCAL_M4) ; \
	then \
	  $(top_srcdir)/../../autogen.sh ; \
	else echo Redundant attempt to remake configure ; \
	fi

$(srcdir)/Makefile.in:  $(srcdir)/Makefile.am  $(am__configure_deps)
	@$(TRACE)if test $(srcdir)/Makefile.in -ot $(top_srcdir)/configure.ac || \
	   test $(srcdir)/Makefile.in -ot $(ACLOCAL_M4) || \
	   test $(srcdir)/Makefile.in -ot $(top_srcdir)/configure || \
	   test $(srcdir)/Makefile.in -ot $(srcdir)/Makefile.am ; \
	then \
	  $(top_srcdir)/../../autogen.sh ; \
	else echo Redundant attempt to remake Makefile.in ; \
	fi



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
	@cd $(LISPDIR) && $(MAKE) $(MFLAGS) $(MYFLAGS) all MYFLAGS="$(MFLAGS) $(MYFLAGS)"


if csl
if fox
fox $(FOXDEP):
	echo Build FOX: $(MAKE) mflags=$(MFLAGS) myflags=$(MYFLAGS) install
	@cd fox && $(MAKE) $(MFLAGS) $(MYFLAGS) install MYFLAGS="$(MFLAGS) $(MYFLAGS)"
endif
if wx
wx $(WXDEP):
	echo Build wxWidgets: $(MAKE) mflags=$(MFLAGS) myflags=$(MYFLAGS) install
	@cd wxWidgets && $(MAKE) $(MFLAGS) $(MYFLAGS) install MYFLAGS="$(MFLAGS) $(MYFLAGS)"
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
	@cd $(LISPDIR) && $(MAKE) $(MFLAGS) $(MYFLAGS) $(MAKECMDGOALS) MYFLAGS="$(MFLAGS) $(MYFLAGS)"

# end of Makefile.am


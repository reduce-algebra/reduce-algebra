#
#  Makefile for REDUCE User Contributed Library (PSL Version)
#	
#  Author:  James H. Davenport <jhd@maths.bath.ac.uk>.
#
#  Modified by:  Anthony C. Hearn.
#
#  This Makefile may be used to build fast loading versions of all the
#  PSL REDUCE User Contributed Library packages, or any particular
#  package.  It assumes that the relevant source files are in the
#  $reduce/lib directory.  It is specific to PSL, and of course those
#  systems (e.g. UNIX) that support a make mechanism.  However, it can
#  be easily used with other systems with a make facility once a
#  suitable mkfasl script has been written.

REDUCE= /reduce
FASL  = b
BINDIR= $(REDUCE)/fasl
SRCDIR= $(REDUCE)/lib
TSTDIR= $(REDUCE)/lib
MKFASL= $(REDUCE)/util/mkfasl

PACKAGES= assist camal changevar cvit desir fide gnuplot laplace \
	  linineq numeric physop pm reacteqn reset rlfi showrules \
	  symmetry tri wu

UNCOMPILEDPACKAGES= odeex

TSTPACKAGES= assist camal changevar cvit desir fide laplace linineq \
	     numeric physop pmrules reacteqn rlfi symmetry tri wu

all:    $(PACKAGES)

assist: $(BINDIR)/assist.$(FASL)

$(BINDIR)/assist.$(FASL): $(SRCDIR)/assist.red
	$(MKFASL) assist lib


camal:  $(BINDIR)/camal.$(FASL)

$(BINDIR)/camal.$(FASL): $(SRCDIR)/camal.red
	$(MKFASL) camal lib


changevar:      $(BINDIR)/changevar.$(FASL)

$(BINDIR)/changevar.$(FASL): $(SRCDIR)/changevar.red
	$(MKFASL) changevar lib


cvit:   $(BINDIR)/cvit.$(FASL)

$(BINDIR)/cvit.$(FASL): $(SRCDIR)/cvit.red
	$(MKFASL) cvit lib


desir:  $(BINDIR)/desir.$(FASL)

$(BINDIR)/desir.$(FASL): $(SRCDIR)/desir.red
	$(MKFASL) desir lib


fide:   $(BINDIR)/fide1.$(FASL) $(BINDIR)/fide.$(FASL)

$(BINDIR)/fide1.$(FASL): $(SRCDIR)/fide1.red
	$(MKFASL) fide1 lib

$(BINDIR)/fide.$(FASL): $(SRCDIR)/fide.red
	$(MKFASL) fide lib


gnuplot:        $(BINDIR)/gnuplot.$(FASL)

$(BINDIR)/gnuplot.$(FASL): $(SRCDIR)/gnuplot.red
	$(MKFASL) gnuplot lib


laplace:        $(BINDIR)/laplace.$(FASL)

$(BINDIR)/laplace.$(FASL): $(SRCDIR)/laplace.red
	$(MKFASL) laplace lib


linineq: $(BINDIR)/linineq.$(FASL)

$(BINDIR)/linineq.$(FASL): $(SRCDIR)/linineq.red
	$(MKFASL) linineq lib


numeric:  $(BINDIR)/numeric.$(FASL)

$(BINDIR)/numeric.$(FASL): $(SRCDIR)/numeric.red
	$(MKFASL) numeric lib


physop: $(BINDIR)/noncom2.$(FASL) $(BINDIR)/physop.$(FASL)

$(BINDIR)/noncom2.$(FASL): $(SRCDIR)/noncom2.red
	$(MKFASL) noncom2 lib

$(BINDIR)/physop.$(FASL): $(SRCDIR)/physop.red
	$(MKFASL) physop lib


pm:     $(BINDIR)/pm.$(FASL) $(BINDIR)/pmrules.$(FASL)
#       $(BINDIR)/pmrules2.$(FASL)

$(BINDIR)/pm.$(FASL): $(SRCDIR)/pm.red
	$(MKFASL) pm lib

$(BINDIR)/pmrules.$(FASL): $(SRCDIR)/pmrules.red
	$(MKFASL) pmrules lib

# $(BINDIR)/pmrules2.$(FASL): $(SRCDIR)/pmrules2.red
#         $(MKFASL) pmrules2 lib


reacteqn: $(BINDIR)/reacteqn.$(FASL)

$(BINDIR)/reacteqn.$(FASL): $(SRCDIR)/reacteqn.red
	$(MKFASL) reacteqn lib


reset:  $(BINDIR)/reset.$(FASL)

$(BINDIR)/reset.$(FASL): $(SRCDIR)/reset.red
	$(MKFASL) reset lib


rlfi:   $(BINDIR)/rlfi.$(FASL)

$(BINDIR)/rlfi.$(FASL): $(SRCDIR)/rlfi.red
	$(MKFASL) rlfi lib


showrules:  $(BINDIR)/showrules.$(FASL)

$(BINDIR)/showrules.$(FASL): $(SRCDIR)/showrules.red
	$(MKFASL) showrules lib


symmetry: $(BINDIR)/symmetry.$(FASL)

$(BINDIR)/symmetry.$(FASL): $(SRCDIR)/symmetry.red
	$(MKFASL) symmetry lib


tri:  $(BINDIR)/tri.$(FASL)

$(BINDIR)/tri.$(FASL): $(SRCDIR)/tri.red
	$(MKFASL) tri lib


wu:     $(BINDIR)/wu.$(FASL)

$(BINDIR)/wu.$(FASL): $(SRCDIR)/wu.red
	$(MKFASL) wu lib

test:   $(PACKAGES)
	for i in $(TSTPACKAGES) ; do \
	rm -f $(REDUCE)/log/$$i.log ; \
	echo \
'load_package '$$i';on errcont;in"'$(TSTDIR)/$$i'.tst";showtime;bye;' \
		    | reduce > $(REDUCE)/log/$$i.log ; \
	done

check:  $(PACKAGES)
	- for i in $(TSTPACKAGES) ; do \
	echo 'comparing '$$i'...' ;  \
	diff $(REDUCE)/log/$$i.log $(TSTDIR) ; \
	done


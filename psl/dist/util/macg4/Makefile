###############################################################################
#
# File:         PXU:Makefile
# Description:  Makefile for psl sun4 specific utilities directory.
# Author:       Harold Carr and Leigh Stoller.
# Created:      08-Oct-86
# Modified:
# Mode:         Text
# Package:      
# Status:
#
# (c) Copyright 1986, University of Utah, all rights reserved.
#
###############################################################################

PROOT	= /Users/winfried/psl

PSL	= $(PROOT)/dist
PSYS	= $(PROOT)/bin
PK	= $(PSL)/kernel
PXK     = $(PK)/$(MACHINE)
PNK	= $(PSL)/nonkernel
PXNK    = $(PNK)/$(MACHINE)
PNKL    = $(PSL)/nonkernel/$(MACHINE)/lap
PC	= $(PSL)/comp
PXC     = $(PC)/$(MACHINE)
PU	= $(PSL)/util
PXU     = $(PU)/$(MACHINE)
PDIST   = $(PSL)/distrib
PXDIST  = $(PDIST)/$(MACHINE)
PL      = $(PSL)/lap/$(MACHINE)

all: \
	$(PL)/disassemble.b $(PL)/get-options.b \
	$(PL)/qualified-counting.b $(PL)/qualified-timing.b \
	$(PL)/helferlein.b $(PL)/spy.b $(PL)/symget.b \
	$(PL)/nbig30.b $(PL)/nbig30a.b $(PL)/mbarith.b $(PL)/double.b \
	$(PL)/fc-indirect.b $(PL)/oload.b $(PL)/l2cdatacon.b \
	$(PL)/quotx30.b
#$(PL)/c2l.o \


# MODEL should be either AREGMODEL for 3.2 or DREGMODEL for 3.4.
MODEL   = DREGMODEL

$(PL)/c2l.o: $(PXU)/c2l.c
	$(CC) -D$(MODEL) -D$(MACHINE) -S c2l.c
	sed 's/_SYM/SYM/g' c2l.s > c2ltemp.s
	rm -f c2l.s
	as c2ltemp.s -o $(PL)/c2l.o
	rm -f c2ltemp.s

$(PL)/disassemble.b: $(PXU)/disassemble.sl
	$(PDIST)/make-lap $(PXU) disassemble

$(PL)/qualified-counting.b: $(PXU)/qualified-counting.sl
	$(PDIST)/make-lap $(PXU) qualified-counting

$(PL)/qualified-timing.b: $(PXU)/qualified-timing.sl
	$(PDIST)/make-lap $(PXU) qualified-timing

$(PL)/helferlein.b: $(PXU)/helferlein.sl $(PL)/if-system.b $(PL)/inum.b
	$(PDIST)/make-lap $(PXU) helferlein

$(PL)/spy.b: $(PXU)/spy.sl
	$(PDIST)/make-lap $(PXU) spy

$(PL)/symget.b: $(PXU)/symget.sl
	$(PDIST)/make-lap $(PXU) symget

$(PL)/fc-indirect.b: $(PXU)/fc-indirect.sl
	$(PDIST)/make-lap $(PXU) fc-indirect

$(PL)/get-options.b: $(PXU)/get-options.sl
	$(PDIST)/make-lap $(PXU) get-options

$(PL)/l2cdatacon.b: $(PXU)/l2cdatacon.sl
	$(PDIST)/make-lap $(PXU) l2cdatacon

$(PL)/oload.b: $(PXU)/oload.sl
	$(PDIST)/make-lap $(PXU) oload

$(PL)/nbig30.b:  $(PXU)/nbig30.sl
	$(PDIST)/make-lap $(PXU) nbig30

$(PL)/nbig30a.b: $(PXU)/nbig30a.sl $(PL)/vfvect.b $(PL)/muls.b $(PL)/double.b \
	$(PL)/inum.b
	$(PDIST)/make-lap $(PXU) nbig30a

$(PL)/quotx30.b: $(PU)/quotx30.sl $(PL)/muls.b $(PL)/double.b
	 $(PDIST)/make-lap $(PU) quotx30


$(PL)/double.b: $(PXU)/double.sl $(PL)/muls.b
	$(PDIST)/make-lap $(PXU) double

$(PL)/mbarith.b: $(PXU)/mbarith.sl $(PL)/muls.b
	$(PDIST)/make-lap $(PXU) mbarith

#

$(PL)/if-system.b b: $(PU)/if-system.sl
	(cd $(PU) ; make $(MFLAGS) MACHINE=$(MACHINE) $(PL)/if-system.b)

$(PL)/inum.b: $(PU)/inum.sl
	(cd $(PU) ; make $(MFLAGS) MACHINE=$(MACHINE) $(PL)/inum.b)

$(PL)/syslisp.b: $(PU)/syslisp.sl
	(cd $(PU) ; make $(MFLAGS) MACHINE=$(MACHINE) $(PL)/syslisp.b)

$(PL)/vfvect.b: $(PXU)/vfvect.sl
	$(PDIST)/make-lap $(PXU) vfvect

$(PL)/muls.b: $(PXU)/muls.sl 
	$(PDIST)/make-lap $(PXU) muls

# Nothing needs to be done, but it needs to be here to interact with the
#  top level Makefile.
clean:


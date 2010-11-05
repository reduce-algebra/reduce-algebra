###############################################################################
#
# File:         PXC:Makefile
# Description:  Makefile for psl compiler system independent modules.
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
#
# 
###############################################################################

PROOT   = /silo/cons/verkaufpsl

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
	$(PL)/unix386-asm.b \
	$(PL)/386-cmac.b \
	$(PL)/386-comp.b \
	$(PL)/386-lap.b \
	$(PL)/lap-to-asm.b $(PL)/nbittab.b \
	$(PL)/carcdrnil.b \
	$(PL)/compiler.b \
	$(PL)/comp-decls.b \
	$(PL)/sys-consts.b \
	$(PL)/sys-dm.b \
	$(PL)/386-spec.b \
	$(PL)/muls.b \
	$(PL)/tags.b

$(PL)/unix386-asm.b: $(PXC)/unix386-asm.sl $(PL)/if-system.b
	$(PDIST)/make-lap $(PXC) unix386-asm

$(PL)/386-cmac.b: $(PXC)/386-cmac.sl $(PL)/if-system.b
	$(PDIST)/make-lap $(PXC) 386-cmac

$(PL)/386-comp.b: $(PXC)/386-comp.sl
	$(PDIST)/make-lap $(PXC) 386-comp

$(PL)/386-lap.b: $(PXC)/386-lap.sl $(PL)/fasl-decls.b \
        $(PXC)/386-inst.dat
	$(PDIST)/make-lap $(PXC) 386-lap

$(PL)/lap-to-asm.b: $(PXC)/lap-to-asm.sl
	$(PDIST)/make-lap $(PXC) lap-to-asm

$(PL)/nbittab.b: $(PXC)/nbittab.sl $(PL)/inum.b $(PL)/fasl-decls.b
	$(PDIST)/make-lap $(PXC) nbittab

$(PL)/carcdrnil.b: $(PXC)/carcdrnil.sl
	$(PDIST)/make-lap $(PXC) carcdrnil

$(PL)/comp-decls.b: $(PXC)/comp-decls.sl
	$(PDIST)/make-lap $(PXC) comp-decls

$(PL)/compiler.b: $(PXC)/compiler.sl
	$(PDIST)/make-lap $(PXC) compiler

$(PL)/sys-consts.b: $(PXC)/sys-consts.sl
	$(PDIST)/make-lap $(PXC) sys-consts

$(PL)/sys-dm.b: $(PXC)/sys-dm.sl $(PL)/tags.b
	$(PDIST)/make-lap $(PXC) sys-dm

$(PL)/tags.b: $(PXC)/tags.sl
	$(PDIST)/make-lap $(PXC) tags

$(PL)/386-spec.b: $(PXC)/386-spec.sl
	$(PDIST)/make-lap $(PXC) 386-spec

$(PL)/muls.b: $(PXC)/muls.sl 
	$(PDIST)/make-lap $(PXC) muls


##

$(PXC)/s386inst.dat: $(PXC)/sun386.geninstr.sl
	(cd $(PXC); make-instructions)

$(PL)/fasl-decls.b: $(PXK)/fasl-decls.sl
	(cd $(PXK); make $(MFLAGS) MACHINE=$(MACHINE) $(PL)/fasl-decls.b)

$(PL)/if-system.b: $(PU)/if-system.sl
	(cd $(PU); make $(MFLAGS) MACHINE=$(MACHINE) $(PL)/if-system.b)

# End of file.

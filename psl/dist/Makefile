###############################################################################
#
# File:         PSL:Makefile
# Description:  Top level makefile for PSL.
# Author:       Harold Carr and Leigh Stoller.
# Created:      04-Feb-87
#
# (c) Copyright 1987, University of Utah, all rights reserved.
###############################################################################
# Revisions:
# 
###############################################################################

# The next line is the only thing that needs to be changed between
# machines/directories.

## PROOT   = /home/cons/reducedev/free_reduce/reduce-algebra/trunk/psl

PSL	= $(PROOT)/dist
PSYS	= $(PROOT)/bin
PK	= $(PSL)/kernel
PXK     = $(PK)/$(MACHINE)
PNK	= $(PSL)/nonkernel
PXNK    = $(PNK)/$(MACHINE)
PNKL    = $(PXNK)/lap
PC	= $(PSL)/comp
PXC     = $(PC)/$(MACHINE)
PU	= $(PSL)/util
PXU     = $(PU)/$(MACHINE)
PDIST   = $(PSL)/distrib
PXDIST  = $(PDIST)/$(MACHINE)
PL      = $(PSL)/lap/$(MACHINE)

PROGRAMS = bare-psl psl pslcomp 

all: bfiles pnkl utilities compiler bpsl make-bare-psl make-psl make-pslcomp
	echo "PSL binaries rebuilt"

executables: make-bare-psl make-psl make-pslcomp

resize:
	rm -f $(PXK)/bps.o $(PXK)/bpsheap.o
	make $(MFLAGS) MACHINE=$(MACHINE) bpsl
	make $(MFLAGS) MACHINE=$(MACHINE) executables

oload:

bfiles: 
	(cd $(PXK); make $(MFLAGS) MACHINE=$(MACHINE) PSL=$(PSL) bfiles)

pnkl:
	(cd $(PXNK); make $(MFLAGS) MACHINE=$(MACHINE) PSL=$(PSL))
	(cd $(PNK) ; make $(MFLAGS) MACHINE=$(MACHINE) PSL=$(PSL))

compiler:
	(cd $(PXC) ; make $(MFLAGS) MACHINE=$(MACHINE) PSL=$(PSL))
	(cd $(PC)  ; make $(MFLAGS) MACHINE=$(MACHINE) PSL=$(PSL))

utilities:
	(cd $(PXU) ; make $(MFLAGS) MACHINE=$(MACHINE) PSL=$(PSL))
	(cd $(PU)  ; make $(MFLAGS) MACHINE=$(MACHINE) PSL=$(PSL))

bpsl: 
	(cd $(PXK) ; make $(MFLAGS) MACHINE=$(MACHINE) PSL=$(PSL) bpsl)

bare-psl: bpsl pnkl make-bare-psl

make-bare-psl:	sparsify
	(cd $(PDIST) ; gcc -Dhpux i-o $(PSYS)/sparsify sparsify.c;  csh -f make-bare-psl)

sparsify:	$(PSYS)/sparsify.c
	(cd $(PDIST) ; gcc -Dhpux i-o $(PSYS)/sparsify sparsify.c)

psl:	bpsl bare-psl utilities make-psl sparsify

make-psl:
	(cd $(PDIST) ; csh -f make-psl)

pslcomp:	bare-psl compiler utilities make-pslcomp sparsify 

make-pslcomp:
	(cd $(PDIST) ; csh -f make-pslcomp)

rlisp: bare-psl compiler utilities make-rlisp

make-rlisp:
	(cd $(PDIST) ; csh -f make-rlisp)


DESTDIR = /usr/site/bin

install:
	-cd $(PSYS)    ; rm -f oload
	-cd $(DESTDIR) ; rm -f $(PROGRAMS)
	-ln -s $(PSYS)/bare-psl $(DESTDIR)
	-ln -s $(PSYS)/psl      $(DESTDIR)
	-ln -s $(PSYS)/pslcomp  $(DESTDIR)
	-ln -s $(PSYS)/rlisp    $(DESTDIR)
	-ln -s $(PSL)/oload     $(PSYS)
	-ln -s $(PSYS)/oload    $(DESTDIR)

tape:
	csh -f $(PDIST)/cleanup.csh
	csh -f $(PDIST)/write-tape.csh

cleanup:
	csh -f $(PDIST)/cleanup.csh
	-rm -f $(PSYS)/old-*

# In order to rebuild the system, pslcomp and bpsl must exist.
clean:
	-rm -f $(PL)/*.b
	-rm -f $(PNKL)/*.b
	-rm -f $(PXK)/*.o
	-rm -f $(PXK)/dmain.s
	-rm -f $(PXK)/main.init
	-rm -f $(PXK)/main.s
	-rm -f $(PXK)/$(MACHINE).sym

# End of file.

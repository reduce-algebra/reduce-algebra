###############################################################################
#
# File:         PXU:Makefile
# Description:  Makefile for psl vax specific utilities directory.
# Author:       Harold Carr and Leigh Stoller.
# Created:      08-Oct-86
# Modified:
# Mode:         Text
# Package:      
# Status:       Open Source: BSD License
#
# (c) Copyright 1982, University of Utah
# %
# % Redistribution and use in source and binary forms, with or without
# % modification, are permitted provided that the following conditions are met:
# %
# %    * Redistributions of source code must retain the relevant copyright
# %      notice, this list of conditions and the following disclaimer.
# %    * Redistributions in binary form must reproduce the above copyright
# %      notice, this list of conditions and the following disclaimer in the
# %      documentation and/or other materials provided with the distribution.
# %
# % THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# % AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
# % THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# % PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR
# % CONTRIBUTORS
# % BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# % CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# % SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# % INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# % CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# % ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# % POSSIBILITY OF SUCH DAMAGE.
#
#
###############################################################################
#
# $Id$
# 
###############################################################################

##	PROOT	= /silo/cons/verkaufpsl

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
	$(PL)/disassemble.b $(PL)/fc-indirect.b $(PL)/get-options.b \
	$(PL)/l2cdatacon.b $(PL)/helferlein.b $(PL)/symget.b \
	$(PL)/nbig32.b $(PL)/nbig32a.b $(PL)/double32.b \
	$(PL)/qualified-timing.b $(PL)/spy.b 

# MODEL should be either AREGMODEL for 3.2 or DREGMODEL for 3.4.
MODEL   = DREGMODEL

$(PL)/c2l.o: $(PXU)/c2l.c
	$(CC) -D$(MODEL) -D$(MACHINE) -S c2l.c
	sed 's/_SYM/SYM/g' c2l.s > c2ltemp.s
	rm -f c2l.s
	as c2ltemp.s -o $(PL)/c2l.o
	rm -f c2ltemp.s

$(PL)/fc-indirect.b: $(PXU)/fc-indirect.sl
	$(PDIST)/make-lap $(PXU) fc-indirect

$(PL)/get-options.b: $(PXU)/get-options.sl
	$(PDIST)/make-lap $(PXU) get-options

$(PL)/l2cdatacon.b: $(PXU)/l2cdatacon.sl
	$(PDIST)/make-lap $(PXU) l2cdatacon

$(PL)/helferlein.b: $(PXU)/helferlein.sl $(PL)/inum.b
	$(PDIST)/make-lap $(PXU) helferlein

$(PL)/symget.b:  $(PXU)/symget.sl
	$(PDIST)/make-lap $(PXU) symget

$(PL)/spy.b: $(PXU)/spy.sl
	$(PDIST)/make-lap $(PXU) spy

$(PL)/qualified-timing.b: $(PXU)/qualified-timing.sl
	$(PDIST)/make-lap $(PXU) qualified-timing

$(PL)/oload.b: $(PXU)/oload.sl
	$(PDIST)/make-lap $(PXU) oload

$(PL)/nbig32.b:  $(PXU)/nbig32.sl
	$(PDIST)/make-lap $(PXU) nbig32

$(PL)/nbig32a.b: $(PXU)/nbig32a.sl $(PL)/vfvect.b $(PL)/muls32.b $(PL)/double32.b \
           $(PL)/fast-vector.b
	$(PDIST)/make-lap $(PXU) nbig32a

$(PL)/double32.b: $(PL)/muls32.b
	$(PDIST)/make-lap $(PXU) double32

$(PL)/disassemble.b: $(PXU)/disassemble.sl
	$(PDIST)/make-lap $(PXU) disassemble
#

$(PL)/inum.b: $(PU)/inum.sl
	(cd $(PU) ; make $(MFLAGS) MACHINE=$(MACHINE) $(PL)/inum.b)

$(PL)/vfvect.b: $(PXU)/vfvect.sl
	$(PDIST)/make-lap $(PXU) vfvect
 
$(PL)/muls.b: $(PXC)/muls.sl
	(cd $(PXC) ; make $(MFLAGS) MACHINE=$(MACHINE) $(PL)/muls.b)
 
$(PL)/muls32.b: $(PXU)/muls32.sl
	$(PDIST)/make-lap $(PXU) muls32

$(PL)/syslisp.b: $(PU)/syslisp.sl
	(cd $(PU) ; make $(MFLAGS) MACHINE=$(MACHINE) $(PL)/syslisp.b)

# Nothing needs to be done, but it needs to be here to interact with the
#  top level Makefile.
clean:


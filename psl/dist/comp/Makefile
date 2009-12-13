###############################################################################
#
# File:         PC:Makefile
# Description:  Makefile for psl compiler system dependent modules.
# Author:       Harold Carr and Leigh Stoller.
# Created:      08-Oct-86
# Modified:
# Mode:         Text
# Package:      
# Status:
#
# (c) Copyright 1982, University of Utah
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
#    * Redistributions of source code must retain the relevant copyright
#      notice, this list of conditions and the following disclaimer.
#    * Redistributions in binary form must reproduce the above copyright
#      notice, this list of conditions and the following disclaimer in the
#      documentation and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
# THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR
# CONTRIBUTORS
# BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#
###############################################################################
#
# 
###############################################################################

PROOT	= /newsilo/silo/cons/verkaufpsl

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
	$(PL)/big-faslend.b \
	$(PL)/datamachine.b \
	$(PL)/faslout.b \
	$(PL)/lap-to-asm.b \
	$(PL)/pass-1.b \
	$(PL)/p1-decls.b \
	$(PL)/pass-1-lap.b \
	$(PL)/pass-2-3.b \
	$(PL)/putprint.b \
	$(PL)/carcdrnil.b \
	$(PL)/comasm.b \
	$(PL)/pslcomp.b

$(PL)/big-faslend.b: $(PC)/big-faslend.sl
	$(PDIST)/make-lap $(PC) big-faslend

$(PL)/datamachine.b: $(PC)/datamachine.sl \
	$(PL)/sys-consts.b $(PL)/sys-dm.b $(PL)/if-system.b
	$(PDIST)/make-lap $(PC) datamachine

$(PL)/faslout.b: $(PC)/faslout.sl \
	$(PL)/fasl-decls.b $(PL)/fast-vector.b
	$(PDIST)/make-lap $(PC) faslout

$(PL)/lap-to-asm.b: $(PC)/lap-to-asm.sl
	$(PDIST)/make-lap $(PC) lap-to-asm

$(PL)/pass-1.b: $(PC)/pass-1.sl	$(PL)/p1-decls.b $(PL)/if-system.b \
	$(PL)/strings.b
	$(PDIST)/make-lap $(PC) pass-1

$(PL)/p1-decls.b: $(PC)/p1-decls.sl
	$(PDIST)/make-lap $(PC) p1-decls

$(PL)/pass-1-lap.b: $(PC)/pass-1-lap.sl \
	$(PC)/anyreg-cmac.sl $(PC)/cmacros.sl \
	$(PC)/predicates.sl \
	$(PL)/fast-vector.b 
	$(PDIST)/make-lap $(PC) pass-1-lap

$(PL)/pass-2-3.b: $(PC)/pass-2-3.sl
	$(PDIST)/make-lap $(PC) pass-2-3

$(PL)/putprint.b: $(PC)/putprint.sl
	$(PDIST)/make-lap $(PC) putprint

$(PL)/carcdrnil.b: $(PC)/carcdrnil.sl
	$(PDIST)/make-lap $(PC) carcdrnil

$(PL)/comasm.b: $(PC)/comasm.sl
	$(PDIST)/make-lap $(PC) comasm

$(PL)/pslcomp.b: $(PC)/pslcomp.sl
	$(PDIST)/make-lap $(PC) pslcomp


# The dependencies

$(PL)/if-system.b: $(PU)/if-system.sl 
	(cd $(PU) ; make $(MFLAGS) MACHINE=$(MACHINE) $(PL)/if-system.b)

$(PL)/fasl-decls.b: $(PXK)/fasl-decls.sl 
	(cd $(PXK) ; make $(MFLAGS)MACHINE=$(MACHINE)  $(PL)/fasl-decls.b)

$(PL)/fast-vector.b: $(PU)/fast-vector.sl
	(cd $(PU) ; make $(MFLAGS) MACHINE=$(MACHINE) $(PL)/fast-vector.b)

$(PL)/strings.b: $(PU)/strings.sl
	(cd $(PU) ; make $(MFLAGS) MACHINE=$(MACHINE) $(PL)/strings.b)

$(PL)/sys-consts.b: $(PXC)/sys-consts.sl
	(cd $(PXC) ; make $(MFLAGS) MACHINE=$(MACHINE) $(PL)/sys-consts.b)

$(PL)/sys-dm.b: $(PXC)/sys-dm.sl
	(cd $(PXC) ; make $(MFLAGS) MACHINE=$(MACHINE) $(PL)/sys-dm.b)

# End of file.

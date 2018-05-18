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

# PROOT   = `pwd`
PROOT	=  $(proot)

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
	$(PL)/armv6-asm.b \
	$(PL)/armv6-cmac.b \
	$(PL)/armv6-comp.b \
	$(PL)/armv6-lap.b \
	$(PL)/armv6-lap-to-asm.b $(PL)/nbittab.b \
	$(PL)/carcdrnil.b \
	$(PL)/compiler.b \
	$(PL)/comp-decls.b \
	$(PL)/sys-consts.b \
	$(PL)/sys-dm.b \
	$(PL)/armv6-spec.b \
	$(PL)/muls.b \
	$(PL)/tags.b

$(PL)/armv6-asm.b: $(PXC)/armv6-asm.sl $(PL)/if-system.b
	$(PDIST)/make-lap $(PXC) armv6-asm

$(PL)/armv6-cmac.b: $(PXC)/armv6-cmac.sl $(PL)/if-system.b
	$(PDIST)/make-lap $(PXC) armv6-cmac

$(PL)/armv6-comp.b: $(PXC)/armv6-comp.sl
	$(PDIST)/make-lap $(PXC) armv6-comp

$(PL)/armv6-lap.b: $(PXC)/armv6-lap.sl $(PL)/fasl-decls.b
	$(PDIST)/make-lap $(PXC) armv6-lap

$(PL)/armv6-lap-to-asm.b: $(PXC)/armv6-lap-to-asm.sl
	$(PDIST)/make-lap $(PXC) armv6-lap-to-asm

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

$(PL)/armv6-spec.b: $(PXC)/armv6-spec.sl
	$(PDIST)/make-lap $(PXC) armv6-spec

$(PL)/muls.b: $(PXC)/muls.sl 
	$(PDIST)/make-lap $(PXC) muls


##

$(PL)/fasl-decls.b: $(PXK)/fasl-decls.sl
	(cd $(PXK); make $(MFLAGS) MACHINE=$(MACHINE) $(PL)/fasl-decls.b)

$(PL)/if-system.b: $(PU)/if-system.sl
	(cd $(PU); make $(MFLAGS) MACHINE=$(MACHINE) $(PL)/if-system.b)

# End of file.

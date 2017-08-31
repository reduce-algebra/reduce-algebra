###############################################################################
#
# File:         PXU:Makefile
# Description:  Makefile for psl vax specific utilities directory.
# Author:       Harold Carr and Leigh Stoller.
# Created:      08-Oct-86
# Modified:
# Mode:         Text
# Package:      
# Status:
#
#% (c) Copyright 1982, University of Utah
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

PSL     = $(PROOT)/dist
PSYS    = $(PROOT)/bin
PK      = $(PSL)/kernel
PXK     = $(PK)/$(MACHINE)
PNK     = $(PSL)/nonkernel
PXNK    = $(PNK)/$(MACHINE)
PNKL    = $(PSL)/nonkernel/$(MACHINE)/lap
PC      = $(PSL)/comp
PXC     = $(PC)/$(MACHINE)
PU      = $(PSL)/util
PXU     = $(PU)/$(MACHINE)
PDIST   = $(PSL)/distrib
PXDIST  = $(PDIST)/$(MACHINE)
PL      = $(PSL)/lap/$(MACHINE)

all: \
	$(PL)/fc-indirect.b $(PL)/get-options.b \
	$(PL)/defmacro.b $(PL)/def1macro.b $(PL)/def2macro.b \
	$(PL)/disassemble.b \
	$(PL)/fastload.b $(PL)/muls32.b \
	$(PL)/l2cdatacon.b $(PL)/helferlein.b $(PL)/symget.b \
	$(PL)/nbig32.b $(PL)/double32.b \
	$(PL)/nbig32a.b $(PL)/quotx32.b \
	$(PL)/w-pipes.b  $(PL)/mathlib.b \
	$(PL)/mbarith.b $(PL)/mbarith-woco.b $(PL)/arith387.b \
	$(PL)/memio.b $(PL)/termio.b \
	$(PL)/make.b $(PL)/du.b \
	$(PL)/qualtime.b $(PL)/qualcount.b
	echo "UTIL frisch"


$(PL)/fc-indirect.b: $(PXU)/fc-indirect.sl
	$(PDIST)/make-lap $(PXU) fc-indirect

$(PL)/fastload.b: $(PXU)/fastload.sl
	$(PDIST)/make-lap $(PXU) fastload

$(PL)/get-options.b: $(PXU)/get-options.sl
	$(PDIST)/make-lap $(PXU) get-options

$(PL)/l2cdatacon.b: $(PXU)/l2cdatacon.sl
	$(PDIST)/make-lap $(PXU) l2cdatacon

$(PL)/helferlein.b: $(PXU)/helferlein.sl $(PL)/inum.b
	$(PDIST)/make-lap $(PXU) helferlein

$(PL)/symget.b:  $(PXU)/symget.sl
	$(PDIST)/make-lap $(PXU) symget

$(PL)/qualtime.b: $(PXU)/qualtime.sl
	$(PDIST)/make-lap $(PXU) qualtime

$(PL)/qualcount.b: $(PXU)/qualcount.sl
	$(PDIST)/make-lap $(PXU) qualcount

$(PL)/make.b: $(PXU)/make.sl
	$(PDIST)/make-lap $(PXU) make

$(PL)/mathlib.b: $(PXU)/mathlib.sl
	$(PDIST)/make-lap $(PXU) mathlib

$(PL)/muls32.b: $(PXU)/muls32.sl
	$(PDIST)/make-lap $(PXU) muls32

$(PL)/du.b: $(PXU)/du.sl
	$(PDIST)/make-lap $(PXU) du

$(PL)/nbig32.b:  $(PXU)/nbig32.sl
	$(PDIST)/make-lap $(PXU) nbig32

$(PL)/nbig32a.b: $(PXU)/nbig32a.sl $(PL)/vfvect.b $(PL)/muls.b $(PL)/double.b \
	   $(PL)/fast-vector.b
	$(PDIST)/make-lap $(PXU) nbig32a

$(PL)/double32.b: $(PXU)/double32.sl $(PL)/muls32.b
	$(PDIST)/make-lap $(PXU) double32

$(PL)/quotx32.b: $(PU)/quotx32.sl
	$(PDIST)/make-lap $(PU) quotx32

$(PL)/mbarith.b: $(PXU)/mbarith.sl $(PL)/muls.b
	$(PDIST)/make-lap $(PXU) mbarith

$(PL)/arith387.b: $(PXU)/arith387.sl
	$(PDIST)/make-lap $(PXU) arith387

$(PL)/mbarith-woco.b: $(PXU)/mbarith.sl $(PL)/muls.b $(PL)/mbarith.b
	copy $(PL)/mbarith.b $(PL)/mbarith-woco.b

$(PL)/memio.b: $(PXU)/memio.sl
	$(PDIST)/make-lap $(PXU) memio

$(PL)/termio.b: $(PXU)/termio.sl
	$(PDIST)/make-lap $(PXU) termio

$(PL)/w-pipes.b: $(PXU)/w-pipes.sl
	$(PDIST)/make-lap $(PXU) w-pipes



#

$(PL)/inum.b: $(PU)/inum.sl
	(cd $(PU) ; make $(PL)/inum.b)

$(PL)/vfvect.b: $(PXU)/vfvect.sl
	$(PDIST)/make-lap $(PXU) vfvect
 
$(PL)/muls.b: $(PXC)/muls.sl
	(cd $(PXC) ; make $(PL)/muls.b)

$(PL)/syslisp.b: $(PU)/syslisp.sl
	(cd $(PU) ; make $(PL)/syslisp.b)

$(PL)/defmacro.b: $(PXU)/defmacro.sl $(PL)/def1macro.b $(PL)/def2macro.b
	$(PDIST)/make-lap $(PXU) defmacro

$(PL)/def1macro.b: $(PXU)/def1macro.sl $(PL)/backquote.b $(PL)/read-macros.b
	$(PDIST)/make-lap $(PXU) def1macro

$(PL)/def2macro.b: $(PXU)/def2macro.sl \
    $(PL)/backquote.b $(PL)/def1macro.b $(PL)/read-macros.b
	$(PDIST)/make-lap $(PXU) def2macro

$(PL)/disassemble.b: $(PXU)/disassemble.sl 
	$(PDIST)/make-lap $(PXU) disassemble

# Nothing needs to be done, but it needs to be here to interact with the
#  top level Makefile.

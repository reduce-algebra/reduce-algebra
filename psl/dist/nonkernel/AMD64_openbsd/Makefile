###############################################################################
#
# File:         PXNK:Makefile
# Description:  Makefile for psl nonkernel system dependent modules.
# Author:       Harold Carr and Leigh Stoller.
# Created:      08-Oct-86
# Modified:
# Mode:         Text
# Package:      
# Status:
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
# 20-SEP-89 (Winfried Neun)
#  initial version for sun386
# 
###############################################################################
#
# $Id: Makefile 6307 2022-05-11 15:35:54Z schoepf $
#
###############################################################################

## PROOT	= /home/cons/reducedev/free_reduce/reduce-algebra/trunk/psl

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

PXNKFILES= \
	$(PNKL)/dumplisp.b  $(PNKL)/copying-gc.b $(PNKL)/funct-prims.b $(PNKL)/ieee-decls.b \
	$(PNKL)/io-data.b $(PNKL)/lap.b $(PNKL)/load-psl.b $(PNKL)/putd-getd.b \
	$(PNKL)/arithmetic.b $(PNKL)/backtrace.b $(PNKL)/printf.b $(PNKL)/fixup.b \
	$(PNKL)/allocators.b $(PNKL)/binding.b $(PNKL)/386-ext.b \
	$(PNKL)/scan-table.b $(PNKL)/sys-date.b $(PNKL)/sys-extras.b \
	$(PNKL)/sys-faslin.b $(PNKL)/sys-gc.b $(PNKL)/sys-io.b \
	$(PNKL)/static-gc.b $(PNKL)/catch-throw.b \
	$(PNKL)/timc.b $(PNKL)/trap.b $(PNKL)/write-float.b $(PNKL)/wfloat.b

all: $(PXNKFILES)
	echo "System dependent files built."

$(PNKL)/386-ext.b: $(PXNK)/386-ext.sl
	$(PDIST)/make-pnk-lap $(PXNK) 386-ext

$(PNKL)/dumplisp.b: $(PXNK)/dumplisp.sl
	$(PDIST)/make-pnk-lap $(PXNK) dumplisp

$(PNKL)/backtrace.b: $(PXNK)/backtrace.sl
	$(PDIST)/make-pnk-lap $(PXNK) backtrace

$(PNKL)/binding.b: $(PXNK)/binding.sl
	$(PDIST)/make-pnk-lap $(PXNK) binding

$(PNKL)/catch-throw.b: $(PXNK)/catch-throw.sl
	$(PDIST)/make-pnk-lap $(PXNK) catch-throw

$(PNKL)/ieee-decls.b: $(PXNK)/ieee-decls.sl  $(PL)/if-system.b
	$(PDIST)/make-pnk-lap $(PXNK) ieee-decls

$(PNKL)/io-data.b: $(PXNK)/io-data.sl $(PNKL)/io-decls.b $(PL)/sys-macros.b
	$(PDIST)/make-pnk-lap $(PXNK) io-data

$(PNKL)/lap.b: $(PXNK)/lap.sl
	$(PDIST)/make-pnk-lap $(PXNK) lap

$(PNKL)/load-psl.b: $(PXNK)/load-psl.sl
	$(PDIST)/make-pnk-lap $(PXNK) load-psl

$(PNKL)/putd-getd.b: $(PXNK)/putd-getd.sl
	$(PDIST)/make-pnk-lap $(PXNK) putd-getd

$(PNKL)/scan-table.b: $(PXNK)/scan-table.sl
	$(PDIST)/make-pnk-lap $(PXNK) scan-table

$(PNKL)/sys-date.b: $(PXNK)/sys-date.sl $(PL)/sys-macros.b
	$(PDIST)/make-pnk-lap $(PXNK) sys-date

$(PNKL)/sys-extras.b: $(PXNK)/sys-extras.sl $(PL)/sys-macros.b
	$(PDIST)/make-pnk-lap $(PXNK) sys-extras

$(PNKL)/sys-faslin.b: $(PXNK)/sys-faslin.sl $(PL)/fasl-decls.b
	$(PDIST)/make-pnk-lap $(PXNK) sys-faslin

#$(PNKL)/sys-faslout.b: $(PXNK)/sys-faslout.sl
#	$(PDIST)/make-pnk-lap $(PXNK) sys-faslout

$(PNKL)/sys-gc.b: $(PXNK)/sys-gc.sl
	$(PDIST)/make-pnk-lap $(PXNK) sys-gc

$(PNKL)/sys-io.b: $(PXNK)/sys-io.sl $(PNKL)/io-decls.b
	$(PDIST)/make-pnk-lap $(PXNK) sys-io

$(PNKL)/timc.b: $(PXNK)/timc.sl $(PL)/sys-macros.b
	$(PDIST)/make-pnk-lap $(PXNK) timc

$(PNKL)/trap.b: $(PXNK)/trap.sl
	$(PDIST)/make-pnk-lap $(PXNK) trap

$(PNKL)/write-float.b: $(PXNK)/write-float.sl
	$(PDIST)/make-pnk-lap $(PXNK) write-float

$(PNKL)/sun4-nk-spec.b: $(PXNK)/sun4-nk-spec.sl
	$(PDIST)/make-pnk-lap $(PXNK) sun4-nk-spec

$(PNKL)/allocators.b: $(PXNK)/allocators.sl $(PL)/if-system.b
	$(PDIST)/make-pnk-lap $(PXNK) allocators

$(PNKL)/arithmetic.b: $(PXNK)/arithmetic.sl $(PL)/if-system.b $(PL)/sys-macros.b
	$(PDIST)/make-pnk-lap $(PXNK) arithmetic

$(PNKL)/static-gc.b: $(PXNK)/static-gc.sl
	$(PDIST)/make-pnk-lap $(PXNK) static-gc

$(PNKL)/base-io.b: $(PXNK)/base-io.sl $(PL)/if-system.b $(PNKL)/io-decls.b
	$(PDIST)/make-pnk-lap $(PXNK) base-io
 
$(PNKL)/copiers.b: $(PXNK)/copiers.sl
	$(PDIST)/make-pnk-lap $(PXNK) copiers

$(PNKL)/printf.b: $(PXNK)/printf.sl $(PL)/if-system.b $(PNKL)/token-decls.b
	$(PDIST)/make-pnk-lap $(PXNK) printf

$(PNKL)/symbol-vals.b: $(PXNK)/symbol-vals.sl
	$(PDIST)/make-pnk-lap $(PXNK) symbol-vals

 
##

#$(PNKL)/compact-gc.b: $(PXNK)/compact-gc.sl
#	$(PDIST)/make-pnk-lap $(PXNK) compact-gc

$(PNKL)/funct-prims.b: $(PXNK)/funct-prims.sl
	$(PDIST)/make-pnk-lap $(PXNK) funct-prims

$(PNKL)/fixup.b: $(PXNK)/fixup.sl
	$(PDIST)/make-pnk-lap $(PXNK) fixup

$(PNKL)/wfloat.b: $(PXNK)/wfloat.sl
	$(PDIST)/make-pnk-lap $(PXNK) wfloat

$(PNKL)/copying-gc.b: $(PXNK)/copying-gc.sl $(PL)/hash-decls.b $(PL)/if-system.b
	$(PDIST)/make-pnk-lap $(PXNK) copying-gc
  
##
$(PL)/hash-decls.b: $(PK)/hash-decls.sl
	(cd $(PXK) ; make $(MFLAGS) MACHINE=$(MACHINE) $(PL)/hash-decls.b)

$(PL)/fasl-decls.b: $(PXK)/fasl-decls.sl
	(cd $(PXK); make $(MFLAGS) $(PL)/fasl-decls.b)

$(PNKL)/io-decls.b: $(PXNK)/io-decls.sl
	$(PDIST)/make-pnk-lap $(PXNK) io-decls

$(PL)/sys-macros.b: $(PU)/sys-macros.sl
	(cd $(PU);  make $(MFLAGS) $(PL)/sys-macros.b)

$(PNKL)/token-decls.b: $(PNK)/token-decls.sl
	(cd $(PNK); make $(MFLAGS) $(PNKL)/token-decls.b)

clean:
	rm -f $(PXNKFILES)

# End of file.

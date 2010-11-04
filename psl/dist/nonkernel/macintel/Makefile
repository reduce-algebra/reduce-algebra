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
###############################################################################
#
# 20-SEP-89 (Winfried Neun)
#  initial version for sun386
# 
###############################################################################

PROOT	= /silo/cons/verkaufpsl

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
	$(PNKL)/dumplisp.b  $(PNKL)/copying-gc.b $(PNKL)/funct-prims.b \
	$(PNKL)/io-data.b $(PNKL)/lap.b $(PNKL)/load-psl.b $(PNKL)/putd-getd.b \
	$(PNKL)/arithmetic.b $(PNKL)/backtrace.b $(PNKL)/printf.b $(PNKL)/fixup.b \
	$(PNKL)/allocators.b $(PNKL)/binding.b $(PNKL)/386-ext.b \
	$(PNKL)/scan-table.b $(PNKL)/sys-date.b $(PNKL)/sys-extras.b \
	$(PNKL)/sys-faslin.b $(PNKL)/sys-gc.b $(PNKL)/sys-io.b \
	$(PNKL)/static-gc.b \
	$(PNKL)/timc.b $(PNKL)/trap.b $(PNKL)/write-float.b $(PNKL)/wfloat.b

all: $(PXNKFILES)
	echo "System dependent files built."

$(PNKL)/386-ext.b: $(PXNK)/386-ext.sl
	$(PDIST)/make-pnk-lap.bsh $(PXNK) 386-ext

$(PNKL)/dumplisp.b: $(PXNK)/dumplisp.sl
	$(PDIST)/make-pnk-lap.bsh $(PXNK) dumplisp

$(PNKL)/backtrace.b: $(PXNK)/backtrace.sl
	$(PDIST)/make-pnk-lap.bsh $(PXNK) backtrace

$(PNKL)/binding.b: $(PXNK)/binding.sl
	$(PDIST)/make-pnk-lap.bsh $(PXNK) binding

$(PNKL)/io-data.b: $(PXNK)/io-data.sl $(PNKL)/io-decls.b $(PL)/sys-macros.b
	$(PDIST)/make-pnk-lap.bsh $(PXNK) io-data

$(PNKL)/lap.b: $(PXNK)/lap.sl
	$(PDIST)/make-pnk-lap.bsh $(PXNK) lap

$(PNKL)/load-psl.b: $(PXNK)/load-psl.sl
	$(PDIST)/make-pnk-lap.bsh $(PXNK) load-psl

$(PNKL)/putd-getd.b: $(PXNK)/putd-getd.sl
	$(PDIST)/make-pnk-lap.bsh $(PXNK) putd-getd

$(PNKL)/scan-table.b: $(PXNK)/scan-table.sl
	$(PDIST)/make-pnk-lap.bsh $(PXNK) scan-table

$(PNKL)/sys-date.b: $(PXNK)/sys-date.sl $(PL)/sys-macros.b
	$(PDIST)/make-pnk-lap.bsh $(PXNK) sys-date

$(PNKL)/sys-extras.b: $(PXNK)/sys-extras.sl $(PL)/sys-macros.b
	$(PDIST)/make-pnk-lap.bsh $(PXNK) sys-extras

$(PNKL)/sys-faslin.b: $(PXNK)/sys-faslin.sl $(PL)/fasl-decls.b
	$(PDIST)/make-pnk-lap.bsh $(PXNK) sys-faslin

#$(PNKL)/sys-faslout.b: $(PXNK)/sys-faslout.sl
#	$(PDIST)/make-pnk-lap.bsh $(PXNK) sys-faslout

$(PNKL)/sys-gc.b: $(PXNK)/sys-gc.sl
	$(PDIST)/make-pnk-lap.bsh $(PXNK) sys-gc

$(PNKL)/sys-io.b: $(PXNK)/sys-io.sl $(PNKL)/io-decls.b
	$(PDIST)/make-pnk-lap.bsh $(PXNK) sys-io

$(PNKL)/timc.b: $(PXNK)/timc.sl $(PL)/sys-macros.b
	$(PDIST)/make-pnk-lap.bsh $(PXNK) timc

$(PNKL)/trap.b: $(PXNK)/trap.sl
	$(PDIST)/make-pnk-lap.bsh $(PXNK) trap

$(PNKL)/write-float.b: $(PXNK)/write-float.sl
	$(PDIST)/make-pnk-lap.bsh $(PXNK) write-float

$(PNKL)/sun4-nk-spec.b: $(PXNK)/sun4-nk-spec.sl
	$(PDIST)/make-pnk-lap.bsh $(PXNK) sun4-nk-spec

$(PNKL)/allocators.b: $(PXNK)/allocators.sl $(PL)/if-system.b
	$(PDIST)/make-pnk-lap.bsh $(PXNK) allocators

$(PNKL)/arithmetic.b: $(PXNK)/arithmetic.sl $(PL)/if-system.b $(PL)/sys-macros.b
	$(PDIST)/make-pnk-lap.bsh $(PXNK) arithmetic

$(PNKL)/static-gc.b: $(PXNK)/static-gc.sl
	$(PDIST)/make-pnk-lap.bsh $(PXNK) static-gc

$(PNKL)/base-io.b: $(PXNK)/base-io.sl $(PL)/if-system.b $(PNKL)/io-decls.b
	$(PDIST)/make-pnk-lap.bsh $(PXNK) base-io
 
$(PNKL)/catch-throw.b: $(PXNK)/catch-throw.sl $(PL)/if-system.b	
	$(PDIST)/make-pnk-lap.bsh $(PXNK) catch-throw

$(PNKL)/copiers.b: $(PXNK)/copiers.sl
	$(PDIST)/make-pnk-lap.bsh $(PXNK) copiers

$(PNKL)/printf.b: $(PXNK)/printf.sl $(PL)/if-system.b $(PNKL)/token-decls.b
	$(PDIST)/make-pnk-lap.bsh $(PXNK) printf

$(PNKL)/symbol-vals.b: $(PXNK)/symbol-vals.sl
	$(PDIST)/make-pnk-lap.bsh $(PXNK) symbol-vals

 
##

#$(PNKL)/compact-gc.b: $(PXNK)/compact-gc.sl
#	$(PDIST)/make-pnk-lap.bsh $(PXNK) compact-gc

$(PNKL)/funct-prims.b: $(PXNK)/funct-prims.sl
	$(PDIST)/make-pnk-lap.bsh $(PXNK) funct-prims

$(PNKL)/fixup.b: $(PXNK)/fixup.sl
	$(PDIST)/make-pnk-lap.bsh $(PXNK) fixup

$(PNKL)/wfloat.b: $(PXNK)/wfloat.sl
	$(PDIST)/make-pnk-lap.bsh $(PXNK) wfloat

$(PNKL)/copying-gc.b: $(PXNK)/copying-gc.sl $(PL)/hash-decls.b $(PL)/if-system.b
	$(PDIST)/make-pnk-lap.bsh $(PXNK) copying-gc
  
##
$(PL)/hash-decls.b: $(PK)/hash-decls.sl
	(cd $(PXK) ; make $(MFLAGS) MACHINE=$(MACHINE) $(PL)/hash-decls.b)

$(PL)/fasl-decls.b: $(PXK)/fasl-decls.sl
	(cd $(PXK); make $(MFLAGS) $(PL)/fasl-decls.b)

$(PNKL)/io-decls.b: $(PXNK)/io-decls.sl
	$(PDIST)/make-pnk-lap.bsh $(PXNK) io-decls

$(PL)/sys-macros.b: $(PU)/sys-macros.sl
	(cd $(PU);  make $(MFLAGS) $(PL)/sys-macros.b)

$(PNKL)/token-decls.b: $(PNK)/token-decls.sl
	(cd $(PNK); make $(MFLAGS) $(PNKL)/token-decls.b)

clean:
	rm -f $(PXNKFILES)

# End of file.

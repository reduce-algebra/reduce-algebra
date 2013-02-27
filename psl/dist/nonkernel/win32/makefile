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
## (c) Copyright 1982, University of Utah
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
# 20-MAR-90 (Winfried Neun)
#  initial version for DOS386
# 
###############################################################################
MACHINE = winnt
PROOT   = $(PSL)

PSL     = $(PROOT)
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
PL      = $(PSL)/lap

PXNKFILES= \
	$(PNKL)/dumplisp.b  $(PNKL)/static-gc.b $(PNKL)/funct-prims.b \
	$(PNKL)/io-data.b $(PNKL)/lap.b $(PNKL)/load-psl.b \
	$(PNKL)/backtrace.b $(PNKL)/equal.b $(PNKL)/386-ext.b \
	$(PNKL)/arithmetic.b $(PNKL)/putd-getd.b \
	$(PNKL)/printf.b $(PNKL)/fixup.b $(PNKL)/eval-apply.b \
	$(PNKL)/arithwoc.b \
	$(PNKL)/symbol-vals.b \
	$(PNKL)/allocators.b $(PNKL)/binding.b $(PNKL)/other-io.b \
	$(PNKL)/scan-table.b $(PNKL)/sys-date.b $(PNKL)/sys-extras.b \
	$(PNKL)/sys-faslin.b $(PNKL)/sys-gc.b $(PNKL)/sys-io.b \
	$(PNKL)/wfloat-w.b \
	$(PNKL)/timc.b $(PNKL)/trap.b $(PNKL)/write-fl.b $(PNKL)/wfloat.b

all: $(PXNKFILES)
	echo "System dependent files built."

$(PNKL)/386-ext.b: $(PXNK)/386-ext.sl
	$(PDIST)/mkpnknt $(PXNK) 386-ext

$(PNKL)/dumplisp.b: $(PXNK)/dumplisp.sl
	$(PDIST)/mkpnknt $(PXNK) dumplisp

$(PNKL)/binding.b: $(PXNK)/binding.sl
	$(PDIST)/mkpnknt $(PXNK) binding

$(PNKL)/backtrace.b: $(PXNK)/backtrace.sl
	$(PDIST)/mkpnknt $(PXNK) backtrace

$(PNKL)/eval-apply.b: $(PXNK)/eval-apply.sl
	$(PDIST)/mkpnknt $(PXNK) eval-apply

$(PNKL)/io-data.b: $(PXNK)/io-data.sl $(PNKL)/io-decls.b $(PL)/sys-macros.b
	$(PDIST)/mkpnknt $(PXNK) io-data

$(PNKL)/lap.b: $(PXNK)/lap.sl
	$(PDIST)/mkpnknt $(PXNK) lap

$(PNKL)/load-psl.b: $(PXNK)/load-psl.sl
	$(PDIST)/mkpnknt $(PXNK) load-psl

$(PNKL)/other-io.b: $(PXNK)/other-io.sl
	$(PDIST)/mkpnknt $(PXNK) other-io

$(PNKL)/putd-getd.b: $(PXNK)/putd-getd.sl
	$(PDIST)/mkpnknt $(PXNK) putd-getd

$(PNKL)/scan-table.b: $(PXNK)/scan-table.sl
	$(PDIST)/mkpnknt $(PXNK) scan-table

$(PNKL)/sys-date.b: $(PXNK)/sys-date.sl $(PL)/sys-macros.b
	$(PDIST)/mkpnknt $(PXNK) sys-date

$(PNKL)/sys-extras.b: $(PXNK)/sys-extras.sl $(PL)/sys-macros.b
	$(PDIST)/mkpnknt $(PXNK) sys-extras

$(PNKL)/sys-faslin.b: $(PXNK)/sys-faslin.sl $(PL)/fasl-decls.b
	$(PDIST)/mkpnknt $(PXNK) sys-faslin

$(PNKL)/equal.b: $(PXNK)/equal.sl
	$(PDIST)/mkpnknt $(PXNK) equal

$(PNKL)/sys-gc.b: $(PXNK)/sys-gc.sl
	$(PDIST)/mkpnknt $(PXNK) sys-gc

$(PNKL)/sys-io.b: $(PXNK)/sys-io.sl $(PNKL)/io-decls.b
	$(PDIST)/mkpnknt $(PXNK) sys-io

$(PNKL)/timc.b: $(PXNK)/timc.sl $(PL)/sys-macros.b
	$(PDIST)/mkpnknt $(PXNK) timc

$(PNKL)/trap.b: $(PXNK)/trap.sl
	$(PDIST)/mkpnknt $(PXNK) trap

$(PNKL)/write-fl.b: $(PXNK)/write-fl.sl
	$(PDIST)/mkpnknt $(PXNK) write-fl

$(PNKL)/sun4-nk-spec.b: $(PXNK)/sun4-nk-spec.sl
	$(PDIST)/mkpnknt $(PXNK) sun4-nk-spec

$(PNKL)/allocators.b: $(PXNK)/allocators.sl $(PL)/if-system.b
	$(PDIST)/mkpnknt $(PXNK) allocators

$(PNKL)/arithmetic.b: $(PXNK)/arithmetic.sl $(PL)/if-system.b $(PL)/sys-macros.b
	$(PDIST)/mkpnknt $(PXNK) arithmetic

$(PNKL)/arithwoc.b: $(PXNK)/arithmetic.sl $(PL)/if-system.b $(PL)/sys-macros.b
	$(PDIST)/mkpnknt $(PXNK) arithwoc

$(PNKL)/backtrace.b: $(PXNK)/backtrace.sl
	$(PDIST)/mkpnknt $(PXNK) backtrace

$(PNKL)/base-io.b: $(PXNK)/base-io.sl $(PL)/if-system.b $(PNKL)/io-decls.b
	$(PDIST)/mkpnknt $(PXNK) base-io
 
$(PNKL)/catch-throw.b: $(PXNK)/catch-throw.sl $(PL)/if-system.b 
	$(PDIST)/mkpnknt $(PXNK) catch-throw

$(PNKL)/copiers.b: $(PXNK)/copiers.sl
	$(PDIST)/mkpnknt $(PXNK) copiers

$(PNKL)/printf.b: $(PXNK)/printf.sl $(PL)/if-system.b $(PNKL)/token-decls.b
	$(PDIST)/mkpnknt $(PXNK) printf

$(PNKL)/symbol-vals.b: $(PXNK)/symbol-vals.sl
	$(PDIST)/mkpnknt $(PXNK) symbol-vals

 
##

#$(PNKL)/compact-gc.b: $(PXNK)/compact-gc.sl
#       $(PDIST)/mkpnknt $(PXNK) compact-gc

$(PNKL)/funct-prims.b: $(PXNK)/funct-prims.sl
	$(PDIST)/mkpnknt $(PXNK) funct-prims

$(PNKL)/fixup.b: $(PXNK)/fixup.sl
	$(PDIST)/mkpnknt $(PXNK) fixup

$(PNKL)/wfloat.b: $(PXNK)/wfloat.sl
	$(PDIST)/mkpnknt $(PXNK) wfloat

$(PNKL)/wfloat-w.b: $(PXNK)/wfloat-w.sl
	$(PDIST)/mkpnknt $(PXNK) wfloat-w

$(PNKL)/static-gc.b: $(PXNK)/static-gc.sl $(PL)/hash-decls.b $(PL)/if-system.b
	$(PDIST)/mkpnknt $(PXNK) static-gc
  
##
$(PL)/hash-decls.b: $(PK)/hash-decls.sl
	(cd $(PXK) ; make $(MFLAGS) MACHINE=$(MACHINE) $(PL)/hash-decls.b)

$(PL)/fasl-decls.b: $(PXK)/fasl-decls.sl
	(cd $(PXK); make $(MFLAGS) $(PL)/fasl-decls.b)

$(PNKL)/io-decls.b: $(PXNK)/io-decls.sl
	$(PDIST)/mkpnknt $(PXNK) io-decls

$(PL)/sys-macros.b: $(PU)/sys-macros.sl
	(cd $(PU);  make $(MFLAGS) $(PL)/sys-macros.b)

$(PNKL)/token-decls.b: $(PNK)/token-decls.sl
      $(PDIST)/mkpnknt $(PNK) token-decls

clean:
	rm -f $(PXNKFILES)

# End of file.

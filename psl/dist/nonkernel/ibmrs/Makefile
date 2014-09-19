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
# (c) Copyright 1986, University of Utah, all rights reserved.
#
###############################################################################
#
# 06-APR-88 (Julian Padget)
#  changed PROOT, removed compact-gc from OTHER and fast-binder from PXNK
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

PXNKFILES= \
	$(PNKL)/allocators.b $(PNKL)/arithmetic.b $(PNKL)/backtrace.b \
	$(PNKL)/base-io.b $(PNKL)/binding.b $(PNKL)/catch-throw.b \
	$(PNKL)/copiers.b $(PNKL)/copying-gc.b $(PNKL)/printf.b \
	$(PNKL)/symbol-vals.b $(PNKL)/dumplisp.b  $(PNKL)/funct-prims.b \
	$(PNKL)/io-data.b $(PNKL)/lap.b $(PNKL)/load-psl.b \
	$(PNKL)/ibmrs-nk-spec.b $(PNKL)/putd-getd.b \
	$(PNKL)/scan-table.b $(PNKL)/sys-date.b $(PNKL)/sys-extras.b \
	$(PNKL)/sys-faslin.b $(PNKL)/sys-gc.b $(PNKL)/sys-io.b \
	$(PNKL)/timc.b $(PNKL)/trap.b $(PNKL)/write-float.b $(PNKL)/wfloat.b

# $(PNKL)/fast-binder.b

all: $(PXNKFILES)
	echo "System dependent files built."

$(PNKL)/allocators.b: $(PXNK)/allocators.sl $(PL)/if-system.b
	$(PDIST)/make-pnk-lap $(PXNK) allocators

$(PNKL)/arithmetic.b: $(PXNK)/arithmetic.sl $(PL)/if-system.b $(PL)/sys-macros.b
	$(PDIST)/make-pnk-lap $(PXNK) arithmetic

$(PNKL)/backtrace.b: $(PXNK)/backtrace.sl
	$(PDIST)/make-pnk-lap $(PXNK) backtrace

$(PNKL)/base-io.b: $(PXNK)/base-io.sl $(PL)/if-system.b $(PNKL)/io-decls.b
	$(PDIST)/make-pnk-lap $(PXNK) base-io

$(PNKL)/binding.b: $(PXNK)/binding.sl
	$(PDIST)/make-pnk-lap $(PXNK) binding

$(PNKL)/catch-throw.b: $(PXNK)/catch-throw.sl $(PL)/if-system.b
	$(PDIST)/make-pnk-lap $(PXNK) catch-throw

$(PNKL)/copiers.b: $(PXNK)/copiers.sl
	$(PDIST)/make-pnk-lap $(PNK) copiers

$(PNKL)/copying-gc.b: $(PXNK)/copying-gc.sl $(PL)/hash-decls.b $(PL)/if-system.b
	$(PDIST)/make-pnk-lap $(PXNK) copying-gc

$(PNKL)/symbol-vals.b: $(PXNK)/symbol-vals.sl
	$(PDIST)/make-pnk-lap $(PXNK) symbol-vals

$(PNKL)/dumplisp.b: $(PXNK)/dumplisp.sl
	$(PDIST)/make-pnk-lap $(PXNK) dumplisp

#$(PNKL)/fast-binder.b: $(PXNK)/fast-binder.sl
#        $(PDIST)/make-pnk-lap $(PXNK) fast-binder

$(PNKL)/io-data.b: $(PXNK)/io-data.sl $(PNKL)/io-decls.b $(PL)/sys-macros.b
	$(PDIST)/make-pnk-lap $(PXNK) io-data

$(PNKL)/lap.b: $(PXNK)/lap.sl
	$(PDIST)/make-pnk-lap $(PXNK) lap

$(PNKL)/load-psl.b: $(PXNK)/load-psl.sl
	$(PDIST)/make-pnk-lap $(PXNK) load-psl

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

$(PNKL)/ibmrs-nk-spec.b: $(PXNK)/ibmrs-nk-spec.sl
	$(PDIST)/make-pnk-lap $(PXNK) ibmrs-nk-spec
 
$(PNKL)/eval-apply.b: $(PXNK)/eval-apply.sl
	$(PDIST)/make-pnk-lap $(PXNK) eval-apply

$(PNKL)/putd-getd.b: $(PXNK)/putd-getd.sl
	$(PDIST)/make-pnk-lap $(PXNK) putd-getd
##

#$(PNKL)/compact-gc.b: $(PXNK)/compact-gc.sl
#	$(PDIST)/make-pnk-lap $(PXNK) compact-gc

$(PNKL)/funct-prims.b: $(PXNK)/funct-prims.sl $(PL)/if-system.b
	$(PDIST)/make-pnk-lap $(PXNK) funct-prims

#$(PNKL)/printf.b: $(PXNK)/printf.sl $(PNKL)/io-decls.b $(PNKL)/token-decls.b
#	$(PDIST)/make-pnk-lap $(PXNK) printf

$(PNKL)/printf.b: $(PXNK)/printf.sl $(PL)/if-system.b $(PNKL)/token-decls.b
	$(PDIST)/make-pnk-lap $(PXNK) printf

$(PNKL)/fixup.b: $(PXNK)/fixup.sl
	$(PDIST)/make-pnk-lap $(PXNK) fixup

$(PNKL)/wfloat.b: $(PXNK)/wfloat.sl
	$(PDIST)/make-pnk-lap $(PXNK) wfloat
  
##

$(PL)/fasl-decls.b: $(PXK)/fasl-decls.sl
	(cd $(PXK); make $(MFLAGS) $(PL)/fasl-decls.b)

$(PL)/hash-decls.b: $(PK)/hash-decls.sl
	$(PDIST)/make-lap $(PK) hash-decls

$(PNKL)/io-decls.b: $(PXNK)/io-decls.sl
	$(PDIST)/make-pnk-lap $(PXNK) io-decls

$(PL)/sys-macros.b: $(PU)/sys-macros.sl
	(cd $(PU);  make $(MFLAGS) $(PL)/sys-macros.b)

$(PNKL)/token-decls.b: $(PNK)/token-decls.sl
	(cd $(PNK); make $(MFLAGS) $(PNKL)/token-decls.b)

clean:
	rm -f $(PXNKFILES)

# End of file.

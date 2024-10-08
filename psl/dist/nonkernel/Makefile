###############################################################################
#
# File:         PNK:Makefile
# Description:  Makefile for psl nonkernel system independent modules.
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
# $Id$
# 
###############################################################################

# PROOT	= /home/cons/reducedev/free_reduce/reduce-algebra/trunk/psl

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

PNKFILES= \
	$(PNKL)/allocators.b $(PNKL)/apply-lap.b $(PNKL)/arithmetic.b \
	$(PNKL)/autoload-tr.b $(PNKL)/autoload.b $(PNKL)/backtrace.b \
	$(PNKL)/base-io.b $(PNKL)/binding.b $(PNKL)/break.b \
	$(PNKL)/carcdr.b $(PNKL)/catch-throw.b $(PNKL)/char-io.b \
	$(PNKL)/compsupport.b $(PNKL)/cons-mkvect.b $(PNKL)/constants.b \
	$(PNKL)/cont-error.b $(PNKL)/copiers.b $(PNKL)/copying-gc.b \
	$(PNKL)/def-smacro.b $(PNKL)/defconst.b $(PNKL)/dskin.b \
	$(PNKL)/easy-non-sl.b $(PNKL)/easy-sl.b $(PNKL)/environment.b \
	$(PNKL)/equal.b $(PNKL)/error-eset.b $(PNKL)/error-hand.b \
	$(PNKL)/eval-apply.b $(PNKL)/eval-when.b $(PNKL)/explode-com.b \
	$(PNKL)/fluid-globl.b $(PNKL)/funct-prims.b $(PNKL)/io-decls.b \
	$(PNKL)/io-errors.b $(PNKL)/io-extens.b $(PNKL)/knowntocomp.b \
	$(PNKL)/lisp-macros.b $(PNKL)/load.b $(PNKL)/loop-macros.b \
	$(PNKL)/oblist.b $(PNKL)/onoff.b $(PNKL)/open-close.b \
	$(PNKL)/other-io.b $(PNKL)/others-sl.b $(PNKL)/printers.b \
	$(PNKL)/printf.b $(PNKL)/prog-friend.b $(PNKL)/prop-list.b \
	$(PNKL)/putd-getd.b $(PNKL)/rds-wrs.b $(PNKL)/read.b \
	$(PNKL)/sequence.b $(PNKL)/sets.b \
	$(PNKL)/string-gen.b $(PNKL)/symbol-vals.b \
	$(PNKL)/token-decls.b $(PNKL)/token-scan.b $(PNKL)/top-loop.b \
	$(PNKL)/type-conver.b $(PNKL)/type-error.b $(PNKL)/vectors.b \
	$(PNKL)/unicode.b

all: $(PNKFILES)
	echo "System independent files built."

$(PNKL)/allocators.b: $(PNK)/allocators.sl $(PL)/if-system.b
	$(PDIST)/make-pnk-lap $(PNK) allocators

$(PNKL)/apply-lap.b: $(PNK)/apply-lap.sl $(PL)/sys-macros.b
	$(PDIST)/make-pnk-lap $(PNK) apply-lap

$(PNKL)/arithmetic.b: $(PNK)/arithmetic.sl $(PL)/if-system.b $(PL)/sys-macros.b
	$(PDIST)/make-pnk-lap $(PNK) arithmetic

$(PNKL)/autoload-tr.b: $(PNK)/autoload-tr.sl
	$(PDIST)/make-pnk-lap $(PNK) autoload-tr

$(PNKL)/autoload.b: $(PNK)/autoload.sl $(PL)/if-system.b
	$(PDIST)/make-pnk-lap $(PNK) autoload

$(PNKL)/backtrace.b: $(PNK)/backtrace.sl
	$(PDIST)/make-pnk-lap $(PNK) backtrace

$(PNKL)/base-io.b: $(PNK)/base-io.sl $(PL)/if-system.b $(PNKL)/io-decls.b
	$(PDIST)/make-pnk-lap $(PNK) base-io

$(PNKL)/binding.b: $(PXNK)/binding.sl
	$(PDIST)/make-pnk-lap $(PXNK) binding

$(PNKL)/break.b: $(PNK)/break.sl
	$(PDIST)/make-pnk-lap $(PNK) break

$(PNKL)/carcdr.b: $(PNK)/carcdr.sl
	$(PDIST)/make-pnk-lap $(PNK) carcdr

$(PNKL)/catch-throw.b: $(PNK)/catch-throw.sl $(PL)/if-system.b
	$(PDIST)/make-pnk-lap $(PNK) catch-throw

$(PNKL)/char-io.b: $(PNK)/char-io.sl $(PNKL)/io-decls.b
	$(PDIST)/make-pnk-lap $(PNK) char-io

$(PNKL)/compsupport.b: $(PNK)/compsupport.sl
	$(PDIST)/make-pnk-lap $(PNK) compsupport

$(PNKL)/cons-mkvect.b: $(PNK)/cons-mkvect.sl
	$(PDIST)/make-pnk-lap $(PNK) cons-mkvect

$(PNKL)/constants.b: $(PNK)/constants.sl
	$(PDIST)/make-pnk-lap $(PNK) constants

$(PNKL)/cont-error.b: $(PNK)/cont-error.sl
	$(PDIST)/make-pnk-lap $(PNK) cont-error

$(PNKL)/copiers.b: $(PNK)/copiers.sl
	$(PDIST)/make-pnk-lap $(PNK) copiers

$(PNKL)/copying-gc.b: $(PNK)/copying-gc.sl $(PL)/hash-decls.b $(PL)/if-system.b
	$(PDIST)/make-pnk-lap $(PNK) copying-gc

$(PNKL)/def-smacro.b: $(PNK)/def-smacro.sl
	$(PDIST)/make-pnk-lap $(PNK) def-smacro

$(PNKL)/defconst.b: $(PNK)/defconst.sl
	$(PDIST)/make-pnk-lap $(PNK) defconst

$(PNKL)/dskin.b: $(PNK)/dskin.sl
	$(PDIST)/make-pnk-lap $(PNK) dskin

$(PNKL)/easy-non-sl.b: $(PNK)/easy-non-sl.sl $(PL)/if-system.b
	$(PDIST)/make-pnk-lap $(PNK) easy-non-sl

$(PNKL)/easy-sl.b: $(PNK)/easy-sl.sl $(PL)/useful.b
	$(PDIST)/make-pnk-lap $(PNK) easy-sl

$(PNKL)/environment.b: $(PNK)/environment.sl
	$(PDIST)/make-pnk-lap $(PNK) environment

$(PNKL)/equal.b: $(PNK)/equal.sl $(PL)/if-system.b
	$(PDIST)/make-pnk-lap $(PNK) equal

$(PNKL)/error-eset.b: $(PNK)/error-eset.sl
	$(PDIST)/make-pnk-lap $(PNK) error-eset

$(PNKL)/error-hand.b: $(PNK)/error-hand.sl $(PL)/if-system.b
	$(PDIST)/make-pnk-lap $(PNK) error-hand

$(PNKL)/eval-apply.b: $(PNK)/eval-apply.sl
	$(PDIST)/make-pnk-lap $(PNK) eval-apply

$(PNKL)/eval-when.b: $(PNK)/eval-when.sl
	$(PDIST)/make-pnk-lap $(PNK) eval-when

$(PNKL)/explode-com.b: $(PNK)/explode-com.sl
	$(PDIST)/make-pnk-lap $(PNK) explode-com

$(PNKL)/fluid-globl.b: $(PNK)/fluid-globl.sl
	$(PDIST)/make-pnk-lap $(PNK) fluid-globl

$(PNKL)/funct-prims.b: $(PXNK)/funct-prims.sl $(PL)/if-system.b
	$(PDIST)/make-pnk-lap $(PXNK) funct-prims

$(PNKL)/io-decls.b: $(PNK)/io-decls.sl
	$(PDIST)/make-pnk-lap $(PNK) io-decls

$(PNKL)/io-errors.b: $(PNK)/io-errors.sl
	$(PDIST)/make-pnk-lap $(PNK) io-errors

$(PNKL)/io-extens.b: $(PNK)/io-extens.sl
	$(PDIST)/make-pnk-lap $(PNK) io-extens

$(PNKL)/knowntocomp.b: $(PNK)/knowntocomp.sl
	$(PDIST)/make-pnk-lap $(PNK) knowntocomp

$(PNKL)/lisp-macros.b: $(PNK)/lisp-macros.sl
	$(PDIST)/make-pnk-lap $(PNK) lisp-macros

$(PNKL)/load.b: $(PNK)/load.sl $(PL)/if-system.b
	$(PDIST)/make-pnk-lap $(PNK) load

$(PNKL)/loop-macros.b: $(PNK)/loop-macros.sl
	$(PDIST)/make-pnk-lap $(PNK) loop-macros

$(PNKL)/oblist.b: $(PNK)/oblist.sl $(PL)/hash-decls.b
	$(PDIST)/make-pnk-lap $(PNK) oblist

$(PNKL)/onoff.b: $(PNK)/onoff.sl
	$(PDIST)/make-pnk-lap $(PNK) onoff

$(PNKL)/open-close.b: $(PNK)/open-close.sl $(PNKL)/io-decls.b
	$(PDIST)/make-pnk-lap $(PNK) open-close

$(PNKL)/other-io.b: $(PNK)/other-io.sl $(PNKL)/io-decls.b
	$(PDIST)/make-pnk-lap $(PNK) other-io

$(PNKL)/others-sl.b: $(PNK)/others-sl.sl
	$(PDIST)/make-pnk-lap $(PNK) others-sl

$(PNKL)/printers.b: $(PNK)/printers.sl \
	$(PL)/if-system.b $(PNKL)/io-decls.b $(PL)/sys-macros.b \
	$(PNKL)/token-decls.b
	$(PDIST)/make-pnk-lap $(PNK) printers

$(PNKL)/printf.b: $(PNK)/printf.sl $(PL)/if-system.b $(PNKL)/token-decls.b
	$(PDIST)/make-pnk-lap $(PNK) printf

$(PNKL)/prog-friend.b: $(PNK)/prog-friend.sl
	$(PDIST)/make-pnk-lap $(PNK) prog-friend

$(PNKL)/prop-list.b: $(PNK)/prop-list.sl
	$(PDIST)/make-pnk-lap $(PNK) prop-list

$(PNKL)/putd-getd.b: $(PNK)/putd-getd.sl
	$(PDIST)/make-pnk-lap $(PNK) putd-getd

$(PNKL)/rds-wrs.b: $(PNK)/rds-wrs.sl $(PNKL)/io-decls.b
	$(PDIST)/make-pnk-lap $(PNK) rds-wrs

$(PNKL)/read.b: $(PNK)/read.sl
	$(PDIST)/make-pnk-lap $(PNK) read

$(PNKL)/sequence.b: $(PNK)/sequence.sl
	$(PDIST)/make-pnk-lap $(PNK) sequence

$(PNKL)/sets.b: $(PNK)/sets.sl
	$(PDIST)/make-pnk-lap $(PNK) sets

$(PNKL)/s-putd-getd.b: $(PNK)/s-putd-getd.sl
	$(PDIST)/make-pnk-lap $(PNK) s-putd-getd

$(PNKL)/short-getd.b: $(PNK)/short-getd.sl
	$(PDIST)/make-pnk-lap $(PNK) short-getd

$(PNKL)/string-gen.b: $(PNK)/string-gen.sl
	$(PDIST)/make-pnk-lap $(PNK) string-gen

$(PNKL)/symbol-vals.b: $(PNK)/symbol-vals.sl
	$(PDIST)/make-pnk-lap $(PNK) symbol-vals

$(PNKL)/token-decls.b: $(PNK)/token-decls.sl
	$(PDIST)/make-pnk-lap $(PNK) token-decls

$(PNKL)/token-scan.b: $(PNK)/token-scan.sl \
	$(PNKL)/io-decls.b $(PL)/sys-macros.b $(PNKL)/token-decls.b
	$(PDIST)/make-pnk-lap $(PNK) token-scan

$(PNKL)/top-loop.b: $(PNK)/top-loop.sl
	$(PDIST)/make-pnk-lap $(PNK) top-loop

$(PNKL)/type-conver.b: $(PNK)/type-conver.sl
	$(PDIST)/make-pnk-lap $(PNK) type-conver

$(PNKL)/type-error.b: $(PNK)/type-error.sl
	$(PDIST)/make-pnk-lap $(PNK) type-error

$(PNKL)/unicode.b: $(PNK)/unicode.sl
	$(PDIST)/make-pnk-lap $(PNK) unicode

$(PNKL)/vectors.b: $(PNK)/vectors.sl
	$(PDIST)/make-pnk-lap $(PNK) vectors

##

$(PL)/hash-decls.b: $(PK)/hash-decls.sl
	(cd $(PXK) ; make $(MFLAGS) MACHINE=$(MACHINE) $(PL)/hash-decls.b)

$(PL)/if-system.b: $(PU)/if-system.sl
	(cd $(PU)  ; make $(MFLAGS) MACHINE=$(MACHINE) $(PL)/if-system.b)

$(PL)/sys-macros.b: $(PU)/sys-macros.sl
	(cd $(PU)  ; make $(MFLAGS) MACHINE=$(MACHINE) $(PL)/sys-macros.b)

$(PL)/useful.b:
	(cd $(PU)  ; make $(MFLAGS) MACHINE=$(MACHINE) useful)

clean:
	rm -f $(PNKFILES)

# End of file.



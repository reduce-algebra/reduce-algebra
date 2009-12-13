###############################################################################
#
# File:         PU:Makefile
# Description:  Makefile for psl utilities directory.
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
	$(PL)/addr2id.b $(PL)/association.b \
	$(PL)/backquote.b $(PL)/big.b $(PL)/bind-macros.b \
	$(PL)/build.b $(PL)/char-macro.b $(PL)/chars.b \
	$(PL)/clcomp.b $(PL)/clcomp1.b $(PL)/c-template.b \
	$(PL)/common.b $(PL)/cond-macros.b $(PL)/debug.b \
	$(PL)/defmacro.b $(PL)/defmacro1.b $(PL)/defmacro2.b \
	$(PL)/defobject.b $(PL)/evalhook.b $(PL)/fast-chars.b \
	$(PL)/f-evectors.b $(PL)/fast-int.b $(PL)/pipes.b \
	$(PL)/fast-math.b $(PL)/f-strings.b  $(PL)/fcomp.b \
	$(PL)/fast-vector.b $(PL)/f-vectors.b $(PL)/find.b \
	$(PL)/for-macro.b $(PL)/gsort.b $(PL)/hcons.b \
	$(PL)/if-system.b $(PL)/if.b $(PL)/init-file.b \
	$(PL)/inum.b $(PL)/iter-macros.b $(PL)/macroexpand.b \
	$(PL)/mathlib.b $(PL)/merge-sort.b $(PL)/misc-macros.b \
	$(PL)/mstruct.b $(PL)/nbarith.b $(PL)/nbig.b $(PL)/nbig0.b \
	$(PL)/nstruct.b $(PL)/numeric-ops.b $(PL)/obj-const.b \
	$(PL)/obj-dflavor.b $(PL)/obj-dmethod.b $(PL)/obj-hash.b \
	$(PL)/objinstance.b $(PL)/obj-lib.b \
	$(PL)/obj-send.b $(PL)/objects.b \
	$(PL)/pp-file.b $(PL)/pp-lisp.b $(PL)/pp.b $(PL)/pvm.b \
	$(PL)/read-macros.b $(PL)/read-utils.b $(PL)/read1macros.b \
	$(PL)/read2macros.b $(PL)/rlispparser.b $(PL)/rlisp-sup.b \
	$(PL)/rlisp.b $(PL)/rprint.b $(PL)/set-macros.b $(PL)/shmem.b \
	$(PL)/set1-macros.b $(PL)/set2-macros.b $(PL)/s-strings.b \
	$(PL)/s-vectors.b $(PL)/step.b $(PL)/str-input.b $(PL)/str-search.b \
	$(PL)/strings.b $(PL)/sys-macros.b $(PL)/syslisp-syn.b \
	$(PL)/syslisp.b $(PL)/un-rlisp.b $(PL)/useful.b \
	$(PL)/vector-fix.b $(PL)/wdeclare.b

$(PL)/addr2id.b: $(PU)/addr2id.sl $(PL)/useful.b
	$(PDIST)/make-lap $(PU) addr2id

#$(PL)/assoc-lists.b: $(PU)/assoc-lists.sl
#	$(PDIST)/make-lap $(PU) assoc-lists

$(PL)/association.b: $(PU)/association.sl
	$(PDIST)/make-lap $(PU) association

$(PL)/backquote.b: $(PU)/backquote.sl
	$(PDIST)/make-lap $(PU) backquote

$(PL)/big.b: $(PU)/big.sl
	$(PDIST)/make-lap $(PU) big

$(PL)/bind-macros.b: $(PU)/bind-macros.sl \
	$(PL)/backquote.b $(PL)/cond-macros.b $(PL)/defmacro.b \
	$(PL)/read-macros.b
	$(PDIST)/make-lap $(PU) bind-macros

$(PL)/build.b: $(PU)/build.sl $(PL)/if-system.b	
	$(PDIST)/make-lap $(PU) build

$(PL)/char-macro.b: $(PU)/char-macro.sl $(PL)/backquote.b $(PL)/read1macros.b
	$(PDIST)/make-lap $(PU) char-macro

$(PL)/chars.b: $(PU)/chars.sl $(PL)/clcomp.b
	$(PDIST)/make-lap $(PU) chars

$(PL)/clcomp.b: $(PU)/clcomp.sl $(PL)/clcomp1.b $(PL)/useful.b
	$(PDIST)/make-lap $(PU) clcomp

$(PL)/clcomp1.b: $(PU)/clcomp1.sl $(PL)/common.b $(PL)/fast-vector.b \
	$(PL)/useful.b
	$(PDIST)/make-lap $(PU) clcomp1

$(PL)/c-template.b: $(PU)/c-template.sl
	$(PDIST)/make-lap $(PU) c-template

$(PL)/common.b: $(PU)/common.sl $(PL)/fast-vector.b $(PL)/numeric-ops.b \
	$(PL)/useful.b
	$(PDIST)/make-lap $(PU) common

$(PL)/cond-macros.b: $(PU)/cond-macros.sl \
	$(PL)/backquote.b $(PL)/defmacro.b $(PL)/read-macros.b
	$(PDIST)/make-lap $(PU) cond-macros

$(PL)/debug.b: $(PU)/debug.sl $(PL)/fast-vector.b
	$(PDIST)/make-lap $(PU) debug

$(PL)/defmacro.b: $(PU)/defmacro.sl $(PL)/defmacro1.b $(PL)/defmacro2.b
	$(PDIST)/make-lap $(PU) defmacro

$(PL)/defmacro1.b: $(PU)/defmacro1.sl $(PL)/backquote.b $(PL)/read-macros.b
	$(PDIST)/make-lap $(PU) defmacro1

$(PL)/defmacro2.b: $(PU)/defmacro2.sl \
	$(PL)/backquote.b $(PL)/defmacro1.b $(PL)/read-macros.b
	$(PDIST)/make-lap $(PU) defmacro2

$(PL)/defobject.b: $(PU)/defobject.sl $(PL)/objects.b $(PL)/c-template.b
	$(PDIST)/make-lap $(PU) defobject

$(PL)/evalhook.b: $(PU)/evalhook.sl $(PL)/clcomp.b $(PL)/useful.b
	$(PDIST)/make-lap $(PU) evalhook

$(PL)/fast-chars.b: $(PU)/fast-chars.sl $(PL)/chars.b $(PL)/if.b \
	$(PL)/numeric-ops.b
	$(PDIST)/make-lap $(PU) fast-chars

$(PL)/f-evectors.b: $(PU)/f-evectors.sl $(PL)/if-system.b
	$(PDIST)/make-lap $(PU) f-evectors

$(PL)/fast-int.b: $(PU)/fast-int.sl $(PL)/numeric-ops.b
	$(PDIST)/make-lap $(PU) fast-int

$(PL)/fast-math.b: $(PU)/fast-math.sl $(PL)/useful.b
	$(PDIST)/make-lap $(PU) fast-math

$(PL)/f-strings.b: $(PU)/f-strings.sl
	$(PDIST)/make-lap $(PU) f-strings

#$(PL)/fast-struct.b: $(PU)/fast-struct.sl
#	$(PDIST)/make-lap $(PU) fast-struct

$(PL)/fast-vector.b: $(PU)/fast-vector.sl $(PL)/if-system.b
	$(PDIST)/make-lap $(PU) fast-vector

$(PL)/fcomp.b: $(PU)/fcomp.sl $(PL)/if-system.b
	$(PDIST)/make-lap $(PU) fcomp

$(PL)/f-vectors.b: $(PU)/f-vectors.sl $(PL)/fast-vector.b \
	$(PL)/s-vectors.b
	$(PDIST)/make-lap $(PU) f-vectors

$(PL)/find.b: $(PU)/find.sl $(PL)/gsort.b
	$(PDIST)/make-lap $(PU) find

$(PL)/for-macro.b: $(PU)/for-macro.sl \
	$(PL)/backquote.b $(PL)/bind-macros.b $(PL)/cond-macros.b \
	$(PL)/defmacro.b $(PL)/iter-macros.b $(PL)/read-macros.b \
	$(PL)/set-macros.b
	$(PDIST)/make-lap $(PU) for-macro

$(PL)/gsort.b: $(PU)/gsort.sl $(PL)/if.b
	$(PDIST)/make-lap $(PU) gsort

$(PL)/hcons.b: $(PU)/hcons.sl $(PL)/useful.b
	$(PDIST)/make-lap $(PU) hcons

$(PL)/if-system.b: $(PU)/if-system.sl
	$(PDIST)/make-lap $(PU) if-system

$(PL)/if.b: $(PU)/if.sl
	$(PDIST)/make-lap $(PU) if

$(PL)/init-file.b: $(PU)/init-file.sl $(PL)/if-system.b
	$(PDIST)/make-lap $(PU) init-file

$(PL)/inum.b: $(PU)/inum.sl $(PL)/rlisp.b
	$(PDIST)/make-lap $(PU) inum

$(PL)/iter-macros.b: $(PU)/iter-macros.sl \
	$(PL)/backquote.b $(PL)/bind-macros.b $(PL)/cond-macros.b \
	$(PL)/defmacro.b $(PL)/read-macros.b $(PL)/set-macros.b
	$(PDIST)/make-lap $(PU) iter-macros

$(PL)/macroexpand.b: $(PU)/macroexpand.sl \
	$(PL)/backquote.b $(PL)/bind-macros.b $(PL)/cond-macros.b \
	$(PL)/defmacro.b $(PL)/for-macro.b $(PL)/iter-macros.b \
	$(PL)/read-macros.b $(PL)/set-macros.b
	$(PDIST)/make-lap $(PU) macroexpand

$(PL)/mathlib.b: $(PU)/mathlib.sl $(PL)/useful.b
	$(PDIST)/make-lap $(PU) mathlib

$(PL)/merge-sort.b: $(PU)/merge-sort.sl $(PL)/if.b $(PL)/numeric-ops.b \
	$(PL)/useful.b
	$(PDIST)/make-lap $(PU) merge-sort

$(PL)/misc-macros.b: $(PU)/misc-macros.sl \
	$(PL)/backquote.b $(PL)/bind-macros.b $(PL)/cond-macros.b \
	$(PL)/defmacro.b $(PL)/for-macro.b $(PL)/iter-macros.b \
	$(PL)/read-macros.b $(PL)/set-macros.b
	$(PDIST)/make-lap $(PU) misc-macros

$(PL)/mstruct.b: $(PU)/mstruct.sl
	$(PDIST)/make-lap $(PU) mstruct

$(PL)/nbarith.b: $(PU)/nbarith.sl $(PL)/comasm.b
	$(PDIST)/make-lap $(PU) nbarith

$(PL)/nbig.b: $(PU)/nbig.sl $(PL)/nbarith.b $(PL)/nbig0.b $(PL)/vector-fix.b
	$(PDIST)/make-lap $(PU) nbig

$(PL)/nbig0.b: $(PU)/nbig0.sl $(PL)/fast-vector.b $(PL)/inum.b \
	$(PL)/if-system.b $(PL)/rlisp.b
	$(PDIST)/make-lap $(PU) nbig0

$(PL)/nstruct.b: $(PU)/nstruct.sl $(PU)/fast-struct.sl $(PL)/clcomp.b \
	$(PL)/strings.b
	($(PU)/nstruct.csh)

$(PL)/numeric-ops.b: $(PU)/numeric-ops.sl $(PL)/useful.b
	$(PDIST)/make-lap $(PU) numeric-ops

$(PL)/obj-const.b: $(PU)/obj-const.sl
	$(PDIST)/make-lap $(PU) obj-const

$(PL)/obj-dflavor.b: $(PU)/obj-dflavor.sl $(PL)/obj-const.b \
	$(PL)/f-vectors.b $(PL)/f-evectors.b $(PL)/strings.b \
	$(PL)/association.b $(PL)/numeric-ops.b 
	$(PDIST)/make-lap $(PU) obj-dflavor

$(PL)/obj-dmethod.b: $(PU)/obj-dmethod.sl $(PL)/obj-const.b \
	$(PL)/f-vectors.b $(PL)/f-evectors.b \
	$(PL)/association.b $(PL)/numeric-ops.b
	$(PDIST)/make-lap $(PU) obj-dmethod

$(PL)/obj-hash.b: $(PU)/obj-hash.sl $(PL)/obj-const.b \
	$(PL)/f-vectors.b $(PL)/f-evectors.b \
	$(PL)/numeric-ops.b
	$(PDIST)/make-lap $(PU) obj-hash

$(PL)/objinstance.b: $(PU)/objinstance.sl $(PL)/obj-const.b \
	$(PL)/f-vectors.b $(PL)/f-evectors.b \
	$(PL)/numeric-ops.b
	$(PDIST)/make-lap $(PU) objinstance

$(PL)/obj-lib.b: $(PU)/obj-lib.sl $(PL)/obj-const.b \
	$(PL)/f-vectors.b $(PL)/f-evectors.b \
	$(PL)/numeric-ops.b $(PL)/strings.b
	$(PDIST)/make-lap $(PU) obj-lib

$(PL)/obj-send.b: $(PU)/obj-send.sl $(PL)/obj-const.b \
	$(PL)/f-vectors.b $(PL)/f-evectors.b \
	$(PL)/numeric-ops.b $(PL)/association.b
	$(PDIST)/make-lap $(PU) obj-send

#$(PL)/obj-io.b: $(PU)/obj-io.sl
#	$(PDIST)/make-lap $(PU) obj-io

#$(PL)/obj-tools.b: $(PU)/obj-tools.sl
#	$(PDIST)/make-lap $(PU) obj-tools

$(PL)/objects.b: $(PU)/objects.sl $(PL)/gsort.b \
	$(PL)/obj-const.b $(PL)/obj-dflavor.b $(PL)/obj-dmethod.b \
	$(PL)/obj-hash.b $(PL)/objinstance.b \
	$(PL)/obj-lib.b $(PL)/obj-send.b $(PL)/fc-indirect.b \
	$(PL)/numeric-ops.b $(PL)/f-vectors.b $(PL)/f-evectors.b \
	$(PL)/strings.b $(PL)/useful.b $(PL)/common.b $(PL)/association.b
	$(PDIST)/make-lap $(PU) objects

#$(PL)/fc-indirect.b

$(PL)/pipes.b: $(PU)/pipes.sl $(PNKL)/io-decls.b
	$(PDIST)/make-lap $(PU) pipes

$(PL)/pp-file.b: $(PU)/pp-file.sl $(PL)/pp.b
	$(PDIST)/make-lap $(PU) pp-file

$(PL)/pp-lisp.b: $(PU)/pp-lisp.sl
	$(PDIST)/make-lap $(PU) pp-lisp

$(PL)/pp.b: $(PU)/pp.sl $(PL)/fast-int.b $(PL)/useful.b
	$(PDIST)/make-lap $(PU) pp

$(PL)/pvm.b: $(PU)/pvm.sl $(PL)/if-system.b
	$(PDIST)/make-lap $(PU) pvm

$(PL)/read-macros.b: $(PU)/read-macros.sl $(PL)/read1macros.b \
	$(PL)/read2macros.b
	$(PDIST)/make-lap $(PU) read-macros

$(PL)/read-utils.b: $(PU)/read-utils.sl
	$(PDIST)/make-lap $(PU) read-utils

$(PL)/read1macros.b: $(PU)/read1macros.sl $(PL)/backquote.b
	$(PDIST)/make-lap $(PU) read1macros

$(PL)/read2macros.b: $(PU)/read2macros.sl \
	$(PL)/backquote.b $(PL)/char-macro.b $(PL)/read1macros.b
	$(PDIST)/make-lap $(PU) read2macros

$(PL)/rlispparser.b: $(PU)/rlispparser.sl $(PL)/c-template.b
	$(PDIST)/make-lap $(PU) rlispparser

$(PL)/rlisp-sup.b: $(PU)/rlisp-sup.sl 
	$(PDIST)/make-lap $(PU) rlisp-sup

$(PL)/rlisp.b: $(PU)/rlisp.sl $(PL)/rlispparser.b $(PL)/rlisp-sup.b
	$(PDIST)/make-lap $(PU) rlisp

$(PL)/rprint.b: $(PU)/rprint.sl
	$(PDIST)/make-lap $(PU) rprint

$(PL)/set-macros.b: $(PU)/set-macros.sl \
	$(PL)/set1-macros.b $(PL)/set2-macros.b
	$(PDIST)/make-lap $(PU) set-macros

$(PL)/set1-macros.b: $(PU)/set1-macros.sl \
	$(PL)/backquote.b $(PL)/bind-macros.b $(PL)/cond-macros.b \
	$(PL)/defmacro.b $(PL)/read-macros.b
	$(PDIST)/make-lap $(PU) set1-macros

$(PL)/set2-macros.b: $(PU)/set2-macros.sl \
	$(PL)/backquote.b $(PL)/bind-macros.b $(PL)/cond-macros.b \
	$(PL)/defmacro.b $(PL)/read-macros.b $(PL)/set1-macros.b
	$(PDIST)/make-lap $(PU) set2-macros

$(PL)/shmem.b: $(PU)/shmem.sl $(PNKL)/io-decls.b
	$(PDIST)/make-lap $(PU) shmem

$(PL)/s-strings.b: $(PU)/s-strings.sl
	$(PDIST)/make-lap $(PU) s-strings

$(PL)/s-vectors.b: $(PU)/s-vectors.sl
	$(PDIST)/make-lap $(PU) s-vectors

$(PL)/step.b: $(PU)/step.sl $(PL)/clcomp.b $(PL)/numeric-ops.b \
	$(PL)/useful.b
	$(PDIST)/make-lap $(PU) step

$(PL)/str-input.b: $(PU)/str-input.sl $(PL)/f-strings.b $(PL)/if.b \
	$(PL)/f-vectors.b $(PL)/numeric-ops.b
	$(PDIST)/make-lap $(PU) str-input

$(PL)/str-search.b: $(PU)/str-search.sl $(PL)/f-strings.b $(PL)/if.b \
	$(PL)/if-system.b $(PL)/numeric-ops.b
	$(PDIST)/make-lap $(PU) str-search

$(PL)/strings.b: $(PU)/strings.sl $(PL)/chars.b $(PL)/clcomp.b $(PL)/useful.b 
	$(PDIST)/make-lap $(PU) strings

$(PL)/sys-macros.b: $(PU)/sys-macros.sl
	$(PDIST)/make-lap $(PU) sys-macros

$(PL)/syslisp-syn.b: $(PU)/syslisp-syn.sl $(PL)/rlisp.b
	$(PDIST)/make-lap $(PU) syslisp-syn

$(PL)/syslisp.b: $(PU)/syslisp.sl $(PL)/datamachine.b $(PL)/sys-macros.b \
	$(PL)/syslisp-syn.b
	$(PDIST)/make-lap $(PU) syslisp

$(PL)/un-rlisp.b: $(PU)/un-rlisp.sl $(PL)/chars.b $(PL)/clcomp1.b \
	$(PL)/common.b  $(PL)/rlisp.b $(PL)/strings.b
	$(PDIST)/make-lap $(PU) un-rlisp

useful: $(PL)/useful.b

$(PL)/useful.b: $(PL)/backquote.b $(PL)/read1macros.b $(PL)/char-macro.b \
		$(PL)/read2macros.b $(PL)/read-macros.b $(PL)/defmacro1.b \
		$(PL)/defmacro2.b $(PL)/defmacro.b $(PL)/cond-macros.b \
		$(PL)/bind-macros.b $(PL)/set1-macros.b $(PL)/set2-macros.b \
		$(PL)/set-macros.b $(PL)/iter-macros.b $(PL)/for-macro.b \
		$(PL)/misc-macros.b $(PL)/macroexpand.b
	$(PDIST)/make-lap $(PU) useful

$(PL)/vector-fix.b: $(PU)/vector-fix.sl
	$(PDIST)/make-lap $(PU) vector-fix

$(PL)/wdeclare.b: $(PU)/wdeclare.sl
	$(PDIST)/make-lap $(PU) wdeclare

#

$(PL)/datamachine.b: $(PC)/datamachine.sl
	(cd $(PC) ; make $(MFLAGS) MACHINE=$(MACHINE) $(PL)/datamachine.b)

$(PL)/comasm.b: $(PC)/comasm.sl
	(cd $(PC) ; make $(MFLAGS) MACHINE=$(MACHINE) $(PL)/comasm.b)

# End of file.

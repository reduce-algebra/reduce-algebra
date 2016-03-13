############################################################################
#
# File:		 PXK:Makefile
# Description:  Makefile for bpsl (microkernel).
# Author:	   Harold Carr and Leigh Stoller.
# Created:	  29-Sep-86
# Modified:	06-Oct-87 (Harold Carr)
# Mode:		 Text
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
##############################################################################
# Revisions
#
# 02-20-88 (Chris Burdorf)
# Got rid of malloc.o, increased BPSSIZE, and added -Bstatic to ld to
# make it run under SUN3 OS.
# 09-Oct-87 (Leigh Stoller)
#  Do not remove bps.o. Disk is cheap, and it avoids having to relink
#   bpsl every time we rebuild.
# 06-Oct-87 (Harold Carr)
#  Add variables: USERDIR to make it still easier to build things into
#  the microkernel.
# 01-Sep-87 (Harold Carr)
#  Added variables: USERSLFILES, USERLIBS, and USEROFILES to make it easy for
#  a random user to build .o files, libs and .sl files into the microkernel.
# 26-11-86 (Tim Mueller)
#  Made extendible and portable. This makefile can be
#  copied to a directory where a private version of the
#  psl kernel (bpsl) with external C code can be constructed.
#  Added main.awk script to automatically construct commands
#  to feed to the cross-compiler to produce main.s .
#
##############################################################################
 
PROOT   = /home/rainer/software/reduce/psl
 
#### MACHINE = unix386
PSL	= $(PROOT)/dist
PSYS	= $(PROOT)/bin
PK	= $(PSL)/kernel
PXK	 = $(PK)/$(MACHINE)
PNK	= $(PSL)/nonkernel
PXNK	= $(PNK)/$(MACHINE)
PNKL	= $(PSL)/nonkernel/$(MACHINE)/lap
PC	= $(PSL)/comp
PXC	 = $(PC)/$(MACHINE)
PU	= $(PSL)/util
PXU	 = $(PU)/$(MACHINE)
PDIST   = $(PSL)/distrib
PXDIST  = $(PDIST)/$(MACHINE)
PL	= $(PSL)/lap/$(MACHINE)
 
#CRT0	= /lib/crt0.o
 
OTHEROFILES = \
	$(PXK)/os-hooks.o \
	$(PXK)/pslextras.o
 
OTHERCFILES = \
	$(PXK)/os-hooks.c \
	$(PXK)/pslextras.c
 
# Use -L in the assembler to keep labels that begin with "L".
ASPROG = x86_64-w64-mingw32-as
ASARGS = 
CCPROG = x86_64-w64-mingw32-gcc
#CFLAGS =
 
# Header file to support car/cdr of NIL.
NIL =
 
# If a user wants to include their own .o files, libraries and .sl files
# to be built into bpsl then they should be defined with these variables.
 
#USERLIBS	=
#USEROFILES  =
#USERSLFILES =
 
# If a user wants to include their own stuff in their own private copy
# of the microkernel they should pass this variable so that a private
# copy of bpsl will be built in the given directory.
 
USERDIR = $(PXK)
 
###################################################################
 
default: $(USERDIR)/bpsl.exe
 
bpsl: default
 
###################################################################
# Object files for ld -
# Local .o files can be added to this list.
OFILES=	\
	$(PXK)/echo.o \
	$(PXK)/file-status.o \
	$(PXK)/float.o \
	$(PXK)/pwd-fn.o \
	$(PXK)/sigs.o \
	$(PXK)/unix-io.o \
	$(OTHEROFILES)
CFILES=	\
	$(PXK)/bps.c \
	$(PXK)/bpsheap.c \
	$(PXK)/echo.c \
	$(PXK)/file-status.c \
	$(PXK)/float.c \
	$(PXK)/pwd-fn.c \
	$(PXK)/sigs.c \
	$(PXK)/unix-io.c \
	$(OTHERCFILES)
 
#####################################################################
# .sl files - Files to be dskin'ed to the cross-assembler to make main.s
# Add local external function definitions (.sl) files here to reference
# external C code.
SLFILES= \
	$(PXK)/main-start.sl \
	$(PXK)/io.sl \
	$(PXK)/intern.sl \
	$(PXK)/faslin.sl \
	$(PXK)/alloc.sl \
	$(PK)/support.sl \
	$(PXK)/sys-support.sl \
	$(PXK)/externals.sl \
	$(USERSLFILES)
 
BFILES= \
	$(PL)/fasl-decls.b \
	$(PL)/f-strings.b \
	$(PL)/fast-vector.b \
	$(PL)/hash-decls.b \
	$(PL)/s-strings.b \
	$(PL)/sys-consts.b

bfiles: $(BFILES)
 
.SUFFIXES: .b .c .o .s .sl
 
# Add libraries for external C code references here.
#LIBS =
#CRT1  = 
 
# Use -n for shared text, -q for demand paged (on some unixes).

$(USERDIR)/bpsl.exe: $(CFILES)  \
		$(USERDIR)/main.o $(USERDIR)/dmain.o
	$(USERDIR)/cclnk

$(USERDIR)/dmain.o: $(USERDIR)/dmain.s 
	cp $(USERDIR)/dmain.s $(USERDIR)/dmain.s.orig
	sed -f $(PXK)/dmain.sed -i $(USERDIR)/dmain.s
	$(ASPROG) $(ASARGS) -o $(USERDIR)/dmain.o $(USERDIR)/dmain.s

$(USERDIR)/main.o: $(USERDIR)/main.s
	cp $(USERDIR)/main.s $(USERDIR)/main.s.orig
	sed -f $(PXK)/main.sed -i $(USERDIR)/main.s
	$(ASPROG) $(ASARGS) -o $(USERDIR)/main.o $(USERDIR)/main.s

$(USERDIR)/main.s: $(BFILES) $(SLFILES) $(PXK)/main.sed \
		$(PXK)/dmain.sed
	-rm -f $(USERDIR)/$(MACHINE).sym
	cp $(PC)/bare-psl.sym $(USERDIR)/$(MACHINE).sym
	(cd $(USERDIR)/; \
	 echo $(SLFILES) | awk -f $(PXK)/main.awk > tmp.sl; \
	$(PXK)/$(MACHINE)-cross tmp.sl)

$(PL)/fasl-decls.b: $(PXK)/fasl-decls.sl
	$(PDIST)/make-lap $(PXK) fasl-decls
 
$(PL)/f-strings.b: $(PU)/f-strings.sl
	$(PDIST)/make-lap $(PU) f-strings
 
$(PL)/fast-vector.b: $(PU)/fast-vector.sl $(PL)/if-system.b
	$(PDIST)/make-lap $(PU) fast-vector
 
$(PL)/hash-decls.b: $(PXK)/hash-decls.sl
	$(PDIST)/make-lap $(PXK) hash-decls
 
$(PL)/if-system.b: $(PU)/if-system.sl
	$(PDIST)/make-lap $(PU) if-system
 
$(PL)/s-strings.b: $(PU)/s-strings.sl
	$(PDIST)/make-lap $(PU) s-strings
 
$(PL)/sys-consts.b: $(PXC)/sys-consts.sl
	$(PDIST)/make-lap $(PXC) sys-consts
 
# End of file.

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
# (c) Copyright 1987, University of Utah, all rights reserved.
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
 
PROOT   = /silo/cons/verkaufpsl
 
PSL	= $(PROOT)/dist
PSYS	= $(PROOT)/bin/$(MACHINE)
PK	= $(PSL)/kernel
PXK	= $(PSL)/kernel/$(MACHINE)
PNK	= $(PSL)/nonkernel
PXNK	= $(PNK)/$(MACHINE)
PNKL	= $(PSL)/nonkernel/$(MACHINE)/lap
PC	= $(PSL)/comp
PXC	= $(PC)/$(MACHINE)
PU	= $(PSL)/util
PXU	= $(PU)/$(MACHINE)
PDIST   = $(PSL)/distrib
PXDIST  = $(PDIST)/$(MACHINE)
PL	= $(PSL)/lap/$(MACHINE)
 
OTHEROFILES = \
	$(PXK)/os-hooks.o \
	$(PXK)/pslsocket.o \
	$(PXK)/pslextras.o
 
OTHERCFILES = \
	$(PXK)/os-hooks.c \
	$(PXK)/pslsocket.c \
	$(PXK)/pslextras.c
 
# Use -L in the assembler to keep labels that begin with "L".
ASARGS =
CFLAGS = -g -bimport:syscall/mycflush.exp
 
# Header file to support car/cdr of NIL.
NIL =
 
# Loader arguments.
LDARGS = -x
BPSSIZE = 5000000
 
# If a user wants to include their own .o files, libraries and .sl files
# to be built into bpsl then they should be defined with these variables.
 
#USERLIBS    =
#USEROFILES  =
#USERSLFILES =
 
# If a user wants to include their own stuff in their own private copy
# of the microkernel they should pass this variable so that a private
# copy of bpsl will be built in the given directory.
 
USERDIR = $(PXK)
 
###################################################################
 
default: $(USERDIR)/bpsl
 
bpsl: default
 
###################################################################
# Object files for ld -
# Local .o files can be added to this list.
OFILES=	\
	$(PXK)/echo.o \
	$(PXK)/file-status.o \
	$(PXK)/float.o \
	$(PXK)/pwd-fn.o \
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
	$(PXK)/support.sl \
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
LIBS= 
CRT1  = 

 
# Use -n for shared text, -q for demand paged (on some unixes).

$(USERDIR)/bpsl: $(USEROFILES) $(USERLIBS) $(OFILES) $(CRT0) \
		$(USERDIR)/bps.o $(USERDIR)/bpsheap.o \
		$(USERDIR)/main.o \
		$(NIL) $(PXK)/Makefile
	mv $(USERDIR)/pslkernel.h $(USERDIR)/pslkernel.tmp
	sed -f $(PXK)/pslkernel.sed \
		 $(USERDIR)/pslkernel.tmp >  $(USERDIR)/pslkernel.h
	date | awk -f $(PXK)/datetag.awk > $(PXK)/datetag.c
	cc -bnso -bimport:/lib/syscalls.exp -bimport:syscall/mycflush.exp \
		-o $(PXK)/bpsl.new $(PXK)/datetag.c \
		$(USERDIR)/bps.o $(CRT0) $(CRT1) \
		$(USERDIR)/main.o $(USERDIR)/bpsheap.o \
		$(PXK)/sigs.c \
		$(OFILES) $(USEROFILES) $(USERLIBS) $(LIBS) -lm -lc
	mv $(PXK)/bpsl.new $(PXK)/bpsl
	$(PSYS)/sparsify $(USERDIR)/bpsl
	$(PSYS)/sparsify $(USERDIR)/bps.o
 
$(USERDIR)/bpsl_om: $(USEROFILES) $(USERLIBS) $(OFILES) $(CRT0) \
		$(USERDIR)/OM_externals.sl $(USERDIR)/bps.o \
		$(USERDIR)/bpsheap.o  $(USERDIR)/main_om.o \
		$(NIL) $(PXK)/Makefile
	mv $(USERDIR)/pslkernel.h $(USERDIR)/pslkernel.tmp
	sed -f $(PXK)/pslkernel.sed \
		 $(USERDIR)/pslkernel.tmp >  $(USERDIR)/pslkernel.h
	date | awk -f $(PXK)/datetag.awk > $(PXK)/datetag.c
	cc -bnso -bimport:/lib/syscalls.exp -bimport:syscall/mycflush.exp \
		-o $(PXK)/bpsl.new $(PXK)/datetag.c \
		$(USERDIR)/bps.o $(CRT0) $(CRT1) \
		$(USERDIR)/main_om.o $(USERDIR)/bpsheap.o \
		$(PXK)/sigs.c \
		$(OFILES) $(USEROFILES)  -L/tmp/claude/OMCv1.0b/src/ -lOM \
		-lOMconn $(USERLIBS) \
		 $(USERLIBS) $(LIBS) -lm -lc
	mv $(PXK)/bpsl.new $(PXK)/bpsl_om
	$(PSYS)/sparsify $(USERDIR)/bpsl_om
	$(PSYS)/sparsify $(USERDIR)/bps.o
 

$(USERDIR)/bpsl_pvm: $(USEROFILES) $(USERLIBS) $(OFILES) $(CRT0) \
		$(USERDIR)/bps.o $(USERDIR)/bpsheap.o \
		$(USERDIR)/main_pvm.o  $(NIL) $(PXK)/Makefile
	mv $(USERDIR)/pslkernel.h $(USERDIR)/pslkernel.tmp
	sed -f $(PXK)/pslkernel.sed \
		 $(USERDIR)/pslkernel.tmp >  $(USERDIR)/pslkernel.h
	date | awk -f $(PXK)/datetag.awk > $(PXK)/datetag.c
	cc -bnso -bimport:/lib/syscalls.exp -bimport:syscall/mycflush.exp \
		-o $(PXK)/bpsl.new $(PXK)/datetag.c \
		$(USERDIR)/bps.o $(CRT0) $(CRT1) \
		$(USERDIR)/main_pvm.o $(USERDIR)/bpsheap.o \
		$(PXK)/sigs.c \
		$(OFILES) $(USEROFILES) $(USERLIBS) $(LIBS) \
		-L/zib/pvm3.1/lib/RS6K  -lpvm3 -lm -lc
	mv $(PXK)/bpsl.new $(PXK)/bpsl_pvm
	$(PSYS)/sparsify $(USERDIR)/bpsl_pvm
	$(PSYS)/sparsify $(USERDIR)/bps.o

$(USERDIR)/main.o: $(USERDIR)/main.s $(PXK)/main.sed
	cat $(PXK)/main.s $(USERDIR)/dmain.s > $(USERDIR)/hugo.s
	/usr/ccs/bin/as-aix $(ASARGS) -o $(USERDIR)/main.o $(USERDIR)/hugo.s
	rm $(USERDIR)/hugo.s

$(USERDIR)/main.s: $(BFILES) $(SLFILES)
	-rm -f $(USERDIR)/$(MACHINE).sym
	cp $(PC)/bare-psl.sym $(USERDIR)/$(MACHINE).sym
	($(PXDIST)/make-$(MACHINE)-cross ; cd $(USERDIR)/; \
	 echo $(SLFILES) | awk -f $(PXK)/main.awk | $(PXK)/$(MACHINE)-cross)

$(USERDIR)/main_om.o: $(USERDIR)/main.s $(PXK)/main.sed
	cat $(PXK)/main_om.s $(USERDIR)/dmain_om.s > $(USERDIR)/hugo.s
	/usr/ccs/bin/as-aix $(ASARGS) -o $(USERDIR)/main_om.o $(USERDIR)/hugo.s
	rm $(USERDIR)/hugo.s
 
$(USERDIR)/main_om.s: $(BFILES) $(SLFILES)
	-rm -f $(USERDIR)/$(MACHINE).sym
	cp $(PC)/bare-psl.sym $(USERDIR)/$(MACHINE).sym
	($(PXDIST)/make-$(MACHINE)-cross ; cd $(USERDIR)/; \
	 echo $(SLFILES) OM_externals.sl | awk -f $(PXK)/main_OM.awk \
	 | $(PXK)/$(MACHINE)-cross)
 
$(USERDIR)/main_pvm.o: $(USERDIR)/main_pvm.s $(PXK)/main.sed
	cat $(PXK)/main_pvm.s $(USERDIR)/dmain_pvm.s > $(USERDIR)/hugo.s
	/usr/ccs/bin/as-aix $(ASARGS) -o $(USERDIR)/main_pvm.o $(USERDIR)/hugo.s
	rm $(USERDIR)/hugo.s
 
$(USERDIR)/main_pvm.s: $(BFILES) $(SLFILES)
	-rm -f $(USERDIR)/$(MACHINE).sym
	cp $(PC)/bare-psl.sym $(USERDIR)/$(MACHINE).sym
	($(PXDIST)/make-$(MACHINE)-cross ; cd $(USERDIR)/; \
	 echo $(SLFILES)  pvmextern.sl\
		 | awk -f $(PXK)/main_pvm.awk | $(PXK)/$(MACHINE)-cross)
 
.s.o:
	as $(ASARGS) -o $*.o $*.s
 
$(USERDIR)/bps.o: $(PXK)/bps.c
	$(CC) -c $(CFLAGS) -o $(USERDIR)/bps.o \
		-DBPSSIZE=$(BPSSIZE) $(PXK)/bps.c
 
# bpsheap.c must have the psl variables converted from C variable format
$(USERDIR)/bpsheap.o: $(PXK)/bpsheap.c $(PXK)/bpsheap.sed
	$(CC) -c $(CFLAGS) -DBPSSIZE=$(BPSSIZE) $(PXK)/bpsheap.c
 
$(PXK)/unix-io.o: $(PXK)/unix-io.c $(PXK)/unix-io.sed
	$(CC) -c $(CFLAGS) $(PXK)/unix-io.c
 
$(PL)/fasl-decls.b: $(PXK)/fasl-decls.sl
	$(PDIST)/make-lap $(PXK) fasl-decls
 
$(PL)/f-strings.b: $(PU)/f-strings.sl
	$(PDIST)/make-lap $(PU) f-strings
 
$(PL)/fast-vector.b: $(PU)/fast-vector.sl $(PL)/if-system.b
	$(PDIST)/make-lap $(PU) fast-vector
 
$(PL)/hash-decls.b: $(PK)/hash-decls.sl
	$(PDIST)/make-lap $(PK) hash-decls
 
$(PL)/if-system.b: $(PU)/if-system.sl
	$(PDIST)/make-lap $(PU) if-system
 
$(PL)/s-strings.b: $(PU)/s-strings.sl
	$(PDIST)/make-lap $(PU) s-strings
 
$(PL)/sys-consts.b: $(PXC)/sys-consts.sl
	$(PDIST)/make-lap $(PXC) sys-consts
 
# End of file.

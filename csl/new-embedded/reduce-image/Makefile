# Makefile for building reduce.img suitable for embedded use. This
# will always want to run on the current machine!


COMMON=-O1 -g -I. -DPAGE_BITS=19 -DHAVE_CONFIG_H=1 -DEMBEDDED=1

# The idea here is that I want a C compiler and set of flags that will
# generate a 32-bit executable. Rather than use a separate configuration
# step I will use GNU Make trickery to detect a collection of cases
# I expect to be enough to get me going rather often. I will assume I am
# going to use (a version of) gcc...
# If this does not work or you do not like it merely set CC and CFLAGS
# manually for yourself.

ifeq ($(findstring Windows, $(OS)), Windows)

CC1:=$(shell i686-w64-mingw32-gcc -v 2>&1)
CC2:=$(shell gcc-3 -v 2>&1)
CC3:=$(shell gcc hello.c -o hello && ./hello 2>&1)

ifneq ($(CC1),)
CC=i686-w64-mingw32-gcc
CFLAGS=$(COMMON)
else
ifneq ($(CC2),)
CC=gcc-3
CFLAGS=-mno-cygwin $(COMMON)
else
ifeq ($(findstring [[4]], $(CC3)), [[4]])
CC=gcc
CFLAGS=$(COMMON)
else
CC=echo "Unable to build 32 bit application" && exit 1 &&
CFLAGS=
endif
endif
endif

else

CC3:=$(shell gcc hello.c -o hello && ./hello 2>&1)
CC4:=$(shell gcc -m32 hello.c -o hello && ./hello 2>&1)

ifeq ($(findstring [[4]], $(CC3)), [[4]])
CC=gcc
CFLAGS=$(COMMON)
else
ifeq ($(findstring [[4]], $(CC4)), [[4]])
CC=gcc
CFLAGS=-m32 $(COMMON)
else
CC=echo "Unable to build 32 bit application" && exit 1 &&
CFLAGS=
endif
endif

endif

S=../../cslbase
R=../../..

VPATH=$(S)

all:	reduce reduce.img

reduce:		arith01.o arith02.o arith03.o arith04.o arith05.o \
		arith06.o arith07.o arith08.o arith09.o arith10.o \
		arith11.o arith12.o bytes.o char.o \
		csl.o cslmpi.o cslread.o eval1.o eval2.o eval3.o \
		eval4.o fasl.o fns1.o fns2.o fns3.o fwin.o gc.o \
		preserve.o print.o restart.o sysfwin.o termed.o \
		stubs.o
	$(CC) $(CFLAGS) arith01.o arith02.o arith03.o arith04.o arith05.o \
		arith06.o arith07.o arith08.o arith09.o arith10.o \
		arith11.o arith12.o bytes.o char.o \
		csl.o cslmpi.o cslread.o eval1.o eval2.o eval3.o \
		eval4.o fasl.o fns1.o fns2.o fns3.o fwin.o gc.o \
		preserve.o print.o restart.o sysfwin.o termed.o \
		stubs.o -lm -o reduce

.c.o:                                                                          <
	$(CC) $(CFLAGS) -c -o $@ $<

# Create the reduce.img file

reduce.img:	reduce
	-rm -f reduce.img
	./reduce -z -Dno_init_file $(S)/buildreduce.lsp \
		-D@srcdir=$(S) -D@reduce=$(R) -o reduce.img -- image.log

clean:
	-rm -f *.o reduce hello reduce.img image.log

HEADERS = config.h \
	$(S)/arith.h $(S)/bytes.h $(S)/clsyms.h $(S)/cslerror.h \
	$(S)/cslread.h $(S)/entries.h $(S)/externs.h $(S)/fwin.h \
	$(S)/headers.h $(S)/machine.h $(S)/proc.h $(S)/sockhdr.h \
	$(S)/stream.h $(S)/syscsl.h $(S)/tags.h $(S)/termed.h \
	$(S)/version.h


arith01.o:	$(S)/arith01.c $(HEADERS)
arith02.o:	$(S)/arith02.c $(HEADERS)
arith03.o:	$(S)/arith03.c $(HEADERS)
arith04.o:	$(S)/arith04.c $(HEADERS)
arith05.o:	$(S)/arith05.c $(HEADERS)
arith06.o:	$(S)/arith06.c $(HEADERS)
arith07.o:	$(S)/arith07.c $(HEADERS)
arith08.o:	$(S)/arith08.c $(HEADERS)
arith09.o:	$(S)/arith09.c $(HEADERS)
arith10.o:	$(S)/arith10.c $(HEADERS)
arith11.o:	$(S)/arith11.c $(HEADERS)
arith12.o:	$(S)/arith12.c $(HEADERS)
bytes.o:	$(S)/bytes.c $(HEADERS)
bytes1.o:	$(S)/bytes1.c $(S)/opnames.c $(HEADERS)
char.o:		$(S)/char.c $(HEADERS)
csl.o:		$(S)/csl.c $(HEADERS)
cslmpi.o:	$(S)/cslmpi.c $(S)/mpipack.c $(HEADERS)
cslread.o:	$(S)/cslread.c $(HEADERS)
driver.o:	$(S)/driver.c $(HEADERS)
embedcsl.o:	$(S)/embedcsl.c $(S)/csl.c $(HEADERS)
eval1.o:	$(S)/eval1.c $(HEADERS)
eval2.o:	$(S)/eval2.c $(HEADERS)
eval3.o:	$(S)/eval3.c $(HEADERS)
eval4.o:	$(S)/eval4.c $(HEADERS)
fasl.o:		$(S)/fasl.c $(HEADERS)
fns1.o:		$(S)/fns1.c $(HEADERS)
fns2.o:		$(S)/fns2.c $(HEADERS)
fns3.o:		$(S)/fns3.c $(HEADERS)
fwin.o:		$(S)/fwin.c $(HEADERS)
gc.o:		$(S)/gc.c $(HEADERS)
preserve.o:	$(S)/preserve.c $(HEADERS)
print.o:	$(S)/print.c $(HEADERS)
restart.o:	$(S)/restart.c machineid.c $(HEADERS)
sysfwin.o:	$(S)/sysfwin.c $(HEADERS)
termed.o:	$(S)/termed.c $(HEADERS)

# end of Makefile

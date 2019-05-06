# Makefile for building reduce.img suitable for embedded use.
# This directory is a build that showcases the "procedural" interface
# as used in the file cal/cslbase/driver.cpp

# I *HOPE* that with the following conditions and provided you use GNU make
# that this will build on 64-bit Linux, 64-bit Cygwin and on a Macintosh
# that has macports installed and libffi fetched via macports.
# I expect that other platforms might not be too hard... but some
# will need the include/config.h file adjusted.

ifeq ($(shell uname),Darwin)
#CC=g++
CC=clang++
XCFLAGS= -I/opt/local/lib/libffi-3.2.1/include
XLIBS=-lm
else
ifeq ($(shell uname -o),Cygwin)
CC=g++
XLIBS=-lm
else
CC=g++
XLIBS=-lm -lpthread
endif
endif

OPT=-O0 -g
#OPT=-O3

CPPFLAGS=$(CFLAGS) -std=gnu++11 $(OPT) -I. -I../include \
    -DHAVE_CONFIG_H=1 -DEMBEDDED=1 $(XCFLAGS)
LIBS=$(XLIBS) -lz -lffi

S=../../cslbase
R=../../..

VPATH=$(S)

all:	reduce

reduce:		allocate.o arith01.o arith02.o arith03.o arith04.o arith05.o \
		arith06.o arith07.o arith08.o arith09.o arith10.o \
		arith11.o arith12.o arith13.o arith14.o bytes.o char.o driver.o \
		embedcsl.o cslmpi.o cslread.o eval1.o eval2.o eval3.o \
		eval4.o fasl.o fns1.o fns2.o fns3.o fwin.o cslgc.o lisphash.o \
		isprime.o preserve.o print.o restart.o sysfwin.o termed.o \
		inthash.o serialize.o stubs.o
	$(CC) allocate.o arith01.o arith02.o arith03.o arith04.o arith05.o \
		arith06.o arith07.o arith08.o arith09.o arith10.o \
		arith11.o arith12.o arith13.o arith14.o bytes.o char.o driver.o \
		embedcsl.o cslmpi.o cslread.o eval1.o eval2.o eval3.o \
		eval4.o fasl.o fns1.o fns2.o fns3.o fwin.o cslgc.o lisphash.o \
		isprime.o preserve.o print.o restart.o sysfwin.o termed.o \
		inthash.o serialize.o stubs.o \
		$(LIBS) -o reduce
	cp ../reduce.img .

.cpp.o:
	$(CC) $(CPPFLAGS) -c -o $@ $<

clean:
	-rm -f *.o reduce hello reduce.img

HEADERS = ../include/config.h \
	$(S)/md5.h       $(S)/termed.h    $(S)/arith.h       $(S)/openmath.h \
	$(S)/uint128_t.h $(S)/bigvector.h $(S)/entries.h     $(S)/proc.h     \
	$(S)/uninames.h  $(S)/bytes.h     $(S)/externs.h     $(S)/int128_t.h \
	$(S)/sockhdr.h   $(S)/version.h   $(S)/charmetrics.h $(S)/fwin.h     \
	$(S)/inthash.h   $(S)/stream.h    $(S)/cslerror.h    $(S)/headers.h  \
	$(S)/lispthrow.h $(S)/syscsl.h    $(S)/cslread.h     $(S)/machine.h  \
	$(S)/tags.h

allocate.o:	$(S)/allocate.cpp $(HEADERS)
arith01.o:	$(S)/arith01.cpp $(HEADERS)
arith02.o:	$(S)/arith02.cpp $(HEADERS)
arith03.o:	$(S)/arith03.cpp $(HEADERS)
arith04.o:	$(S)/arith04.cpp $(HEADERS)
arith05.o:	$(S)/arith05.cpp $(HEADERS)
arith06.o:	$(S)/arith06.cpp $(HEADERS)
arith07.o:	$(S)/arith07.cpp $(HEADERS)
arith08.o:	$(S)/arith08.cpp $(HEADERS)
arith09.o:	$(S)/arith09.cpp $(HEADERS)
arith10.o:	$(S)/arith10.cpp $(HEADERS)
arith11.o:	$(S)/arith11.cpp $(HEADERS)
arith12.o:	$(S)/arith12.cpp $(HEADERS)
arith13.o:	$(S)/arith13.cpp $(HEADERS)
arith14.o:	$(S)/arith14.cpp $(HEADERS)
bytes.o:	$(S)/bytes.cpp $(HEADERS)
bytes1.o:	$(S)/bytes1.cpp $(S)/opnames.cpp $(HEADERS)
char.o:		$(S)/char.cpp $(HEADERS)
csl.o:		$(S)/csl.cpp $(HEADERS)
cslmpi.o:	$(S)/cslmpi.cpp $(S)/mpipack.cpp $(HEADERS)
cslread.o:	$(S)/cslread.cpp $(HEADERS)
driver.o:	$(S)/driver.cpp $(HEADERS)
embedcsl.o:	$(S)/embedcsl.cpp $(S)/csl.cpp $(HEADERS)
eval1.o:	$(S)/eval1.cpp $(HEADERS)
eval2.o:	$(S)/eval2.cpp $(HEADERS)
eval3.o:	$(S)/eval3.cpp $(HEADERS)
eval4.o:	$(S)/eval4.cpp $(HEADERS)
fasl.o:		$(S)/fasl.cpp $(HEADERS)
fns1.o:		$(S)/fns1.cpp $(HEADERS)
fns2.o:		$(S)/fns2.cpp $(HEADERS)
fns3.o:		$(S)/fns3.cpp $(HEADERS)
fwin.o:		$(S)/fwin.cpp $(HEADERS)
cslgc.o:	$(S)/cslgc.cpp $(HEADERS)
lisphash.o:	$(S)/lisphash.cpp $(HEADERS)
isprime.o:	$(S)/isprime.cpp $(HEADERS)
preserve.o:	$(S)/preserve.cpp $(HEADERS)
print.o:	$(S)/print.cpp $(HEADERS)
restart.o:	$(S)/restart.cpp machineid.cpp $(HEADERS)
sysfwin.o:	$(S)/sysfwin.cpp $(HEADERS)
termed.o:	$(S)/termed.cpp $(HEADERS)
inthash.o:	$(S)/inthash.cpp $(HEADERS)
serialize.o:	$(S)/serialize.cpp $(HEADERS)


# end of Makefile

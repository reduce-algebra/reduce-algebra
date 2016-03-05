# Makefile for building reduce.img suitable for embedded use.

# The idea here is that I want a C compiler and set of flags that will
# generate a 32-bit executable. I assume absolutely that "gcc -m32"
# will do the trick. On a 64-bit Linux you are liable to need to
# check that you have multilib support and relevant development libraries
# all installed. That may cost you some messy playing around - as an
# alternative you may find it easier to set up a 32-bit Linux in a
# virtual machine and use that.

CC=g++
CFLAGS=-m32 -O2 -I. -I../include -L../lib \
    -DPAGE_BITS=19 -DHAVE_CONFIG_H=1 \
    -DHAVE_CRLIBM=1 -DEMBEDDED=1
#endif /* XXX */

S=../../cslbase
R=../../..

VPATH=$(S)

all:	reduce reduce.img image.cpp

reduce:		arith01.o arith02.o arith03.o arith04.o arith05.o \
		arith06.o arith07.o arith08.o arith09.o arith10.o \
		arith11.o arith12.o arith13.o arith14.o bytes.o char.o \
		csl.o cslmpi.o cslread.o eval1.o eval2.o eval3.o \
		eval4.o fasl.o fns1.o fns2.o fns3.o fwin.o cslgc.o \
		preserve.o print.o restart.o sysfwin.o termed.o \
		inthash.o serialize.o stubs.o
	$(CC) $(CFLAGS) arith01.o arith02.o arith03.o arith04.o arith05.o \
		arith06.o arith07.o arith08.o arith09.o arith10.o \
		arith11.o arith12.o arith13.o arith14.o bytes.o char.o \
		csl.o cslmpi.o cslread.o eval1.o eval2.o eval3.o \
		eval4.o fasl.o fns1.o fns2.o fns3.o fwin.o cslgc.o \
		preserve.o print.o restart.o sysfwin.o termed.o \
		inthash.o serialize.o stubs.o \
		-lcrlibm -lsoftfloat -lm -o reduce

.cpp.o:                                                                          <
	$(CC) $(CFLAGS) -c -o $@ $<

# Create the reduce.img file

reduce.img:	reduce
	-rm -f reduce.img
	./reduce -z -Dminireduce -Dno_init_file $(S)/buildreduce.lsp \
		-D@srcdir=$(S) -D@reduce=$(R) -o reduce.img -- image.log

make-image:	../make-image.cpp
	$(CC) $(CFLAGS) ../make-image.cpp -o make-image

image.cpp:	make-image reduce.img
	./make-image
	cp image.cpp ../minireduce-image.cpp
	cp reduce.img ..
clean:
	-rm -f *.o reduce hello reduce.img image.log make-image image.cpp

HEADERS = config.h \
	$(S)/arith.h $(S)/bytes.h $(S)/clsyms.h $(S)/cslerror.h \
	$(S)/cslread.h $(S)/entries.h $(S)/externs.h $(S)/fwin.h \
	$(S)/headers.h $(S)/machine.h $(S)/proc.h $(S)/sockhdr.h \
	$(S)/stream.h $(S)/syscsl.h $(S)/tags.h $(S)/termed.h \
	$(S)/version.h

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
preserve.o:	$(S)/preserve.cpp $(HEADERS)
print.o:	$(S)/print.cpp $(HEADERS)
restart.o:	$(S)/restart.cpp machineid.cpp $(HEADERS)
sysfwin.o:	$(S)/sysfwin.cpp $(HEADERS)
termed.o:	$(S)/termed.cpp $(HEADERS)
inthash.o:	$(S)/inthash.cpp $(HEADERS)
serialize.o:	$(S)/serialize.cpp $(HEADERS)

# end of Makefile

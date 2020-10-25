# Makefile for building reduce.img suitable for embedded use.

# This version uses em++ to create a javascript version.


# For a FULL bootstrapped build you need to go
#
#    make bootstrapreduce.img
#    rm bootstrapreduce.img; make bootstrapreduce.img
#    make c-code
#    make reduce.img
#
# The repeated build of bootstrapreduce.img is so that forward references
# to inline functions end up coped with properly.

# NOTE that my going "make USERFLAGS="-O0 -g" it is possible to override this
# optimization level and get a debugging build.
OPT=-O2

CC=em++ -s DISABLE_EXCEPTION_CATCHING=0 -s STACK_OVERFLOW_CHECK=2 \
        -s EXIT_RUNTIME=1 -s TOTAL_STACK=5mb \
        -s MALLOC="dlmalloc" -s INITIAL_MEMORY=16777216 \
        -s ALLOW_MEMORY_GROWTH=1 -s SAFE_HEAP=1 \
        -s DEMANGLE_SUPPORT=1 -s USE_ZLIB

CPPFLAGS=$(CFLAGS) -std=gnu++17 $(OPT) -I. -I../include -Iinclude -I$(S) \
    -DHAVE_CONFIG_H=1 -DEMBEDDED=1 $(XCFLAGS) $(USERFLAGS)
LIBS=$(XLIBS) -s USE_ZLIB -Lcrlibm -lcrlibm

JSOPTS= -s ERROR_ON_UNDEFINED_SYMBOLS=0 -g4 \
	-s ALLOW_MEMORY_GROWTH=1 \
	-s DISABLE_EXCEPTION_CATCHING=0 \
	--source-map-base http://localhost:8000/new-embedded/reduce-image/

JS_SRC=../js

# --pre-js mountfs.js \

NODEOPTS= -s NODERAWFS=1
WEBOPTS= --preload-file reduce.img --shell-file $(JS_SRC)/template.html
REDUCE_TARGET=reduce.js

ifndef WEB
 JSOPTS += $(NODEOPTS)
else
 ifeq (WEB,0)
 	JSOPTS += $(NODEOPTS)
 else
 	JSOPTS += $(WEBOPTS)
 	REDUCE_TARGET=reduce.html
 endif
endif


S=../../cslbase
R=../../..

VPATH=$(S)

all:	reduce.js reduce.img image.cpp

bootstrapreduce.js:		allocate.o arith01.o arith02.o arith03.o arith04.o arith05.o \
		arith06.o arith07.o arith08.o arith09.o arith10.o \
		arith11.o arith12.o arith13.o arith14.o bytes.o char.o \
		csl.o cslmpi.o cslread.o eval1.o eval2.o eval3.o \
		eval4.o fasl.o fns1.o fns2.o fns3.o fwin.o cslgc.o lisphash.o \
		isprime.o preserve.o print.o restart.o sysfwin.o termed.o \
		inthash.o serialize.o stubs.o
	$(CC) allocate.o arith01.o arith02.o arith03.o arith04.o arith05.o \
		arith06.o arith07.o arith08.o arith09.o arith10.o \
		arith11.o arith12.o arith13.o arith14.o bytes.o char.o \
		csl.o cslmpi.o cslread.o eval1.o eval2.o eval3.o \
		eval4.o fasl.o fns1.o fns2.o fns3.o fwin.o cslgc.o lisphash.o \
		isprime.o preserve.o print.o restart.o sysfwin.o termed.o \
		inthash.o serialize.o stubs.o \
		$(LIBS) $(JSOPTS) -o bootstrapreduce.js

.PHONY:	bootstrapreduce
bootstrapreduce:	bootstrapreduce.js
	echo Building bootstrapreduce.js

# I am going to build both reduce and bootstrapreduce in the same directory
# and they use overlapping source files. To keep things clean I put the object
# files for one versionwith suffix .o and the other .oo.

.cpp.o:
	$(CC) $(CPPFLAGS) -c -o $@ $<

.SUFFIXES:	.oo

.cpp.oo:
	$(CC) $(CPPFLAGS) -c -o $@ $<

# Create the bootstrapreduce.img file

bootstrapreduce.img:	bootstrapreduce.js
	-rm -f bootstrapreduce.img
	node bootstrapreduce.js -z -Dno_init_file $(S)/buildreduce.lsp -Dbootstrap \
		-D@srcdir=$(S) -D@reduce=$(R) -o bootstrapreduce.img -L bootstrap_image.log


c-code:	bootstrapreduce.img
	node bootstrapreduce.js -w $(CSLFLAGS) \
		-Dno_init_file \
		$(S)/make-c-code.red \
		-D@destdir=$(R)/cslbuild/generated-c \
		-Dhow_many=$(how_many) -Dsize_per_file=$(size_per_file) \
		-L c-code.log


# Now the full version.

reduce.js:		allocate.oo arith01.oo arith02.oo arith03.oo arith04.oo arith05.oo \
		arith06.oo arith07.oo arith08.oo arith09.oo arith10.oo \
		arith11.oo arith12.oo arith13.oo arith14.oo bytes.oo char.oo \
		csl.oo cslmpi.oo cslread.oo eval1.oo eval2.oo eval3.oo \
		eval4.oo fasl.oo fns1.oo fns2.oo fns3.oo fwin.oo cslgc.oo lisphash.oo \
		isprime.oo preserve.oo print.oo restart.oo sysfwin.oo termed.oo \
		inthash.oo serialize.oo \
		u01.oo u02.oo u03.oo u04.oo u05.oo u06.oo u07.oo u08.oo u09.oo u10.oo \
		u11.oo u12.oo u13.oo u14.oo u15.oo u16.oo u17.oo u18.oo u19.oo u20.oo \
		u21.oo u22.oo u23.oo u24.oo u25.oo u26.oo u27.oo u28.oo u29.oo u30.oo \
		u31.oo u32.oo u33.oo u34.oo u35.oo u36.oo u37.oo u38.oo u39.oo u40.oo \
		u41.oo u42.oo u43.oo u44.oo u45.oo u46.oo u47.oo u48.oo u49.oo u50.oo \
		u51.oo u52.oo u53.oo u54.oo u55.oo u56.oo u57.oo u58.oo u59.oo u60.oo
	$(CC) allocate.oo arith01.oo arith02.oo arith03.oo arith04.oo arith05.oo \
		arith06.oo arith07.oo arith08.oo arith09.oo arith10.oo \
		arith11.oo arith12.oo arith13.oo arith14.oo bytes.oo char.oo \
		csl.oo cslmpi.oo cslread.oo eval1.oo eval2.oo eval3.oo \
		eval4.oo fasl.oo fns1.oo fns2.oo fns3.oo fwin.oo cslgc.oo lisphash.oo \
		isprime.oo preserve.oo print.oo restart.oo sysfwin.oo termed.oo \
		inthash.oo serialize.oo \
		u01.oo u02.oo u03.oo u04.oo u05.oo u06.oo u07.oo u08.oo u09.oo u10.oo \
		u11.oo u12.oo u13.oo u14.oo u15.oo u16.oo u17.oo u18.oo u19.oo u20.oo \
		u21.oo u22.oo u23.oo u24.oo u25.oo u26.oo u27.oo u28.oo u29.oo u30.oo \
		u31.oo u32.oo u33.oo u34.oo u35.oo u36.oo u37.oo u38.oo u39.oo u40.oo \
		u41.oo u42.oo u43.oo u44.oo u45.oo u46.oo u47.oo u48.oo u49.oo u50.oo \
		u51.oo u52.oo u53.oo u54.oo u55.oo u56.oo u57.oo u58.oo u59.oo u60.oo \
		$(LIBS) $(JSOPTS) -o $(REDUCE_TARGET)

.PHONY:	reduce
reduce:	reduce.js
	echo Building $(REDUCE_TARGET)

reduce.img:	reduce.js
	-rm -f reduce.img
	export reduce=$(R) && node reduce.js -z -Dforce_c_code -Dno_init_file $(S)/buildreduce.lsp \
		-D@srcdir=$(S) -D@reduce=$(R) -o reduce.img -L reduce_image.log

make-image.js:	$(S)/make-image.cpp
	$(CC) $(CPPFLAGS) $(S)/hexify.cpp $(LIBS) $(JSOPTS) -o make-image.js

image.cpp:	make-image.js reduce.img
	node make-image.js
	cp image.cpp ../reduce-image.cpp
	cp reduce.img ..

clean:
	-rm -f *.o *.oo reduce* *.log make-image* image.cpp
	-rm -f bootstrapreduce* *.bak *.map

HEADERS = ../include/config.h \
	$(S)/md5.h       $(S)/termed.h    $(S)/arith.h       $(S)/openmath.h \
	$(S)/bigvector.h $(S)/entries.h     $(S)/proc.h     \
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
restart.o:	$(S)/restart.cpp $(HEADERS)
sysfwin.o:	$(S)/sysfwin.cpp $(HEADERS)
termed.o:	$(S)/termed.cpp $(HEADERS)
inthash.o:	$(S)/inthash.cpp $(HEADERS)
serialize.o:	$(S)/serialize.cpp $(HEADERS)

makeheaders.o:	$(S)/makeheaders.cpp
objtype.o:	$(S)/objtype.cpp

allocate.oo:	$(S)/allocate.cpp $(HEADERS)
arith01.oo:	$(S)/arith01.cpp $(HEADERS)
arith02.oo:	$(S)/arith02.cpp $(HEADERS)
arith03.oo:	$(S)/arith03.cpp $(HEADERS)
arith04.oo:	$(S)/arith04.cpp $(HEADERS)
arith05.oo:	$(S)/arith05.cpp $(HEADERS)
arith06.oo:	$(S)/arith06.cpp $(HEADERS)
arith07.oo:	$(S)/arith07.cpp $(HEADERS)
arith08.oo:	$(S)/arith08.cpp $(HEADERS)
arith09.oo:	$(S)/arith09.cpp $(HEADERS)
arith10.oo:	$(S)/arith10.cpp $(HEADERS)
arith11.oo:	$(S)/arith11.cpp $(HEADERS)
arith12.oo:	$(S)/arith12.cpp $(HEADERS)
arith13.oo:	$(S)/arith13.cpp $(HEADERS)
arith14.oo:	$(S)/arith14.cpp $(HEADERS)
bytes.oo:	$(S)/bytes.cpp $(HEADERS)
bytes1.oo:	$(S)/bytes1.cpp $(S)/opnames.cpp $(HEADERS)
char.oo:		$(S)/char.cpp $(HEADERS)
csl.oo:		$(S)/csl.cpp $(HEADERS)
cslmpi.oo:	$(S)/cslmpi.cpp $(S)/mpipack.cpp $(HEADERS)
cslread.oo:	$(S)/cslread.cpp $(HEADERS)
driver.oo:	$(S)/driver.cpp $(HEADERS)
embedcsl.oo:	$(S)/embedcsl.cpp $(S)/csl.cpp $(HEADERS)
eval1.oo:	$(S)/eval1.cpp $(HEADERS)
eval2.oo:	$(S)/eval2.cpp $(HEADERS)
eval3.oo:	$(S)/eval3.cpp $(HEADERS)
eval4.oo:	$(S)/eval4.cpp $(HEADERS)
fasl.oo:		$(S)/fasl.cpp $(HEADERS)
fns1.oo:		$(S)/fns1.cpp $(HEADERS)
fns2.oo:		$(S)/fns2.cpp $(HEADERS)
fns3.oo:		$(S)/fns3.cpp $(HEADERS)
fwin.oo:		$(S)/fwin.cpp $(HEADERS)
cslgc.oo:	$(S)/cslgc.cpp $(HEADERS)
lisphash.oo:	$(S)/lisphash.cpp $(HEADERS)
isprime.oo:	$(S)/isprime.cpp $(HEADERS)
preserve.oo:	$(S)/preserve.cpp $(HEADERS)
print.oo:	$(S)/print.cpp $(HEADERS)
restart.oo:	$(S)/restart.cpp $(HEADERS)
sysfwin.oo:	$(S)/sysfwin.cpp $(HEADERS)
termed.oo:	$(S)/termed.cpp $(HEADERS)
inthash.oo:	$(S)/inthash.cpp $(HEADERS)
serialize.oo:	$(S)/serialize.cpp $(HEADERS)
u01.oo:		$(S)/u01.cpp $(HEADERS)
u02.oo:		$(S)/u02.cpp $(HEADERS)
u03.oo:		$(S)/u03.cpp $(HEADERS)
u04.oo:		$(S)/u04.cpp $(HEADERS)
u05.oo:		$(S)/u05.cpp $(HEADERS)
u06.oo:		$(S)/u06.cpp $(HEADERS)
u07.oo:		$(S)/u07.cpp $(HEADERS)
u08.oo:		$(S)/u08.cpp $(HEADERS)
u09.oo:		$(S)/u09.cpp $(HEADERS)
u10.oo:		$(S)/u10.cpp $(HEADERS)
u11.oo:		$(S)/u11.cpp $(HEADERS)
u12.oo:		$(S)/u12.cpp $(HEADERS)
u13.oo:		$(S)/u13.cpp $(HEADERS)
u14.oo:		$(S)/u14.cpp $(HEADERS)
u15.oo:		$(S)/u15.cpp $(HEADERS)
u16.oo:		$(S)/u16.cpp $(HEADERS)
u17.oo:		$(S)/u17.cpp $(HEADERS)
u18.oo:		$(S)/u18.cpp $(HEADERS)
u19.oo:		$(S)/u19.cpp $(HEADERS)
u20.oo:		$(S)/u20.cpp $(HEADERS)
u21.oo:		$(S)/u21.cpp $(HEADERS)
u22.oo:		$(S)/u22.cpp $(HEADERS)
u23.oo:		$(S)/u23.cpp $(HEADERS)
u24.oo:		$(S)/u24.cpp $(HEADERS)
u25.oo:		$(S)/u25.cpp $(HEADERS)
u26.oo:		$(S)/u26.cpp $(HEADERS)
u27.oo:		$(S)/u27.cpp $(HEADERS)
u28.oo:		$(S)/u28.cpp $(HEADERS)
u29.oo:		$(S)/u29.cpp $(HEADERS)
u30.oo:		$(S)/u30.cpp $(HEADERS)
u31.oo:		$(S)/u31.cpp $(HEADERS)
u32.oo:		$(S)/u32.cpp $(HEADERS)
u33.oo:		$(S)/u33.cpp $(HEADERS)
u34.oo:		$(S)/u34.cpp $(HEADERS)
u35.oo:		$(S)/u35.cpp $(HEADERS)
u36.oo:		$(S)/u36.cpp $(HEADERS)
u37.oo:		$(S)/u37.cpp $(HEADERS)
u38.oo:		$(S)/u38.cpp $(HEADERS)
u39.oo:		$(S)/u39.cpp $(HEADERS)
u40.oo:		$(S)/u40.cpp $(HEADERS)
u41.oo:		$(S)/u41.cpp $(HEADERS)
u42.oo:		$(S)/u42.cpp $(HEADERS)
u43.oo:		$(S)/u43.cpp $(HEADERS)
u44.oo:		$(S)/u44.cpp $(HEADERS)
u45.oo:		$(S)/u45.cpp $(HEADERS)
u46.oo:		$(S)/u46.cpp $(HEADERS)
u47.oo:		$(S)/u47.cpp $(HEADERS)
u48.oo:		$(S)/u48.cpp $(HEADERS)
u49.oo:		$(S)/u49.cpp $(HEADERS)
u50.oo:		$(S)/u50.cpp $(HEADERS)
u51.oo:		$(S)/u51.cpp $(HEADERS)
u52.oo:		$(S)/u52.cpp $(HEADERS)
u53.oo:		$(S)/u53.cpp $(HEADERS)
u54.oo:		$(S)/u54.cpp $(HEADERS)
u55.oo:		$(S)/u55.cpp $(HEADERS)
u56.oo:		$(S)/u56.cpp $(HEADERS)
u57.oo:		$(S)/u57.cpp $(HEADERS)
u58.oo:		$(S)/u58.cpp $(HEADERS)
u59.oo:		$(S)/u59.cpp $(HEADERS)
u60.oo:		$(S)/u60.cpp $(HEADERS)

# end of Makefile

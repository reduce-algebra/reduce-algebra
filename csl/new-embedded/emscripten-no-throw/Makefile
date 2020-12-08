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
# to debug with sourcemaps, -g4 and -g must be used, eg USERFLAGS="-O0 -g -g4"

OPT=-O3

CC=em++

EMFLAGS:=$(shell source ./emflags.sh && echo $$EMFLAGS)
# EMFLAGS+= -s EXPORTED_FUNCTIONS="['_main', '_insert_buffer']"

#ASYNC_FUNCTIONS:=$(shell source ./asyncfuns.sh stack_trace_*.txt && echo $$cfuns)
#ASYNC_IMPORTS:=$(shell source ./asyncfuns.sh stack_trace_*.txt && echo $$jsimports)

CPPFLAGS=$(EMFLAGS) -std=gnu++17 $(OPT) -I. -I../include -Iinclude -I$(S) \
    -DHAVE_CONFIG_H=1 -DHAVE_CRLIBM=1 -DEMBEDDED=1 $(XCFLAGS) $(USERFLAGS)
CFLAGS=$(EMFLAGS)
CXXFLAGS=$(EMFLAGS)
LDFLAGS=$(EMFLAGS) -Llib -lcrlibm
LIBS=-lcrlibm

JSOPTS= --source-map-base http://localhost:8000/ $(USERFLAGS)

JS_SRC=js

# --pre-js mountfs.js \

# On at least one Linux machine I find that if I launch things by using
# a command like   "node bootstrapreduce.js"   I get a failure, but if I
# use a fully-rooted path for the "node" command all is well. I do not
# understand! But this setting for NODE arranges the careful scheme for me.
NODE= $(shell which node)
NODEOPTS= -s NODERAWFS=1 \
	-s FORCE_FILESYSTEM=1 \

#WEBOPTS= --preload-file reduce.img \
#	--shell-file $(JS_SRC)/shell_emterm.html \
#	-s ENVIRONMENT=web
PRE_JS=$(JS_SRC)/init.js
WEBOPTS= --pre-js $(PRE_JS) \
	-s ENVIRONMENT=worker \
	-s BUILD_AS_WORKER=1 \
	--js-library $(JS_SRC)/io.js
# -s MODULARIZE=1 -s 'EXPORT_NAME="reduceModule"' \

# JSOPTS += $(WEBOPTS)


#ASYNCIFY_OPTS = -s ASYNCIFY \
#	$(ASYNC_IMPORTS) \
#	$(ASYNC_FUNCTIONS) \
#	-s ASYNCIFY_ADVISE \
#	-DWASM_ASYNC_IO=1 \
#	-s ASYNCIFY_IGNORE_INDIRECT
#	-s ASYNCIFY_STACK_SIZE=1048576

#ifndef WEB
# JSOPTS += $(NODEOPTS)
#else
# ifeq (WEB,0)
# 	JSOPTS += $(NODEOPTS)
# else
# 	JSOPTS += $(WEBOPTS)
# 	REDUCE_TARGET=reduce.html
# endif
#endif


S=../../cslbase-nothrow
R=../../..

VPATH=$(S)

all:	reduce.js reduce.img image.cpp

include/crlibm.h lib/libcrlibm.a:	emflags.sh make-crlibm.sh
	./make-crlibm.sh

bootstrapreduce.js:		allocate.o arith01.o arith02.o arith03.o arith04.o arith05.o \
		arith06.o arith07.o arith08.o arith09.o arith10.o \
		arith11.o arith12.o arith13.o arith14.o bytes.o char.o \
		csl.o cslmpi.o cslread.o eval1.o eval2.o eval3.o \
		eval4.o fasl.o fns1.o fns2.o fns3.o fwin.o cslgc.o lisphash.o \
		isprime.o preserve.o print.o restart.o sysfwin.o termed.o \
		inthash.o serialize.o stubs.o lib/libcrlibm.a
	$(CC) allocate.o arith01.o arith02.o arith03.o arith04.o arith05.o \
		arith06.o arith07.o arith08.o arith09.o arith10.o \
		arith11.o arith12.o arith13.o arith14.o bytes.o char.o \
		csl.o cslmpi.o cslread.o eval1.o eval2.o eval3.o \
		eval4.o fasl.o fns1.o fns2.o fns3.o fwin.o cslgc.o lisphash.o \
		isprime.o preserve.o print.o restart.o sysfwin.o termed.o \
		inthash.o serialize.o stubs.o \
		$(LDFLAGS) $(NODEOPTS) $(LIBS) $(JSOPTS) -o bootstrapreduce.js

.PHONY:	bootstrapreduce
bootstrapreduce:	bootstrapreduce.js
	echo Building bootstrapreduce.js

# I am going to build both reduce and bootstrapreduce in the same directory
# and they use overlapping source files. To keep things clean I put the object
# files for one versionwith suffix .o and the other .oo.
# Avery: I'm also going to add .ooo for object files which have been compiled
# with the asynchronous javascript IO library (just so we don't have to rebuild
# each time we want to switch between node/browser)

.cpp.o:
	$(CC) $(CPPFLAGS) $(NODEOPTS) -c -o $@ $<

.SUFFIXES:	.oo .ooo

.cpp.oo:
	$(CC) $(CPPFLAGS) $(NODEOPTS) -c -o $@ $<

# don't use NODEOPTS here, because we want a virtual FS
.cpp.ooo:
	$(CC) $(CPPFLAGS) -DPROCEDURAL_WASM_XX=1 $(ASYNCIFY_OPTS) -c -o $@ $<

#csl.ooo: csl.cpp
#	$(CC) $(CPPFLAGS) $(ASYNCIFY_OPTS) -c -o $@ $<
#cslread.ooo: cslread.cpp
#	$(CC) $(CPPFLAGS) $(ASYNCIFY_OPTS) -c -o $@ $<
# Create the bootstrapreduce.img file

bootstrapreduce.img:	bootstrapreduce.js
	-rm -f bootstrapreduce.img
	$(NODE) bootstrapreduce.js -z -Dno_init_file $(S)/buildreduce.lsp -Dbootstrap \
		-D@srcdir=$(S) -D@reduce=$(R) -o bootstrapreduce.img -L bootstrap_image.log


c-code:	bootstrapreduce.img
	$(NODE) bootstrapreduce.js -w $(CSLFLAGS) \
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
		$(LDFLAGS) $(NODEOPTS) $(LIBS) $(JSOPTS) -o reduce.js

# The web-based (non-node) version

reduce.web.wasm:	allocate.ooo arith01.ooo arith02.ooo arith03.ooo arith04.ooo arith05.ooo \
		arith06.ooo arith07.ooo arith08.ooo arith09.ooo arith10.ooo \
		arith11.ooo arith12.ooo arith13.ooo arith14.ooo bytes.ooo char.ooo \
		csl.ooo cslmpi.ooo cslread.ooo eval1.ooo eval2.ooo eval3.ooo \
		eval4.ooo fasl.ooo fns1.ooo fns2.ooo fns3.ooo fwin.ooo cslgc.ooo lisphash.ooo \
		isprime.ooo preserve.ooo print.ooo restart.ooo sysfwin.ooo termed.ooo \
		inthash.ooo serialize.ooo \
		u01.ooo u02.ooo u03.ooo u04.ooo u05.ooo u06.ooo u07.ooo u08.ooo u09.ooo u10.ooo \
		u11.ooo u12.ooo u13.ooo u14.ooo u15.ooo u16.ooo u17.ooo u18.ooo u19.ooo u20.ooo \
		u21.ooo u22.ooo u23.ooo u24.ooo u25.ooo u26.ooo u27.ooo u28.ooo u29.ooo u30.ooo \
		u31.ooo u32.ooo u33.ooo u34.ooo u35.ooo u36.ooo u37.ooo u38.ooo u39.ooo u40.ooo \
		u41.ooo u42.ooo u43.ooo u44.ooo u45.ooo u46.ooo u47.ooo u48.ooo u49.ooo u50.ooo \
		u51.ooo u52.ooo u53.ooo u54.ooo u55.ooo u56.ooo u57.ooo u58.ooo u59.ooo u60.ooo
	$(CC) allocate.ooo arith01.ooo arith02.ooo arith03.ooo arith04.ooo arith05.ooo \
		arith06.ooo arith07.ooo arith08.ooo arith09.ooo arith10.ooo \
		arith11.ooo arith12.ooo arith13.ooo arith14.ooo bytes.ooo char.ooo \
		csl.ooo cslmpi.ooo cslread.ooo eval1.ooo eval2.ooo eval3.ooo \
		eval4.ooo fasl.ooo fns1.ooo fns2.ooo fns3.ooo fwin.ooo cslgc.ooo lisphash.ooo \
		isprime.ooo preserve.ooo print.ooo restart.ooo sysfwin.ooo termed.ooo \
		inthash.ooo serialize.ooo \
		u01.ooo u02.ooo u03.ooo u04.ooo u05.ooo u06.ooo u07.ooo u08.ooo u09.ooo u10.ooo \
		u11.ooo u12.ooo u13.ooo u14.ooo u15.ooo u16.ooo u17.ooo u18.ooo u19.ooo u20.ooo \
		u21.ooo u22.ooo u23.ooo u24.ooo u25.ooo u26.ooo u27.ooo u28.ooo u29.ooo u30.ooo \
		u31.ooo u32.ooo u33.ooo u34.ooo u35.ooo u36.ooo u37.ooo u38.ooo u39.ooo u40.ooo \
		u41.ooo u42.ooo u43.ooo u44.ooo u45.ooo u46.ooo u47.ooo u48.ooo u49.ooo u50.ooo \
		u51.ooo u52.ooo u53.ooo u54.ooo u55.ooo u56.ooo u57.ooo u58.ooo u59.ooo u60.ooo \
		$(LDFLAGS) $(LIBS) $(JSOPTS) $(ASYNCIFY_OPTS) $(WEBOPTS) \
		-s EXPORTED_FUNCTIONS="['_main', '_insert_buffer']" \
		-o reduce.web.js


.PHONY:	reduce
reduce:	reduce.js
	echo Building reduce.js


.PHONY: reduce-web
reduce-web: reduce.web.wasm
	echo Building reduce worker

reduce.img:	reduce.js
	-rm -f reduce.img
	export reduce=$(R) && $(NODE) reduce.js -z -Dforce_c_code -Dno_init_file $(S)/buildreduce.lsp \
		-D@srcdir=$(S) -D@reduce=$(R) -o reduce.img -L reduce_image.log

# same as above, because we just want the image, and that is built by the node version
reduce.img.worker:	reduce.img reduce-web
#export reduce=$(R) && $(NODE) reduce.js -z -Dforce_c_code -Dno_init_file $(S)/buildreduce.lsp \
#	-D@srcdir=$(S) -D@reduce=$(R) -o reduce.img -L reduce_image.log


make-image.js:	$(S)/make-image.cpp
	$(CC) $(CPPFLAGS) $(NODEOPTS) $(S)/hexify.cpp $(LDFLAGS) $(LIBS) $(JSOPTS) -o make-image.js

image.cpp:	make-image.js reduce.img
	$(NODE) make-image.js
	cp image.cpp ../reduce-image.cpp
	cp reduce.img ..

clean:
	-rm -f *.o *.oo *.ooo reduce* *.log make-image* image.cpp
	-rm -f bootstrapreduce* *.bak *.map
	-rm -rf crlibm include lib bin jscsl-times

HEADERS = ../include/config.h include/crlibm.h \
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

allocate.ooo:	$(S)/allocate.cpp $(HEADERS)
arith01.ooo:	$(S)/arith01.cpp $(HEADERS)
arith02.ooo:	$(S)/arith02.cpp $(HEADERS)
arith03.ooo:	$(S)/arith03.cpp $(HEADERS)
arith04.ooo:	$(S)/arith04.cpp $(HEADERS)
arith05.ooo:	$(S)/arith05.cpp $(HEADERS)
arith06.ooo:	$(S)/arith06.cpp $(HEADERS)
arith07.ooo:	$(S)/arith07.cpp $(HEADERS)
arith08.ooo:	$(S)/arith08.cpp $(HEADERS)
arith09.ooo:	$(S)/arith09.cpp $(HEADERS)
arith10.ooo:	$(S)/arith10.cpp $(HEADERS)
arith11.ooo:	$(S)/arith11.cpp $(HEADERS)
arith12.ooo:	$(S)/arith12.cpp $(HEADERS)
arith13.ooo:	$(S)/arith13.cpp $(HEADERS)
arith14.ooo:	$(S)/arith14.cpp $(HEADERS)
bytes.ooo:		$(S)/bytes.cpp $(HEADERS)
bytes1.ooo:		$(S)/bytes1.cpp $(S)/opnames.cpp $(HEADERS)
char.ooo:		$(S)/char.cpp $(HEADERS)
csl.ooo:		$(S)/csl.cpp $(HEADERS)
cslmpi.ooo:		$(S)/cslmpi.cpp $(S)/mpipack.cpp $(HEADERS)
cslread.ooo:	$(S)/cslread.cpp $(HEADERS)
driver.ooo:		$(S)/driver.cpp $(HEADERS)
embedcsl.ooo:	$(S)/embedcsl.cpp $(S)/csl.cpp $(HEADERS)
eval1.ooo:		$(S)/eval1.cpp $(HEADERS)
eval2.ooo:		$(S)/eval2.cpp $(HEADERS)
eval3.ooo:		$(S)/eval3.cpp $(HEADERS)
eval4.ooo:		$(S)/eval4.cpp $(HEADERS)
fasl.ooo:		$(S)/fasl.cpp $(HEADERS)
fns1.ooo:		$(S)/fns1.cpp $(HEADERS)
fns2.ooo:		$(S)/fns2.cpp $(HEADERS)
fns3.ooo:		$(S)/fns3.cpp $(HEADERS)
fwin.ooo:		$(S)/fwin.cpp $(HEADERS)
cslgc.ooo:		$(S)/cslgc.cpp $(HEADERS)
lisphash.ooo:	$(S)/lisphash.cpp $(HEADERS)
isprime.ooo:	$(S)/isprime.cpp $(HEADERS)
preserve.ooo:	$(S)/preserve.cpp $(HEADERS)
print.ooo:		$(S)/print.cpp $(HEADERS)
restart.ooo:	$(S)/restart.cpp $(HEADERS)
sysfwin.ooo:	$(S)/sysfwin.cpp $(HEADERS)
termed.ooo:		$(S)/termed.cpp $(HEADERS)
inthash.ooo:	$(S)/inthash.cpp $(HEADERS)
serialize.ooo:	$(S)/serialize.cpp $(HEADERS)
u01.ooo:		$(S)/u01.cpp $(HEADERS)
u02.ooo:		$(S)/u02.cpp $(HEADERS)
u03.ooo:		$(S)/u03.cpp $(HEADERS)
u04.ooo:		$(S)/u04.cpp $(HEADERS)
u05.ooo:		$(S)/u05.cpp $(HEADERS)
u06.ooo:		$(S)/u06.cpp $(HEADERS)
u07.ooo:		$(S)/u07.cpp $(HEADERS)
u08.ooo:		$(S)/u08.cpp $(HEADERS)
u09.ooo:		$(S)/u09.cpp $(HEADERS)
u10.ooo:		$(S)/u10.cpp $(HEADERS)
u11.ooo:		$(S)/u11.cpp $(HEADERS)
u12.ooo:		$(S)/u12.cpp $(HEADERS)
u13.ooo:		$(S)/u13.cpp $(HEADERS)
u14.ooo:		$(S)/u14.cpp $(HEADERS)
u15.ooo:		$(S)/u15.cpp $(HEADERS)
u16.ooo:		$(S)/u16.cpp $(HEADERS)
u17.ooo:		$(S)/u17.cpp $(HEADERS)
u18.ooo:		$(S)/u18.cpp $(HEADERS)
u19.ooo:		$(S)/u19.cpp $(HEADERS)
u20.ooo:		$(S)/u20.cpp $(HEADERS)
u21.ooo:		$(S)/u21.cpp $(HEADERS)
u22.ooo:		$(S)/u22.cpp $(HEADERS)
u23.ooo:		$(S)/u23.cpp $(HEADERS)
u24.ooo:		$(S)/u24.cpp $(HEADERS)
u25.ooo:		$(S)/u25.cpp $(HEADERS)
u26.ooo:		$(S)/u26.cpp $(HEADERS)
u27.ooo:		$(S)/u27.cpp $(HEADERS)
u28.ooo:		$(S)/u28.cpp $(HEADERS)
u29.ooo:		$(S)/u29.cpp $(HEADERS)
u30.ooo:		$(S)/u30.cpp $(HEADERS)
u31.ooo:		$(S)/u31.cpp $(HEADERS)
u32.ooo:		$(S)/u32.cpp $(HEADERS)
u33.ooo:		$(S)/u33.cpp $(HEADERS)
u34.ooo:		$(S)/u34.cpp $(HEADERS)
u35.ooo:		$(S)/u35.cpp $(HEADERS)
u36.ooo:		$(S)/u36.cpp $(HEADERS)
u37.ooo:		$(S)/u37.cpp $(HEADERS)
u38.ooo:		$(S)/u38.cpp $(HEADERS)
u39.ooo:		$(S)/u39.cpp $(HEADERS)
u40.ooo:		$(S)/u40.cpp $(HEADERS)
u41.ooo:		$(S)/u41.cpp $(HEADERS)
u42.ooo:		$(S)/u42.cpp $(HEADERS)
u43.ooo:		$(S)/u43.cpp $(HEADERS)
u44.ooo:		$(S)/u44.cpp $(HEADERS)
u45.ooo:		$(S)/u45.cpp $(HEADERS)
u46.ooo:		$(S)/u46.cpp $(HEADERS)
u47.ooo:		$(S)/u47.cpp $(HEADERS)
u48.ooo:		$(S)/u48.cpp $(HEADERS)
u49.ooo:		$(S)/u49.cpp $(HEADERS)
u50.ooo:		$(S)/u50.cpp $(HEADERS)
u51.ooo:		$(S)/u51.cpp $(HEADERS)
u52.ooo:		$(S)/u52.cpp $(HEADERS)
u53.ooo:		$(S)/u53.cpp $(HEADERS)
u54.ooo:		$(S)/u54.cpp $(HEADERS)
u55.ooo:		$(S)/u55.cpp $(HEADERS)
u56.ooo:		$(S)/u56.cpp $(HEADERS)
u57.ooo:		$(S)/u57.cpp $(HEADERS)
u58.ooo:		$(S)/u58.cpp $(HEADERS)
u59.ooo:		$(S)/u59.cpp $(HEADERS)
u60.ooo:		$(S)/u60.cpp $(HEADERS)

# end of Makefile

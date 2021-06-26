# Makefile for building reduce.img suitable for embedded use.
#    Arthur Norman & Avery Laird, 2020 - 2021.


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

# NOTE that by going "make USERFLAGS="-O0 -g" it is possible to override this
# optimization level and get a debugging build.
# to debug with sourcemaps, -g4 and -g must be used, eg USERFLAGS="-O0 -g -g4"

OPT=-Oz

# with certain emscripten builds, the linker can take a long time.
# linking with a lower opt level, like O0, may help with this.
LINK_OPT=$(OPT)

CXX=em++

EMFLAGS:=$(shell . ./emflags.sh && echo $$EMFLAGS)

#ASYNC_FUNCTIONS:=$(shell source ./asyncfuns.sh stack_trace_*.txt && echo $$cfuns)
#ASYNC_IMPORTS:=$(shell source ./asyncfuns.sh stack_trace_*.txt && echo $$jsimports)

CPPFLAGS=$(EMFLAGS) \
	 -std=gnu++17 $(OPT) -I. -I../include -Iinclude -I$(S) \
	-DHAVE_CONFIG_H=1 -DNO_THROW=1 -DHAVE_CRLIBM=1 \
	-DEMBEDDED=1 $(XCFLAGS) $(USERFLAGS)
CFLAGS=$(EMFLAGS)
CXXFLAGS=$(EMFLAGS)
LDFLAGS=$(EMFLAGS) -Llib -lcrlibm
LIBS=-lcrlibm

JSOPTS= $(USERFLAGS)
# --source-map-base http://localhost:8000/

JS_SRC=js

# --pre-js mountfs.js \

# On at least one Linux machine I find that if I launch things by using
# a command like   "node bootstrapreduce.js"   I get a failure, but if I
# use a fully-rooted path for the "node" command all is well. I do not
# understand! But this setting for NODE arranges the careful scheme for me.
NODE= $(shell which node)

NODEOPTS= -s NODERAWFS=1 -s FORCE_FILESYSTEM=1 \

PRE_JS=$(JS_SRC)/init.js
WEBOPTS= --pre-js $(PRE_JS) \
	-s ENVIRONMENT=worker \
	-s BUILD_AS_WORKER=1 \
	--js-library $(JS_SRC)/io.js


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

S=../../cslbase
R=../../..

VPATH=$(S)

all:	reduce.js reduce.img image.cpp

include/crlibm.h lib/libcrlibm.a:	emflags.sh make-crlibm.sh
	./make-crlibm.sh

bootstrapreduce.js:	allocate.o arith01.o arith02.o arith03.o arith04.o \
		arith05.o arith06.o arith07.o arith08.o arith09.o arith10.o \
		arith11.o arith12.o arith13.o arith14.o bytes1.o char.o \
		csl.o cslmpi.o cslread.o eval1.o eval2.o eval3.o \
		eval4.o fasl.o fns1.o fns2.o fns3.o fwin.o cslgc.o lisphash.o \
		isprime.o preserve.o print.o restart.o sysfwin.o termed.o \
		inthash.o serialize.o stubs.o lib/libcrlibm.a
	$(CXX) allocate.o arith01.o arith02.o arith03.o arith04.o arith05.o \
		arith06.o arith07.o arith08.o arith09.o arith10.o \
		arith11.o arith12.o arith13.o arith14.o bytes1.o char.o \
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
# files for one version with suffix .o and the other .oo.
# I'm also going to add .yo for object files which have been compiled
# with the asynchronous javascript IO library (just so we don't have
# to rebuild each time we want to switch between node/browser), and .xo for
# for a copy of Reduce to be run using node nut with its "image file" stored
# as static data within the executable.

.SUFFIXES:	.oo .xo .yo

.cpp.o:
	$(CXX) $(CPPFLAGS) $(NODEOPTS) -c -o $@ $<

.cpp.oo:
	$(CXX) $(CPPFLAGS) $(NODEOPTS) -c -o $@ $<

.cpp.xo:
	$(CXX) $(CPPFLAGS) -DBUILTIN_IMAGE=1 $(NODEOPTS) -c -o $@ $<

# don't use NODEOPTS here, because we want a virtual FS
.cpp.yo:
	$(CXX) $(CPPFLAGS) -DBUILTIN_IMAGE=1 -DPROCEDURAL_WASM_XX=1 \
		$(ASYNCIFY_OPTS) -c -o $@ $<

#csl.yo: csl.cpp
#	$(CXX) $(CPPFLAGS) $(ASYNCIFY_OPTS) -c -o $@ $<
#cslread.yo: cslread.cpp
#	$(CXX) $(CPPFLAGS) $(ASYNCIFY_OPTS) -c -o $@ $<
# Create the bootstrapreduce.img file

bootstrapreduce.img:	bootstrapreduce.js
	-rm -f bootstrapreduce.img
	$(NODE) bootstrapreduce.js -z -Dno_init_file $(S)/buildreduce.lsp \
		-Dbootstrap -D@srcdir=$(S) -D@reduce=$(R) \
		-o bootstrapreduce.img -L bootstrap_image.log


c-code:	bootstrapreduce.img
	$(NODE) bootstrapreduce.js -w $(CSLFLAGS) \
		-Dno_init_file \
		$(S)/make-c-code.red \
		-D@destdir=$(R)/cslbuild/generated-c \
		-Dhow_many=$(how_many) -Dsize_per_file=$(size_per_file) \
		-L c-code.log


# Now the full version.

reduce.js:	allocate.oo arith01.oo arith02.oo arith03.oo arith04.oo \
		arith05.oo arith06.oo arith07.oo arith08.oo arith09.oo \
		arith10.oo arith11.oo arith12.oo arith13.oo arith14.oo \
		bytes1.oo char.oo csl.oo cslmpi.oo cslread.oo eval1.oo \
		eval2.oo eval3.oo eval4.oo fasl.oo fns1.oo fns2.oo fns3.oo \
		fwin.oo cslgc.oo lisphash.oo isprime.oo preserve.oo print.oo \
		restart.oo sysfwin.oo termed.oo inthash.oo serialize.oo \
		u01.oo u02.oo u03.oo u04.oo u05.oo u06.oo u07.oo u08.oo u09.oo u10.oo \
	        u11.oo u12.oo u13.oo u14.oo u15.oo u16.oo u17.oo u18.oo u19.oo u20.oo \
		u21.oo u22.oo u23.oo u24.oo u25.oo u26.oo u27.oo u28.oo u29.oo u30.oo \
	        u31.oo u32.oo u33.oo u34.oo u35.oo u36.oo u37.oo u38.oo u39.oo u40.oo \
		u41.oo u42.oo u43.oo u44.oo u45.oo u46.oo u47.oo u48.oo u49.oo u50.oo \
	        u51.oo u52.oo u53.oo u54.oo u55.oo u56.oo u57.oo u58.oo u59.oo u60.oo
	$(CXX) allocate.oo arith01.oo arith02.oo arith03.oo arith04.oo \
		arith05.oo arith06.oo arith07.oo arith08.oo arith09.oo \
		arith10.oo arith11.oo arith12.oo arith13.oo arith14.oo \
		bytes1.oo char.oo csl.oo cslmpi.oo cslread.oo eval1.oo \
		eval2.oo eval3.oo eval4.oo fasl.oo fns1.oo fns2.oo fns3.oo \
		fwin.oo cslgc.oo lisphash.oo isprime.oo preserve.oo print.oo \
		restart.oo sysfwin.oo termed.oo inthash.oo serialize.oo \
		u01.oo u02.oo u03.oo u04.oo u05.oo u06.oo u07.oo u08.oo u09.oo u10.oo \
	        u11.oo u12.oo u13.oo u14.oo u15.oo u16.oo u17.oo u18.oo u19.oo u20.oo \
		u21.oo u22.oo u23.oo u24.oo u25.oo u26.oo u27.oo u28.oo u29.oo u30.oo \
	        u31.oo u32.oo u33.oo u34.oo u35.oo u36.oo u37.oo u38.oo u39.oo u40.oo \
		u41.oo u42.oo u43.oo u44.oo u45.oo u46.oo u47.oo u48.oo u49.oo u50.oo \
	        u51.oo u52.oo u53.oo u54.oo u55.oo u56.oo u57.oo u58.oo u59.oo u60.oo \
		$(LDFLAGS) $(NODEOPTS) $(LIBS) $(JSOPTS) -o reduce.js

# Now the full version but with a built-in image.

reducex.js:	allocate.xo arith01.xo arith02.xo arith03.xo arith04.xo \
		arith05.xo arith06.xo arith07.xo arith08.xo arith09.xo \
		arith10.xo arith11.xo arith12.xo arith13.xo arith14.xo \
		bytes1.xo char.xo csl.xo cslmpi.xo cslread.xo eval1.xo \
		eval2.xo eval3.xo eval4.xo fasl.xo fns1.xo fns2.xo fns3.xo \
		fwin.xo cslgc.xo lisphash.xo isprime.xo preserve.xo print.xo \
		restart.xo sysfwin.xo termed.xo inthash.xo serialize.xo \
		u01.xo u02.xo u03.xo u04.xo u05.xo u06.xo u07.xo u08.xo u09.xo u10.xo \
	        u11.xo u12.xo u13.xo u14.xo u15.xo u16.xo u17.xo u18.xo u19.xo u20.xo \
		u21.xo u22.xo u23.xo u24.xo u25.xo u26.xo u27.xo u28.xo u29.xo u30.xo \
	        u31.xo u32.xo u33.xo u34.xo u35.xo u36.xo u37.xo u38.xo u39.xo u40.xo \
		u41.xo u42.xo u43.xo u44.xo u45.xo u46.xo u47.xo u48.xo u49.xo u50.xo \
	        u51.xo u52.xo u53.xo u54.xo u55.xo u56.xo u57.xo u58.xo u59.xo u60.xo
	$(CXX) allocate.xo arith01.xo arith02.xo arith03.xo arith04.xo \
		arith05.xo arith06.xo arith07.xo arith08.xo arith09.xo \
		arith10.xo arith11.xo arith12.xo arith13.xo arith14.xo \
		bytes1.xo char.xo csl.xo cslmpi.xo cslread.xo eval1.xo \
		eval2.xo eval3.xo eval4.xo fasl.xo fns1.xo fns2.xo fns3.xo \
		fwin.xo cslgc.xo lisphash.xo isprime.xo preserve.xo print.xo \
		restart.xo sysfwin.xo termed.xo inthash.xo serialize.xo \
		u01.xo u02.xo u03.xo u04.xo u05.xo u06.xo u07.xo u08.xo u09.xo u10.xo \
	        u11.xo u12.xo u13.xo u14.xo u15.xo u16.xo u17.xo u18.xo u19.xo u20.xo \
	        u21.xo u22.xo u23.xo u24.xo u25.xo u26.xo u27.xo u28.xo u29.xo u30.xo \
		u31.xo u32.xo u33.xo u34.xo u35.xo u36.xo u37.xo u38.xo u39.xo u40.xo \
	        u41.xo u42.xo u43.xo u44.xo u45.xo u46.xo u47.xo u48.xo u49.xo u50.xo \
		u51.xo u52.xo u53.xo u54.xo u55.xo u56.xo u57.xo u58.xo u59.xo u60.xo \
		$(LDFLAGS) $(NODEOPTS) $(LIBS) $(JSOPTS) -o reducex.js

# The web-based (non-node) version

INSERT_BUFFER = '_insert_buffer'

reduce.web.wasm:	allocate.yo arith01.yo arith02.yo arith03.yo \
		arith04.yo arith05.yo arith06.yo arith07.yo arith08.yo \
		arith09.yo arith10.yo arith11.yo arith12.yo arith13.yo \
		arith14.yo bytes1.yo char.yo csl.yo cslmpi.yo cslread.yo \
		eval1.yo eval2.yo eval3.yo eval4.yo fasl.yo fns1.yo fns2.yo \
		fns3.yo fwin.yo cslgc.yo lisphash.yo isprime.yo preserve.yo \
		print.yo restart.yo sysfwin.yo termed.yo inthash.yo \
		serialize.yo \
		u01.yo u02.yo u03.yo u04.yo u05.yo u06.yo u07.yo u08.yo u09.yo u10.yo \
		u11.yo u12.yo u13.yo u14.yo u15.yo u16.yo u17.yo u18.yo u19.yo u20.yo \
		u21.yo u22.yo u23.yo u24.yo u25.yo u26.yo u27.yo u28.yo u29.yo u30.yo \
		u31.yo u32.yo u33.yo u34.yo u35.yo u36.yo u37.yo u38.yo u39.yo u40.yo \
		u41.yo u42.yo u43.yo u44.yo u45.yo u46.yo u47.yo u48.yo u49.yo u50.yo \
		u51.yo u52.yo u53.yo u54.yo u55.yo u56.yo u57.yo u58.yo u59.yo u60.yo
	$(CXX) allocate.yo arith01.yo arith02.yo arith03.yo arith04.yo \
		arith05.yo arith06.yo arith07.yo arith08.yo arith09.yo \
		arith10.yo arith11.yo arith12.yo arith13.yo arith14.yo \
		bytes1.yo char.yo csl.yo cslmpi.yo cslread.yo eval1.yo \
		eval2.yo eval3.yo eval4.yo fasl.yo fns1.yo fns2.yo fns3.yo \
		fwin.yo cslgc.yo lisphash.yo isprime.yo preserve.yo print.yo \
		restart.yo sysfwin.yo termed.yo inthash.yo serialize.yo \
		u01.yo u02.yo u03.yo u04.yo u05.yo u06.yo u07.yo u08.yo u09.yo u10.yo \
		u11.yo u12.yo u13.yo u14.yo u15.yo u16.yo u17.yo u18.yo u19.yo u20.yo \
		u21.yo u22.yo u23.yo u24.yo u25.yo u26.yo u27.yo u28.yo u29.yo u30.yo \
		u31.yo u32.yo u33.yo u34.yo u35.yo u36.yo u37.yo u38.yo u39.yo u40.yo \
		u41.yo u42.yo u43.yo u44.yo u45.yo u46.yo u47.yo u48.yo u49.yo u50.yo \
		u51.yo u52.yo u53.yo u54.yo u55.yo u56.yo u57.yo u58.yo u59.yo u60.yo \
		$(LDFLAGS) $(LIBS) $(JSOPTS) $(ASYNCIFY_OPTS) $(WEBOPTS) $(LINK_OPT) \
		-s EXPORTED_FUNCTIONS="['_main',$(INSERT_BUFFER)]" \
		-o reduce.web.js

.PHONY:	reduce
reduce:	reduce.js
	echo Building reduce.js


.PHONY: reduce-web
reduce-web: reduce.web.wasm
	echo Building reduce workers

reduce.img:	reduce.js
	-rm -f reduce.img
	export reduce=$(R) && \
		$(NODE) reduce.js -z -Dforce_c_code \
		-Dno_init_file $(S)/buildreduce.lsp \
		-D@srcdir=$(S) -D@reduce=$(R) -o reduce.img \
		-L reduce_image.log

HEADERS = ../include/config.h include/crlibm.h \
	$(S)/md5.h       $(S)/termed.h    $(S)/arith.h       $(S)/openmath.h \
	$(S)/bigvector.h $(S)/entries.h   $(S)/proc.h                        \
	$(S)/uninames.h  $(S)/bytes.h     $(S)/externs.h     $(S)/int128_t.h \
	$(S)/sockhdr.h   $(S)/version.h   $(S)/charmetrics.h $(S)/fwin.h     \
	$(S)/inthash.h   $(S)/stream.h    $(S)/cslerror.h    $(S)/headers.h  \
	$(S)/lispthrow.h $(S)/syscsl.h    $(S)/cslread.h     $(S)/machine.h  \
	$(S)/tags.h

make-image.js:	$(S)/make-image.cpp $(HEADERS)
	$(CXX) $(CPPFLAGS) $(NODEOPTS) $(S)/make-image.cpp \
		$(LDFLAGS) $(LIBS) $(JSOPTS) -o make-image.js

image.cpp:	make-image.js reduce.img
	$(NODE) make-image.js
	cp image.cpp ../reduce-image.cpp
	cp reduce.img ..

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
bytes1.oo:	$(S)/bytes1.cpp $(S)/opnames.cpp $(HEADERS)
char.oo:	$(S)/char.cpp $(HEADERS)
csl.oo:		$(S)/csl.cpp $(HEADERS)
cslmpi.oo:	$(S)/cslmpi.cpp $(S)/mpipack.cpp $(HEADERS)
cslread.oo:	$(S)/cslread.cpp $(HEADERS)
driver.oo:	$(S)/driver.cpp $(HEADERS)
embedcsl.oo:	$(S)/embedcsl.cpp $(S)/csl.cpp $(HEADERS)
eval1.oo:	$(S)/eval1.cpp $(HEADERS)
eval2.oo:	$(S)/eval2.cpp $(HEADERS)
eval3.oo:	$(S)/eval3.cpp $(HEADERS)
eval4.oo:	$(S)/eval4.cpp $(HEADERS)
fasl.oo:	$(S)/fasl.cpp $(HEADERS)
fns1.oo:	$(S)/fns1.cpp $(HEADERS)
fns2.oo:	$(S)/fns2.cpp $(HEADERS)
fns3.oo:	$(S)/fns3.cpp $(HEADERS)
fwin.oo:	$(S)/fwin.cpp $(HEADERS)
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

allocate.xo:	$(S)/allocate.cpp $(HEADERS)
arith01.xo:	$(S)/arith01.cpp $(HEADERS)
arith02.xo:	$(S)/arith02.cpp $(HEADERS)
arith03.xo:	$(S)/arith03.cpp $(HEADERS)
arith04.xo:	$(S)/arith04.cpp $(HEADERS)
arith05.xo:	$(S)/arith05.cpp $(HEADERS)
arith06.xo:	$(S)/arith06.cpp $(HEADERS)
arith07.xo:	$(S)/arith07.cpp $(HEADERS)
arith08.xo:	$(S)/arith08.cpp $(HEADERS)
arith09.xo:	$(S)/arith09.cpp $(HEADERS)
arith10.xo:	$(S)/arith10.cpp $(HEADERS)
arith11.xo:	$(S)/arith11.cpp $(HEADERS)
arith12.xo:	$(S)/arith12.cpp $(HEADERS)
arith13.xo:	$(S)/arith13.cpp $(HEADERS)
arith14.xo:	$(S)/arith14.cpp $(HEADERS)
bytes1.xo:	$(S)/bytes1.cpp $(S)/opnames.cpp $(HEADERS)
char.xo:	$(S)/char.cpp $(HEADERS)
csl.xo:		$(S)/csl.cpp $(HEADERS)
cslmpi.xo:	$(S)/cslmpi.cpp $(S)/mpipack.cpp $(HEADERS)
cslread.xo:	$(S)/cslread.cpp $(HEADERS)
driver.xo:	$(S)/driver.cpp $(HEADERS)
embedcsl.xo:	$(S)/embedcsl.cpp $(S)/csl.cpp $(HEADERS)
eval1.xo:	$(S)/eval1.cpp $(HEADERS)
eval2.xo:	$(S)/eval2.cpp $(HEADERS)
eval3.xo:	$(S)/eval3.cpp $(HEADERS)
eval4.xo:	$(S)/eval4.cpp $(HEADERS)
fasl.xo:	$(S)/fasl.cpp $(HEADERS)
fns1.xo:	$(S)/fns1.cpp $(HEADERS)
fns2.xo:	$(S)/fns2.cpp $(HEADERS)
fns3.xo:	$(S)/fns3.cpp $(HEADERS)
fwin.xo:	$(S)/fwin.cpp $(HEADERS)
cslgc.xo:	$(S)/cslgc.cpp $(HEADERS)
lisphash.xo:	$(S)/lisphash.cpp $(HEADERS)
isprime.xo:	$(S)/isprime.cpp $(HEADERS)
preserve.xo:	$(S)/preserve.cpp image.cpp $(HEADERS)
print.xo:	$(S)/print.cpp $(HEADERS)
restart.xo:	$(S)/restart.cpp $(HEADERS)
sysfwin.xo:	$(S)/sysfwin.cpp $(HEADERS)
termed.xo:	$(S)/termed.cpp $(HEADERS)
inthash.xo:	$(S)/inthash.cpp $(HEADERS)
serialize.xo:	$(S)/serialize.cpp $(HEADERS)
u01.xo:		$(S)/u01.cpp $(HEADERS)
u02.xo:		$(S)/u02.cpp $(HEADERS)
u03.xo:		$(S)/u03.cpp $(HEADERS)
u04.xo:		$(S)/u04.cpp $(HEADERS)
u05.xo:		$(S)/u05.cpp $(HEADERS)
u06.xo:		$(S)/u06.cpp $(HEADERS)
u07.xo:		$(S)/u07.cpp $(HEADERS)
u08.xo:		$(S)/u08.cpp $(HEADERS)
u09.xo:		$(S)/u09.cpp $(HEADERS)
u10.xo:		$(S)/u10.cpp $(HEADERS)
u11.xo:		$(S)/u11.cpp $(HEADERS)
u12.xo:		$(S)/u12.cpp $(HEADERS)
u13.xo:		$(S)/u13.cpp $(HEADERS)
u14.xo:		$(S)/u14.cpp $(HEADERS)
u15.xo:		$(S)/u15.cpp $(HEADERS)
u16.xo:		$(S)/u16.cpp $(HEADERS)
u17.xo:		$(S)/u17.cpp $(HEADERS)
u18.xo:		$(S)/u18.cpp $(HEADERS)
u19.xo:		$(S)/u19.cpp $(HEADERS)
u20.xo:		$(S)/u20.cpp $(HEADERS)
u21.xo:		$(S)/u21.cpp $(HEADERS)
u22.xo:		$(S)/u22.cpp $(HEADERS)
u23.xo:		$(S)/u23.cpp $(HEADERS)
u24.xo:		$(S)/u24.cpp $(HEADERS)
u25.xo:		$(S)/u25.cpp $(HEADERS)
u26.xo:		$(S)/u26.cpp $(HEADERS)
u27.xo:		$(S)/u27.cpp $(HEADERS)
u28.xo:		$(S)/u28.cpp $(HEADERS)
u29.xo:		$(S)/u29.cpp $(HEADERS)
u30.xo:		$(S)/u30.cpp $(HEADERS)
u31.xo:		$(S)/u31.cpp $(HEADERS)
u32.xo:		$(S)/u32.cpp $(HEADERS)
u33.xo:		$(S)/u33.cpp $(HEADERS)
u34.xo:		$(S)/u34.cpp $(HEADERS)
u35.xo:		$(S)/u35.cpp $(HEADERS)
u36.xo:		$(S)/u36.cpp $(HEADERS)
u37.xo:		$(S)/u37.cpp $(HEADERS)
u38.xo:		$(S)/u38.cpp $(HEADERS)
u39.xo:		$(S)/u39.cpp $(HEADERS)
u40.xo:		$(S)/u40.cpp $(HEADERS)
u41.xo:		$(S)/u41.cpp $(HEADERS)
u42.xo:		$(S)/u42.cpp $(HEADERS)
u43.xo:		$(S)/u43.cpp $(HEADERS)
u44.xo:		$(S)/u44.cpp $(HEADERS)
u45.xo:		$(S)/u45.cpp $(HEADERS)
u46.xo:		$(S)/u46.cpp $(HEADERS)
u47.xo:		$(S)/u47.cpp $(HEADERS)
u48.xo:		$(S)/u48.cpp $(HEADERS)
u49.xo:		$(S)/u49.cpp $(HEADERS)
u50.xo:		$(S)/u50.cpp $(HEADERS)
u51.xo:		$(S)/u51.cpp $(HEADERS)
u52.xo:		$(S)/u52.cpp $(HEADERS)
u53.xo:		$(S)/u53.cpp $(HEADERS)
u54.xo:		$(S)/u54.cpp $(HEADERS)
u55.xo:		$(S)/u55.cpp $(HEADERS)
u56.xo:		$(S)/u56.cpp $(HEADERS)
u57.xo:		$(S)/u57.cpp $(HEADERS)
u58.xo:		$(S)/u58.cpp $(HEADERS)
u59.xo:		$(S)/u59.cpp $(HEADERS)
u60.xo:		$(S)/u60.cpp $(HEADERS)

allocate.yo:	$(S)/allocate.cpp $(HEADERS)
arith01.yo:	$(S)/arith01.cpp $(HEADERS)
arith02.yo:	$(S)/arith02.cpp $(HEADERS)
arith03.yo:	$(S)/arith03.cpp $(HEADERS)
arith04.yo:	$(S)/arith04.cpp $(HEADERS)
arith05.yo:	$(S)/arith05.cpp $(HEADERS)
arith06.yo:	$(S)/arith06.cpp $(HEADERS)
arith07.yo:	$(S)/arith07.cpp $(HEADERS)
arith08.yo:	$(S)/arith08.cpp $(HEADERS)
arith09.yo:	$(S)/arith09.cpp $(HEADERS)
arith10.yo:	$(S)/arith10.cpp $(HEADERS)
arith11.yo:	$(S)/arith11.cpp $(HEADERS)
arith12.yo:	$(S)/arith12.cpp $(HEADERS)
arith13.yo:	$(S)/arith13.cpp $(HEADERS)
arith14.yo:	$(S)/arith14.cpp $(HEADERS)
bytes1.yo:	$(S)/bytes1.cpp $(S)/opnames.cpp $(HEADERS)
char.yo:	$(S)/char.cpp $(HEADERS)
csl.yo:		$(S)/csl.cpp $(HEADERS)
cslmpi.yo:	$(S)/cslmpi.cpp $(S)/mpipack.cpp $(HEADERS)
cslread.yo:	$(S)/cslread.cpp $(HEADERS)
driver.yo:	$(S)/driver.cpp $(HEADERS)
embedcsl.yo:	$(S)/embedcsl.cpp $(S)/csl.cpp $(HEADERS)
eval1.yo:	$(S)/eval1.cpp $(HEADERS)
eval2.yo:	$(S)/eval2.cpp $(HEADERS)
eval3.yo:	$(S)/eval3.cpp $(HEADERS)
eval4.yo:	$(S)/eval4.cpp $(HEADERS)
fasl.yo:	$(S)/fasl.cpp $(HEADERS)
fns1.yo:	$(S)/fns1.cpp $(HEADERS)
fns2.yo:	$(S)/fns2.cpp $(HEADERS)
fns3.yo:	$(S)/fns3.cpp $(HEADERS)
fwin.yo:	$(S)/fwin.cpp $(HEADERS)
cslgc.yo:	$(S)/cslgc.cpp $(HEADERS)
lisphash.yo:	$(S)/lisphash.cpp $(HEADERS)
isprime.yo:	$(S)/isprime.cpp $(HEADERS)
preserve.yo:	$(S)/preserve.cpp image.cpp $(HEADERS)
print.yo:	$(S)/print.cpp $(HEADERS)
restart.yo:	$(S)/restart.cpp $(HEADERS)
sysfwin.yo:	$(S)/sysfwin.cpp $(HEADERS)
termed.yo:	$(S)/termed.cpp $(HEADERS)
inthash.yo:	$(S)/inthash.cpp $(HEADERS)
serialize.yo:	$(S)/serialize.cpp $(HEADERS)
u01.yo:		$(S)/u01.cpp $(HEADERS)
u02.yo:		$(S)/u02.cpp $(HEADERS)
u03.yo:		$(S)/u03.cpp $(HEADERS)
u04.yo:		$(S)/u04.cpp $(HEADERS)
u05.yo:		$(S)/u05.cpp $(HEADERS)
u06.yo:		$(S)/u06.cpp $(HEADERS)
u07.yo:		$(S)/u07.cpp $(HEADERS)
u08.yo:		$(S)/u08.cpp $(HEADERS)
u09.yo:		$(S)/u09.cpp $(HEADERS)
u10.yo:		$(S)/u10.cpp $(HEADERS)
u11.yo:		$(S)/u11.cpp $(HEADERS)
u12.yo:		$(S)/u12.cpp $(HEADERS)
u13.yo:		$(S)/u13.cpp $(HEADERS)
u14.yo:		$(S)/u14.cpp $(HEADERS)
u15.yo:		$(S)/u15.cpp $(HEADERS)
u16.yo:		$(S)/u16.cpp $(HEADERS)
u17.yo:		$(S)/u17.cpp $(HEADERS)
u18.yo:		$(S)/u18.cpp $(HEADERS)
u19.yo:		$(S)/u19.cpp $(HEADERS)
u20.yo:		$(S)/u20.cpp $(HEADERS)
u21.yo:		$(S)/u21.cpp $(HEADERS)
u22.yo:		$(S)/u22.cpp $(HEADERS)
u23.yo:		$(S)/u23.cpp $(HEADERS)
u24.yo:		$(S)/u24.cpp $(HEADERS)
u25.yo:		$(S)/u25.cpp $(HEADERS)
u26.yo:		$(S)/u26.cpp $(HEADERS)
u27.yo:		$(S)/u27.cpp $(HEADERS)
u28.yo:		$(S)/u28.cpp $(HEADERS)
u29.yo:		$(S)/u29.cpp $(HEADERS)
u30.yo:		$(S)/u30.cpp $(HEADERS)
u31.yo:		$(S)/u31.cpp $(HEADERS)
u32.yo:		$(S)/u32.cpp $(HEADERS)
u33.yo:		$(S)/u33.cpp $(HEADERS)
u34.yo:		$(S)/u34.cpp $(HEADERS)
u35.yo:		$(S)/u35.cpp $(HEADERS)
u36.yo:		$(S)/u36.cpp $(HEADERS)
u37.yo:		$(S)/u37.cpp $(HEADERS)
u38.yo:		$(S)/u38.cpp $(HEADERS)
u39.yo:		$(S)/u39.cpp $(HEADERS)
u40.yo:		$(S)/u40.cpp $(HEADERS)
u41.yo:		$(S)/u41.cpp $(HEADERS)
u42.yo:		$(S)/u42.cpp $(HEADERS)
u43.yo:		$(S)/u43.cpp $(HEADERS)
u44.yo:		$(S)/u44.cpp $(HEADERS)
u45.yo:		$(S)/u45.cpp $(HEADERS)
u46.yo:		$(S)/u46.cpp $(HEADERS)
u47.yo:		$(S)/u47.cpp $(HEADERS)
u48.yo:		$(S)/u48.cpp $(HEADERS)
u49.yo:		$(S)/u49.cpp $(HEADERS)
u50.yo:		$(S)/u50.cpp $(HEADERS)
u51.yo:		$(S)/u51.cpp $(HEADERS)
u52.yo:		$(S)/u52.cpp $(HEADERS)
u53.yo:		$(S)/u53.cpp $(HEADERS)
u54.yo:		$(S)/u54.cpp $(HEADERS)
u55.yo:		$(S)/u55.cpp $(HEADERS)
u56.yo:		$(S)/u56.cpp $(HEADERS)
u57.yo:		$(S)/u57.cpp $(HEADERS)
u58.yo:		$(S)/u58.cpp $(HEADERS)
u59.yo:		$(S)/u59.cpp $(HEADERS)
u60.yo:		$(S)/u60.cpp $(HEADERS)

clean:
	-rm -f *.o *.oo *.xo *.yo reduce* *.log make-image* image.cpp
	-rm -f bootstrapreduce* *.bak *.map
	-rm -rf crlibm include lib bin jscsl-times

# end of Makefile

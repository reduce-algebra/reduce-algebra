# Makefile for building reduce.img suitable for embedded use.
#	 Arthur Norman & Avery Laird, 2020--2021.

# This version uses emscripten em++ to create JavaScript/WebAssembly versions
# for use with node (reduce.{js,wasm}) and web browsers (reduce.web.{js,wasm}).

# $Id$

# For a FULL bootstrapped build for node you need to go
#
#	 make bootstrapreduce.img
#	 rm bootstrapreduce.img; make bootstrapreduce.img
#	 make c-code
#	 make reduce.img
#
# To add a build for web browsers, do the above, then
#	make reduce-web
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
# CFLAGS=$(EMFLAGS)
# CXXFLAGS=$(EMFLAGS)
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
#	JSOPTS += $(NODEOPTS)
# else
#	JSOPTS += $(WEBOPTS)
#	REDUCE_TARGET=reduce.html
# endif
#endif

S=../../cslbase
R=../../..

VPATH=$(S)

.PHONY: all
all: reduce.js reduce.img image.cpp reduce.web.wasm

include/crlibm.h lib/libcrlibm.a: emflags.sh make-crlibm.sh
	./make-crlibm.sh

mainObjects = allocate.o arith01.o arith02.o arith03.o arith04.o \
		arith05.o arith06.o arith07.o arith08.o arith09.o \
		arith10.o arith11.o arith12.o arith13.o arith14.o \
		bytes1.o char.o csl.o cslmpi.o cslread.o eval1.o \
		eval2.o eval3.o eval4.o fasl.o fns1.o fns2.o fns3.o \
		fwin.o cslgc.o lisphash.o isprime.o preserve.o print.o \
		restart.o sysfwin.o termed.o inthash.o serialize.o

bootstrapObjects = $(mainObjects) stubs.o

bootstrapreduce.js:	$(bootstrapObjects) lib/libcrlibm.a
	$(CXX) $(bootstrapObjects) \
		$(LDFLAGS) $(NODEOPTS) $(LIBS) $(JSOPTS) -o bootstrapreduce.js

.PHONY:	bootstrapreduce
bootstrapreduce: bootstrapreduce.js
	echo Building bootstrapreduce.js


# I am going to build both reduce and bootstrapreduce in the same directory
# and they use overlapping source files. To keep things clean I put the object
# files for one version with suffix .o and the other .oo.
# I'm also going to add .yo for object files which have been compiled
# with the asynchronous javascript IO library (just so we don't have
# to rebuild each time we want to switch between node/browser), and .xo for
# for a copy of Reduce to be run using node but with its "image file" stored
# as static data within the executable.

.SUFFIXES:	.oo .xo .yo

# I do not set NO_BYTECOUNTS on the .cpp.o target because that is used to
# make bootstrapreduce.js which can be used for profiling - an action which
# relies on bytecounts.
.cpp.o:
	$(CXX) $(CPPFLAGS) $(NODEOPTS) -c -o $@ $<

.cpp.oo:
	$(CXX) $(CPPFLAGS) $(NODEOPTS) -DNO_BYTECOUNTS=1 -c -o $@ $<

.cpp.xo:
	$(CXX) $(CPPFLAGS) -DBUILTIN_IMAGE=1 $(NODEOPTS) -DNO_BYTECOUNTS=1 -c -o $@ $<

# don't use NODEOPTS here, because we want a virtual FS
.cpp.yo:
	$(CXX) $(CPPFLAGS) -DBUILTIN_IMAGE=1 -DPROCEDURAL_WASM_XX=1 \
		$(ASYNCIFY_OPTS) -DNO_BYTECOUNTS=1 -c -o $@ $<


# Create the bootstrapreduce.img file

bootstrapreduce.img: bootstrapreduce.js
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

reduceObjects = $(mainObjects:.o=.oo) \
		u01.oo u02.oo u03.oo u04.oo u05.oo u06.oo u07.oo u08.oo u09.oo u10.oo \
		u11.oo u12.oo u13.oo u14.oo u15.oo u16.oo u17.oo u18.oo u19.oo u20.oo \
		u21.oo u22.oo u23.oo u24.oo u25.oo u26.oo u27.oo u28.oo u29.oo u30.oo \
		u31.oo u32.oo u33.oo u34.oo u35.oo u36.oo u37.oo u38.oo u39.oo u40.oo \
		u41.oo u42.oo u43.oo u44.oo u45.oo u46.oo u47.oo u48.oo u49.oo u50.oo \
		u51.oo u52.oo u53.oo u54.oo u55.oo u56.oo u57.oo u58.oo u59.oo u60.oo

reduce.js: $(reduceObjects)
	$(CXX) $(reduceObjects) \
		$(LDFLAGS) $(NODEOPTS) $(LIBS) $(JSOPTS) -o reduce.js

# Now the full version but with a built-in image.

reducexObjects = $(reduceObjects:.oo=.xo)

reducex.js: $(reducexObjects)
	$(CXX) $(reducexObjects) \
		$(LDFLAGS) $(NODEOPTS) $(LIBS) $(JSOPTS) -o reducex.js

# The web-based (non-node) version

INSERT_BUFFER = '_insert_buffer'

reduceWebObjects = $(reduceObjects:.oo=.yo)

reduce.web.wasm: $(reduceWebObjects)
	$(CXX) $(reduceWebObjects) \
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
	$(S)/md5.h		 $(S)/termed.h	  $(S)/arith.h		 $(S)/openmath.h \
	$(S)/bigvector.h $(S)/entries.h	  $(S)/proc.h						 \
	$(S)/uninames.h	 $(S)/bytes.h	  $(S)/externs.h	 $(S)/int128_t.h \
	$(S)/sockhdr.h	 $(S)/version.h	  $(S)/charmetrics.h $(S)/fwin.h	 \
	$(S)/inthash.h	 $(S)/stream.h	  $(S)/cslerror.h	 $(S)/headers.h	 \
	$(S)/lispthrow.h $(S)/syscsl.h	  $(S)/cslread.h	 $(S)/machine.h	 \
	$(S)/tags.h

make-image.js: $(S)/make-image.cpp $(HEADERS)
	$(CXX) $(CPPFLAGS) $(NODEOPTS) $(S)/make-image.cpp \
		$(LDFLAGS) $(LIBS) $(JSOPTS) -o make-image.js

image.cpp: make-image.js reduce.img
	$(NODE) make-image.js
	cp image.cpp ../reduce-image.cpp
	cp reduce.img ..

allocate.o  allocate.oo  allocate.xo  allocate.yo:  $(S)/allocate.cpp $(HEADERS)
arith01.o   arith01.oo   arith01.xo   arith01.yo:   $(S)/arith01.cpp $(HEADERS)
arith02.o   arith02.oo   arith02.xo   arith02.yo:   $(S)/arith02.cpp $(HEADERS)
arith03.o   arith03.oo   arith03.xo   arith03.yo:   $(S)/arith03.cpp $(HEADERS)
arith04.o   arith04.oo   arith04.xo   arith04.yo:   $(S)/arith04.cpp $(HEADERS)
arith05.o   arith05.oo   arith05.xo   arith05.yo:   $(S)/arith05.cpp $(HEADERS)
arith06.o   arith06.oo   arith06.xo   arith06.yo:   $(S)/arith06.cpp $(HEADERS)
arith07.o   arith07.oo   arith07.xo   arith07.yo:   $(S)/arith07.cpp $(HEADERS)
arith08.o   arith08.oo   arith08.xo   arith08.yo:   $(S)/arith08.cpp $(HEADERS)
arith09.o   arith09.oo   arith09.xo   arith09.yo:   $(S)/arith09.cpp $(HEADERS)
arith10.o   arith10.oo   arith10.xo   arith10.yo:   $(S)/arith10.cpp $(HEADERS)
arith11.o   arith11.oo   arith11.xo   arith11.yo:   $(S)/arith11.cpp $(HEADERS)
arith12.o   arith12.oo   arith12.xo   arith12.yo:   $(S)/arith12.cpp $(HEADERS)
arith13.o   arith13.oo   arith13.xo   arith13.yo:   $(S)/arith13.cpp $(HEADERS)
arith14.o   arith14.oo   arith14.xo   arith14.yo:   $(S)/arith14.cpp $(HEADERS)
bytes1.o    bytes1.oo    bytes1.xo    bytes1.yo:    $(S)/bytes1.cpp $(S)/opnames.cpp $(HEADERS)
char.o      char.oo      char.xo      char.yo:      $(S)/char.cpp $(HEADERS)
csl.o       csl.oo       csl.xo       csl.yo:       $(S)/csl.cpp $(HEADERS)
cslmpi.o    cslmpi.oo    cslmpi.xo    cslmpi.yo:    $(S)/cslmpi.cpp $(S)/mpipack.cpp $(HEADERS)
cslread.o   cslread.oo   cslread.xo   cslread.yo:   $(S)/cslread.cpp $(HEADERS)
driver.o    driver.oo    driver.xo    driver.yo:    $(S)/driver.cpp $(HEADERS)
embedcsl.o  embedcsl.oo  embedcsl.xo  embedcsl.yo:  $(S)/embedcsl.cpp $(S)/csl.cpp $(HEADERS)
eval1.o     eval1.oo     eval1.xo     eval1.yo:     $(S)/eval1.cpp $(HEADERS)
eval2.o     eval2.oo     eval2.xo     eval2.yo:     $(S)/eval2.cpp $(HEADERS)
eval3.o     eval3.oo     eval3.xo     eval3.yo:     $(S)/eval3.cpp $(HEADERS)
eval4.o     eval4.oo     eval4.xo     eval4.yo:     $(S)/eval4.cpp $(HEADERS)
fasl.o      fasl.oo      fasl.xo      fasl.yo:      $(S)/fasl.cpp $(HEADERS)
fns1.o      fns1.oo      fns1.xo      fns1.yo:      $(S)/fns1.cpp $(HEADERS)
fns2.o      fns2.oo      fns2.xo      fns2.yo:      $(S)/fns2.cpp $(HEADERS)
fns3.o      fns3.oo      fns3.xo      fns3.yo:      $(S)/fns3.cpp $(HEADERS)
fwin.o      fwin.oo      fwin.xo      fwin.yo:      $(S)/fwin.cpp $(HEADERS)
cslgc.o     cslgc.oo     cslgc.xo     cslgc.yo:     $(S)/cslgc.cpp $(HEADERS)
lisphash.o  lisphash.oo  lisphash.xo  lisphash.yo:  $(S)/lisphash.cpp $(HEADERS)
isprime.o   isprime.oo   isprime.xo   isprime.yo:   $(S)/isprime.cpp $(HEADERS)
print.o     print.oo     print.xo     print.yo:     $(S)/print.cpp $(HEADERS)
restart.o   restart.oo   restart.xo   restart.yo:   $(S)/restart.cpp $(HEADERS)
sysfwin.o   sysfwin.oo   sysfwin.xo   sysfwin.yo:   $(S)/sysfwin.cpp $(HEADERS)
termed.o    termed.oo    termed.xo    termed.yo:    $(S)/termed.cpp $(HEADERS)
inthash.o   inthash.oo   inthash.xo   inthash.yo:   $(S)/inthash.cpp $(HEADERS)
serialize.o serialize.oo serialize.xo serialize.yo: $(S)/serialize.cpp $(HEADERS)

makeheaders.o: $(S)/makeheaders.cpp
objtype.o: $(S)/objtype.cpp

preserve.o  preserve.oo: $(S)/preserve.cpp $(HEADERS)
preserve.xo preserve.yo: $(S)/preserve.cpp image.cpp $(HEADERS)

u01.oo u01.xo u01.yo: $(S)/u01.cpp $(HEADERS)
u02.oo u02.xo u02.yo: $(S)/u02.cpp $(HEADERS)
u03.oo u03.xo u03.yo: $(S)/u03.cpp $(HEADERS)
u04.oo u04.xo u04.yo: $(S)/u04.cpp $(HEADERS)
u05.oo u05.xo u05.yo: $(S)/u05.cpp $(HEADERS)
u06.oo u06.xo u06.yo: $(S)/u06.cpp $(HEADERS)
u07.oo u07.xo u07.yo: $(S)/u07.cpp $(HEADERS)
u08.oo u08.xo u08.yo: $(S)/u08.cpp $(HEADERS)
u09.oo u09.xo u09.yo: $(S)/u09.cpp $(HEADERS)
u10.oo u10.xo u10.yo: $(S)/u10.cpp $(HEADERS)
u11.oo u11.xo u11.yo: $(S)/u11.cpp $(HEADERS)
u12.oo u12.xo u12.yo: $(S)/u12.cpp $(HEADERS)
u13.oo u13.xo u13.yo: $(S)/u13.cpp $(HEADERS)
u14.oo u14.xo u14.yo: $(S)/u14.cpp $(HEADERS)
u15.oo u15.xo u15.yo: $(S)/u15.cpp $(HEADERS)
u16.oo u16.xo u16.yo: $(S)/u16.cpp $(HEADERS)
u17.oo u17.xo u17.yo: $(S)/u17.cpp $(HEADERS)
u18.oo u18.xo u18.yo: $(S)/u18.cpp $(HEADERS)
u19.oo u19.xo u19.yo: $(S)/u19.cpp $(HEADERS)
u20.oo u20.xo u20.yo: $(S)/u20.cpp $(HEADERS)
u21.oo u21.xo u21.yo: $(S)/u21.cpp $(HEADERS)
u22.oo u22.xo u22.yo: $(S)/u22.cpp $(HEADERS)
u23.oo u23.xo u23.yo: $(S)/u23.cpp $(HEADERS)
u24.oo u24.xo u24.yo: $(S)/u24.cpp $(HEADERS)
u25.oo u25.xo u25.yo: $(S)/u25.cpp $(HEADERS)
u26.oo u26.xo u26.yo: $(S)/u26.cpp $(HEADERS)
u27.oo u27.xo u27.yo: $(S)/u27.cpp $(HEADERS)
u28.oo u28.xo u28.yo: $(S)/u28.cpp $(HEADERS)
u29.oo u29.xo u29.yo: $(S)/u29.cpp $(HEADERS)
u30.oo u30.xo u30.yo: $(S)/u30.cpp $(HEADERS)
u31.oo u31.xo u31.yo: $(S)/u31.cpp $(HEADERS)
u32.oo u32.xo u32.yo: $(S)/u32.cpp $(HEADERS)
u33.oo u33.xo u33.yo: $(S)/u33.cpp $(HEADERS)
u34.oo u34.xo u34.yo: $(S)/u34.cpp $(HEADERS)
u35.oo u35.xo u35.yo: $(S)/u35.cpp $(HEADERS)
u36.oo u36.xo u36.yo: $(S)/u36.cpp $(HEADERS)
u37.oo u37.xo u37.yo: $(S)/u37.cpp $(HEADERS)
u38.oo u38.xo u38.yo: $(S)/u38.cpp $(HEADERS)
u39.oo u39.xo u39.yo: $(S)/u39.cpp $(HEADERS)
u40.oo u40.xo u40.yo: $(S)/u40.cpp $(HEADERS)
u41.oo u41.xo u41.yo: $(S)/u41.cpp $(HEADERS)
u42.oo u42.xo u42.yo: $(S)/u42.cpp $(HEADERS)
u43.oo u43.xo u43.yo: $(S)/u43.cpp $(HEADERS)
u44.oo u44.xo u44.yo: $(S)/u44.cpp $(HEADERS)
u45.oo u45.xo u45.yo: $(S)/u45.cpp $(HEADERS)
u46.oo u46.xo u46.yo: $(S)/u46.cpp $(HEADERS)
u47.oo u47.xo u47.yo: $(S)/u47.cpp $(HEADERS)
u48.oo u48.xo u48.yo: $(S)/u48.cpp $(HEADERS)
u49.oo u49.xo u49.yo: $(S)/u49.cpp $(HEADERS)
u50.oo u50.xo u50.yo: $(S)/u50.cpp $(HEADERS)
u51.oo u51.xo u51.yo: $(S)/u51.cpp $(HEADERS)
u52.oo u52.xo u52.yo: $(S)/u52.cpp $(HEADERS)
u53.oo u53.xo u53.yo: $(S)/u53.cpp $(HEADERS)
u54.oo u54.xo u54.yo: $(S)/u54.cpp $(HEADERS)
u55.oo u55.xo u55.yo: $(S)/u55.cpp $(HEADERS)
u56.oo u56.xo u56.yo: $(S)/u56.cpp $(HEADERS)
u57.oo u57.xo u57.yo: $(S)/u57.cpp $(HEADERS)
u58.oo u58.xo u58.yo: $(S)/u58.cpp $(HEADERS)
u59.oo u59.xo u59.yo: $(S)/u59.cpp $(HEADERS)
u60.oo u60.xo u60.yo: $(S)/u60.cpp $(HEADERS)

.PHONY: clean
clean:
	-rm -f *.o *.oo *.xo *.yo reduce* *.log make-image* image.cpp
	-rm -f bootstrapreduce* *.bak *.map http.pid
	-rm -rf crlibm include lib bin jscsl-times

# end of Makefile

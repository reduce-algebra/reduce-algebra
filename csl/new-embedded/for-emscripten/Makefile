# Makefile for building reduce.img suitable for embedded use.
#	 Arthur Norman & Avery Laird, 2020--2021.

# This version uses emscripten (em++ etc.) to create JavaScript/WebAssembly versions
# for use with Node.js (reduce.{js,wasm}) and web browsers (reduce.web.{js,wasm}).

# $Id$

# For a FULL bootstrapped build for Node.js you need to run
#
#	make bootstrapreduce.img
#	rm bootstrapreduce.img; make bootstrapreduce.img
#	make c-code
#	make reduce.img
#
# To add a build for web browsers, run the above, then run
#
#	make reduce-web

# As a convenience,
#
#	make webreduce
#
# runs ALL the above steps, and
#
#	make mini-webreduce
#
# runs the same steps to build min-REDUCE.  This uses "./package.map",
# which should have most packages commented out, and a smaller memory
# size to build a version of REDUCE with a smaller footprint.

# To disable optimization and have a readable JavaScript file, run
#
#	make ... OPT=-O0
#
# which also makes -s ASSERTIONS=1 the default.

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

# EMFLAGS:=$(shell . ./emflags.sh && echo $$EMFLAGS)
# Non-default Emscripten flags, keeping compile and link flags distinct
# to avoid warnings.

# Emscripten compile and link flags:
EM_CC_LD_FLAGS = -flto -s USE_ZLIB
# USE_ZLIB needed (initially) at compile time to install <zlib.h>!

# Emscripten compile flags:
EM_CCFLAGS = $(EM_CC_LD_FLAGS)

ifdef MINIREDUCE
 initial_memory = 256mb
else
 initial_memory = 1024mb
endif

# Emscripten link flags:
EM_LDFLAGS = $(EM_CC_LD_FLAGS)\
 -s EXIT_RUNTIME\
 -s INITIAL_MEMORY=$(initial_memory)\
 -s NO_ERROR_ON_UNDEFINED_SYMBOLS


#ASYNC_FUNCTIONS:=$(shell source ./asyncfuns.sh stack_trace_*.txt && echo $$cfuns)
#ASYNC_IMPORTS:=$(shell source ./asyncfuns.sh stack_trace_*.txt && echo $$jsimports)

CPPFLAGS=$(EM_CCFLAGS)\
 -std=gnu++17 $(OPT) -I. -I../include -Iinclude -I$(S)\
 -DHAVE_CONFIG_H=1 -DNO_THROW=1 -DHAVE_CRLIBM=1\
 -DAVOID_KARATSUBA_THREADS=1 -DEMBEDDED=1 $(XCFLAGS) $(USERFLAGS)

LDFLAGS=$(EM_LDFLAGS) -Llib
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

# Emscripten link flags when building for Node.Js:
NODE_EM_LDFLAGS= -s NODERAWFS -s FORCE_FILESYSTEM

PRE_JS=$(JS_SRC)/init.js
WEBOPTS= --pre-js $(PRE_JS)\
 -s ENVIRONMENT=worker\
 -s BUILD_AS_WORKER\
 --js-library $(JS_SRC)/io.js


#ASYNCIFY_OPTS = -s ASYNCIFY \
#	$(ASYNC_IMPORTS) \
#	$(ASYNC_FUNCTIONS) \
#	-s ASYNCIFY_ADVISE \
#	-DWASM_ASYNC_IO=1 \
#	-s ASYNCIFY_IGNORE_INDIRECT
#	-s ASYNCIFY_STACK_SIZE=1048576

#ifndef WEB
# JSOPTS += $(NODE_EM_LDFLAGS)
#else
# ifeq (WEB,0)
#	JSOPTS += $(NODE_EM_LDFLAGS)
# else
#	JSOPTS += $(WEBOPTS)
#	REDUCE_TARGET=reduce.html
# endif
#endif

S=../../cslbase
R=../../..

# VPATH=$(S)

.PHONY: all
all: reduce.js reduce.img image.cpp reduce.web.js

# The recipe below must be a single (logical) line so that it is all
# run in the same shell instance, hence all the backslashes:
include/crlibm.h lib/libcrlibm.a:
	rm -rf crlibm include lib; \
	mkdir -p crlibm; \
	cd crlibm; \
	../../../../libraries/crlibm/configure\
	 CC=emcc CFLAGS="$(EM_CCFLAGS) -D__INTEL_COMPILER=1 -O3"\
	 LDFLAGS="$(EM_LDFLAGS)" AR=emar RANLIB=emranlib\
	 --prefix=`pwd`/..; \
	make clean; \
	make; \
	make install; \
	cd ..


main_o_files =\
 allocate.o arith01.o arith02.o arith03.o arith04.o\
 arith05.o arith06.o arith07.o arith08.o arith09.o\
 arith10.o arith11.o arith12.o arith13.o arith14.o\
 bytes1.o char.o cslmpi.o cslread.o eval1.o\
 eval2.o eval3.o eval4.o fasl.o fns1.o fns2.o fns3.o\
 fwin.o cslgc.o lisphash.o isprime.o print.o\
 restart.o sysfwin.o termed.o inthash.o serialize.o

special_o_files = csl.o preserve.o

bootstrapObjects = $(main_o_files) $(special_o_files) stubs.o

bootstrapreduce.js:	$(bootstrapObjects) lib/libcrlibm.a
	$(CXX) $(bootstrapObjects)\
	 $(LDFLAGS) $(NODE_EM_LDFLAGS) $(LIBS) $(JSOPTS) -o bootstrapreduce.js

.PHONY:	bootstrapreduce
bootstrapreduce: bootstrapreduce.js
	@echo Building bootstrapreduce.js


# I am going to build both reduce and bootstrapreduce in the same directory
# and they use overlapping source files. To keep things clean I put the object
# files for one version with suffix .o and the other .oo.
# I'm also going to add .yo for object files which have been compiled
# with the asynchronous javascript IO library (just so we don't have
# to rebuild each time we want to switch between Node.js/browser), and .xo for
# for a copy of Reduce to be run using Node.js but with its "image file" stored
# as static data within the executable.

# However, this creates a lot of identical object files, so re-use
# them unless they actually differ.  (This can be established by
# assuming they differ and then comparing them!)

# Create the bootstrapreduce.img file

ifdef MINIREDUCE
 package_map = package.map
endif

# If MINIREDUCE is set (to -Dminireduce) then buildreduce.lsp reads
# "./package.map", which should have most packages commented out.  See
# target mini-webreduce at the end of this file.
bootstrapreduce.img: bootstrapreduce.js $(package_map)
	-rm -f bootstrapreduce.img
	$(NODE) bootstrapreduce.js -z -Dno_init_file $(MINIREDUCE) $(S)/buildreduce.lsp\
	 -Dbootstrap -D@srcdir=$(S) -D@reduce=$(R)\
	 -o bootstrapreduce.img -L bootstrap_image.log

c-code:	bootstrapreduce.img
	$(NODE) bootstrapreduce.js -w $(CSLFLAGS)\
	 -Dno_init_file\
	 $(S)/make-c-code.red\
	 -D@destdir=$(R)/cslbuild/generated-c\
	 -Dhow_many=$(how_many) -Dsize_per_file=$(size_per_file)\
	 -L c-code.log


# Now the full version.

unn_oo_files =\
 u01.oo u02.oo u03.oo u04.oo u05.oo u06.oo u07.oo u08.oo u09.oo u10.oo\
 u11.oo u12.oo u13.oo u14.oo u15.oo u16.oo u17.oo u18.oo u19.oo u20.oo\
 u21.oo u22.oo u23.oo u24.oo u25.oo u26.oo u27.oo u28.oo u29.oo u30.oo\
 u31.oo u32.oo u33.oo u34.oo u35.oo u36.oo u37.oo u38.oo u39.oo u40.oo\
 u41.oo u42.oo u43.oo u44.oo u45.oo u46.oo u47.oo u48.oo u49.oo u50.oo\
 u51.oo u52.oo u53.oo u54.oo u55.oo u56.oo u57.oo u58.oo u59.oo u60.oo

# Re-use $(main_o_files) and $(special_o_files), since the .oo files
# are identical, as would be shown by running
# for f in *.o; do echo $f; cmp $f ${f%.o}.oo; done

reduceObjects = $(main_o_files) $(special_o_files) $(unn_oo_files)

reduce.js: $(reduceObjects)
	$(CXX) $(reduceObjects)\
	 $(LDFLAGS) $(NODE_EM_LDFLAGS) $(LIBS) $(JSOPTS) -o reduce.js

# Now the full version but with a built-in image.
# (Object file list for this rule not optimized!)

reducexObjects = $(main_o_files:.o=.xo) $(special_o_files:.o=.xo) $(unn_oo_files:.oo=.xo)

reducex.js: $(reducexObjects)
	$(CXX) $(reducexObjects) \
		$(LDFLAGS) $(NODE_EM_LDFLAGS) $(LIBS) $(JSOPTS) -o reducex.js

# The web-based (non-Node.js) version
# Re-use $(main_o_files) and $(unn_oo_files), since the .yo files are
# identical, as would be shown by running
# for f in *.oo; do echo $f; cmp $f ${f%.oo}.yo; done

reduceWebObjects = $(main_o_files) $(special_o_files:.o=.yo) $(unn_oo_files)

reduce.web.js: $(reduceWebObjects)
	$(CXX) $(reduceWebObjects)\
	 $(LDFLAGS) $(LIBS) $(JSOPTS) $(ASYNCIFY_OPTS) $(WEBOPTS) $(LINK_OPT)\
	 -o reduce.web.js

.PHONY:	reduce
reduce:	reduce.js
	@echo '=== Built "reduce.js" and "reduce.wasm".'

.PHONY: reduce-web
reduce-web: reduce.web.js
	@echo '=== Built "reduce.web.js" and "reduce.web.wasm".'

reduce.img: reduce.js $(package_map)
	-rm -f reduce.img
	export reduce=$(R) &&\
	 $(NODE) reduce.js -z -Dforce_c_code\
	 -Dno_init_file $(MINIREDUCE) $(S)/buildreduce.lsp\
	 -D@srcdir=$(S) -D@reduce=$(R) -o reduce.img\
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
	$(CXX) $(CPPFLAGS) $(NODE_EM_LDFLAGS) $(S)/make-image.cpp\
	 $(LDFLAGS) $(LIBS) $(JSOPTS) -o make-image.js

image.cpp: make-image.js reduce.img
	$(NODE) make-image.js
	cp image.cpp ../reduce-image.cpp
	cp reduce.img ..


# These implicit pattern rules cover most of the object files:

%.o : $(S)/%.cpp $(HEADERS)
	$(CXX) $(CPPFLAGS) -c -o $@ $<
# I do not set NO_BYTECOUNTS on the %.o target because that is used to
# make bootstrapreduce.js which can be used for profiling - an action which
# relies on bytecounts.

%.oo : $(S)/%.cpp $(HEADERS)
	$(CXX) $(CPPFLAGS) -DNO_BYTECOUNTS=1 -c -o $@ $<

%.xo : $(S)/%.cpp $(HEADERS)
	$(CXX) $(CPPFLAGS) -DBUILTIN_IMAGE=1 -DNO_BYTECOUNTS=1 -c -o $@ $<

%.yo : $(S)/%.cpp $(HEADERS)
	$(CXX) $(CPPFLAGS) -DBUILTIN_IMAGE=1 -DPROCEDURAL_WASM_XX=1\
	 $(ASYNCIFY_OPTS) -DNO_BYTECOUNTS=1 -c -o $@ $<

# These rules cover the few special case object files. The
# prerequisites are specified explicitly but the recipes use the
# implicit rules above:

bytes1.o   bytes1.xo   : $(S)/bytes1.cpp $(S)/opnames.cpp $(HEADERS)
cslmpi.o   cslmpi.xo   : $(S)/cslmpi.cpp $(S)/mpipack.cpp $(HEADERS)
embedcsl.o embedcsl.xo : $(S)/embedcsl.cpp $(S)/csl.cpp $(HEADERS)

makeheaders.o : $(S)/makeheaders.cpp
objtype.o : $(S)/objtype.cpp

preserve.xo preserve.yo : $(S)/preserve.cpp image.cpp $(HEADERS)


.PHONY: mostlyclean
# Delete files generated by make except crlibm.
# But DO NOT DELETE package.map if you want to build mini-REDUCE!
mostlyclean:
	-rm -f *.o *.oo *.xo *.yo reduce* *.log make-image* image.cpp
	-rm -f bootstrapreduce* *.bak http.pid  #  *.map
	-rm -rf bin jscsl-times

.PHONY: clean
# Delete all files generated by make.
clean:
	make mostlyclean
	-rm -rf crlibm include lib


# Convenience rules.  It's currently safest to run "make mostlyclean"
# before either of the following targets.

.PHONY: webreduce
webreduce:
	$(MAKE) bootstrapreduce.img
	rm bootstrapreduce.img; $(MAKE) bootstrapreduce.img
	$(MAKE) c-code
	$(MAKE) reduce.img
	$(MAKE) reduce-web

# For a full build of mini-REDUCE for the web, ensure that the copy of
# "package.map" in this directory is consistent with the general
# version but edited as required, then run make mini-webreduce

.PHONY: mini-webreduce
mini-webreduce:
	$(MAKE) MINIREDUCE=-Dminireduce webreduce

# end of Makefile

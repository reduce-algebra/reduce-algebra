# Makefile for embedded and other custom versions of Reduce

# The Makefile here expect to use GNU make, but all the scripts
# obeyed are in fact VERY simple and so anybody who wants to build some
# alternative way ought not to have much trouble.

# This only works using g++ (or clang++, which works hard to be compatible
# with g++).

# The idea here is that there may be many different embedded variants.
# All of them will require a Reduce image file (typically called "reduce.img")
# but I show here how to build two variants. The first if a full image
# including pretty-well ALL of the capabilites of Reduce. The second
# (minireduce) is cut down, and while not quite minimal is at least a
# lot smaller. Anybody trying minireduce will want to review the file
# "packages.map" where it is built to ensure that they include just what
# THEY want. The version I provide here is merely a starting position.

# You should go either "make reduce" or "make minireduce" first to create
# the version of "reduce.img" that interests you.

# Here I always use gcc. As of 2019 I am just testing this on 64-bit
# computers: Cygwin(64), Ubuntu(64) and a Macintosh.

CFLAGS=

.PHONY:	reduce
reduce:
	cd reduce-image && \
		$(MAKE) CFLAGS=$(CFLAGS) reduce.img && \
		cp reduce.img ..

# Thse days I avoid needing these two libraries, but I will leave the recipes
# for building them in place for the benefit of anybody who wants to
# fuss with them.

#lib/libcrlibm.a:
#	mkdir -p crlibm
#	cd crlibm && CFLAGS=$(CFLAGS) \
#		`pwd`/../../../libraries/crlibm/configure --prefix=`pwd`/..
#	cd crlibm && $(MAKE) install

#lib/libsoftfloat.a:
#	mkdir -p softfloat
#	cd softfloat && CFLAGS=$(CFLAGS) \
#		`pwd`/../../../libraries/SoftFloat-3a/source/configure --prefix=`pwd`/..
#	cd softfloat && $(MAKE) install

.PHONY:	minireduce
minireduce:
	cd minireduce-image && \
		$(MAKE) CFLAGS=$(CFLAGS) reduce.img && \
		cp reduce.img ..

# So far I provide only one sample. I call it "proc" and it illustrates
# a procedural interface into Reduce.

.PHONY:	proc
proc:	reduce.img
	cd procedural && $(MAKE) CFLAGS=$(CFLAGS)

# If you go "make proc" without having gone either "make reduce" or
# "make minireduce" first it will default to the full build

reduce.img:	reduce

# Obviously one needs to tidy up occasionally.

clean:
	-rm -f reduce.img lib/* include/crlibm_config.h include/crlibm.h \
		include/scs.h include/softfloat.h include/softfloat_types.h
	if test -d crlibm; then cd crlibm && $(MAKE) clean; fi
	if test -d softfloat; then cd softfloat && $(MAKE) clean; fi
	cd reduce-image && $(MAKE) clean
	cd minireduce-image && $(MAKE) clean
	cd procedural && $(MAKE) clean

# end of Makefile

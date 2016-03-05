# Makefile for embedded and other custom versions of Reduce

# The Makefile here expect to use GNU make, but all the scripts
# obeyed are in fact VERY simple and so anybody who wants to build some
# alternative way ought not to have much trouble.

# This only works using gcc/g++

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

.PHONY:	reduce
reduce: lib/libcrlibm.a lib/libsoftfloat.a
	cd reduce-image && make reduce.img && cp reduce.img ..

lib/libcrlibm.a:
	mkdir -p crlibm
	cd crlibm && CFLAGS=-m32 `pwd`/../../../libraries/crlibm/configure --prefix=`pwd`/..
	cd crlibm && make install

lib/libsoftfloat.a:
	mkdir -p softfloat
	cd softfloat && CFLAGS=-m32 `pwd`/../../../libraries/SoftFloat-3a/source/configure --prefix=`pwd`/..
	cd softfloat && make install

.PHONY:	minireduce
minireduce:	lib/libcrlibm.a lib/libsoftfloat.a
	cd minireduce-image && make reduce.img && cp reduce.img ..

# So far I provide only one sample. I call it "proc" and it illustrates
# a procedural interface into Reduce.

.PHONY:	proc
proc:	lib/libcrlibm.a lib/libsoftfloat.a reduce.img
	cd procedural && make

# If you go "make proc" without having gone either "make reduce" or
# "make minireduce" first it will default to the full build

reduce.img:	reduce

# Obviously one needs to tidy up occasionally.

clean:
	-rm -f reduce.img lib/* include/*
	if test -d crlibm; then cd crlibm && make clean; fi
	if test -d softfloat; then cd softfloat && make clean; fi
	cd reduce-image && make clean
	cd minireduce-image && make clean
	cd procedural && make clean

# end of Makefile
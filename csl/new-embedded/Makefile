# Makefile for embedded and other custom versions of Reduce

# The Makefile here expect to use GNU make, but all the scripts
# obeyed are in fact VERY simple and so anybody who wants to build some
# alternative way ought not to have much trouble.


# The idea here is that there may be many different embedded variants.
# All of them will require a Reduce image file (typically called "reduce.img")
# but I show here how to build two variants. The first if a full image
# including ALL of the capabilites of Reduce. The second (minireduce) is
# cut down, and while not quite minimal is at least a lot smller. Anybody
# trying minireduce will want to review the file "packages.map" where it is
# built to ensure that they include just what THEY want. The version I provide
# here is merely a starting position.

# You should go either "make reduce" or "make minireduce" first to create
# the version of "reduce.img" that interests you.

.PHONY:	reduce
reduce:
	cd reduce-image && make reduce.img && cp reduce.img ..

.PHONY:	minireduce
minireduce:
	cd minireduce-image && make reduce.img && cp reduce.img ..

# So far I provide only one sample. I call it "proc" and it illustrates
# a procedural interface into Reduce.

.PHONY:	proc
proc:
	cd procedural && make

# Obviuously one needs to tody up occasionally.

clean:
	-rm -f reduce.img
	cd reduce-image && make clean
	cd minireduce-image && make clean
	cd procedural && make clean

# end of Makefile
# Makefile for embedded and other custom versions of Reduce

reduce.img:
	cd reduce-image && make reduce.img && cp reduce.img ..

proc:	reduce.img
	cd procedural && make

clean:
	-rm -f reduce.img
	cd reduce-image && make clean
	cd procedural && make clean

# end of Makefile
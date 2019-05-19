# Do local maintenance in the cslbase directory

csl.pdf:	csl.tex
	rm -f csl.ind
	pdflatex csl
	makeindex csl
	pdflatex csl

lispfile:
	./lispfile.sh


.PHONY:	charmetrics.h
charmetrics.h:	charmetrics.cpp
	g++ -DCREATE charmetrics.cpp -o charmetrics && \
	./charmetrics && \
	g++ -DTEST charmetrics.cpp -o charmetrictest && \
	./charmetrictest

.PHONY: coverage.cpp
coverage.cpp:
	g++ glyphtable.cpp -o glyphtable
	./glyphtable wxfonts/*.glyphs

doxtract:	doxtract.cpp
	g++ doxtract.cpp -o doxtract

.PHONY:	csl.tex
csl.tex:	doxtract *.red *.lsp
	./doxtract -p csl -o csl.tex *.h *.cpp *.red *.lsp

# The following conversion does not map from C to C++ in any real way. It
# merely updates comments from "/* ... */" style to "//" style and re-indents
# code in a consistent way that is at least close to the one I have used
# when I hand-indent things.

c2cpp:	c2cpp.cpp
	g++ -O2 c2cpp.c -o c2cpp

# This is something I will want to be very cautious about and NOT do
#  automatically because if I where to reset a timestamp on any legacy
# C code this would clobber the C++ version even if I had made further
# adjustments to it. But the recipe here is to remind me how I did the
# initial conversion.

#%.cpp:	%.c c2cpp
#	./c2cpp $< $@
#	astyle $@

# Tests and demonstrations of arithlib.hpp

ifeq ($(shell uname -o),Cygwin)
LIBS=-lgmp
else
LIBS=-lgmp -lpthread
endif

# "arithtest" tries to do fairly full testing of arithlib.hpp for correctness
# while running it in the mode where it is accessed via C++. Towards the top
# of arithtest.cpp there are a sequence of #define statements that enable
# various papts of the testing. The complete set of tests runs for a time
# that may be of the order of 15 minutes to a few hours depending on the
# speed of the computer being used. It starts with some dull output that is
# just there to confirm the basic setup, but then as it runs the hoped-for
# output is merely "Bitwise operation tests completed in NNN sec" and the
# like, while in the case of trouble it should be more verbose.

.PHONY:	arithtest

arithtest:	arithtest.cpp arithlib.hpp
	g++ -O3 arithtest.cpp $(LIBS) -o arithtest
	time ./arithtest

# "time-arith" tries to compare (crudely) the speed of the existing (or
# dare I now say "old"?) CSL arithmetic based on 31-bit digits with the
# performance of arithlib that used 64-bit digits. On a 64-bit machine
# this shows the newer code winning fairly convincingly! On general grounds
# one could start with a prediction that long addition and subtraction might
# be twice as fast using 64-bit digits, with long multiplication and division
# showing a factor of 4 in the range where classical methods are used and
# one of 3 for numbers big enough to trigger Karatsuba multiplication. I
# believe that the results from this test (which just tries huge
# multiplication) is in reasonable agreement with that.

.PHONY:	time-arith

time-arith:	time-arith.sh
	./time-arith.sh

# end of Makefile in cslbase

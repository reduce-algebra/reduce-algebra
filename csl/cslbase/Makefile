# Do local maintenance in the cslbase directory

SHELL=bash

ifeq ($(OS),Windows_NT)
else
  UNAME_S := $(shell uname -s)
  ifeq ($(UNAME_S),Darwin)
    MACFLAGS=-I/opt/local/include -L/opt/local/lib -std=gnu++17
  endif
endif

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

# Tests and demonstrations of arithlib.cpp

# The file arithlib.cpp is maintained in the form of a top level file
# arithlib.base.cpp and a collection of files that it uses "#include" to
# get merged in. The utility flatten performs the expansion for me. The
# consequence of this is that arithlib.cpp is a single free-standing
# header-only library, but if you also #include one of the things it
# incorporates (eg threadloc.h or lvector.h) then there will be no clash.
#
# I also create aritrhlib.h by scanning arithlin.cpp and extracting the
# declarations in it.

flatten:	flatten.cpp
	g++ $(CXXFLAGS) flatten.cpp -o flatten

makeheader:	makeheader.cpp makeheader.lex
	flex  -o lexheader.cpp makeheader.lex
	g++ $(CXXFLAGS) makeheader.cpp -o makeheader

lvector.h:	flatten lvector.base.h threadloc.h
	./flatten lvector.base.h lvector.h

multiply.cpp:	flatten multiply.base.cpp inlinemul.cpp lvector.h \
		cthread.cpp fftmod.cpp fftkernel.cpp
	./flatten multiply.base.cpp multiply.cpp

arithlib.cpp:	flatten makeheader arithlib.base.cpp lvector.h \
		acnutil.h multiply.base.cpp inlinemul.cpp \
		fftutils.cpp fftmod.cpp fftkernel.cpp bitmaps.h cthread.cpp
	./flatten arithlib.base.cpp arithlib.cpp
	./makeheader arithlib.cpp arithlib.h

arithlib.h:	arithlib.cpp

geninline:	geninline.cpp
	g++ $(CXXFLAGS) geninline.cpp -o geninline

inlinemul.cpp:	geninline
	./geninline > inlinemul.cpp



ifeq ($(shell uname -o),Cygwin)
LIBS=-lgmp
else
LIBS=-lgmp -lpthread
endif

# "arithtest" tries to do fairly full testing of arithlib.cpp for correctness
# while running it in the mode where it is accessed via C++. Towards the top
# of arithtest.cpp there are a sequence of #define statements that enable
# various parts of the testing. The complete set of tests runs for a time
# that may be of the order of 15 minutes to a few hours depending on the
# speed of the computer being used. It starts with some dull output that is
# just there to confirm the basic setup, but then as it runs the hoped-for
# output is merely "Bitwise operation tests completed in NNN sec" and the
# like, while in the case of trouble it should be more verbose.

.PHONY:	arithtest

arithtest:	arithtest.cpp arithlib.cpp
	time g++ -O3 -std=gnu++17 $(MACFLAGS) arithtest.cpp arithlib.cpp $(LIBS) -o arithtest
# If one runs arithtest without a command line paramater it should seed
# its random number generator in an unpredictable way. Specifing an integer
# uses that as the seed for repeatable behaviour.
	-time ./arithtest 1

.PRECIOUS:	arithtestg
arithtestg:	arithtest.cpp arithlib.cpp
	time g++ -O0 -g -std=gnu++17 $(MACFLAGS) arithtest.cpp \
		-DDEBUG=1 $(LIBS) \
		-o arithtestg
	-time ./arithtestg 1

.PHONY:	arithtestwin

# At present this DOES NOT BUILD AND RUN for me because of some
# linking issues against gmp... I hope to sort those out later.

arithtestwin:	arithtest.cpp arithlib.cpp
	time x86_64-w64-mingw32-g++ -O3 -std=gnu++17 --static \
		arithtest.cpp -Wl,--subsystem,console \
		-lgmp -o arithtestwin
	-time ./arithtestwin 1


# "karatune" attepts to judge a proper value for KARATSUBA_CUTOFF

.PHONY:	karatune

ifeq ($(shell uname -o),Cygwin)
KLIBS=
else
KLIBS=-lpthread
endif

karatune:	karatune.cpp arithlib.cpp
	g++ $(MACFLAGS) -std=gnu++17 -O3 karatune.cpp arithlib.cpp \
		$(KLIBS) -o karatune
	time ./karatune


# "karatunewin" attepts to judge a proper value for KARATSUBA_CUTOFF
# but is only for use on Windows systems. Note both use of the
# console subsystem and static linking here!

.PHONY:	karatunewin

karatunewin:	karatune.cpp arithlib.cpp
	x86_64-w64-mingw32-g++ \
		-std=gnu++17 -O3 karatune.cpp arithlib.cpp --static \
		-Wl,--subsystem,console -o karatunewin
	time ./karatunewin

ffttune:	ffttune.cpp arithlib.cpp
	g++ $(MACFLAGS) -std=gnu++17 -O3 ffttune.cpp arithlib.cpp \
		$(KLIBS) -o ffttune
	time ./ffttune

# end of Makefile in cslbase


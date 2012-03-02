# Makefile for vsl

ifeq ($(findstring Windows, $(OS)), Windows)
CC = i686-w64-mingw32-gcc
CXX = i686-w64-mingw32-g++
else
CC = gcc
CXX = g++
endif

all:	vsl vsl.img vslmanual.pdf

vsl:	vsl.c
	$(CC) -O2 -Wall vsl.c -lm -o vsl

vsl.img:	vsl library.lsp
	./vsl -z library.lsp

reduce:
	mkdir -p modules
	rm -f modules/* reduce.img
	./vsl -z -ireduce.img -D@srcdir=. -D@reduce=.. \
	  buildreduce.lsp > reduce.log

# To run Reduce go
#    ./vsl -ireduce.img
# then
#    in "alg.tst";
# runs a test/demo script.

clean:
	rm -f *.o *.bak *.exe *.log *.img vsl

# To build this you need to go "make vslmanual.pdf" explicitly. It is
# not done automatically because not everybody will have installed
# pdflatex.

vslmanual.pdf:	vslmanual.tex vslfunctions.tex
	touch vslmanual.ind
	pdflatex vslmanual.tex
	makeindex vslmanual.idx
	pdflatex vslmanual.tex
	pdflatex vslmanual.tex

# end of Makefile




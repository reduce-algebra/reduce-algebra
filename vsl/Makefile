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
	./vsl -z buildreduce.lsp > reduce.log 2>&1

clean:
	rm -f *.o *.bak *.exe *.log *.img vsl

vslmanual.pdf:	vslmanual.tex vslfunctions.tex
	touch vslmanual.ind
	pdflatex vslmanual.tex
	makeindex vslmanual.idx
	pdflatex vslmanual.tex
	pdflatex vslmanual.tex


# end of Makefile




# end of Makefile




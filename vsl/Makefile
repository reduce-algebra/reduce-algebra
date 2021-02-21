# Makefile for vsl

CC = gcc
OPT = -O3

all:	vsl vsl.img vslmanual.pdf

# The "PSL" target makes vsl but with a reader that treats most punctuation
# characters as if they were letters so that symbols can have names such as
# *x*, &a, abc-def, 1+ and {q} without needing escape characters.

# I am making vsl use "libedit" for input local editing, which gives it
# input history etc. 

psl:	vslpsl vsl.img

.PHONY:	vslpsl

vsl:	vsl.c
	$(CC) $(OPT) -Wall vsl.c -lm -ledit -o vsl

vsl1:	vsl1.c
	$(CC) $(OPT) -Wall vsl1.c -lm -ledit -lz -o vsl1

vsl1d:	vsl1.c
	$(CC) -O0 -g -Wall vsl1.c -lm -ledit -lz -o vsl1d

vslpsl:	vsl.c
	$(CC) -DPSL=1 $(OPT) -Wall vsl.c -lm -ledit -o vsl

vsl.img:	vsl library.lsp vsl.lsp extras.lsp
	./vsl -z library.lsp

vsl1.img:	vsl1 library.lsp vsl.lsp extras.lsp
	./vsl1 -z library.lsp -ivsl1.img

reduce:	vsl1
	mkdir -p reduce.img.modules
	rm -f reduce.img.modules/* reduce.img
	./vsl1 -z -ireduce.img -D@srcdir=. -D@reduce=.. \
	   buildreduce.lsp | tee reduce.log


clean:
	rm -f *.o *.bak *.exe *.log *.img vsl *.ind *.aux *.idx *.ilg *~

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




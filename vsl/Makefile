# Makefile for vsl

CC = gcc

all:	vsl vsl.img vslmanual.pdf

# The "PSL" target makes vsl but with a reader that treats most punctuation
# characters as if they were letters so that symbols can have names such as
# *x*, &a, abc-def, 1+ and {q} without needing escape characters.

# I am making vsl use "libedit" for input local editing, which gives it
# input history etc. 

psl:	vslpsl vsl.img

.PHONY:	vslpsl

vsl:	vsl.c
	$(CC) -O3 -Wall vsl.c -lm -ledit -o vsl

vslpsl:	vsl.c
	$(CC) -DPSL=1 -O3 -Wall vsl.c -lm -ledit -o vsl

vsl.img:	vsl library.lsp vsl.lsp extras.lsp
	./vsl -z library.lsp

clean:
	rm -f *.o *.bak *.exe *.log *.img vsl *.ind *.pdf *.aux *.idx *.ilg *~

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




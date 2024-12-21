# Makefile for vsl

# *WARNING*
#   As of December 2024 "vsl.c" is out of date and should not be used
#   until it has been reviewed.
#   "vsl1.c" is the version of this code that implements a more complet
#   Lisp and can be used to build Reduce.
#   The main current command here is "make reduce" followed by
#       ./vsl1 -i reduce.img
#
# There is other stuff here relating to the start of a project to use
# vsl to perform the first stages of a bootstrap build of PSL. This
# is experimental and incomplete, but has got far enough that it is
# probably "proof of concept".

# You can go "make OPT=xxx" to select different optimization choices,
# or "make NOLIBEDIT=-DNOLIBEDIT" if libedit/editline is not available.

ifneq ($(shell which clang),)
CC=clang
else
ifneq ($(shell which cc),)
CC=cc
else
CC=gcc
endif
endif

OPT=-O3

all:	vsl vsl.img vslmanual.pdf

# The "PSL" target makes vsl but with a reader that treats most punctuation
# characters as if they were letters so that symbols can have names such as
# *x*, &a, abc-def, 1+ and {q} without needing escape characters.

# I am making vsl use "libedit" for input local editing, which gives it
# input history etc. unless you predefined NOLIBEDIT.

psl:	vslpsl vsl.img

.PHONY:	vslpsl

vsl:	vsl.c
	$(CC) $(OPT) $(NOLIBEDIT) -Wall vsl.c -lm -ledit -o vsl

vsl1:	vsl1.c
	$(CC) $(OPT) $(NOLIBEDIT) -Wall vsl1.c -lm -ledit -lz -o vsl1

vsl1d:	vsl1.c
	$(CC) -O0 -g $(NOLIBEDIT) -Wall vsl1.c -lm -ledit -lz -o vsl1d

vslpsl:	vsl.c
	$(CC) -DPSL=1 $(OPT) $(NOLIBEDIT) -Wall vsl.c -lm -ledit -o vsl

vsl.img:	vsl library.lsp vsl.lsp extras.lsp
	./vsl -z library.lsp

vsl1.img:	vsl1 library.lsp vsl.lsp extras.lsp
	./vsl1 -z library.lsp -ivsl1.img

reduce:	vsl1
	mkdir -p reduce.img.modules
	rm -f reduce.img.modules/* reduce.img
	./vsl1 -z -g -ireduce.img -D@srcdir=. -D@reduce=.. \
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

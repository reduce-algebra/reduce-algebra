# Do local maintenance in the cslbase directory

csl.pdf:	csl.tex
	pdflatex csl
	pdflatex csl

lispfile:
	./lispfile.sh


doxtract:	doxtract.c
	gcc doxtract.c -o doxtract

csl.tex:	doxtract *.h *.c *.cpp *.red *.lsp
	./doxtract -p csl -o csl.tex *.h *.c *.cpp *.red *.lsp

# end of Makefile in cslbase
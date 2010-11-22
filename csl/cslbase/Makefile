# Do local maintenance in the cslbase directory

csl.pdf:	csl.tex
	latex csl
	latex csl
	dvips csl -o csl.ps
	ps2pdf csl.ps csl.pdf
	-rm csl.aux csl.dvi csl.ps csl.log

lispfile:
	./lispfile.sh

# end of Makefile in cslbase
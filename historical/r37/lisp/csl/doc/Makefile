
all:	uguide.ps uguide.pdf install.ps install.pdf

uguide.pdf:	uguide.dvi
	dvipdfm uguide

uguide.ps:	uguide.dvi
	dvips uguide

uguide.dvi:	uguide.tex
	latex uguide
	latex uguide
	latex uguide


	latex uguide


install.pdf:	install.dvi
	dvipdfm install

install.ps:	install.dvi
	dvips install

install.dvi:	install.tex
	latex install
	latex install
	latex install


# end of makefile
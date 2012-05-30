
all: primer.pdf sl.pdf


sl.pdf:		sl.tex sl.bib
	./mkpdf.sh sl
	bibtex sl
	./mkpdf.sh sl

rmtmpfiles:
	rm -f *.aux *.toc *.idx *.tmp *.xref *.idv *.out .4?? *.blg

clean:	rmtmpfiles
	rm -f sl.bbl *.pdf *.log *.ilg *.lg *.dvi *.ind *.png

%.pdf:	%.tex
	./mkpdf.sh $(*F)



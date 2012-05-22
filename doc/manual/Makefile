
all:	manual-pdf.pdf index.html

manual-pdf.pdf:	manual-pdf.tex
	./mkpdf.sh

index.html:	manual-pdf.tex
	./mkhtml.sh



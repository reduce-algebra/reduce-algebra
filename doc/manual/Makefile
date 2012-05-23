
DOCBASE=manual-pdf

all:	$(DOCBASE).pdf index.html

rmtmpfiles:
	rm -f $(DOCBASE)*.aux $(DOCBASE)*.toc $(DOCBASE)*.idx $(DOCBASE)*.tmp $(DOCBASE)*.xref $(DOCBASE)*.idv $(DOCBASE)*.out $(DOCBASE).4??

clean:	rmtmpfiles
	rm -f index.html $(DOCBASE)*.html $(DOCBASE)*.css $(DOCBASE)*.pdf $(DOCBASE)*.log $(DOCBASE)*.ilg $(DOCBASE)*.lg $(DOCBASE)*.dvi $(DOCBASE)*.ind $(DOCBASE)*.png

$(DOCBASE).pdf:	$(DOCBASE).tex
	./mkpdf.sh

index.html $(DOCBASE).html $(DOCBASE).css:	$(DOCBASE).tex
	./mkhtml.sh



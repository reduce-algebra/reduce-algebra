
DOCBASE=manual

all:	$(DOCBASE).pdf index.html

rmtmpfiles:
	rm -f *.aux $(DOCBASE)*.toc $(DOCBASE)*.idx $(DOCBASE)*.tmp $(DOCBASE)*.xref $(DOCBASE)*.idv $(DOCBASE)*.out $(DOCBASE).4??

clean:	rmtmpfiles
	rm -f index.html $(DOCBASE)*.html $(DOCBASE)*.css $(DOCBASE)*.pdf $(DOCBASE)*.log $(DOCBASE)*.ilg $(DOCBASE)*.lg $(DOCBASE)*.dvi $(DOCBASE)*.ind $(DOCBASE)*.png

$(DOCBASE).pdf:	$(wildcard *.tex)
	./mkpdf.sh

index.html $(DOCBASE).html $(DOCBASE).css:	$(wildcard *.tex)
	./mkhtml.sh



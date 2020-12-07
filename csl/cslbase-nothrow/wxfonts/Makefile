# Simple Makefile assuming the gcc is available. This should not need
# re-use by ordinary users and so absolute portability (and autoconf) is
# not essential.

all:	metrics/cslSTIX-Regular.afm \
	metrics/cslSTIX-Bold.afm \
	metrics/cslSTIX-Italic.afm \
	metrics/cslSTIX-BoldItalic.afm \
	metrics/cslSTIXMath-Regular.afm

metrics/cslSTIX-Regular.afm:	makeafm
	./makeafm metrics/cslSTIX-Regular.tables

metrics/cslSTIX-Bold.afm:	makeafm
	./makeafm metrics/cslSTIX-Bold.tables

metrics/cslSTIX-Italic.afm:	makeafm
	./makeafm metrics/cslSTIX-Italic.tables

metrics/cslSTIX-BoldItalic.afm:	makeafm
	./makeafm metrics/cslSTIX-BoldItalic.tables

metrics/cslSTIXMath-Regular.afm:	makeafm
	./makeafm metrics/cslSTIXMath-Regular.tables

makeafm:	makeafm.c
	gcc -g -O1 makeafm.c -o makeafm

clean:
	rm -f metrics/cslSTIX-Regular.afm
	rm -f metrics/cslSTIX-Bold.afm
	rm -f metrics/cslSTIX-Italic.afm
	rm -f metrics/cslSTIX-BoldItalic.afm
	rm -f metrics/cslSTIXMath-Regular.afm

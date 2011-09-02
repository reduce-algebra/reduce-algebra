#
# $Id: Makefile,v 3.26 1992/03/25 04:53:29 woo Exp woo $
#
# Makefile for GNUPLOT documentation
#
# Note that the top-level file for documentation is gnuplot.doc.
# See README.
#
# To print manual:
#    make gnuplot.dvi             (for latex)
#    (print or view gnuplot.dvi)
# OR
#    make gnuplot.nroff           (for nroff)
#    (print or view gnuplot.nroff)
#   or
#    make "TROFF=itroff" troff    (for troff; use your troff here)
#
# $Id: Makefile,v 3.26 1992/03/25 04:53:29 woo Exp woo $

# usually overridden by ../Makefile
HELPDEST = /usr/local/lib/

# substitute your troff command (and any flags) for this one
TROFF=troff
  
# substitute cp if you do not have the install program
INSTALL=install

# Compiler flags
# -DSYSV if att sys V
# -DMSDOS if MSDOS PS
# -traditional -g -O if gcc (set 'CC = gcc')
# no extra flags for BSD
CFLAGS = -s
CC = cc

# default is what is needed for interactive gnuplot
default: gnuplot.hlp gnuplot.gih

### [tn]roff documentation
troff: gnuplot.ms titlepage.ms
	tbl gnuplot.ms | eqn | $(TROFF) -ms

nroff gnuplot.nroff: gnuplot.ms titlepage.ms
	tbl gnuplot.ms | neqn | nroff -ms | col > gnuplot.nroff

ms gnuplot.ms: doc2ms gnuplot.doc
	./doc2ms < gnuplot.doc > gnuplot.ms

doc2ms: doc2ms.c
	$(CC) $(CFLAGS) -o doc2ms doc2ms.c

### LaTeX documentation
tex gnuplot.tex: doc2tex gnuplot.doc
	./doc2tex < gnuplot.doc > gnuplot.tex

dvi gnuplot.dvi: gnuplot.tex titlepage.tex
	(latex gnuplot.tex ; latex gnuplot.tex)

doc2tex: doc2tex.c
	$(CC) $(CFLAGS) -o doc2tex doc2tex.c

# this is how to make gnuplot.hlp
hlp gnuplot.hlp: doc2hlp gnuplot.doc
	./doc2hlp < gnuplot.doc > gnuplot.hlp

doc2hlp: doc2hlp.c
	$(CC) $(CFLAGS) -o doc2hlp doc2hlp.c

# this is how to make gnuplot.gih
gih gnuplot.gih: doc2gih gnuplot.doc
	./doc2gih < gnuplot.doc > gnuplot.gih

doc2gih: doc2gih.c
	$(CC) $(CFLAGS) -o doc2gih doc2gih.c

# this is how to check the gnuplot.doc file
check: checkdoc gnuplot.doc
	./checkdoc < gnuplot.doc

checkdoc: checkdoc.c
	$(CC) $(CFLAGS) -o checkdoc checkdoc.c

# For Unix and MSDOS only
install-unix: gnuplot.gih
	$(INSTALL) gnuplot.gih $(HELPDEST)

# for VMS only
install-vms: gnuplot.hlp
	$(INSTALL) gnuplot.hlp $(HELPDEST)

# remove all derived files
clean:
	rm -f doc2ms gnuplot.nroff gnuplot.ms
	rm -f doc2tex gnuplot.tex gnuplot.dvi gnuplot.aux gnuplot.log gnuplot.toc
	rm -f doc2hlp gnuplot.hlp
	rm -f doc2gih gnuplot.gih
	rm -f checkdoc *~ *.o core a.out

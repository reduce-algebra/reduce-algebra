# Makefile for uFy project

# uFy is the start of an adaptation of TeX to provide a Lisp/Reduce
# screen driver. It takes the original Knuth TeX source (tex.web) and
# as a first step it converts it into Pascal and then into a Lisp-readable
# parse tree. Then name "uFy" is obtained from "TeX" by moving from
# T to u, e to F and X to y. It is intended to be a name that reflects the
# TeX origin of this code but that should never cause confusion with the
# original. 

# $Id: $

all:	ufy.log

# Use "tangle" to map the original literate tex source into
# Pascal.

tex.p:	tex.web
	tangle tex.web

# "p2l" is a Pascal to Lisp converter, and it has three components.
# The first is flex lexer...

plex.cpp:	p2l.l
	flex -o plex.cpp p2l.l

# The second is a bison parser...

p2l.tag.hpp p2l-generated.cpp:	p2l.ypp
	bison -d p2l.ypp -o p2l-generated.cpp

# The final one is some hand-written glue in p2l.cpp that builds and then
# dumps a parse tree. This code has been written clumsily and without
# concern for error checking or recovery. It is only intended for use in
# the single context of the translation performed here. Furthermore the
# "parse tree" generated is ugly in many respects. The expectation is that
# tidying it up will be best done using Lisp code rather that au this
# C++ stage.

p2l:	p2l.cpp p2l-generated.cpp p2l.tag.hpp plex.cpp
	g++ p2l.cpp p2l-generated.cpp plex.cpp -lfl -o p2l

# Run p2l to convert tex.p.

.PHONY:	ufy.log
ufy.log:	tex.p p2l
	./p2l < tex.p | tee ufy.log

# Discard all files that can be re-generated.

.PHONY:	clean
clean:
	rm -f *.o *.log *~ *.bak *.old\
		tex.p tex.pool \
		p2l-generated.hpp p2l-generated.cpp plex.cpp \
		p2l p2l.exe
		

# end of Makefile

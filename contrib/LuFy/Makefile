# Makefile for LuFy project

# LuFy is the start of an adaptation of TeX to provide a Lisp/Reduce
# screen driver. It takes the original Knuth TeX source (tex.web) and
# as a first step it converts it into Pascal and then into a Lisp-readable
# parse tree. Then name "LuFy" is obtained from "TeX" by moving from
# T to u, e to F and X to y with an L for Lisp on the front.
# It is intended to be a name that reflects the TeX origin of this code
# but that should never cause confusion with the original. 

# $Id$

# I will need "tangle", "flex" and "bison" installed.

all:	lufy.red

# Use "tangle" to map the original literate tex source into
# Pascal.

tex.p:	tex.web
	rm -f tex.p
	tangle tex.web

# "Free Pascal" (https://www.freepascal.org/) comes with a utility "ptop"
# that can prettyprint Pascal code, and the raw output from tangle is
# in pretty despate need of prettyprinting. The path to ptop corresponds
# to the default location the Free Pascal installer put it for me. The
# sed script is to get rid of {nn:} and {:mm} comments that tangle leave in
# its expanded code that may refer back to the literate documentation but
# that otherwise get in my way.

# I do not actually use tex.pas in my transformation pipeline here, but it is
# really useful to have it around as a somewhat human readable version
# of the Pascal code. I mess around with sed so that character literals '{'
# and '}' are not discarded as comments, but that otherwise things within
# braces get removed. I am not fully comfortable that I will cope with
# all potential arrangements of braces here, but the output I generate
# is merely for documentation so it it is "tidy enough" I may be content.

tex.pas:	tex.p
	sed -e "s/'{'/@@@1/g" -e "s/'}'/@@@2/g" tex.p | \
		sed "s/{[^}]*}/ /g" | \
		sed '/{/,/}/d' | \
		sed -e "s/@@@1/'{'/g" -e "s/@@@2/'}'/g" > tex.tmp
	/cygdrive/c/FPC/3.0.2/bin/i386-win32/ptop -l 72 tex.tmp tex.pas
	rm tex.tmp

# "p2l" is my Pascal to Lisp converter, and it has three components.
# The first is flex lexer...

plex.cpp:	p2l.l
	flex -o plex.cpp p2l.l

# The second is a bison parser...

p2l-generated.hpp:	p2l-generated.cpp

p2l-generated.cpp:	p2l.ypp
	bison -d p2l.ypp -o p2l-generated.cpp
	touch p2l-generated.hpp

# The final one is some hand-written glue in p2l.cpp that builds and then
# dumps a parse tree. This code has been written clumsily and without
# concern for error checking or recovery. It is only intended for use in
# the single context of the translation performed here. Furthermore the
# "parse tree" generated is ugly in many respects. The expectation is that
# tidying it up will be best done using Lisp code rather that at this
# C++ stage.

# On the Mac when flex has been installed using macports I need to
# scan /opt/local/lib to be able to find its support module.

p2l:	p2l.cpp p2l-generated.cpp p2l-generated.hpp plex.cpp
	if test -d /opt/local/lib; then L="-L/opt/local/lib"; \
	else L=""; fi; \
	g++ p2l.cpp p2l-generated.cpp plex.cpp $$L -lfl -o p2l

# Run p2l to convert tex.p.
# lufy.raw is the parse tree for the Pascal code but in an crude form
# that merely ties to capture the syntax. It will not be usable until I
# have processed it somewhat more.

lufy.raw:	tex.p p2l
	./p2l < tex.p > lufy.raw

# Run some rlisp code that reads in lufy.raw and creates lufy.red

# There is a misery here about how to invoke Reduce. I look in turn for
#     redcsl             (ie installed on your PATH)
#     $reduce/bin/redcsl (if "$reduce" is your Reduce build tree)
#     $O/bin/redcsl      (I use "$O" for the root of my private build tree)
#     reduce             (a fall-back)
#
# Eventually I should work to make the code support either PSL or CSL,
# but for now it will be being developed as a CSL-only system.

lufy.red:	lufy.raw p2l.red
	if which redcsl; then R="redcsl -w"; \
	elif test -x "$$reduce/bin/redcsl"; then R="$$reduce/bin/redcsl -w"; \
	elif test -x "$$O/bin/redcsl"; then R="$$O/bin/redcsl -w"; \
	else R=reduce; fi; \
	$$R < p2l.red > p2l.log

# Discard all files that can be re-generated.

.PHONY:	clean
clean:
	rm -f *.o *.log *~ *.bak *.old\
		tex.p tex.pool *.tmp lufy.raw tex.pas \
		p2l-generated.hpp p2l-generated.cpp plex.cpp \
		p2l p2l.exe \
		lufy.red
		

# end of Makefile

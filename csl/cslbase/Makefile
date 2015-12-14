# Do local maintenance in the cslbase directory

csl.pdf:	csl.tex
	rm -f csl.ind
	pdflatex csl
	makeindex csl
	pdflatex csl

lispfile:
	./lispfile.sh


.PHONY:	charmetrics.h
charmetrics.h:	charmetrics.cpp
	g++ -DCREATE charmetrics.cpp -o charmetrics && \
	./charmetrics && \
	g++ -DTEST charmetrics.cpp -o charmetrictest && \
	./charmetrictest

.PHONY: coverage.cpp
coverage.cpp:
	g++ glyphtable.cpp -o glyphtable
	./glyphtable wxfonts/*.glyphs

doxtract:	doxtract.cpp
	g++ doxtract.cpp -o doxtract

.PHONY:	csl.tex
csl.tex:	doxtract *.red *.lsp
	./doxtract -p csl -o csl.tex *.h *.cpp *.red *.lsp

# The following conversion does not map from C to C++ in any real way. It
# merely updates comments from "/* ... */" style to "//" style and re-indents
# code in a consistent way that is at least close to the one I have used
# when I hand-indent things.

c2cpp:	c2cpp.cpp
	g++ -O2 c2cpp.c -o c2cpp

# This is something I will want to be very cautious about and NOT do
#  automatically because if I where to reset a timestamp on any legacy
# C code this would clobber the C++ version even if I had made further
# adjustments to it. But the recipe here is to remind me how I did the
# initial conversion.

#%.cpp:	%.c c2cpp
#	./c2cpp $< $@
#	astyle $@

# end of Makefile in cslbase

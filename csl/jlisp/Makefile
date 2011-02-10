# Makefile for "Jlisp"
# Now using a reasonably standard "make" syntax.


all:	jlisp.jar

.PHONY:	clean
clean:
	-rm -f *.jar *.class *.bak *~



jlisp.jar:	*.java jlisp_manifest
# Well many people would have me put everything in a package, and might
# look for neater ways of only compiling what I need to. The rule here
# is clumsy in that arbitrary stray java source code that just HAPPENS to
# end up in this directory (eg including old versions etc) risks ending up
# in the jar file.
	javac *.java
	jar cmf jlisp_manifest jlisp.jar *.class default.img


JLISP	= java -jar jlisp.jar


###########################################################################

C = ../cslbase

jlisp.img:	jlisp.jar
	-rm -f jlisp.img
	$(JLISP) -w -v -z -o jlisp.img $(C)/buildcsl.lsp \
		-D@cslbase="$(C)" -- jlispimg.log



reduce.img:	jlisp.jar
	-rm -f jlisp.img
	$(JLISP) -w -v -z -o reduce.img $(C)/buildreduce.lsp \
		-D@srcdir="$(C)" -L reduce.log




# end of Makefile

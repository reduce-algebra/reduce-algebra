# Makefile for "Jlisp"
# Now using a reasonably standard "make" syntax.


all:	reduce.jar jlisp.jar

.PHONY:	clean
clean:
	-rm -f *.jar *.class *.img *.log *.bak *~

# The idea here is that the jar file contains EVERYTHING needed for
# Reduce, and so "java -jar jlisp.jar" will launch the system with its
# default image file.

reduce.jar:	*.java jlisp_manifest reduce.img
	javac *.java
	cp reduce.img default.img
	-rm -f reduce.jar
	jar cmf jlisp_manifest reduce.jar *.class default.img
	rm default.img

# jlisp.jar is merely the Lisp system without any algebra. If may sometimes
# be easier to work with this smaller system while developing or interfacing?

jlisp.jar:	*.java jlisp_manifest jlisp.img
	javac *.java
	cp jlisp.img default.img
	-rm -f jlisp.jar
	jar cmf jlisp_manifest jlisp.jar *.class default.img
	rm default.img


JLISP   = java -jar jlisp.jar -i jlisp.img
REDUCE	= java -jar jlisp.jar


###########################################################################

C = ../cslbase

# I make the targets here .PHONY so that (eg) "make reduce.img" always
# rebuilds the image even though I have not got careful dependencies set up
# to make it clear why this is necessary.

.PHONY:	jlisp.img
jlisp.img:
	javac *.java
	-rm -f jlisp.img
	java Jlisp -w -v -z -o jlisp.img $(C)/buildcsl.lsp \
		-D@cslbase="$(C)" -- jlispimg.log



.PHONY:	reduce.img
reduce.img:
	javac *.java
	-rm -f reduce.img
	java Jlisp -w -v -z -o reduce.img $(C)/buildreduce.lsp \
		-D@srcdir="$(C)" -- reduce.log




# end of Makefile

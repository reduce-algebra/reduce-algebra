# Makefile for "Jlisp"
# This version uses the gcc386 "make" utility

all:	jlisp.zip

clean:
	-rm *.class
	-rm *.bak
	-rm *~
	-rm jlisp.zip

test:	jlisp.zip
	jlisp < test.lsp

CLASSES = Bps.class CharCounter.class CharGetter.class Cons.class \
	DoubleWriter.class \
	EchoReader.class Fasl.class Fns.class Fns1.class Fns2.class \
	Fns3.class Interpreted.class Jlisp.class \
	JlispInner.class LispBroadcast.class LispEqHash.class \
	LispEqObject.class LispException.class LispFile.class \
	LispFloat.class LispFunction.class LispHash.class \
	LispInputFile.class LispInteger.class LispNumber.class \
	LispObject.class LispOutputFile.class LispString.class \
	LispTokenizer.class LispVector.class LispWriter.class \
	Macro.class ProgEvent.class Specfn.class \
	SpecialFunction.class Symbol.class Undefined.class


jlisp.zip:	$(CLASSES)
	zip -q jlisp.zip *.class


.SUFFIXES:	.java .class

JSTORE = 64000000

# I tell javac that it can use up to $(JSTORE) bytes of memory when
# compiling things.

.java.class:
	javac -deprecation -J-mx$(JSTORE) $<


RM = rm

jlisp.img:	jlisp.zip compat.lsp compiler.lsp ccomp.lsp extras.lsp
	-$(RM) jlisp.img
	jlisp $(STORE) -v -z -o jlisp.img build0.lsp -- jlispimg.log

# end of makefile.gnu


# Makefile.am for redfront project

# $Id:

bin_PROGRAMS = rfpsl rfcsl

if WINDOWS
dist_bin_SCRIPTS = rfpslwin.exe rfcslwin.exe
endif

# This little bit of trickers is intended to arrange that if you go
# just "make" it will build all the executables and copy them into the
# trunk/bin directory. This depends on the location within the Reduce
# tree that the sources for redfront live. This is also somewhere where I
# can strip the binaries of unnecessary symbol tables.

noinst_SCRIPTS = redfront.marker
redfront.marker:	$(progs)
if !DEBUG
	strip rfcsl$(EXEEXT)
	strip rfpsl$(EXEEXT)
#endif
	cp rfcsl$(EXEEXT) rfpsl$(EXEEXT) $(srcdir)/../../bin
if WINDOWS
if !debug
	i686-w64-mingw32-strip rfcslwin.exe
	i686-w64-mingw32-strip rfpslwin.exe
endif
#endif
# On Windows generally PATHEXT will pick up a ".com" file before a ".exe"
# one. However Cygwin sees ".exe" rather than ".com". So by giving the
# native windows versions a ".com" suffix it becomes possible to launch them
# as just "rfcsl" and "rfpsl". Note that for reduce itself there will be
# files "redcsl" (a cygwin/linux/etc shell script) and "redcsl.bat" and again
# native windows picks up the one that makes sense if the user just goes
# "redcsl".
	cp rfcsl$(EXEEXT) $(srcdir)/../../bin/rfcsl.com
	cp rfpsl$(EXEEXT) $(srcdir)/../../bin/rfpsl.com
endif

DATESTAMP = $(shell date +%d-%b-%Y)
CPPFLAGS += -DBUILDTIME="\"$(DATESTAMP)\""

rfcsl_SOURCES = redchild.c reddeb.c redfront.c redline.c \
	redparent.c redsig.c redstrings.c findself.c

rfpsl_SOURCES = redchild.c reddeb.c redfront.c redline.c \
	redparent.c redsig.c redstrings.c findself.c

rfcsl_CPPFLAGS = -DCSL=1 -I../include
rfpsl_CPPFLAGS = -DPSL=1 -I../include

rfcsl_LDADD = ../lib/libedit.a -lncurses
rfpsl_LDADD = ../lib/libedit.a -lncurses

rfcsl_DEPENDENCIES = ../lib/libedit.a
rfpsl_DEPENDENCIES = ../lib/libedit.a

# The next bunch are to get libedit built before attempts to build other
# things. It is in fact the header files installed by libedit that matter
# first.

rfcsl-redchild.$(OBJEXT):	../lib/libedit.a
rfcsl-reddeb.$(OBJEXT):		../lib/libedit.a
rfcsl-redfront.$(OBJEXT):	../lib/libedit.a
rfcsl-redline.$(OBJEXT):	../lib/libedit.a
rfcsl-redparent.$(OBJEXT):	../lib/libedit.a
rfcsl-redsig.$(OBJEXT):		../lib/libedit.a
rfcsl-redstrings.$(OBJEXT):	../lib/libedit.a
rfcsl-findself.$(OBJEXT):	../lib/libedit.a

rfpsl-redchild.$(OBJEXT):	../lib/libedit.a
rfpsl-reddeb.$(OBJEXT):		../lib/libedit.a
rfpsl-redfront.$(OBJEXT):	../lib/libedit.a
rfpsl-redline.$(OBJEXT):	../lib/libedit.a
rfpsl-redparent.$(OBJEXT):	../lib/libedit.a
rfpsl-redsig.$(OBJEXT):		../lib/libedit.a
rfpsl-redstrings.$(OBJEXT):	../lib/libedit.a
rfpsl-findself.$(OBJEXT):	../lib/libedit.a

../lib/libedit.a:
	cd ../libedit && $(MAKE) install

# The native Windows versions can have rigidly fixed build sequences since
# there is no flexibility in the way they should be built. I compile
# the wineditline in library right in along with the redfront stuff.

MOSTLYCLEANFILES = rfcslwin.exe rfpslwin.exe

rfcslwin.exe:	$(srcdir)/redchild.c $(srcdir)/reddeb.c $(srcdir)/redfront.c \
	$(srcdir)/redline.c $(srcdir)/redparent.c $(srcdir)/redsig.c \
	$(srcdir)/redstrings.c $(srcdir)/findself.c \
	../wineditline/src/editline.c ../wineditline/src/fn_complete.c \
	../wineditline/src/history.c
	i686-w64-mingw32-gcc $(CFLAGS) -DCSL=1 \
		-DBUILDTIME="\"$(DATESTAMP)\"" \
		$(srcdir)/redchild.c $(srcdir)/reddeb.c \
		$(srcdir)/redfront.c $(srcdir)/redline.c \
		$(srcdir)/redparent.c $(srcdir)/redsig.c \
		$(srcdir)/redstrings.c $(srcdir)/findself.c \
		-I ../wineditline/src ../wineditline/src/editline.c \
		../wineditline/src/fn_complete.c ../wineditline/src/history.c \
		-o rfcslwin.exe

rfpslwin.exe:	$(srcdir)/redchild.c $(srcdir)/reddeb.c $(srcdir)/redfront.c \
	$(srcdir)/redline.c $(srcdir)/redparent.c $(srcdir)/redsig.c \
	$(srcdir)/redstrings.c $(srcdir)/findself.c \
	../wineditline/src/editline.c ../wineditline/src/fn_complete.c \
	../wineditline/src/history.c
	i686-w64-mingw32-gcc $(CFLAGS) -DPSL=1 \
		-DBUILDTIME="\"$(DATESTAMP)\"" \
		$(srcdir)/redchild.c $(srcdir)/reddeb.c \
		$(srcdir)/redfront.c $(srcdir)/redline.c \
		$(srcdir)/redparent.c $(srcdir)/redsig.c \
		$(srcdir)/redstrings.c $(srcdir)/findself.c \
		-I ../wineditline/src ../wineditline/src/editline.c \
		../wineditline/src/fn_complete.c ../wineditline/src/history.c \
		-o rfpslwin.exe

if WINDOWS

plain_RFCSL = rfcsl
plain_RFPSL = rfpsl
plain_RFCSLWIN = rfcslwin
plain_RFPSLWIN = rfpslwin

.PHONY:	redfront.marker
.PHONY: $(plain_RFCSL)
.PHONY: $(plain_RFPSL)
.PHONY: $(plain_RFCSLWIN)
.PHONY:	$(plain_RFPSLWIN)

$(plain_RFCSL):	rfcsl.exe
	echo "make rfcsl.exe is perhaps clearer"

$(plain_RFPSL):	rfpsl.exe
	echo "make rfpsl.exe is perhaps clearer"

$(plain_RFCSLWIN):	rfcslwin.exe
	echo "make rfcslwin.exe is perhaps clearer"

$(plain_RFPSLWIN):	rfpslwin.exe
	echo "make rfpslwin.exe is perhaps clearer"

else
.PHONY:	redfront.marker
endif

# end of Makefile.am

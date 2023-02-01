# Makefile.am for redfront project

#    $Id$

ACLOCAL_AMFLAGS = -I m4

REDCSL="redcsl"
REDPSL="redpsl"
BOOTSTRAPREDUCE="bootstrapreduce"
BAT=".bat"

if NATIVEWIN

bin_PROGRAMS =
dist_bin_SCRIPTS = rfpslwin.exe rfcslwin.exe rfbootwin.exe
progs = rfpslwin.exe rfcslwin.exe rfbootwin.exe

else !NATIVEWIN

bin_PROGRAMS = rfpsl rfcsl rfboot

if WINDOWS
dist_bin_SCRIPTS = rfpslwin.exe rfcslwin.exe rfbootwin.exe
progs = rfpsl.exe rfcsl.exe rfboot.exe rfpslwin.exe rfcslwin.exe rfbootwin.exe
else
progs = rfpsl rfcsl rfboot
endif

endif !NATIVEWIN

# This little bit of trickery is intended to arrange that if you go
# just "make" it will build all the executables and copy them into the
# trunk/bin directory. This depends on the location within the Reduce
# tree that the sources for redfront live. This is also somewhere where I
# can strip the binaries of unnecessary symbol tables.

noinst_SCRIPTS = redfront.marker
redfront.marker:	$(progs)

if WINDOWS
if !NATIVEWIN
# These days I find that automake arranges that the actual executable that
# I want gets put in the .libs directory - this is (I believe) to do with
# libtool.
if !DEBUG
	$(STRIP) .libs/rfcsl$(EXEEXT)
	$(STRIP) .libs/rfboot$(EXEEXT)
	$(STRIP) .libs/rfpsl$(EXEEXT)
endif
	cp .libs/rfcsl$(EXEEXT) $(srcdir)/../../bin
	cp .libs/rfboot$(EXEEXT) $(srcdir)/../../bin
	cp .libs/rfpsl$(EXEEXT) $(srcdir)/../../bin
endif
else
if !DEBUG
	$(STRIP) rfcsl$(EXEEXT)
	$(STRIP) rfboot$(EXEEXT)
	$(STRIP) rfpsl$(EXEEXT)
endif
	cp rfcsl$(EXEEXT) $(srcdir)/../../bin
	cp rfboot$(EXEEXT) $(srcdir)/../../bin
	cp rfpsl$(EXEEXT) $(srcdir)/../../bin
endif

if WINDOWS
if !DEBUG
	i686-w64-mingw32-strip rfcslwin.exe
	i686-w64-mingw32-strip rfbootwin.exe
	i686-w64-mingw32-strip rfpslwin.exe
endif
# On Windows generally PATHEXT will pick up a ".com" file before a ".exe"
# one. However Cygwin sees ".exe" rather than ".com". So by giving the
# native windows versions a ".com" suffix it becomes possible to launch them
# as just "rfcsl" and "rfpsl". Note that for reduce itself there will be
# files "redcsl" (a cygwin/linux/etc shell script) and "redcsl.bat" and again
# native windows picks up the one that makes sense if the user just goes
# "redcsl".
	cp rfcslwin$(EXEEXT) $(srcdir)/../../bin/rfcsl.com
	cp rfbootwin$(EXEEXT) $(srcdir)/../../bin/rfboot.com
	cp rfpslwin$(EXEEXT) $(srcdir)/../../bin/rfpsl.com
endif

DATESTAMP = $(shell date +%d-%b-%Y)
CPPFLAGS += -DBUILDTIME="\"$(DATESTAMP)\""

rfcsl_SOURCES = redchild.c reddeb.c redfront.c redline.c \
	redparent.c redsig.c redstrings.c findself.c

rfboot_SOURCES = redchild.c reddeb.c redfront.c redline.c \
	redparent.c redsig.c redstrings.c findself.c

rfpsl_SOURCES = redchild.c reddeb.c redfront.c redline.c \
	redparent.c redsig.c redstrings.c findself.c

rfcsl_CPPFLAGS = -DCSL=1 -I../include
rfboot_CPPFLAGS = -DBOOT=1 -I../include
rfpsl_CPPFLAGS = -DPSL=1 -I../include

if LINUX
# What I have here is a horrid hack that carried maintenance pains for the
# future. It links in all the object files that go to make up libedit. This
# done because if I go via libedit.a in a sane way I seem to pick up a
# demand for a copy of libtinfo where Fedora and Ubuntu disagree about
# absence or presence of version numbers. Doing things this way lets me
# link in libtinfo statically (using "-l:") and perhaps avoids the misery.

L = ../libedit/src

LIBEDIT =	$(L)/chared.o $(L)/chartype.o $(L)/common.o $(L)/eln.o \
                $(L)/el.o $(L)/emacs.o $(L)/fcns.o $(L)/fgetln.o \
                $(L)/filecomplete.o $(L)/help.o $(L)/hist.o $(L)/historyn.o \
                $(L)/history.o $(L)/keymacro.o $(L)/map.o $(L)/parse.o \
                $(L)/prompt.o $(L)/readline.o $(L)/read.o $(L)/refresh.o \
                $(L)/search.o $(L)/sig.o $(L)/strlcat.o $(L)/strlcpy.o \
                $(L)/terminal.o $(L)/tokenizern.o $(L)/tokenizer.o $(L)/tty.o \
                $(L)/unvis.o $(L)/vi.o $(L)/vis.o $(L)/wcsdup.o

rfcsl_LDADD = -l:libtinfo.a $(LIBEDIT) -lncurses
rfboot_LDADD = -l:libtinfo.a $(LIBEDIT) -lncurses
rfpsl_LDADD = -l:libtinfo.a $(LIBEDIT) -lncurses
else !LINUX
rfcsl_LDADD = ../lib/libedit.a -lncurses
rfboot_LDADD = ../lib/libedit.a -lncurses
rfpsl_LDADD = ../lib/libedit.a -lncurses
endif !LINUX

rfcsl_DEPENDENCIES = ../lib/libedit.a
rfboot_DEPENDENCIES = ../lib/libedit.a
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

rfboot-redchild.$(OBJEXT):	../lib/libedit.a
rfboot-reddeb.$(OBJEXT):		../lib/libedit.a
rfboot-redfront.$(OBJEXT):	../lib/libedit.a
rfboot-redline.$(OBJEXT):	../lib/libedit.a
rfboot-redparent.$(OBJEXT):	../lib/libedit.a
rfboot-redsig.$(OBJEXT):		../lib/libedit.a
rfboot-redstrings.$(OBJEXT):	../lib/libedit.a
rfboot-findself.$(OBJEXT):	../lib/libedit.a

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

MOSTLYCLEANFILES = rfcslwin.exe rfbootwin.exe rfpslwin.exe

rfcslwin.exe:	$(srcdir)/redchild.c $(srcdir)/reddeb.c $(srcdir)/redfront.c \
	$(srcdir)/redlinewin.c $(srcdir)/redparent.c $(srcdir)/redsig.c \
	$(srcdir)/redstrings.c $(srcdir)/findself.c \
	../wineditline/src/editline.c ../wineditline/src/fn_complete.c \
	../wineditline/src/history.c
	i686-w64-mingw32-gcc $(CFLAGS) -DCSL=1 \
		-DREDCSL=\"$(REDCSL)\" -DREDPSL=\"$(REDPSL)\" \
		-DBOOTSTRAPREDUCE=\"$(BOOTSTRAPREDUCE)\" -DBAT=\"$(BAT)\" \
		-DBUILDTIME="\"$(DATESTAMP)\"" \
		-DHAVE_HISTORY=1 -DLITHIST=1 \
		-DIGNOREDUPS=1 -DHISTFILESIZE=10000 \
		$(srcdir)/redchild.c $(srcdir)/reddeb.c \
		$(srcdir)/redfront.c $(srcdir)/redlinewin.c \
		$(srcdir)/redparent.c $(srcdir)/redsig.c \
		$(srcdir)/redstrings.c $(srcdir)/findself.c \
		-I ../wineditline/src ../wineditline/src/editline.c \
		../wineditline/src/fn_complete.c ../wineditline/src/history.c \
		-o rfcslwin.exe

rfbootwin.exe:	$(srcdir)/redchild.c $(srcdir)/reddeb.c $(srcdir)/redfront.c \
	$(srcdir)/redlinewin.c $(srcdir)/redparent.c $(srcdir)/redsig.c \
	$(srcdir)/redstrings.c $(srcdir)/findself.c \
	../wineditline/src/editline.c ../wineditline/src/fn_complete.c \
	../wineditline/src/history.c
	i686-w64-mingw32-gcc $(CFLAGS) -DBOOT=1 \
		-DREDCSL=\"$(REDCSL)\" -DREDPSL=\"$(REDPSL)\" \
		-DBOOTSTRAPREDUCE=\"$(BOOTSTRAPREDUCE)\" -DBAT=\"$(BAT)\" \
		-DBUILDTIME="\"$(DATESTAMP)\"" \
		-DHAVE_HISTORY=1 -DLITHIST=1 \
		-DIGNOREDUPS=1 -DHISTFILESIZE=10000 \
		$(srcdir)/redchild.c $(srcdir)/reddeb.c \
		$(srcdir)/redfront.c $(srcdir)/redlinewin.c \
		$(srcdir)/redparent.c $(srcdir)/redsig.c \
		$(srcdir)/redstrings.c $(srcdir)/findself.c \
		-I ../wineditline/src ../wineditline/src/editline.c \
		../wineditline/src/fn_complete.c ../wineditline/src/history.c \
		-o rfbootwin.exe

rfpslwin.exe:	$(srcdir)/redchild.c $(srcdir)/reddeb.c $(srcdir)/redfront.c \
	$(srcdir)/redlinewin.c $(srcdir)/redparent.c $(srcdir)/redsig.c \
	$(srcdir)/redstrings.c $(srcdir)/findself.c \
	../wineditline/src/editline.c ../wineditline/src/fn_complete.c \
	../wineditline/src/history.c
	i686-w64-mingw32-gcc $(CFLAGS) -DPSL=1 \
		-DREDCSL=\"$(REDCSL)\" -DREDPSL=\"$(REDPSL)\" \
		-DBOOTSTRAPREDUCE=\"$(BOOTSTRAPREDUCE)\" -DBAT=\"$(BAT)\" \
		-DBUILDTIME="\"$(DATESTAMP)\"" \
		-DHAVE_HISTORY=1 -DLITHIST=1 \
		-DIGNOREDUPS=1 -DHISTFILESIZE=10000 \
		$(srcdir)/redchild.c $(srcdir)/reddeb.c \
		$(srcdir)/redfront.c $(srcdir)/redlinewin.c \
		$(srcdir)/redparent.c $(srcdir)/redsig.c \
		$(srcdir)/redstrings.c $(srcdir)/findself.c \
		-I ../wineditline/src ../wineditline/src/editline.c \
		../wineditline/src/fn_complete.c ../wineditline/src/history.c \
		-o rfpslwin.exe

if WINDOWS

plain_RFCSL = rfcsl
plain_RFBOOT = rfboot
plain_RFPSL = rfpsl
plain_RFCSLWIN = rfcslwin
plain_RFBOOTWIN = rfbootwin
plain_RFPSLWIN = rfpslwin

.PHONY:	redfront.marker
.PHONY: $(plain_RFCSL)
.PHONY: $(plain_RFBOOT)
.PHONY: $(plain_RFPSL)
.PHONY: $(plain_RFCSLWIN)
.PHONY: $(plain_RFBOOTWIN)
.PHONY:	$(plain_RFPSLWIN)

$(plain_RFCSL):	rfcsl.exe
	echo "make rfcsl.exe is perhaps clearer"

$(plain_RFBOOT):	rfboot.exe
	echo "make rfboot.exe is perhaps clearer"

$(plain_RFPSL):	rfpsl.exe
	echo "make rfpsl.exe is perhaps clearer"

$(plain_RFCSLWIN):	rfcslwin.exe
	echo "make rfcslwin.exe is perhaps clearer"

$(plain_RFBOOTWIN):	rfbootwin.exe
	echo "make rfbootwin.exe is perhaps clearer"

$(plain_RFPSLWIN):	rfpslwin.exe
	echo "make rfpslwin.exe is perhaps clearer"

else
.PHONY:	redfront.marker
endif

# end of Makefile.am

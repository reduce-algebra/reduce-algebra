# Makefile.am for redfront project

# $Id:

bin_PROGRAMS = rfpsl rfcsl

if WINDOWS
dist_bin_SCRIPTS = rfpslwin.exe rfcslwin.exe
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

../lib/libedit.a:
	cd ../libedit && $(MAKE) install

# The native Windows versions can have rigidly fixed build sequences since
# there is no flexibility in the way they should be built. I compile
# the wineditline in library right in along with the redfront stuff.

rfcslwin.exe:	$(srcdir)/redchild.c $(srcdir)/reddeb.c $(srcdir)/redfront.c \
	$(srcdir)/redline.c $(srcdir)/redparent.c $(srcdir)/redsig.c \
	$(srcdir)/redstrings.c $(srcdir)/findself.c \
	../wineditline/src/editline.c ../wineditline/src/fn_complete.c \
	../wineditline/src/history.c
	i686-w64-mingw32-gcc $(CFLAGS) -DCSL=1 -DBUILD_TIME="$(DATESTAMP)" \
		$(srcdir)/redchild.c $(srcdir)/reddeb.c \
		$(srcdir)/redfront.c $(srcdir)/redline.c \
		$(srcdir)/redparent.c $(srcdir)/redsig.c \
		$(srcdir)/redstrings.c $(srcdir)/findself.c \
		-I ../wineditline/src ../wineditline/src/editline.c \
		../wineditline/src/fn_complete.c ../wineditline/src/history.c \
		-o rfcslwin.exe
if !DEBUG
	i686-w64-mingw32-strip rfcslwin.exe
endif

rfpslwin.exe:	$(srcdir)/redchild.c $(srcdir)/reddeb.c $(srcdir)/redfront.c \
	$(srcdir)/redline.c $(srcdir)/redparent.c $(srcdir)/redsig.c \
	$(srcdir)/redstrings.c $(srcdir)/findself.c \
	../wineditline/src/editline.c ../wineditline/src/fn_complete.c \
	../wineditline/src/history.c
	i686-w64-mingw32-gcc $(CFLAGS) -DPSL=1 -DBUILD_TIME="$(DATESTAMP)" \
		$(srcdir)/redchild.c $(srcdir)/reddeb.c \
		$(srcdir)/redfront.c $(srcdir)/redline.c \
		$(srcdir)/redparent.c $(srcdir)/redsig.c \
		$(srcdir)/redstrings.c $(srcdir)/findself.c \
		-I ../wineditline/src ../wineditline/src/editline.c \
		../wineditline/src/fn_complete.c ../wineditline/src/history.c \
		-o rfpslwin.exe
if !DEBUG
	i686-w64-mingw32-strip rfpslwin.exe
endif

if WINDOWS

plain_RFCSL = rfcsl
plain_RFPSL = rfpsl
plain_RFCSLWIN = rfcslwin
plain_RFPSLWIN = rfpslwin

.PHONY: $(plain_RFCSL)
.PHONY: $(plain_RFPSL)
.PHONY: $(plain_RFCSLWIN)
.PHONY: $(plain_RFPSLWIN)

$(plain_RFCSL):	rfcsl.exe
	echo "make rfcsl.exe is perhaps clearer"

$(plain_RFPSL):	rfpsl.exe
	echo "make rfpsl.exe is perhaps clearer"

$(plain_RFCSLWIN):	rfcslwin.exe
	echo "make rfcslwin.exe is perhaps clearer"

$(plain_RFPSLWIN):	rfpslwin.exe
	echo "make rfpslwin.exe is perhaps clearer"

endif

# end of Makefile.am

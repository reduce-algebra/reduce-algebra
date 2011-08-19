## process this file with automake to create Makefile.in
## and then use autoconf to create ./configure. Finally run that
## to build your usable Makefile (probably in another directory)

# CSL and REDUCE build sequences

CP = cp
RM = rm

if cygpath
# Note that "cygpath -m" converts to a Windows-style path except that
# if leaves "/" not "\" in the name. This latter fact matters because
# of shell quoting issues. The fomer can be vital when non-cygwin
# applications might otherwise receive a file-name starting "/cygdrive/x/.."
# and not understand it.
CYGSRC = $(shell cygpath -m $(srcdir))
else !cygpath
CYGSRC = $(srcdir)
endif !cygpath

if cygwin
EXE=
else !cygwin
EXE=$(EXEEXT)
endif !cygwin

if wx
if wxbuiltin
WXC=../bin/wx-config
CPPFLAGS += $(shell ../bin/wx-config --cppflags 2>/dev/null)
CFLAGS   += $(shell ../bin/wx-config --cflags 2>/dev/null)
CXXFLAGS += $(shell ../bin/wx-config --cxxflags 2>/dev/null)
LIBS     += $(shell ../bin/wx-config --libs 2>/dev/null)
else !wxbuiltin
WXC=
CPPFLAGS += $(shell wx-config --cppflags)
CFLAGS   += $(shell wx-config --cflags)
CXXFLAGS += $(shell wx-config --cxxflags)
LIBS     += $(shell wx-config --libs)
endif !wxbuiltin
else !wx
WXC=
endif !wx

# I wish to know where this build intends to install things...
CPPFLAGS += -DBINDIR=$(bindir) -DPKGDATADIR=$(pkgdatadir)

# On Windows if I have a GUI (wither based on Fox or wxWidgets) I will want
# the main version of my code to be an .exe file but I will also want a
# .com version to be a console application. If I only have command-line
# versions it is easiest to make everything .exe
if windows
if gui
COM=.com
else !gui
COM=.exe
endif !gui
else !windows
COM=
endif !windows

if fox
foxdemotarget = foxdemo$(EXEEXT) fontdemo$(EXEEXT) showmathdemo$(EXEEXT)
else !fox
foxdemotarget =
endif !fox

if wx
wxdemotarget = wxdemo$(EXEEXT) wxfontdemo$(EXEEXT) wxdvi$(EXEEXT) wxshowmathdemo$(EXEEXT)
else !wx
wxdemotarget =
endif !wx

if wx
bin_PROGRAMS = csl$(EXEEXT) reduce$(EXEEXT) wxpsl$(EXEEXT)
else !wx
bin_PROGRAMS = csl$(EXEEXT) reduce$(EXEEXT)
endif !wx
noinst_PROGRAMS = bootstrapreduce$(EXEEXT) fwindemo$(EXEEXT) \
	termdemo$(EXEEXT) $(foxdemotarget) dyndemo$(EXEEXT) \
	$(wxdemotarget)

if mac_framework
all-local:	make-clickable csl.img reduce.img
else !mac_framework
if cygwin
all-local:	report-dlls csl.img reduce.img
else !cygwin
all-local:	csl.img reduce.img
endif !cygwin
endif !mac_framework


core_sources = arith01.c arith02.c arith03.c arith04.c arith05.c \
		arith06.c arith07.c arith08.c arith09.c arith10.c arith11.c \
		arith12.c char.c cslmpi.c eval1.c eval2.c \
		eval3.c eval4.c fns1.c fns2.c fns3.c \
		print.c cslread.c restart.c sysfwin.c

demo_sources = csl.c fasl.c gc.c preserve.c

undemo_sources = csl.c fasl.c gc.c preserve.c

# If I am building under FOX then the main parts of material from
# fwin.c and termed.c get picked up from the FOX library.
# If wxWidgets is in use I have an alternate versions called wxfwin.c 
# but termed.c can be used unchanged (but from source in this directory
# not in the FOX directory). When I do not have a GUI at all I use both
# fwin.c and termed.c from this directory.

if fox
fwin_sources =
else !fox
if wx
fwin_sources = wxfwin.c wxterminal.cpp termed.c
else !wx
fwin_sources = fwin.c termed.c
endif !wx
endif !fox

if x86
# A BSD-licensed disassembler for x86 and x86_64
distormsrc = x86defs.c wstring.c textdefs.c prefix.c operands.c \
		insts.c instructions.c distorm.c decoder.c
else !x86
distormstrc =
endif !x86

if jit
# the JIT is EXPERIMENTAL and not all working yet. It only pretends
# to be available for the x86 (32-bit) platform. Mention of it is
# present here to support the development activity.
jit_sources = jit1.c jit2.c jit3.c jitx86.c $(distormsrc)
else !jit
jit_sources =
endif !jit

gensrc=$(srcdir)/../../cslbuild/generated-c

generated_sources =             $(gensrc)/u01.c \
		$(gensrc)/u02.c $(gensrc)/u03.c \
		$(gensrc)/u04.c $(gensrc)/u05.c \
		$(gensrc)/u06.c $(gensrc)/u07.c \
		$(gensrc)/u08.c $(gensrc)/u09.c \
		$(gensrc)/u10.c $(gensrc)/u11.c \
		$(gensrc)/u12.c $(gensrc)/u13.c \
		$(gensrc)/u14.c $(gensrc)/u15.c \
		$(gensrc)/u16.c $(gensrc)/u17.c \
		$(gensrc)/u18.c $(gensrc)/u19.c \
		$(gensrc)/u20.c $(gensrc)/u21.c \
		$(gensrc)/u22.c $(gensrc)/u23.c \
		$(gensrc)/u24.c $(gensrc)/u25.c \
		$(gensrc)/u26.c $(gensrc)/u27.c \
		$(gensrc)/u28.c $(gensrc)/u29.c \
		$(gensrc)/u30.c $(gensrc)/u31.c \
		$(gensrc)/u32.c $(gensrc)/u33.c \
		$(gensrc)/u34.c $(gensrc)/u35.c \
		$(gensrc)/u36.c $(gensrc)/u37.c \
		$(gensrc)/u38.c $(gensrc)/u39.c \
		$(gensrc)/u40.c $(gensrc)/u41.c \
		$(gensrc)/u42.c $(gensrc)/u43.c \
		$(gensrc)/u44.c $(gensrc)/u45.c \
		$(gensrc)/u46.c $(gensrc)/u47.c \
		$(gensrc)/u48.c $(gensrc)/u49.c \
		$(gensrc)/u50.c $(gensrc)/u51.c \
		$(gensrc)/u52.c $(gensrc)/u53.c \
		$(gensrc)/u54.c $(gensrc)/u55.c \
		$(gensrc)/u56.c $(gensrc)/u57.c \
		$(gensrc)/u58.c $(gensrc)/u59.c \
		$(gensrc)/u60.c
generated_objects =           u01.$(OBJEXT) \
		u02.$(OBJEXT) u03.$(OBJEXT) \
		u04.$(OBJEXT) u05.$(OBJEXT) \
		u06.$(OBJEXT) u07.$(OBJEXT) \
		u08.$(OBJEXT) u09.$(OBJEXT) \
		u10.$(OBJEXT) u11.$(OBJEXT) \
		u12.$(OBJEXT) u13.$(OBJEXT) \
		u14.$(OBJEXT) u15.$(OBJEXT) \
		u16.$(OBJEXT) u17.$(OBJEXT) \
		u18.$(OBJEXT) u19.$(OBJEXT) \
		u20.$(OBJEXT) u21.$(OBJEXT) \
		u22.$(OBJEXT) u23.$(OBJEXT) \
		u24.$(OBJEXT) u25.$(OBJEXT) \
		u26.$(OBJEXT) u27.$(OBJEXT) \
		u28.$(OBJEXT) u29.$(OBJEXT) \
		u30.$(OBJEXT) u31.$(OBJEXT) \
		u32.$(OBJEXT) u33.$(OBJEXT) \
		u34.$(OBJEXT) u35.$(OBJEXT) \
		u36.$(OBJEXT) u37.$(OBJEXT) \
		u38.$(OBJEXT) u39.$(OBJEXT) \
		u40.$(OBJEXT) u41.$(OBJEXT) \
		u42.$(OBJEXT) u43.$(OBJEXT) \
		u44.$(OBJEXT) u45.$(OBJEXT) \
		u46.$(OBJEXT) u47.$(OBJEXT) \
		u48.$(OBJEXT) u49.$(OBJEXT) \
		u50.$(OBJEXT) u51.$(OBJEXT) \
		u52.$(OBJEXT) u53.$(OBJEXT) \
		u54.$(OBJEXT) u55.$(OBJEXT) \
		u56.$(OBJEXT) u57.$(OBJEXT) \
		u58.$(OBJEXT) u59.$(OBJEXT) \
		u60.$(OBJEXT)
generated_lisp =                  $(gensrc)/u01.lsp \
		$(gensrc)/u02.lsp $(gensrc)/u03.lsp \
		$(gensrc)/u04.lsp $(gensrc)/u05.lsp \
		$(gensrc)/u06.lsp $(gensrc)/u07.lsp \
		$(gensrc)/u08.lsp $(gensrc)/u09.lsp \
		$(gensrc)/u10.lsp $(gensrc)/u11.lsp \
		$(gensrc)/u12.lsp $(gensrc)/u13.lsp \
		$(gensrc)/u14.lsp $(gensrc)/u15.lsp \
		$(gensrc)/u16.lsp $(gensrc)/u17.lsp \
		$(gensrc)/u18.lsp $(gensrc)/u19.lsp \
		$(gensrc)/u20.lsp $(gensrc)/u21.lsp \
		$(gensrc)/u22.lsp $(gensrc)/u23.lsp \
		$(gensrc)/u24.lsp $(gensrc)/u25.lsp \
		$(gensrc)/u26.lsp $(gensrc)/u27.lsp \
		$(gensrc)/u28.lsp $(gensrc)/u29.lsp \
		$(gensrc)/u30.lsp $(gensrc)/u31.lsp \
		$(gensrc)/u32.lsp $(gensrc)/u33.lsp \
		$(gensrc)/u34.lsp $(gensrc)/u35.lsp \
		$(gensrc)/u36.lsp $(gensrc)/u37.lsp \
		$(gensrc)/u38.lsp $(gensrc)/u39.lsp \
		$(gensrc)/u40.lsp $(gensrc)/u41.lsp \
		$(gensrc)/u42.lsp $(gensrc)/u43.lsp \
		$(gensrc)/u44.lsp $(gensrc)/u45.lsp \
		$(gensrc)/u46.lsp $(gensrc)/u47.lsp \
		$(gensrc)/u48.lsp $(gensrc)/u49.lsp \
		$(gensrc)/u50.lsp $(gensrc)/u51.lsp \
		$(gensrc)/u52.lsp $(gensrc)/u53.lsp \
		$(gensrc)/u54.lsp $(gensrc)/u55.lsp \
		$(gensrc)/u56.lsp $(gensrc)/u57.lsp \
		$(gensrc)/u58.lsp $(gensrc)/u59.lsp \
		$(gensrc)/u60.lsp

csl_SOURCES = $(core_sources) $(undemo_sources) $(fwin_sources) \
		$(jit_sources) bytes.c stubs.c

bootstrapreduce_SOURCES = $(core_sources) $(undemo_sources) $(fwin_sources) \
		$(jit_sources) bytes1.c stubs.c

reduce_SOURCES = $(core_sources) $(demo_sources) $(fwin_sources) \
		$(jit_sources) bytes.c $(generated_sources)

if windows
fwin_icon = fwin-icon.$(OBJEXT)
else !windows
fwin_icon =
endif !windows

if wx
fontsdir = wxfonts
samplefont=cmuntt.otf
else !wx
fontsdir = fonts
samplefont=cmr10.pfb
endif !wx

if mac_framework
if wx
# On the Mac local fonts get put into the Application Bundle not into
# a directory here
FONTDEP=
else !wx
# On the Mac with FOX I need a fonts directory in the old way
FONTDEP=reduce.$(fontsdir)/$(samplefont)
endif !wx
else !mac_framework
# For X11 and Windows I need a fonts directory
FONTDEP=reduce.$(fontsdir)/$(samplefont)
endif !mac_framework

AM_CPPFLAGS = -Dfontsdir=reduce.$(fontsdir)

foxdemo_SOURCES = foxdemo.cpp
foxdemo_CPPFLAGS = $(FOX_INCLUDES)
foxdemo_LDADD = $(fwin_icon) $(FOX_LIBS)
foxdemo_DEPENDENCIES = $(fwin_icon) 

fontdemo_SOURCES = fontdemo.cpp
fontdemo_CPPFLAGS = $(FOX_INCLUDES)
fontdemo_LDADD = $(fwin_icon) $(FOX_LIBS)
fontdemo_DEPENDENCIES = $(fwin_icon) $(FONTDEP)

showmathdemo_SOURCES = showmathdemo.cpp
showmathdemo_CPPFLAGS = $(FOX_INCLUDES)
showmathdemo_LDADD = $(fwin_icon) $(FOX_LIBS)
showmathdemo_DEPENDENCIES = $(fwin_icon) $(FONTDEP)

wxdemo_SOURCES = wxdemo.cpp
wxdemo_LDADD = $(fwin_icon)
wxdemo_DEPENDENCIES = $(fwin_icon) $(FONTDEP) $(WXC)

wxfontdemo_SOURCES = wxfontdemo.cpp
wxfontdemo_LDADD = $(fwin_icon)
wxfontdemo_DEPENDENCIES = $(fwin_icon) $(FONTDEP) $(WXC)

wxdvi_SOURCES = wxdvi.cpp
wxdvi_LDADD = $(fwin_icon)
wxdvi_DEPENDENCIES = $(fwin_icon) $(FONTDEP) $(WXC)

wxshowmathdemo_SOURCES = wxshowmathdemo.cpp
wxshowmathdemo_LDADD = $(fwin_icon)
wxshowmathdemo_DEPENDENCIES = $(fwin_icon) $(FONTDEP) $(WXC)


if windows
DLLEXT=dll
else !windows
DLLEXT=so
endif !windows

dyndemo_SOURCES = dyndemo.c

if !windows
dyndemo_DEPENDENCIES = dynmodule.so
endif !windows

if windows

# Even on Windows I will try to use commands "cp" and "rm", and in general
# I will expect the user to have established a path which includes the
# cygwin tools and hence utilities by these names. This unpleasant issue
# is because I will end up using file-paths with "/" in not "\", and
# the Microsoft "copy" and "del" commands get unhppy then. So this issue
# is one that goes along with using GNU make even in a Microsoft world, and
# if "make" is on ones path then "rm" and "cp" can be too without too much
# pain!
#

local-bootstrapreduceexe.def:	$(srcdir)/bootstrapreduceexe.def $(srcdir)/impex.def
	cat $(srcdir)/bootstrapreduceexe.def $(srcdir)/impex.def > local-bootstrapreduceexe.def

local-reduceexe.def:	$(srcdir)/reduceexe.def $(srcdir)/impex.def
	cat $(srcdir)/reduceexe.def $(srcdir)/impex.def > local-reduceexe.def

local-reducecom.def:	$(srcdir)/reducecom.def $(srcdir)/impex.def
	cat $(srcdir)/reducecom.def $(srcdir)/impex.def > local-reducecom.def

local-cslexe.def:	$(srcdir)/cslexe.def $(srcdir)/impex.def
	cat $(srcdir)/cslexe.def $(srcdir)/impex.def > local-cslexe.def

local-cslcom.def:	$(srcdir)/cslcom.def $(srcdir)/impex.def
	cat $(srcdir)/cslcom.def $(srcdir)/impex.def > local-cslcom.def

CSLEXEDEF = local-cslexe.def
CSLCOMDEF = local-cslcom.def
BOOTSTRAPREDUCEEXEDEF = local-bootstrapreduceexe.def
REDUCEEXEDEF = local-reduceexe.def
REDUCECOMDEF = local-reducecom.def

# For a build on Windows with a GUI I want to add an icon into each binary,
# via a resource-file. I also want linking to be in "windows-subsystem-mode",
# but I also want matching ".com" files to be created to be console
# mode versions.

CONAP=-Wl,--subsystem,console
if gui
WINAP=-Wl,--subsystem,windows
else !gui
WINAP=-Wl,--subsystem,console
endif !gui

GP=wgnuplot.exe

dyndemo_LDADD = $(srcdir)/dyndemo.def

reduceres = fwin-reduce.$(OBJEXT)

fwindemo_LDADD = $(fwin_icon) $(FOX_LIBS)
csl_LDADD = fwin-csl.$(OBJEXT) $(FOX_LIBS)
bootstrapreduce_LDADD = fwin-csl.$(OBJEXT) $(FOX_LIBS)
reduce_LDADD = $(reduceres) $(FOX_LIBS)

csl_DEPENDENCIES = local-cslexe.def local-cslcom.def fwin-csl.$(OBJEXT) \
		$(FONTDEP) $(WXC)
bootstrapreduce_DEPENDENCIES = local-bootstrapreduceexe.def \
		fwin-csl.$(OBJEXT) $(FONTDEP) \
		reduce.doc/index.html $(GP) $(WXC)
reduce_DEPENDENCIES = local-reduceexe.def local-reducecom.def $(reduceres) \
		$(FONTDEP) reduce.doc/index.html $(GP) $(WXC)
if wx
fwindemo_DEPENDENCIES = $(fwin_icon) $(FONTDEP) $(WXC)
wxpsl_DEPENDENCIES = $(fwin_icon) $(FONTDEP) $(WXC)
else !wx
fwindemo_DEPENDENCIES = $(fwin_icon)
endif !wx
dyndemo_DEPENDENCIES = $(srcdir)/dyndemo.def dynmodule.dll

fwin-icon.$(OBJEXT):	$(srcdir)/fwin-icon.rc
	$(WINDRES) $(srcdir)/fwin-icon.rc --include-dir=$(srcdir) \
		-o fwin-icon.$(OBJEXT)

fwin-csl.$(OBJEXT):	$(srcdir)/fwin-csl.rc
	$(WINDRES) $(srcdir)/fwin-csl.rc --include-dir=$(srcdir) \
		-o fwin-csl.$(OBJEXT)

fwin-reduce.$(OBJEXT):	$(srcdir)/fwin-reduce.rc
	$(WINDRES) $(srcdir)/fwin-reduce.rc --include-dir=$(srcdir) \
		-o fwin-reduce.$(OBJEXT)

else !windows
CONAP=
WINAP=

CSLEXEDEF =
CSLCOMDEF =
BOOTSTRAPREDUCEEXEDEF =
BOOTSTRAPREDUCECOMDEF =
REDUCEEXEDEF =
REDUCECOMDEF =

GP=

fwindemo_LDADD = $(FOX_LIBS)
csl_LDADD = $(FOX_LIBS)
bootstrapreduce_LDADD = $(FOX_LIBS)
reduce_LDADD = $(FOX_LIBS)

csl_DEPENDENCIES = $(FONTDEP) $(WXC)
bootstrapreduce_DEPENDENCIES = $(FONTDEP) \
		reduce.doc/index.html $(GP) $(WXC)
reduce_DEPENDENCIES = $(FONTDEP) reduce.doc/index.html \
		$(GP) $(WXC)
if wx
fwindemo_DEPENDENCIES = $(fwin_icon) $(FONTDEP) $(WXC)
wxpsl_DEPENDENCIES = $(fwin_icon) $(FONTDEP) $(WXC)
else !wx
fwindemo_DEPENDENCIES = $(fwin_icon)
endif !wx

# end of windows vs non-windows conditions
endif !windows

# The next line is because CXXLINK has "-o $@" as part of it and in this
# case I want to have separate control of the destination of the executable
# that I create. In doing it this way I ASSUME (and in general this can not
# be guaranteed) that the expression "-o destination" will be what works.

CXXLINKTO = $(CXXLD) $(AM_CXXFLAGS) $(CXXFLAGS) $(AM_LDFLAGS) $(LDFLAGS)

# BEWARE BEWARE BEWARE the next line must have trailing blanks
DEST=-o   

if fox
if win64
#FOXDEPS=../lib/libFOX-1.6.lib
FOXDEPS=../lib/libFOX-1.6.a
else !win64
FOXDEPS=../lib/libFOX-1.6.a
endif !win64
else !fox
FOXDEPS=
endif !fox

# The next rule will only trigger if fxver.h is not present at all.

$(FOXDEPS):
	@cd ../fox && $(MAKE) install

# If one of the major foundations of this Makefile have a date later than that
# on fxver.h then make does a futile recursion to try to fix it and in the
# process it can do a LOT of work that I do not want done. I can at least
# arrange that that happens at most once by putting the following rules:

$(srcdir)/configure.ac:
	touch $(srcdir)/configure.ac

$(srcdir)/Makefile.am:
	touch $(srcdir)/Makefile.am

if wx

if wxbuiltin
BASELIB=../lib/libwx_baseu-2.9.a
WXDEPS=../bin/wx-config $(BASELIB)

# When I build wxWidgets locally I *ALWAYS* end up passing an explicit
# "--host=..." option to the configure script. A result of that is that
# the libraries get installed with names that include the host identity.
# The script here makes symbolic links from the host-qualified names from
# plain undecorated ones as mentioned by "wx-config --libs"

$(BASELIB):	../lib/libwx_baseu-2.9-$(HOST).a
	cd ../lib; \
	for x in *$(HOST).a; \
	do \
	  y=$${x%-$(HOST).a}.a; \
	  echo ln -s -f $$x $$y; \
	  ln -s -f $$x $$y; \
	done

../lib/libwx_baseu-2.9-$(HOST).a ../bin/wx-config:
	@cd ../wxWidgets && $(MAKE) install

else !wxbuiltin
WXDEPS=
endif !wxbuiltin

wxfontdemo$(EXEEXT): $(wxfontdemo_OBJECTS) $(wxfontdemo_DEPENDENCIES) $(WXDEPS)
	-rm -f wxfontdemo$(EXEEXT)
	$(CXXLINKTO) $(DEST)wxfontdemo$(EXEEXT) $(wxfontdemo_OBJECTS) $(wxfontdemo_LDADD) $(LIBS) $(CONAP)
if !debug
if !darwin
	$(STRIP) wxfontdemo$(EXEEXT)
endif !darwin
endif !debug
if mac_framework
	$(srcdir)/create_bundle.sh wxfontdemo $(srcdir)
endif mac_framework

wxdvi$(EXEEXT): $(wxdvi_OBJECTS) $(wxdvi_DEPENDENCIES) $(WXDEPS)
	-rm -f wxdvi$(EXEEXT)
	$(CXXLINKTO) $(DEST)wxdvi$(EXEEXT) $(wxdvi_OBJECTS) $(wxdvi_LDADD) $(LIBS) $(CONAP)
if !debug
if !darwin
	$(STRIP) wxdvi$(EXEEXT)
endif !darwin
endif !debug
if mac_framework
	$(srcdir)/create_bundle.sh wxdvi $(srcdir)
endif mac_framework

wxdemo$(EXEEXT): $(wxdemo_OBJECTS) $(wxdemo_DEPENDENCIES) $(WXDEPS)
	-rm -f wxdemo$(EXEEXT)
	$(CXXLINKTO) $(DEST)wxdemo$(EXEEXT) $(wxdemo_OBJECTS) $(wxdemo_LDADD) $(LIBS) $(CONAP)
if !debug
if !darwin
	$(STRIP) wxdemo$(EXEEXT)
endif !darwin
endif !debug
if mac_framework
	$(srcdir)/create_bundle.sh wxdemo $(srcdir)
endif mac_framework

wxshowmathdemo$(EXEEXT): $(wxshowmathdemo_OBJECTS) $(wxshowmathdemo_DEPENDENCIES) $(WXDEPS)
	-rm -f wxshowmathdemo$(EXEEXT)
	$(CXXLINKTO) $(DEST)wxshowmathdemo$(EXEEXT) $(wxshowmathdemo_OBJECTS) $(wxshowmathdemo_LDADD) $(LIBS) $(CONAP)
if !debug
if !darwin
	$(STRIP) wxshowmathdemo$(EXEEXT)
endif !darwin
endif !debug
if mac_framework
	$(srcdir)/create_bundle.sh wxshowmathdemo $(srcdir)
endif mac_framework

else !wx
WXDEPS=
endif !wx

csl$(EXEEXT): $(csl_OBJECTS) $(csl_DEPENDENCIES) $(FOXDEPS) $(WXDEPS)
	-rm -f csl$(EXEEXT)
	$(CXXLINKTO) $(CSLEXEDEF) $(DEST)csl$(EXEEXT) $(csl_OBJECTS) $(csl_LDADD) $(LIBS) $(WINAP)
if windows
if gui
	-rm -f csl$(COM)
	$(CXXLINKTO) $(CSLCOMDEF) $(DEST)csl$(COM) $(csl_OBJECTS) $(csl_LDADD) $(LIBS) $(CONAP)
endif gui
endif windows
if !debug
if !darwin
	$(STRIP) csl$(EXEEXT)
if windows
if gui
	$(STRIP) csl$(COM)
endif gui
endif windows
endif !darwin
endif !debug
if wx
if mac_framework
	$(srcdir)/create_bundle.sh csl $(srcdir) csl
endif mac_framework
endif wx

reduce$(EXEEXT): $(reduce_OBJECTS) $(reduce_DEPENDENCIES) $(FOXDEPS) $(WXDEPS)
	-rm -f reduce$(EXEEXT)
	$(CXXLINKTO) $(REDUCEEXEDEF) $(DEST)reduce$(EXEEXT) $(reduce_OBJECTS) $(reduce_LDADD) $(LIBS) $(WINAP)
if windows
if gui
	-rm -f reduce$(COM)
	$(CXXLINKTO) $(REDUCECOMDEF) $(DEST)reduce$(COM) $(reduce_OBJECTS) $(reduce_LDADD) $(LIBS) $(CONAP)
endif gui
endif windows
if !debug
if !darwin
	$(STRIP) reduce$(EXEEXT)
if windows
if gui
	$(STRIP) reduce$(COM)
endif gui
endif windows
endif !darwin
endif !debug
if wx
if mac_framework
	$(srcdir)/create_bundle.sh reduce $(srcdir) reduce
endif mac_framework
endif wx

bootstrapreduce$(EXEEXT): $(bootstrapreduce_OBJECTS) $(bootstrapreduce_DEPENDENCIES) $(FOXDEPS) $(WXDEPS)
	-rm -f bootstrapreduce$(EXEEXT)
	$(CXXLINKTO) $(BOOTSTRAPREDUCEEXEDEF) $(DEST)bootstrapreduce$(EXEEXT) $(bootstrapreduce_OBJECTS) $(bootstrapreduce_LDADD) $(LIBS) $(CONAP)
if !debug
if !darwin
	$(STRIP) bootstrapreduce$(EXEEXT)
endif !darwin
endif !debug
if wx
if mac_framework
	$(srcdir)/create_bundle.sh bootstrapreduce $(srcdir) reduce
endif mac_framework
endif wx

fwindemo$(EXEEXT): $(fwindemo_OBJECTS) $(fwindemo_DEPENDENCIES) $(FOXDEPS) $(WXDEPS)
	-rm -f fwindemo$(EXEEXT)
	$(CXXLINKTO) $(DEST)fwindemo$(EXEEXT) $(fwindemo_OBJECTS) $(fwindemo_LDADD) $(LIBS) $(WINAP)
if windows
if gui
	-rm -f fwindemo$(COM)
	$(CXXLINKTO) $(DEST)fwindemo$(COM) $(fwindemo_OBJECTS) $(fwindemo_LDADD) $(LIBS) $(CONAP)
endif gui
endif windows
if !debug
if !darwin
	$(STRIP) fwindemo$(EXEEXT)
if windows
if gui
	$(STRIP) fwindemo$(COM)
endif gui
endif windows
endif !darwin
endif !debug
if wx
if mac_framework
	$(srcdir)/create_bundle.sh fwindemo $(srcdir)
endif mac_framework
endif wx

if wx
wxpsl$(EXEEXT): $(wxpsl_OBJECTS) $(wxpsl_DEPENDENCIES) $(WXDEPS)
	-rm -f wxpsl$(EXEEXT)
	$(CXXLINKTO) $(DEST)wxpsl$(EXEEXT) $(wxpsl_OBJECTS) $(wxpsl_LDADD) $(LIBS) $(WINAP)
if windows
if gui
	-rm -f wxpsl$(COM)
	$(CXXLINKTO) $(DEST)wxpsl$(COM) $(wxpsl_OBJECTS) $(wxpsl_LDADD) $(LIBS) $(CONAP)
endif gui
endif windows
if !debug
if !darwin
	$(STRIP) wxpsl$(EXEEXT)
if windows
if gui
	$(STRIP) wxpsl$(COM)
endif gui
endif windows
endif !darwin
endif !debug
if mac_framework
	$(srcdir)/create_bundle.sh wxpsl $(srcdir)
endif mac_framework
endif wx

if fox

fontdemo$(EXEEXT): $(fontdemo_OBJECTS) $(fontdemo_DEPENDENCIES) $(FOXDEPS)
	-rm -f fontdemo$(EXEEXT)
	$(CXXLINKTO) $(DEST)fontdemo$(EXEEXT) $(fontdemo_OBJECTS) $(fontdemo_LDADD) $(LIBS) $(CONAP)
if !debug
if !darwin
	$(STRIP) fontdemo$(EXEEXT)
endif !darwin
endif !debug

foxdemo$(EXEEXT): $(foxdemo_OBJECTS) $(foxdemo_DEPENDENCIES) $(FOXDEPS)
	-rm -f foxdemo$(EXEEXT)
	$(CXXLINKTO) $(DEST)foxdemo$(EXEEXT) $(foxdemo_OBJECTS) $(foxdemo_LDADD) $(LIBS) $(CONAP)
if !debug
if !darwin
	$(STRIP) foxdemo$(EXEEXT)
endif !darwin
endif !debug

showmathdemo$(EXEEXT): $(showmathdemo_OBJECTS) $(showmathdemo_DEPENDENCIES) $(FOXDEPS)
	-rm -f showmathdemo$(EXEEXT)
	$(CXXLINKTO) $(DEST)showmathdemo$(EXEEXT) $(showmathdemo_OBJECTS) $(showmathdemo_LDADD) $(LIBS) $(CONAP)
if !debug
if !darwin
	$(STRIP) showmathdemo$(EXEEXT)
endif !darwin
endif !debug

endif fox

if gui
if windows

csl$(COM):	$(csl_OBJECTS) $(csl_DEPENDENCIES)
	-rm -f csl.exe
	$(MAKE) csl.exe

reduce$(COM):	$(reduce_OBJECTS) $(reduce_DEPENDENCIES)
	-rm -f reduce.exe
	$(MAKE) reduce.exe

fwindemo$(COM):	$(fwindemo_OBJECTS) $(fwindemo_DEPENDENCIES)
	-rm -f fwindemo.exe
	$(MAKE) fwindemo.exe

wxpsl$(COM):	$(wxpsl_OBJECTS) $(wxpsl_DEPENDENCIES)
	-rm -f wxpsl.exe
	$(MAKE) wxpsl.exe

endif windows
endif gui

reduce.$(fontsdir)/$(samplefont):	$(srcdir)/fonts
if wx
if mac_framework
	echo reduce.wxfonts not used on the Mac with wxWidgets
else !mac_framework
	-rm -rf reduce.$(fontsdir)
	-mkdir -p reduce.$(fontsdir)
	$(CP) $(srcdir)/$(fontsdir)/README reduce.$(fontsdir)/README.BaKoMa
	$(CP) $(srcdir)/$(fontsdir)/BaKoMa-AMS.Fonts reduce.$(fontsdir)
	$(CP) $(srcdir)/$(fontsdir)/BaKoMa-CM.Fonts reduce.$(fontsdir)
	$(CP) $(srcdir)/$(fontsdir)/README.news reduce.$(fontsdir)/README.news.BaKoMa
	$(CP) $(srcdir)/$(fontsdir)/LICENCE reduce.$(fontsdir)/LICENCE.BaKoMa
	$(CP) $(srcdir)/$(fontsdir)/*.ttf reduce.$(fontsdir)
# At present the only CM Unicode font I will copy across is CMTT.
# I will still need and use the BaKoMa fonts for CMSY, CMEX and MSAM etc
# special characters when typesetting high quality mathematics..
	$(CP) $(srcdir)/cm-unicode/LICENSE reduce.$(fontsdir)/LICENSE.cm-unicode
	$(CP) $(srcdir)/cm-unicode/README reduce.$(fontsdir)/README.cm-unicode
	$(CP) $(srcdir)/cm-unicode/cmuntt.otf reduce.$(fontsdir)
# The DejaVu Sans Mono font covers a range of characters that CMTT does not..
	$(CP) $(srcdir)/dejavu-fonts-ttf-2.32/LICENSE reduce.$(fontsdir)/LICENSE.dejavu-fonts-ttf-2.32
	$(CP) $(srcdir)/dejavu-fonts-ttf-2.32/README reduce.$(fontsdir)/README.dejavu-fonts-ttf-2.32
	$(CP) $(srcdir)/dejavu-fonts-ttf-2.32/AUTHORS reduce.$(fontsdir)/AUTHORS.dejavu-fonts-ttf-2.32
	$(CP) $(srcdir)/dejavu-fonts-ttf-2.32/ttf/DejaVuSansMono.ttf reduce.$(fontsdir)
# I will also use fireflysung and sazanami fonts to cover the CJK range
# I list every file I am copying individually to avoid (eg) any backups or
# subversion admin files ending up where I do not want them.
	$(CP) $(srcdir)/fireflysung-1.3.0/fireflysung.ttf reduce.$(fontsdir)
	$(CP) $(srcdir)/fireflysung-1.3.0/AUTHORS reduce.$(fontsdir)/AUTHORS.fireflysung
	$(CP) $(srcdir)/fireflysung-1.3.0/COPYRIGHT reduce.$(fontsdir)/COPYRIGHT.fireflysung
	mkdir -p reduce.$(fontsdir)/license.fireflysung
	mkdir -p reduce.$(fontsdir)/license.fireflysung/big5
	mkdir -p reduce.$(fontsdir)/license.fireflysung/english
	mkdir -p reduce.$(fontsdir)/license.fireflysung/gb
	$(CP) $(srcdir)/fireflysung-1.3.0/license/big5/ARPHICPL.TXT reduce.$(fontsdir)/license.fireflysung/big5
	$(CP) $(srcdir)/fireflysung-1.3.0/license/english/ARPHICPL.TXT reduce.$(fontsdir)/license.fireflysung/english
	$(CP) $(srcdir)/fireflysung-1.3.0/license/gb/ARPHICPL.TXT reduce.$(fontsdir)/license.fireflysung/gb
	$(CP) $(srcdir)/sazanami-20040629/README reduce.$(fontsdir)/README.sazanami
	$(CP) $(srcdir)/sazanami-20040629/sazanami-gothic.ttf reduce.$(fontsdir)
	$(CP) $(srcdir)/sazanami-20040629/sazanami-mincho.ttf reduce.$(fontsdir)
	mkdir -p reduce.$(fontsdir)/doc.sazanami
	mkdir -p reduce.$(fontsdir)/doc.sazanami/ayu
	mkdir -p reduce.$(fontsdir)/doc.sazanami/kappa
	mkdir -p reduce.$(fontsdir)/doc.sazanami/misaki
	mkdir -p reduce.$(fontsdir)/doc.sazanami/mplus
	mkdir -p reduce.$(fontsdir)/doc.sazanami/oradano
	mkdir -p reduce.$(fontsdir)/doc.sazanami/shinonome
	$(CP)  $(srcdir)/sazanami-20040629/doc/ayu/README.txt reduce.$(fontsdir)/doc.sazanami/ayu
	$(CP)  $(srcdir)/sazanami-20040629/doc/kappa/README reduce.$(fontsdir)/doc.sazanami/kappa
	$(CP)  $(srcdir)/sazanami-20040629/doc/misaki/misakib8.txt reduce.$(fontsdir)/doc.sazanami/misaki
	$(CP)  $(srcdir)/sazanami-20040629/doc/mplus/LICENSE_J reduce.$(fontsdir)/doc.sazanami/mplus
	$(CP)  $(srcdir)/sazanami-20040629/doc/oradano/README.txt reduce.$(fontsdir)/doc.sazanami/oradano
	$(CP)  $(srcdir)/sazanami-20040629/doc/shinonome/LICENSE reduce.$(fontsdir)/doc.sazanami/shinonome

endif !mac_framework
else !wx
	-rm -rf reduce.$(fontsdir)
	-mkdir reduce.$(fontsdir)
	$(CP) $(srcdir)/$(fontsdir)/README reduce.$(fontsdir)
	$(CP) $(srcdir)/$(fontsdir)/README.cmps-fonts reduce.$(fontsdir)
	$(CP) $(srcdir)/$(fontsdir)/README.BaKoMa reduce.$(fontsdir)
	$(CP) $(srcdir)/$(fontsdir)/*.ttf reduce.$(fontsdir)
	$(CP) $(srcdir)/$(fontsdir)/*.pfb reduce.$(fontsdir)
	$(CP) $(srcdir)/$(fontsdir)/*.pfa reduce.$(fontsdir)
	$(CP) $(srcdir)/$(fontsdir)/fonts.dir reduce.$(fontsdir)
	$(CP) $(srcdir)/$(fontsdir)/fonts.scale reduce.$(fontsdir)
	-mkdir -p reduce.$(fontsdir)/pfmfiles
	$(CP) -r $(srcdir)/$(fontsdir)/pfmfiles/*.pfm reduce.$(fontsdir)/pfmfiles
	-mkdir -p reduce.$(fontsdir)/src
	$(CP) -r $(srcdir)/$(fontsdir)/src/*.gz reduce.$(fontsdir)/src
endif !wx

if exeext

# The next section is to conspire with automake's treatement of externions for
# executables (ie ".exe") so that eg "make reduce" will case "make reduce.exe" to
# happen. The use of parameter substitution to generate the plain targets is
# because in that case automake will not auto-map the target adding ".exe".

plain_csl = csl
plain_reduce = reduce
plain_bootstrapreduce = bootstrapreduce
plain_fwindemo = fwindemo
plain_wxpsl = wxpsl
plain_termdemo = termdemo
plain_foxdemo  = foxdemo
plain_fontdemo = fontdemo
plain_showmathdemo = showmathdemo
plain_wxdemo  = wxdemo
plain_wxfontdemo = wxfontdemo
plain_wxdvi = wxdvi
plain_wxshowmathdemo = wxshowmathdemo
plain_dyndemo = dyndemo

if gui
$(plain_csl):	csl.exe csl$(COM)
	echo "make csl.exe is preferred"

$(plain_reduce):	reduce.exe reduce$(COM)
	echo "make reduce.exe is preferred"

$(plain_bootstrapreduce):	bootstrapreduce.exe
	echo "make bootstrapreduce.exe is preferred"

$(plain_fwindemo):	fwindemo.exe fwindemo$(COM)
	echo "make fwindemo.exe is preferred"

if wx
$(plain_wxpsl):	wxpsl.exe wxpsl$(COM)
	echo "make wxpsl.exe is preferred"
endif wx

else !gui
$(plain_csl):	csl.exe
	echo "make csl.exe is preferred"

$(plain_reduce):	reduce.exe
	echo "make reduce.exe is preferred"

$(plain_bootstrapreduce):	bootstrapreduce.exe
	echo "make bootstrapreduce.exe is preferred"

$(plain_fwindemo):	fwindemo.exe
	echo "make fwindemo.exe is preferred"

endif !gui

if fox

$(plain_foxdemo):	foxdemo.exe
	echo "make foxdemo.exe is preferred"

$(plain_fontdemo):	fontdemo.exe
	echo "make fontdemo.exe is preferred"

$(plain_showmathdemo):	showmathdemo.exe
	echo "make showmathdemo.exe is preferred"


endif fox

if wx

$(plain_wxdemo):	wxdemo.exe
	echo "make wxdemo.exe is preferred"

$(plain_wxfontdemo):	wxfontdemo.exe
	echo "make wxfontdemo.exe is preferred"

$(plain_wxdvi):	wxdvi.exe
	echo "make wxdvi.exe is preferred"

$(plain_wxshowmathdemo):	wxshowmathdemo.exe
	echo "make wxshowmathdemo.exe is preferred"


endif wx

$(plain_termdemo):	termdemo.exe
	echo "make termdemo.exe is preferred"

$(plain_dyndemo):	dyndemo.exe dynmodule.dll
	echo "make dyndemo.exe is preferred"

endif exeext

if mac_framework
# on Darwin I want to go
# /Developer/Tools/Rez -t APPL -o reduce $(srcdir)/mac.r
# (and similarly for csl) after linking, so that the items concerned
# become clickable. Note that "mac.r" is copied directly from the
# FLTK distribution (www.fltk.org) and it is released there under
# LGPL with an array of extra permissions that mean that static
# linking is permitted and it is not necessary to be as careful
# to distribute copies of licenses as it is with the regular LGPL.
#
# Well to be a little more precise, I want to do that if the MacOS framework
# is available. on raw Darwin it will not be.

make-clickable:	csl bootstrapreduce reduce
# Rez is now an rather old fashioned way of doing things. With wxWidgets I
# will replace this with stuff that creates application bundles.
	/Developer/Tools/Rez -t APPL -o csl $(srcdir)/mac.r
	/Developer/Tools/Rez -t APPL -o bootstrapreduce $(srcdir)/mac.r
	/Developer/Tools/Rez -t APPL -o reduce $(srcdir)/mac.r

endif mac_framework

if cygwin
# on cygwin I scan to verify which DLLs are referenced by my main
# executables so that I can verify (eg) that they do not link to
# cygwin1.dll or any other library that is liable to impose license
# conditions that affect distribution rules.
report-dlls:	csl.exe bootstrapreduce.exe reduce.exe
	objdump -p csl.exe | grep "DLL"
	objdump -p bootstrapreduce.exe | grep "DLL"
	objdump -p reduce.exe | grep "DLL"
endif cygwin

fwindemo_SOURCES=fwindemo.c $(fwin_sources)
if wx
wxpsl_SOURCES=wxpsl.cpp $(fwin_sources)
endif wx

termdemo_SOURCES=termdemo.c termed.c
termdemo_LIBS=

#
# Possibly unreasonably (but it is WHAT I DO!) image files for CSL live
# in the same directory as executables.
#

if windows
image_files = csl.img reduce.img reduce.doc reduce.$(fontsdir) wgnuplot* gnuplot.Copyright
else !windows
if mac_framework
image_files = csl.img reduce.img reduce.doc reduce.$(fontsdir) *.app
else
image_files = csl.img reduce.img reduce.doc reduce.$(fontsdir)
endif
endif !windows
install-data-local: $(image_files)
	@$(NORMAL_INSTALL)
	$(mkinstalldirs) $(DESTDIR)$(bindir)
	@list='$(image_files)'; for p in $$list; do \
	  if test -f $$p; then \
	    f=`echo "$$p" | sed 's,^.*/,,'`; \
	   echo " $(INSTALL_PROGRAM_ENV) $(binPROGRAMS_INSTALL) $$p $(DESTDIR)$(bindir)/$$f"; \
	   $(INSTALL_PROGRAM_ENV) $(binPROGRAMS_INSTALL) $$p $(DESTDIR)$(bindir)/$$f || exit 1; \
	  else :; fi; \
	done

if windows

if gui
if wx
console_binaries = csl$(COM) reduce$(COM) wxpsl$(COM) wgnuplot.exe wgnuplot.mnu wgnuplot.hlp
else !wx
console_binaries = csl$(COM) reduce$(COM) wgnuplot.exe wgnuplot.mnu wgnuplot.hlp
endif !wx
noinstall_console_binaries = fwindemo$(COM)
else !gui
console_binaries = wgnuplot.exe wgnuplot.mnu wgnuplot.hlp
noinstall_console_binaries =
endif !gui

install-exec-local: $(console_binaries)
	@$(NORMAL_INSTALL)
	$(mkinstalldirs) $(DESTDIR)$(bindir)
	@list='$(console_binaries)'; for p in $$list; do \
	  if test -f $$p; then \
	    f=`echo "$$p" | sed 's,^.*/,,'`; \
	   echo " $(INSTALL_PROGRAM_ENV) $(binPROGRAMS_INSTALL) $$p $(DESTDIR)$(bindir)/$$f"; \
	   $(INSTALL_PROGRAM_ENV) $(binPROGRAMS_INSTALL) $$p $(DESTDIR)$(bindir)/$$f || exit 1; \
	  else :; fi; \
	done

uninstall-local:
	@$(NORMAL_UNINSTALL)
	@list='$(console_binaries) $(image_files)'; for p in $$list; do \
	  f=`echo "$$p" | sed 's,^.*/,,'`; \
	  echo " rm -f $(DESTDIR)$(bindir)/$$f"; \
	  -rm -rf $(DESTDIR)$(bindir)/$$f; \
	done

local_image_files = bootstrapreduce.img

generatedfiles=$(console_binaries) $(noinstall_console_binaries) \
	$(image_files) $(local_image_files) \
	objtype* cl-wrap* makeheaders* *.def machineid.c dynmodule*

clean-local:
	-rm -rf $(generatedfiles)
	
else !windows

uninstall-local:
	@$(NORMAL_UNINSTALL)
	@list='$(image_files)'; for p in $$list; do \
	  f=`echo "$$p" | sed 's,^.*/,,'`; \
	  echo " rm -f $(DESTDIR)$(bindir)/$$f"; \
	  -rm -rf $(DESTDIR)$(bindir)/$$f; \
	done

local_image_files = bootstrapreduce.img

if mac_framework
macr = mac.r *.app
else !mac_framework
macr =
endif !mac_framework

generatedfiles=$(image_files) $(local_image_files) \
	objtype makeheaders machineid.c dynmodule* \
	$(macr)

clean-local:
	-rm -rf $(generatedfiles)
	
endif !windows



##############################################################################
#
# Beware. Many of the comments and targets here may be out of date!
#
##############################################################################

#=============================================================================
#
# The main final target is reduce.img, the image file for full REDUCE.
# If you want to rebuild stage-by-stage (eg while testing), try the
# sequence
#    make bootstrapreduce         compiles and links C coded kernel
#    make bootstrapreduce.img     makes bootstrap REDUCE
#                                 (roughly twice as slow as final one)
#                                 only used for system recompilation.
#    make profile                 runs tests, collects profile information.
#                                 This takes a long time!
#    make c-code                  Create files u*.c and u*.lsp
#                                 out of hot-spot parts of REDUCE.
#                                 (should happen automatically)
#  [ make full-c-code             Creates u*.c etc but trying to compile
#                                 pretty much everything into C. This leads
#                                 to a huge executable and may put undue
#                                 stress on C compilers. Mainly for use
#                                 as an experiment ]
#=============================================================================
# Note that only the steps from here downwards are usually needed
#
#    make reduce                final compilation of most of REDUCE
#    make reduce.img            build final image file
#    make testall               runs test files, output to log directory
# OR make test which=modulename
#    (make checkall             creates logs/checkall.log & logs/times.log
#                               (done anyway by testall))
#
#
#=============================================================================



default:	reduce$(EXEEXT) reduce.img

# This is the command needed to compile a module for use as a DLL or other
# dynamically loaded module

DLL_CFLAGS = @DLL_CFLAGS@

COMPILE_DLL = $(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) \
	$(CPPFLAGS) $(AM_CFLAGS) $(DLL_CFLAGS)

if windows
dyndef =  $(srcdir)/dynmodule1.def
dyndep =
else !windows
dyndef =
dyndep =
endif !windows

DLLIB=

dynmodule.$(DLLEXT):	$(srcdir)/dynmodule.c $(srcdir)/dynmodule.def $(dyndep)
	$(COMPILE_DLL) $(dyndef) $(srcdir)/dynmodule.c $(DLLIB) $(DEST)dynmodule.$(DLLEXT)

if canrun

if windows

# On windows I must avoid -mno-cygwin here.

objtype$(EXEEXT):	$(srcdir)/objtype.c
	gcc $(srcdir)/objtype.c -o objtype$(EXEEXT)

makeheaders$(EXEEXT):	$(srcdir)/makeheaders.c
	gcc $(srcdir)/makeheaders.c -o makeheaders$(EXEEXT)

else !windows

objtype$(EXEEXT):	$(srcdir)/objtype.c
	$(COMPILE) $(srcdir)/objtype.c -o objtype$(EXEEXT)

makeheaders$(EXEEXT):	$(srcdir)/makeheaders.c
	$(COMPILE) $(srcdir)/makeheaders.c -o makeheaders$(EXEEXT)

endif !windows
else !canrun

# If I can not run programs built by the normal C compiler (eg because I am
# cross-compiling) I will build these two utilities using gcc. I will blandly
# assume that in any cross-compilation situation that gcc is available
# and works, and the assumption is simplified by the fact that these two
# programs are botf fairly small and conservative.

objtype$(EXEEXT):	$(srcdir)/objtype.c
	gcc $(srcdir)/objtype.c -o objtype$(EXEEXT)

makeheaders$(EXEEXT):	$(srcdir)/makeheaders.c
	gcc $(srcdir)/makeheaders.c -o makeheaders$(EXEEXT)

endif !canrun

# The next line generates a small file that contains inforation about the
# object files used on this computer and the command used to compile
# simple C code.

machineid.c:	cslread.$(OBJEXT) config.h objtype$(EXEEXT) makeheaders$(EXEEXT) \
			makeheaders$(EXEEXT) Makefile $(srcdir)/impex.def \
			$(srcdir)/machine.h $(srcdir)/tags.h \
			$(srcdir)/cslerror.h $(srcdir)/externs.h \
			$(srcdir)/arith.h $(srcdir)/entries.h
	./objtype$(EXEEXT) cslread.$(OBJEXT) \
		$(srcdir)/impex.def machineid-1.c $(COMPILE_DLL)
	./makeheaders$(EXEEXT) config.h $(srcdir)/machine.h \
		$(srcdir)/tags.h \
		$(srcdir)/cslerror.h $(srcdir)/externs.h \
		$(srcdir)/arith.h $(srcdir)/entries.h > machineid-2.c
	cat machineid-1.c machineid-2.c > machineid.c

# It is important for the next line that restart.$(OBJEXT) is created from
# restart.c using a generic default rule - otherwise the lack of
# explicit actions here would hurt.
restart.$(OBJEXT):	machineid.c

-include reduce.dep

reduce.dep:
	touch reduce.dep

reduce.img:	reduce$(COM) $(reducedep) $(gensrc)/timestamp.dat
	-$(RM) -rf reduce.img
if canrun
# I will make the REDUCE image file a directory rather than a single
# file... This is achieved by specifying its name here with a trailing "/",
# but I could have also have just made a directory with the right name
# before starting the build job.
	mkdir -p buildlogs
	./reduce$(COM) -w -z -Dno_init_file $(CYGSRC)/buildreduce.lsp \
		-D@srcdir=$(CYGSRC) \
		-- buildlogs/reduce.log \
		-j reduce.dep
# I copy an image into $(gensrc) with a view to keeping a copy thare that
# is up to date with my lastest build. There is a complication here that I
# only partially hack around. On the Mac I will often save image files within
# an application bundle, while on all other platforms they life in the
# directory adjacent to the executable file. I conditionally copy from both
# places here
	if test -f reduce.app/Contents/reduce.img; \
	then cp reduce.app/Contents/reduce.img $(gensrc); \
	elif test -f reduce.img; then cp reduce.img $(gensrc); fi
else !canrun
	echo Can not build reduce.img on this platform.
	echo Copying from $(gensrc)
	-rm -rf reduce.img
	cp -r $(gensrc)/reduce.img .
endif !canrun

# This is a temporary target "reduce.dir" to create the image as a directory
# rather than as a single file.

reduce.dir:	reduce$(COM) $(reducedep) $(gensrc)/timestamp.dat
	-$(RM) -rf reduce.img
if canrun
# I will make the REDUCE image file a directory rather than a single
# file... This is achieved by specifying its name here with a trailing "/",
# but I could have also have just made a directory with the right name
# before starting the build job.
	mkdir -p buildlogs
	./reduce$(COM) -w -z -Dno_init_file $(CYGSRC)/buildreduce.lsp \
		-D@srcdir=$(CYGSRC) \
		-o ./reduce.img/ \
		-- buildlogs/reduce.log \
		-j reduce.dep
else !canrun
	echo Can not build reduce.img on this platform
	echo Copying from $(gensrc)
	-rm -rf reduce.img
	cp -r $(gensrc)/reduce.img .
endif !canrun

bootstraprecompile:	bootstrapreduce.img
if canrun
	mkdir -p buildlogs
	./bootstrapreduce$(EXEEXT) -v -w $(CYGSRC)/recompile.red \
		-Dno_init_file -D@srcdir=$(CYGSRC) \
		-l buildlogs/$(which).log -Dwhich=$(which)
else !canrun
	echo Can not build images on this platfrom
endif !canrun

recompile:	reduce.img
if canrun
	mkdir -p buildlogs
	./reduce$(COM) -v -w $(CYGSRC)/recompile.red \
		-Dno_init_file -D@srcdir=$(CYGSRC) \
		-l buildlogs/$(which).log -Dwhich=$(which)
else !canrun
	echo Can not build images on this platfrom
endif !canrun

# Copy HTML help files in a directory reduce.doc
reduce.doc/index.html:
	-$(RM) -rf reduce.doc
	mkdir -p reduce.doc
	$(CP) -r $(srcdir)/../reduce.doc/*.html reduce.doc
	$(CP) -r $(srcdir)/../reduce.doc/*.tex reduce.doc
	$(CP) -r $(srcdir)/../reduce.doc/*.gif reduce.doc
	$(CP) -r $(srcdir)/../reduce.doc/*.txt reduce.doc

if windows
#
# I also copy a set of gnuplot binaries into this directory.
# Note that the Gnuplot license permits this, but if I host any of this
# on Sourceforge then their terms and conditions mean I have to put a
# set of gnuplot sources in their file release system! Also in the version
# if this stuff as fetched using subversion there will be directories
# called ".svn" that should not be copied, so I can not merely use
# a simple wild-card to copy everything!
$(GP):
	$(CP) $(srcdir)/../support-packages/gnuplot-windows-bin/R* .
	$(CP) $(srcdir)/../support-packages/gnuplot-windows-bin/g* .
	$(CP) $(srcdir)/../support-packages/gnuplot-windows-bin/p* .
	$(CP) $(srcdir)/../support-packages/gnuplot-windows-bin/w* .
	-mkdir -p share/PostScript
	$(CP) $(srcdir)/../support-packages/gnuplot-windows-bin/share/Post*/R* share/PostScript
	$(CP) $(srcdir)/../support-packages/gnuplot-windows-bin/share/Post*/8* share/PostScript
	$(CP) $(srcdir)/../support-packages/gnuplot-windows-bin/share/Post*/c* share/PostScript
	$(CP) $(srcdir)/../support-packages/gnuplot-windows-bin/share/Post*/k* share/PostScript
	$(CP) $(srcdir)/../support-packages/gnuplot-windows-bin/share/Post*/p* share/PostScript
# I view it as most unwelcome that I need the "chmod" here, but if I have
# gcc/g++ on my path and available I will suppose I can have chmod too.
	chmod +x *gnuplot*.exe
endif windows

-include bootstrapreduce.dep

bootstrapreduce.dep:
	touch bootstrapreduce.dep

bootstrapreduce.img:	bootstrapreduce$(EXEEXT) $(bootstrapreducedep)
	-$(RM) -f bootstrapreduce.img
if canrun
	mkdir -p buildlogs
	./bootstrapreduce$(EXEEXT) -w -z -Dno_init_file \
		$(CYGSRC)/buildreduce.lsp -D@srcdir=$(CYGSRC) \
		-- buildlogs/bootstrapreduce.log \
		-j bootstrapreduce.dep
	if test -f bootstrapreduce.app/Contents/bootstrapreduce.img; \
	then cp bootstrapreduce.app/Contents/bootstrapreduce.img $(gensrc); \
	elif test -f bootstrapreduce.img; \
	then cp bootstrapreduce.img $(gensrc); fi
else !canrun
	echo Can not build bootstrapreduce.img on this platform
	echo Copying from $(gensrc)
	-rm -rf bootstrapreduce.img
	cp $(gensrc)/bootstrapreduce.img .
endif !canrun

profile:	bootstrapreduce.img
if canrun
	mkdir -p buildlogs
	./bootstrapreduce$(EXEEXT) -w -Dno_init_file \
		$(CYGSRC)/profile.red -D@srcdir=$(CYGSRC) \
                -Dcpulimit=$(cpulimit) -Dconslimit=$(conslimit) \
		-- buildlogs/profile.log
# I preserve the previous profile.dat as profile.dat.old
	-cp $(gensrc)/profile.dat $(gensrc)/profile.dat.old
	mv profile.dat $(gensrc)
else !canrun
	echo Can not profile on this platform
endif !canrun

prof-inst:	profile.dat
	$(CP) profile.dat $(gensrc)
	-$(RM) -f profile.dat

$(gensrc)/profile.dat:
	-mkdir -p $(gensrc)
	$(CP) $(srcdir)/../profile.dat $(gensrc)

$(gensrc)/make.stamp:	$(bootstrapreducedep) $(gensrc)/profile.dat
	@rm -f $(gensrc)/make.tmp
	@touch $(gensrc)/make.tmp
	mkdir -p buildlogs
	$(MAKE) $(AM_MAKEFLAGS) bootstrapreduce.img
	./bootstrapreduce$(EXEEXT) -w -Dno_init_file $(CYGSRC)/make-c-code.red \
		-D@destdir=$(CYGSRC)/../../cslbuild/generated-c \
		-Dhow_many=$(how_many) -Dsize_per_file=$(size_per_file) \
		-- buildlogs/c-code.log
	@mv $(gensrc)/make.tmp $(gensrc)/make.stamp

# The following rule can lead to rache conditions with parallel make if
# several generated files have been deleted but not the make.stamp file.
# You should be able to recover reliably by going "make clean" followed
# by "make".

c-code $(generated_sources) $(generated_lisp):	$(gensrc)/make.stamp
## Recover from the removal of $@
	if test -f $@; then :; else \
	  rm -f $(gensrc)/make.stamp; \
	  $(MAKE) $(AM_MAKEFLAGS) $(gensrc)/make.stamp; \
	fi

#c-code $(gensrc)/timestamp.dat:	$(bootstrapreducedep) $(gensrc)/profile.dat
#if canrun
#	mkdir -p buildlogs
#	$(MAKE) bootstrapreduce.img
#	./bootstrapreduce$(EXEEXT) -w -Dno_init_file $(CYGSRC)/make-c-code.red \
#		-D@destdir=$(CYGSRC)/../../cslbuild/generated-c \
#		-Dhow_many=$(how_many) -Dsize_per_file=$(size_per_file) \
#		-- buildlogs/c-code.log
#else !canrun
#	echo Can not generate C code on this platfrom
#	echo Touching existing files to adjust datestamps
#	touch $(gensrc)/*
#endif !canrun

#$(generated_objects):	$(gensrc)/timestamp.dat

# full-c-code is a target only activated manually.

full-c-code:	bootstrapreduce.img $(gensrc)/profile.dat
if canrun
	mkdir -p buildlogs
	./bootstrapreduce$(EXEEXT) -w -Dno_init_file $(CYGSRC)/make-c-code.red \
		-D@destdir=$(CYGSRC)/../../cslbuild/generated-c -Dfull_c_code \
		-Dhow_many=$(how_many) -Dsize_per_file=$(size_per_file) \
		-- buildlogs/full-c-code.log
else !canrun
	echo Can not generate C code on this platfrom
endif !canrun

smacros smacros.red:	bootstrapreduce.img
if canrun
	mkdir -p buildlogs
	./bootstrapreduce$(EXEEXT) -w -Dno_init_file $(CYGSRC)/make-smacros.red \
		-Dhow_many=$(how_many) -Dhow_big=$(how_big) \
		-L buildlogs/smacros.log
	echo You may now copy smacros.red to trunk/packages/support
else !canrun
	echo Can not generate smacros.red on this platfrom
endif !canrun

testslow:	bootstrapreduce.img
if canrun
	mkdir -p testlogs
	./bootstrapreduce$(EXEEXT) -v -w $(CYGSRC)/testall.red \
		-Dno_init_file -D@srcdir=$(CYGSRC) \
		-- testlogs/testslow.log
	./bootstrapreduce$(EXEEXT) -v -w $(CYGSRC)/checkall.red \
		-Dno_init_file -D@srcdir=$(CYGSRC) \
		-- testlogs/checkslow.log
else !canrun
	echo Can not run tests on this platfrom
endif !canrun

testall:	reduce.img
if canrun
	mkdir -p testlogs
	./reduce$(COM) -v -w $(CYGSRC)/testall.red \
		-Dno_init_file -D@srcdir=$(CYGSRC) \
                -Dcpulimit=$(cpulimit) -Dconslimit=$(conslimit) \
		-- testlogs/testreduce.log
	./reduce$(COM) -v -w $(CYGSRC)/checkall.red \
		-Dno_init_file -D@srcdir=$(CYGSRC) \
		-- testlogs/checkall.log
else !canrun
	echo Can not run tests on this platfrom
endif !canrun

testslow1:	bootstrapreduce.img
if canrun
	mkdir -p testlogs
	./bootstrapreduce$(EXEEXT) -v -w $(CYGSRC)/testall.red \
		-Dno_init_file -D@srcdir=$(CYGSRC) \
                -Dcpulimit=$(cpulimit) -Dconslimit=$(conslimit) \
		-- testlogs/test$(which).log -Dwhich=$(which)
else !canrun
	echo Can not run tests on this platfrom
endif !canrun

if valgrind

countall:	reduce.img
	mkdir -p testlogs
	valgrind --tool=exp-bbv --instr-count-only=yes \
		./reduce$(COM) -v -w $(CYGSRC)/testall.red \
		-Dno_init_file -D@srcdir=$(CYGSRC) \
                -Dcpulimit=30000 -Dconslimit=$(conslimit) \
		-- testlogs/countreduce.log



endif valgrind

test1:	reduce.img
if canrun
	mkdir -p testlogs
	./reduce$(COM) -v -w $(CYGSRC)/testall.red \
		-Dno_init_file -D@srcdir=$(CYGSRC) \
		-- testlogs/test$(which).log -Dwhich=$(which) \
                -Dcpulimit=$(cpulimit) -Dconslimit=$(conslimit)
else !canrun
	echo Can not run tests on this platfrom
endif !canrun

if valgrind

count1:	reduce.img
	mkdir -p testlogs
	valgrind --tool=exp-bbv --instr-count-only=yes \
		./reduce$(COM) -v -w $(CYGSRC)/testall.red \
		-Dno_init_file -D@srcdir=$(CYGSRC) \
		-- testlogs/count$(which).log -Dwhich=$(which) \
                -Dcpulimit=30000 -Dconslimit=$(conslimit)

endif valgrind

checkall:	reduce.img
if canrun
	mkdir -p testlogs
	./reduce$(COM) -v -w $(CYGSRC)/checkall.red \
		-Dno_init_file -D@srcdir=$(CYGSRC) \
		-- testlogs/checkall.log
else !canrun
	echo Can not check test results on this platfrom
endif !canrun

cleanlog:
	-$(RM) -f buildlogs/*.log testlogs/*.rlg



# Note that I may need to use a native windows path on the command line
# here in that cygwin paths that include cygwin symbolic links or that
# are absolute (starting with "/") may not be handled well by my code.

-include csl.dep

csl.dep:
	touch csl.dep

csl.img:	csl$(COM) $(csldep)
	-$(RM) -rf csl.img
if canrun
	mkdir -p buildlogs
	./csl$(COM) -w -v -z "$(CYGSRC)/buildcsl.lsp" \
		-D@cslbase="$(CYGSRC)" \
		-- buildlogs/csl.img.log \
		-j csl.dep
	if test -f csl.app/Contents/csl.img; \
	then cp -r csl.app/Contents/csl.img $(gensrc); \
	elif test -f csl.img; then cp -r csl.img $(gensrc); fi
else !canrun
	echo Can not create csl.img on this platfrom
	echo Copying from $(gensrc)
	-rm -rf csl.img
	cp -r $(gensrc)/csl.img .
endif !canrun


csl.dir:	csl$(COM) $(csldep)
	-$(RM) -rf csl.img
if canrun
	mkdir -p buildlogs
	./csl$(COM) -w -v -z "$(CYGSRC)/buildcsl.lsp" \
		-o ./csl.img/ -D@cslbase="$(CYGSRC)" \
		-- buildlogs/csl.img.log \
		-j csl.dep
else !canrun
	echo Can not create csl.img on this platfrom
	echo Copying from $(gensrc)
	-rm -rf csl.img
	cp -r $(gensrc)/csl.img .
endif !canrun



#
# The target "bytes1a.$(OBJEXT)" recompiles bytes1.c, but with the flag set that
# arranges that the number of GET operations performed and the associated
# indicators will be recorded, so that (bytecounts) will display statistics
# about it. This slows things down considerably, but can help when you are in
# the process of deciding which indicators are specified as "fast" ones.
#

#bytes1a.$(OBJEXT):	$(C)/bytes1.c $(C)/bytes.c $(C)/tags.h $(C)/machine.h \
#		$(C)/externs.h $(C)/sys.h $(C)/cslerror.h \
#		$(C)/bytes.h $(C)/arith.h
#	$(COMPILE) -DRECORD_GET=1 \
#		-o bytes1.$(OBJEXT) \
#		$(C)/bytes1.c

if fox
guisrc=$(foxdemo_SOURCES) $(fontdemo_SOURCES) $(showmathdemo_SOURCES)
else !fox
if wx
guisrc=$(wxdemo_SOURCES) $(wxfontdemo_SOURCES) $(wxshowmathdemo_SOURCES)
else !wx
guisrc=
endif !wx
endif !fox
if wx
mainsrc=$(guisrc) $(fwindemo_SOURCES) $(wxpsl_SOURCES) $(termdemo_SOURCES) $(reduce_SOURCES)
else !wx
mainsrc=$(guisrc) $(fwindemo_SOURCES) $(termdemo_SOURCES) $(reduce_SOURCES)
endif !wx
srcfiles=$(mainsrc) $(csl_SOURCES)

if fox
guibin=foxdemo$(EXEEXT) fontdemo$(EXEEXT) showmathdemo$(EXEEXT)
else !fox
if wx
guibin=wxdemo$(EXEEXT) wxfontdemo$(EXEEXT) wxshowmathdemo$(EXEEXT)
else !wx
guibin=
endif !wx
endif !fox
if wx
mainbin=$(guibin) fwindemo$(EXEEXT) wxpsl$(EXEEXT) termdemo$(EXEEXT) reduce$(EXEEXT)
else !wx
mainbin=$(guibin) fwindemo$(EXEEXT) termdemo$(EXEEXT) reduce$(EXEEXT)
endif !wx
if windows
if wx
mainbin+=fwindemo$(COM) wxpsl$(COM) reduce$(COM)
else !wx
mainbin+=fwindemo$(COM) reduce$(COM)
endif !wx
endif windows
binfiles=$(mainbin) csl$(EXEEXT)
if windows
binfiles+=csl$(COM)
endif windows

save:	all
if win64
NAME=windows64
else !win64
if windows
NAME=windows32
else !windows
NAME=$(BUILD)
endif !windows
endif !win64
	echo ARCHITECTURE=$(ARCHITECTURE)  NAME=$(NAME)
if windows
	-rm -f reduce-windows-$(shell date +%Y%m%d).zip
	-rm -rf reduce-$(NAME)-$(shell date +%Y%m%d)
	mkdir -p reduce-$(NAME)-$(shell date +%Y%m%d)
	cp -r reduce.exe reduce.com reduce.img reduce.doc reduce.fonts *gnuplot* reduce-$(NAME)-$(shell date +%Y%m%d)
	zip -r reduce-$(NAME)-$(shell date +%Y%m%d).zip reduce-$(NAME)-$(shell date +%Y%m%d)
ARCHIVE=reduce-$(NAME)-$(shell date +%Y%m%d).zip
else !windows
	-rm -f reduce-$(NAME)-$(shell date +%Y%m%d).tar.bz2
	-rm -rf reduce-$(NAME)-$(shell date +%Y%m%d)
	mkdir -p reduce-$(NAME)-$(shell date +%Y%m%d)
	cp -r reduce reduce.img reduce.doc reduce.fonts reduce-$(NAME)-$(shell date +%Y%m%d)
	tar cvfj reduce-$(NAME)-$(shell date +%Y%m%d).tar.bz2 reduce-$(NAME)-$(shell date +%Y%m%d)
ARCHIVE=reduce-$(NAME)-$(shell date +%Y%m%d).tar.bz2 
endif !windows
	if test "x$(savedest)" != "x"; then scp $(ARCHIVE) $(savedest); fi



showhost:
	echo host = $(HOST)

# end of Makefile


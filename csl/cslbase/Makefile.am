## process this file with automake to create Makefile.in

## and then use autoconf to create ./configure. Finally run that
## to build your usable Makefile (probably in another directory)

# CSL and REDUCE build sequences

# I want to be able to see what gets built and why, so here is a GNU
# make trace facility.

TRACE = $(warning TRACE: $@ :: $?)

AM_CPPFLAGS = $(TRACE)
AM_LDFLAGS  = $(TRACE)

# If I list all the phony targets here this may help document things you
# can do via this Makefile

if exeext
# On Windows I might normally have to go "make reduce.exe" but I really
# want to be able to say merely "make reduce". So to cope with that I make
# "reduce" a phony target that triggers rebuiling of reduce.exe. However
# I had better not do that on Unix where the ".exe" extension is not
# used so that just "reduce" is the true name of the executable. I find
# that automake gets unhappy about .PHONY targets in a conditonal section
# so I introduce a load that have silly names in the case I do not
# really need them.
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
else !exeext
plain_csl = csl.unnecessary.except.on.windows
plain_reduce = reduce.unnecessary.except.on.windows
plain_bootstrapreduce = bootstrapreduce.unnecessary.except.on.windows
plain_fwindemo = fwindemo.unnecessary.except.on.windows
plain_wxpsl = wxpsl.unnecessary.except.on.windows
plain_termdemo = termdemo.unnecessary.except.on.windows
plain_foxdemo  = foxdemo.unnecessary.except.on.windows
plain_fontdemo = fontdemo.unnecessary.except.on.windows
plain_showmathdemo = showmathdemo.unnecessary.except.on.windows
plain_wxdemo  = wxdemo.unnecessary.except.on.windows
plain_wxfontdemo = wxfontdemo.unnecessary.except.on.windows
plain_wxdvi = wxdvi.unnecessary.except.on.windows
plain_wxshowmathdemo = wxshowmathdemo.unnecessary.except.on.windows
plain_dyndemo = dyndemo.unnecessary.except.on.windows
endif !exeext

.PHONY: $(plain_csl)
.PHONY: $(plain_reduce)
.PHONY: $(plain_bootstrapreduce)
.PHONY: $(plain_fwindemo)
.PHONY: $(plain_wxpsl)
.PHONY: $(plain_foxdemo)
.PHONY: $(plain_fontdemo)
.PHONY: $(plain_showmathdemo)
.PHONY: $(plain_wxdemo)
.PHONY: $(plain_wxfontdemo)
.PHONY: $(plain_wxdvi)
.PHONY: $(plain_wxshowmathdemo)
.PHONY: $(plain_termdemo)
.PHONY: $(plain_dyndemo)

.PHONY: report-dlls
.PHONY:	bootstraprecompile
.PHONY:	recompile
.PHONY:	profile
.PHONY:	prof-inst
.PHONY:	c-code
.PHONY:	standard-c-code
.PHONY:	full-c-code
.PHONY: j-code
.PHONY:	smacros
.PHONY:	testslow
.PHONY:	testall
.PHONY:	testslow1
.PHONY:	countall
.PHONY:	test1
.PHONY:	count1
.PHONY:	checkall
.PHONY:	cleanlog
.PHONY:	showhost

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
WXC=../bin/wx-config
BUILT_SOURCES = $(WXC)
MY_CPPFLAGS := $(shell ../bin/wx-config --cppflags 2>/dev/null)
MY_CFLAGS   := $(shell ../bin/wx-config --cflags 2>/dev/null)
MY_CXXFLAGS := $(shell ../bin/wx-config --cxxflags 2>/dev/null)
MY_LIBS     := $(shell ../bin/wx-config --libs 2>/dev/null)

AM_CPPFLAGS += $(MY_CPPFLAGS)
AM_CFLAGS    = $(MY_CFLAGS)
AM_CXXFLAGS  = $(MY_CXXFLAGS)
AM_LIBS      = $(MY_LIBS)

else !wx
WXC=
endif !wx

# I wish to know where this build intends to install things...
AM_CPPFLAGS += -DBINDIR=$(bindir) -DPKGDATADIR=$(pkgdatadir)

# On Windows if I have a GUI (wither based on Fox or wxWidgets) I will want
# the main version of my code to be an .exe file but I will also want a
# .com version to be a console application. If I only have command-line
# versions it is easiest to make everything .exe
if windows
if cygwin
COM=.exe
else !cygwin
if gui
COM=.com
else !gui
COM=.exe
endif !gui
endif !cygwin
else !windows
if cygwin
COM=.exe
else !cygwin
COM=
endif !cygwin
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
if mac_framework
noinst_PROGRAMS = bootstrapreduce$(EXEEXT) fwindemo$(EXEEXT) \
	termdemo$(EXEEXT) $(foxdemotarget) \
	$(wxdemotarget)
else !mac_framework
noinst_PROGRAMS = bootstrapreduce$(EXEEXT) fwindemo$(EXEEXT) \
	termdemo$(EXEEXT) $(foxdemotarget) dyndemo$(EXEEXT) \
	$(wxdemotarget)
endif !mac_framework

if cygwin
all-local:	report-dlls csl.img reduce.img
else !cygwin
all-local:	csl.img reduce.img
endif !cygwin


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

INLINE_DEFS = $(gensrc)/inline-defs.dat

$(INLINE_DEFS):
	touch $(INLINE_DEFS)

generated_sources =             u01.c \
		u02.c u03.c \
		u04.c u05.c \
		u06.c u07.c \
		u08.c u09.c \
		u10.c u11.c \
		u12.c u13.c \
		u14.c u15.c \
		u16.c u17.c \
		u18.c u19.c \
		u20.c u21.c \
		u22.c u23.c \
		u24.c u25.c \
		u26.c u27.c \
		u28.c u29.c \
		u30.c u31.c \
		u32.c u33.c \
		u34.c u35.c \
		u36.c u37.c \
		u38.c u39.c \
		u40.c u41.c \
		u42.c u43.c \
		u44.c u45.c \
		u46.c u47.c \
		u48.c u49.c \
		u50.c u51.c \
		u52.c u53.c \
		u54.c u55.c \
		u56.c u57.c \
		u58.c u59.c \
		u60.c
generated_sources_deps =             $(gensrc)/01.c \
		$(gensrc)/02.c $(gensrc)/03.c \
		$(gensrc)/04.c $(gensrc)/05.c \
		$(gensrc)/06.c $(gensrc)/07.c \
		$(gensrc)/08.c $(gensrc)/09.c \
		$(gensrc)/10.c $(gensrc)/11.c \
		$(gensrc)/12.c $(gensrc)/13.c \
		$(gensrc)/14.c $(gensrc)/15.c \
		$(gensrc)/16.c $(gensrc)/17.c \
		$(gensrc)/18.c $(gensrc)/19.c \
		$(gensrc)/20.c $(gensrc)/21.c \
		$(gensrc)/22.c $(gensrc)/23.c \
		$(gensrc)/24.c $(gensrc)/25.c \
		$(gensrc)/26.c $(gensrc)/27.c \
		$(gensrc)/28.c $(gensrc)/29.c \
		$(gensrc)/30.c $(gensrc)/31.c \
		$(gensrc)/32.c $(gensrc)/33.c \
		$(gensrc)/34.c $(gensrc)/35.c \
		$(gensrc)/36.c $(gensrc)/37.c \
		$(gensrc)/38.c $(gensrc)/39.c \
		$(gensrc)/40.c $(gensrc)/41.c \
		$(gensrc)/42.c $(gensrc)/43.c \
		$(gensrc)/44.c $(gensrc)/45.c \
		$(gensrc)/46.c $(gensrc)/47.c \
		$(gensrc)/48.c $(gensrc)/49.c \
		$(gensrc)/50.c $(gensrc)/51.c \
		$(gensrc)/52.c $(gensrc)/53.c \
		$(gensrc)/54.c $(gensrc)/55.c \
		$(gensrc)/56.c $(gensrc)/57.c \
		$(gensrc)/58.c $(gensrc)/59.c \
		$(gensrc)/60.c
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

AM_CPPFLAGS += -Dfontsdir=reduce.$(fontsdir)

foxdemo_SOURCES = foxdemo.cpp
foxdemo_CPPFLAGS = $(FOX_INCLUDES) $(TRACE) $(MY_CPPFLAGS) -DBINDIR=$(bindir) -DPKGDATADIR=$(pkgdatadir) -Dfontsdir=reduce.$(fontsdir) $(CRINC)
foxdemo_LDADD = $(fwin_icon) $(FOX_LIBS)
foxdemo_DEPENDENCIES = $(fwin_icon) 

fontdemo_SOURCES = fontdemo.cpp
fontdemo_CPPFLAGS = $(FOX_INCLUDES) $(TRACE) $(MY_CPPFLAGS) -DBINDIR=$(bindir) -DPKGDATADIR=$(pkgdatadir) -Dfontsdir=reduce.$(fontsdir) $(CRINC)
fontdemo_LDADD = $(fwin_icon) $(FOX_LIBS)
fontdemo_DEPENDENCIES = $(fwin_icon) $(FONTDEP)

showmathdemo_SOURCES = showmathdemo.cpp
showmathdemo_CPPFLAGS = $(FOX_INCLUDES) $(TRACE) $(MY_CPPFLAGS) -DBINDIR=$(bindir) -DPKGDATADIR=$(pkgdatadir) -Dfontsdir=reduce.$(fontsdir) $(CRINC)
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

if cygwin
libdyndemo.a: $(srcdir)/dyndemo.def
	$(TRACE)$(DLLTOOL) --input-def $(srcdir)/dyndemo.def --dllname=dyndemo.exe --output-lib libdyndemo.a
endif cygwin
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

dyndemo_LDADD = $(srcdir)/dyndemo.def

reduceres = fwin-reduce.$(OBJEXT)

AWKFILES=reduce.resources/mma.awk reduce.resources/qepcad.awk

fwindemo_LDADD = $(fwin_icon) $(FOX_LIBS)
csl_LDADD = fwin-csl.$(OBJEXT) $(FOX_LIBS)
bootstrapreduce_LDADD = fwin-csl.$(OBJEXT) $(FOX_LIBS)
reduce_LDADD = $(reduceres) $(FOX_LIBS)

# The purpose of these two tiny programs is explained in the
# file $(srcdir)/gui-or-not.txt and both are only for use on Windows.
# They are not compiled with the general configure-detected compilation
# options.

if cygwin
WINHELPERS=
else !cygwin
WINHELPERS= cygwin-isatty.exe cygwin64-isatty.exe not-under-cygwin.exe
endif !cygwin

# A brief note about version of C compilers under cygwin. On either the
# 32 or 64-bit cygwin just "gcc" is the main C compiler that targets the
# native width of the platform. But on each it is also possible to have
# one or both of i686-pc-cygwin-gcc and x86_64-pc-cygwin-gcc which explicitly
# target one or other width. These count as cross compilers, and at the
# time of writing they behave well enough to build the small command-line
# utilities here but do not come with enough development libraries to make
# it possible to use them to build all of CSL/Reduce. Because some people
# may not have them installed I have a fallback scheme here that fetches
# precompiled versions of the utilities. Note that they will include
# copies of cygwin1.dll but because they are BSD-licensed open source code
# that does not prevent me from redistributing them in an unconstrained manner.

cygwin-isatty.exe:	$(srcdir)/cygwin-isatty.c
	if test -x /usr/bin/i686-pc-cygwin-gcc.exe; then i686-pc-cygwin-gcc -O3 $(srcdir)/cygwin-isatty.c -o cygwin-isatty.exe; else $(CP) $(srcdir)/premade-cygwin-isatty.exe .; \
	  if test -x /usr/bin/i686-pc-cygwin-strip.exe; then i686-pc-cygwin-strip cygwin-isatty.exe; else strip cygwin-isatty.exe; fi fi

cygwin64-isatty.exe:	$(srcdir)/cygwin-isatty.c
	if test -x /usr/bin/x86_64-pc-cygwin-gcc.exe; then x86_64-pc-cygwin-gcc -O3 $(srcdir)/cygwin-isatty.c -o cygwin64-isatty.exe; else $(CP) $(srcdir)/premade-cygwin64-isatty.exe .; \
	  if test -s /usr/bin/x86_64-pc-cygwin-strip.exe; then x86_64-pc-cygwin-strip cygwin-isatty.exe; else strip cygwin-isatty.exe; fi fi

not-under-cygwin.exe:	$(srcdir)/not-under-cygwin.c
	i686-w64-mingw32-gcc -O3 $(srcdir)/not-under-cygwin.c -o not-under-cygwin.exe
	i686-w64-mingw32-strip not-under-cygwin.exe

csl_DEPENDENCIES = local-cslexe.def local-cslcom.def fwin-csl.$(OBJEXT) \
		$(FONTDEP) $(WXC)
bootstrapreduce_DEPENDENCIES = local-bootstrapreduceexe.def \
		fwin-csl.$(OBJEXT) $(FONTDEP) \
		reduce.doc/index.html $(AWKFILES) $(GP) $(WXC)
reduce_DEPENDENCIES = local-reduceexe.def local-reducecom.def $(reduceres) \
		$(FONTDEP) reduce.doc/index.html $(GP) $(WXC) \
		$(AWKFILES)

if wx
fwindemo_DEPENDENCIES = $(fwin_icon) $(FONTDEP) $(WXC)
wxpsl_DEPENDENCIES = $(fwin_icon) $(FONTDEP) $(WXC)
else !wx
fwindemo_DEPENDENCIES = $(fwin_icon) $(WINHELPERS)
endif !wx
dyndemo_DEPENDENCIES = $(srcdir)/dyndemo.def dynmodule.dll

libdyndemo.a: $(srcdir)/dyndemo.def
	$(DLLTOOL) --input-def $(srcdir)/dyndemo.def --dllname dyndemo.exe --output-lib libdyndemo.a

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
		reduce.doc/index.html $(AWKFILES) $(GP) $(WXC)
reduce_DEPENDENCIES = $(FONTDEP) reduce.doc/index.html \
		$(AWKFILES) $(GP) $(WXC)
if wx
fwindemo_DEPENDENCIES = $(fwin_icon) $(FONTDEP) $(WXC)
wxpsl_DEPENDENCIES = $(fwin_icon) $(FONTDEP) $(WXC)
else !wx
fwindemo_DEPENDENCIES = $(fwin_icon)
endif !wx

if cygwin
dyndemo_LDADD = $(srcdir)/dyndemo.def
endif cygwin
# end of windows vs non-windows conditions
endif !windows

# The next line is because CXXLINK has "-o $@" as part of it and in this
# case I want to have separate control of the destination of the executable
# that I create. In doing it this way I ASSUME (and in general this can not
# be guaranteed) that the expression "-o destination" will be what works.

CXXLINKTO = $(CXXLD) $(AM_CXXFLAGS) $(CXXFLAGS) $(AM_LDFLAGS) $(LDFLAGS)

# BEWARE BEWARE BEWARE the next line must have trailing blanks
DEST=-o # Note that the variable needs to include a trailing blank

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

# I make the whole of the FOX library depend on just one
# file, viz CHANGED. That is the file where I record updates that I make
# to it. A consequence of this should be that FOX will be (re-)compiled
# either the first time Reduce is built or if that CHANGED file gets updated,
# but that I avoid the cost of checking and recompiling for any alteration
# that does not cause me to record it in the CHANGED file.

$(FOXDEPS):	$(srcdir)/../fox/CHANGED
	$(TRACE)@cd ../fox && $(MAKE) install


if crlibm

CRLIBMDEPS=../lib/libcrlibm.a ../include/crlibm.h

CRINC = -I../include
AM_CPPFLAGS += $(CRINC)

# The following ugly dependencies are here so that one can go, for
# instance, "make csl.o" in a clean tree and crlibm building will get
# triggered.

# Note that all the compilation of these files must be performed using
# a Make "default" action so that the dependencies shown here are not
# taken as speciying conflicting actions.

arith01.$(OBJEXT):	../include/crlibm.h
arith02.$(OBJEXT):	../include/crlibm.h
arith03.$(OBJEXT):	../include/crlibm.h
arith04.$(OBJEXT):	../include/crlibm.h
arith05.$(OBJEXT):	../include/crlibm.h
arith06.$(OBJEXT):	../include/crlibm.h
arith07.$(OBJEXT):	../include/crlibm.h
arith08.$(OBJEXT):	../include/crlibm.h
arith09.$(OBJEXT):	../include/crlibm.h
arith10.$(OBJEXT):	../include/crlibm.h
arith11.$(OBJEXT):	../include/crlibm.h
arith12.$(OBJEXT):	../include/crlibm.h
bytes1.$(OBJEXT):	../include/crlibm.h
char.$(OBJEXT):	../include/crlibm.h
csl.$(OBJEXT):	../include/crlibm.h
cslmpi.$(OBJEXT):	../include/crlibm.h
cslread.$(OBJEXT):	../include/crlibm.h
eval1.$(OBJEXT):	../include/crlibm.h
eval2.$(OBJEXT):	../include/crlibm.h
eval3.$(OBJEXT):	../include/crlibm.h
eval4.$(OBJEXT):	../include/crlibm.h
fasl.$(OBJEXT):	../include/crlibm.h
fns1.$(OBJEXT):	../include/crlibm.h
fns2.$(OBJEXT):	../include/crlibm.h
fns3.$(OBJEXT):	../include/crlibm.h
gc.$(OBJEXT):	../include/crlibm.h
imulvc.$(OBJEXT):	../include/crlibm.h
jit1.$(OBJEXT):	../include/crlibm.h
jit2.$(OBJEXT):	../include/crlibm.h
jit3.$(OBJEXT):	../include/crlibm.h
jitx86.$(OBJEXT):	../include/crlibm.h
ompsetup.$(OBJEXT):	../include/crlibm.h
openmath.$(OBJEXT):	../include/crlibm.h
preserve.$(OBJEXT):	../include/crlibm.h
print.$(OBJEXT):	../include/crlibm.h
pro.$(OBJEXT):	../include/crlibm.h
restart.$(OBJEXT):	../include/crlibm.h machineid.c
stubs.$(OBJEXT):	../include/crlibm.h
sysfwin.$(OBJEXT):	../include/crlibm.h
sysipaq.$(OBJEXT):	../include/crlibm.h

csl_LDADD += -L../lib -lcrlibm
bootstrapreduce_LDADD += -L../lib -lcrlibm
reduce_LDADD += -L../lib -lcrlibm

csl_DEPENDENCIES += $(CRLIBMDEPS)
bootstrapreduce_DEPENDENCIES += $(CRLIBMDEPS)
reduce_DEPENDENCIES += $(CRLIBMDEPS)

$(CRLIBMDEPS):
	$(TRACE)@cd ../crlibm && $(MAKE) install

else !crlibm
CRINC =

# It is important for the next line that restart.$(OBJEXT) is created from
# restart.c using a generic default rule - otherwise the lack of
# explicit actions here would hurt.
restart.$(OBJEXT):	machineid.c

endif !crlibm

# If one of the major foundations of this Makefile have a date later than that
# on fxver.h then make does a futile recursion to try to fix it and in the
# process it can do a LOT of work that I do not want done. I can at least
# arrange that that happens at most once by putting the following rules:

$(srcdir)/configure.ac:
	touch $(srcdir)/configure.ac

$(srcdir)/Makefile.am:
	touch $(srcdir)/Makefile.am

if wx

#
# the wxWidgets snapshot that I have just uploaded builds as version
# 3.1 while earlier ones I had been using were 2.9. This is a mild nuisance
# but because hardly anybody will be working with the wxWidgets version at
# this stage I will just go with the flow. If in doubt please go
#   rm -rd cslbuild/*wx csl/wxWidgets; ./configure --with-csl --with-wx
# to get the latest snapshot unpacked and built.
#
WXV=3.1

# The master version of wxWidgets is kept in the source tree as a .tar
# archive, and the file support-packages/wxWidgets_version is updated
# whenever a new copy needs unpacking. This script probably depends on
# use of "bash" as your shell... I ought to review that issue at some stage.

$(srcdir)/../wxWidgets/wxWidgets_revision:	\
		$(srcdir)/../support-packages/wxWidgets_revision
	$(TRACE) ( cd $(srcdir)/../support-packages ; \
	a=`echo wxWidgets-v*.tar.bz2` ; \
	a=$${a##* } ; \
	b=$${a%.tar.bz2} ; \
	cd .. ; \
	rm -rf wxWidgets ; \
	tar xfj support-packages/$$a ; \
	chmod -R +rw wxWidgets-* ; \
	mv wxWidgets-* wxWidgets ; \
	cp $(srcdir)/../support-packages/wxWidgets_revision wxWidgets ; \
	echo wxWidgets unpacked from archive $$a )

BASELIB=../lib/libwx_baseu-$(WXV).a
WXDEPS=../bin/wx-config $(BASELIB)

if cygwin
$(BASELIB) ../bin/wx-config:	$(srcdir)/../wxWidgets/wxWidgets_revision
	$(TRACE)@cd ../wxWidgets && $(MAKE) install
else !cygwin
# When I build wxWidgets locally I *ALWAYS* end up passing an explicit
# "--host=..." option to the configure script. Well that is always except
# when under cygwin in certain cases... A result of that is that
# the libraries get installed with names that include the host identity.
# The script here makes symbolic links from the host-qualified names from
# plain undecorated ones as mentioned by "wx-config --libs". Well actually
# if I build under raw cygwin that is not the case, so I disable this
# hack in that situation.

$(BASELIB):	../lib/libwx_baseu-$(WXV)-$(HOST).a
	$(TRACE)cd ../lib; \
	for x in *$(HOST).a; \
	do \
	  y=$${x%-$(HOST).a}.a; \
	  echo ln -s -f $$x $$y; \
	  ln -s -f $$x $$y; \
	done

../lib/libwx_baseu-$(WXV)-$(HOST).a ../bin/wx-config:	\
		$(srcdir)/../wxWidgets/wxWidgets_revision
	$(TRACE)@cd ../wxWidgets && $(MAKE) install
endif !cygwin

wxfontdemo$(EXEEXT): $(wxfontdemo_OBJECTS) $(wxfontdemo_DEPENDENCIES) $(WXDEPS)
	-$(RM) -f wxfontdemo$(EXEEXT)
	$(CXXLINKTO) $(DEST)wxfontdemo$(EXEEXT) $(wxfontdemo_OBJECTS) $(wxfontdemo_LDADD) $(AM_LIBS) $(LIBS) $(CONAP)
if !debug
if !darwin
	$(STRIP) wxfontdemo$(EXEEXT)
endif !darwin
endif !debug
if mac_framework
	$(srcdir)/create_bundle.sh wxfontdemo $(srcdir)
endif mac_framework

wxdvi$(EXEEXT): $(wxdvi_OBJECTS) $(wxdvi_DEPENDENCIES) $(WXDEPS)
	-$(RM) -f wxdvi$(EXEEXT)
	$(CXXLINKTO) $(DEST)wxdvi$(EXEEXT) $(wxdvi_OBJECTS) $(wxdvi_LDADD) $(AM_LIBS) $(LIBS) $(CONAP)
if !debug
if !darwin
	$(STRIP) wxdvi$(EXEEXT)
endif !darwin
endif !debug
if mac_framework
	$(srcdir)/create_bundle.sh wxdvi $(srcdir)
endif mac_framework

wxdemo$(EXEEXT): $(wxdemo_OBJECTS) $(wxdemo_DEPENDENCIES) $(WXDEPS)
	-$(RM) -f wxdemo$(EXEEXT)
	$(CXXLINKTO) $(DEST)wxdemo$(EXEEXT) $(wxdemo_OBJECTS) $(wxdemo_LDADD) $(AM_LIBS) $(LIBS) $(CONAP)
if !debug
if !darwin
	$(STRIP) wxdemo$(EXEEXT)
endif !darwin
endif !debug
if mac_framework
	$(srcdir)/create_bundle.sh wxdemo $(srcdir)
endif mac_framework

wxshowmathdemo$(EXEEXT): $(wxshowmathdemo_OBJECTS) $(wxshowmathdemo_DEPENDENCIES) $(WXDEPS)
	-$(RM) -f wxshowmathdemo$(EXEEXT)
	$(CXXLINKTO) $(DEST)wxshowmathdemo$(EXEEXT) $(wxshowmathdemo_OBJECTS) $(wxshowmathdemo_LDADD) $(AM_LIBS) $(LIBS) $(CONAP)
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

csl$(EXEEXT): $(csl_OBJECTS) $(csl_DEPENDENCIES) $(FOXDEPS) $(WXDEPS) $(WINHELPERS)
	-$(RM) -f csl$(EXEEXT)
if windows
if gui
	$(CP) $(srcdir)/csl .
else !gui
	$(CP) $(srcdir)/csl-nogui .
endif !gui
if !cygwin
if cyg32
	cd $(with_cygbuild)/csl && make csl.exe
endif cyg32
	if test -x $(with_cygbuild)/csl/csl.exe; then $(CP) $(with_cygbuild)/csl/csl.exe cygwin-csl.exe; fi
if cyg64
	cd $(with_cygbuild64)/csl && make csl.exe
endif cyg64
	if test -x $(with_cygbuild64)/csl/csl.exe; then $(CP) $(with_cygbuild64)/csl/csl.exe cygwin64-csl.exe; fi
endif !cygwin
endif windows
	$(CXXLINKTO) $(CSLEXEDEF) $(DEST)csl$(EXEEXT) $(csl_OBJECTS) $(csl_LDADD) $(AM_LIBS) $(LIBS) $(WINAP)
if windows
if gui
	-$(RM) -f csl$(COM)
	$(CXXLINKTO) $(CSLCOMDEF) $(DEST)csl$(COM) $(csl_OBJECTS) $(csl_LDADD) $(AM_LIBS) $(LIBS) $(CONAP)
endif gui
	$(DLLTOOL) --def $(CSLEXEDEF) --output-lib libcslexe.a
	$(DLLTOOL) --def $(CSLCOMDEF) --output-lib libcslcom.a
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
else !wx
if mac_framework
	$(REZ) -t APPL -o csl $(srcdir)/mac.r
endif mac_framework

endif !wx

reduce$(EXEEXT): $(reduce_OBJECTS) $(reduce_DEPENDENCIES) $(FOXDEPS) \
			$(WXDEPS) $(generated_lisp) $(WINHELPERS)
	-$(RM) -f reduce$(EXEEXT)
if windows
# See "gui-or-not.txt" for an explanation of what this is about...
if gui
	$(CP) $(srcdir)/reduce .
else !gui
	$(CP) $(srcdir)/reduce-nogui .
endif !gui
if !cygwin
if cyg32
	cd $(with_cygbuild)/csl && make reduce.exe
endif cyg32
	if test -x $(with_cygbuild)/csl/reduce.exe; then $(CP) $(with_cygbuild)/csl/reduce.exe cygwin-reduce.exe; fi
if cyg64
	if test "x$(with_cygbuild64)" != "x"; then cd $(with_cygbuild64)/csl && make reduce.exe; fi
endif cyg64
	if test -x $(with_cygbuild64)/csl/reduce.exe; then $(CP) $(with_cygbuild64)/csl/reduce.exe cygwin64-reduce.exe; fi
endif !cygwin
endif windows
	$(CXXLINKTO) $(REDUCEEXEDEF) $(DEST)reduce$(EXEEXT) $(reduce_OBJECTS) $(reduce_LDADD) $(AM_LIBS) $(LIBS) $(WINAP)
if windows
if gui
	-$(RM) -f reduce$(COM)
	$(CXXLINKTO) $(REDUCECOMDEF) $(DEST)reduce$(COM) $(reduce_OBJECTS) $(reduce_LDADD) $(AM_LIBS) $(LIBS) $(CONAP)
endif gui
	$(DLLTOOL) --def $(REDUCEEXEDEF) --output-lib libreduceexe.a
	$(DLLTOOL) --def $(REDUCECOMDEF) --output-lib libreducecom.a
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
else !wx
if mac_framework
# on Darwin I want to go
# $(REZ) -t APPL -o reduce $(srcdir)/mac.r
# (and similarly for csl) after linking, so that the items concerned
# become clickable. Note that "mac.r" is copied directly from the
# FLTK distribution (www.fltk.org) and it is released there under
# LGPL with an array of extra permissions that mean that static
# linking is permitted and it is not necessary to be as careful
# to distribute copies of licenses as it is with the regular LGPL.
#
# Well to be a little more precise, I want to do that if the MacOS framework
# is available. on raw Darwin it will not be.
#
# Rez is now an rather old fashioned way of doing things. With wxWidgets I
# will replace this with stuff that creates application bundles.
	$(REZ) -t APPL -o reduce $(srcdir)/mac.r
endif mac_framework
endif !wx

bootstrapreduce$(EXEEXT): $(bootstrapreduce_OBJECTS) $(bootstrapreduce_DEPENDENCIES) $(FOXDEPS) $(WXDEPS)
	-$(RM) -f bootstrapreduce$(EXEEXT)
if windows
# See "gui-or-not.txt" for an explanation of what this is about...
	$(CP) $(srcdir)/bootstrapreduce .
if !cygwin
if cyg32
	cd $(with_cygbuild)/csl && make bootstrapreduce.exe
endif cyg32
	if test -x $(with_cygbuild)/csl/bootstrapreduce.exe; then $(CP) $(with_cygbuild)/csl/bootstrapreduce.exe cygwin-bootstrapreduce.exe; fi
if cyg64
	cd $(with_cygbuild64)/csl && make bootstrapreduce.exe;
endif cyg64
	if test -x $(with_cygbuild64)/csl/bootstrapreduce.exe; then $(CP) $(with_cygbuild64)/csl/bootstrapreduce.exe cygwin64-bootstrapreduce.exe; fi
endif !cygwin
endif windows
	$(CXXLINKTO) $(BOOTSTRAPREDUCEEXEDEF) $(DEST)bootstrapreduce$(EXEEXT) $(bootstrapreduce_OBJECTS) $(bootstrapreduce_LDADD) $(AM_LIBS) $(LIBS) $(CONAP)
if !debug
if !darwin
	$(STRIP) bootstrapreduce$(EXEEXT)
endif !darwin
endif !debug
if wx
if mac_framework
	$(srcdir)/create_bundle.sh bootstrapreduce $(srcdir) reduce
endif mac_framework
else !wx
if mac_framework
	$(REZ) -t APPL -o bootstrapreduce $(srcdir)/mac.r
endif mac_framework
endif !wx
if windows
	$(DLLTOOL) --def $(BOOTSTRAPREDUCEEXEDEF) --output-lib libbootstrapreduce.a
endif windows

fwindemo$(EXEEXT): $(fwindemo_OBJECTS) $(fwindemo_DEPENDENCIES) $(FOXDEPS) $(WXDEPS) $(WINHELPERS)
	-$(RM) -f fwindemo$(EXEEXT)
if windows
if gui
	$(CP) $(srcdir)/fwindemo .
else !gui
	$(CP) $(srcdir)/fwindemo-nogui .
endif !gui
if !cygwin
if cyg32
	cd $(with_cygbuild)/csl && make fwindemo.exe
endif cyg32
	if test -x $(with_cygbuild)/csl/fwindemo.exe; then $(CP) $(with_cygbuild)/csl/fwindemo.exe cygwin-fwindemo.exe; fi
if cyg64
	cd $(with_cygbuild64)/csl && make fwindemo.exe;
endif cyg64
	if test -x $(with_cygbuild64)/csl/fwindemo.exe; then $(CP) $(with_cygbuild64)/csl/fwindemo.exe cygwin64-fwindemo.exe; fi
endif !cygwin
endif windows
	$(CXXLINKTO) $(DEST)fwindemo$(EXEEXT) $(fwindemo_OBJECTS) $(fwindemo_LDADD) $(AM_LIBS) $(LIBS) $(WINAP)
if windows
if gui
	-$(RM) -f fwindemo$(COM)
	$(CXXLINKTO) $(DEST)fwindemo$(COM) $(fwindemo_OBJECTS) $(fwindemo_LDADD) $(AM_LIBS) $(LIBS) $(CONAP)
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
	-$(RM) -f wxpsl$(EXEEXT)
	$(CXXLINKTO) $(DEST)wxpsl$(EXEEXT) $(wxpsl_OBJECTS) $(wxpsl_LDADD) $(AM_LIBS) $(LIBS) $(WINAP)
if windows
if gui
	-$(RM) -f wxpsl$(COM)
	$(CXXLINKTO) $(DEST)wxpsl$(COM) $(wxpsl_OBJECTS) $(wxpsl_LDADD) $(AM_LIBS) $(LIBS) $(CONAP)
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
	-$(RM) -f fontdemo$(EXEEXT)
	$(CXXLINKTO) $(DEST)fontdemo$(EXEEXT) $(fontdemo_OBJECTS) $(fontdemo_LDADD) $(AM_LIBS) $(LIBS) $(CONAP)
if !debug
if !darwin
	$(STRIP) fontdemo$(EXEEXT)
endif !darwin
endif !debug

foxdemo$(EXEEXT): $(foxdemo_OBJECTS) $(foxdemo_DEPENDENCIES) $(FOXDEPS)
	-$(RM) -f foxdemo$(EXEEXT)
	$(CXXLINKTO) $(DEST)foxdemo$(EXEEXT) $(foxdemo_OBJECTS) $(foxdemo_LDADD) $(AM_LIBS) $(LIBS) $(CONAP)
if !debug
if !darwin
	$(STRIP) foxdemo$(EXEEXT)
endif !darwin
endif !debug

showmathdemo$(EXEEXT): $(showmathdemo_OBJECTS) $(showmathdemo_DEPENDENCIES) $(FOXDEPS)
	-$(RM) -f showmathdemo$(EXEEXT)
	$(CXXLINKTO) $(DEST)showmathdemo$(EXEEXT) $(showmathdemo_OBJECTS) $(showmathdemo_LDADD) $(AM_LIBS) $(LIBS) $(CONAP)
if !debug
if !darwin
	$(STRIP) showmathdemo$(EXEEXT)
endif !darwin
endif !debug

endif fox

if gui
if windows
if !cygwin

csl$(COM):	csl.exe
## Recover from the removal of csl.com
	if test -f csl.com; then touch csl.com; else \
	  $(RM) -f csl.exe; \
	  $(MAKE) $(AM_MAKEFLAGS) csl.exe; \
	fi

reduce$(COM):	reduce.exe
## Recover from the removal of reduce.com
	if test -f reduce.com; then touch reduce.com; else \
	  $(RM) -f reduce.exe; \
	  $(MAKE) $(AM_MAKEFLAGS) reduce.exe; \
	fi

fwindemo$(COM):	fwindemo.exe
## Recover from the removal of fwindemo.com
	if test -f fwindemo.com; then touch fwindemo.com; else \
	  $(RM) -f fwindemo.exe; \
	  $(MAKE) $(AM_MAKEFLAGS) fwindemo.exe; \
	fi

wxpsl$(COM):	wxpsl.exe
## Recover from the removal of wxpsl.com
	if test -f wxpsl.com; then touch wxpsl.com; else \
	  $(RM) -f wxpsl.exe; \
	  $(MAKE) $(AM_MAKEFLAGS) wxpsl.exe; \
	fi

endif !cygwin
endif windows
endif gui

# Here you could take the view that I am lazy in that I take
# just one file in the font directory as a signature that it has been
# built. If I was keener I would put in rules that allowed the
# fonts to be updated if any other font was lost or became out of date.

reduce.$(fontsdir)/$(samplefont):	$(srcdir)/fonts
if wx
if mac_framework
	echo reduce.wxfonts not used on the Mac with wxWidgets
else !mac_framework
	-$(TRACE)$(RM) -rf reduce.$(fontsdir)
	-mkdir -p reduce.$(fontsdir)
	$(CP) $(srcdir)/$(fontsdir)/README reduce.$(fontsdir)/README.BaKoMa
	$(CP) $(srcdir)/$(fontsdir)/BaKoMa-AMS.Fonts reduce.$(fontsdir)
	$(CP) $(srcdir)/$(fontsdir)/BaKoMa-CM.Fonts reduce.$(fontsdir)
	$(CP) $(srcdir)/$(fontsdir)/README.news reduce.$(fontsdir)/README.news.BaKoMa
	$(CP) $(srcdir)/$(fontsdir)/LICENCE reduce.$(fontsdir)/LICENCE.BaKoMa
if wx
# The Latin Modern (and Latin Modern Maths) fonts might well replace the
# BaKoMa ones for my purposes... At present their inclusion here is an
# experiment. Note that although I may distribute them as part of Reduce
# I must ensure that users know that they do not have the right to separate
# out the fonts for separate use. Also I should observe that the original
# distribution that I used is in the csl/support-packages directory of a full
# reduce file-set.
	$(CP) $(srcdir)/$(fontsdir)/MANIFEST-Latin-Modern.txt reduce.$(fontsdir)/MANIFEST-Latin-Modern.txt
	$(CP) $(srcdir)/$(fontsdir)/README-Latin-Modern.txt reduce.$(fontsdir)/README-Latin-Modern.txt
	$(CP) $(srcdir)/$(fontsdir)/README-Latin-Modern-Math.txt reduce.$(fontsdir)/README-Latin-Modern-Math.txt
endif wx
	$(CP) $(srcdir)/$(fontsdir)/*.ttf reduce.$(fontsdir)
# At present the only CM Unicode font I will copy across is CMTT.
# I will still need and use the BaKoMa fonts for CMSY, CMEX and MSAM etc
# special characters when typesetting high quality mathematics..
	$(CP) $(srcdir)/cm-unicode/LICENSE reduce.$(fontsdir)/LICENSE.cm-unicode
	$(CP) $(srcdir)/cm-unicode/README reduce.$(fontsdir)/README.cm-unicode
	$(CP) $(srcdir)/cm-unicode/cmuntt.otf reduce.$(fontsdir)
if windows
# With Windows I will want a .ttf version for any time I am using gdiplus.
# But when I am not the original .otf version might be better.
	$(CP) $(srcdir)/cm-unicode/cmuntt.ttf reduce.$(fontsdir)
endif windows
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
	-$(TRACE)$(RM) -rf reduce.$(fontsdir)
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
	chmod +x reduce.$(fontsdir)/*.ttf
endif !wx

if exeext

# The next section is to conspire with automake's treatment of extensions for
# executables (ie ".exe") so that eg "make reduce" will case "make reduce.exe" to
# happen. The use of parameter substitution to generate the plain targets is
# because in that case automake will not auto-map the target adding ".exe".



if cygwin
$(plain_csl):	csl.exe
	echo "make csl.exe is preferred"

$(plain_reduce):	reduce.exe
	echo "make reduce.exe is preferred"

$(plain_bootstrapreduce):	bootstrapreduce.exe
	echo "make bootstrapreduce.exe is preferred"

$(plain_fwindemo):	fwindemo.exe
	echo "make fwindemo.exe is preferred"

if wx
$(plain_wxpsl):	wxpsl.exe
	echo "make wxpsl.exe is preferred"
endif wx

else !cygwin
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
endif !cygwin
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

$(plain_dyndemo):	dyndemo.exe
	echo "make dyndemo.exe is preferred"

endif exeext

if cygwin
# on cygwin I scan to verify which DLLs are referenced by my main
# executables so that I can verify (eg) that they do not link to
# cygwin1.dll or any other library that is liable to impose license
# conditions that affect distribution rules.
report-dlls:	csl.exe bootstrapreduce.exe reduce.exe
	$(OBJDUMP) -p csl.exe | grep "DLL"
	$(OBJDUMP) -p bootstrapreduce.exe | grep "DLL"
	$(OBJDUMP) -p reduce.exe | grep "DLL"
endif cygwin

fwindemo_SOURCES=fwindemo.c $(fwin_sources)
if wx
wxpsl_SOURCES=wxpsl.cpp $(fwin_sources)
endif wx

termdemo_SOURCES=termdemo.c termed.c
termdemo_LIBS=

#
# Possibly unreasonably (but it is WHAT I DO!) image files for CSL live
# in the same directory as executables. Well actually it is more complicated
# that that. If the executable lives as .../bin/xxx then I will also look
# in .../share/xxx/xxx.img for an image, and on the Macintosh with my newer
# code I look in xxx.app/Contents/...
# But initially the images get built next to the executable.
#

if windows
image_files = csl.img reduce.img reduce.doc reduce.resources reduce.$(fontsdir)
else !windows
if mac_framework
image_files = csl.img reduce.img reduce.doc reduce.resources reduce.$(fontsdir) *.app
else
image_files = csl.img reduce.img reduce.doc reduce.resources reduce.$(fontsdir)
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
console_binaries = csl$(COM) reduce$(COM) wxpsl$(COM)
else !wx
console_binaries = csl$(COM) reduce$(COM)
endif !wx
noinstall_console_binaries = fwindemo$(COM)
else !gui
console_binaries =
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

win_specials = cygwin-reduce.exe cygwin-csl.exe cygwin-fwindemo.exe \
	not-under-cygwin.exe cygwin-isatty.exe cygwin64-isatty.exe csl \
	reduce fwindemo

generatedfiles=$(console_binaries) $(noinstall_console_binaries) \
	$(image_files) $(local_image_files) $(win_specials) \
	objtype* cl-wrap* makeheaders* *.def machineid.c *.dep $(INLINE_DEFS)

clean-local:
	-$(RM) -rf $(generatedfiles)
	
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
	-$(RM) -rf $(generatedfiles)
	
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
dyndef =
dyndep = libdyndemo.a
else !windows
if cygwin
dyndef =
dyndep = libdyndemo.a
else !cygwin
dyndef =
dyndep =
endif !cygwin
endif !windows

dynmodule.$(DLLEXT):	$(srcdir)/dynmodule.c $(dyndep)
	$(COMPILE_DLL) $(srcdir)/dynmodule.c $(dyndep) $(DEST)dynmodule.$(DLLEXT)

if canrun

if windows

# On windows I must avoid -mno-cygwin here if only because that is an option
# that no longer exists!

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
# programs are both fairly small and conservative.

objtype$(EXEEXT):	$(srcdir)/objtype.c
	gcc $(srcdir)/objtype.c -o objtype$(EXEEXT)

makeheaders$(EXEEXT):	$(srcdir)/makeheaders.c
	gcc $(srcdir)/makeheaders.c -o makeheaders$(EXEEXT)

endif !canrun

# The next line generates a small file that contains inforation about the
# object files used on this computer and the command used to compile
# simple C code. Note that machineid.c is made to depend on Makefile
# so if for any reason Makefile gets update so will it, and hence
# restart.o and the rest.

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

-include reduce.dep

reduce.dep:
	$(TRACE)touch reduce.dep

reduce.img:	reduce$(COM) $(reducedep) $(generated_lisp)
	-$(TRACE)$(RM) -rf reduce.img
if canrun
# I will make the REDUCE image file a directory rather than a single
# file... This is achieved by specifying its name here with a trailing "/",
# but I could have also have just made a directory with the right name
# before starting the build job.
	mkdir -p buildlogs
	./reduce$(COM) -w -z -Dno_init_file $(CYGSRC)/buildreduce.lsp \
		-D@srcdir=$(CYGSRC) -D@reduce=$(CYGSRC)/../.. \
		-- buildlogs/reduce.log \
		-j reduce.dep
# I copy an image into $(gensrc) with a view to keeping a copy thare that
# is up to date with my lastest build. There is a complication here that I
# only partially hack around. On the Mac I will often save image files within
# an application bundle, while on all other platforms they life in the
# directory adjacent to the executable file. I conditionally copy from both
# places here
	if test -f reduce.app/Contents/reduce.img; \
	then $(CP) reduce.app/Contents/reduce.img $(gensrc); \
	elif test -f reduce.img; then $(CP) reduce.img $(gensrc); fi
else !canrun
	echo Can not build reduce.img on this platform.
	echo Copying from $(gensrc)
	-$(RM) -rf reduce.img
	$(CP) -r $(gensrc)/reduce.img .
endif !canrun

# This is a temporary target "reduce.dir" to create the image as a directory
# rather than as a single file.

reduce.dir:	reduce$(COM) $(reducedep) $(generated_lisp)
	-$(TRACE)$(RM) -rf reduce.img
if canrun
# I will make the REDUCE image file a directory rather than a single
# file... This is achieved by specifying its name here with a trailing "/",
# but I could have also have just made a directory with the right name
# before starting the build job.
	mkdir -p buildlogs
	./reduce$(COM) -w -z -Dno_init_file $(CYGSRC)/buildreduce.lsp \
		-D@srcdir=$(CYGSRC) -D@reduce=$(CYGSRC)/../.. \
		-o ./reduce.img/ \
		-- buildlogs/reduce.log \
		-j reduce.dep
else !canrun
	echo Can not build reduce.img on this platform
	echo Copying from $(gensrc)
	-$(RM) -rf reduce.img
	$(CP) -r $(gensrc)/reduce.img .
endif !canrun

# "make bootstraprecompile which=<module-name>" and "make recompile which="
# recompile just one package, assuming everything else is properly up to
# date (at least if the image file exists at all) and they end up by
# stamping all files so that a subsequent "make test" etc will not cause
# unwanted extra recompilation.

bootstraprecompile:
if canrun
	if !test -f bootstrapreduce.img; then make bootstrapreduce.img; fi
	mkdir -p buildlogs
	./bootstrapreduce$(EXEEXT) -v -w $(CYGSRC)/recompile.red \
		-Dno_init_file -D@srcdir=$(CYGSRC) -D@reduce=$(CYGSRC)/../.. \
		-l buildlogs/$(which).log -Dwhich=$(which)
	make -t bootstrapreduce.img > /dev/null
else !canrun
	echo Can not build images on this platfrom
endif !canrun

recompile:
if canrun
	if !test -f reduce.img; then make reduce.img; fi
	mkdir -p buildlogs
	./reduce$(COM) -v -w $(CYGSRC)/recompile.red \
		-Dno_init_file -D@srcdir=$(CYGSRC) -D@reduce=$(CYGSRC)/../.. \
		-l buildlogs/$(which).log -Dwhich=$(which)
	make -t reduce.img > /dev/null
else !canrun
	echo Can not build images on this platfrom
endif !canrun

# Copy HTML help files in a directory reduce.doc.
# This rule lets the index file stand for all others, so if others
# were to get lost or corrupted they would not be automatically restored.
reduce.doc/index.html:
	-$(RM) -rf reduce.doc
	mkdir -p reduce.doc
	$(CP) -r $(srcdir)/../reduce.doc/*.html reduce.doc
	$(CP) -r $(srcdir)/../reduce.doc/*.tex reduce.doc
	$(CP) -r $(srcdir)/../reduce.doc/*.gif reduce.doc
	$(CP) -r $(srcdir)/../reduce.doc/*.txt reduce.doc

$(AWKFILES):	$(srcdir)/../../packages/redlog/mma/mma.awk \
	$(srcdir)/../../packages/redlog/qepcad/qepcad.awk
	-mkdir -p reduce.resources
	$(CP) $(srcdir)/../../packages/redlog/mma/mma.awk reduce.resources
	$(CP) $(srcdir)/../../packages/redlog/qepcad/qepcad.awk reduce.resources

-include bootstrapreduce.dep

bootstrapreduce.dep:
	$(TRACE)touch bootstrapreduce.dep

bootstrapreduce.img:	bootstrapreduce$(EXEEXT) $(bootstrapreducedep)
	-$(TRACE)$(RM) -f bootstrapreduce.img
if canrun
	mkdir -p buildlogs
	./bootstrapreduce$(EXEEXT) -w -z -Dno_init_file \
		$(CYGSRC)/buildreduce.lsp -D@srcdir=$(CYGSRC) -D@reduce=$(CYGSRC)/../.. \
		-- buildlogs/bootstrapreduce.log \
		-j bootstrapreduce.dep
	if test -f bootstrapreduce.app/Contents/bootstrapreduce.img; \
	then $(CP) bootstrapreduce.app/Contents/bootstrapreduce.img $(gensrc); \
	elif test -f bootstrapreduce.img; \
	then $(CP) bootstrapreduce.img $(gensrc); fi
else !canrun
	echo Can not build bootstrapreduce.img on this platform
	echo Copying from $(gensrc)
	-$(RM) -rf bootstrapreduce.img
	$(CP) $(gensrc)/bootstrapreduce.img .
endif !canrun

profile:	bootstrapreduce.img
if canrun
	$(TRACE)mkdir -p buildlogs
	./bootstrapreduce$(EXEEXT) -w -Dno_init_file \
		$(CYGSRC)/profile.red -D@srcdir=$(CYGSRC) -D@reduce=$(CYGSRC)/../.. \
		-Dcpulimit=$(cpulimit) -Dconslimit=$(conslimit) \
		-- buildlogs/profile.log
# I preserve the previous profile.dat as profile.dat.old
	-$(CP) $(gensrc)/profile.dat $(gensrc)/profile.dat.old
	mv profile.dat $(gensrc)
else !canrun
	echo Can not profile on this platform
endif !canrun

prof-inst:	profile.dat
	$(CP) profile.dat $(gensrc)
	-$(RM) -f profile.dat

$(gensrc)/profile.dat:	$(srcdir)/../generated-c/profile.dat
	-$(TRACE)mkdir -p $(gensrc)
	$(CP) $(srcdir)/../generated-c/profile.dat $(gensrc)

c-code:	$(gensrc)/make.stamp

$(gensrc)/make.stamp:	$(bootstrapreducedep) $(gensrc)/profile.dat \
		$(srcdir)/make-c-code.red
	@$(TRACE)$(RM) -f $(gensrc)/make.tmp
	@touch $(gensrc)/make.tmp
	mkdir -p buildlogs
# I want the C code to be created from a version of the boostrap code
# that has ALL the inline definitions available. To ensure that things are
# clean I discard any old inline definition database. To ensure that even
# forward references to inlines are expanded I do the build twice.
	if test -f $(INLINE_DEFS); \
	then mv $(INLINE_DEFS) old-inline-defs.dat; \
	else touch old-inline-defs.dat; \
	fi
	touch $(INLINE_DEFS)
	$(RM) -f bootstrapreduce.img
	$(MAKE) $(AM_MAKEFLAGS) bootstrapreduce.img
	if diff $(INLINE_DEFS) old-inline-defs.dat > /dev/null; \
	then \
	  echo "Inline definitions have not changed"; \
        else \
	  $(RM) bootstrapreduce.img; \
	  $(MAKE) $(AM_MAKEFLAGS) bootstrapreduce.img; \
	fi
	./bootstrapreduce$(EXEEXT) -w -Dno_init_file $(CYGSRC)/make-c-code.red \
		-D@destdir=$(CYGSRC)/../../cslbuild/generated-c \
		-Dhow_many=$(how_many) -Dsize_per_file=$(size_per_file) \
		-- buildlogs/c-code.log
# If the inline-defs file has not changed I will restore the old one. Its
# contents will be just what I would have seen in the new one but its
# datestamp will be older and that can help avoid unnecessary rebuilding.
	if diff $(INLINE_DEFS) old-inline-defs.dat > /dev/null; \
	then \
	  echo "Inline definitions have not changed"; \
	  mv old-inline-defs.dat $(INLINE_DEFS); \
	else \
	  $(RM) old-inline-defs.dat; \
	fi
	@mv $(gensrc)/make.tmp $(gensrc)/make.stamp

# The following rule can lead to race conditions with parallel make if
# several generated files have been deleted but not the make.stamp file.
# You should be able to recover reliably by going "make clean" followed
# by "make".
# See section 27.9 of the Automake manual where it discusses
# adding a lock to cope with any races.. Well maybe soon while I am about
# it I will implement what they suggest! Soon.

$(generated_objects):	$(gensrc)/make.stamp $(bootstrapreducedep) \
		$(gensrc)/profile.dat

# Whenever I rebuild the generated C files I will forcibly recompile
# all of them. This is because otherwise any versions that were
# up to date before the regeneration will NOT get spotted as in need
# of compilation even though they have changed.

# I believe there is a potential race (with "make -j") if say u01.o is
# out of date in a simple way and starts to get compiled, but while that
# is going on a missing version of say u33.lsp causes the rule here to
# trigger... and in the process re-create a new version of u05.c. I try
# to deal with that by deleting all the *.o files just in case some
# parallel process has slotted one in just when I did not want that!
# Well it is even worse - the main reduce executable can become out
# of date... but fail to be rebuilt. So here I will forcibly remake that.
# I rather hope that the delay while C-code is re-created is long enough
# to let any previous steps complete.

standard-c-code $(generated_sources_deps) $(generated_lisp):	$(gensrc)/make.stamp
## Recover from the removal of $@
	if test -f $@; then touch $@; else \
	  $(RM) -f $(gensrc)/make.stamp; \
	  $(MAKE) $(AM_MAKEFLAGS) $(gensrc)/make.stamp; \
	  $(RM) -f $(generated-objects); \
	  $(MAKE) $(AM_MAKEFLAGS) reduce; \
	fi


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

# j-code will only be triggered manually.

j-code:	bootstrapreduce.img $(gensrc)/profile.dat
if canrun
	mkdir -p buildlogs
	mkdir -p $(CYGSRC)/../../cslbuild/generated-java
	./bootstrapreduce$(EXEEXT) -w -Dno_init_file $(CYGSRC)/make-j-code.red \
		-D@destdir=$(CYGSRC)/../../cslbuild/generated-java \
		-Dhow_many=$(how_many) -Dsize_per_file=$(size_per_file) \
		-- buildlogs/j-code.log
else !canrun
	echo Can not generate Java code on this platfrom
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
		-Dno_init_file -D@srcdir=$(CYGSRC) -D@reduce=$(CYGSRC)/../.. \
		-- testlogs/testslow.log
	./bootstrapreduce$(EXEEXT) -v -w $(CYGSRC)/checkall.red \
		-Dno_init_file -D@srcdir=$(CYGSRC) -D@reduce=$(CYGSRC)/../.. \
		-- testlogs/checkslow.log
else !canrun
	echo Can not run tests on this platfrom
endif !canrun

testall:	reduce.img
if canrun
	mkdir -p testlogs
	./reduce$(COM) -v -w $(CYGSRC)/testall.red \
		-Dno_init_file -D@srcdir=$(CYGSRC) -D@reduce=$(CYGSRC)/../.. \
		-Dcpulimit=$(cpulimit) -Dconslimit=$(conslimit) \
		-- testlogs/testreduce.log
	./reduce$(COM) -v -w $(CYGSRC)/checkall.red \
		-Dno_init_file -D@srcdir=$(CYGSRC) -D@reduce=$(CYGSRC)/../.. \
		-- testlogs/checkall.log
else !canrun
	echo Can not run tests on this platfrom
endif !canrun

testslow1:	bootstrapreduce.img
if canrun
	mkdir -p testlogs
	./bootstrapreduce$(EXEEXT) -v -w $(CYGSRC)/testall.red \
		-Dno_init_file -D@srcdir=$(CYGSRC) -D@reduce=$(CYGSRC)/../.. \
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
		-Dno_init_file -D@srcdir=$(CYGSRC) -D@reduce=$(CYGSRC)/../.. \
		-Dcpulimit=30000 -Dconslimit=$(conslimit) \
		-- testlogs/countreduce.log



endif valgrind

test1:	reduce.img
if canrun
	mkdir -p testlogs
	./reduce$(COM) -v -w $(CYGSRC)/testall.red \
		-Dno_init_file -D@srcdir=$(CYGSRC) -D@reduce=$(CYGSRC)/../.. \
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
		-Dno_init_file -D@srcdir=$(CYGSRC) -D@reduce=$(CYGSRC)/../.. \
		-- testlogs/count$(which).log -Dwhich=$(which) \
		-Dcpulimit=30000 -Dconslimit=$(conslimit)

endif valgrind

checkall:	reduce.img
if canrun
	mkdir -p testlogs
	./reduce$(COM) -v -w $(CYGSRC)/checkall.red \
		-Dno_init_file -D@srcdir=$(CYGSRC) -D@reduce=$(CYGSRC)/../.. \
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
	$(TRACE)touch csl.dep

csl.img:	csl$(COM) $(csldep)
	-$(TRACE)$(RM) -rf csl.img
if canrun
	mkdir -p buildlogs
	./csl$(COM) -w -v -z "$(CYGSRC)/buildcsl.lsp" \
		-D@cslbase="$(CYGSRC)" \
		-- buildlogs/csl.img.log \
		-j csl.dep
	if test -f csl.app/Contents/csl.img; \
	then $(CP) -r csl.app/Contents/csl.img $(gensrc); \
	elif test -f csl.img; then $(CP) -r csl.img $(gensrc); fi
else !canrun
	echo Can not create csl.img on this platfrom
	echo Copying from $(gensrc)
	-$(RM) -rf csl.img
	$(CP) -r $(gensrc)/csl.img .
endif !canrun


csl.dir:	csl$(COM) $(csldep)
	-$(TRACE)$(RM) -rf csl.img
if canrun
	mkdir -p buildlogs
	./csl$(COM) -w -v -z "$(CYGSRC)/buildcsl.lsp" \
		-o ./csl.img/ -D@cslbase="$(CYGSRC)" \
		-- buildlogs/csl.img.log \
		-j csl.dep
else !canrun
	echo Can not create csl.img on this platfrom
	echo Copying from $(gensrc)
	-$(RM) -rf csl.img
	$(CP) -r $(gensrc)/csl.img .
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
	-$(RM) -f reduce-windows-$(shell date +%Y%m%d).zip
	-$(RM) -rf reduce-$(NAME)-$(shell date +%Y%m%d)
	mkdir -p reduce-$(NAME)-$(shell date +%Y%m%d)
	$(CP) -r reduce.exe reduce.com reduce.img reduce.doc reduce.fonts reduce-$(NAME)-$(shell date +%Y%m%d)
	zip -r reduce-$(NAME)-$(shell date +%Y%m%d).zip reduce-$(NAME)-$(shell date +%Y%m%d)
ARCHIVE=reduce-$(NAME)-$(shell date +%Y%m%d).zip
else !windows
	-$(RM) -f reduce-$(NAME)-$(shell date +%Y%m%d).tar.bz2
	-$(RM) -rf reduce-$(NAME)-$(shell date +%Y%m%d)
	mkdir -p reduce-$(NAME)-$(shell date +%Y%m%d)
	$(CP) -r reduce reduce.img reduce.doc reduce.fonts reduce-$(NAME)-$(shell date +%Y%m%d)
	tar cfj reduce-$(NAME)-$(shell date +%Y%m%d).tar.bz2 reduce-$(NAME)-$(shell date +%Y%m%d)
ARCHIVE=reduce-$(NAME)-$(shell date +%Y%m%d).tar.bz2 
endif !windows
	if test "x$(savedest)" != "x"; then scp $(ARCHIVE) $(savedest); fi



showhost:
	echo host = $(HOST)

# end of Makefile

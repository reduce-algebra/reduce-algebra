## process this file with automake to create Makefile.in

## and then use autoconf to create ./configure. Finally run that
## to build your usable Makefile (probably in another directory)

# CSL and REDUCE build sequences


# Set up ways to refer to files in the main Reduce source tree.

cslbase = $(srcdir)
csl = $(cslbase)/..
reduce = $(csl)/..
cslbuild = $(reduce)/cslbuild
packages = $(reduce)/packages
generic = $(reduce)/generic

ACLOCAL_AMFLAGS = -I m4

# I want to be able to see what gets built and why, so here is a GNU
# make trace facility.

# A user may go "make CSLFLAGS=-g" to force "-g" into built-times Lisp flags...

TRACE = $(warning TRACE: $@ :: $?)

AM_CPPFLAGS = $(TRACE)
AM_LDFLAGS  = $(TRACE)

reduce_CPPFLAGS = $(TRACE) -DNO_BYTECOUNT=1
#
# At least on a temporary basis I will make CSL keep profiling
# information. This is because that will help me debug the profile
# collection code and is acceptable because maybe only very few people use
# raw CSL and anyway performance is "good enough" for most purposes
# regardless.
#
#csl_CPPFLAGS    = $(TRACE) -DNO_BYTECOUNT=1
csl_CPPFLAGS    = $(TRACE)
# For at least a while I will NOT warn about unused (static) functions, because
# I have rather a lot of that that are to do with support for short floats.
# This is just for flatcsl where the program is all compiled as a single
# compilation unit, so "spurious" warnings are especially bulky.
flatcsl_CPPFLAGS = $(TRACE) -Wno-unused-function

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
plain_flatcsl = flatcsl
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
plain_wxfontdemo1 = wxfontdemo1
plain_wxdvi = wxdvi
plain_wxshowmath = wxshowmath
plain_wxshowmathdemo = wxshowmathdemo
plain_dyndemo = dyndemo
plain_zlibdemo = zlibdemo
plain_gctest = gctest
else !exeext
plain_csl = csl.unnecessary.except.on.windows
plain_flatcsl = csl.unnecessary.except.on.windows
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
plain_wxfontdemo1 = wxfontdemo1.unnecessary.except.on.windows
plain_wxdvi = wxdvi.unnecessary.except.on.windows
plain_wxshowmath = wxshowmath.unnecessary.except.on.windows
plain_wxshowmathdemo = wxshowmathdemo.unnecessary.except.on.windows
plain_dyndemo = dyndemo.unnecessary.except.on.windows
plain_zlibdemo = zlibdemo.unnecessary.except.on.windows
plain_gctest = gctest.unnecessary.except.on.windows
endif !exeext

.PHONY: $(plain_csl)
.PHONY: $(plain_flatcsl)
.PHONY: $(plain_reduce)
.PHONY: $(plain_bootstrapreduce)
.PHONY: $(plain_fwindemo)
.PHONY: $(plain_wxpsl)
.PHONY: $(plain_foxdemo)
.PHONY: $(plain_fontdemo)
.PHONY: $(plain_showmathdemo)
.PHONY: $(plain_wxdemo)
.PHONY: $(plain_wxfontdemo)
.PHONY: $(plain_wxfontdemo1)
.PHONY: $(plain_wxdvi)
.PHONY: $(plain_wxshowmath)
.PHONY: $(plain_wxshowmathdemo)
.PHONY: $(plain_termdemo)
.PHONY: $(plain_dyndemo)
.PHONY: $(plain_zlibdemo)
.PHONY: $(plain_gctest)

.PHONY:	bootstraprecompile
.PHONY:	recompile
.PHONY:	profile
.PHONY:	prof-inst
.PHONY:	c-code
.PHONY:	just-c-code
.PHONY:	standard-c-code
.PHONY:	partial-c-code
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
CYGSRC = $(shell cygpath -m $(cslbase))
else !cygpath
CYGSRC = $(cslbase)
endif !cygpath
CYGREDUCE = $(CYGSRC)/../..

if cygwin
EXE=

if cyg32
CYG=$(cslbuild)/cyg32
$(CYG):	$(cslbase)/other-cygwin.cpp
	i686-w64-mingw32-g++ -O3 -DFORCE32 $(cslbase)/other-cygwin.cpp -o $(CYG)
	i686-w64-mingw32-strip $(CYG)
else !cyg32
if cyg64
CYG=$(cslbuild)/cyg64
$(CYG):	$(cslbase)/other-cygwin.cpp
	i686-w64-mingw32-g++ -O3 -DFORCE64 $(cslbase)/other-cygwin.cpp -o $(CYG)
	i686-w64-mingw32-strip $(CYG)
endif cyg64
endif !cyg32

else !cygwin
EXE=$(EXEEXT)
endif !cygwin

if wx
WXC=../bin/wx-config
BUILT_SOURCES = $(WXC)
MY_CPPFLAGS := $(shell ../bin/wx-config --cppflags 2>/dev/null)
MY_CFLAGS   := $(shell ../bin/wx-config --cflags 2>/dev/null)
MY_CXXFLAGS := $(shell ../bin/wx-config --cxxflags 2>/dev/null)
MY_LIBS     := $(shell ../bin/wx-config --libs --static 2>/dev/null)

AM_CPPFLAGS     += $(MY_CPPFLAGS)
reduce_CPPFLAGS += $(MY_CPPFLAGS)
csl_CPPFLAGS    += $(MY_CPPFLAGS)
# For at least a while I will NOT warn about unused (static) functions, because
# I have rather a lot of that that are to do with support for short floats.
flatcsl_CPPFLAGS    += $(MY_CPPFLAGS)
AM_CFLAGS        = $(MY_CFLAGS)
AM_CXXFLAGS      = $(MY_CXXFLAGS)
AM_LIBS          = $(MY_LIBS)

else !wx
WXC=
endif !wx

AM_CPPFLAGS     += -DBINDIR=$(bindir) -DPKGDATADIR=$(pkgdatadir)
reduce_CPPFLAGS += -DBINDIR=$(bindir) -DPKGDATADIR=$(pkgdatadir)
csl_CPPFLAGS    += -DBINDIR=$(bindir) -DPKGDATADIR=$(pkgdatadir)
flatcsl_CPPFLAGS    += -DBINDIR=$(bindir) -DPKGDATADIR=$(pkgdatadir)

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
wxdemotarget = wxdemo$(EXEEXT) wxfontdemo$(EXEEXT) wxfontdemo1$(EXEEXT) wxdvi$(EXEEXT) wxshowmath$(EXEEXT) wxshowmathdemo$(EXEEXT)
else !wx
wxdemotarget =
endif !wx

if wx
noinst_PROGRAMS = csl$(EXEEXT) reduce$(EXEEXT) wxpsl$(EXEEXT)
else !wx
noinst_PROGRAMS = csl$(EXEEXT) reduce$(EXEEXT)
endif !wx
if mac_framework
noinst_PROGRAMS += bootstrapreduce$(EXEEXT)
check_PROGRAMS = flatcsl$(EXEEXT) fwindemo$(EXEEXT) \
	termdemo$(EXEEXT) $(foxdemotarget) \
	zlibdemo$(EXEEXT) $(wxdemotarget)
else !mac_framework
noinst_PROGRAMS = bootstrapreduce$(EXEEXT)
check_PROGRAMS = flatcsl$(EXEEXT) fwindemo$(EXEEXT) \
	termdemo$(EXEEXT) $(foxdemotarget) \
	dyndemo$(EXEEXT) zlibdemo$(EXEEXT) $(wxdemotarget)
endif !mac_framework

if boehm
check_PROGRAMS += gctest$(EXEEXT)
endif boehm

if mac_framework
REDUCE_IMG=reduce.app/Contents/MacOS/reduce.img
else !mac_framework
REDUCE_IMG=reduce.img
endif !mac_framework

all-local:	csl.img $(REDUCE_IMG)

core_sources = arith01.cpp arith02.cpp arith03.cpp arith04.cpp arith05.cpp \
		arith06.cpp arith07.cpp arith08.cpp arith09.cpp arith10.cpp \
		arith11.cpp arith12.cpp arith13.cpp arith14.cpp isprime.cpp \
                bytes1.cpp \
		char.cpp cslmpi.cpp eval1.cpp eval2.cpp eval3.cpp eval4.cpp \
		fns1.cpp fns2.cpp fns3.cpp inthash.cpp print.cpp cslread.cpp \
		restart.cpp lisphash.cpp newhash.cpp serialize.cpp sysfwin.cpp

# Thie little rule is because from time to time I really want to see the
# expanded version of a C++ file (ie after C++ macroexpansion has taken place).
# This gives a target filename.cxx for that. The reason I want to do this
# is that sometimes I wish to use single stepping in a debugger wihin code
# that is expanded from a messy C macro. I use astyle to fix up the layout
# of the expanded code and then sed to comment out the lines that could
# cause the debugger to refer back to the original version of the source.
# This letter so that if I then copy foo.cxx to foo.cpp in my build directory
# and recompile using the expanded version I can use a debugger and see
# line numbers that relate to the expanded version...

%.cxx:	%.cpp
	$(AM_V_CXX)$(CXXCOMPILE) -E -o $@ $<
	astyle -n $@
	sed -e '/^#/ s:#:// #:' < $@ > $@.tmp
	mv $@.tmp $@

# You can go "make foo.s" to get an assembly-code version of the compiled
# form of foo.

%.s:	%.cpp
	$(AM_V_CXX)$(CXXCOMPILE) -S -o $@ $<

demo_sources = csl.cpp fasl.cpp cslgc.cpp preserve.cpp

undemo_sources = csl.cpp fasl.cpp cslgc.cpp preserve.cpp

# If I am building under FOX then the main parts of material from
# fwin.cpp and termed.cpp get picked up from the FOX library.
# If wxWidgets is in use I have an alternate versions called wxfwin.cpp 
# but termed.cpp can be used unchanged (but from source in this directory
# not in the FOX directory). When I do not have a GUI at all I use both
# fwin.cpp and termed.cpp from this directory.

if fox
fwin_sources =
else !fox
if wx
fwin_sources = wxfwin.cpp wxterminal.cpp termed.cpp
else !wx
fwin_sources = fwin.cpp termed.cpp
endif !wx
endif !fox

gensrc=$(cslbuild)/generated-c

INLINE_DEFS = $(gensrc)/inline-defs.dat

$(INLINE_DEFS):
	touch $(INLINE_DEFS)

generated_sources =             u01.cpp \
		u02.cpp u03.cpp \
		u04.cpp u05.cpp \
		u06.cpp u07.cpp \
		u08.cpp u09.cpp \
		u10.cpp u11.cpp \
		u12.cpp u13.cpp \
		u14.cpp u15.cpp \
		u16.cpp u17.cpp \
		u18.cpp u19.cpp \
		u20.cpp u21.cpp \
		u22.cpp u23.cpp \
		u24.cpp u25.cpp \
		u26.cpp u27.cpp \
		u28.cpp u29.cpp \
		u30.cpp u31.cpp \
		u32.cpp u33.cpp \
		u34.cpp u35.cpp \
		u36.cpp u37.cpp \
		u38.cpp u39.cpp \
		u40.cpp u41.cpp \
		u42.cpp u43.cpp \
		u44.cpp u45.cpp \
		u46.cpp u47.cpp \
		u48.cpp u49.cpp \
		u50.cpp u51.cpp \
		u52.cpp u53.cpp \
		u54.cpp u55.cpp \
		u56.cpp u57.cpp \
		u58.cpp u59.cpp \
		u60.cpp
generated_sources_deps =             $(gensrc)/u01.cpp \
		$(gensrc)/u02.cpp $(gensrc)/u03.cpp \
		$(gensrc)/u04.cpp $(gensrc)/u05.cpp \
		$(gensrc)/u06.cpp $(gensrc)/u07.cpp \
		$(gensrc)/u08.cpp $(gensrc)/u09.cpp \
		$(gensrc)/u10.cpp $(gensrc)/u11.cpp \
		$(gensrc)/u12.cpp $(gensrc)/u13.cpp \
		$(gensrc)/u14.cpp $(gensrc)/u15.cpp \
		$(gensrc)/u16.cpp $(gensrc)/u17.cpp \
		$(gensrc)/u18.cpp $(gensrc)/u19.cpp \
		$(gensrc)/u20.cpp $(gensrc)/u21.cpp \
		$(gensrc)/u22.cpp $(gensrc)/u23.cpp \
		$(gensrc)/u24.cpp $(gensrc)/u25.cpp \
		$(gensrc)/u26.cpp $(gensrc)/u27.cpp \
		$(gensrc)/u28.cpp $(gensrc)/u29.cpp \
		$(gensrc)/u30.cpp $(gensrc)/u31.cpp \
		$(gensrc)/u32.cpp $(gensrc)/u33.cpp \
		$(gensrc)/u34.cpp $(gensrc)/u35.cpp \
		$(gensrc)/u36.cpp $(gensrc)/u37.cpp \
		$(gensrc)/u38.cpp $(gensrc)/u39.cpp \
		$(gensrc)/u40.cpp $(gensrc)/u41.cpp \
		$(gensrc)/u42.cpp $(gensrc)/u43.cpp \
		$(gensrc)/u44.cpp $(gensrc)/u45.cpp \
		$(gensrc)/u46.cpp $(gensrc)/u47.cpp \
		$(gensrc)/u48.cpp $(gensrc)/u49.cpp \
		$(gensrc)/u50.cpp $(gensrc)/u51.cpp \
		$(gensrc)/u52.cpp $(gensrc)/u53.cpp \
		$(gensrc)/u54.cpp $(gensrc)/u55.cpp \
		$(gensrc)/u56.cpp $(gensrc)/u57.cpp \
		$(gensrc)/u58.cpp $(gensrc)/u59.cpp \
		$(gensrc)/u60.cpp
generated_objects =           reduce-u01.$(OBJEXT) \
		reduce-u02.$(OBJEXT) reduce-u03.$(OBJEXT) \
		reduce-u04.$(OBJEXT) reduce-u05.$(OBJEXT) \
		reduce-u06.$(OBJEXT) reduce-u07.$(OBJEXT) \
		reduce-u08.$(OBJEXT) reduce-u09.$(OBJEXT) \
		reduce-u10.$(OBJEXT) reduce-u11.$(OBJEXT) \
		reduce-u12.$(OBJEXT) reduce-u13.$(OBJEXT) \
		reduce-u14.$(OBJEXT) reduce-u15.$(OBJEXT) \
		reduce-u16.$(OBJEXT) reduce-u17.$(OBJEXT) \
		reduce-u18.$(OBJEXT) reduce-u19.$(OBJEXT) \
		reduce-u20.$(OBJEXT) reduce-u21.$(OBJEXT) \
		reduce-u22.$(OBJEXT) reduce-u23.$(OBJEXT) \
		reduce-u24.$(OBJEXT) reduce-u25.$(OBJEXT) \
		reduce-u26.$(OBJEXT) reduce-u27.$(OBJEXT) \
		reduce-u28.$(OBJEXT) reduce-u29.$(OBJEXT) \
		reduce-u30.$(OBJEXT) reduce-u31.$(OBJEXT) \
		reduce-u32.$(OBJEXT) reduce-u33.$(OBJEXT) \
		reduce-u34.$(OBJEXT) reduce-u35.$(OBJEXT) \
		reduce-u36.$(OBJEXT) reduce-u37.$(OBJEXT) \
		reduce-u38.$(OBJEXT) reduce-u39.$(OBJEXT) \
		reduce-u40.$(OBJEXT) reduce-u41.$(OBJEXT) \
		reduce-u42.$(OBJEXT) reduce-u43.$(OBJEXT) \
		reduce-u44.$(OBJEXT) reduce-u45.$(OBJEXT) \
		reduce-u46.$(OBJEXT) reduce-u47.$(OBJEXT) \
		reduce-u48.$(OBJEXT) reduce-u49.$(OBJEXT) \
		reduce-u50.$(OBJEXT) reduce-u51.$(OBJEXT) \
		reduce-u52.$(OBJEXT) reduce-u53.$(OBJEXT) \
		reduce-u54.$(OBJEXT) reduce-u55.$(OBJEXT) \
		reduce-u56.$(OBJEXT) reduce-u57.$(OBJEXT) \
		reduce-u58.$(OBJEXT) reduce-u59.$(OBJEXT) \
		reduce-u60.$(OBJEXT)
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
		stubs.cpp

flatcsl_SOURCES = flatcsl.cpp

bootstrapreduce_SOURCES = $(core_sources) $(undemo_sources) $(fwin_sources) \
		stubs.cpp

reduce_SOURCES = $(core_sources) $(demo_sources) $(fwin_sources) \
		$(generated_sources)

if windows
fwin_icon = fwin-icon.$(OBJEXT)
else !windows
fwin_icon =
endif !windows

if wx
fontsdir = wxfonts
if windows
samplefont=cmuntt.ttf
else !windows
samplefont=cmuntt.otf
endif !windows
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

AM_CPPFLAGS     += -Dfontsdir=reduce.$(fontsdir)
reduce_CPPFLAGS += -Dfontsdir=reduce.$(fontsdir)
csl_CPPFLAGS    += -Dfontsdir=reduce.$(fontsdir)
flatcsl_CPPFLAGS    += -Dfontsdir=reduce.$(fontsdir)

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

wxdemo_SOURCES = wxdemo.cpp wxfwin.cpp termed.cpp charmetrics.cpp
wxdemo_LDADD = $(fwin_icon)
wxdemo_DEPENDENCIES = $(fwin_icon) $(FONTDEP) $(WXC)

wxfontdemo_SOURCES = wxfontdemo.cpp charmetrics.cpp
wxfontdemo_LDADD = $(fwin_icon)
wxfontdemo_DEPENDENCIES = $(fwin_icon) $(FONTDEP) $(WXC)

wxfontdemo1_SOURCES = wxfontdemo1.cpp wxfwin.cpp termed.cpp charmetrics.cpp
wxfontdemo1_LDADD = $(fwin_icon)
wxfontdemo1_DEPENDENCIES = $(fwin_icon) $(FONTDEP) $(WXC)

wxdvi_SOURCES = wxdvi.cpp wxfwin.cpp termed.cpp
wxdvi_LDADD = $(fwin_icon)
wxdvi_DEPENDENCIES = $(fwin_icon) $(FONTDEP) $(WXC)

wxshowmath_SOURCES = wxshowmath.cpp wxfwin.cpp termed.cpp charmetrics.cpp unimaths.cpp
wxshowmath_LDADD = $(fwin_icon)
wxshowmath_DEPENDENCIES = $(fwin_icon) $(FONTDEP) $(WXC)

wxshowmathdemo_SOURCES = wxshowmathdemo.cpp wxfwin.cpp termed.cpp
wxshowmathdemo_LDADD = $(fwin_icon)
wxshowmathdemo_DEPENDENCIES = $(fwin_icon) $(FONTDEP) $(WXC)

AWKFILES=reduce.resources/mma.awk reduce.resources/qepcad.awk

if windows
DLLEXT=dll
else !windows
DLLEXT=so
endif !windows

dyndemo_SOURCES = dyndemo.cpp

if !windows
dyndemo_DEPENDENCIES = dynmodule.so

if cygwin
libdyndemo.a: $(cslbase)/dyndemo.def
	$(TRACE)$(DLLTOOL) --input-def $(cslbase)/dyndemo.def --dllname=dyndemo.exe --output-lib libdyndemo.a
endif cygwin
endif !windows

dyndemo$(EXEEXT): $(dyndemo_OBJECTS) $(dyndemo_DEPENDENCIES)
	-$(RM) -f dyndemo$(EXEEXT)
	$(CXXLINKTO) $(DEST)dyndemo$(EXEEXT) $(dyndemo_OBJECTS) $(LIBS)
if !debug
if !darwin
	$(STRIP) dyndemo$(EXEEXT)
endif !darwin
endif !debug

zlibdemo_SOURCES = zlibdemo.cpp
zlibdemo_LDADD = -lz

remake-zlibdemo-source:	$(cslbase)/preserve.cpp
	unifdef -x2 -DZLIB_DEMO < $(cslbase)/preserve.cpp > $(cslbase)/zlibdemo.cpp



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

local-bootstrapreduceexe.def:	$(cslbase)/bootstrapreduceexe.def $(cslbase)/impex.def
	cat $(cslbase)/bootstrapreduceexe.def $(cslbase)/impex.def > local-bootstrapreduceexe.def

local-reduceexe.def:	$(cslbase)/reduceexe.def $(cslbase)/impex.def
	cat $(cslbase)/reduceexe.def $(cslbase)/impex.def > local-reduceexe.def

local-reducecom.def:	$(cslbase)/reducecom.def $(cslbase)/impex.def
	cat $(cslbase)/reducecom.def $(cslbase)/impex.def > local-reducecom.def

local-cslexe.def:	$(cslbase)/cslexe.def $(cslbase)/impex.def
	cat $(cslbase)/cslexe.def $(cslbase)/impex.def > local-cslexe.def

local-cslcom.def:	$(cslbase)/cslcom.def $(cslbase)/impex.def
	cat $(cslbase)/cslcom.def $(cslbase)/impex.def > local-cslcom.def

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

dyndemo_LDADD = $(cslbase)/dyndemo.def

reduceres = fwin-reduce.$(OBJEXT)

fwindemo_LDADD = $(fwin_icon) $(FOX_LIBS)
csl_LDADD = fwin-csl.$(OBJEXT) $(FOX_LIBS)
flatcsl_LDADD = fwin-csl.$(OBJEXT) $(FOX_LIBS)
bootstrapreduce_LDADD = fwin-csl.$(OBJEXT) $(FOX_LIBS)
reduce_LDADD = $(reduceres) $(FOX_LIBS)

# The purpose of these two tiny programs is explained in the
# file $(cslbase)/gui-or-not.txt and both are only for use on Windows.
# They are not compiled with the general configure-detected compilation
# options.

if cygwin
WINHELPERS=
else !cygwin
WINHELPERS= cygwin-isatty.exe cygwin64-isatty.exe not-under-cygwin.exe
endif !cygwin

# A brief note about version of C compilers under cygwin. On either the
# 32 or 64-bit cygwin just "g++" is the main C++ compiler that targets the
# native width of the platform. But on each it is also possible to have
# one or both of i686-pc-cygwin-g++ and x86_64-pc-cygwin-g++ which explicitly
# target one or other width. These count as cross compilers, and at the
# time of writing they behave well enough to build the small command-line
# utilities here but do not come with enough development libraries to make
# it possible to use them to build all of CSL/Reduce. Because some people
# may not have them installed I have a fallback scheme here that fetches
# precompiled versions of the utilities. Note that they will include
# copies of cygwin1.dll but because they are BSD-licensed open source code
# that does not prevent me from redistributing them in an unconstrained manner.

cygwin-isatty.exe:	$(cslbase)/cygwin-isatty.cpp
	if test -x /usr/bin/i686-pc-cygwin-g++.exe; then i686-pc-cygwin-g++ -O3 $(cslbase)/cygwin-isatty.cpp -o cygwin-isatty.exe; else $(CP) $(cslbase)/premade-cygwin-isatty.exe .; \
	  if test -x /usr/bin/i686-pc-cygwin-strip.exe; then i686-pc-cygwin-strip cygwin-isatty.exe; else strip cygwin-isatty.exe; fi fi

cygwin64-isatty.exe:	$(cslbase)/cygwin-isatty.cpp
	if test -x /usr/bin/x86_64-pc-cygwin-g++.exe; then x86_64-pc-cygwin-g++ -O3 $(cslbase)/cygwin-isatty.cpp -o cygwin64-isatty.exe; else $(CP) $(cslbase)/premade-cygwin64-isatty.exe .; \
	  if test -s /usr/bin/x86_64-pc-cygwin-strip.exe; then x86_64-pc-cygwin-strip cygwin64-isatty.exe; else strip cygwin64-isatty.exe; fi fi

not-under-cygwin.exe:	$(cslbase)/not-under-cygwin.cpp
	i686-w64-mingw32-g++ -O3 $(cslbase)/not-under-cygwin.cpp -o not-under-cygwin.exe
	i686-w64-mingw32-strip not-under-cygwin.exe

csl_DEPENDENCIES = local-cslexe.def local-cslcom.def fwin-csl.$(OBJEXT) \
		$(FONTDEP) $(WXC)
flatcsl_DEPENDENCIES = local-cslexe.def local-cslcom.def fwin-csl.$(OBJEXT) \
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
dyndemo_DEPENDENCIES = $(cslbase)/dyndemo.def dynmodule.dll

libdyndemo.a: $(cslbase)/dyndemo.def
	$(DLLTOOL) --input-def $(cslbase)/dyndemo.def --dllname dyndemo.exe --output-lib libdyndemo.a

fwin-icon.$(OBJEXT):	$(cslbase)/fwin-icon.rc $(CYG)
	$(CYG) $(WINDRES) $(cslbase)/fwin-icon.rc --include-dir=$(cslbase) \
		-o fwin-icon.$(OBJEXT)

fwin-csl.$(OBJEXT):	$(cslbase)/fwin-csl.rc $(CYG)
	$(CYG) $(WINDRES) $(cslbase)/fwin-csl.rc --include-dir=$(cslbase) \
		-o fwin-csl.$(OBJEXT)

fwin-reduce.$(OBJEXT):	$(cslbase)/fwin-reduce.rc $(CYG)
	$(CYG) $(WINDRES) $(cslbase)/fwin-reduce.rc --include-dir=$(cslbase) \
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
flatcsl_LDADD = $(FOX_LIBS)
bootstrapreduce_LDADD = $(FOX_LIBS)
reduce_LDADD = $(FOX_LIBS)

csl_DEPENDENCIES = $(FONTDEP) $(WXC)
flatcsl_DEPENDENCIES = $(FONTDEP) $(WXC)
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
dyndemo_LDADD = $(cslbase)/dyndemo.def
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

$(FOXDEPS):	$(csl)/fox/CHANGED
	$(TRACE)@cd ../fox && $(CYG) $(MAKE) install


if crlibm

CRLIBMDEPS=../lib/libcrlibm.a ../include/crlibm.h

CRDEP = ../include/crlibm.h
CRINC = -I../include
AM_CPPFLAGS     += $(CRINC)
reduce_CPPFLAGS += $(CRINC)
csl_CPPFLAGS    += $(CRINC)
flatcsl_CPPFLAGS    += $(CRINC)

# The following ugly dependencies are here so that one can go, for
# instance, "make csl.o" in a clean tree and crlibm building will get
# triggered.


csl_LDADD += -L../lib -lcrlibm
flatcsl_LDADD += -L../lib -lcrlibm
bootstrapreduce_LDADD += -L../lib -lcrlibm
reduce_LDADD += -L../lib -lcrlibm

csl_DEPENDENCIES += $(CRLIBMDEPS)
flatcsl_DEPENDENCIES += $(CRLIBMDEPS)
bootstrapreduce_DEPENDENCIES += $(CRLIBMDEPS)
reduce_DEPENDENCIES += $(CRLIBMDEPS)

$(CRLIBMDEPS):
	$(TRACE)@cd ../crlibm && $(CYG) $(MAKE) install

else !crlibm
CRINC =
CRDEP =

endif !crlibm

if boehm

gctest_SOURCES = gctest.cpp
gctest_CPPFLAGS = $(TRACE)
gctest_LDADD =
gctest_DEPENDENCIES =

BOEHMDEPS=../lib/libgc.a ../include/gc/gc.h

BOEHMDEP = ../include/gc/gc.h
BOEHMINC = -I../include
AM_CPPFLAGS     += $(BOEHMINC)
reduce_CPPFLAGS += $(BOEHMINC)
csl_CPPFLAGS    += $(BOEHMINC)
flatcsl_CPPFLAGS    += $(BOEHMINC)
gctest_CPPFLAGS    += $(BOEHMINC)



csl_LDADD += ../lib/libgc.a
flatcsl_LDADD += ../lib/libgc.a
bootstrapreduce_LDADD += ../lib/libgc.a
reduce_LDADD += ../lib/libgc.a
gctest_LDADD += ../lib/libgc.a

csl_DEPENDENCIES += $(BOEHMDEPS)
flatcsl_DEPENDENCIES += $(BOEHMDEPS)
bootstrapreduce_DEPENDENCIES += $(BOEHMDEPS)
reduce_DEPENDENCIES += $(BOEHMDEPS)
gctest_DEPENDENCIES += $(BOEHMDEPS)

$(BOEHMDEPS):
	$(TRACE)@cd ../boehm && $(CYG) $(MAKE) install

gctest$(EXEEXT): $(gctest_OBJECTS) $(gctest_DEPENDENCIES)
	-$(RM) -f gctest$(EXEEXT)
	$(CXXLINKTO) $(DEST)gctest$(EXEEXT) $(gctest_OBJECTS) $(gctest_LDADD) $(LIBS)
if !debug
if !darwin
	$(STRIP) gctest$(EXEEXT)
endif !darwin
endif !debug

else !boehm
BOEHMINC =
BOEHMDEP =

endif !boehm


SOFTFLOATDEPS=../lib/libsoftfloat.a ../include/softfloat.h

SOFTFLOATDEP = ../include/softfloat.h
SOFTFLOATINC = -I../include
AM_CPPFLAGS     += $(SOFTFLOATINC)
reduce_CPPFLAGS += $(SOFTFLOATINC)
csl_CPPFLAGS    += $(SOFTFLOATINC)
flatcsl_CPPFLAGS    += $(SOFTFLOATINC)

# The following ugly dependencies are here so that one can go, for
# instance, "make csl.o" in a clean tree and softfloat building will get
# triggered.


csl_LDADD += -L../lib -lsoftfloat
flatcsl_LDADD += -L../lib -lsoftfloat
bootstrapreduce_LDADD += -L../lib -lsoftfloat
reduce_LDADD += -L../lib -lsoftfloat

csl_DEPENDENCIES += $(SOFTFLOATDEPS)
bootstrapreduce_DEPENDENCIES += $(SOFTFLOATDEPS)
reduce_DEPENDENCIES += $(SOFTFLOATDEPS)

$(SOFTFLOATDEPS):
	$(TRACE)@cd ../softfloat && $(CYG) $(MAKE) install

# Note that all the compilation of these files must be performed using
# a Make "default" action so that the dependencies shown here are not
# taken as specifing conflicting actions.

arith01.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
arith02.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
arith03.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
arith04.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
arith05.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
arith06.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
arith07.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
arith08.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
arith09.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
arith10.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
arith11.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
arith12.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
arith13.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
arith14.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
isprime.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
bytes1.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
char.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
csl.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
cslmpi.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
cslread.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
eval1.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
eval2.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
eval3.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
eval4.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
fasl.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
fns1.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
fns2.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
fns3.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
lisphash.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
newhash.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
cslgc.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
ompsetup.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
openmath.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
preserve.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
print.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
pro.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
restart.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) machineid.cpp $(CYG)
stubs.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
sysfwin.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
sysipaq.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)

csl-arith01.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
csl-arith02.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
csl-arith03.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
csl-arith04.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
csl-arith05.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
csl-arith06.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
csl-arith07.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
csl-arith08.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
csl-arith09.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
csl-arith10.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
csl-arith11.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
csl-arith12.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
csl-arith13.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
csl-arith14.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
csl-isprime.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
csl-bytes1.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
csl-char.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
csl-csl.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
csl-cslmpi.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
csl-cslread.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
csl-eval1.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
csl-eval2.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
csl-eval3.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
csl-eval4.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
csl-fasl.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
csl-fns1.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
csl-fns2.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
csl-fns3.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
csl-lisphash.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
csl-newhash.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
csl-cslgc.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
csl-ompsetup.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
csl-openmath.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
csl-preserve.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
csl-print.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
csl-pro.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
csl-restart.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) machineid.cpp $(CYG)
csl-stubs.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
csl-sysfwin.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
csl-sysipaq.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)

reduce-arith01.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
reduce-arith02.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
reduce-arith03.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
reduce-arith04.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
reduce-arith05.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
reduce-arith06.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
reduce-arith07.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
reduce-arith08.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
reduce-arith09.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
reduce-arith10.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
reduce-arith11.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
reduce-arith12.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
reduce-arith13.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
reduce-arith14.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
reduce-isprime.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
reduce-bytes1.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
reduce-char.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
reduce-csl.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
reduce-cslmpi.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
reduce-cslread.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
reduce-eval1.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
reduce-eval2.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
reduce-eval3.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
reduce-eval4.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
reduce-fasl.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
reduce-fns1.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
reduce-fns2.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
reduce-fns3.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
reduce-lisphash.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
reduce-newhash.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
reduce-cslgc.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
reduce-ompsetup.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
reduce-openmath.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
reduce-preserve.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
reduce-print.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
reduce-pro.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
reduce-restart.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) machineid.cpp $(CYG)
reduce-stubs.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
reduce-sysfwin.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)
reduce-sysipaq.$(OBJEXT):	$(CRDEP) $(BOEHMDEP) $(SOFTFLOATDEP) $(CYG)

# If one of the major foundations of this Makefile have a date later than that
# on fxver.h then make does a futile recursion to try to fix it and in the
# process it can do a LOT of work that I do not want done. I can at least
# arrange that that happens at most once by putting the following rules:

$(cslbase)/configure.ac:
	touch $(cslbase)/configure.ac

$(cslbase)/Makefile.am:
	touch $(cslbase)/Makefile.am

if wx

$(csl)/wxWidgets/wxWidgets_revision:	\
		$(csl)/support-packages/wxWidgets_revision
	$(TRACE) ( cd $(csl)/support-packages ; \
	a=`echo wxWidgets-*-*-*.tar.bz2` ; \
	a=$${a##* } ; \
	b=$${a%.tar.bz2} ; \
	cd .. ; \
	rm -rf wxWidgets ; \
	tar xfj support-packages/$$a ; \
	chmod -R +rw wxWidgets ; \
	find . \( -name configure.ac -o -name configure.in \
	          -o -name Makefile.am \) -print | xargs touch ; \
	sleep 1 ; \
	find wxWidgets -name aclocal.m4 -print | xargs touch ; \
	sleep 1 ; \
	find wxWidgets -name configure -print | xargs touch ; \
	find wxWidgets -name configure -print | xargs chmod +x ; \
	sleep 1 ; \
	find wxWidgets -name config.h.in -print | xargs touch ; \
	sleep 1 ; \
	find wxWidgets -name Makefile.in -print | xargs touch ; \
	cp $(csl)/support-packages/wxWidgets_revision wxWidgets ; \
	echo wxWidgets unpacked from archive $$a )

# I use wx-config as my main and only indication that wxwidgets has been
# built and installed.

WXDEPS=../bin/wx-config

../bin/wx-config:	$(csl)/wxWidgets/wxWidgets_revision
	$(TRACE)@cd ../wxWidgets && $(CYG) $(MAKE) install

wxfontdemo$(EXEEXT): $(wxfontdemo_OBJECTS) $(wxfontdemo_DEPENDENCIES) $(WXDEPS)
	-$(RM) -f wxfontdemo$(EXEEXT)
	$(CXXLINKTO) $(DEST)wxfontdemo$(EXEEXT) $(wxfontdemo_OBJECTS) $(wxfontdemo_LDADD) $(AM_LIBS) $(LIBS) $(CONAP)
if !debug
if !darwin
	$(STRIP) wxfontdemo$(EXEEXT)
endif !darwin
endif !debug
if mac_framework
	$(cslbase)/create_bundle.sh wxfontdemo $(cslbase)
endif mac_framework

wxfontdemo1$(EXEEXT): $(wxfontdemo1_OBJECTS) $(wxfontdemo1_DEPENDENCIES) $(WXDEPS)
	-$(RM) -f wxfontdemo1$(EXEEXT)
	$(CXXLINKTO) $(DEST)wxfontdemo1$(EXEEXT) $(wxfontdemo1_OBJECTS) $(wxfontdemo1_LDADD) $(AM_LIBS) $(LIBS) $(CONAP)
if !debug
if !darwin
	$(STRIP) wxfontdemo1$(EXEEXT)
endif !darwin
endif !debug
if mac_framework
	$(cslbase)/create_bundle.sh wxfontdemo1 $(cslbase)
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
	$(cslbase)/create_bundle.sh wxdvi $(cslbase)
endif mac_framework

wxshowmath$(EXEEXT): $(wxshowmath_OBJECTS) $(wxshowmath_DEPENDENCIES) $(WXDEPS)
	-$(RM) -f wxshowmath$(EXEEXT)
	$(CXXLINKTO) $(DEST)wxshowmath$(EXEEXT) $(wxshowmath_OBJECTS) $(wxshowmath_LDADD) $(AM_LIBS) $(LIBS) $(CONAP)
if !debug
if !darwin
	$(STRIP) wxshowmath$(EXEEXT)
endif !darwin
endif !debug
if mac_framework
	$(cslbase)/create_bundle.sh wxshowmath $(cslbase)
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
	$(cslbase)/create_bundle.sh wxdemo $(cslbase)
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
	$(cslbase)/create_bundle.sh wxshowmathdemo $(cslbase)
endif mac_framework

else !wx
WXDEPS=
endif !wx

csl$(EXEEXT): $(csl_OBJECTS) $(csl_DEPENDENCIES) $(FOXDEPS) $(WXDEPS) $(WINHELPERS)
	-$(RM) -f csl$(EXEEXT)
if windows
if gui
	$(CP) $(cslbase)/csl .
else !gui
	$(CP) $(cslbase)/csl-nogui .
endif !gui
if !cygwin
if cyg32
	if test x"$(with_cygbuild)" != "x"; then cd $(with_cygbuild)/csl && $(MAKE) csl.exe; fi
endif cyg32
	if test -x $(with_cygbuild)/csl/csl.exe; then $(CP) $(with_cygbuild)/csl/csl.exe cygwin-csl.exe; fi
if cyg64
	if test x"$(with_cygbuild64)" != "x"; then cd $(with_cygbuild64)/csl && $(MAKE) csl.exe; fi
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
	$(cslbase)/create_bundle.sh csl $(cslbase) csl
endif mac_framework
else !wx
if mac_framework
	$(REZ) -t APPL -o csl $(cslbase)/mac.r
	$(cslbase)/create_old_bundle.sh csl $(cslbase) csl
endif mac_framework

endif !wx

flatcsl$(EXEEXT): $(flatcsl_OBJECTS) $(csl_DEPENDENCIES) $(FOXDEPS) $(WXDEPS) $(WINHELPERS)
	-$(RM) -f csl$(EXEEXT)
if windows
if gui
	$(CP) $(cslbase)/csl .
else !gui
	$(CP) $(cslbase)/csl-nogui .
endif !gui
if !cygwin
if cyg32
	if test x"$(with_cygbuild)" != "x"; then cd $(with_cygbuild)/csl && $(MAKE) flatcsl.exe; fi
endif cyg32
	if test -x $(with_cygbuild)/csl/flatcsl.exe; then $(CP) $(with_cygbuild)/csl/flatcsl.exe cygwin-flatcsl.exe; fi
if cyg64
	if test x"$(with_cygbuild64)" != "x"; then cd $(with_cygbuild64)/csl && $(MAKE) flatcsl.exe; fi
endif cyg64
	if test -x $(with_cygbuild64)/csl/flatcsl.exe; then $(CP) $(with_cygbuild64)/csl/flatcsl.exe cygwin64-flatcsl.exe; fi
endif !cygwin
endif windows
	$(CXXLINKTO) $(CSLEXEDEF) $(DEST)flatcsl$(EXEEXT) $(flatcsl_OBJECTS) $(flatcsl_LDADD) $(AM_LIBS) $(LIBS) $(WINAP)
if windows
if gui
	-$(RM) -f csl$(COM)
	$(CXXLINKTO) $(CSLCOMDEF) $(DEST)flatcsl$(COM) $(flatcsl_OBJECTS) $(flatcsl_LDADD) $(AM_LIBS) $(LIBS) $(CONAP)
endif gui
	$(DLLTOOL) --def $(CSLEXEDEF) --output-lib libcslexe.a
	$(DLLTOOL) --def $(CSLCOMDEF) --output-lib libcslcom.a
endif windows
if !debug
if !darwin
	$(STRIP) flatcsl$(EXEEXT)
if windows
if gui
	$(STRIP) flatcsl$(COM)
endif gui
endif windows
endif !darwin
endif !debug
if wx
if mac_framework
	$(cslbase)/create_bundle.sh flatcsl $(cslbase) flatcsl
endif mac_framework
else !wx
if mac_framework
	$(REZ) -t APPL -o flatcsl $(cslbase)/mac.r
	$(cslbase)/create_old_bundle.sh flatcsl $(cslbase) flatcsl
endif mac_framework

endif !wx

reduce$(EXEEXT): $(reduce_OBJECTS) $(reduce_DEPENDENCIES) $(FOXDEPS) \
			$(WXDEPS) $(generated_lisp) $(WINHELPERS)
	-$(RM) -f reduce$(EXEEXT)
if windows
# See "gui-or-not.txt" for an explanation of what this is about...
if gui
	$(CP) $(cslbase)/reduce .
else !gui
	$(CP) $(cslbase)/reduce-nogui .
endif !gui
if !cygwin
if cyg32
	if test x"$(with_cygbuild)" != "x"; then cd $(with_cygbuild)/csl && $(MAKE) reduce.exe; fi
endif cyg32
	if test -x $(with_cygbuild)/csl/reduce.exe; then $(CP) $(with_cygbuild)/csl/reduce.exe cygwin-reduce.exe; fi
if cyg64
	if test "x$(with_cygbuild64)" != "x"; then cd $(with_cygbuild64)/csl && $(MAKE) reduce.exe; fi
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
	$(cslbase)/create_bundle.sh reduce $(cslbase) reduce
endif mac_framework
else !wx
if mac_framework
# on Darwin I want to go
# $(REZ) -t APPL -o reduce $(cslbase)/mac.r
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
	$(REZ) -t APPL -o reduce $(cslbase)/mac.r
	$(cslbase)/create_old_bundle.sh reduce $(cslbase) reduce
endif mac_framework
endif !wx

bootstrapreduce$(EXEEXT): $(bootstrapreduce_OBJECTS) $(bootstrapreduce_DEPENDENCIES) $(FOXDEPS) $(WXDEPS)
	-$(RM) -f bootstrapreduce$(EXEEXT)
if windows
# See "gui-or-not.txt" for an explanation of what this is about...
	$(CP) $(cslbase)/bootstrapreduce .
if !cygwin
if cyg32
	if test x"$(with_cygbuild)" != "x"; then cd $(with_cygbuild)/csl && $(MAKE) bootstrapreduce.exe; fi
endif cyg32
	if test -x $(with_cygbuild)/csl/bootstrapreduce.exe; then $(CP) $(with_cygbuild)/csl/bootstrapreduce.exe cygwin-bootstrapreduce.exe; fi
if cyg64
	if test x"$(with_cygbuild64)" != "x"; then cd $(with_cygbuild64)/csl && $(MAKE) bootstrapreduce.exe; fi
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
	$(cslbase)/create_bundle.sh bootstrapreduce $(cslbase) reduce
endif mac_framework
else !wx
if mac_framework
	$(REZ) -t APPL -o bootstrapreduce $(cslbase)/mac.r
	$(cslbase)/create_old_bundle.sh bootstrapreduce $(cslbase) reduce
endif mac_framework
endif !wx
if windows
	$(DLLTOOL) --def $(BOOTSTRAPREDUCEEXEDEF) --output-lib libbootstrapreduce.a
endif windows

fwindemo$(EXEEXT): $(fwindemo_OBJECTS) $(fwindemo_DEPENDENCIES) $(FOXDEPS) $(WXDEPS) $(WINHELPERS)
	-$(RM) -f fwindemo$(EXEEXT)
if windows
if gui
	$(CP) $(cslbase)/fwindemo .
else !gui
	$(CP) $(cslbase)/fwindemo-nogui .
endif !gui
if !cygwin
if cyg32
	if test x"$(with_cygbuild)" != "x"; then cd $(with_cygbuild)/csl && $(MAKE) fwindemo.exe; fi
endif cyg32
	if test -x $(with_cygbuild)/csl/fwindemo.exe; then $(CP) $(with_cygbuild)/csl/fwindemo.exe cygwin-fwindemo.exe; fi
if cyg64
	if test x"$(with_cygbuild64)" != "x"; then cd $(with_cygbuild64)/csl && $(MAKE) fwindemo.exe; fi
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
	$(cslbase)/create_bundle.sh fwindemo $(cslbase)
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
	$(cslbase)/create_bundle.sh wxpsl $(cslbase)
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

flatcsl$(COM):	flatcsl.exe
## Recover from the removal of flatcsl.com
	if test -f flatcsl.com; then touch flatcsl.com; else \
	  $(RM) -f flatcsl.exe; \
	  $(MAKE) $(AM_MAKEFLAGS) flatcsl.exe; \
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

reduce.$(fontsdir)/$(samplefont):	$(cslbase)/fonts
if wx
if mac_framework
	echo reduce.wxfonts not used on the Mac with wxWidgets
else !mac_framework
	-$(TRACE)$(RM) -rf reduce.$(fontsdir)
	-mkdir -p reduce.$(fontsdir)
	$(CP) $(cslbase)/$(fontsdir)/LICENSE.cmuntt reduce.$(fontsdir)
	$(CP) $(cslbase)/$(fontsdir)/STIX*.pdf reduce.$(fontsdir)
	$(CP) $(cslbase)/$(fontsdir)/LICENSE-fireflysung-odokai.txt reduce.$(fontsdir)
# odokai only seems to come in .ttf form.
	$(CP) $(cslbase)/$(fontsdir)/odokai.ttf reduce.$(fontsdir)
if windows
# With Windows I will want a .ttf version for any time I am using gdiplus.
# However on a Windows platform under Cygwin and using X11 I would rather
# have the .otf version, so I will copy the .ttf version as well rather then
# instead of the .otf file.
	$(CP) $(cslbase)/$(fontsdir)/cmuntt.ttf reduce.$(fontsdir)
	$(CP) $(cslbase)/$(fontsdir)/cslSTIX*.ttf reduce.$(fontsdir)
endif windows
	$(CP) $(cslbase)/$(fontsdir)/cmuntt.otf reduce.$(fontsdir)
	$(CP) $(cslbase)/$(fontsdir)/cslSTIX*.otf reduce.$(fontsdir)

endif !mac_framework
else !wx
	-$(TRACE)$(RM) -rf reduce.$(fontsdir)
	-mkdir reduce.$(fontsdir)
	$(CP) $(cslbase)/$(fontsdir)/README reduce.$(fontsdir)
	$(CP) $(cslbase)/$(fontsdir)/README.cmps-fonts reduce.$(fontsdir)
	$(CP) $(cslbase)/$(fontsdir)/README.BaKoMa reduce.$(fontsdir)
	$(CP) $(cslbase)/$(fontsdir)/*.ttf reduce.$(fontsdir)
	$(CP) $(cslbase)/$(fontsdir)/*.pfb reduce.$(fontsdir)
	$(CP) $(cslbase)/$(fontsdir)/*.pfa reduce.$(fontsdir)
	$(CP) $(cslbase)/$(fontsdir)/fonts.dir reduce.$(fontsdir)
	$(CP) $(cslbase)/$(fontsdir)/fonts.scale reduce.$(fontsdir)
	-mkdir -p reduce.$(fontsdir)/pfmfiles
	$(CP) -r $(cslbase)/$(fontsdir)/pfmfiles/*.pfm reduce.$(fontsdir)/pfmfiles
	-mkdir -p reduce.$(fontsdir)/src
	$(CP) -r $(cslbase)/$(fontsdir)/src/*.gz reduce.$(fontsdir)/src
	chmod +x reduce.$(fontsdir)/*.ttf
endif !wx

if exeext

# The next section is to conspire with automake's treatment of extensions for
# executables (ie ".exe") so that eg "make reduce" will case "make reduce.exe" to
# happen. The use of parameter substitution to generate the plain targets is
# because in that case automake will not auto-map the target adding ".exe".



if cygwin
$(plain_csl):	csl.exe
	echo "$(MAKE) csl.exe is preferred"

$(plain_flatcsl):	flatcsl.exe
	echo "$(MAKE) flatcsl.exe is preferred"

$(plain_reduce):	reduce.exe
	echo "$(MAKE) reduce.exe is preferred"

$(plain_bootstrapreduce):	bootstrapreduce.exe
	echo "$(MAKE) bootstrapreduce.exe is preferred"

$(plain_fwindemo):	fwindemo.exe
	echo "$(MAKE) fwindemo.exe is preferred"

if wx
$(plain_wxpsl):	wxpsl.exe
	echo "$(MAKE) wxpsl.exe is preferred"
endif wx

else !cygwin
if gui
$(plain_csl):	csl.exe csl$(COM)
	echo "$(MAKE) csl.exe is preferred"

$(plain_flatcsl):	flatcsl.exe flatcsl$(COM)
	echo "$(MAKE) flatcsl.exe is preferred"

$(plain_reduce):	reduce.exe reduce$(COM)
	echo "$(MAKE) reduce.exe is preferred"

$(plain_bootstrapreduce):	bootstrapreduce.exe
	echo "$(MAKE) bootstrapreduce.exe is preferred"

$(plain_fwindemo):	fwindemo.exe fwindemo$(COM)
	echo "$(MAKE) fwindemo.exe is preferred"

if wx
$(plain_wxpsl):	wxpsl.exe wxpsl$(COM)
	echo "$(MAKE) wxpsl.exe is preferred"
endif wx

else !gui
$(plain_csl):	csl.exe
	echo "$(MAKE) csl.exe is preferred"

$(plain_flatcsl):	flatcsl.exe
	echo "$(MAKE) flatcsl.exe is preferred"

$(plain_reduce):	reduce.exe
	echo "$(MAKE) reduce.exe is preferred"

$(plain_bootstrapreduce):	bootstrapreduce.exe
	echo "$(MAKE) bootstrapreduce.exe is preferred"

$(plain_fwindemo):	fwindemo.exe
	echo "$(MAKE) fwindemo.exe is preferred"

endif !gui
endif !cygwin
if fox

$(plain_foxdemo):	foxdemo.exe
	echo "$(MAKE) foxdemo.exe is preferred"

$(plain_fontdemo):	fontdemo.exe
	echo "$(MAKE) fontdemo.exe is preferred"

$(plain_showmathdemo):	showmathdemo.exe
	echo "$(MAKE) showmathdemo.exe is preferred"


endif fox

if wx

$(plain_wxdemo):	wxdemo.exe
	echo "$(MAKE) wxdemo.exe is preferred"

$(plain_wxfontdemo):	wxfontdemo.exe
	echo "$(MAKE) wxfontdemo.exe is preferred"

$(plain_wxfontdemo1):	wxfontdemo1.exe
	echo "$(MAKE) wxfontdemo1.exe is preferred"

$(plain_wxdvi):	wxdvi.exe
	echo "$(MAKE) wxdvi.exe is preferred"

$(plain_wxshowmath):	wxshowmath.exe
	echo "$(MAKE) wxshowmath.exe is preferred"

$(plain_wxshowmathdemo):	wxshowmathdemo.exe
	echo "$(MAKE) wxshowmathdemo.exe is preferred"

endif wx

$(plain_termdemo):	termdemo.exe
	echo "$(MAKE) termdemo.exe is preferred"

$(plain_dyndemo):	dyndemo.exe
	echo "$(MAKE) dyndemo.exe is preferred"

$(plain_zlibdemo):	zlibdemo.exe
	echo "$(MAKE) zlibdemo.exe is preferred"

if boehm

$(plain_gctest):	gctest.exe
	echo "$(MAKE) gctest.exe is preferred"

endif boehm

endif exeext

fwindemo_SOURCES=fwindemo.cpp $(fwin_sources)
if wx
wxpsl_SOURCES=wxpsl.cpp $(fwin_sources)
endif wx

termdemo_SOURCES=termdemo.cpp termed.cpp
termdemo_LIBS = $(FOX_LIBS)

termdemo$(EXEEXT): $(termdemo_OBJECTS) $(termdemo_DEPENDENCIES)
	-$(RM) -f termdemo$(EXEEXT)
	$(CXXLINKTO) $(DEST)termdemo$(EXEEXT) $(termdemo_OBJECTS) $(LIBS)
if !debug
if !darwin
	$(STRIP) termdemo$(EXEEXT)
endif !darwin
endif !debug

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
image_files = csl.img $(REDUCE_IMG) reduce.doc reduce.resources reduce.$(fontsdir) *.app
else
image_files = csl.img reduce.img reduce.doc reduce.resources reduce.$(fontsdir)
endif
endif !windows

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

local_image_files = bootstrapreduce.img

win_specials = cygwin-reduce.exe cygwin-csl.exe cygwin-fwindemo.exe \
	not-under-cygwin.exe cygwin-isatty.exe cygwin64-isatty.exe csl \
	reduce fwindemo

generatedfiles=$(console_binaries) $(noinstall_console_binaries) \
	$(image_files) $(local_image_files) $(win_specials) \
	objtype* cl-wrap* makeheaders* *.def machineid.cpp *.dep $(INLINE_DEFS)

clean-local:
	-$(RM) -rf $(generatedfiles) $(CYG)
	
else !windows

local_image_files = bootstrapreduce.img

if mac_framework
macr = mac.r *.app
else !mac_framework
macr =
endif !mac_framework

generatedfiles=$(image_files) $(local_image_files) \
	objtype makeheaders machineid.cpp dynmodule* \
	$(macr)

clean-local:
	-$(RM) -rf $(generatedfiles) $(CYG)
	
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
#    make c-code                  Create files u*.cpp and u*.lsp
#                                 out of hot-spot parts of REDUCE.
#                                 (should happen automatically)
#  [ make full-c-code             Creates u*.cpp etc but trying to compile
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



default:	reduce$(EXEEXT) $(REDUCE_IMG)

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

dynmodule.$(DLLEXT):	$(cslbase)/dynmodule.cpp $(dyndep)
	$(COMPILE_DLL) $(cslbase)/dynmodule.cpp $(dyndep) $(DEST)dynmodule.$(DLLEXT)

if canrun

objtype$(EXEEXT):	$(cslbase)/objtype.cpp
	$(LOCALCXX) $(cslbase)/objtype.cpp -o objtype$(EXEEXT)

makeheaders$(EXEEXT):	$(cslbase)/makeheaders.cpp
	$(LOCALCXX) $(cslbase)/makeheaders.cpp -o makeheaders$(EXEEXT)

else !canrun

# If I can not run programs built by the normal C compiler (eg because I am
# cross-compiling) I will build these two utilities using $(LOCALCXX). I will blandly
# assume that in any cross-compilation situation that $(LOCALCXX) is available
# and works, and the assumption is simplified by the fact that these two
# programs are both fairly small and conservative.

objtype$(EXEEXT):	$(cslbase)/objtype.cpp
	$(LOCALCXX) $(cslbase)/objtype.cpp -o objtype$(EXEEXT)

makeheaders$(EXEEXT):	$(cslbase)/makeheaders.cpp
	$(LOCALCXX) $(cslbase)/makeheaders.cpp -o makeheaders$(EXEEXT)

endif !canrun

# The next line generates a small file that contains inforation about the
# object files used on this computer and the command used to compile
# simple C code. Note that machineid.cpp is made to depend on Makefile
# so if for any reason Makefile gets update so will it, and hence
# restart.o and the rest.

machineid.cpp:	reduce-cslread.$(OBJEXT) config.h objtype$(EXEEXT) makeheaders$(EXEEXT) \
			makeheaders$(EXEEXT) Makefile $(cslbase)/impex.def \
			$(cslbase)/machine.h $(cslbase)/int128_t.h \
			$(cslbase)/tags.h $(cslbase)/cslerror.h \
			$(cslbase)/externs.h $(cslbase)/arith.h \
			$(cslbase)/entries.h $(cslbase)/lispthrow.h
	./objtype$(EXEEXT) reduce-cslread.$(OBJEXT) \
		$(cslbase)/impex.def machineid-1.cpp $(COMPILE_DLL)
	./makeheaders$(EXEEXT) config.h $(cslbase)/machine.h \
		$(cslbase)/int128_t.h $(cslbase)/tags.h \
		$(cslbase)/cslerror.h $(cslbase)/externs.h \
		$(cslbase)/arith.h $(cslbase)/entries.h \
		$(cslbase)/lispthrow.h > machineid-2.cpp
	cat machineid-1.cpp machineid-2.cpp > machineid.cpp

-include reduce.dep

reduce.dep:
	$(TRACE)touch reduce.dep

$(REDUCE_IMG):	reduce$(COM) $(reducedep) $(generated_lisp) $(CYG)
	-$(TRACE)$(RM) -rf $(REDUCE_IMG)
if canrun
# I will make the REDUCE image file a directory rather than a single
# file... This is achieved by specifying its name here with a trailing "/",
# but I could have also have just made a directory with the right name
# before starting the build job.
	mkdir -p buildlogs
	echo Building in `pwd`
# A reasonable person might ask what all the "chmod 664 $(gensrc)/* commands
# are doing here. Well they are because if you run under a cygwin (mintty)
# shell but execute that native windows (mingw-style) version of Reduce and
# it creates files then the cygwin file access bits at least sometimes do not
# get set and you can end up with files with access mode 000. That is a bit
# of a recipe for disaster, and so I enthusiastically reset access rights
# here. This ought to be harmless under other systems - at least I hope it
# will be. I make the access rights 664 not 644 in case you are a group member
# for the file-space not actually the owner.
	chmod 664 $(gensrc)/*
	$(CYG) ./reduce$(COM) -w -z $(CSLFLAGS) -Dno_init_file \
		$(CYGSRC)/buildreduce.lsp \
		-D@srcdir=$(CYGSRC) -D@reduce=$(CYGREDUCE) \
		-o- -- buildlogs/reduce.log \
		-j reduce.dep
	sed -i -e 's/::	;/:/g' *.dep
	chmod 664 $(gensrc)/*
# I copy an image into $(gensrc) with a view to keeping a copy thare that
# is up to date with my lastest build. There is a complication here that I
# only partially hack around. On the Mac I will often save image files within
# an application bundle, while on all other platforms they life in the
# directory adjacent to the executable file. I conditionally copy from both
# places here
	if test -f reduce.app/Contents/reduce.img; \
	then $(CP) reduce.app/Contents/reduce.img $(gensrc); \
	elif test -f reduce.img; then $(CP) reduce.img $(gensrc); fi
	chmod 664 $(gensrc)/*
else !canrun
	echo Can not build reduce.img on this platform.
	echo Copying from $(gensrc)
# Note that the following will only behave properly if some version where the
# image file CAN be made has already put it in $(gensrc). I do not put
# any careful dependencies here to enforce that. If you are running on
# a 32-bit Windows and trying to cross-build the 64-bit Windows system it
# can all work but I will insist that you build the 32-bit version first and
# leave it to YOU to check that this happens late enough to behave well and
# that the image gets re-copied when that is needed.
	-$(RM) -rf reduce.img
	$(CP) -r $(gensrc)/reduce.img .
endif !canrun

# This is a temporary target "reduce.dir" to create the image as a directory
# rather than as a single file.

reduce.dir:	reduce$(COM) $(reducedep) $(generated_lisp) $(CYG)
	-$(TRACE)$(RM) -rf reduce.img
if canrun
# I will make the REDUCE image file a directory rather than a single
# file... This is achieved by specifying its name here with a trailing "/",
# but I could have also have just made a directory with the right name
# before starting the build job.
	mkdir -p buildlogs
	chmod 664 $(gensrc)/*
	$(CYG) ./reduce$(COM) -w -z $(CSLFLAGS) \
		-Dno_init_file $(CYGSRC)/buildreduce.lsp \
		-D@srcdir=$(CYGSRC) -D@reduce=$(CYGREDUCE) \
		-o ./reduce.img/ \
		-- buildlogs/reduce.log \
		-j reduce.dep
	sed -i -e 's/::	;/:/g' *.dep
	chmod 664 $(gensrc)/*
else !canrun
	echo Can not build reduce.img on this platform
	echo Copying from $(gensrc)
# Note that the following will only behave properly if some version where the
# image file CAN be made has already put it in $(gensrc).
	-$(RM) -rf reduce.img
	$(CP) -r $(gensrc)/reduce.img .
endif !canrun

# "make bootstraprecompile which=<module-name>" and "make recompile which="
# recompile just one package, assuming everything else is properly up to
# date (at least if the image file exists at all) and they end up by
# stamping all files so that a subsequent "make test" etc will not cause
# unwanted extra recompilation.

bootstraprecompile: $(CYG)
if canrun
	chmod 664 $(gensrc)/*
	if ! test -f bootstrapreduce.img; then $(MAKE) bootstrapreduce.img; fi
	mkdir -p buildlogs
	chmod 664 $(gensrc)/*
	$(CYG) ./bootstrapreduce$(EXEEXT) -v -w $(CSLFLAGS) $(CYGSRC)/recompile.red \
		-Dno_init_file -D@srcdir=$(CYGSRC) -D@reduce=$(CYGREDUCE) \
		-l buildlogs/$(which).log -Dwhich=$(which)
	chmod 664 $(gensrc)/*
	$(MAKE) -t bootstrapreduce.img > /dev/null
else !canrun
	echo Can not build images on this platfrom
endif !canrun

recompile:	$(CYG)
if canrun
	chmod 664 $(gensrc)/*
	if ! test -f $(REDUCE_IMG); then $(MAKE) $(REDUCE_IMG); fi
	mkdir -p buildlogs
	chmod 664 $(gensrc)/*
	$(CYG) ./reduce$(COM) -v -w $(CSLFLAGS) $(CYGSRC)/recompile.red \
		-Dno_init_file -D@srcdir=$(CYGSRC) -D@reduce=$(CYGREDUCE) \
		-l buildlogs/$(which).log -Dwhich=$(which)
	chmod 664 $(gensrc)/*
	$(MAKE) -t $(REDUCE_IMG) > /dev/null
else !canrun
	echo Can not build images on this platfrom
endif !canrun

# Pseudo-targets with names like "packagename.bootfasl" and "packagename.fasl"
# can be used to trigger recompilation of just a single package.

%.bootfasl:
	$(MAKE) bootstraprecompile which=$*

%.fasl:
	$(MAKE) recompile which=$*


# Copy HTML help files in a directory reduce.doc.
# This rule lets the index file stand for all others, so if others
# were to get lost or corrupted they would not be automatically restored.
reduce.doc/index.html:
	-$(RM) -rf reduce.doc
	mkdir -p reduce.doc
	$(CP) -r $(csl)/reduce.doc/*.html reduce.doc
	$(CP) -r $(csl)/reduce.doc/*.tex reduce.doc
	$(CP) -r $(csl)/reduce.doc/*.gif reduce.doc
	$(CP) -r $(csl)/reduce.doc/*.txt reduce.doc

reduce.resources/mma.awk:	$(packages)/redlog/ofsf/mma.awk
	-mkdir -p reduce.resources
	$(CP) $(packages)/redlog/ofsf/mma.awk reduce.resources

reduce.resources/qepcad.awk:	$(packages)/redlog/ofsf/qepcad.awk
	-mkdir -p reduce.resources
	$(CP) $(packages)/redlog/ofsf/qepcad.awk reduce.resources

-include bootstrapreduce.dep

bootstrapreduce.dep:
	$(TRACE)touch bootstrapreduce.dep

bootstrapreduce.img:	bootstrapreduce$(EXEEXT) $(bootstrapreducedep) $(CYG)
	-$(TRACE)$(RM) -f bootstrapreduce.img
if canrun
	mkdir -p buildlogs
	echo Building in `pwd`
	chmod 664 $(gensrc)/*
	$(CYG) ./bootstrapreduce$(EXEEXT) -w -z $(CSLFLAGS) -Dno_init_file \
		$(CYGSRC)/buildreduce.lsp -D@srcdir=$(CYGSRC) -D@reduce=$(CYGREDUCE) \
		-o- -- buildlogs/bootstrapreduce.log \
		-j bootstrapreduce.dep
	sed -i -e 's/::	;/:/g' *.dep
	chmod 664 $(gensrc)/*
	if test -f bootstrapreduce.app/Contents/bootstrapreduce.img; \
	then $(CP) bootstrapreduce.app/Contents/bootstrapreduce.img $(gensrc); \
	elif test -f bootstrapreduce.img; \
	then $(CP) bootstrapreduce.img $(gensrc); fi
	chmod 664 $(gensrc)/*
else !canrun
	echo Can not build bootstrapreduce.img on this platform
	echo Copying from $(gensrc)
# Note that the following will only behave properly if some version where the
# image file CAN be made has already put it in $(gensrc).
	-$(RM) -rf bootstrapreduce.img
	$(CP) $(gensrc)/bootstrapreduce.img .
endif !canrun

# The image here is JUST for debugging and related testing and development.
# It is one that contains Rlisp and the most basic parts of Reduce, sufficient
# such that the rest of Reduce should be buildable on top of it. The
# standard "bootstrapreduce.img" target in effect builds this as an
# intermediate step.

boot.img:	bootstrapreduce$(EXEEXT) $(bootstrapreducedep) $(CYG)
	-$(TRACE)$(RM) -f boot.img
if canrun
	mkdir -p buildlogs
	echo Building in `pwd`
	chmod 664 $(gensrc)/*
	$(CYG) ./bootstrapreduce$(EXEEXT) -w -z $(CSLFLAGS) -Dno_init_file \
		$(CYGSRC)/buildboot.lsp -D@srcdir=$(CYGSRC) -D@reduce=$(CYGREDUCE) \
		-o boot.img -- buildlogs/boot.log
else !canrun
	echo Can not build boot.img on this platform
endif !canrun

profile:	bootstrapreduce.img $(CYG)
if canrun
	$(TRACE)mkdir -p buildlogs
	chmod 664 $(gensrc)/*
	$(CYG) ./bootstrapreduce$(EXEEXT) -w $(CSLFLAGS) -Dno_init_file \
		$(CYGSRC)/profile.red -D@srcdir=$(CYGSRC) -D@reduce=$(CYGREDUCE) \
		-Dcpulimit=$(cpulimit) -Dconslimit=$(conslimit) \
		-- buildlogs/profile.log
# I preserve the previous profile.dat as profile.dat.old
	-$(CP) $(gensrc)/profile.dat $(gensrc)/profile.dat.old
	mv profile.dat $(gensrc)
	chmod 664 $(gensrc)/*
else !canrun
	echo Can not profile on this platform
endif !canrun

prof-inst:	profile.dat
	$(CP) profile.dat $(gensrc)
	chmod 664 $(gensrc)/*
	-$(RM) -f profile.dat

$(gensrc)/profile.dat:	$(csl)/generated-c/profile.dat
	-$(TRACE)mkdir -p $(gensrc)
	$(CP) $(csl)/generated-c/profile.dat $(gensrc)
	chmod 664 $(gensrc)/*

c-code:	$(gensrc)/make.stamp

$(gensrc)/make.stamp:	$(bootstrapreducedep) $(gensrc)/profile.dat \
		$(cslbase)/make-c-code.red
	chmod 664 $(gensrc)/*
	$(TRACE)$(RM) -f $(gensrc)/make.tmp
	touch $(gensrc)/make.tmp
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
	chmod 664 $(gensrc)/*
	if diff $(INLINE_DEFS) old-inline-defs.dat > /dev/null; \
	then \
	  echo "Inline definitions have not changed"; \
	  else \
	  $(RM) bootstrapreduce.img; \
	  $(MAKE) $(AM_MAKEFLAGS) bootstrapreduce.img; \
	fi
	$(MAKE) $(AM_MAKEFLAGS) just-c-code
	chmod 664 $(gensrc)/*
# If the inline-defs file has not changed I will restore the old one. Its
# contents will be just what I would have seen in the new one but its
# datestamp will be older and that can help avoid unnecessary rebuilding.
	if diff $(INLINE_DEFS) old-inline-defs.dat > /dev/null; \
	then \
	  echo "Inline definitions have not changed"; \
	  mv old-inline-defs.dat $(INLINE_DEFS); \
	else \
	  $(RM) -f old-inline-defs.dat; \
	fi
	mv $(gensrc)/make.tmp $(gensrc)/make.stamp

# This target assumes that bootstrapreduce.img is up to date and on that
# basis regenerates the C++ code. It is really only intended for direct use
# while debugging.

just-c-code:	$(CYG)
	$(CYG) ./bootstrapreduce$(EXEEXT) -i- -w $(CSLFLAGS) \
		-Dno_init_file $(CYGSRC)/make-c-code.red \
		-D@destdir=$(CYGREDUCE)/cslbuild/generated-c \
		-Dhow_many=$(how_many) -Dsize_per_file=$(size_per_file) \
		-- buildlogs/c-code.log

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

# I believe there is a potential race (with "make -j") if say reduce-u01.o is
# out of date in a simple way and starts to get compiled, but while that
# is going on a missing version of say u33.lsp causes the rule here to
# trigger... and in the process re-create a new version of reduce-u05.cpp. I try
# to deal with that by deleting all the *.o files just in case some
# parallel process has slotted one in just when I did not want that!
# Well it is even worse - the main reduce executable can become out
# of date... but fail to be rebuilt. So here I will forcibly remake that.
# I rather hope that the delay while C-code is re-created is long enough
# to let any previous steps complete.

$(generated_source_deps):	$(gensrc)/make.stamp
	$(MAKE) standard_c_code

standard-c-code $(generated_lisp):	$(gensrc)/make.stamp
## Recover from the removal of $@
	if test -f $@; then touch $@; else \
	  $(RM) -f $(gensrc)/make.stamp; \
	  $(MAKE) $(AM_MAKEFLAGS) $(gensrc)/make.stamp; \
	  $(RM) -f $(generated-objects); \
	  $(MAKE) $(AM_MAKEFLAGS) reduce; \
	fi


# partial-c-code is a target only activated manually.

partial-c-code:	bootstrapreduce.img $(gensrc)/profile.dat $(CYG)
if canrun
	mkdir -p buildlogs
	chmod 664 $(gensrc)/*
	$(CYG) ./bootstrapreduce$(EXEEXT) -w $(CSLFLAGS) \
		-Dno_init_file $(CYGSRC)/make-c-code.red \
		-D@destdir=$(CYGREDUCE)/cslbuild/generated-c \
		-Dhow_many=$(how_many) -Dsize_per_file=$(size_per_file) \
		-- buildlogs/partial-c-code.log
	chmod 664 $(gensrc)/*
else !canrun
	echo Can not generate C code on this platfrom
endif !canrun

# full-c-code is a target only activated manually.

full-c-code:	bootstrapreduce.img $(gensrc)/profile.dat $(CYG)
if canrun
	mkdir -p buildlogs
	chmod 664 $(gensrc)/*
	$(CYG) ./bootstrapreduce$(EXEEXT) -w $(CSLFLAGS) \
		-Dno_init_file $(CYGSRC)/make-c-code.red \
		-D@destdir=$(CYGREDUCE)/cslbuild/generated-c -Dfull_c_code \
		-Dhow_many=$(how_many) -Dsize_per_file=$(size_per_file) \
		-- buildlogs/full-c-code.log
	chmod 664 $(gensrc)/*
else !canrun
	echo Can not generate C code on this platfrom
endif !canrun

# j-code will only be triggered manually.

j-code:	bootstrapreduce.img $(gensrc)/profile.dat $(CYG)
if canrun
	mkdir -p buildlogs
	mkdir -p $(CYGREDUCE)/cslbuild/generated-java
	$(CYG) ./bootstrapreduce$(EXEEXT) -w $(CSLFLAGS) \
		-Dno_init_file $(CYGSRC)/make-j-code.red \
		-D@destdir=$(CYGREDUCE)/cslbuild/generated-java \
		-Dhow_many=$(how_many) -Dsize_per_file=$(size_per_file) \
		-- buildlogs/j-code.log
else !canrun
	echo Can not generate Java code on this platfrom
endif !canrun

smacros smacros.red:	bootstrapreduce.img $(CYG)
if canrun
	mkdir -p buildlogs
	chmod 664 $(gensrc)/*
	$(CYG) ./bootstrapreduce$(EXEEXT) -w $(CSLFLAGS) \
		-Dno_init_file $(CYGSRC)/make-smacros.red \
		-Dhow_many=$(how_many) -Dhow_big=$(how_big) \
		-L buildlogs/smacros.log
	echo You may now copy smacros.red to trunk/packages/support
else !canrun
	echo Can not generate smacros.red on this platfrom
endif !canrun

testslow:	bootstrapreduce.img $(CYG)
if canrun
	mkdir -p testlogs
	$(CYG) ./bootstrapreduce$(EXEEXT) -v -w $(CSLFLAGS) $(CYGSRC)/testall.red \
		-Dno_init_file -D@srcdir=$(CYGSRC) -D@reduce=$(CYGREDUCE) \
		-- testlogs/testslow.log
	$(CYG) ./bootstrapreduce$(EXEEXT) -v -w $(CSLFLAGS) $(CYGSRC)/checkall.red \
		-Dno_init_file -D@srcdir=$(CYGSRC) -D@reduce=$(CYGREDUCE) \
		-- testlogs/checkslow.log
else !canrun
	echo Can not run tests on this platfrom
endif !canrun

testall:	$(REDUCE_IMG) $(CYG)
if canrun
	mkdir -p testlogs
	$(CYG) ./reduce$(COM) -v -w $(CSLFLAGS) $(CYGSRC)/testall.red \
		-Dno_init_file -D@srcdir=$(CYGSRC) -D@reduce=$(CYGREDUCE) \
		-Dcpulimit=$(cpulimit) -Dconslimit=$(conslimit) \
		-- testlogs/testreduce.log
	$(CYG) ./reduce$(COM) -v -w $(CSLFLAGS) $(CYGSRC)/checkall.red \
		-Dno_init_file -D@srcdir=$(CYGSRC) -D@reduce=$(CYGREDUCE) \
		-- testlogs/checkall.log
else !canrun
	echo Can not run tests on this platfrom
endif !canrun

testslow1:	bootstrapreduce.img $(CYG)
if canrun
	mkdir -p testlogs
	$(CYG) ./bootstrapreduce$(EXEEXT) -v -w $(CSLFLAGS) $(CYGSRC)/testall.red \
		-Dno_init_file -D@srcdir=$(CYGSRC) -D@reduce=$(CYGREDUCE) \
		-Dcpulimit=$(cpulimit) -Dconslimit=$(conslimit) \
		-- testlogs/test$(which).log -Dwhich=$(which)
else !canrun
	echo Can not run tests on this platfrom
endif !canrun

if valgrind

countall:	$(REDUCE_IMG)
	mkdir -p testlogs
	valgrind --tool=exp-bbv --instr-count-only=yes \
		./reduce$(COM) -v -w $(CSLFLAGS) $(CYGSRC)/testall.red \
		-Dno_init_file -D@srcdir=$(CYGSRC) -D@reduce=$(CYGREDUCE) \
		-Dcpulimit=30000 -Dconslimit=$(conslimit) \
		-- testlogs/countreduce.log



endif valgrind

test1:	$(REDUCE_IMG) $(CYG)
if canrun
	mkdir -p testlogs
	$(CYG) ./reduce$(COM) -v -w $(CSLFLAGS) $(CYGSRC)/testall.red \
		-Dno_init_file -D@srcdir=$(CYGSRC) -D@reduce=$(CYGREDUCE) \
		-- testlogs/test$(which).log -Dwhich=$(which) \
		-Dcpulimit=$(cpulimit) -Dconslimit=$(conslimit)
else !canrun
	echo Can not run tests on this platfrom
endif !canrun

if valgrind

count1:	$(REDUCE_IMG)
	mkdir -p testlogs
	valgrind --tool=exp-bbv --instr-count-only=yes \
		./reduce$(COM) -v -w $(CSLFLAGS) $(CYGSRC)/testall.red \
		-Dno_init_file -D@srcdir=$(CYGSRC) -D@reduce=$(CYGREDUCE) \
		-- testlogs/count$(which).log -Dwhich=$(which) \
		-Dcpulimit=30000 -Dconslimit=$(conslimit)

endif valgrind

checkall:	$(REDUCE_IMG) $(CYG)
if canrun
	mkdir -p testlogs
	$(CYG) ./reduce$(COM) -v -w $(CSLFLAGS) $(CYGSRC)/checkall.red \
		-Dno_init_file -D@srcdir=$(CYGSRC) -D@reduce=$(CYGREDUCE) \
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

csl.img:	csl$(COM) $(csldep) $(CYG)
	-$(TRACE)$(RM) -rf csl.img
if canrun
	mkdir -p buildlogs
	echo Building in `pwd`
	$(CYG) ./csl$(COM) -w -v -z $(CSLFLAGS) "$(CYGSRC)/buildcsl.lsp" \
		-D@cslbase="$(CYGSRC)" \
		-o- -- buildlogs/csl.img.log \
		-j csl.dep
	sed -i -e 's/::	;/:/g' *.dep
	if test -f csl.app/Contents/csl.img; \
	then $(CP) -r csl.app/Contents/csl.img $(gensrc); \
	elif test -f csl.img; then $(CP) -r csl.img $(gensrc); fi
else !canrun
	echo Can not create csl.img on this platfrom
	echo Copying from $(gensrc)
# Note that the following will only behave properly if some version where the
# image file CAN be made has already put it in $(gensrc).
	-$(RM) -rf csl.img
	$(CP) -r $(gensrc)/csl.img .
endif !canrun


csli.img:	csl$(COM) $(csldep) $(CYG)
	-$(TRACE)$(RM) -rf csli.img
	mkdir -p buildlogs
	echo Building in `pwd`
	$(CYG) ./csl$(COM) -w -v -z $(CSLFLAGS) "$(CYGSRC)/buildcsli.lsp" \
		-D@cslbase="$(CYGSRC)" \
		-o csli.img -L buildlogs/csli.img.log \
		-j csl.dep
	sed -i -e 's/::	;/:/g' *.dep


csl.dir:	csl$(COM) $(csldep) $(CYG)
	-$(TRACE)$(RM) -rf csl.img
if canrun
	mkdir -p buildlogs
	$(CYG) ./csl$(COM) -w -v -z $(CSLFLAGS) "$(CYGSRC)/buildcsl.lsp" \
		-o ./csl.img/ -D@cslbase="$(CYGSRC)" \
		-- buildlogs/csl.img.log \
		-j csl.dep
	sed -i -e 's/::	;/:/g' *.dep
else !canrun
	echo Can not create csl.img on this platfrom
	echo Copying from $(gensrc)
# Note that the following will only behave properly if some version where the
# image file CAN be made has already put it in $(gensrc).
	-$(RM) -rf csl.img
	$(CP) -r $(gensrc)/csl.img .
endif !canrun



if fox
guisrc=$(foxdemo_SOURCES) $(fontdemo_SOURCES) $(showmathdemo_SOURCES)
else !fox
if wx
guisrc=$(wxdemo_SOURCES) $(wxfontdemo_SOURCES) $(wxfontdemo1_SOURCES) $(wxshowmathdemo_SOURCES)
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
guibin=wxdemo$(EXEEXT) wxfontdemo$(EXEEXT) wxfontdemo1$(EXEEXT) wxshowmathdemo$(EXEEXT)
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

if redfront
# This little bit of trickieness is intended to arrange that if you go
# just "make" it will, in addition to everything else, have a go at
# building and installing redfront if that is needed. It assumes that
# when rfcsl$(EXEEXT) is build that rfpsl etc get built too.

noinst_SCRIPTS = $(reduce)/bin/rfcsl$(EXEEXT)

$(reduce)/bin/rfcsl$(EXEEXT): \
		$(generic)/newfront/findself.c \
		$(generic)/newfront/findself.h \
		$(generic)/newfront/redchild.c \
		$(generic)/newfront/reddeb.c \
		$(generic)/newfront/redfront.c \
		$(generic)/newfront/redfront.h \
		$(generic)/newfront/redline.c \
		$(generic)/newfront/redparent.c \
		$(generic)/newfront/redsig.c \
		$(generic)/newfront/redstrings.c
	cd ../redfront && $(CYG) $(MAKE)

endif redfront

showhost:
	echo host = $(HOST)

# Now I am going to put some customized and rather odd install stuff. When I
# have this working I will want to put in matching uninstall code, but for
# now that will wait. The idea I have is that the files that get set up by the
# stuff here should match the ones created by the system-specific installers,
# i.e. reduce.deb and .rpm and the Windows installer. I am really not sure
# what I should do on a Macintosh! So I think I will put things so that
# reduce can be launched from the command-line an dnot worry (at least the
# start with) about applications bundles etc.

if cygwin
install-exec-local:	reduce.exe reduce.img bootstrapreduce.exe bootstrapreduce.img csl.exe csl.img
	echo install for cygwin not implemented
	exit 1

else !cygwin
if mac_framework
install-exec-local:	reduce reduce.img bootstrapreduce bootstrapreduce.img csl csl.img
	echo install for macintosh not implemented
	exit 1

else !mac_framework
if windows
install-exec-local:	reduce.exe reduce.img bootstrapreduce.exe bootstrapreduce.img csl.exe csl.img
	echo install for windows not implemented
	exit 1

else !windows
install-exec-local:	reduce reduce.img bootstrapreduce bootstrapreduce.img csl csl.img
# This version is mainly for Linus... It follows the directory layout used
# in the "debianbuild" directory.
	echo install for Linux, Unix etc into destdir=$(DESTDIR) prefix=$(DESTDIR)$(prefix)
	rm -rf $(DESTDIR)$(libdir)/reduce/cslbuild
	rm -rf $(DESTDIR)$(prefix)/share/reduce/cslbuild
	rm -rf $(DESTDIR)$(prefix)/share/reduce/fonts
	rm -rf $(DESTDIR)$(docdir)
	mkdir -p $(DESTDIR)$(libdir)/reduce/cslbuild/csl/reduce.resources
	mkdir -p $(DESTDIR)$(prefix)/share/reduce/fonts
	mkdir -p $(DESTDIR)$(docdir)
	mkdir -p $(DESTDIR)$(prefix)/bin
	mkdir -p $(DESTDIR)$(prefix)/man
	cp csl $(DESTDIR)$(libdir)/reduce/cslbuild/csl
	cp bootstrapreduce $(DESTDIR)$(libdir)/reduce/cslbuild/csl
	cp reduce $(DESTDIR)$(libdir)/reduce/cslbuild/csl
	cp csl.img $(DESTDIR)$(libdir)/reduce/cslbuild/csl
	cp bootstrapreduce.img $(DESTDIR)$(libdir)/reduce/cslbuild/csl
	cp reduce.img $(DESTDIR)$(libdir)/reduce/cslbuild/csl
	cp -r reduce.resources/* $(DESTDIR)$(libdir)/reduce/cslbuild/csl/reduce.resources
	cp -r reduce.fonts/* $(DESTDIR)$(prefix)/share/reduce/fonts
	cp -r reduce.doc/* $(DESTDIR)$(docdir)
	cp  $(cslbase)redcsl.1 $(DESTDIR)$(mandir)
	rm -f $(DESTDIR)$(libdir)/reduce/cslbuild/csl/reduce.doc
	rm -f $(DESTDIR)$(libdir)/reduce/cslbuild/csl/reduce.fonts
	rm -f $(DESTDIR)$(prefix)/share/reduce/cslbuild
	ln -s $(DESTDIR)$(docdir) $(DESTDIR)$(libdir)/reduce/cslbuild/csl/reduce.doc
	ln -s $(DESTDIR)$(prefix)/share/reduce/fonts $(DESTDIR)$(libdir)/reduce/cslbuild/csl/reduce.fonts
	ln -s $(DESTDIR)$(libdir)/reduce/cslbuild $(DESTDIR)$(prefix)/share/reduce/cslbuild
	sed -e "s/@libdir@/$(libdir)/" $(cslbase)/binscripts/csl > $(DESTDIR)$(prefix)/bin/csl
	sed -e "s/@libdir@/$(libdir)/" $(cslbase)/binscripts/bootstrapreduce > $(DESTDIR)$(prefix)/bin/bootstrapreduce
	sed -e "s/@libdir@/$(libdir)/" $(cslbase)/binscripts/redcsl > $(DESTDIR)$(prefix)/bin/redcsl
	echo Installed for CSL in $(DESTDIR)$(prefix)

endif !windows
endif !mac_framework
endif !cygwin

if cygwin
uninstall-local:
	echo uninstall for cygwin not implemented
	exit 1

else !cygwin
if mac_framework
uninstall-local:
	echo uninstall for macintosh not implemented
	exit 1

else !mac_framework
if windows
uninstall-local:
	echo uninstall for windows not implemented
	exit 1

else !windows
uninstall-local:
	echo uninstall for Linux, Unix etc into destdir=$(DESTDIR) prefix=$(DESTDIR)$(prefix)
	rm -rf $(DESTDIR)$(libdir)/reduce/cslbuild
	rm -rf $(DESTDIR)$(prefix)/share/reduce/cslbuild
	rm -rf $(DESTDIR)$(prefix)/share/reduce/fonts
	rm -rf $(DESTDIR)$(docdir)
	rm -f $(DESTDIR)$(prefix)/bin/csl
	rm -f $(DESTDIR)$(prefix)/bin/bootstrapreduce
	rm -f $(DESTDIR)$(prefix)/bin/redcsl
	rm -f $(DESTDIR)$(mandir)/redcsl.1
	echo Uninstalled for CSL in $(DESTDIR)$(prefix)

endif !windows
endif !mac_framework
endif !cygwin

install-data-local:
	echo " "

# end of Makefile

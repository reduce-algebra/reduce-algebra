## process this file with automake to create Makefile.in
## and then use autoconf to create ./configure. Finally run that
## to build your usable Makefile (probably in another directory)

# CSL and REDUCE build sequences

if cygwin
# IF BUILDING WITH CYGWIN YOU *MUST* REVIEW ALL LICENSES VERY CAREFULLY
# BEFORE REDISTRIBUTING ANY BINARIES SINCE THE MAIN CYGWIN DLL is GPL.
#
# I COMPILE AND LINK WITH "-mno-cygwin" WHICH SHOULD AVOID LINKING IN THE
# MAIN CYGWIN DLL, BUT CARE MUST BE TAKEN TO AVOID OTHER LIBRARIES THAT
# HAVE LICENSE CONDITIONS THAT WOULD CAUSE ME GRIEF.
endif cygwin

CP = cp
RM = rm

if cygpath
# Note that "cygpath -m" converts to a Windows-style path except that
# if leaves "/" not "\" in the name. This latter fact matters because
# of shell quoting issues. The fomer can be vital when non-cygwin
# applications might otherwise receive a file-name starting "/cygdrive/x/.."
# and not understand it.
CYGSRC = $(shell cygpath -m $(srcdir))
else
CYGSRC = $(srcdir)
endif

if windows
COMEXT=.com
else
COMEXT=
endif

if fox
foxdemotarget = foxdemo$(EXEEXT) fontdemo$(EXEEXT) showmathdemo$(EXEEXT)
else !fox
foxdemotarget =
endif !fox

bin_PROGRAMS = csl$(EXEEXT) reduce$(EXEEXT)
noinst_PROGRAMS = bootstrapreduce$(EXEEXT) fwindemo$(EXEEXT) \
                  termdemo$(EXEEXT) $(foxdemotarget) dyndemo$(EXEEXT)

if mac_framework
all-local:	make-clickable csl.img reduce.img
else !mac_framework
if cygwin
all-local:	report-dlls csl.img reduce.img
else !cygwin
if canrun
all-local:	csl.img reduce.img
else !canrun
# If I am cross-building I will not be able to create the image files.
all-local:
endif !canrun
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
# I arrange that fwin.c at least shows what you would need if it is
# used stand-alone.

if fox
fwin_sources =
else !fox
fwin_sources = fwin.c termed.c
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

generated_sources = $(gensrc)/u01.c $(gensrc)/u02.c \
		$(gensrc)/u03.c $(gensrc)/u04.c \
		$(gensrc)/u05.c $(gensrc)/u06.c \
		$(gensrc)/u07.c $(gensrc)/u08.c \
		$(gensrc)/u09.c $(gensrc)/u10.c \
		$(gensrc)/u11.c $(gensrc)/u12.c

generated_lisp = $(gensrc)/u01.lsp $(gensrc)/u02.lsp \
		$(gensrc)/u03.lsp $(gensrc)/u04.lsp \
		$(gensrc)/u05.lsp $(gensrc)/u06.lsp \
		$(gensrc)/u07.lsp $(gensrc)/u08.lsp \
		$(gensrc)/u09.lsp $(gensrc)/u10.lsp \
		$(gensrc)/u11.lsp $(gensrc)/u12.lsp

csl_SOURCES = $(core_sources) $(undemo_sources) $(fwin_sources) \
		$(jit_sources) bytes.c stubs.c

bootstrapreduce_SOURCES = $(core_sources) $(undemo_sources) $(fwin_sources) \
		$(jit_sources) bytes1.c stubs.c

reduce_SOURCES = $(core_sources) $(demo_sources) $(fwin_sources) \
		$(jit_sources) bytes.c $(generated_sources)

foxdemo_SOURCES = foxdemo.cpp
foxdemo_CPPFLAGS = $(FOX_INCLUDES)
foxdemo_LDADD = $(FOX_LIBS)

fontdemo_SOURCES = fontdemo.cpp
fontdemo_CPPFLAGS = $(FOX_INCLUDES)
fontdemo_LDADD = $(FOX_LIBS)

showmathdemo_SOURCES = showmathdemo.cpp
showmathdemo_CPPFLAGS = $(FOX_INCLUDES)
showmathdemo_LDADD = $(FOX_LIBS)

if windows
DLLEXT=dll
else !windows
DLLEXT=so
endif !windows

dyndemo_SOURCES = dyndemo.c

if !windows
dyndemo_DEPENDENCIES = dynmodule.so
endif !windows

fontsdir = reduce.fonts
AM_CPPFLAGS = -Dfontsdir=reduce.fonts

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

# For a build on Windows I want to add an icon into each binary, via
# a resource-file. I also want linking to be in "windows-subsystem-mode",
# but I also want matching ".com" files to be created to be console
# mode versions.

CONAP=-Wl,--subsystem,console
if fox
WINAP=-Wl,--subsystem,windows
else !fox
WINAP=-Wl,--subsystem,console
endif !fox

if windows
GP=wgnuplot.exe
else !windows
GP=
endif !windows

dyndemo_LDADD = $(srcdir)/dyndemo.def

reduceres = fwin-reduce.$(OBJEXT)

fwindemo_LDADD = fwin-icon.$(OBJEXT) $(FOX_LIBS)
csl_LDADD = fwin-csl.$(OBJEXT) $(FOX_LIBS)
bootstrapreduce_LDADD = fwin-csl.$(OBJEXT) $(FOX_LIBS)
reduce_LDADD = $(reduceres) $(FOX_LIBS)

csl_DEPENDENCIES = local-cslexe.def local-cslcom.def fwin-csl.$(OBJEXT) \
		$(fontsdir)/cmr10.pfb
bootstrapreduce_DEPENDENCIES = local-bootstrapreduceexe.def \
		fwin-csl.$(OBJEXT) $(fontsdir)/cmr10.pfb reduce.doc/index.html $(GP)
reduce_DEPENDENCIES = local-reduceexe.def local-reducecom.def $(reduceres) $(fontsdir)/cmr10.pfb reduce.doc/index.html $(GP)
fwindemo_DEPENDENCIES = fwin-icon.$(OBJEXT)
dyndemo_DEPENDENCIES = $(srcdir)/dyndemo.def dynmodule.dll

if fox
fontdemo_DEPENDENCIES = $(fontsdir)/cmr10.pfb
showmathdemo_DEPENDENCIES = $(fontsdir)/cmr10.pfb
endif fox

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

fwindemo_LDADD = $(FOX_LIBS)
csl_LDADD = $(FOX_LIBS)
bootstrapreduce_LDADD = $(FOX_LIBS)
reduce_LDADD = $(FOX_LIBS)

csl_DEPENDENCIES = $(fontsdir)/cmr10.pfb
bootstrapreduce_DEPENDENCIES = $(fontsdir)/cmr10.pfb reduce.doc/index.html $(GP)
reduce_DEPENDENCIES = $(fontsdir)/cmr10.pfb reduce.doc/index.html $(GP)

if fox
fontdemo_DEPENDENCIES = $(fontsdir)/cmr10.pfb
showmathdemo_DEPENDENCIES = $(fontsdir)/cmr10.pfb
endif fox

# On non-windows systems I am ASSUMING here that the C compiler will
# accept an "-o" option to indicate where it should put its object file.
#
fwin-csl.$(OBJEXT):	$(srcdir)/null.c
	$(COMPILE) -c $(srcdir)/null.c -o fwin-csl.$(OBJEXT)

fwin-reduce.$(OBJEXT):	$(srcdir)/null.c
	$(COMPILE) -c $(srcdir)/null.c -o fwin-reduce.$(OBJEXT)

# end of windows vs non-windows conditions
endif !windows

# The next line is because CXXLINK has "-o $@" as part of it and in this
# case I want to have separate control of the destination of the executable
# that I create. In doing it this way I ASSUME (and in general this can not
# be guaranteed) that the expression "-o destination" will be what works.

CXXLINKTO = $(CXXLD) $(AM_CXXFLAGS) $(CXXFLAGS) $(AM_LDFLAGS) $(LDFLAGS)

# BEWARE BEWARE BEWARE the next line must have trailing blanks
DEST=-o   

R = $(srcdir)/../..

#FOXDEP=../include/fox-1.6/fxver.h
if win64
FOXDEP=../lib/libFOX-1.6.lib
else !win64
FOXDEP=../lib/libFOX-1.6.a
endif !win64

# The next rule will only trigger if fxver.h is not present at all.

$(FOXDEP):
	@cd ../fox && $(MAKE) install

# If one of the major foundations of this Makefile have a date later than that
# on fxver.h then make does a futile recursion to try to fix it and in the
# process it can do a LOT of work that I do not want done. I can at least
# arrange that that happens at most once by putting the following rules:

$(srcdir)/configure.ac:
	touch $(srcdir)/configure.ac

$(srcdir)/Makefile.am:
	touch $(srcdir)/Makefile.am


csl$(EXEEXT): $(csl_OBJECTS) $(csl_DEPENDENCIES) $(FOXDEPS)
	-rm -f csl$(EXEEXT)
	$(CXXLINKTO) $(CSLEXEDEF) $(DEST)csl$(EXEEXT) $(csl_OBJECTS) $(csl_LDADD) $(LIBS) $(WINAP)
if windows
if fox
	-rm -f csl$(COMEXT)
	$(CXXLINKTO) $(CSLCOMDEF) $(DEST)csl$(COMEXT) $(csl_OBJECTS) $(csl_LDADD) $(LIBS) $(CONAP)
endif fox
endif windows
if !debug
if !darwin
	$(STRIP) csl$(EXEEXT)
if windows
if fox
	$(STRIP) csl$(COMEXT)
endif fox
endif windows
endif !darwin
endif !debug

reduce$(EXEEXT): $(reduce_OBJECTS) $(reduce_DEPENDENCIES) $(FOXDEPS)
	-rm -f reduce$(EXEEXT)
	$(CXXLINKTO) $(REDUCEEXEDEF) $(DEST)reduce$(EXEEXT) $(reduce_OBJECTS) $(reduce_LDADD) $(LIBS) $(WINAP)
if windows
if fox
	-rm -f reduce$(COMEXT)
	$(CXXLINKTO) $(REDUCECOMDEF) $(DEST)reduce$(COMEXT) $(reduce_OBJECTS) $(reduce_LDADD) $(LIBS) $(CONAP)
endif fox
endif windows
if !debug
if !darwin
	$(STRIP) reduce$(EXEEXT)
if windows
if fox
	$(STRIP) reduce$(COMEXT)
endif fox
endif windows
endif !darwin
endif !debug

bootstrapreduce$(EXEEXT): $(bootstrapreduce_OBJECTS) $(bootstrapreduce_DEPENDENCIES) $(FOXDEPS)
	-rm -f bootstrapreduce$(EXEEXT)
	$(CXXLINKTO) $(BOOTSTRAPREDUCEEXEDEF) $(DEST)bootstrapreduce$(EXEEXT) $(bootstrapreduce_OBJECTS) $(bootstrapreduce_LDADD) $(LIBS) $(CONAP)
if !debug
if !darwin
	$(STRIP) bootstrapreduce$(EXEEXT)
endif !darwin
endif !debug

fwindemo$(EXEEXT): $(fwindemo_OBJECTS) $(fwindemo_DEPENDENCIES) $(FOXDEPS)
	-rm -f fwindemo$(EXEEXT)
	$(CXXLINKTO) $(DEST)fwindemo$(EXEEXT) $(fwindemo_OBJECTS) $(fwindemo_LDADD) $(LIBS) $(WINAP)
if windows
if fox
	-rm -f fwindemo$(COMEXT)
	$(CXXLINKTO) $(DEST)fwindemo$(COMEXT) $(fwindemo_OBJECTS) $(fwindemo_LDADD) $(LIBS) $(CONAP)
endif fox
endif windows
if !debug
if !darwin
	$(STRIP) fwindemo$(EXEEXT)
if windows
if fox
	$(STRIP) fwindemo$(COMEXT)
endif fox
endif windows
endif !darwin
endif !debug

if fox

fontdemo$(EXEEXT): $(fontdemo_OBJECTS) $(fontdemo_DEPENDENCIES) $(FOXDEPS)
	-rm -f fontdemo$(EXEEXT)
	$(CXXLINKTO) $(DEST)fontdemo$(EXEEXT) $(fontdemo_OBJECTS) $(fontdemo_LDADD) $(LIBS) $(CONAP)
if !debug
if !darwin
	$(STRIP) fontdemo$(EXEEXT)
endif !darwin
endif !debug

foxdemo$(EXEEXT): $(foxdemo_OBJECTS) $(foxdemo_DEPENDENCIES)
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

if windows

csl$(COMEXT):	$(csl_OBJECTS) $(csl_DEPENDENCIES)
	-rm -f csl.exe
	$(MAKE) csl.exe

reduce$(COMEXT):	$(reduce_OBJECTS) $(reduce_DEPENDENCIES)
	-rm -f reduce.exe
	$(MAKE) reduce.exe

fwindemo$(COMEXT):	$(fwindemo_OBJECTS) $(fwindemo_DEPENDENCIES)
	-rm -f fwindemo.exe
	$(MAKE) fwindemo.exe

endif windows
endif fox

$(fontsdir)/cmr10.pfb:	$(srcdir)/fonts
	-rm -rf $(fontsdir)
	-mkdir $(fontsdir)
	$(CP) $(srcdir)/fonts/README $(fontsdir)
	$(CP) $(srcdir)/fonts/README.cmps-fonts $(fontsdir)
	$(CP) $(srcdir)/fonts/README.BaKoMa $(fontsdir)
	$(CP) $(srcdir)/fonts/*.ttf $(fontsdir)
	$(CP) $(srcdir)/fonts/*.pfb $(fontsdir)
	$(CP) $(srcdir)/fonts/*.pfa $(fontsdir)
	$(CP) $(srcdir)/fonts/fonts.dir $(fontsdir)
	$(CP) $(srcdir)/fonts/fonts.scale $(fontsdir)
	-mkdir $(fontsdir)/pfmfiles
	$(CP) -r $(srcdir)/fonts/pfmfiles/*.pfm $(fontsdir)/pfmfiles
	-mkdir $(fontsdir)/src
	$(CP) -r $(srcdir)/fonts/src/*.gz $(fontsdir)/src

if exeext

# The next section is to conspire with automake's treatement of externions for
# executables (ie ".exe") so that eg "make reduce" will case "make reduce.exe" to
# happen. The use of parameter substitution to generate the plain targets is
# because in that case automake will not auto-map the target adding ".exe".

plain_csl = csl
plain_reduce = reduce
plain_bootstrapreduce = bootstrapreduce
plain_fwindemo = fwindemo
plain_termdemo = termdemo
plain_foxdemo  = foxdemo
plain_fontdemo = fontdemo
plain_showmathdemo = showmathdemo
plain_dyndemo = dyndemo

if fox
$(plain_csl):	csl.exe csl$(COMEXT)
	echo "make csl.exe is preferred"

$(plain_reduce):	reduce.exe reduce$(COMEXT)
	echo "make reduce.exe is preferred"

$(plain_bootstrapreduce):	bootstrapreduce.exe
	echo "make bootstrapreduce.exe is preferred"

$(plain_fwindemo):	fwindemo.exe fwindemo$(COMEXT)
	echo "make fwindemo.exe is preferred"

$(plain_foxdemo):	foxdemo.exe
	echo "make foxdemo.exe is preferred"

$(plain_fontdemo):	fontdemo.exe
	echo "make fontdemo.exe is preferred"

$(plain_showmathdemo):	showmathdemo.exe
	echo "make showmathdemo.exe is preferred"

else !fox
$(plain_csl):	csl.exe
	echo "make csl.exe is preferred"

$(plain_reduce):	reduce.exe
	echo "make reduce.exe is preferred"

$(plain_bootstrapreduce):	bootstrapreduce.exe
	echo "make bootstrapreduce.exe is preferred"

$(plain_fwindemo):	fwindemo.exe
	echo "make fwindemo.exe is preferred"

endif !fox

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

termdemo_SOURCES=termdemo.c termed.c
termdemo_LIBS=

#
# Possibly unreasonably (but it is WHAT I DO!) image files for CSL live
# in the same directory as executables.
#

image_files = csl.img reduce.img reduce.doc $(fontsdir) wgnuplot* gnuplot.Copyright
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

if fox
console_binaries = csl$(COMEXT) reduce$(COMEXT) wgnuplot.exe wgnuplot.mnu wgnuplot.hlp
noinstall_console_binaries = fwindemo$(COMEXT)
else !fox
console_binaries = wgnuplot.exe wgnuplot.mnu wgnuplot.hlp
noinstall_console_binaries =
endif !fox

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
	  rm -f $(DESTDIR)$(bindir)/$$f; \
	done

local_image_files = bootstrapreduce.img

generatedfiles=$(console_binaries) $(noinstall_console_binaries) \
	$(image_files) $(local_image_files) \
	objtype* cl-wrap* makeheaders* *.def machineid.c dynmodule* \
	object-files.tar.gz objs relink* datestamp.dat

clean-local:
	-rm -rf $(generatedfiles)
	
else !windows

uninstall-local:
	@$(NORMAL_UNINSTALL)
	@list='$(image_files)'; for p in $$list; do \
	  f=`echo "$$p" | sed 's,^.*/,,'`; \
	  echo " rm -f $(DESTDIR)$(bindir)/$$f"; \
	  rm -f $(DESTDIR)$(bindir)/$$f; \
	done

local_image_files = bootstrapreduce.img

if mac_framework
macr = mac.r
else !mac_framework
macr =
endif !mac_framework

generatedfiles=$(image_files) $(local_image_files) \
	objtype makeheaders machineid.c dynmodule* \
	$(macr) \
	object-files.tar.gz objs relink* datestamp.dat

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
#=============================================================================
# Note that only the steps from here downwards are usually needed
#
#    make reduce                final compilation of most of REDUCE
#    make reduce.img            build final image file
#    make testall               runs test files, output to log directory
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
else
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

else

objtype$(EXEEXT):	$(srcdir)/objtype.c
	$(COMPILE) $(srcdir)/objtype.c -o objtype$(EXEEXT)

makeheaders$(EXEEXT):	$(srcdir)/makeheaders.c
	$(COMPILE) $(srcdir)/makeheaders.c -o makeheaders$(EXEEXT)

endif
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

reduce.img:	reduce$(COMEXT) $(reducedep)
	-$(RM) -rf reduce.img
if canrun
# I will make the REDUCE image file a directory rather than a single
# file... This is achieved by specifying its name here with a trailing "/",
# but I could have also have just made a directory with the right name
# before starting the build job.
	mkdir -p buildlogs
	./reduce$(COMEXT) -w -z -Dno_init_file $(CYGSRC)/buildreduce.lsp \
		-D@srcdir=$(CYGSRC) \
		-o ./reduce.img \
		-- buildlogs/reduce.log \
		-j reduce.dep
else !canrun
	echo Can not build reduce.img on this platform
endif !canrun

# This is a temporary target "reduce.dir" to create the image as a directory
# rather than as a single file.

reduce.dir:	reduce$(COMEXT) $(reducedep)
	-$(RM) -rf reduce.img
if canrun
# I will make the REDUCE image file a directory rather than a single
# file... This is achieved by specifying its name here with a trailing "/",
# but I could have also have just made a directory with the right name
# before starting the build job.
	mkdir -p buildlogs
	./reduce$(COMEXT) -w -z -Dno_init_file $(CYGSRC)/buildreduce.lsp \
		-D@srcdir=$(CYGSRC) \
		-o ./reduce.img/ \
		-- buildlogs/reduce.log \
		-j reduce.dep
else !canrun
	echo Can not build reduce.img on this platform
endif !canrun

# Copy HTML help files in a directory reduce.doc
reduce.doc/index.html:
	-$(RM) -rf reduce.doc
	mkdir reduce.doc
	$(CP) -r $(srcdir)/../reduce.doc/*.html reduce.doc
	$(CP) -r $(srcdir)/../reduce.doc/*.tex reduce.doc
	$(CP) -r $(srcdir)/../reduce.doc/*.gif reduce.doc
	$(CP) -r $(srcdir)/../reduce.doc/*.txt reduce.doc

if windows
#
# I also copy a set of gnuplot binaries into this directory.
# Note that the Gnuplot license permits this, but if I host any of this
# on Sourceforge then their terms and conditions mean I have to put a
# set of gnuplot sources in their file release system!
$(GP):
	$(CP) -r $(CYGSRC)/../support-packages/gnuplot-windows-bin/* .
# I view it as most unwelcome that I need the "chmod" here, but if I have
# gcc/g++ on my path and available I will suppose I can have chmod too.
	chmod +x wgnuplot.exe
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
else !canrun
	echo Can not build bootstrapreduce.img on this platform
endif !canrun

profile:	bootstrapreduce.img
if canrun
	mkdir -p buildlogs
	./bootstrapreduce$(EXEEXT) -w -Dno_init_file \
		$(CYGSRC)/profile.red -D@srcdir=$(CYGSRC) \
		-- buildlogs/profile.log
# I preserve the previous profile.dat as profile.dat.old
	-cp $(srcdir)/../../cslbuild/profile.dat $(srcdir)/../../cslbuild/profile.dat.old
	mv profile.dat $(srcdir)/../../cslbuild
else !canrun
	echo Can not profile on this platform
endif !canrun

prof-inst:	profile.dat
	$(CP) profile.dat $(srcdir)/../../cslbuild
	-$(RM) -f profile.dat

$(srcdir)/../../cslbuild/profile.dat:
	-mkdir -p $(srcdir)/../../cslbuild
	$(CP) $(srcdir)/../profile.dat $(srcdir)/../../cslbuild

c-code $(generated_sources) $(generated_lisp):	bootstrapreduce.img $(srcdir)/../../cslbuild/profile.dat
if canrun
	mkdir -p buildlogs
	./bootstrapreduce$(EXEEXT) -w -Dno_init_file $(CYGSRC)/make-c-code.red \
		-D@destdir=$(CYGSRC)/../../cslbuild \
		-- buildlogs/c-code.log
else !canrun
	echo Can not generate C code on this platfrom
endif !canrun

testslow:	bootstrapreduce.img
if canrun
	mkdir -p testlogs
	$(srcdir)/../util/testslow.sh $(srcdir)
	./bootstrapreduce$(EXEEXT) -v $(CYGSRC)/testall.red \
		-Dno_init_file -D@srcdir=$(CYGSRC) \
		-- testlogs/testbootstrap.log



else !canrun
	echo Can not run tests on this platfrom
endif !canrun

testall:	reduce.img
if canrun
	mkdir -p testlogs
	./reduce$(COMEXT) -v -w $(CYGSRC)/testall.red \
		-Dno_init_file -D@srcdir=$(CYGSRC) \
		-- testlogs/testreduce.log
	./reduce$(COMEXT) -v -w $(CYGSRC)/checkall.red \
		-Dno_init_file -D@srcdir=$(CYGSRC) \
		-- testlogs/checkall.log
else !canrun
	echo Can not run tests on this platfrom
endif !canrun

checkall:	reduce.img
if canrun
	mkdir -p testlogs
	./reduce$(COMEXT) -v -w $(CYGSRC)/checkall.red \
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

csl.img:	csl$(COMEXT) $(csldep)
	-$(RM) -f csl.img
if canrun
	mkdir -p buildlogs
	./csl$(COMEXT) -w -v -z "$(CYGSRC)/buildcsl.lsp" \
		-D@cslbase="$(CYGSRC)" \
		-- buildlogs/csl.img.log \
		-j csl.dep
else !canrun
	echo Can not create csl.img on this platfrom
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
guisrc=
endif !fox
mainsrc=$(guisrc) $(fwindemo_SOURCES) $(termdemo_SOURCES) $(reduce_SOURCES)
srcfiles=$(mainsrc) $(csl_SOURCES)

if fox
guibin=foxdemo$(EXEEXT) fontdemo$(EXEEXT) showmathdemo$(EXEEXT)
else !fox
guibin=
endif !fox
mainbin=$(guibin) fwindemo$(EXEEXT) termdemo$(EXEEXT) reduce$(EXEEXT)
if windows
mainbin+=fwindemo$(COMEXT) reduce$(COMEXT)
endif windows
binfiles=$(mainbin) csl$(EXEEXT)
if windows
binfiles+=csl$(COMEXT)
endif windows

save:	all
	echo ARCHITECTURE=$(ARCHITECTURE)  BUILD=$(BUILD)
if windows
	-rm -f reduce-windows-$(shell date +%Y%m%d).zip
	-rm -rf reduce-$(BUILD)-$(shell date +%Y%m%d)
	mkdir reduce-$(BUILD)-$(shell date +%Y%m%d)
	cp -r reduce.exe reduce.com reduce.img reduce.doc reduce.fonts *gnuplot* reduce-$(BUILD)-$(shell date +%Y%m%d)
	zip -r reduce-windows-$(shell date +%Y%m%d).zip reduce-$(BUILD)-$(shell date +%Y%m%d)
ARCHIVE=reduce-windows-$(shell date +%Y%m%d).zip
else !windows
	-rm -f reduce-$(BUILD)-$(shell date +%Y%m%d).tar.bz2
	-rm -rf reduce-$(BUILD)-$(shell date +%Y%m%d)
	mkdir reduce-$(BUILD)-$(shell date +%Y%m%d)
	cp -r reduce reduce.img reduce.doc reduce.fonts reduce-$(BUILD)-$(shell date +%Y%m%d)
	tar cvfj reduce-$(BUILD)-$(shell date +%Y%m%d).tar.bz2 reduce-$(BUILD)-$(shell date +%Y%m%d)
ARCHIVE=reduce-$(BUILD)-$(shell date +%Y%m%d).tar.bz2 
endif !windows
	if test "x$(savedest)" != "x"; then scp $(ARCHIVE) $(savedest); fi

#save:	all
#	echo Save files from this build
#	echo MAKE=$(MAKE)
#	$(srcdir)/save-objs.sh $(srcdir) $(OBJEXT) $(FOXLIB) -f $(srcfiles)
#	$(srcdir)/save-files.sh $(BUILD) $(binfiles)
#	$(srcdir)/save-relink.sh $(BUILD) $(binfiles)
#	./relink.sh

# end of Makefile

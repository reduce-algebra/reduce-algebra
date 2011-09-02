
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

if fox
foxdemotarget = fontdemo showmathdemo hello scribble
else !fox
foxdemotarget =
endif !fox

if demo
bin_PROGRAMS = r38
noinst_PROGRAMS = slowr38 fwindemo termdemo $(foxdemotarget) dyndemo
else !demo
bin_PROGRAMS = csl r38
noinst_PROGRAMS = slowr38 fwindemo \
                  termdemo $(foxdemotarget) dyndemo
endif !demo

if mac_framework
if demo
all-local:	make-clickable r38.img
else !demo
all-local:	make-clickable csl.img r38.img
endif !demo
else !mac_framework
if cygwin
if demo
all-local:	report-dlls r38.img
else !demo
all-local:	report-dlls csl.img r38.img
endif !demo
else !cygwin
if canrun
if demo
all-local:	r38.img
else !demo
all-local:	csl.img r38.img
endif !demo
else !canrun
# If I am cross-building I will not be able to create the image files.
all-local:
endif !canrun
endif !cygwin
endif !mac_framework


mathtextsrc = FXMathText.cpp

core_sources = arith01.c arith02.c arith03.c arith04.c arith05.c \
		arith06.c arith07.c arith08.c arith09.c arith10.c arith11.c \
		arith12.c char.c cslmpi.c eval1.c eval2.c \
		eval3.c eval4.c fns1.c fns2.c fns3.c \
		print.c cslread.c restart.c sysfwin.c

if demo
demo_sources = demo.c
else !demo
demo_sources = csl.c fasl.c gc.c preserve.c
endif !demo

undemo_sources = csl.c fasl.c gc.c preserve.c

if fox
fwin_sources = fwin.c FXTerminal.cpp FXMathText.cpp FXShowMath.cpp \
		FXWorker.cpp FXDCNativePrinter.cpp FXPostscriptFont.cpp \
		termed.c
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

generated_sources = $(srcdir)/../csl-c/u01.c $(srcdir)/../csl-c/u02.c \
		$(srcdir)/../csl-c/u03.c $(srcdir)/../csl-c/u04.c \
		$(srcdir)/../csl-c/u05.c $(srcdir)/../csl-c/u06.c \
		$(srcdir)/../csl-c/u07.c $(srcdir)/../csl-c/u08.c \
		$(srcdir)/../csl-c/u09.c $(srcdir)/../csl-c/u10.c \
		$(srcdir)/../csl-c/u11.c $(srcdir)/../csl-c/u12.c

csl_SOURCES = $(core_sources) $(undemo_sources) $(fwin_sources) \
		$(jit_sources) bytes.c stubs.c

if demo
slowr38_SOURCES = $(core_sources) $(undemo_sources) $(fwin_sources) \
		$(jit_sources) bytes1.c $(generated_sources)
else !demo
slowr38_SOURCES = $(core_sources) $(undemo_sources) $(fwin_sources) \
		$(jit_sources) bytes1.c stubs.c
endif !demo

r38_SOURCES = $(core_sources) $(demo_sources) $(fwin_sources) \
		$(jit_sources) bytes.c $(generated_sources)

fontdemo_SOURCES = fontdemo.cpp

showmathdemo_SOURCES = FXShowMath.cpp showmathdemo.cpp

hello_SOURCES = hello.cpp
scribble_SOURCES = scribble.cpp

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

local-slowr38exe.def:	$(srcdir)/slowr38exe.def $(srcdir)/impex.def
	cat $(srcdir)/slowr38exe.def $(srcdir)/impex.def > local-slowr38exe.def

local-slowr38com.def:	$(srcdir)/slowr38com.def $(srcdir)/impex.def
	cat $(srcdir)/slowr38com.def $(srcdir)/impex.def > local-slowr38com.def

local-r38exe.def:	$(srcdir)/r38exe.def $(srcdir)/impex.def
	cat $(srcdir)/r38exe.def $(srcdir)/impex.def > local-r38exe.def

local-r38com.def:	$(srcdir)/r38com.def $(srcdir)/impex.def
	cat $(srcdir)/r38com.def $(srcdir)/impex.def > local-r38com.def

local-cslexe.def:	$(srcdir)/cslexe.def $(srcdir)/impex.def
	cat $(srcdir)/cslexe.def $(srcdir)/impex.def > local-cslexe.def

local-cslcom.def:	$(srcdir)/cslcom.def $(srcdir)/impex.def
	cat $(srcdir)/cslcom.def $(srcdir)/impex.def > local-cslcom.def

CSLEXEDEF = local-cslexe.def
CSLCOMDEF = local-cslcom.def
SLOWR38EXEDEF = local-slowr38exe.def
SLOWR38COMDEF = local-slowr38com.def
R38EXEDEF = local-r38exe.def
R38COMDEF = local-r38com.def

# For a build on Windows I want to add an icon into each binary, via
# a resource-file. I also want linking to be in "windows-subsystem-mode",
# but I also want matching ".com" files to be created to be console
# mode versions.

if microsoft_c
CONAP=-link -subsystem:console -nodefaultlib:libc
if fox
WINAP=-link -entry:mainCRTStartup -subsystem:windows -nodefaultlib:libc
else !fox
WINAP=-link -subsystem:console -nodefaultlib:libc
endif !fox
else !microsoft_c
CONAP=-Wl,--subsystem,console
if fox
WINAP=-Wl,--subsystem,windows
else !fox
WINAP=-Wl,--subsystem,console
endif !fox
endif !microsoft_c

if microsoft_c
if demo
r38res = fwin-demor38.res
else !demo
r38res = fwin-r38.res
endif !demo

fwindemo_LDADD = fwin-icon.res
csl_LDADD = fwin-csl.res
slowr38_LDADD = fwin-csl.res
r38_LDADD = $(r38res)
dyndemo_LDADD = $(srcdir)/dyndemo.def

csl_DEPENDENCIES = local-cslexe.def local-cslcom.def fwin-csl.res r38.fonts/cmr10.pfb
slowr38_DEPENDENCIES = local-slowr38exe.def local-slowr38com.def \
		fwin-csl.res r38.fonts/cmr10.pfb r38.doc/index.html
r38_DEPENDENCIES = local-r38exe.def local-r38com.def $(r38res) r38.fonts/cmr10.pfb r38.doc/index.html
fwindemo_DEPENDENCIES = fwin-icon.res
# Note that if you are using Microsoft C you must create dynmodule.dll
# explicitly.
dyndemo_DEPENDENCIES = $(srcdir)/dyndemo.def

if fox
fontdemo_DEPENDENCIES = r38.fonts/cmr10.pfb
showmathdemo_DEPENDENCIES = r38.fonts/cmr10.pfb
endif fox

fwin-icon.res:	$(srcdir)/fwin-icon.rc
	rc /fo fwin-icon.res $(srcdir)/fwin-icon.rc

fwin-csl.res:	$(srcdir)/fwin-csl.rc
	rc /fo fwin-csl.res $(srcdir)/fwin-csl.rc

fwin-r38.res:	$(srcdir)/fwin-r38.rc
	rc /fo fwin-r38.res $(srcdir)/fwin-r38.rc

fwin-demor38.res:	$(srcdir)/fwin-demor38.rc
	rc /fo fwin-demor38.res $(srcdir)/fwin-demor38.rc

else !microsoft_c

dyndemo_LDADD = $(srcdir)/dyndemo.def

if demo
r38res = fwin-demor38.$(OBJEXT)
else !demo
r38res = fwin-r38.$(OBJEXT)
endif !demo

fwindemo_LDADD = fwin-icon.$(OBJEXT)
csl_LDADD = fwin-csl.$(OBJEXT)
slowr38_LDADD = fwin-csl.$(OBJEXT)
r38_LDADD = $(r38res)

csl_DEPENDENCIES = local-cslexe.def local-cslcom.def fwin-csl.$(OBJEXT) \
		r38.fonts/cmr10.pfb
slowr38_DEPENDENCIES = local-slowr38exe.def local-slowr38com.def \
		fwin-csl.$(OBJEXT) r38.fonts/cmr10.pfb r38.doc/index.html
r38_DEPENDENCIES = local-r38exe.def local-r38com.def $(r38res) r38.fonts/cmr10.pfb r38.doc/index.html
fwindemo_DEPENDENCIES = fwin-icon.$(OBJEXT)
dyndemo_DEPENDENCIES = $(srcdir)/dyndemo.def dynmodule.dll

if fox
fontdemo_DEPENDENCIES = r38.fonts/cmr10.pfb
showmathdemo_DEPENDENCIES = r38.fonts/cmr10.pfb
endif fox

fwin-icon.$(OBJEXT):	$(srcdir)/fwin-icon.rc
	$(WINDRES) $(srcdir)/fwin-icon.rc --include-dir=$(srcdir) \
		-o fwin-icon.$(OBJEXT)

fwin-csl.$(OBJEXT):	$(srcdir)/fwin-csl.rc
	$(WINDRES) $(srcdir)/fwin-csl.rc --include-dir=$(srcdir) \
		-o fwin-csl.$(OBJEXT)

fwin-r38.$(OBJEXT):	$(srcdir)/fwin-r38.rc
	$(WINDRES) $(srcdir)/fwin-r38.rc --include-dir=$(srcdir) \
		-o fwin-r38.$(OBJEXT)

fwin-demor38.$(OBJEXT):	$(srcdir)/fwin-demor38.rc
	$(WINDRES) $(srcdir)/fwin-demor38.rc --include-dir=$(srcdir) \
		-o fwin-demor38.$(OBJEXT)

endif !microsoft_c

else !windows
CONAP=
WINAP=

CSLEXEDEF =
CSLCOMDEF =
SLOWR38EXEDEF =
SLOWR38COMDEF =
R38EXEDEF =
R38COMDEF =

csl_DEPENDENCIES = r38.fonts/cmr10.pfb
slowr38_DEPENDENCIES = r38.fonts/cmr10.pfb r38.doc/index.html
r38_DEPENDENCIES = r38.fonts/cmr10.pfb r38.doc/index.html

if fox
fontdemo_DEPENDENCIES = r38.fonts/cmr10.pfb
showmathdemo_DEPENDENCIES = r38.fonts/cmr10.pfb
endif fox

# On non-windows systems I am ASSUMING here that the C compiler will
# accept an "-o" option to indicate where it should put its object file.
#
fwin-csl.$(OBJEXT):	$(srcdir)/null.c
	$(COMPILE) -c $(srcdir)/null.c -o fwin-csl.$(OBJEXT)

fwin-r38.$(OBJEXT):	$(srcdir)/null.c
	$(COMPILE) -c $(srcdir)/null.c -o fwin-r38.$(OBJEXT)

fwin-demor38.$(OBJEXT):	$(srcdir)/null.c
	$(COMPILE) -c $(srcdir)/null.c -o fwin-demor38.$(OBJEXT)

# end of windows vs non-windows conditions
endif !windows

# The next line is because CXXLINK has "-o $@" as part of it and in this
# case I want to have separate control of the destination of the executable
# that I create. In doing it this way I ASSUME (and in general this can not
# be guaranteed) that the expression "-o destination" will be what works.

CXXLINKTO = $(CXXLD) $(AM_CXXFLAGS) $(CXXFLAGS) $(AM_LDFLAGS) $(LDFLAGS)

if xp64
# BEWARE BEWARE BEWARE the next line must NOT have trailing blanks
DEST=-Fe
else !xp64
# BEWARE BEWARE BEWARE the next line must have trailing blanks
DEST=-o   
endif !xp64

csl$(EXEEXT): $(csl_OBJECTS) $(csl_DEPENDENCIES)
	-rm -f csl$(EXEEXT)
	$(CXXLINKTO) $(CSLEXEDEF) $(DEST)csl$(EXEEXT) $(csl_OBJECTS) $(csl_LDADD) $(LIBS) $(WINAP)
if windows
if fox
	-rm -f csl.com
	$(CXXLINKTO) $(CSLCOMDEF) $(DEST)csl.com $(csl_OBJECTS) $(csl_LDADD) $(LIBS) $(CONAP)
endif fox
endif windows
if !debug
if !microsoft_c
if !darwin
	$(STRIP) csl$(EXEEXT)
if windows
if fox
	$(STRIP) csl.com
endif fox
endif windows
endif !darwin
endif !microsoft_c
endif !debug

r38$(EXEEXT): $(r38_OBJECTS) $(r38_DEPENDENCIES)
	-rm -f r38$(EXEEXT)
	$(CXXLINKTO) $(R38EXEDEF) $(DEST)r38$(EXEEXT) $(r38_OBJECTS) $(r38_LDADD) $(LIBS) $(WINAP)
if windows
if fox
	-rm -f r38.com
	$(CXXLINKTO) $(R38COMDEF) $(DEST)r38.com $(r38_OBJECTS) $(r38_LDADD) $(LIBS) $(CONAP)
endif fox
endif windows
if !debug
if !microsoft_c
if !darwin
	$(STRIP) r38$(EXEEXT)
if windows
if fox
	$(STRIP) r38.com
endif fox
endif windows
endif !darwin
endif !microsoft_c
endif !debug

slowr38$(EXEEXT): $(slowr38_OBJECTS) $(slowr38_DEPENDENCIES)
	-rm -f slowr38$(EXEEXT)
	$(CXXLINKTO) $(SLOWR38EXEDEF) $(DEST)slowr38$(EXEEXT) $(slowr38_OBJECTS) $(slowr38_LDADD) $(LIBS) $(WINAP)
if windows
if fox
	-rm -f slowr38.com
	$(CXXLINKTO) $(SLOWR38COMDEF) $(DEST)slowr38.com $(slowr38_OBJECTS) $(slowr38_LDADD) $(LIBS) $(CONAP)
endif fox
endif windows
if !debug
if !microsoft_c
if !darwin
	$(STRIP) slowr38$(EXEEXT)
if windows
if fox
	$(STRIP) slowr38.com
endif fox
endif windows
endif !darwin
endif !microsoft_c
endif !debug

fwindemo$(EXEEXT): $(fwindemo_OBJECTS) $(fwindemo_DEPENDENCIES)
	-rm -f fwindemo$(EXEEXT)
	$(CXXLINKTO) $(DEST)fwindemo$(EXEEXT) $(fwindemo_OBJECTS) $(fwindemo_LDADD) $(LIBS) $(WINAP)
if windows
if fox
	-rm -f fwindemo.com
	$(CXXLINKTO) $(DEST)fwindemo.com $(fwindemo_OBJECTS) $(fwindemo_LDADD) $(LIBS) $(CONAP)
endif fox
endif windows
if !debug
if !microsoft_c
if !darwin
	$(STRIP) fwindemo$(EXEEXT)
if windows
if fox
	$(STRIP) fwindemo.com
endif fox
endif windows
endif !darwin
endif !microsoft_c
endif !debug

if fox
hello$(EXEEXT): $(hello_OBJECTS) $(hello_DEPENDENCIES)
	-rm -f hello$(EXEEXT)
	$(CXXLINKTO) $(DEST)hello$(EXEEXT) $(hello_OBJECTS) $(hello_LDADD) $(LIBS) $(WINAP)
if !debug
if !microsoft_c
if !darwin
	$(STRIP) hello$(EXEEXT)
endif !darwin
endif !microsoft_c
endif !debug

scribble$(EXEEXT): $(scribble_OBJECTS) $(scribble_DEPENDENCIES)
	-rm -f scribble$(EXEEXT)
	$(CXXLINKTO) $(DEST)scribble$(EXEEXT) $(scribble_OBJECTS) $(scribble_LDADD) $(LIBS)
if !debug
if !microsoft_c
if !darwin
	$(STRIP) scribble$(EXEEXT)
endif !darwin
endif !microsoft_c
endif !debug

fontdemo$(EXEEXT): $(fontdemo_OBJECTS) $(fontdemo_DEPENDENCIES)
	-rm -f fontdemo$(EXEEXT)
	$(CXXLINKTO) $(DEST)fontdemo$(EXEEXT) $(fontdemo_OBJECTS) $(fontdemo_LDADD) $(LIBS) $(CONAP)
if !debug
if !microsoft_c
if !darwin
	$(STRIP) fontdemo$(EXEEXT)
endif !darwin
endif !microsoft_c
endif !debug

showmathdemo$(EXEEXT): $(showmathdemo_OBJECTS) $(showmathdemo_DEPENDENCIES)
	-rm -f showmathdemo$(EXEEXT)
	$(CXXLINKTO) $(DEST)showmathdemo$(EXEEXT) $(showmathdemo_OBJECTS) $(showmathdemo_LDADD) $(LIBS) $(CONAP)
if !debug
if !microsoft_c
if !darwin
	$(STRIP) showmathdemo$(EXEEXT)
endif !darwin
endif !microsoft_c
endif !debug

if windows

csl.com:	$(csl_OBJECTS) $(csl_DEPENDENCIES)
	-rm -f csl.exe
	$(MAKE) csl.exe

r38.com:	$(r38_OBJECTS) $(r38_DEPENDENCIES)
	-rm -f r38.exe
	$(MAKE) r38.exe

slowr38.com:	$(slowr38_OBJECTS) $(slowr38_DEPENDENCIES)
	-rm -f slowr38.exe
	$(MAKE) slowr38.exe

fwindemo.com:	$(fwindemo_OBJECTS) $(fwindemo_DEPENDENCIES)
	-rm -f fwindemo.exe
	$(MAKE) fwindemo.exe

endif windows
endif fox

r38.fonts/cmr10.pfb:	$(srcdir)/fonts
	-rm -rf r38.fonts
	-mkdir r38.fonts
	$(CP) $(srcdir)/fonts/README r38.fonts
	$(CP) $(srcdir)/fonts/README.cmps-fonts r38.fonts
	$(CP) $(srcdir)/fonts/*.ttf r38.fonts
	$(CP) $(srcdir)/fonts/*.pfb r38.fonts
	$(CP) $(srcdir)/fonts/*.pfa r38.fonts
	$(CP) $(srcdir)/fonts/fonts.dir r38.fonts
	$(CP) $(srcdir)/fonts/fonts.scale r38.fonts
	-mkdir r38.fonts/pfmfiles
	$(CP) -r $(srcdir)/fonts/pfmfiles/*.pfm r38.fonts/pfmfiles
	-mkdir r38.fonts/src
	$(CP) -r $(srcdir)/fonts/src/*.gz r38.fonts/src

if exeext

# The next section is to conspire with automake's treatement of externions for
# executables (ie ".exe") so that eg "make r38" will case "make r38.exe" to
# happen. The use of parameter substitution to generate the plain targets is
# because in that case automake will not auto-map the target adding ".exe".

plain_csl = csl
plain_r38 = r38
plain_slowr38 = slowr38
plain_fwindemo = fwindemo
plain_termdemo = termdemo
plain_fontdemo = fontdemo
plain_showmathdemo = showmathdemo
plain_hello = hello
plain_scribble = scribble
plain_dyndemo = dyndemo

if fox
$(plain_csl):	csl.exe csl.com
	echo "make csl.exe is preferred"

$(plain_r38):	r38.exe r38.com
	echo "make r38.exe is preferred"

$(plain_slowr38):	slowr38.exe slowr38.com
	echo "make slowr38.exe is preferred"

$(plain_fwindemo):	fwindemo.exe fwindemo.com
	echo "make fwindemo.exe is preferred"

$(plain_fontdemo):	fontdemo.exe
	echo "make fontdemo.exe is preferred"

$(plain_showmathdemo):	showmathdemo.exe
	echo "make showmathdemo.exe is preferred"

$(plain_hello):	hello.exe
	echo "make hello.exe is preferred"

$(plain_scribble):	scribble.exe
	echo "make scribble.exe is preferred"
else !fox
$(plain_csl):	csl.exe
	echo "make csl.exe is preferred"

$(plain_r38):	r38.exe
	echo "make r38.exe is preferred"

$(plain_slowr38):	slowr38.exe
	echo "make slowr38.exe is preferred"

$(plain_fwindemo):	fwindemo.exe
	echo "make fwindemo.exe is preferred"

endif !fox

$(plain_termdemo):	termdemo.exe
	echo "make termdemo.exe is preferred"

if microsoft_c
$(plain_dyndemo):	dyndemo.exe dynmodule.dll
	echo "make dyndemo.exe; make dynmodule.dll is preferred"
else !microsoft_c
$(plain_dyndemo):	dyndemo.exe dynmodule.dll
	echo "make dyndemo.exe is preferred"
endif !microsoft_c
endif exeext

if mac_framework
# on Darwin I want to go
# /Developer/Tools/Rez -t APPL -o r38 $(srcdir)/mac.r
# (and similarly for csl) after linking, so that the items concerned
# become clickable. Note that "mac.r" is copied directly from the
# FLTK distribution (www.fltk.org) and it is released there under
# LGPL with an array of extra permissions that mean that static
# linking is permitted and it is not necessary to be as careful
# to distribute copies of licenses as it is with the regular LGPL.
#
# Well to be a little more precise, I want to do that if the MacOS framework
# is available. on raw Darwin it will not be.

if demo
make-clickable:	slowr38 r38
else !demo
make-clickable:	csl slowr38 r38
	/Developer/Tools/Rez -t APPL -o csl $(srcdir)/mac.r
endif !demo
	/Developer/Tools/Rez -t APPL -o slowr38 $(srcdir)/mac.r
	/Developer/Tools/Rez -t APPL -o r38 $(srcdir)/mac.r

endif mac_framework

if cygwin
# on cygwin I scan to verify which DLLs are referenced by my main
# executables so that I can verify (eg) that they do not link to
# cygwin1.dll or any other library that is liable to impose license
# conditions that affect distribution rules.
if demo
report-dlls:	slowr38.exe r38.exe
else !demo
report-dlls:	csl.exe slowr38.exe r38.exe
	objdump -p csl.exe | grep "DLL"
endif !demo
	objdump -p slowr38.exe | grep "DLL"
	objdump -p r38.exe | grep "DLL"
endif cygwin

fwindemo_SOURCES=fwindemo.c $(fwin_sources)

termdemo_SOURCES=termdemo.c termed.c

#
# Possibly unreasonably (but it is WHAT I DO!) image files for CSL live
# in the same directory as executables.
#

if demo
image_files = r38.img r38.doc r38.fonts
else !demo
image_files = csl.img r38.img r38.doc r38.fonts
endif !demo
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
if demo
# I will suppose that I never make a demo version on platforms where I do not
# have FOX working...
console_binaries = r38.com wgnuplot.exe wgnuplot.mnu wgnuplot.hlp
noinstall_console_binaries = slowr38.com
else !demo
if fox
console_binaries = csl.com r38.com wgnuplot.exe wgnuplot.mnu wgnuplot.hlp
noinstall_console_binaries = slowr38.com fwindemo.com
else !fox
console_binaries = wgnuplot.exe wgnuplot.mnu wgnuplot.hlp
noinstall_console_binaries =
endif !fox
endif !demo
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

local_image_files = slowr38.img

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

local_image_files = slowr38.img

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


#=============================================================================
#
# The main final target is r38.img, the image file for full REDUCE.
# If you want to rebuild stage-by-stage (eg while testing), try the
# sequence
#    make slowr38            compiles and links C coded kernel
#    make slowr38.img            makes bootstrap REDUCE
#                                 (roughly twice as slow as final one)
#                                 only used for system recompilation.
#    make profile                 runs tests, collects profile information.
#                                 This takes a long time!
#    make prof-inst               installs profile data
#    make c-code                  Create files u*.c and u*.lsp
#                                 out of hot-spot parts of REDUCE.
#=============================================================================
# Note that only the steps from here downwards are usually needed
#
#    make r38                final compilation of most of REDUCE
#    make r38.img                build final image file
if !demo
#    make testall                 runs test files, output to log directory
#    make checkall                creates log/checkall.log
endif !demo
#
#
#=============================================================================



default:	r38$(EXEEXT) r38.img

# This is the command needed to compile a module for use as a DLL or other
# dynamically loaded module

DLL_CFLAGS = @DLL_CFLAGS@

COMPILE_DLL = $(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) \
	$(CPPFLAGS) $(AM_CFLAGS) $(DLL_CFLAGS)

if windows
if microsoft_c
dyndef = $(srcdir)/dynmodule.def dyndemo.lib
# In the win64 case I have to build dyndemo.exe before dynmodule.dll because
# a side-effect of creating dyndemo.exe is that dyndemo.lib gets made. Thus
# I must avoid making a circular dependency and dyndemo.exe must not
# formally depend on dynmodule.dll.
dyndep = dyndemo.exe
else !microsoft_c
dyndef = $(srcdir)/dynmodule1.def
dyndep =
endif !microsoft_c
else !windows
dyndef =
dyndep =
endif !windows

if xp64
DLLIB=bufferoverflowU.lib
else !xp64
DLLIB=
endif !xp64

dynmodule.$(DLLEXT):	dynmodule.c dynmodule.def $(dyndep)
	$(COMPILE_DLL) $(dyndef) $(srcdir)/dynmodule.c $(DLLIB) $(DEST)dynmodule.$(DLLEXT)

if microsoft_c

# If I am cross-compiling for win64 I still need to run these two little
# utilities. They are not very large or fussy programs and so I am going to
# assume that I can compile them in the simplest possible way using gcc,
# which I will assume is installed and native. Note that if I an running
# on a real Windows XP-64 system I will still want cygwin installed and
# then these will get compiled as 32-bit programs. That is just fine by me!

if xp64
# ensure that this gets built FIRST at least if you go "make all", however
# "make csl" or "make bytes.obj" (etc) will not trigger this. Hmmm.
BUILT_SOURCES = cl-wrap.exe

endif xp64

NOCYGWIN=-mno-cygwin

cl-wrap.exe:	$(srcdir)/cl-wrap.c
	gcc $NOCYGWIN $(srcdir)/cl-wrap.c -o cl-wrap.exe

objtype.exe:	$(srcdir)/objtype.c
	gcc $(NOCYGWIN) $(srcdir)/objtype.c -o objtype.exe

makeheaders.exe:	$(srcdir)/makeheaders.c
	gcc $(NOCYGWIN) $(srcdir)/makeheaders.c -o makeheaders.exe

else !microsoft_c

if canrun

objtype$(EXEEXT):	$(srcdir)/objtype.c
	$(COMPILE) $(srcdir)/objtype.c -o objtype$(EXEEXT)

makeheaders$(EXEEXT):	$(srcdir)/makeheaders.c
	$(COMPILE) $(srcdir)/makeheaders.c -o makeheaders$(EXEEXT)

else !canrun

# If I can not run programs built by the normal C compiler (eg because I am
# cross-compiling) I will build these two utilities using gcc. I will blandly
# assume that in any cross-compilation situation that gcc is available
# and works, and the assumption is simplified by the fact that these two
# programs are botf fairly small and conservative.

objtype$(EXEEXT):	$(srcdir)/objtype.c
	gcc $(NOCYGWIN) $(srcdir)/objtype.c -o objtype$(EXEEXT)

makeheaders$(EXEEXT):	$(srcdir)/makeheaders.c
	gcc $(NOCYGWIN) $(srcdir)/makeheaders.c -o makeheaders$(EXEEXT)

endif !canrun

endif !microsoft_c

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

if demo
r38.img:	r38$(EXEEXT) slowr38$(EXEEXT)
else !demo
r38.img:	r38$(EXEEXT)
endif !demo
	touch r38.img
	-$(RM) r38.img
if canrun
if demo
	./slowr38 -w -v -z -or38.img -Dno_init_file $(srcdir)/../util/build38.lsp -D@srcdir=$(srcdir) -- log/full38.log
else !demo
	$(srcdir)/../util/full38.sh $(srcdir)
endif !demo
else !canrun
	echo Can not build r38.img on this platform
endif !canrun

# Copy HTML help files in a directory r38.doc - also install gnuplot if windows
r38.doc/index.html:
	touch r38.doc
	-$(RM) -rf r38.doc
	$(CP) -r $(srcdir)/../r38.doc r38.doc
if windows
# I also unpack copies of the gnuplot binaries into this directory.
# Note that I have a binary of zip in the support-packages directory
# but I am going to require here that a version that works under whatever
# shell you are using is on your path... Install it somewhere if you need to.
	unzip -d . -j -o \
		../support-packages/gp400win32.zip \
		gnuplot/bin/wgnuplot.exe gnuplot/bin/wgnuplot.hlp \
		gnuplot/bin/wgnuplot.mnu
# I view it as most unwelcome that I need the "chmod" here, but if I have
# gcc/g++ on my path and available I will suppose I can have chmod too.
	chmod +x wgnuplot.exe
endif windows

slowr38.img:	slowr38$(EXEEXT)
	touch slowr38.img
	-$(RM) slowr38.img
if canrun
	$(srcdir)/../util/boot38.sh $(srcdir)
else !canrun
	echo Can not build slowr38.img on this platform
endif !canrun

profile:	slowr38.img
if canrun
	$(srcdir)/../util/profile.sh $(srcdir)
else !canrun
	echo Can not profile on this platform
endif !canrun

prof-inst:	profile.dat
	$(CP) profile.dat $(srcdir)/../csl-c
	touch profile.dat
	-$(RM) profile.dat

c-code:	slowr38.img
if canrun
	$(srcdir)/../util/c-code38.sh $(srcdir)
else !canrun
	echo Can not generate C code on this platfrom
endif !canrun

testslow:	slowr38.img
if canrun
	$(srcdir)/../util/testslow.sh $(srcdir)
else !canrun
	echo Can not run tests on this platfrom
endif !canrun

testall:	r38.img
if canrun
	$(srcdir)/../util/testrest.sh $(srcdir)
else !canrun
	echo Can not run tests on this platfrom
endif !canrun

checkall:	r38.img
if canrun
	$(srcdir)/../util/checkall.sh $(srcdir)
else !canrun
	echo Can not check test results on this platfrom
endif !canrun

# This target is to be retired when I have reviewed the Reduce 3.8 patch
# scheme.
patchup:	r38.img
if canrun
	$(srcdir)/../util/patchup.sh $(srcdir)
else !canrun
	echo Can not install REDUCE patches on this platfrom
endif !canrun

cleanlog:
	-$(RM) $(srcdir)/../../../log/*.rlg



csl.img:	csl$(EXEEXT) $(srcdir)/compat.lsp $(srcdir)/compiler.lsp \
			$(srcdir)/ccomp.lsp $(srcdir)/extras.lsp
	touch csl.img
	-$(RM) csl.img
if canrun
	./csl$(EXEEXT) -w -v -z $(srcdir)/build0.lsp \
		-D@cslbase="$(srcdir)" -l log/cslimg.log
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
guisrc=$(fontdemo_SOURCES) $(showmathdemo_SOURCES) $(hello_SOURCES) $(scribble_SOURCES)
else !fox
guisrc=
endif !fox
mainsrc=$(guisrc) $(fwindemo_SOURCES) $(termdemo_SOURCES) $(r38_SOURCES)
if demo
srcfiles=$(mainsrc)
else !demo
srcfiles=$(mainsrc) $(csl_SOURCES)
endif !demo

if fox
guibin=fontdemo$(EXEEXT) showmathdemo$(EXEEXT) hello$(EXEEXT) scribble$(EXEEXT)
else !fox
guibin=
endif !fox
mainbin=$(guibin) fwindemo$(EXEEXT) termdemo$(EXEEXT) r38$(EXEEXT)
if windows
mainbin+=fwindemo.com r38.com
endif windows
if demo
binfiles=$(mainbin)
else !demo
binfiles=$(mainbin) csl$(EXEEXT)
if windows
binfiles+=csl.com
endif windows
endif !demo

save:	all
	echo Save files from this build
	echo MAKE=$(MAKE)
	$(srcdir)/save-objs.sh $(srcdir) $(OBJEXT) $(FOXLIB) -f $(srcfiles)
	$(srcdir)/save-files.sh $(ARCHITECTURE) $(binfiles)
	$(srcdir)/save-relink.sh $(ARCHITECTURE) $(binfiles)
	./relink.sh

# end of Makefile


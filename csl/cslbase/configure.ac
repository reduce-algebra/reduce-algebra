## Process this file with autoconf to produce a configure script.

# A C Norman.                                         2008-2010

#
# Special flags that can be used here:
#
#   --with-m32        Force 32-bit compilation when host is 64-bit gcc
#   --with-m64        Force 64-bit compilation even if default is 32-bit
# Both --with-m32 and --with-m64 should be viewed as archaic, in that
# building for a word-width that is not the main native one for the
# build platform should be treated as cross compilation using "--host=xxx".
# Various versions of gcc now seem to be withdrawing support form "-m32" and
# "-m64"...
#
#   --with-lto        Try link-time optimisation with gcc. EXPERIMENTAL.
#   --with-cygwin     Build native cygwin X11 based system, 
#                     Please note cygwin licensing issues, which do not
#                     have any adverse effects so long as you retain BSD
#                     licensing here. But if you included CSL in a closed
#                     product (as BSD permits) think about this!
#   --with-smallpage  build in way that may be better for small embedded
#                     machines.
#   --enable-debug    Switch on debugging.
#
#
#   --enable-conservative   development version not working yet!
#   --enable-test     predefine a symbol TEST used to protect
#                     temporary or unfinished code developments.
#   --enable-jit      another experimental and incomplete extension.
#   --enable-embedded well the EMBEDDED option is intended for use via
#                     a heavily cleaned up minimalist build system, but
#                     for testing purposes I allow a build here.

#   --host=<triplet>  cross compile for that host.
# Eg if I have installed the 64-bit mingw compilers that cygwin supports
# I can go  --host=x86_64-w64-mingw32  and build everything.
# The "--with-mingw64" option is a convenience feature for use by
# a higher level configure script and should not be used directly here.
# 


# FOX gets built in a directory whose name is based on the platform
# it supports. In simple cases this is just the GNU triple, as in
# i686-pc-linux etc. However there are a range of cases when I will
# change that. These are the things I note above as "special flags"

# Specify the name of this "application" and a version number
AC_INIT([REDUCE],[6.04])
AM_INIT_AUTOMAKE([1.8.3 -Wall -Wno-portability -Wno-override foreign dist-bzip2])

here=`pwd`
AC_MSG_NOTICE([+++ Configure in directory $here +++])

# Explain that a file "config.h" should be generated
AC_CONFIG_HEADERS([config.h])

AC_COPYRIGHT([Codemist Ltd])

AC_PREREQ(2.59)

# My source file is expected to have "csl.c" in it. This is just a small
# sanity check in case somebody tries to configure with directories
# messed up.
AC_CONFIG_SRCDIR(csl.c)
AC_CONFIG_FILES(Makefile)

AC_DEFINE(CSL, [1], [True to tell sources that this build is part of CSL])

AC_DEFINE(NILSEG_EXTERNS, [1], [Makes use of a debugger easier, I hope.])

AC_ARG_WITH(csl,
  AC_HELP_STRING([--with-csl], [Use the CSL Lisp system]),
  [],
  [with_csl="no"])

AC_ARG_WITH(psl,
  AC_HELP_STRING([--with-psl], [Use the PSL Lisp system. Do not use here!]),
  [],
  [with_psl="no"])

AC_ARG_WITH(mingw64,
  AC_HELP_STRING([--with-mingw64], [this option is ignored here!]),
  [],
  [])

AC_ARG_WITH(SDK,
  AC_HELP_STRING([--with-SDK], [Eg try --with-SDK=10.7. For CSL/MacOSX]),
  [],
  [with_SDK="10.8"])

AC_ARG_WITH(gui,
  AC_HELP_STRING([--with-gui], [this option is ignored here!]),
  [],
  [])

# What host am I on?
AC_CANONICAL_HOST()

AC_ARG_WITH(build,
   AC_HELP_STRING([--with-build], [specify host-name to use when logging]),
   [],
   [with_build="unknown"])

BUILTFOR="$with_build"

AC_ARG_WITH(pslbuild,
   AC_HELP_STRING([--with-pslbuild], [used if I wish to call the PSL version]),
   [],
   [with_pslbuild="unknown"])

AC_DEFINE_UNQUOTED(PSLBUILD,["$with_pslbuild"], [Show where a matching PSL might live])

AC_ARG_WITH(cygbuild,
   AC_HELP_STRING([--with-cygbuild], [used if I wish to call the cygwin version]),
   [],
   [with_cygbuild="unknown"])

AC_SUBST(with_cygbuild)

AC_ARG_WITH(cygbuild64,
   AC_HELP_STRING([--with-cygbuild64], [used if I wish to call the 64-bit cygwin version]),
   [],
   [with_cygbuild64="unknown"])

AC_SUBST(with_cygbuild64)

if test "x$BUILTFOR" = "xunknown"
then
  BUILTFOR=`eval "$SHELL $srcdir/../scripts/findhost.sh $host $ac_configure_args"`
  AC_MSG_NOTICE([Build platform detected as $BUILTFOR])
else
  AC_MSG_NOTICE([Build platform specified as $BUILTFOR])

fi

AC_DEFINE_UNQUOTED(BUILTFOR,["$BUILTFOR"], [Architecture this is built to run on])

AC_SUBST(BUILTFOR)
AC_SUBST(PSLBUILD)

AC_SUBST(DLL_CFLAGS)

# The following are always to be defined when I go through this route

AC_DEFINE(HAVE_FWIN,[1],[True if we will use the FWIN terminal code])
AC_DEFINE(WINDOW_SYSTEM,[1],[True for a (potentially) Windowed system])

AC_DEFINE_UNQUOTED(HOST_CPU,"$host_cpu",[Name of CPU])
AC_DEFINE_UNQUOTED(HOST_VENDOR,"$host_vendor",[Name of vendor])
AC_DEFINE_UNQUOTED(HOST_OS,"$host_os",[Name of Operating System])

AC_ARG_WITH(lto,
   AC_HELP_STRING([--with-lto],
                  [Force extreme optimisation with gcc]),
   [],
   [with_lto="no"])

# The next line may be of use when building on a 64-bit system that uses
# gcc. It forces "-m32" into CFLAGS etc.

AC_ARG_WITH(m32,
   AC_HELP_STRING([--with-m32],
                  [Force 32-bit model even on 64-bit gcc (deprecated)]),
   [],
   [with_m32="no"])

if test "x$with_m32" = "xyes"
then
  bits32="yes"
fi

# gcc only: Force "-m64" into CFLAGS etc.

AC_ARG_WITH(m64,
   AC_HELP_STRING([--with-m64],
                  [Force 64-bit model even if 32-bit is default (deprecated)]),
   [],
   [with_m64="no"])

if test "x$with_m64" = "xyes"
then
  bits64="yes"
fi

AC_ARG_WITH(fox,
  AC_HELP_STRING([--with-fox=DIR],
                 [FOX installation location]),
  [],
  [with_fox="no"])
AC_MSG_NOTICE([--with-fox=$with_fox])

AC_ARG_WITH(wx,
  AC_HELP_STRING([--with-wx],
                 [enable use of wxWidgets]),
  [],
  [with_wx="no"])
AC_MSG_NOTICE([--with-wx=$with_wx])

AC_ARG_WITH(cygwin,
  AC_HELP_STRING([--with-cygwin],
                 [Force use of raw cywgin (note Cygwin license)]),
  [],
  [with_cygwin="no"])

AC_ARG_WITH(force,
  AC_HELP_STRING([--with-force],
                 [Used at a higher level]),
  [],
  [with_force="no"])

if test "x$with_fox" != "xno" || test "x$with_wx" != "xno"
then
  with_gui="yes"
else
  with_gui="no"
fi

AC_SUBST(MAKE)
AC_SUBST(AR)
AC_SUBST(STRIP)
AC_SUBST(SED)
AC_SUBST(WINDRES)
AC_SUBST(REZ)
AC_SUBST(DLLTOOL)
AC_SUBST(OBJDUMP)

# The next two should only be required if you are building for windows
# (cygwin or native style) and are wanting to create a DLL to be loaded
# by my code.

if test "x$WINDRES" = "x"
then
  AC_CHECK_TOOL(WINDRES, windres, windres)
fi

if test "x$DLLTOOL" = "x"
then
  AC_CHECK_TOOL(DLLTOOL, dlltool, dlltool)
fi

if test "x$OBJDUMP" = "x"
then
  AC_CHECK_TOOL(OBJDUMP, objdump, objdump)
fi

AC_MSG_NOTICE([host=$host])

case $host in
x86_64-w64-*)
  AC_DEFINE(WIN32, [1], [True if we are running on Windows])
  AC_DEFINE(WIN64, [1], [True if we are running on 64-bit Windows])
  CPPFLAGS="$CPPFLAGS"
  DLL_CFLAGS="$CFLAGS -shared"
  LDFLAGS="$LDFLAGS -static"
  windows_build="yes"
  exeext="yes"
  X_BASE_LIBS=""
  win64="yes"
  ;;
*-*-cygwin* | *-*-*mingw*)
  AC_MSG_NOTICE([Building under cygwin])
  AC_MSG_NOTICE([with_cygwin=<$with_cygwin>])
  x86="yes"
  exeext="yes"
  if test "x$with_cygwin" != "xno"
  then
# If you go "--with-cygwin" in the call to configure then I will build
# in native cygwin mode, and not use the "-mno-cywgin" flag (or the more
# modern cross-compiler-style equivalent mechanisms). As a consequence
# some GPL libraries will be linked with your application. The cygwin
# license has a special exception so that when cygwin1.dll is linked
# with other code that is subject to an approved Open Source License
# the GPL constraints do not come into force, but that nature of the
# BSD license that CSL is subject to is that it would be quite proper
# to extent it with non-open components or use it in a non-open context,
# and the BSD license was adopted in part because I do not wish to apply
# any constraints that would prevent that. Therefore before I just link
# in any code that tried to "protect freedom by insisting that people
# give it up" I will ensure that I provide clear and explicit notice and
# warning of what is happening.
#
#
    AC_MSG_NOTICE([************************************************])
    AC_MSG_NOTICE([** "--with-cygwin" set so I will link in the  **])
    AC_MSG_NOTICE([** library cygwin1.dll, which is subject to   **])
    AC_MSG_NOTICE([** the Cygwin's license terms. Please check.  **])
    AC_MSG_NOTICE([** Specifically do not distribute what you    **])
    AC_MSG_NOTICE([** build in this mode without fully           **])
    AC_MSG_NOTICE([** the obligations imposed by this license.   **])
    AC_MSG_NOTICE([************************************************])
# The next line may ALMOST count as a lie, but under raw cygwin the world
# is closer to Unix than to Windows so this does make some sense!
    AC_DEFINE(UNIX,[1],[True if we are running on Unix, Linux, BSD etc])
# The next line gives further refinement in case there are places where
# I have to take account of the very special case I am in. 
    AC_DEFINE(RAW_CYGWIN, [1], [True if we are running on RAW Cygwin])
    CPPFLAGS="$CPPFLAGS -I/usr/include/ncurses -I/usr/include/freetype2"
    if test "x$with_gui" != "xno"
    then
      LDFLAGS="$LDFLAGS -L/usr/X11R6/lib"
    fi
    DLL_CFLAGS="$CFLAGS -shared"
    XLIBS="-lXext -lX11"
    cygwin_build="yes"
# Here is the normal situation where cygwin is the BUILD environment. Mostly
# that means using the mingw-style version of the compiler via
# "i686-w64-mingw32-gcc".
  else
    AC_MSG_NOTICE([Windows built creating native binary])
    AC_DEFINE(WIN32, [1], [True if we are running on Windows])
    LDFLAGS="$LDFLAGS -static"
    DLL_CFLAGS="$CFLAGS -shared"
# In this case I make the machine appear to be "i686-pc-windows" or some
# such to distinguish it from the case where cygwin1.dll might be involved.
    foxdir=`echo $foxdir | sed -e 's/cygwin/windows/'`
    windows_build="yes"
    exeext="yes"
  fi
  X_BASE_LIBS=""
  ;;
*-*-msdos* | *-*-go32* | *-*-windows*)
  AC_MSG_ERROR([For Windows you are expected to use cygwin as your build environment])
  ;;
*-*solaris*)
  AC_MSG_NOTICE([Building for Solaris])
# I USED to somewhat encourage the use of the Sun compiler "cc" here but now
# I am testing using Solaris 10 x86 and gcc seems available and adequate.
# Note that by setting CC and CXX before using "configure" you can select
# the compiler of your choice. However there is a risk that I need to
# specify explicit paths so if they are not set by the user I will force
# something here! The paths shown here are the ones I find installed on
# Solaris 10 x86 from the Software Companion DVD. This all seems pretty
# HORRID to me!
  if test "x$CC" = "x"
  then
    AC_PATH_PROGS(CC, gcc, gcc, [/usr/sfw/bin:$PATH])
  fi
  if test "x$CXX" = "x"
  then
    AC_PATH_PROGS(CXX, g++, g++, [/usr/sfw/bin:$PATH])
  fi 
  if test "x$MAKE" = "x"
  then
    AC_PATH_PROGS(MAKE, [gmake make], make, [/usr/sfw/bin:$PATH])
  fi
  if test "x$AR" = "x"
  then
    AC_PATH_PROGS(AR, [gar ar], ar, [/usr/sfw/bin:$PATH])
  fi
  if test "x$STRIP" = "x"
  then
    AC_PATH_PROGS(STRIP, [gstrip strip], strip, [/usr/sfw/bin:$PATH])
  fi
  if test "x$SED" = "x"
  then
    AC_PATH_PROGS(SED, [gsed sed], sed, [/usr/sfw/bin:$PATH])
  fi
  if test "x$with_gui" != "xno"
  then
    LDFLAGS="$LDFLAGS -L/usr/X11R6/lib"
  fi
  XLIBS="-lXext -lX11"
  DLL_CFLAGS="$CFLAGS -shared"
  AC_DEFINE(SOLARIS, [1], [True if we are running on Solaris])
  solaris="yes"
  ;;
*darwin*)
  AC_MSG_NOTICE([Building for Macintosh/Darwin with X11])
  darwin_build="yes"
  AC_DEFINE(MACINTOSH, [1], [True if we are running on Macintosh])
# Here if the person who invoked configure had arranged to specify
# CC or CXX (to something other than gcc and g++) then it becomes
# THEIR responsibility to arrange all other relavant flags (eg CFLAGS,
# LDFLAGS, LIBS) to as to access a relevant SDK etc etc. ANY problems
# that arise because they hand down options that lead to failures in
# compilation of any sort at all are then THEIR job to resolve by providing
# settings that are satisfactory.
  XLIBS="-lXext -lX11"
  macintosh_build="yes"
  darwin_build="yes"
  if test "x$CC$CXX" == "x" || (test "x$CC" == "xgcc" && test "x$CXX" == "xg++")
  then
# The following line was suggested by the libEDIT configuration files.
# Even though I no longer use libEDIT I will keep it!
#
# OK. -fno-common causes C programs to lead to a linker error if you have
#     declarations of variables in several files. It may thus count as
#     and extra safety measure.
#     -no-cpp-precomp was historically useful because some people
#     found that the Apple pre-processor gave them trouble, so I think it
#     arranges a slower but possibly safer compilation. It is probably not
#     needed at all these days.
    CFLAGS="$CFLAGS -fno-common -no-cpp-precomp"
    CXXFLAGS="$CXXFLAGS -fno-common -no-cpp-precomp"
# At least maybe MacOS 10.2 may not put X11 headers on the standard include
# path by default, so I help it out here. In later releases it should be
# present already, but an extra chance to scan ought not to hurt anybody.
# Note that 10.2 now counts as seriously archaic.
    CPPFLAGS="$CPPFLAGS -fno-common -no-cpp-precomp -flat_namespace -I/usr/X11R6/include"
    DLL_CFLAGS="$CFLAGS -bundle -undefined suppress"
    AC_DEFINE(UNIX,[1],[True if we are running on Unix, Linux, BSD etc])
    LDFLAGS="$LDFLAGS -L/usr/X11R6/lib -flat_namespace"
    LDFLAGS="$LDFLAGS -framework Carbon -framework CoreServices -framework ApplicationServices"
# I need to make a provisional judgement about whether I will be supporting
# fat binaries here so that if I am I can disable dependency tracking. The
# mode of dependency tracking gets decided during the elaboration of
# AC_PROG_CC, and the "proper" test for fat binary support can only happen
# after I have found myself a C compiler. Since I KNOW I am on MacOSX here
# I will make the test command-line simple and explicit, not using $CFLAGS
# or any such.
    archflags=""
    AC_LANG_CONFTEST(
      [AC_LANG_PROGRAM([], [])])
    oldSDKloc=/Developer/SDKs
    newSDKloc=/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs
    if test -e $newSDKloc/MacOSX$with_SDK.sdk
    then
      SDK=$newSDKloc/MacOSX$with_SDK.sdk
    elif test -e $oldSDKloc/MacOSX$with_SDK.sdk
    then
      SDK=$oldSDKloc/MacOSX$with_SDK.sdk
    else
      AC_MSG_ERROR([SDK $with_SDK not found])
    fi
    if gcc -isysroot $SDK -arch x86_64 -arch ppc conftest.c -o conftest > /dev/null 2>&1
    then
      archflags="-arch x86_64 -arch ppc"
    elif gcc -isysroot $SDK -arch x86_64 conftest.c -o conftest > /dev/null 2>&1
    then
      archflags="-arch x86_64"
    elif gcc -isysroot $SDK -arch ppc conftest.c -o conftest > /dev/null 2>&1
    then
      archflags="-arch ppc"
    else
      AC_MSG_ERROR([Failed to compile test code-fragment using SDK $with_SDK])
    fi
  fi
  AC_CHECK_PROGS(REZ,[/usr/bin/Rez /Developer/tools/Rez],[Rez])
  ;;
*-freebsd*)
  AC_MSG_NOTICE([Building on FreeBSD])
  AC_DEFINE(UNIX,[1],[True if we are running on Unix, Linux, BSD etc])
  if test "x$target" = "x"
  then
    xtarget="$host"
  else
    xtarget="$target"
  fi
  case $xtarget in
  *i386* | *i486* | *i586* | *i686* | *x86* | *amd64*)
     x86="yes"
     ;;
  esac
# To survive 64-bit Linux the next line seems needed. I will leave it for
# BSD since is a /usr/X11R6/lib64 directory does not exist no harm will
# be done.
  if test "x$with_gui" != "xno"
  then
    if test "x$bits32" != "xyes" && test "x$cross_compiling" != "xyes"
    then
      AC_CHECK_FILE([/usr/X11R6/lib64],[XLL=lib64],[XLL=lib])
    else
      XLL=lib
    fi
    LDFLAGS="$LDFLAGS -L/usr/X11R6/$XLL"
  fi
  LDFLAGS="$LDFLAGS -pthread"
  DLL_CFLAGS="$CFLAGS -shared"
  XLIBS="-lXext -lX11"
  ;;
*)
  AC_MSG_NOTICE([Assuming a Unix-like environment, including Linux])
  AC_MSG_NOTICE([host=$host, target=$target])
  AC_DEFINE(UNIX,[1],[True if we are running on Unix, Linux, BSD etc])
  if test "x$target" = "x"
  then
    xtarget="$host"
  else
    xtarget="$target"
  fi
  case $xtarget in
  *i386* | *i486* | *i586* | *i686* | *x86* | *amd64*)
     x86="yes"
     ;;
  esac
# To survive 64-bit Linux the next line seems needed.
  if test "x$with_gui" != "xno"
  then
    if test "x$bits32" != "xyes" && test "x$cross_compiling" != "xyes"
    then
      AC_CHECK_FILE([/usr/X11R6/lib64],[XLL=lib64],[XLL=lib])
    else
      XLL=lib
    fi
    LDFLAGS="$LDFLAGS -L/usr/X11R6/$XLL"
  fi
  DLL_CFLAGS="$CFLAGS -shared"
  XLIBS="-lXext -lX11"
  ;;
esac

# In some cases there may be explicitly GNU versions of various utilities,
# and I will perhaps use them if I find them.

if test "x$MAKE" = "x"
then
  AC_CHECK_PROGS(MAKE,[gmake make],[make])
fi
if test "x$AR" = "x"
then
  AC_CHECK_PROGS(AR,[gar ar],[ar])
fi
if test "x$STRIP" = "x"
then
  AC_CHECK_PROGS(STRIP,[gstrip strip],[echo])
fi
if test "x$SED" = "x"
then
  AC_CHECK_PROGS(SED,[gsed sed],[sed])
fi

AC_CHECK_PROGS(VALGRIND, [valgrind], [x])

AC_ARG_WITH(fox-pending,
  AC_HELP_STRING([--with-fox-pending],
                 [do not check dir from --with-fox]),
  [],
  [with_fox_pending="no"])
AC_MSG_NOTICE([--with-fox-pending=$with_fox_pending])

# Here I will adjust foxdir to mention the Linux distribution involved
# in case that I can discover that. The effect is that my (adjusted)
# "triple" will be something like say
#     i686-pc-fedora_6    OR   powerpc-macos_10.4_tiger-darwin8.8.0
# rather than
#     i686-pc=linux-gnu   OR   powerpc-apple-darwin8.8.0

distrib=`"$srcdir/findos.sh"`
AC_MSG_NOTICE([distrib = $distrib])

if test "x$distrib" != "xunknown"
then
  foxdir=`echo $foxdir | sed -e s/linux-gnu/$distrib/`
  foxdir=`echo $foxdir | sed -e s/apple/$distrib/`
fi

if test "x$bits32" = "xyes"
then
  foxdir="$foxdir-m32"
fi

if test "x$bits64" = "xyes"
then
  foxdir="$foxdir-m64"
fi

# Debugging turned on?
AC_MSG_CHECKING(for debugging)
AC_ARG_ENABLE(debug,
  AC_HELP_STRING([--enable-debug],
                 [compile for debugging]),
  [],
  [enable_debug="no"])
AC_MSG_RESULT([$enable_debug])

if test "x$enable_debug" = "xyes"
then
  foxdir="$foxdir-debug"
fi

AC_MSG_NOTICE([foxdir = $foxdir])
# Architecture is only used by the "make save" option, which is a relic
# of older times.
AC_SUBST(ARCHITECTURE)
ARCHITECTURE="$foxdir"

# Want to build "conservative" variant?
AC_MSG_CHECKING(for conservative)
AC_ARG_ENABLE(conservative,
  AC_HELP_STRING([--enable-conservative],
                 [garbage collect option]),
  [],
  [enable_conservative="no"])
AC_MSG_RESULT([$enable_conservative])

if test "x$enable_conservative" = "xyes"
then
  AC_DEFINE(CONSERVATIVE, [1], [True if GC experiment enabled])
fi

# Want to build "test" variant?
AC_MSG_CHECKING(for test)
AC_ARG_ENABLE(test,
  AC_HELP_STRING([--enable-test],
                 [testing-mode version]),
  [],
  [enable_test="no"])
AC_MSG_RESULT([$enable_test])

if test "x$enable_test" = "xyes"
then
  AC_DEFINE(TEST, [1], [True if this is an experimental testing mode variant])
fi

# Want to build "embedded" variant?
AC_MSG_CHECKING(for embedded)
AC_ARG_ENABLE(embedded,
  AC_HELP_STRING([--enable-embedded],
                 [embedded-mode version]),
  [],
  [enable_embedded="no"])
AC_MSG_RESULT([$enable_embedded])

if test "x$enable_embedded" = "xyes"
then
  AC_DEFINE(EMBEDDED, [1], [True if this is with no GUI and aimed at embedded use])
fi

if test "x$x86" = "xyes"
then
  AC_DEFINE(X86, [1], [True if Intel or AMD (32 or 64-bit)])
fi

# Checks for programs.

#
# AC_PROG_CC sets CFLAGS to "-g -O2" if it was not already set to
# something else and if gcc was in use. I view that as not what I want!
# so I try to preserve CFLAGS here
#

# find C compiler & preprocessor
# I will not need C++ unless FOX is available and I try to build a GUI
# version, but maybe it does not hurt a lot to look for it regardless.



old_CFLAGS="$CFLAGS"
old_CXXFLAGS="$CXXFLAGS"
AC_MSG_NOTICE([Looking for C pre-processor])
AC_PROG_CPP
AC_MSG_NOTICE([Looking for C compiler])
AC_PROG_CC
# I will use per-target CPPFLAGS so need this...
AM_PROG_CC_C_O
AC_MSG_NOTICE([Looking for C++ pre-processor])
AC_PROG_CXXCPP
AC_MSG_NOTICE([Looking for C++ compiler])
AC_PROG_CXX
CFLAGS="$old_CFLAGS"
CXXFLAGS="$old_CXXFLAGS"

# Some newer versions of gcc support a new gnu (rather then sysv) format
# of part of object files. The effect of this new format it to speed up
# dynamic linking, perhaps by a factor of 2. That is good! But an object
# made using only the new scheme fails with a floating point exception
# when you try to run it on an older system. That is it fails while being
# loaded, not while being run. Fedora Core 6 (at least) by default
# uses just the new format, and so generates VERY non-portable executables.
# Enabling the "both" option here should soften the impact...

AC_MSG_NOTICE([Checking for "--hash-style=both"])
if test "x$GCC" = "xyes"
then
  OLDLDFLAGS="$LDFLAGS"
  LDFLAGS="$LDFLAGS -Wl,--hash-style=both"
  AC_LINK_IFELSE([AC_LANG_PROGRAM([[#include <stdio.h>]],
                                  [[printf("\n");]])],
    [AC_MSG_NOTICE(Will use --hash-style=both)],
    [LDFLAGS="$OLDLDFLAGS"
     AC_MSG_NOTICE(--hash-style=both not available)])
fi

# $bits32 gets set to "yes" if I pass the "--with-m32" option. This is
# intended for use when the build-machine is a 64-bit one but I want to
# create a 32-bit compatible system. This is a fairly commonplace situation
# on 64-bit Linux where gcc is a bi-architecture compiler, with the flag
# "-m32" switching it to work for 32-bit targets. Trying to use this option
# other than with gcc in the above situation will be ineffective.

# On a Mac one should not need to use this because multi-arch binaries are
# built by default.

if test "x$bits32" = "xyes"
then
  AC_MSG_CHECKING([if -m32 option can be used])
  if test "x$GCC" = "xyes"
  then
     OLDCFLAGS="$CFLAGS"
     CFLAGS="$CFLAGS -m32"
     AC_LINK_IFELSE([AC_LANG_PROGRAM([[#include <stdio.h>]],
                                     [[printf("\n");]])],
       [AC_MSG_NOTICE([Using -m32 to force 32-bit compilation])
        CXXFLAGS="$CXXFLAGS -m32"
        LDFLAGS="$LDFLAGS -m32"],
       [CFLAGS="$OLDCPPFLAGS"
         AC_MSG_NOTICE([This version of gcc does not accept -m32])])
  else
    AC_MSG_NOTICE([--with-m32 specified but not using gcc])
  fi
fi

# Similarly for $bits64

if test "x$bits64" = "xyes"
then
  AC_MSG_CHECKING([if -m64 option can be used])
  if test "x$GCC" = "xyes"
  then
    OLDCFLAGS="$CFLAGS"
    CFLAGS="$CFLAGS -m64"
    AC_LINK_IFELSE([AC_LANG_PROGRAM([[#include <stdio.h>]],
                                    [[printf("\n");]])],
      [AC_MSG_NOTICE([Using -m64 to force 64-bit compilation])
       CXXFLAGS="$CXXFLAGS -m64"
       LDFLAGS="$LDFLAGS -m64"],
      [CFLAGS="$OLDCPPFLAGS"
        AC_MSG_NOTICE([This version of gcc does not accept -m64])])
  else
    AC_MSG_NOTICE([--with-m64 specified but not using gcc])
  fi
fi

# I have alternative ways of doing things on Windows and Macintosh, but
# for systems that use gcc (and I am perhaps most thinking of Linux here)
# I want the flag "-rdynamic" enabled (if possible) so that dynamic modules
# (xxx.so) can be loaded with dlopen/dlsym and can access symbols set
# in the main executable.

# Note that this just checks if the flag "-rdynamic" causes compilation to
# FAIL. In some cases it can lead to a compiler warning but then be
# ignored.

if test "x$windows_build" != "xyes"
then
  if test "x$macintosh_build" != "xyes"
  then
# If I am using gcc then I would like to use the flag "-rdynamic" when I
# link. I must test and avoid using if if it will cause failure
    AC_MSG_NOTICE([Checking for "-rdynamic"])
    if test "x$GCC" = "xyes"
    then
      OLDLDFLAGS="$LDFLAGS"
      LDFLAGS="$LDFLAGS -rdynamic"
      AC_LINK_IFELSE([AC_LANG_PROGRAM([[#include <stdio.h>]],
                                      [[printf("\n");]])],
        [rdynamic_available="yes"],
# This test behaves as if it succeeded if gcc did not actually refuse to
# work if given a flag "-rdynamic", but it seems that it also lets through
# cases where gcc issues a warning that -rdynamic was not recognised as
# an option. I guess that is fairly harmless, although it may cause
# people who see it to worry.
        [LDFLAGS="$OLDLDFLAGS"
        rdynamic_available="no"])
    else
      rdynamic_available="no"
    fi
  else
    rdynamic_available="no"
  fi
  AC_MSG_NOTICE([rdynamic=$rdynamic_available])
fi

if test "x$darwin_build" = "xyes"
then
# I COULD be trying to build on raw Darwin without MacOS present, and in that
# case Carbon etc will not be available.
  AC_MSG_NOTICE([Checking for "-framework"])
  if test "x$GCC" = "xyes"
  then
    OLDLDFLAGS="$LDFLAGS"
    LDFLAGS="$LDFLAGS -framework Carbon -framework CoreServices -framework ApplicationServices"
    AC_LINK_IFELSE([AC_LANG_PROGRAM([[#include <stdio.h>]],
                                    [[printf("\n");]])],
      [framework_available="yes"],
      [LDFLAGS="$OLDLDFLAGS"
      framework_available="no"])
  else
    framework_available="no"
  fi
  AC_MSG_NOTICE([framework=$framework_available])
  if test "x$framework_available" = "xyes"
  then
    AC_DEFINE(MAC_FRAMEWORK,[1],[Apple MacOS frameworks available])
  fi

  AC_MSG_NOTICE([Checking for ability to build multi-arch binaries])
# If it seems to be supported at all I will go "-arch ppc -arch x86_64" to
# build a fat binary that will run on both powerpc and intel-based
# macs. If that is not supported by the SDK I am using I will drop back
# to just using x86_64 if that is available, or just ppc otherwise.
# *NOTE* that when doing a multi-arch build dependency tracking using the
# mcchanisms that automake usually tries to use will FAIL. I work around that
# by providing a customised version of "depcomp".
#
# Also in the Macintosh/Darwin I have had special hand-crafted code to
# detect the case and switch off dependency checking as if the user had
# run this script with "-disable_dependency_tracking" as a command-line
# option.
#
  if test "x$GCC" = "xyes"
  then
    if test "x$macintosh_build" = "xyes"
    then
      sysroot=""
      AC_MSG_NOTICE([Checking for MacOSX framework])
      OLDCFLAGS="$CFLAGS"
      CFLAGS="$CFLAGS -isysroot $SDK"
      AC_LINK_IFELSE([AC_LANG_PROGRAM([[#include <stdio.h>]],
                                      [[printf("\n");]])],
        [CXXFLAGS="$CXXFLAGS -isysroot $SDK"
         AC_MSG_NOTICE([MacOS SDK found as $SDK])
         sysroot="$SDK"],
        [CFLAGS="$OLDCFLAGS"
         AC_MSG_ERROR([MacOS SKD NOT found])])
    fi
  fi
fi

# I might like to be able to force generation of position-independent
# code, and GCC has a directive -fPIC. This checks if it is accepted.
# Specifically when I am generating a loadable module this can be needed.
# However for Windows the option does not cause GCC to fail but it does
# load to a warning that it has no effect, so I will avoid even trying to
# activate it then (for x86 all case is position independent anyway).

if test "x$windows_build" != "xyes"
then
  AC_MSG_NOTICE([Checking for "-fPIC"])
  if test "x$GCC" = "xyes"
  then
    OLDCFLAGS="$CFLAGS"
    CFLAGS="$CFLAGS -fPIC"
    AC_LINK_IFELSE([AC_LANG_PROGRAM([[#include <stdio.h>]],
                                     [[printf("\n");]])],
       [fpic_available="yes"],
       [fpic_available="no"])
    CFLAGS="$OLDCFLAGS"
  else
    fpic_available="no"
  fi
  AC_MSG_NOTICE([-fPIC=$fpic_available])

  if test "x$fpic_available" = "xyes"
  then
    DLL_CFLAGS="$DLL_CFLAGS -fPIC"
  fi
fi

if test "x$solaris" = "xyes"
then
# I believe that the Sun C compilers need a "-mt" flag so here I check if
# such a flag is accepted and if so I will use it.
  OLDCFLAGS="$CFLAGS"
  CFLAGS="$CFLAGS -mt"
  AC_LINK_IFELSE([AC_LANG_PROGRAM([[#include <stdio.h>]],
                                  [[printf("\n");]])],
                 [CXXFLAGS="$CXXFLAGS -mt"],
                 [CFLAGS="$OLDCFLAGS"])
fi

if test "x$with_lto" != "xno"
then
  AC_MSG_NOTICE([Checking for link time optimisation capability (LTO)])
  if test "x$GCC" = "xyes"
  then
    OLDCFLAGS="$CFLAGS"
    OLDLDFLAGS="$LDFLAGS"
    CFLAGS="$CFLAGS -flto"
    LDFLAGS="$LDFLAGS -flto"
    AC_LINK_IFELSE([AC_LANG_PROGRAM([[#include <stdio.h>]],
                                    [[printf("\n");]])],
      [CXXFLAGS="$CXXFLAGS -flto"
       HIGHOPT="-O3"
       AC_MSG_NOTICE(Will use link-time optimisation and -O3)],
      [CFLAGS="$OLDCFLAGS"
       LDFLAGS="$OLDLDFLAGS"
       AC_MSG_NOTICE(-flto not available)])
  fi
fi

if test "x$with_gui" != "xno"
then
  if (test "x$windows_build" != "xyes" || test "x$with_cygwin" != "xno")
  then
# I will not even look for Xft if I am building for win32 not X.
#
# Furthermore I will not try xft-config if I am cross-compiling. This may
# be a mess if I ever try to cross compile towards a machine that needs it.
    AC_ARG_WITH(xft,
      AC_HELP_STRING([--with-xft],
                     [Can be used to disable use of XFT. Default is yes]),
      [],
      [with_xft="yes"])
    if test "x$with_xft" != "xno" && test "x$cross_compiling" != "xyes"
    then
      AC_PATH_PROGS(XFT_CONFIG, xft-config, [no],
        [/usr/local/bin:/usr/X11R6/bin:/usr/sfw/bin:/usr/csw/bin:$PATH])
      if test "$XFT_CONFIG" != "no"
      then
# I will add to CFLAGS and XLIBS if xft-config is found
        xft_cflags=`$XFT_CONFIG --cflags`
        CFLAGS="$CFLAGS $xft_cflags"
        CXXFLAGS="$CXXFLAGS $xft_cflags"
        CPPFLAGS="$CPPFLAGS $xft_cflags"
        xft_libs=`$XFT_CONFIG --libs`
        XLIBS="$XLIBS $xft_libs"
# NB that xft-config hands back some stuff that I might believe should
# perhaps be in LDFLAGS not LIBS, but never mind! Also done this way we
# may get some libraries mentioned more than once in LIBS - I hope that
# will not cause pain.
        AC_DEFINE(HAVE_LIBXFT, [1], [True Xft is available])
        AC_MSG_NOTICE([xft-config found, so Xft should be available])
      else
# here xft-config is NOT present, but it may be that xft headers and
# libraries are nevertheless available. I will look for freetype-config
# which may also help me...
        AC_PATH_PROGS(FREETYPE_CONFIG, freetype-config, [no],
          [/usr/local/bin:/usr/sfw/bin:$PATH])
        if test "$FREETYPE_CONFIG" != "no"
        then
# I will add to CFLAGS and XLIBS if freetype-config is found, an in fact I
# will then leave them there even if then Xft is not found. That is perhaps
# slightly untidy.
          freetype_cflags=`$FREETYPE_CONFIG --cflags`
          CFLAGS="$CFLAGS $freetype_cflags"
          CXXFLAGS="$CXXFLAGS $freetype_cflags"
          CPPFLAGS="$CPPFLAGS $freetype_cflags"
          freetype_libs=`$FREETYPE_CONFIG --libs`
          XLIBS="$XLIBS $freetype_libs"
          xft_found="yes"
          AC_CHECK_LIB(fontconfig, FcConfigCreate)
          AC_CHECK_LIB(Xft, XftFontOpen,,[xft_found="no"])
          AC_CHECK_HEADER(X11/Xft/Xft.h,,[xft_found="no"])
          if test "$xft_found" = "yes"
          then
            AC_DEFINE(HAVE_LIBXFT, [1], [True Xft is available])
            AC_MSG_NOTICE([freetype-config found, and Xft should be available])
          fi
        else
# Now a search without the benefit of helper tools.
          xft_found="yes"
          AC_CHECK_LIB(fontconfig, FcConfigCreate)
          AC_CHECK_LIB(Xft, XftFontOpen,,[xft_found="no"])
          AC_CHECK_HEADER(X11/Xft/Xft.h,,[xft_found="no"])
          if test "$xft_found" = "yes"
          then
            AC_DEFINE(HAVE_LIBXFT, [1], [True Xft is available])
          fi
        fi
      fi
    fi
  fi
fi

if test "x$xft_found" != "xyes"
then
# Now a search without the benefit of helper tools.
  xft_found="yes"
  AC_CHECK_LIB(fontconfig, FcConfigCreate)
  AC_CHECK_LIB(Xft, XftFontOpen,,[xft_found="no"])
  AC_CHECK_HEADER(X11/Xft/Xft.h,,[xft_found="no"])
  if test "$xft_found" = "yes"
  then
    AC_DEFINE(HAVE_LIBXFT, [1], [True Xft is available])
  fi
fi

# find command to do best approx to "ln -s" and set LN_S		
AC_PROG_LN_S

# Building (experimental) version that has a JIT?
AC_MSG_CHECKING(for JIT support)
AC_ARG_ENABLE(jit,
  AC_HELP_STRING([--enable-jit],
                 [build in experimental JIT]),
  [],
  [enable_jit="no"])
AC_MSG_RESULT([$enable_jit])

if test "x$enable_jit" = "xyes"
then
  AC_DEFINE(JIT, [1], [True if we are building with a JIT])
fi

# Static linking wanted?
# NOTE that at present I only do anything about this if compiling with "gcc"
# since then I expect that just including "-static" in LDFLAGS will do the
# trick for me.
AC_MSG_CHECKING(for static linking)
AC_ARG_ENABLE(static,
  AC_HELP_STRING([--enable-static],
                 [link it all statically]),
  [],
  [enable_static="no"])
AC_MSG_RESULT([$enable_static])

# In lots of cases I will be using gcc. In that case I will use -O2 for
# release code, but -O0 when debugging. I also stick in -Wall so I get
# loads of comments about code style etc. For other C compilers I do
# not set any optimisation flags but I do expect "-g" to be available
# to enable debugging.

#
# Well as of late 2003/early 2004 some versions of gcc appears to compile
# some of my code at -O3 in ways that hurt me, but at -O2 mostly things seem
# better behaved. At one stage I believed that my trouble might have been
# to do with "Strict Aliasing" but I am less convinced of that now - however
# to be cautious I switch off that aspect of gcc. I really want this code
# to compile and run first-time on as many systems as I can and so tuning
# down the optimisation level from -O3 to -O2 is probably worthwhile even
# though it hits performance a little. Furthermore in 2008 I found that
# some things behaved in ways I did not understand with "-O1 -g" hence I
# drop back to "-O0 -g".
#

LOWOPT="-O0"
if test "x$HIGHOPT" = "x"
then
  HIGHOPT="-O2"
fi

case $CC in
x86_64-w64-*)
  AC_DEFINE(WIN64, [1], [True if we are running on Windows (64 bit)])
  ;;
esac

AC_ARG_WITH(smallpage,
   AC_HELP_STRING([--with-smallpage],
                  [Use smaller block of memory to suit tiny computers]),
   [],
   [with_smallpage="no"])

if test "x$with_smallpage" != "xno"
then
# Using 19 bits here causes allocation in pages each of which is 512Kbytes,
# rather than the default 4M pages. A key limitation this introduces is that
# any Lisp vector may then be at most 128K items long. I hope that not many
# people will worry about that.
  CFLAGS="$CFLAGS -DPAGE_BITS=19"
fi

if test "x$GCC" = "xyes"
then
  if test "x$enable_debug" = "xyes"
  then
# If only to see how many people get upset, I will put "-pg" in the command
# line if debugging is requested. For gcc (at least on many platforms) this
# will enabling profiling so that "gprof" can be used after a run to observe
# where theer were hot-spots. If I get keen I will put in extra tests here to
# check if the "-pg" option is at least acceptable to the compiler... but
# for now it is unconditional based on a belief that those who specify
# --enable-debug will be experienced enough to sort out any mess that could
# arise.  Aha, the initial testing versions of 64-bit cygwin appear to choke
# if you specify profiling, and so I will withdraw this for now but leave the
# indication of how to re-enable it in place here.
#   PROFILE="-pg"
    PROFILE=""
    CFLAGS="${CFLAGS} -fno-strict-aliasing ${LOWOPT} -g ${PROFILE} -DDEBUG=1 -Wall"
    CXXFLAGS="${CXXFLAGS} -fno-strict-aliasing ${LOWOPT} -g ${PROFILE} -DDEBUG=1 -Wall"
    DLL_CFLAGS="${DLL_CFLAGS} -fno-strict-aliasing ${LOWOPT} -g ${PROFILE} -DDEBUG=1 -Wall"
    LDFLAGS="${LDFLAGS} -g ${PROFILE}"
  else
    CFLAGS="$CFLAGS -fno-strict-aliasing ${HIGHOPT} -Wall"
    CXXFLAGS="$CXXFLAGS -fno-strict-aliasing ${HIGHOPT} -Wall"
    DLL_CFLAGS="${DLL_CFLAGS} -fno-strict-aliasing ${HIGHOPT}"
  fi
  if test "x$enable_static" = "xyes"
  then
    LDFLAGS="${LDFLAGS} -static"
  fi
else
#
# BEWARE any other C compilers that take an enthusiastic view on Strict
# Aliasing! It causes real problems with the way that Lisp data is mapped onto
# machine resources. Actually my current reading of the standard makes it feel
# perhaps less horrid than I had at one stage thought...
# I am 
  if test "x$enable_debug" = "xyes"
  then
    CFLAGS="${CFLAGS} -g -DDEBUG=1"
    CXXFLAGS="${CXXFLAGS} -g -DDEBUG=1"
    DLL_CFLAGS="${DLL_CFLAGS} -g -DDEBUG=1"
    LDFLAGS="${LDFLAGS} -g"
  fi
fi

# On at least some systems static linking against X11 needs -ldl
# Also I will use dlopen (and friends) for dynamic loading of stuff
# compiled via C.
AC_CHECK_LIB(dl, dlopen)

# Fox 1.6 seems to use nanosleep in FXThread and on some systems at least
# the means I must link against librt.
AC_CHECK_LIB(rt, clock_nanosleep)

AC_CHECK_LIB(pthread, pthread_create)

if test "x$with_gui" != "xno"
then
  LIBS="$XLIBS $LIBS"
fi

# I want to support some flavour of direct screen addressing. 
# On Windows I use the Console API. 
# Otherwise I need both term.h and [n]curses.h. Sometimes the file
# may be <ncurses/term.h>. If term.h is not available I may survive
# on tgetent.
# For linking I count "tgetent" as an adequate function to test for
# as diagnostic of curses.

# I am giving up on supporting things that only have "termcap" on the
# grounds that that is now supposed to count as ancient.
# At an earlier stage I deeply nested messes of tests here. They became
# confusing! So now I will just check for each header and then work out later
# on if I have enough to support what I need.

if test "x$windows_build" != "xyes" || test "x$with_cygwin" = "xyes"
then
  AC_CHECK_HEADERS(termios.h sys/ioctl.h)

  AC_CHECK_HEADERS(curses.h ncurses.h)

  AC_MSG_NOTICE([curses=$HAVE_CURSES_H ncurses=$HAVE_NCURSES_H])

  AC_CHECK_LIB(curses, tgetent, [],
    [AC_CHECK_LIB(ncurses, tgetent)])

# There is a misery here! "term.h" (on some machines) needs cuses.h
# included first (typically to define "bool" for it).
  AC_CHECK_HEADERS(term.h,[],[],
     [#if HAVE_CURSES_H
      #include <curses.h>
      #else
      #if HAVE_NCURSES_H
      #include <ncurses.h>
      #endif
      #endif])
  AC_CHECK_HEADERS(ncurses/term.h,[],[],
     [#if HAVE_CURSES_H
      #include <curses.h>
      #else
      #if HAVE_NCURSES_H
      #include <ncurses.h>
      #endif
      #endif])

  AC_CHECK_FUNCS([tgetent tputs])

# Now I have access to some terminfo support. I would like to know if
# the convenience function cfmakeraw is present since if so I will use
# it, but if it is not there I will just simulate what I hope it does.
  AC_CHECK_FUNCS(cfmakeraw)

fi

# Some platforms appear to require the Xcursor library. The next line
# should arrange that it gets scanned if it is available.
# It is obviously irrelevant on Windows and if no GUI is required,
# However Solarix 10 x86 seems to misdetect Xrender when in
# 64-bit mode so I fudge that away here.

if test "x$with_gui" != "xno" &&
   test "x$solaris" != "xyes" &&
   (test "x$windows_build" != "xyes" ||
     test "x$with_cygwin" = "xyes")
then
  AC_SEARCH_LIBS(XRenderCreateCursor, Xrender)
  AC_SEARCH_LIBS(XcursorImageCreate, Xcursor)
  AC_SEARCH_LIBS(XRRQueryVersion, Xrandr)
fi

# Checks for header files.
AC_HEADER_DIRENT
AC_HEADER_SYS_WAIT

AC_CHECK_HEADER([stdint.h],
                [stdint_header=y
                 AC_DEFINE(HAVE_STDINT_H, 1)],
                [stdint_header=n])
AC_MSG_NOTICE([stdint_header=$stdint_header])

AC_CHECK_HEADER([inttypes.h],
                [inttypes_header=y
                 AC_DEFINE(HAVE_INTTYPES_H, 1)],
                [inttypes_header=n])
AC_MSG_NOTICE([inttypes_header=$inttypes_header])

AC_CHECK_HEADERS([fcntl.h float.h malloc.h memory.h])
AC_CHECK_HEADERS([stddef.h stdlib.h string.h sys/resource.h])
AC_CHECK_HEADERS([sys/param.h sys/time.h sys/times.h unistd.h utime.h])
AC_CHECK_HEADERS([arpa/inet.h netdb.h netinet/in.h sys/socket.h sys/stat.h])
AC_CHECK_HEADERS([sys/types.h sys/wait.h sys/shm.h sys/ipc.h signal.h])
AC_CHECK_HEADERS([setjmp.h sys/sysctl.h syscall.h sched.h])


AC_CHECK_TYPES([cpu_set_t], [], [],
   [#ifdef HAVE_SCHED_H
    #include <sched.h>
    #endif])

AC_CHECK_TYPES([struct tms], [], [],
   [#ifdef HAVE_SYS_TIMES_H
    #include <sys/times.h>
    #endif])

AC_CHECK_TYPES([struct timeval], [], [],
   [#ifdef HAVE_SYS_TIME_H
    #include <sys/time.h>
    #endif])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STAT
AC_C_CONST
AC_STRUCT_TM
AC_C_VOLATILE

AC_CHECK_TYPES([int8_t,int16_t,int32_t,int64_t,intptr_t], [], [],
   [#ifdef HAVE_STDINT_H
    #include <stdint.h>
    #endif])
AC_CHECK_TYPES([uint8_t,uint16_t,uint32_t,uint64_t,uintptr_t], [], [],
   [#ifdef HAVE_STDINT_H
    #include <stdint.h>
    #endif])
AC_CHECK_TYPES([u_int8_t,u_int16_t,u_int32_t,u_int64_t,u_intptr_t], [], [],
   [#ifdef HAVE_STDINT_H
    #include <stdint.h>
    #endif])

# With luck the above types from newer C standards will ba available. If
# they are I can rely on them an I then do not need to worry about
# the sized of the older-style native types such as "long". And for
# cross compilation and multi-architecture builds it can be delicate to
# work out the size of types at configure time! But I will do so now and
# use what I find as a fall-back for the unusual case when intptr_t is not
# available. In that case I use these measurements just once to
# define my own versions of int32_t etc etc.
#
# Note that if <stdint.h> is available, which should really almost always
# be the case now, I do NOT do anything here.

if test "x$stdint_header" != "xy"
then
  AC_MSG_NOTICE([Falling back to finding datatype sizes at configure time.])
  AC_CHECK_SIZEOF(void *)
  AC_CHECK_SIZEOF(short int)
  AC_CHECK_SIZEOF(int)
  AC_CHECK_SIZEOF(long)
  AC_CHECK_SIZEOF(long long)
fi

AC_CHECK_TYPES([socklen_t],[],[],[#include <sys/socket.h>])

AC_CHECK_LIB(socket, socket)
AC_CHECK_LIB(nsl, gethostbyname)

# Checks for library functions.
AC_FUNC_CLOSEDIR_VOID
AC_FUNC_ERROR_AT_LINE
AC_FUNC_LSTAT
AC_FUNC_LSTAT_FOLLOWS_SLASHED_SYMLINK
AC_FUNC_MEMCMP
AC_FUNC_SETVBUF_REVERSED
AC_TYPE_SIGNAL
AC_FUNC_STAT
AC_FUNC_UTIME_NULL
AC_FUNC_VPRINTF
AC_CHECK_FUNCS([atexit ftruncate getcwd gethostbyaddr gethostbyname inet_ntoa])
AC_CHECK_FUNCS([memmove memset mkdir pow rmdir socket sqrt strchr strdup])
AC_CHECK_FUNCS([strrchr strstr utime popen getrlimit])
AC_CHECK_FUNCS([fork wait waitpid shmget shmat shmdt shmctl])
AC_CHECK_FUNCS([vsnprintf sysctlbyname gettimeofday times])
AC_CHECK_FUNCS([siglongjmp sigaltstack sigaction])
   
if test x$ac_cv_header_sys_resource_h = "xyes"
then
  AC_CHECK_DECLS([RLIM_SAVED_CUR, RLIM_SAVED_MAX], [], [],
    [[#include <sys/resource.h>]])
fi

# sigsetjmp will be a macro not a function, and so the various predefined
# tests are not very good at detecting it. So I have a custom test here.
AC_LINK_IFELSE([AC_LANG_PROGRAM([[#include <setjmp.h>]],
                                [[static sigjmp_buf env;
                                  int main(int argc, char *argv())
                                  { sigsetjmp(env, 0); return 0; }]])],
  [AC_MSG_NOTICE(sigsetjmp appears to be available)
   AC_DEFINE(HAVE_SIGSETJMP, [1], [sigsetjmp present])],
  [])


# The next bit tests if I can compile and then run programs.
# This information is used in the Makefiles when I appear to be
# cross compiling but neverthless the executables I generate can
# be run. This notably arises when I am building a 64-bit windows
# application using x86_64-w64-mingw32-gcc and my computer is
# running 64-bit windows. If I used the same toolchain but was on
# 32-bit windows the more normal cross-compilation restrictions would
# apply. When I am NOT able to run the "proper" executables I would like
# to I will expect that plain use of "gcc utility.c -o utility" can be
# used to create working utility programs when I need that.


save_cross=cross_compiling
cross_compiling=no
AC_RUN_IFELSE([AC_LANG_PROGRAM([[#include <stdio.h>]],
                               [[printf("\n"); return 0;]])],
              [can_run_executables="yes"],
              [can_run_executables="no"],
              [can_run_executables="no"])
cross_compiling=$save_cross

AC_MSG_NOTICE([Can Run Executables = $can_run_executables])

AC_RUN_IFELSE([AC_LANG_PROGRAM([[]],
  [[int x=-1;int y=x>>1;int z=(y<0)?1:0;return z;]])],
  [odd_shifts="yes"],
  [odd_shifts="no"],
  [odd_shifts="no"])
AC_MSG_NOTICE([Signed shifts logical status = $odd_shifts])
if test "x$odd_shifts" = "xyes"
then
  AC_DEFINE(SIGNED_SHIFTS_ARE_LOGICAL, [1], [Unusual but within ANSI spec])
fi

AC_SUBST(FOX_INCLUDES)
AC_SUBST(FOX_LIBS)


if test "x$with_fox" != "xno"
then
  if test "x$with_fox_pending" != "xno"
  then
    fox_present="yes"
    AC_MSG_NOTICE([Will expect FOX to be in $with_fox])
    FOX_INCLUDES="-I \"$with_fox/include/fox-1.6\""
    FOX_LIBS="-L\"$with_fox/lib\" -lFOX-1.6"
    AC_SUBST(FOXLIB)
    FOXLIB="$with_fox/lib/libFOX*"
    AC_DEFINE(HAVE_LIBFOX, [1], [Fox library present])
# Display FOX level (ie minor version number) if actually present
    if test -f "$with_fox/include/fox-1.6/fxver.h"
    then
      grep LEVEL "$with_fox/include/fox-1.6/fxver.h"
    fi
  else
    if test "x$with_fox" = "x"
    then
      with_fox="/usr/local"
    else if test "x$with_fox" = "xyes"
      then
        with_fox="/usr/local"
      fi
    fi

    if test -d "$with_fox/$foxdir"
    then
      with_fox="$with_fox/$foxdir"
    fi

    AC_MSG_NOTICE("Will look for FOX in $with_fox")

# FOX is unhappy if you try to link (or even compile) in C
# mode so set C++ usage here. Because some other things get confused in
# C++ mode I make this test happen here at the end of my configure script.

# Also I will not even want to try using C++ for anything unless FOX is
# going to be used. Another reason to put this stuff late her.

    AC_LANG(C++)

    cppflags_save="$CPPFLAGS"
    ldflags_save="$LDFLAGS"
    libs_save="$LIBS"

# NB that for FOX I am going to expect the library to be in 
#       $with_fox/lib
# and $with_fox has had a subdir tagged on its end to reflect a 
# modified GNU-style triple, as in i686-pc-linux. So if the
# user says --with-fox=/homes/myself/foxplace and the build is for
# Windows-64 the location inspected will end up
# /homes/myself/foxplace/x86_64-w64-windows64. Etc etc.

# Only look for FOX 1.6. That is because at present the changes
# introduced since then are not important to me but the additional licensing
# constraints are ones I am unwilling to accept.

    AC_SUBST(FOXLIB)
    CPPFLAGS="$CPPFLAGS -I \"$with_fox/include/fox-1.6\""
    LDFLAGS="$LDFLAGS -L \"$with_fox/lib\""
    FOXLIB="$with_fox/lib/libFOX*"
    LIBS="-lFOX-1.6 $LIBS"
    AC_MSG_NOTICE([FOX libraries probably as $FOXLIB])

    AC_LINK_IFELSE(
      [AC_LANG_PROGRAM([#define exit(x) acnexit(x)
                        #include "fx.h"
                        extern "C" char fxfindfox();],
                       [fxfindfox();])],
      [AC_DEFINE(HAVE_LIBFOX, [1], [Fox library present])
       AC_MSG_NOTICE([Found FOX version 1.6])],
      [fox_not_found=1])

    if test "x$fox_not_found" != "x"
    then
      AC_MSG_NOTICE([FOX libraries not found: will not build GUI code])
      CPPFLAGS="$cppflags_save"
      LDFLAGS="$ldflags_save"
      LIBS="$libs_save"
    else
      fox_present="yes"
      CPPFLAGS="$cppflags_save"
      LDFLAGS="$ldflags_save"
      LIBS="$libs_save"
      FOX_INCLUDES="-I \"$with_fox/include/fox-1.6\""
      FOX_LIBS="-L\"$with_fox/lib\" -lFOX-1.6"
# Display FOX level (ie minor version number)
      grep LEVEL "$with_fox/include/fox-1.6/fxver.h"
    fi

  fi

fi

if test "x$with_wx" != "xno"
then
  AC_DEFINE(HAVE_LIBWX, [1], [wxWidgets library will be used])
fi

#
# The extra libraries listed here seem to need to be scanned last.
#

if test "x$windows_build" = "xyes"
then
  case $CC in
  x86_64-w64-*)
    LIBS="$LIBS -ladvapi32 -lshell32 -lcomctl32 -lgdi32 -lws2_32 -lmswsock -lwinspool -lmpr -luser32"
    ;;
  *)
    LIBS="$LIBS -lcomctl32 -lgdi32 -lws2_32 -lwsock32 -lwinspool -lmpr"
    ;;
  esac
fi

if test "x$macintosh_build" = "xyes"
then
# 10.0  Cheetah  )
# 10.1  Puma     )
# 10.2  Jaguar   ) I will not support these at all any more
# 10.3  Panther  )
# 10.4  Tiger    )
# 10.5  Leopard  )
#
# 10.6  Snow Leopard   [Since my test machine runs Lion I will not
#                      be (easily) able to test anything on Snow Leopard]
# 10.7  Lion
# 10.8  Mountain Lion

# Well now that 10.8 has been released I will always target
# 10.6 and support for earlier versions is no longer guaranteed. I may
# well feel obliged to dump 10.6 soon.
  if test "x$with_wx" != "xno"
  then
    ENVP=MACOSX_DEPLOYMENT_TARGET=10.6
  else
    ENVP=MACOSX_DEPLOYMENT_TARGET=10.6
  fi
  CC="$ENVP $CC"
  CXX="$ENVP $CXX"
fi

AC_CHECK_PROGS(CYGPATH,[cygpath],[no])

if test "x$windows_build" != "xyes" && test "x$with_wx" != "xno"
then
# The "xpm" files use to establish icons for wxWindows lead to a lot
# of ugly warnings about casts from strings to (char *) unless I disable
# that particular warning.
  CXXFLAGS="$CXXFLAGS -Wno-write-strings "
fi

AC_SUBST(HOST)
HOST="$host"

#
# Make some things available for conditional segments of a Makefile
#

AM_CONDITIONAL(x86,test "x$x86" = "xyes")
AM_CONDITIONAL(windows,test "x$windows_build" = "xyes")
AM_CONDITIONAL(win64,test "x$win64" = "xyes")
AM_CONDITIONAL(cygwin,test "x$cygwin_build" = "xyes")
AM_CONDITIONAL(darwin,test "x$darwin_build" = "xyes")
AM_CONDITIONAL(mac_framework,test "x$framework_available" = "xyes")
AM_CONDITIONAL(debug,test "x$enable_debug" = "xyes")
AM_CONDITIONAL(exeext,test "x$exeext" = "xyes")
AM_CONDITIONAL(fox,test "x$fox_present" = "xyes")
AM_CONDITIONAL(wx,test "x$with_wx" != "xno")
AM_CONDITIONAL(gui,test "x$fox_present" = "xyes" || test "x$with_wx" != "xno")
AM_CONDITIONAL(jit,test "x$enable_jit" = "xyes")
AM_CONDITIONAL(canrun,test "x$can_run_executables" = "xyes")
AM_CONDITIONAL(cygpath, test "x$CYGPATH" != "xno")
AM_CONDITIONAL(valgrind, test "x$VALGRIND" = "xvalgrind")

AC_OUTPUT

# end of "configure.ac"


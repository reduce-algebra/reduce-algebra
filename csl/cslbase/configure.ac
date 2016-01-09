## Process this file with autoconf to produce a configure script.

# A C Norman.                                         2008-2015

#
# Special flags that can be used here:
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
#   --enable-test     predefine a symbol EXPERIMENT used to protect
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
AC_INIT([REDUCE],[7.00])

# automake 1.13 was the first to support AC_CONFIG_MACRO_DIRS
AM_INIT_AUTOMAKE([1.13 -Wno-portability -Wno-override foreign dist-bzip2])
AC_CONFIG_MACRO_DIRS([m4])

here=`pwd`
AC_MSG_NOTICE([+++ Configure in directory $here +++])

# Explain that a file "config.h" should be generated
AC_CONFIG_HEADERS([config.h])

AC_COPYRIGHT([Codemist])

AC_PREREQ(2.59)

# My source file is expected to have "csl.cpp" in it. This is just a small
# sanity check in case somebody tries to configure with directories
# messed up.
AC_CONFIG_SRCDIR(csl.cpp)
AC_CONFIG_FILES(Makefile)


# aclocal.m4:	configure.ac
# 	aclocal
# config.h.in:	configure.ac
# 	autoheader
# helpers = COPYING INSTALL install-sh missing mkinstalldirs config.sub \
# 		ltmain.sh ltconfig
# Makefile.in $(helpers):	configure.ac Makefile.am aclocal.m4
# 	automake
# Note: automake calls libtool for you when necessary.

# When I configure CSL I will also ensure that the config-related files for
# crlibm and gc-7 are up to date... I will not test for the presence of the
# various helper scripts (eg install-sh, config.sub) that automake can
# install.
# When I tried the fuller set of dependencies as shown above I ran into
# trouble with autoreconf sometimes not leaving date-stamps in the order
# I expcted. That could then lead to an infinite cycle of reconfiguration
# attempts. So now I just look at the master source filed configure.ac and
# Makefile.am, and compare them against the key derived files configure
# and Makefile.in. So the check here can not detect and recover from all
# possible cases where configuration files are out of date, but should
# cope with some of the more common and important cases.

if \
   ! test $srcdir/Makefile.in -nt $srcdir/configure.ac || \
   ! test $srcdir/Makefile.in -nt $srcdir/Makefile.am || \
   ! test $srcdir/configure -nt $srcdir/configure.ac || \
   ! test $srcdir/crlibm/Makefile.in -nt $srcdir/crlibm/configure.ac || \
   ! test $srcdir/crlibm/Makefile.in -nt $srcdir/crlibm/Makefile.am || \
   ! test $srcdir/crlibm/configure -nt $srcdir/crlibm/configure.ac || \
   ! test $srcdir/gc-7/Makefile.in -nt $srcdir/gc-7/configure.ac || \
   ! test $srcdir/gc-7/Makefile.in -nt $srcdir/gc-7/Makefile.am || \
   ! test $srcdir/gc-7/configure -nt $srcdir/gc-7/configure.ac || \
   ! test $srcdir/gc-7/libatomic_ops/Makefile.in -nt $srcdir/gc-7/libatomic_ops/configure.ac || \
   ! test $srcdir/gc-7/libatomic_ops/Makefile.in -nt $srcdir/gc-7/libatomic_ops/Makefile.am || \
   ! test $srcdir/gc-7/libatomic_ops/configure -nt $srcdir/gc-7/libatomic_ops/configure.ac
then
  echo "autoreconf necessary I think $ac_configure_args"
#
# For the following to work properly the sequence MUST leave datestamps
# on files in the order I test for above, which is based on my understanding
# of what depends on what. However on SOME platforms at least I find that
# files do not end up properly ordered and I can get an infinite loop
# of attempred reconfiguration. So for now I withdraw this!
#
# here=`pwd`
# cd $srcdir
# autoreconf -f -i -v
# cd crlibm
# autoreconf -f -i -v
# cd ../gc-7
# autoreconf -f -i -v
# cd $here
# echo "Restart: $srcdir/configure $ac_configure_args"
# exec /bin/sh -c "$srcdir/configure $ac_configure_args"
fi

# These days I am making all the source files for CSL ones in C++ not C
# and so it is best to make configuration tests match.

AC_LANG(C++)

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
   [with_cygbuild=""])

AC_SUBST(with_cygbuild)

AC_ARG_WITH(cygbuild64,
   AC_HELP_STRING([--with-cygbuild64], [used if I wish to call the 64-bit cygwin version]),
   [],
   [with_cygbuild64=""])

AC_SUBST(with_cygbuild64)

AC_SUBST(with_cygbuild64)

AC_ARG_WITH(crlibm,
   AC_HELP_STRING([--with-crlibm], [Can be used to disable use of crlibm]),
   [],
   [with_crlibm="yes"])

if test "x$with_crlibm" != "xno"
then
  AC_DEFINE(HAVE_CRLIBM, [1], [Correct Rounding maths library should be used])
fi

AC_ARG_WITH(boehm,
   AC_HELP_STRING([--with-boehm], [Can be used to disable use of boehm]),
   [],
   [with_boehm="no"])

if test "x$with_boehm" != "xno"
then
  AC_DEFINE(HAVE_BOEHM, [1], [Boehm conservative collector should be available])
fi

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

AC_MSG_NOTICE([Building with host: $host])

cyg32="no"
cyg64="no"
case $host in
*-*-cygwin* | *-*-mingw*)
  AC_MSG_NOTICE([Building under cygwin])
# Note that I may be under either cygwin32 or cygwin64 here...
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
# any constraints that would prevent that.
#
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
    case $host in
    x86_64*)
      cyg64="yes"
      ;;
    *)
      cyg32="yes"
      ;;
    esac
  else
# Here is the normal situation where cygwin is the BUILD environment. Mostly
# that means using the mingw-style version of the compiler via
# "i686-w64-mingw32-gcc".
    AC_MSG_NOTICE([Windows built creating native binary])
    AC_DEFINE(WIN32, [1], [True if we are running on Windows])
# I seem to need to link with "-static" in a Windows mode or else things
# like the C++ library do not get found when I try to run the executables.
# This is of course liable to be an issue of my $PATH, but linking in static
# mode will still keep me safe.
    LDFLAGS="$LDFLAGS -static"
    DLL_CFLAGS="$CFLAGS -shared"
# In this case I make the machine appear to be "i686-pc-windows" or some
# such to distinguish it from the case where cygwin1.dll might be involved.
    foxdir=`echo $foxdir | sed -e 's/cygwin/windows/'`
    windows_build="yes"
    exeext="yes"
  fi
  X_BASE_LIBS=""
  case `uname -m` in
  *i686*)
    cyg32="yes"
    ;;
  *x86_64*)
    cyg64="yes"
    ;;
  *)
    AC_MSG_ERROR([Unknown platform in cygwin build])
    ;;
  esac
  AC_MSG_NOTICE([with_cygwin=<$with_cygwin> cyg32=$cyg32 cyg64=$cyg64])
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
*darwin* | *Darwin*)
  AC_MSG_NOTICE([Building for Macintosh/Darwin with X11])
  darwin_build="yes"
  AC_DEFINE(MACINTOSH, [1], [True if we are running on Macintosh])
# Here if the person who invoked configure had arranged to specify
# CC or CXX (to something other than gcc and g++) then it becomes
# THEIR responsibility to arrange all other relevant flags (eg CFLAGS,
# LDFLAGS, LIBS) so as to access a relevant SDK etc etc. ANY problems
# that arise because they hand down options that lead to failures in
# compilation of any sort at all are then THEIR job to resolve by providing
# settings that are satisfactory.
  CPPFLAGS="$CPPFLAGS -I/opt/local/include -I/opt/local/include/freetype2"
  XLIBS="-lXext -lX11 -lXft -lfontconfig"
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
    CFLAGS="$CFLAGS -fno-common"
    CXXFLAGS="$CXXFLAGS -fno-common"
# At least maybe MacOS 10.2 may not put X11 headers on the standard include
# path by default, so I help it out here. In later releases it should be
# present already, but an extra chance to scan ought not to hurt anybody.
# Note that 10.2 now counts as seriously archaic. Really use of X11 at all
# on OSX is not very forward-looking!
    CPPFLAGS="$CPPFLAGS -fno-common -I/usr/X11R6/include"
    DLL_CFLAGS="$CFLAGS -bundle -undefined suppress"
    AC_DEFINE(UNIX,[1],[True if we are running on Unix, Linux, BSD etc])
    LDFLAGS="$LDFLAGS -L/usr/X11R6/lib -L/opt/local/lib -L/opt/X11/lib"
    LDFLAGS="$LDFLAGS -framework Carbon -framework CoreServices -framework ApplicationServices"
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
    if test "x$cross_compiling" != "xyes"
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
    if test "x$cross_compiling" != "xyes"
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

# I need a C++ compiler that is use to compile small utility programs.
# Im some cases I can not use $CXX because that is a cross-compiler that
# generates binaries that I can not run. I used to just use "g++" and hope,
# but here I will see which of g++, clang++, c++ and CC is at least present.
# I will then assume that that is a viable compiler to use.

AC_PATH_PROGS(LOCALCXX, [g++ clang++ c++ CC], g++, [])

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

AC_CHECK_PROGS(VALGRIND,[valgrind],[x])

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
  AC_DEFINE(EXPERIMENT, [1], [True if this is an experimental testing mode variant])
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

LT_INIT([disable-static])

if test "x$XLIBS" != "x"
then
  AC_PATH_X
fi

# Some newer versions of gcc support a new gnu (rather then sysv) format
# of part of object files. The effect of this new format it to speed up
# dynamic linking, perhaps by a factor of 2. That is good! But an object
# made using only the new scheme fails with a floating point exception
# when you try to run it on an older system. That is it fails while being
# loaded, not while being run. Fedora Core 6 (at least) by default
# uses just the new format, and so generates VERY non-portable executables.
# Enabling the "both" option here should soften the impact...
# Perhaps this is now an issue of ancient history?

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

AC_MSG_NOTICE([Checking for "--std=gnu++11"])
if test "x$GCC" = "xyes"
then
# I need gnu++11 so that non-ANSI functions such as putc-unlocked are
# left available to me.
  OLDCPPFLAGS="$CPPFLAGS"
  CPPFLAGS="$CPPFLAGS --std=gnu++11"
  AC_LINK_IFELSE([AC_LANG_PROGRAM([[#include <stdio.h>]],
                                  [[printf("\n");]])],
    [AC_MSG_NOTICE(Will use --std=gnu++11)],
    [CPPFLAGS="$OLDCPPFLAGS"
     AC_MSG_NOTICE(--std=gnu++11 not available)])
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

case $host in
i386* | i486* | i586* | i686*)
# On 32-bit Intel-style machines I will try to build using gcc options
# that force use of sse2 rather than 387 floating point arithmetic. This
# should be faster and it avoids intermediate floating point values
# remaining at 80-bit working precision (which messes up some attempts to
# be clever). But the binary that is created will only run on a machine
# from a Pentium 4 onwards (or AMD Operton/Athlon which were introduced in
# 2003). I believe that for now I am not too upset if forcing these flags in
# means that the binaries that are created will fail on CPUs that are a
# full decade behind the cutting edge, but this comment is so that anybody
# is still trying to use a Pentium 3 knows that I at least thought about them.
# Processors that could cause worry here are:
#  AMD prior to Athlon 64 (ie all Socket A CPUs)
#  Intel prior to Pentium 4
#  VIA C3 (distribution ceased in 2006. The C7 should be OK)
#  Transmeta Crusoe (a fine museum item!)
#
# On a Mac where the compiler is in fact clang not gcc these options are
# not recognised and you get messages about that, but the code still passes
# the test here which checks if things can still be compiled even if they
# are specified.
  case $host in
  *darwin* | *Darwin*)
   ;;
  *)
   OLDCPPFLAGS="$CPPFLAGS"
   CPPFLAGS="$CPPFLAGS -msse2 -mfpmath=sse"
   AC_LINK_IFELSE([AC_LANG_PROGRAM([[#include <stdio.h>]],
                                   [[printf("\n");]])],
     [sse2math_available="yes"],
     [CPPFLAGS="$OLDLDFLAGS"
     sse2math_available="no"])
   AC_MSG_NOTICE([SSE math status = $sse2math_available])
   ;;
  esac
  ;;
esac

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
        xft_found="yes"
        AC_MSG_NOTICE([xft-config found, so Xft should be available])
      else
# here xft-config is NOT present, but it may be that xft headers and
# libraries are nevertheless available. I will look for freetype-config
# which may also help me...
        AC_PATH_PROGS(FREETYPE_CONFIG, freetype-config, [no],
          [/usr/local/bin:/usr/sfw/bin:/opt/local/bin:$PATH])
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
            CPPFLAGS="$CPPFLAGS -I/usr/include/freetype2"
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
# arise. Beware: the initial release of cygwin-64 seems to fail if this is
# used... but I will leave people to adjust for that manually.
    PROFILE="-pg"
#   PROFILE=""
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
    AC_MSG_NOTICE([including -static in linker flags])
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

AC_CHECK_HEADERS([complex.h])

AC_CHECK_HEADERS([fcntl.h float.h malloc.h memory.h stdio.h])
AC_CHECK_HEADERS([stddef.h stdlib.h string.h sys/resource.h time.h])
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
AC_CHECK_TYPES([complex double], [], [],
   [#ifdef HAVE_COMPLEX_H
    #include <complex.h>
    #endif])

# With luck the above types from newer C standards will be available. If
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

AC_CHECK_SIZEOF(wchar_t)

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
AC_CHECK_FUNCS([clock_gettime signbit])
AC_CHECK_FUNCS([getc_unlocked putc_unlocked])
AC_CHECK_FUNCS([_getc_nolock _putc_nolock])

# I will view csqrt as representative of all the complex elementary functions
# and if it is found I will assume that csin, clog and all the rest are
# available.
AC_CHECK_FUNCS([csqrt])
   
if test x$ac_cv_header_sys_resource_h = "xyes"
then
  AC_CHECK_DECLS([RLIM_SAVED_CUR, RLIM_SAVED_MAX], [], [],
    [[#include <sys/resource.h>]])
fi

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
# 10.6  Snow Leopard
# 10.7  Lion
# 10.8  Mountain Lion   This is the oldest version I will worry about,
#                       and actually I am in the process of stopping
#                       thinking about anything earlier than Yosemite.
# 10.9  Mavericks       It seems that I may NEED to specify this as the
#                       oldest supported platform, because changes that
#                       Apple made that are triggered by (merely) setting
#                       an earlier deployment target appear to cause trouble.
# 10.10 Yosemite        My test machine runs this.
# 10.11 El Capitan     ... I will now be moving to test on this

# Well now that 10.11 has been released I will always target
# 10.10 and support for earlier versions is no longer guaranteed. I
# take this rather agressive stance because my experience is that Apple
# follow a line that old versions of anything can not be expected to work.
  if test "x$with_wx" != "xno"
  then
    ENVP=MACOSX_DEPLOYMENT_TARGET=10.10
  else
    ENVP=MACOSX_DEPLOYMENT_TARGET=10.10
  fi
  CC="$ENVP $CC"
  CXX="$ENVP $CXX"
# The eccentric code here insists that I use the "macports" version
# of many libraries and it links in the .a files not the .dyld ones so
# that the resulting executable is easier to distribute. At present
# fontconfig seems to be problems in that macports only generates a
# .dylib version not a .a one.
# To cope with that - on my development machine - I found the fontconfig
# sources where macports had fetched them, went "./configure --enable-static"
# and built a libfontconfig.a, which I then copied back into /opt/local/lib.
# The nad news is that me doing that means that ANYBODY building on a
# Macintosh will need to do the same, so I will put a script in csl/cslbase
# that can try to do that for you. But people will need to run that by hand
# before they can build Reduce.
#
# I believe an alternative scheme would be to icnlude fontconfig in a
# private custom framework to be included within the application bundle,
# but at present the explanations and documenattion about how to achieve that
# seem denser than I am willing to confront. Perhaps some Macintosh
# enthusiast can improve on this. But building binaries that can not
# be moved across to other computers that do not have macports installed
# seems to me to be quite unsatisfactory!
#
# Note that all these libraries on my Macintosh have been compiled from
# the source files that "macports" provides without me making any changes.
# So relevant associated source code can be obtained from the macports
# repositories. Since CSL and Reduce are provided under an open source
# license you OF COURSE have the right to reverse engineer or re-link
# against alternative versions of any of the libraries. Linking against the
# .a rather than the .dylib versions is to make the distribution here
# simpler, not to try to lock anybody in or our of anything.
# 
# Note that pthread and dl resolve to system-provided libraries and so
# I am not distributing them, merely links to them.
  LL=/opt/local/lib
  LIBS="$LL/libXrandr.a \
    $LL/libXcursor.a \
    $LL/libXrender.a \
    $LL/libcurses.a \
    $LL/libXext.a \
    $LL/libX11.a \
    $LL/libXft.a \
    $LL/libXau.a \
    $LL/libXfixes.a \
    $LL/libxcb.a \
    $LL/libXdmcp.a \
    $LL/libpng.a \
    $LL/libz.a \
    $LL/libbz2.a \
    $LL/libfreetype.a \
    $LL/libiconv.a \
    $LL/libXft.a \
    $LL/libfontconfig.a \
    $LL/libexpat.a \
    -lpthread \
    -ldl"  
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
AM_CONDITIONAL(cyg32,test "x$cyg32" = "xyes")
AM_CONDITIONAL(cyg64,test "x$cyg64" = "xyes")
AM_CONDITIONAL(darwin,test "x$darwin_build" = "xyes")
AM_CONDITIONAL(mac_framework,test "x$framework_available" = "xyes")
AM_CONDITIONAL(debug,test "x$enable_debug" = "xyes")
AM_CONDITIONAL(exeext,test "x$exeext" = "xyes")
AM_CONDITIONAL(fox,test "x$fox_present" = "xyes")
AM_CONDITIONAL(wx,test "x$with_wx" != "xno")
AM_CONDITIONAL(gui,test "x$fox_present" = "xyes" || test "x$with_wx" != "xno")
AM_CONDITIONAL(experiment,test "x$enable_test" = "xyes")
AM_CONDITIONAL(jit,test "x$enable_jit" = "xyes")
AM_CONDITIONAL(canrun,test "x$can_run_executables" = "xyes")
AM_CONDITIONAL(cygpath, test "x$CYGPATH" != "xno")
AM_CONDITIONAL(valgrind, test "x$VALGRIND" = "xvalgrind")
AM_CONDITIONAL(crlibm, test "x$with_crlibm" != "xno")
AM_CONDITIONAL(boehm, test "x$with_boehm" != "xno")
AM_CONDITIONAL(crlibmorboehm, test "x$with_crlibm" != "xno" || "x$with_boehm" != "xno")

AC_OUTPUT

# end of "configure.ac"


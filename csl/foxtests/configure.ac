## Process this file with autoconf to produce a configure script.

# A C Norman.                                         May 2008-2021

# This is for building the FOX test programs in the CSL/Reduce environment,
# and the sources for the FOX tests have been moved to a distinct directory
# to make it clear that they are not part of CSL or Reduce but are merely
# aggregated with same. 

#
#   --with-cygwin     Build native cygwin X11 based system.
#   --enable-debug    Switch on debugging.
#
#


# FOX gets built in a directory whose name is based on the platform
# it supports. In simple cases this is just the GNU triple, as in
# x86_64-pc-linux etc. However there are a range of cases when I will
# change that. These are the things I note above as "special flags"

# Specify the name of this "application" and a version number
AC_INIT([FOXTESTS],[1.4.21])

# This seemed to work with 2.57 so despite other parts of the code needing
# a yet newer version I will leave this here.
AC_PREREQ([2.72])

here=`pwd`
AC_MSG_NOTICE([+++ Configuring FOX tests in directory $here +++])

AC_CONFIG_SRCDIR(scribble.cpp)
AC_CONFIG_FILES(Makefile)

AC_CONFIG_MACRO_DIRS([m4])
AC_CONFIG_AUX_DIR([.])

AM_INIT_AUTOMAKE([1.8.3 -Wall -Wno-override -Wno-portability foreign dist-bzip2])

# What host am I on?
AC_CANONICAL_HOST()

AC_SUBST(DLL_CFLAGS)

# The following are always to be defined when I go through this route

AC_DEFINE_UNQUOTED(HOST_CPU,"$host_cpu",[Name of CPU])
AC_DEFINE_UNQUOTED(HOST_VENDOR,"$host_vendor",[Name of vendor])
AC_DEFINE_UNQUOTED(HOST_OS,"$host_os",[Name of Operating System])

foxdir="$host"


AC_ARG_WITH(csl,
  AS_HELP_STRING([--with-csl], [Use the CSL Lisp system]),
  [],
  [with_csl="no"])

AC_ARG_WITH(psl,
  AS_HELP_STRING([--with-psl], [Use the PSL Lisp system]),
  [],
  [with_psl="no"])

AC_ARG_WITH(mingw64,
  AS_HELP_STRING([--with-mingw64], [Use internally with CSL]),
  [],
  [with_mingw64="no"])

AC_ARG_WITH(build,
  AS_HELP_STRING([--with-build], [Used internally to control build directory]),
  [],
  [with_build="unknown"])

AC_ARG_WITH(pslbuild,
  AS_HELP_STRING([--with-pslbuild], [Used internally to control build directory]),
  [],
  [with_pslbuild="unknown"])

AC_ARG_WITH(cygbuild,
  AS_HELP_STRING([--with-cygbuild], [Used internally to control build directory]),
  [],
  [with_cygbuild="unknown"])

AC_ARG_WITH(cygbuild64,
  AS_HELP_STRING([--with-cygbuild64], [Used internally to control build directory]),
  [],
  [with_cygbuild64="unknown"])

AC_ARG_WITH(force,
  AS_HELP_STRING([--with-force], [Used internally]),
  [],
  [])

AC_ARG_WITH(crlibm,
  AS_HELP_STRING([--with-crlibm], [Used internally]),
  [],
  [])

AC_SUBST(MAKE)
AC_SUBST(AR)
AC_SUBST(STRIP)
AC_SUBST(SED)
AC_SUBST(WINDRES)

if test "x$WINDRES" = "x"
then
  AC_CHECK_TOOL(WINDRES, windres, windres)
fi

case $host in
x86_64-w64-*)
  AC_DEFINE(WIN32, [1], [True if we are running on Windows])
  AC_DEFINE(WIN64, [1], [True if we are running on 64-bit Windows])
  CPPFLAGS="$CPPFLAGS"
  CFLAGS="$CFLAGS -funsigned-char"
  CXXFLAGS="$CXXFLAGS -funsigned-char"
  DLL_CFLAGS="$CFLAGS -shared"
  windows_build="yes"
  exeext="yes"
  X_BASE_LIBS=""
  ;;
*-*-cygwin* | *mingw*)
  AC_MSG_NOTICE([Building under cygwin])
  AC_ARG_WITH(cygwin,
    [  --with-cygwin           Force use of raw cywgin (note GPL)],
    really_use_cygwin="yes")
  x86="yes"
  if test "x$really_use_cygwin" = "xyes"
  then
    CFLAGS="$CFLAGS -funsigned-char"
    CXXFLAGS="$CXXFLAGS -funsigned-char"
    LDFLAGS="$LDFLAGS -L/usr/X11R6/lib"
    DLL_CFLAGS="$CFLAGS -shared"
    XLIBS="-lXext -lX11 -lXft"
    cygwin_build="yes"
    exeext="yes"
# Here is the normal situation where cygwin is the BUILD environment. Mostly
# that means mingw-style usage.
  else
    AC_DEFINE(WIN32, [1], [True if we are running on Windows])
    CPPFLAGS="$CPPFLAGS "
    CFLAGS="$CFLAGS -funsigned-char"
    CXXFLAGS="$CXXFLAGS -funsigned-char"
    LDFLAGS="$LDFLAGS "
# In this case I make the machine appear to be "x86_64-pc-windows" or some
# such to distinguish it from the case where cygwin1.dll might be involved.
    foxdir=`echo $foxdir | sed -e 's/cygwin/windows/'`
  fi
  windows_build="yes"
  exeext="yes"
  X_BASE_LIBS=""
  ;;
*-*-msdos* | *-*-go32* | *-*-windows*)
  AC_MSG_ERROR([For Windows you are expected to use cygwin/mingw32])
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
  LDFLAGS="$LDFLAGS -L/usr/X11R6/lib"
  XLIBS="-lXext -lX11 -lXft"
  DLL_CFLAGS="$CFLAGS -shared"
  AC_DEFINE(SOLARIS, [1], [True if we are running on Solaris])
  solaris="yes"
  ;;
*darwin*)
  AC_MSG_NOTICE([Building for Macintosh/Darwin with X11])
  macintosh_build="yes"
  darwin_build="yes"
  XLIBS="-lXext -lX11 -lXft -lfontconfig"
  AC_DEFINE(MACINTOSH, [1], [True if we are running on Macintosh])
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
    CPPFLAGS="$CPPFLAGS -fno-common -I/usr/X11R6/include"
    DLL_CFLAGS="$CFLAGS -bundle -undefined suppress"
    AC_DEFINE(UNIX,[1],[True if we are running on Unix, Linux, BSD etc])
    LDFLAGS="$LDFLAGS -L/usr/X11R6/lib -L/opt/local/lib -L/opt/X11/lib"
    LDFLAGS="$LDFLAGS -framework Carbon -framework CoreServices -framework ApplicationServices"
  fi
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
  *x86* | *amd64*)
     x86="yes"
     ;;
  esac
# To survive 64-bit Linux the next line seems needed. I will leave it for
# BSD since is a /usr/X11R6/lib64 directory does not exist no harm will
# be done.
  if test "x$cross_compiling" != "xyes"
  then
    AC_CHECK_FILE([/usr/X11R6/lib64],[XLL=lib64],[XLL=lib])
  else
    XLL=lib
  fi
  LDFLAGS="$LDFLAGS -L/usr/X11R6/$XLL -pthread"
  DLL_CFLAGS="$CFLAGS -shared"
  XLIBS="-lXext -lX11 -lXft"
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
  *x86* | *amd64*)
     x86="yes"
     ;;
  esac
# To survive 64-bit Linux the next line seems needed.
  if test "x$cross_compiling" != "xyes"
  then
    AC_CHECK_FILE([/usr/X11R6/lib64],[XLL=lib64],[XLL=lib])
  else
    XLL=lib
  fi
  LDFLAGS="$LDFLAGS -L/usr/X11R6/$XLL"
  DLL_CFLAGS="$CFLAGS -shared"
  XLIBS="-lXext -lX11 -lXft"
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


AC_ARG_WITH(fox,         [  --with-fox[=DIR]          FOX installation location])
AC_ARG_WITH(fox-pending, [  --with-fox-pending        do not check dir from --with-fox])


# Here I will adjust foxdir to mention the Linux distribution involved
# in case that I can discover that. The effect is that my (adjusted)
# "triple" will be something like say
#     x86__64-pc-fedora_6    OR   powerpc-macos_10.4_tiger-darwin8.8.0
# rather than
#     x86_64-pc-linux-gnu    OR   powerpc-apple-darwin8.8.0

distrib=`"$srcdir/../../scripts/findos.sh"`
AC_MSG_NOTICE([distrib = $distrib])

if test "x$distrib" != "xunknown"
then
  foxdir=`echo $foxdir | sed -e s/linux-gnu/$distrib/`
  foxdir=`echo $foxdir | sed -e s/apple/$distrib/`
fi

# Debugging turned on?
AC_MSG_CHECKING(for debugging)
AC_ARG_ENABLE(debug,[  --enable-debug           compile for debugging])
AC_MSG_RESULT([$enable_debug])

if test "x$enable_debug" = "xyes"
then
  foxdir="$foxdir-debug"
fi

AC_MSG_NOTICE([foxdir = $foxdir])

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
                                  [[printf("Hello\n");]])],
    [AC_MSG_NOTICE(Will use --hash-style=both)],
    [LDFLAGS="$OLDLDFLAGS"
     AC_MSG_NOTICE(--hash-style=both not available)])
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
                                    [[printf("Hello\n");]])],
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
    AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[#include <stdio.h>]],
                                     [[printf("Hello\n");]])],
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
  AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[#include <stdio.h>]],
                                     [[printf("Hello\n");]])],
                    [CXXFLAGS="$CXXFLAGS -mt"],
                    [CFLAGS="$OLDCFLAGS"])
fi

if (test "x$windows_build" != "xyes" || test "x$with_cygwin" = "xyes")
then
  AC_ARG_WITH(xim,
    [  --with-xim              Can be used to control use of XIM])
# I will not even look for Xft if I am building for win32 not X.
#
# Furthermore I will not try xft-config if I am cross-compiling. This may
# be a mess if I ever try to cross compile towards a machine that needs it.
#
# All of the above is more of a worry now I am starting to assume that
# Xft is available...
  AC_ARG_WITH(xft,
    [  --with-xft              Can be used to disable use of XFT])
  if test "x$with_xft" != "xno" && test "x$cross_compiling" != "xyes"
  then
    AC_PATH_PROGS(XFT_CONFIG, xft-config, [no],
      [/usr/local/bin:/usr/X11R6/bin:/usr/sfw/bin:$PATH])
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
# libraries are nevertheless available. I will look for pkg-config
# support for freetype, or failing that freetype-config.
      if pkg-config --cflags freetype2 > /dev/null
      then
        freetype_cflags=`pkg-config --cflags freetype2`
        CFLAGS="$CFLAGS $freetype_cflags"
        CXXFLAGS="$CXXFLAGS $freetype_cflags"
        CPPFLAGS="$CPPFLAGS $freetype_cflags"
        freetype_libs=`pkg-config --libs freetype2`
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
      fi
      else
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
        fi
      fi
    fi
  fi
fi

AC_CHECK_HEADERS([X11/extensions/Xrandr.h])
AC_CHECK_LIB(Xrandr, XRRQueryExtension)

# find command to do best approx to "ln -s" and set LN_S		
AC_PROG_LN_S


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
HIGHOPT="-O2"

case $CC in
x86_64-w64-*)
  AC_DEFINE(WIN64, [1], [True if we are running on Windows (64 bit)])
  ;;
esac

if test "x$GCC" = "xyes"
then
  if test "x$enable_debug" = "xyes"
  then
    CFLAGS="${CFLAGS} -fno-strict-aliasing ${LOWOPT} -g -DDEBUG=1 -Wall"
    CXXFLAGS="${CXXFLAGS} -fno-strict-aliasing ${LOWOPT} -g -DDEBUG=1 -Wall"
    DLL_CFLAGS="${DLL_CFLAGS} -fno-strict-aliasing ${LOWOPT} -g -DDEBUG=1 -Wall"
    LDFLAGS="${LDFLAGS} -g"
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

LIBS="$XLIBS $LIBS"

# Some platforms appear to require the Xcursor library. The next line
# should arrange that it gets scanned if it is available. This test
# does not make a lot of sense on Windows, but in that case it will
# just harmlessly fail. And sometimes (especially for static linking)
# a Xrender library is needed too... However Solarix 10 x86 seems to
# misdetect Xrender when in 64-bit mode so I fudge that away here.

if test "x$solaris" != "xyes"
then
AC_CHECK_LIB(Xrender, XRenderCreateCursor)
AC_CHECK_LIB(Xcursor, XcursorImageCreate)
fi

# Checks for header files.
AC_FUNC_ALLOCA
AC_HEADER_DIRENT
AC_HEADER_SYS_WAIT

AC_CHECK_HEADERS([fcntl.h float.h malloc.h memory.h])
AC_CHECK_HEADERS([stddef.h stdlib.h string.h stdint.h])
AC_CHECK_HEADERS([sys/param.h sys/time.h sys/times.h unistd.h utime.h])
AC_CHECK_HEADERS([arpa/inet.h netdb.h netinet/in.h sys/socket.h sys/stat.h])
AC_CHECK_HEADERS([sys/types.h sys/wait.h sys/shm.h sys/ipc.h signal.h])

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
# use what I find as a fall-back for when (mostly) intptr_t is not
# available.

AC_CHECK_SIZEOF(void *)
AC_CHECK_SIZEOF(short int)
AC_CHECK_SIZEOF(int)
AC_CHECK_SIZEOF(long)
AC_CHECK_SIZEOF(long long)

AC_CHECK_TYPES([socklen_t],[],[],[#include <sys/socket.h>])

AC_CHECK_LIB(socket, socket)
AC_CHECK_LIB(nsl, gethostbyname)

# Checks for library functions.
AC_FUNC_CLOSEDIR_VOID
AC_FUNC_ERROR_AT_LINE
AC_FUNC_LSTAT
AC_FUNC_LSTAT_FOLLOWS_SLASHED_SYMLINK
AC_FUNC_MEMCMP
AC_FUNC_STAT
AC_FUNC_UTIME_NULL
AC_FUNC_VPRINTF
AC_CHECK_FUNCS([atexit ftruncate getcwd gethostbyaddr gethostbyname inet_ntoa])
AC_CHECK_FUNCS([memmove memset mkdir pow rmdir socket sqrt strchr strdup])
AC_CHECK_FUNCS([strrchr strstr utime popen])
AC_CHECK_FUNCS([fork wait waitpid shmget shmat shmdt shmctl])
AC_CHECK_FUNCS([vsnprintf])

if test "x$with_fox" = "xno"
then
  AC_MSG_NOTICE("Will not even attempt to look for FOX")
else

  if test "x$with_fox_pending" != "xno"
  then
    fox_present="yes"
    AC_MSG_NOTICE([Will expect FOX to be in $with_fox])
    CPPFLAGS="$CPPFLAGS -I \"$with_fox/include/fox-1.6\""
    LDFLAGS="$LDFLAGS -L \"$with_fox/lib\""
    AC_SUBST(FOXLIB)
    FOXLIB="$with_fox/lib/libFOX*"
    LIBS="-lFOX-1.6 $LIBS"
    AC_SUBST(FOXDEPS)
    FOXDEPS="$with_fox/lib/libFOX-1.6.a"
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
# goin to be used. Another reason to put this stuff late her.

    AC_LANG(C++)

    cppflags_save="$CPPFLAGS"
    ldflags_save="$LDFLAGS"
    libs_save="$LIBS"

# NB that for FOX I am going to expect the library to be in 
#       $with_fox/lib
# and $with_fox has had a subdir tagged on its end to reflect a 
# modified GNU-style triple, as in x86_64-pc-linux. So if the
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
# Display FOX level (ie minor version number)
      grep LEVEL "$with_fox/include/fox-1.6/fxver.h"
    fi

  fi

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
  ENVP=MACOSX_DEPLOYMENT_TARGET=10.11
  CC="$ENVP $CC"
  CXX="$ENVP $CXX"
fi

AC_CHECK_PROGS(CYGPATH,[cygpath],[no])

AC_OUTPUT

# end of "configure.ac"

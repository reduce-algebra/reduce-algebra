## Process this file with autoconf to produce a configure script.

# A C Norman.                                         April 2009

#
# The object of this configuration file is not to set the world up to
# compile anything - it is to verify the availability of tools and libraries
# that will be neededto build a CSL-based Reduce. So it will try to test
# for these libraries and STOP with an error message if it finds anything
# out of place.
#

# Specify the name of this "application" and a version number
AC_INIT([CSLCONFIGTEST],[1.0])
AM_INIT_AUTOMAKE([1.9.0 -Wall -Wno-portability -Wno-override foreign dist-bzip2])

# The next bit is because config.guess fails on Solaris if SHELL=/bin/bash
if test -x /bin/sh
then
  SHELL=/bin/sh
  export SHELL
fi

# I am going to expect that you have at least this version of
# autoconf. In general I will build with  the latest version and
# not really verify that 2.61 is still sufficient!
AC_PREREQ(2.61)

AC_CONFIG_SRCDIR(profile.dat)
AC_CONFIG_FILES([Makefile])


AC_CHECK_PROG([ACLOCAL],    [aclocal], [yes], [no])
if test "x$ACLOCAL" = "xno"
then
  AC_MSG_WARN([Please consider installing aclocal (and other autoconf tools)])
fi

AC_CHECK_PROG([AUTOCONF],   [autoconf], [yes], [no])
if test "x$AUTOCONF" = "xno"
then
  AC_MSG_WARN([Please consider installing autoconf])
fi

AC_CHECK_PROG([AUTOMAKE],   [automake], [yes], [no])
if test "x$AUTOMAKE" = "xno"
then
  AC_MSG_WARN([Please consider installing automake])
fi

AC_CHECK_PROG([AUTORECONF], [autoreconf], [yes], [no])
if test "x$AUTORECONF" = "xno"
then
  AC_MSG_WARN([Please consider installing autoreconf])
fi



# Part of the idea here is that you can pass THIS configure script a useful
# subset of the options that will go to the top-level one...

AC_ARG_WITH(mingw64,
   AC_HELP_STRING([--with-mingw64],
                  [Try to cross-build using 64-bit mingw]),
   [],
   [with_mingw64="no"])

if test "x$with_mingw64" = "xyes"
then
   mingw64="yes"
else
   mingw64="no"
fi

if test "x$mingw64" = "xyes"
then
   AC_MSG_NOTICE([You have selected --with-mingw64. This is much like --host=x86_64-pc-mingw32])
   AC_MSG_NOTICE([and requires cross-compilation tools such as x86_64-pc-mingw32-gcc])
   host="x86_64-pc-mingw32"
   ac_tool_prefix="x86_64-pc-mingw32-"
   cross_compiling=yes
   STRIP="x86_64-pc-mingw32-strip"
   AR="x86_64-pc-mingw32-ar"
fi

# What host am I on?
AC_CANONICAL_HOST()

AC_ARG_WITH(m32,
   AC_HELP_STRING([--with-m32],
                  [Force 32-bit model even on 64-bit gcc]),
   [],
   [with_m32="no"])

if test "x$with_m32" = "xyes"
then
  bits32="yes"
fi

AC_ARG_WITH(m64,
   AC_HELP_STRING([--with-m64],
                  [Force 64-bit model even if 32-bit is default]),
   [],
   [with_m64="no"])

if test "x$with_m64" = "xyes"
then
  bits64="yes"
fi


if test "x$mingw64" = "xyes"
then
  AC_DEFINE(WIN32, [1], [True if we are running on Windows])
  AC_DEFINE(WIN64, [1], [True if we are running on 64-bit Windows])
  CPPFLAGS="$CPPFLAGS"
  CFLAGS="$CFLAGS -funsigned-char"
  CXXFLAGS="$CXXFLAGS -funsigned-char"
  LDFLAGS="$LDFLAGS -e _mainCRTStartup"
  windows_build="yes"
  exeext="yes"
  X_BASE_LIBS=""
else
case $host in
*-*-cygwin* | x86_64-pc-mingw32)
  AC_MSG_NOTICE([Building under cygwin])
  AC_ARG_WITH(cygwin,
    AC_HELP_STRING([--with-cygwin],
                   [Force use of raw cywgin (note GPL)]),
    [],
    [with_cygwin="no"])
  if test "x$with_cywgin" = "xyes"
  then
    really_use_cygwin="yes"
  fi
  x86="yes"
  if test "x$really_use_cygwin" = "xyes"
  then
    AC_DEFINE(UNIX,[1],[True if we are running on Unix, Linux, BSD etc])
    AC_DEFINE(RAW_CYGWIN, [1], [True if we are running on RAW Cygwin])
    CFLAGS="$CFLAGS -funsigned-char"
    CXXFLAGS="$CXXFLAGS -funsigned-char"
    LDFLAGS="$LDFLAGS -L/usr/X11R6/lib"
    XLIBS="-lXext -lX11"
    cygwin_build="yes"
    exeext="yes"
  else
    AC_DEFINE(WIN32, [1], [True if we are running on Windows])
    CPPFLAGS="$CPPFLAGS -mno-cygwin"
    CFLAGS="$CFLAGS -mno-cygwin -funsigned-char"
    CXXFLAGS="$CXXFLAGS -mno-cygwin -funsigned-char"
    LDFLAGS="$LDFLAGS -mno-cygwin -e _mainCRTStartup"
    foxdir=`echo $foxdir | sed -e 's/cygwin/windows/'`
  fi
  windows_build="yes"
  exeext="yes"
  X_BASE_LIBS=""
  ;;
*-*-msdos* | *-*-go32* | *-*-windows* | *-*-mingw*)
  AC_MSG_ERROR([For Windows you are expected to use cygwin/mingw32])
  ;;
*-*solaris*)
  AC_MSG_NOTICE([Building for Solaris])
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
  XLIBS="-lXext -lX11"
  AC_DEFINE(SOLARIS, [1], [True if we are running on Solaris])
  solaris="yes"
# I think that my Solaris settings may not be fully complete or up to date...
  ;;
*darwin*)
  AC_MSG_NOTICE([Building for Macintosh/Darwin with X11])
  darwin_build="yes"
  AC_DEFINE(MACINTOSH, [1], [True if we are running on Macintosh])
  CFLAGS="$CFLAGS -fno-common -no-cpp-precomp"
  CXXFLAGS="$CXXFLAGS -fno-common -no-cpp-precomp"
  CPPFLAGS="$CPPFLAGS -fno-common -no-cpp-precomp -flat_namespace -I/usr/X11R6/include"
  AC_DEFINE(UNIX,[1],[True if we are running on Unix, Linux, BSD etc])
  LDFLAGS="$LDFLAGS -L/usr/X11R6/lib -flat_namespace"
  XLIBS="-lXext -lX11"
  macintosh_build="yes"
  darwin_build="yes"
  LDFLAGS="$LDFLAGS -framework Carbon -framework CoreServices -framework ApplicationServices"
  AC_LANG_CONFTEST(
    [AC_LANG_PROGRAM([], [])])
  if gcc -isysroot /Developer/SDKs/MacOSX10.5.sdk -arch ppc -arch i386 conftest.c -o conftest > /dev/null 2>&1
  then
    AC_MSG_NOTICE([fat binary creation will probably be possible using 10.5])
    enable_dependency_tracking="no"
  else
    if gcc -isysroot /Developer/SDKs/MacOSX10.4u.sdk -arch ppc -arch i386 conftest.c -o conftest > /dev/null 2>&1
    then
      AC_MSG_NOTICE([fat binary creation will probably be possible using 10.4])
      enable_dependency_tracking="no"
    else
      AC_MSG_NOTICE([fat binary creation will probably NOT be possible])
      AC_MSG_NOTICE([If you have a MacOSX later than 10.5 this script may need adjustment])
    fi
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
  *i386* | *i486* | *i586* | *i686* | *x86* | *amd64*)
     x86="yes"
     ;;
  esac
  if test "x$bits32" != "xyes" && test "x$cross_compiling" != "xyes"
  then
    AC_CHECK_FILE([/usr/X11R6/lib64],[XLL=lib64],[XLL=lib])
  else
    XLL=lib
  fi
  LDFLAGS="$LDFLAGS -L/usr/X11R6/$XLL -pthread"
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
  if test "x$bits32" != "xyes" && test "x$cross_compiling" != "xyes"
  then
    AC_CHECK_FILE([/usr/X11R6/lib64],[XLL=lib64],[XLL=lib])
  else
    XLL=lib
  fi
  LDFLAGS="$LDFLAGS -L/usr/X11R6/$XLL"
  XLIBS="-lXext -lX11"
  ;;
esac
fi

if test "x$MAKE" = "x"
then
  AC_CHECK_PROGS(MAKE,[gmake make],[no])
  if test "x$MAKE" = "xno"
  then
    AC_MSG_ERROR([Please install (the GNU version of) "make"])
  fi
fi
if test "x$AR" = "x"
then
  AC_CHECK_PROGS(AR,[gar ar],[no])
  if test "x$AR" = "xno"
  then
    AC_MSG_ERROR([Please install "ar"])
  fi
fi
if test "x$STRIP" = "x"
then
  AC_CHECK_PROGS(STRIP,[gstrip strip],[echo])
fi
if test "x$SED" = "x"
then
  AC_CHECK_PROGS(SED,[gsed sed],[no])
  if test "x$SED" = "xno"
  then
    AC_MSG_ERROR([Please install "sed"])
  fi
fi


# Debugging turned on?
AC_MSG_CHECKING(for debugging)
AC_ARG_ENABLE(debug,
  AC_HELP_STRING([--enable-debug],
                 [compile for debugging]),
  [],
  [enable_debug="no"])
AC_MSG_RESULT([$enable_debug])

if test "x$x86" = "xyes"
then
  AC_DEFINE(X86, [1], [True if Intel or AMD (32 or 64-bit)])
fi

# The following may not give the most helpful messages if there is no
# C compiler at all, so I will do a simple pre-check based on a limited
# number of plausible choices.

AC_CHECK_PROGS(CCOMPILER, [gcc cc $CC], [none])
AC_CHECK_PROGS(CXXCOMPILER, [g++ CC $CXX], [none])


if test "x$CCOMPILER" = "xnone" || test "x$CXXCOMPILER" = "xnone"
then
   AC_MSG_WARN([You need a C compiler and a C++ compiler installed])
   AC_MSG_WARN([and the most obvious ones do not seem to be present.])
   AC_MSG_WARN([If you do not have a compiler you probably do not have])
   AC_MSG_WARN([development libraries (eg for X, Xft, curses, etc etc])
   AC_MSG_WARN([either. I will let a further test check more carefully])
fi

old_CFLAGS="$CFLAGS"
old_CXXFLAGS="$CXXFLAGS"
AC_MSG_NOTICE([Looking for C pre-processor])
AC_PROG_CPP
AC_MSG_NOTICE([Looking for C compiler])
AC_PROG_CC
AM_PROG_CC_C_O
AC_MSG_NOTICE([Looking for C++ pre-processor])
AC_PROG_CXXCPP
AC_MSG_NOTICE([Looking for C++ compiler])
AC_PROG_CXX
CFLAGS="$old_CFLAGS"
CXXFLAGS="$old_CXXFLAGS"


if test "x$CC" = "x"
then
  AC_MSG_ERROR([Please install a C compiler and try again])
fi

if test "x$CXX" = "x"
then
  AC_MSG_ERROR([Please install a C++ compiler and try again])
fi

AC_PROG_RANLIB

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

if test "x$windows_build" = "xyes"
then
  if test "x$WINDRES" = "x"
  then
    AC_CHECK_TOOL([WINDRES], [windres], [no])
    if test "x$WINDRES" = "xno"
    then
      AC_MSG_ERROR([windres tool needed for windows builds: please install it])
    fi
  fi
fi

if test "x$windows_build" != "xyes"
then
  if test "x$macintosh_build" != "xyes"
  then
    AC_MSG_NOTICE([Checking for "-rdynamic"])
    if test "x$GCC" = "xyes"
    then
      OLDLDFLAGS="$LDFLAGS"
      LDFLAGS="$LDFLAGS -rdynamic"
      AC_LINK_IFELSE([AC_LANG_PROGRAM([[#include <stdio.h>]],
                                      [[printf("\n");]])],
        [rdynamic_available="yes"],
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

  AC_MSG_NOTICE([Checking for ability to build dual arch binaries])
  if test "x$GCC" = "xyes"
  then
    if test "x$macintosh_build" = "xyes"
    then
      sysroot=""
      AC_MSG_NOTICE([Checking for OSX10.5 framework])
      OLDCFLAGS="$CFLAGS"
      CFLAGS="$CFLAGS -isysroot /Developer/SDKs/MacOSX10.5.sdk"
      AC_LINK_IFELSE([AC_LANG_PROGRAM([[#include <stdio.h>]],
                                      [[printf("\n");]])],
        [CXXFLAGS="$CXXFLAGS -isysroot /Developer/SDKs/MacOSX10.5.sdk"
         AC_MSG_NOTICE([MacOS10.5 SDK found])
         sysroot="/Developer/SDKs/MacOSX10.5.sdk"],
        [CFLAGS="$OLDCFLAGS"
         AC_MSG_NOTICE([MacOS10.5 SKD NOT found])])
      if test "x$sysroot" = "x"
      then
        AC_MSG_NOTICE([Checking for OSX10.4u framework])
        CFLAGS="$CFLAGS -isysroot /Developer/SDKs/MacOSX10.4u.sdk"
        AC_LINK_IFELSE([AC_LANG_PROGRAM([[#include <stdio.h>]],
                                        [[printf("\n");]])],
          [CXXFLAGS="$CXXFLAGS -isysroot /Developer/SDKs/MacOSX10.4u.sdk"
           AC_MSG_NOTICE([MacOS10.4u SDK found])
           sysroot="/Developer/SDKs/MacOSX10.4u"],
          [CFLAGS="$OLDCFLAGS"
           AC_MSG_NOTICE([MacOS10.4u SKD NOT found])])
      fi
      OLDCFLAGS="$CFLAGS"
      CFLAGS="$CFLAGS -arch ppc -arch i386"
      AC_LINK_IFELSE([AC_LANG_PROGRAM([[#include <stdio.h>]],
                                      [[printf("\n");]])],
        [CXXFLAGS="$CXXFLAGS -arch ppc -arch i386"
         LDFLAGS="$LDFLAGS -arch ppc -arch i386"
         fat_support_available="yes"],
        [CFLAGS="$OLDCFLAGS"
         fat_support_available="no"])
      AC_MSG_NOTICE([fat_support=$fat_support_available])
    fi
  fi
fi

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

fi

if test "x$solaris" = "xyes"
then
  OLDCFLAGS="$CFLAGS"
  CFLAGS="$CFLAGS -mt"
  AC_LINK_IFELSE([AC_LANG_PROGRAM([[#include <stdio.h>]],
                                     [[printf("\n");]])],
                    [CXXFLAGS="$CXXFLAGS -mt"],
                    [CFLAGS="$OLDCFLAGS"])
fi

if test "x$windows_build" != "xyes" || test "x$with_cygwin" = "xyes"
then
  AC_ARG_WITH(xft,
    AC_HELP_STRING([--with-xft],
                   [Can be used to disable use of XFT. Default is yes]),
    [],
    [with_xft="yes"])
  if test "x$with_xft" != "xno" && test "x$cross_compiling" != "xyes"
  then
    AC_PATH_PROGS(XFT_CONFIG, xft-config, [no],
      [/usr/local/bin:/usr/X11R6/bin:/usr/sfw/bin:$PATH])
    if test "$XFT_CONFIG" != "no"
    then
      xft_cflags=`$XFT_CONFIG --cflags`
      CFLAGS="$CFLAGS $xft_cflags"
      CXXFLAGS="$CXXFLAGS $xft_cflags"
      CPPFLAGS="$CPPFLAGS $xft_cflags"
      xft_libs=`$XFT_CONFIG --libs`
      XLIBS="$XLIBS $xft_libs"
      xft_found="yes"
      AC_DEFINE(HAVE_LIBXFT, [1], [True Xft is available])
      AC_MSG_NOTICE([xft-config found, so Xft should be available])
    else
      AC_PATH_PROGS(FREETYPE_CONFIG, freetype-config, [no],
        [/usr/local/bin:/usr/sfw/bin:$PATH])
      if test "$FREETYPE_CONFIG" != "no"
      then
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
  if test "x$xft_found" != "xyes"
  then
    AC_MSG_ERROR([On non-Windows platforms the Xft library development files are required])
  fi
fi

AC_PROG_LN_S

AC_MSG_CHECKING(for static linking)
AC_ARG_ENABLE(static,
  AC_HELP_STRING([--enable-static],
                 [link it all statically]),
  [],
  [enable_static="no"])

if test "x$win32" != "xyes"
then
# Well in this particular case I reall DO NOT WANT static linking since
# it seems to cause me some pain!
  enable_static="no"
fi

LOWOPT="-O0"
HIGHOPT="-O2"

if test "x$CC" = "xx86_64-pc-mingw32-gcc"
then
  AC_DEFINE(WIN64, [1], [True if we are running on Windows (64 bit)])
fi

if test "x$GCC" = "xyes"
then
  if test "x$enable_debug" = "xyes"
  then
    CFLAGS="${CFLAGS} -fno-strict-aliasing ${LOWOPT} -g -DDEBUG=1 -Wall"
    CXXFLAGS="${CXXFLAGS} -fno-strict-aliasing ${LOWOPT} -g -DDEBUG=1 -Wall"
    LDFLAGS="${LDFLAGS} -g"
  else
    CFLAGS="$CFLAGS -fno-strict-aliasing ${HIGHOPT} -Wall"
    CXXFLAGS="$CXXFLAGS -fno-strict-aliasing ${HIGHOPT} -Wall"
  fi
  if test "x$enable_static" = "xyes"
  then
    LDFLAGS="${LDFLAGS} -static"
    echo "++++ enable_static set +++++"
  fi
else
  if test "x$enable_debug" = "xyes"
  then
    CFLAGS="${CFLAGS} -g -DDEBUG=1"
    CXXFLAGS="${CXXFLAGS} -g -DDEBUG=1"
    LDFLAGS="${LDFLAGS} -g"
  fi
fi

AC_CHECK_LIB(dl, dlopen)

AC_CHECK_LIB(rt, clock_nanosleep)

AC_CHECK_LIB(pthread, pthread_create)

LIBS="$XLIBS $LIBS"

AC_LINK_IFELSE([AC_LANG_PROGRAM([[#include <stdio.h>]],
                                [[printf("\n");]])],
    [],
    [AC_MSG_ERROR([Unable to link with X libraries. Please install them])])


if test "x$windows_build" != "xyes" || test "x$with_cygwin" = "xyes"
then
  AC_CHECK_HEADER(termios.h,
    [AC_DEFINE(HAVE_TERMIOS_H, [1], [Header file termios.h available])],
    [AC_MSG_ERROR([Header file "termios.h" needed but not found])])

  AC_CHECK_HEADER(sys/ioctl.h,
    [AC_DEFINE(HAVE_SYS_IOCTL_H, [1], [Header file sys/ioctl.h available])],
    [AC_MSG_ERROR([Header file "sys/ioctl.h" needed but not found])])

  curses_header="no"
  AC_CHECK_HEADER(curses.h,
    [AC_DEFINE(HAVE_CURSES_H, [1], [Header file curses.h available])
     curses_header="yes"])
  AC_CHECK_HEADER(ncurses.h,
    [AC_DEFINE(HAVE_NCURSES_H, [], [Header file ncurses.h available])
     curses_header="yes"])
  if test "x$curses_header" = "xno"
  then
    AC_MSG_ERROR([neither "curses.h" nor "ncurses.h" found])
  fi

  curses_tgetent="no"
  AC_CHECK_LIB(curses, tgetent,
    [curses_tgetent="yes"
     LIBS=" -lcurses $LIBS"],
    [AC_CHECK_LIB(ncurses, tgetent,
      [curses_tgetent="yes"
       LIBS=" -lncurses $LIBS"])])
  if test "x$curses_tgetent" = "xyes"
  then
    AC_DEFINE([HAVE_TGETENT])
  else
    AC_MSG_ERROR([curses library containing "tgetent" not available])
  fi

  curses_term_h="no"
  AC_CHECK_HEADER(term.h,
     [AC_DEFINE(HAVE_TERM_H, [1], [Header file term.h available])
      curses_term_h="yes"],
     [],
     [#if HAVE_CURSES_H
      #include <curses.h>
      #else
      #if HAVE_NCURSES_H
      #include <ncurses.h>
      #endif
      #endif])
  AC_CHECK_HEADER(ncurses/term.h,
     [AC_DEFINE(HAVE_NCURSES_TERM_H, [1], [Header file ncurses/term.h available])
      curses_term_h="yes"],
     [],
     [#if HAVE_CURSES_H
      #include <curses.h>
      #else
      #if HAVE_NCURSES_H
      #include <ncurses.h>
      #endif
      #endif])
  if test "x$curses_term_h" = "xno"
  then
    AC_CHECK_FUNCS([tgetent],
      AC_DEFINE(HAVE_TGETENT, [1], [Function tgetent available]),
      AC_MSG_ERROR([Neither function "tgetent" nor header "term.h" available]))
  fi

  AC_CHECK_FUNCS([tputs],
    AC_DEFINE(HAVE_TPUTS, [1], [Function tputs available]),
    AC_MSG_ERROR([Function "tputs" not available]))
  AC_CHECK_FUNCS([cfmakeraw])

fi

if test "x$solaris" != "xyes" && test "x$windows_build" != "xyes" 
then

# I am not certain how current the avoidance of these tests on Solaris is,
# and it may reflect issues that are now in the past!

AC_SEARCH_LIBS(XRenderCreateCursor, XRender,
  [AC_DEFINE(HAVE_XRENDERCREATECURSOR, [1], [Function XRenderCreateCursor available])],
  [AC_MSG_ERROR([Function "XRenderCreateCursor" not available])])

AC_SEARCH_LIBS(XcursorImageCreate, Xcursor)
AC_SEARCH_LIBS(XRRQueryVersion, Xrandr)

fi

# For MANY of the following I should maybe upgrade my tests so that if the
# functions are not present I moan. But actually the easiest way of getting
# that effect will be to put code in the program I try to compile along
# the lines of
#     #ifnder HAVE_XXX
#     #error XXX seems to be unavailable
#     #endif
#
# I will maybe stick that sort of stuff in soon.

# Checks for header files.
AC_FUNC_ALLOCA
AC_HEADER_DIRENT
AC_HEADER_STDC
AC_HEADER_SYS_WAIT

AC_CHECK_HEADERS([fcntl.h float.h malloc.h memory.h dlfcn.h])
AC_CHECK_HEADERS([stddef.h stdlib.h string.h stdint.h])
AC_CHECK_HEADERS([sys/param.h sys/time.h sys/times.h unistd.h utime.h])
AC_CHECK_HEADERS([arpa/inet.h netdb.h netinet/in.h sys/socket.h sys/stat.h])
AC_CHECK_HEADERS([sys/types.h sys/wait.h sys/shm.h sys/ipc.h signal.h])
AC_CHECK_HEADERS([sys/sysctl.h syscall.h sched.h])

AC_CHECK_TYPES([cpu_set_t], [], [],
   [#ifdef HAVE_SCHED_H
    #include <sched.h>
    #endif])

AC_HEADER_STAT
AC_C_CONST
AC_STRUCT_TM
AC_C_VOLATILE

# If I were keen I would check that a lot of the above actually found the
# headers and definitions they were looking for... but in general they have
# not been the most troublesome cases so I will worry about that later.

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

save_cross=cross_compiling
cross_compiling=no
AC_RUN_IFELSE([AC_LANG_PROGRAM([[#include <stdio.h>]],
                               [[printf("\n"); return 0;]])],
              [can_run_executables="yes"],
              [can_run_executables="no"],
              [can_run_executables="no"])
cross_compiling=$save_cross

if test "x$can_run_executables" != "xyes"
then
  AC_MSG_ERROR([Unable to compile and run even simple C code])
fi

AC_CHECK_SIZEOF(void *)
AC_CHECK_SIZEOF(short int)
AC_CHECK_SIZEOF(int)
AC_CHECK_SIZEOF(long)
AC_CHECK_SIZEOF(long long)
AC_C_BIGENDIAN

AC_CHECK_TYPES([socklen_t],[],[],[#include <sys/socket.h>])

AC_CHECK_LIB(socket, socket)
AC_CHECK_LIB(nsl, gethostbyname)

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
AC_CHECK_FUNCS([strrchr strstr utime popen])
AC_CHECK_FUNCS([fork wait waitpid shmget shmat shmdt shmctl])
AC_CHECK_FUNCS([vsnprintf sysctlbyname])

save_cross=cross_compiling
cross_compiling=no
AC_RUN_IFELSE([AC_LANG_PROGRAM([[#include <stdio.h>]],
                               [[printf("\n"); return 0;]])],
              [can_run_executables="yes"],
              [can_run_executables="no"],
              [can_run_executables="no"])
cross_compiling=$save_cross

AC_MSG_NOTICE([Can Run Executables = $can_run_executables])

if test "x$windows_build" = "xyes"
then
  if test "x$CC" = "xx86_64-pc-mingw32-gcc"
  then
    LIBS="$LIBS -ladvapi32 -lshell32 -lcomctl32 -lgdi32 -lws2_32 -lmswsock -lwinspool -lmpr -luser32"
  else
    LIBS="$LIBS -lcomctl32 -lgdi32 -lws2_32 -lwsock32 -lwinspool -lmpr"
  fi
fi

if test "x$macintosh_build" = "xyes"
then
  ENVP=MACOSX_DEPLOYMENT_TARGET=10.2
  CC="$ENVP $CC"
  CXX="$ENVP $CXX"
fi

# I will check this again right at the end.
save_cross=cross_compiling
cross_compiling=no
AC_RUN_IFELSE([AC_LANG_PROGRAM([[#include <stdio.h>]],
                               [[printf("\n"); return 0;]])],
              [can_run_executables="yes"],
              [can_run_executables="no"],
              [can_run_executables="no"])
cross_compiling=$save_cross
AC_CHECK_PROGS(CYGPATH,[cygpath],[no])

AC_CONFIG_HEADERS([config.h])
AC_OUTPUT



AC_MSG_NOTICE([Build environment seems OK])

# end of "configure.ac"


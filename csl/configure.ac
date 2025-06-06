## Process this file with autoconf to produce a configure script.

# A C Norman.                                         April 2009-2021

#
# The object of this configuration file is not to set the world up to
# compile anything - it is to verify the availability of tools and libraries
# that will be neededto build a CSL-based Reduce. So it will try to test
# for these libraries and STOP with an error message if it finds anything
# out of place.
#

# Specify the name of this "application" and a version number
AC_INIT([CSLCONFIGTEST],[1.0])
AC_PREREQ(2.61)
AC_CONFIG_MACRO_DIRS([m4])
AC_CONFIG_AUX_DIR([.])

AM_INIT_AUTOMAKE([1.13 -Wall -Wno-portability -Wno-override foreign dist-bzip2])

# The next bit is because config.guess fails on Solaris if SHELL=/bin/bash
if test -x /bin/sh
then
  SHELL=/bin/sh
  export SHELL
fi

#
# There is a horror here. If one fetches everything from subversion
# then timstamps can be ill-ordered, and it can seem necessary to
# re-create the autoconf-related files. The standard way that autoconf and
# automake allow for this is not very generous if the version of autoconf
# on the local machine does not match the one used in the files from the
# central site.
#
# I am now going to try to respond to that by forcing a re-generation of
# all the autoconf files each time anybody runs configure. That adds to the
# cost for everybody and means that everybody NEEDS autoconf, automake and
# libtool installed, but may be more robust.
#

AC_ARG_WITH(autogen,
  AS_HELP_STRING([--with-autogen], [Regenerate autoconf file at start]),
  [],
  [with_autogen="yes"])

if test "x$with_autogen" = "xyes"
then

  if ! which autoconf > /dev/null 2> /dev/null
  then
    printf "You must have autoconf (at least version 2.61) installed to\n"
    printf "build this package. Install it and try again please.\n"
    exit 1
  fi

  if ! which automake > /dev/null 2> /dev/null
  then
    printf "You must have automake (at least version 1.13) installed to\n"
    printf "build this package. Install it and try again please.\n"
    exit 1
  fi

  if ! which libtool > /dev/null 2> /dev/null
  then
    printf "You must have libtool installed to build this package. Install\n"
    printf "it and try again please.\n"
    exit 1
  fi

# The next fragment should extract version numbers for autoconf and automake

# I extract versionm infor from the two utilities. The first line of
# the output from "autoxx --version" is "autoxx ...  nn.nn.nn" with
# a two or three component version number at the end.

  acver=`autoconf --version 2> /dev/null | head -1`
  amver=`automake --version 2> /dev/null | head -1`

# Get rid of everything as far as the final blank in the data. What is
# left is just the version number, whihc may be two or three components,
# such as 14.2.1 or 15.0

  acver=`echo $acver | sed -e 's/.* //'`
  amver=`echo $amver | sed -e 's/.* //'`

# The major version number is got by stripping of everything from the "." on.

  acmaj=`echo $acver | sed -e 's/\..*//'`
  ammaj=`echo $amver | sed -e 's/\..*//'`

# The minor version number is left if one deleted the major number.

  acver=`echo $acver | sed -e "s/$acmaj\.//"`
  amver=`echo $amver | sed -e "s/$ammaj\.//"`

# What was left could have a patch level - get rid of it.

  acmin=`echo $acver | sed -e 's/\..*//'`
  ammin=`echo $amver | sed -e 's/\..*//'`

  AC_MSG_NOTICE([detected autoconf: $acmaj.$acmin automake: $ammaj.$ammin])

  if test $acmaj -lt 2 || test $acmaj -eq 2 && test $acmin -lt 61
  then
    printf "You have autconf $acmaj.$acmin but at least 2.61 is needed\n"
    printf "to build this package. Install it and try again please.\n"
    exit 1
  fi

  if test $ammaj -lt 1 || test $ammaj -eq 1 && test $ammin -lt 13
  then
    printf "You have automake $ammaj.$ammin but at least 1.13 is needed\n"
    printf "to build this package. Install it and try again please.\n"
    exit 1
  fi

  here=`pwd`
  cd $srcdir
  printf "Regenerate autoconf-related files\n"
# Because you will probably not pass arguments to the configure script here
# autogen.sh will re-make autoconf-related files all the way through the
# entire Reduce tree. This is perhaps excessive and expensive, but on the
# other hand it may enhance safety!
  if ! ./autogen.sh $ac_configure_args
  then
    printf "The autogen.sh script seems to have failed. I can not continue\n"
    exit 1
  fi
  cd $here

  printf "Restart: $srcdir/configure $ac_configure_args\n"
  exec /bin/sh -c "$srcdir/configure $ac_configure_args --without-autogen"
fi

# I am going to expect that you have at least this version of autoconf.
AC_PREREQ(2.59)

AC_CONFIG_SRCDIR(window.cpp)
AC_CONFIG_FILES([Makefile])


AC_CHECK_PROG([ACLOCAL],    [aclocal], [yes], [no])
if test "x$ACLOCAL" = "xno"
then
  AC_MSG_WARN([Please install aclocal (and other autoconf tools)])
fi

AC_CHECK_PROG([AUTOCONF],   [autoconf], [yes], [no])
if test "x$AUTOCONF" = "xno"
then
  AC_MSG_WARN([Please install autoconf])
fi

AC_CHECK_PROG([AUTOMAKE],   [automake], [yes], [no])
if test "x$AUTOMAKE" = "xno"
then
  AC_MSG_WARN([Please install automake])
fi

AC_CHECK_PROG([AUTORECONF], [autoreconf], [yes], [no])
if test "x$AUTORECONF" = "xno"
then
  AC_MSG_WARN([Please install autoreconf])
fi



# Part of the idea here is that you can pass THIS configure script a useful
# subset of the options that will go to the top-level one...

AC_ARG_WITH(mingw64,
   AS_HELP_STRING([--with-mingw64],
                  [Should behave like --host=x86_64-w64-mingw32]),
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
   AC_MSG_NOTICE([You have selected --with-mingw64. This is much like --host=x86_64-w64-mingw32])
   AC_MSG_NOTICE([and requires cross-compilation tools such as x86_64-w64-mingw32-gcc])
   host="x86_64-w64-mingw32"
   ac_tool_prefix="x86_64-w64-mingw32-"
   cross_compiling=yes
   STRIP="x86_64-w64-mingw32-strip"
   AR="x86_64-w64-mingw32-ar"
fi

# What host am I on?
AC_CANONICAL_HOST()

case $host in
x86_64-w64-*)
  AC_DEFINE(WIN32, [1], [True if we are running on Windows])
  AC_DEFINE(WIN64, [1], [True if we are running on 64-bit Windows])
  CPPFLAGS="$CPPFLAGS"
  CFLAGS="$CFLAGS -funsigned-char"
  CXXFLAGS="$CXXFLAGS -funsigned-char"
  windows_build="yes"
  exeext="yes"
  X_BASE_LIBS=""
  ;;
*-*-cygwin* | *-*-*mingw*)
  AC_MSG_NOTICE([Building under cygwin])
  AC_ARG_WITH(cygwin,
    AS_HELP_STRING([--with-cygwin],
                   [Force use of raw cywgin (note license consequences please)]),
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
    CPPFLAGS="$CPPFLAGS "
    CFLAGS="$CFLAGS -funsigned-char"
    CXXFLAGS="$CXXFLAGS -funsigned-char"
    LDFLAGS="$LDFLAGS "
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
# If the person who invoked the configure script had set CC or CXX so as to
# override any default selection of which C and C++ compiler to use then
# it will be THEIR business to set up any associated CFLAGS, LDFLAGS etc so
# as to access an appropriate SDK. If I am on a Mac and the person who
# invoked configure did NOT specify options to force which compilers were to
# be used I will feel entitled to use "gcc" and "g++", and with them I
# will make assumptions about where the proper SDKs will have been installed
# and what compiler options will behave properly. Once again any individual or
# script that forces CC or CXX to values other the gcc or g++ have to take
# responsibility for ALL consequences of their actions, and they must also
# pass CFLAGS, LDFLAGS, LIBS and anything else needed.
  if test "x$CC$CXX" == "x" || (test "x$CC" == "xgcc" && test "x$CXX" == "xg++")
  then
    CFLAGS="$CFLAGS -fno-common -no-cpp-precomp"
    CXXFLAGS="$CXXFLAGS -fno-common -no-cpp-precomp"
    CPPFLAGS="$CPPFLAGS -fno-common -no-cpp-precomp -flat_namespace -I/usr/X11R6/include"
    AC_DEFINE(UNIX,[1],[True if we are running on Unix, Linux, BSD etc])
    LDFLAGS="$LDFLAGS -L/usr/X11R6/lib -flat_namespace"
    XLIBS="-lXext -lX11"
    macintosh_build="yes"
    darwin_build="yes"
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
  if test "x$cross_compiling" != "xyes"
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
  *x86* | *amd64*)
     x86="yes"
     ;;
  esac
  if test "x$cross_compiling" != "xyes"
  then
    AC_CHECK_FILE([/usr/X11R6/lib64],[XLL=lib64],[XLL=lib])
  else
    XLL=lib
  fi
  LDFLAGS="$LDFLAGS -L/usr/X11R6/$XLL"
  XLIBS="-lXext -lX11"
  ;;
esac

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
  AS_HELP_STRING([--enable-debug],
                 [compile for debugging]),
  [],
  [enable_debug="no"])
AC_MSG_RESULT([$enable_debug])

if test "x$x86" = "xyes"
then
  AC_DEFINE(X86, [1], [True if Intel or AMD (32 or 64-bit)])
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

LT_INIT

if test "x$CC" = "x"
then
  AC_MSG_ERROR([Please install a C compiler and try again])
fi

if test "x$CXX" = "x"
then
  AC_MSG_ERROR([Please install a C++ compiler and try again])
fi

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
    AS_HELP_STRING([--with-xft],
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
          AC_MSG_NOTICE([pkg-config freetype found, and Xft should be available])
        fi
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
  fi
  if test "x$xft_found" != "xyes"
  then
    AC_MSG_NOTICE([On non-Windows platforms the Xft library development files are required])
  fi
fi

AC_PROG_LN_S

AC_MSG_CHECKING(for static linking)
AC_ARG_ENABLE(static,
  AS_HELP_STRING([--enable-static],
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

AC_SEARCH_LIBS(XRenderCreateCursor, Xrender,
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
AC_FUNC_STAT
AC_FUNC_UTIME_NULL
AC_FUNC_VPRINTF
AC_CHECK_FUNCS([atexit ftruncate getcwd gethostbyaddr gethostbyname inet_ntoa])
AC_CHECK_FUNCS([memmove memset mkdir pow rmdir socket sqrt strchr strdup])
AC_CHECK_FUNCS([strrchr strstr utime popen])
AC_CHECK_FUNCS([fork wait waitpid shmget shmat shmdt shmctl])
AC_CHECK_FUNCS([vsnprintf sysctlbyname])

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
  ENVP=MACOSX_DEPLOYMENT_TARGET=10.13
  CC="$ENVP $CC"
  CXX="$ENVP $CXX"
fi

AC_CHECK_PROGS(CYGPATH,[cygpath],[no])

AC_CONFIG_HEADERS([config.h])
AC_OUTPUT

AC_MSG_NOTICE([Build environment seems OK])

# end of "configure.ac"

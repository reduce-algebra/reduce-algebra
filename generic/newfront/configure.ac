# --------------------------------------------------------------------
# $Id$
# --------------------------------------------------------------------
# Copyright (c) 1999-2009 Andreas Dolzmann and Thomas Sturm
# --------------------------------------------------------------------
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
#    * Redistributions of source code must retain the relevant
#      copyright notice, this list of conditions and the following
#      disclaimer.
#    * Redistributions in binary form must reproduce the above
#      copyright notice, this list of conditions and the following
#      disclaimer in the documentation and/or other materials provided
#      with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
# A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
# OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
# SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
# LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#

# Process this file with autoconf to produce a configure script.
AC_INIT([Redfront],[3.3],[http://sourceforge.net/reduce-algebra])

AC_CONFIG_MACRO_DIRS([m4])
AC_CONFIG_AUX_DIR([.])
AM_INIT_AUTOMAKE([1.13 -Wno-portability -Wno-override foreign dist-bzip2])

LT_INIT

# For MUCH of the Reduce code on Windows I configure multiple times using
# x86_64-w64-mingw32 and x86_64-pc-cygwin. This package is different and I
# really will NOT want that to happen, so the scripts that call for the
# configuration here should NOT pass down "--host" please.

AC_CANONICAL_HOST

# Checks for programs.
AC_PROG_CC
AC_CHECK_TOOL([STRIP], [strip])

on_windows="no"
on_linux="no"

case `$CC --version` in
*w64-mingw32*)
  native_win="yes"
  ;;
*)
  native_win="no"
  ;;
esac

# Note that the native windows version will have WIN32 defined and
# __CYGWIN__ not defined.

AS_IF([test "$EXEEXT" = .exe],
  [AC_DEFINE(WIN32,1,[This is some Windows version])
   AC_DEFINE(USE_PIPES,1,[Define as 1 for using pipes instead if sockets])
   COMEXT=".com"
   on_windows="yes"],
  [AC_ARG_ENABLE(pipes,
    AS_HELP_STRING([--enable-pipes],
      [use pipes not sockets on systems other than Windows]),
   if test "$enableval" = no
   then
     AC_DEFINE(USE_PIPES,0,[Define  1 for using pipes instead if sockets])
   else
     AC_DEFINE(USE_PIPES,1,[Define to 1 for using pipes instead if sockets])
   fi,
   AC_DEFINE(USE_PIPES,0,[Define to 1 for using pipes instead if sockets]))
   COMEXT=""])

if test "x$on_windows" != "xyes"
then
  if test -f /usr/lib/*/libtinfo.a
  then
    on_linux="yes"
  fi
fi

# Checks for libraries.

# This is done on ALL hosts, and that is potentially dodgy.
# So let me explain what it is about. If one builds on Ubuntu without this
# then libtinfo (used by ncurses) is linked dynamically. If you take the
# resulting binary to a Fedora machine it works OK but you get an annoying
# warning about whether the library has a proper version number. This hack
# will link in libtinfo statically and ought to avoid that ugly warning at
# a rather modest increase in the size of the shipped binary. HOWEVER this
# will be a problem when cross-compiling and for that case I ought to
# seek a version specific to the architecture I am building for. Ugh!
# Well it seems that if I list ALL versions that I find then ones that are
# not the relevant architecture get ignored...
a=`find /usr/lib -name libtinfo.a -printf "%p "`
if test "$a" = ""
then    # No libtinfo found
  AC_SEARCH_LIBS([tgetent], [ncurses curses tinfo])
else    # At least one version found.
  LIBS="$LIBS $a"
fi

OLIBS="$LIBS"
LIBS="$OLIBS -lncurses"
AC_LINK_IFELSE(
  [AC_LANG_SOURCE([#include <ncurses.h>
     #include <term.h>
     int main()
     {  (void)tgetent(NULL, "xterm");
        return 0;
     } ])],
  [AC_MSG_NOTICE([tgetent found in ncurses])],
  [AC_MSG_NOTICE([tgetent NOT found in ncurses])
   LIBS="$OLIBS -lcurses"
   AC_LINK_IFELSE(
     [AC_LANG_SOURCE([#include <curses.h>
        #include <term.h>
        int main()
        {  (void)tgetent(NULL, "xterm");
           return 0;
        } ])],
     [AC_MSG_NOTICE([tgetent found in curses])],
     [AC_MSG_NOTICE([tgetent NOT found in curses])
      LIBS="$OLIBS"
      LDFLAGS="$LDFLAGS -L/usr/local/lib"
      AC_SEARCH_LIBS([tgetent], [ncurses curses])
     ])
  ])

curses_header="no"
AC_CHECK_HEADER(curses.h,
  [AC_DEFINE(HAVE_CURSES_H, [1], [Header file curses.h available])
   curses_header="yes"])
AC_CHECK_HEADER(ncurses.h,
  [AC_DEFINE(HAVE_NCURSES_H, [1], [Header file ncurses.h available])
   curses_header="yes"])
if test "x$curses_header" = "xno"
then
# If you are going to build for native Windows then not having curses
# or ncurses is expected and not an error. For Cygwin and all non-Windows
# platforms it would be a disaster.
  AC_MSG_NOTICE([neither "curses.h" nor "ncurses.h" found])
fi

# This is done on ALL hosts, and that is potentially dodgy.
# So let me explain what it is about. If one builds on Ubuntu without this
# then libtinfo (used by ncurses) is linked dynamically. If you take the
# resulting binary to a Fedora machine it works OK but you get an annoying
# warning about whether the library has a proper version number. This hack
# will link in libtinfo statically and ought to avoid that ugly warning at
# a rather modest increase in the size of the shipped binary.
# And on Gentoo you need -ltinfo as well as -lncurses to access tgetent.
if test -f /usr/lib/*/libtinfo.a
then
  LIBS="-l:libtinfo.a $LIBS"
else
  AC_SEARCH_LIBS([tgetent], [ncurses curses tinfo])
fi


AC_CHECK_LIB(socket,socketpair,LIBS="-lsocket $LIBS")

AC_CHECK_HEADERS(wait.h sys/wait.h,break)

# Checks for library functions.

AC_CHECK_FUNCS(waitpid)
AC_CHECK_FUNCS(setlinebuf)

AC_ARG_ENABLE(debug,
  AS_HELP_STRING([--enable-debug],
    [comprehensive printing of debugging messages]),
if test "$enableval" = yes
then
  debug="yes"
  AC_DEFINE(DEBUG,1,[Define this for debug information on signals and files])
  CFLAGS="$CFLAGS -O1 -g"
fi)

if ! test "x$debug" = "xyes"
then
  CFLAGS="$CFLAGS -O3"
fi

AC_ARG_WITH(win32bit,
  AS_HELP_STRING([--with-win32bit], [not relevent here]))

AC_ARG_WITH(c32,
  AS_HELP_STRING([--with-c32], [not relevent here]))

AC_ARG_WITH(both,
  AS_HELP_STRING([--with-both], [not relevent here]))


AM_CONDITIONAL(DEBUG,   test "x$debug" = "xyes")
AM_CONDITIONAL(WINDOWS, test "x$on_windows" = "xyes")
AM_CONDITIONAL(LINUX,   test "x$on_linux" = "xyes")
AM_CONDITIONAL(NATIVEWIN, test "x$native_win" = "xyes")

# The previous version of this configuration file provided a range of extra
# configuration options that made it possible to selectively disable parts
# of the code. They have been removed to simplify things and in the
# expectation that building will be a simple hands-off process with nobody
# wanting to have redfront in use but without a history mechanism (etc).
# I have left the option to build a version that does not impose colour and
# a way of setting how much history will be kept.

AC_CONFIG_FILES([Makefile])
AC_OUTPUT

# end of configure.ac

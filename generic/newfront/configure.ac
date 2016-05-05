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

AM_INIT_AUTOMAKE([1.13 -Wno-portability -Wno-override foreign dist-bzip2])
AC_CONFIG_MACRO_DIRS([m4])
# I will use the older version too.
AC_CONFIG_MACRO_DIR([m4])

# For MUCH of the Reduce code on Windows I configure multiple times using
# --host=i686-pc-cygwin, i686-w64-mingw32, x86_64-w64-mingw32 and
# x86_64-pc-cygwin. This package is different and I really will NOT want
# that to happen, so the scripts that call for the configuration here should
# NOT pass down "--host" please.

AC_CANONICAL_HOST

# Checks for programs.
AC_PROG_CC

on_windows="no"
# Note that the native windows version will have WIN32 defined and
# __CYGWIN__ not defined.

AS_IF([test "$EXEEXT" = .exe],
  [AC_DEFINE(WIN32,1,[This is some Windows version])
   AC_DEFINE(USE_PIPES,1,[Define as 1 for using pipes instead if sockets])
   COMEXT=".com"
   on_windows="yes"],
  [AC_ARG_ENABLE(pipes,
    AC_HELP_STRING([--enable-pipes],
      [use pipes not sockets on systems other than Windows]),
   if test "$enableval" = no
   then
     AC_DEFINE(USE_PIPES,0,[Define  1 for using pipes instead if sockets])
   else
     AC_DEFINE(USE_PIPES,1,[Define to 1 for using pipes instead if sockets])
   fi,
   AC_DEFINE(USE_PIPES,0,[Define to 1 for using pipes instead if sockets]))
   COMEXT=""])

# Checks for libraries.

curses_header="no"
AC_CHECK_HEADER(curses.h,
  [AC_DEFINE(HAVE_CURSES_H, [1], [Header file curses.h available])
   curses_header="yes"])
AC_CHECK_HEADER(ncurses.h,
  [AC_DEFINE(HAVE_NCURSES_H, [1], [Header file ncurses.h available])
   curses_header="yes"])
if test "x$curses_header" = "xno"
then
  AC_MSG_ERROR([neither "curses.h" nor "ncurses.h" found])
fi

AC_CHECK_LIB(socket,socketpair,LIBS="-lsocket $LIBS")

AC_CHECK_HEADERS(wait.h sys/wait.h,break)

# Checks for library functions.
AC_TYPE_SIGNAL
AC_CHECK_FUNCS(waitpid)
AC_CHECK_FUNCS(setlinebuf)

AC_ARG_ENABLE(debug,
  AC_HELP_STRING([--enable-debug],
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

AM_CONDITIONAL(DEBUG,   test "x$debug" = "xyes")
AM_CONDITIONAL(WINDOWS, test "x$on_windows" = "xyes")

# The previous version of this configuration file provided a range of extra
# configuration options that made it possible to selectively disable parts
# of the code. They have been removed to simplify things and in the
# expectation that building will be a simple hands-off process with nobody
# wanting to have redfront in use but without a history mechanism (etc).
# I have left the option to build a version that does not impose colour and
# a way of setting how much history will be kept.

AC_OUTPUT(Makefile)

# end of configure.ac

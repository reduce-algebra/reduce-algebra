dnl --------------------------------------------------------------------
dnl $Id$
dnl --------------------------------------------------------------------
dnl Copyright (c) 1999-2009 Andreas Dolzmann and Thomas Sturm
dnl --------------------------------------------------------------------
dnl Redistribution and use in source and binary forms, with or without
dnl modification, are permitted provided that the following conditions
dnl are met:
dnl
dnl    * Redistributions of source code must retain the relevant
dnl      copyright notice, this list of conditions and the following
dnl      disclaimer.
dnl    * Redistributions in binary form must reproduce the above
dnl      copyright notice, this list of conditions and the following
dnl      disclaimer in the documentation and/or other materials provided
dnl      with the distribution.
dnl 
dnl THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
dnl "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
dnl LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
dnl A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
dnl OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
dnl SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
dnl LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
dnl DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
dnl THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
dnl (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
dnl OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
dnl

dnl Process this file with autoconf to produce a configure script.
AC_INIT(redfront.c)

abssrcdir=`$srcdir/../../../scripts/here.sh`

AC_CANONICAL_HOST
BUILD=`eval "$SHELL $srcdir/../../../scripts/findhost.sh $host $ac_configure_args"`
AC_MSG_NOTICE([Build platform detected as $BUILD])
AC_SUBST(BUILD)

AC_CONFIG_HEADER(config.h)

AC_ARG_WITH(csl,
  AC_HELP_STRING([--with-csl], [Use the CSL Lisp system]),
  [],
  [with_csl="no"])

AC_ARG_WITH(psl,
  AC_HELP_STRING([--with-psl], [Use the PSL Lisp system]),
  [],
  [with_psl="no"])

if test "x$with_csl" != "xno" ; then
   if test "x$with_psl" != "xno" ; then
      AC_MSG_ERROR("use only one of --with-csl or --with-psl")
   fi
   AC_DEFINE_UNQUOTED(REDUCE,"$abssrcdir/cslbuild/$BUILD/csl/reduce",
      [Define your executable REDUCE (with CSL)])
elif test "x$with_psl" != "xno" ; then
   if test "x$with_csl" != "xno" ; then
      AC_MSG_ERROR("use only one of --with-csl or --with-psl")
   fi
   AC_DEFINE_UNQUOTED(BPSL,"$abssrcdir/pslbuild/$BUILD/psl/bpsl",
	[Define your executable bpsl (with PSL)])
   AC_DEFINE_UNQUOTED(REDIMG,"$abssrcdir/pslbuild/$BUILD/red/reduce.img",
	[Define your REDUCE image (with PSL)])
   AC_ARG_WITH(td,
	AC_HELP_STRING([--with-td=BYTES],
		[override the BPSL default memory [[BYTES=128000000]]]),
	defmem=$withval,defmem=128000000)
   AC_DEFINE_UNQUOTED(MEMORY,"$defmem",
	[Define bytes allocated by BPSL (-td argument) as a string])
else
   AC_MSG_ERROR("use one of --with-csl or --with-psl")
fi

AC_DEFINE_UNQUOTED(REDFRONTROOT,"$abssrcdir/packages/redfront",
	[Define the location of redfront.red])

dnl Checks for programs.
AC_PROG_CC

dnl Checks for libraries.
dnl AC_CHECK_LIB(termcap,main,LIBS="-ltermcap $LIBS",\
dnl AC_MSG_ERROR("install a termcap library first"))
AC_CHECK_LIB(curses,main,LIBS="-lcurses $LIBS",\
AC_MSG_ERROR("install a curses library first"))
AC_CHECK_LIB(socket,socketpair,LIBS="-lsocket $LIBS")

AC_CHECK_HEADERS(wait.h sys/wait.h,break)

dnl Checks for library functions.
AC_TYPE_SIGNAL
AC_CHECK_FUNCS(wait4 waitpid wait3,break)
AC_CHECK_FUNCS(setlinebuf)

dnl Following is adapted from GNU tar configure.in
AC_CACHE_CHECK(for union wait, tar_cv_header_union_wait,
  [AC_TRY_COMPILE([
#include <sys/types.h>
#if HAVE_SYS_WAIT_H
# include <sys/wait.h>
#endif],
  [int status; int pid; pid = wait (&status);],
  tar_cv_header_union_wait=no, tar_cv_header_union_wait=yes)])
test $tar_cv_header_union_wait = yes && AC_DEFINE(HAVE_UNION_WAIT,1,[use (union wait)* in contrast to int* for arg2 of wait4])

AC_ARG_ENABLE(color,
   AC_HELP_STRING([--enable-color],[build for color terminal [[yes]]]),
   if test "$enableval" = no ; then
      AC_DEFINE(HAVE_COLOR,0,[Define for color terminal support])
   else
      AC_DEFINE(HAVE_COLOR,1,[Define for color terminal support])
   fi,
   AC_DEFINE(HAVE_COLOR,1,[Define for color terminal support]))

AC_ARG_WITH(hist-size,[  --with-hist-size=LINES  length of the .reduce_history file [[LINES=1000]]],
	histfilesize=$withval,histfilesize=1000)
AC_DEFINE_UNQUOTED(HISTFILESIZE,$histfilesize,
	[Define the maximum number of lines in your .reduce_history])

AC_ARG_ENABLE(debug,[  --enable-debug          provide information on signals and files [[no]]],
if test "$enableval" = yes ; then
AC_DEFINE(DEBUG,1,[Define this for debug information on signals and files])
fi)

AC_ARG_ENABLE(static,[  --enable-static         force static linking [[no]]],
if test "$enableval" = yes ; then
AC_DEFINE(STATIC,"s",[static linking info in banner])
AC_SUBST(LDFLAGS,"-static $LDFLAGS")
else
AC_DEFINE(STATIC,"",[static linking info in banner])
fi,
AC_DEFINE(STATIC,"",[static linking info in banner])
)

AC_ARG_ENABLE(readline,[  --enable-readline       use GNU readline instead of editline [[no]]],
if test "$enableval" = yes ; then
AC_DEFINE(USE_READLINE,1,[Use GNU readline instead of editline])
readline=yes
fi)

if test "x$readline" = "xyes" ; then

AC_CHECK_LIB(readline,readline,LIBS="-lreadline $LIBS",\
	AC_MSG_ERROR("install GNU readline first"))
AC_CHECK_LIB(readline,using_history,\
	AC_DEFINE(HAVE_HISTORY,1,\
		[history provided by libreadline or libhistory]),\
	AC_CHECK_LIB(history,using_history,\
		AC_DEFINE(HAVE_HISTORY,1,\
			[history provided by libreadline or libhistory])))

fi

AC_ARG_ENABLE(cmdhist,[  --enable-cmdhist        use bash cmdhist history style [[yes]]],
if test "$enableval" = no ; then
AC_DEFINE(CMDHIST,0,[Use bash cmdhist history style])
else
AC_DEFINE(CMDHIST,1,[Use bash cmdhist history style])
fi,
AC_DEFINE(CMDHIST,1,[Use bash cmdhist history style])
)

AC_ARG_ENABLE(lithist,[  --enable-lithist        use bash lithist history style [[yes]]],
if test "$enableval" = no ; then
AC_DEFINE(LITHIST,0,[Use bash lithist history style])
else
AC_DEFINE(LITHIST,1,[Use bash lithist history style])
fi,
AC_DEFINE(LITHIST,1,[Use bash lithist history style])
)

AC_OUTPUT(Makefile)

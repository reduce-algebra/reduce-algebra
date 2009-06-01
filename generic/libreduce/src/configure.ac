dnl --------------------------------------------------------------------
dnl $Id$
dnl --------------------------------------------------------------------
dnl Copyright (c) 2008-2009 Thomas Sturm
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
AC_INIT(RedProc.c)

AC_CANONICAL_HOST
BUILD=`eval "$SHELL $srcdir/../../../scripts/findhost.sh $host $ac_configure_args"`
AC_MSG_NOTICE([Build platform detected as $BUILD])
AC_SUBST(BUILD)

AC_CONFIG_HEADER(config.h)

dnl Checks for programs.
AC_PROG_CC

AS_IF([test "$EXEEXT" = .exe],
  [AC_DEFINE(WIN32,1,[This is some Windows version])
   AC_DEFINE(USE_PIPES,1,[Define as 1 for using pipes instead of sockets])
   on_windows=yes],
  [AC_ARG_ENABLE(pipes,
   AC_HELP_STRING([--enable-pipes],
		  [use pipes not sockets on systems other than Windows]),
   if test "$enableval" = no ; then
      AC_DEFINE(USE_PIPES,0,[Define  1 for using pipes instead if sockets])
   else
      AC_DEFINE(USE_PIPES,1,[Define to 1 for using pipes instead if sockets])
   fi,
   AC_DEFINE(USE_PIPES,0,[Define to 1 for using pipes instead if sockets]))])

dnl Checks for libraries.
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

AC_ARG_WITH(reduce,[  --with-reduce=PROG      complete path to the default reduce binary [[./reduce]]],
	redbin=$withval,redbin=./reduce)
AC_SUBST(redbin)
AC_DEFINE_UNQUOTED(REDUCE,"$redbin",[complete path to the reduce executable])

AC_ARG_WITH(initfile,[  --with-initfile=FILE    complete path to the initialization file [[./libreduce.red]]],
	initfile=$withval,initfile=./libreduce.red)
AC_SUBST(initfile)
AC_DEFINE_UNQUOTED(INITFILE,"$initfile",[complete path to the initfile])

AC_ARG_ENABLE(logfile,[  --enable-logfile        create libreduce.log [[yes]]],
if test "$enableval" = yes ; then
AC_DEFINE_UNQUOTED(LOGFILE,1,[Define this for creating libreduce.log])
fi,
AC_DEFINE_UNQUOTED(LOGFILE,1,[Define this for creating libreduce.log])
)

AC_ARG_ENABLE(fastmode,[  --enable-fastmode       exclusively provide result [[no]]],
if test "$enableval" = yes ; then
AC_DEFINE_UNQUOTED(FASTMODE,1,[Exclusively provide result in RedAns])
fi,
AC_DEFINE_UNQUOTED(FASTMODE,0,[Exclusively provide result in RedAns])
)

AC_ARG_ENABLE(pslfix,[  --enable-pslfix         fix an issue with PSL prompts in long input lines [[no]]],
if test "$enableval" = yes ; then
AC_DEFINE_UNQUOTED(PSLFIX,1,[Define this for fixing an issue with PSL prompts in long input lines])
fi)

AC_ARG_ENABLE(rlgfile,[  --enable-rlgfile        create libreduce-<pid>.rlg [[no]]],
if test "$enableval" = yes ; then
AC_DEFINE_UNQUOTED(RLGFILE,1,[Define this for creating libreduce-<pid>.rlg])
fi)

AC_ARG_ENABLE(debug,[  --enable-debug          print debugging information to tty [[no]]],
if test "$enableval" = yes ; then
AC_DEFINE(DEBUG,1,[Define this for debug information on signals and files])
fi)

AC_OUTPUT(Makefile)

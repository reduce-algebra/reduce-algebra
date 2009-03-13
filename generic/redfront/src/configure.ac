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

AC_CONFIG_HEADER(config.h)

dnl Checks for programs.
AC_PROG_CC

dnl Checks for libraries.
AC_CHECK_LIB(termcap,main,LIBS="-ltermcap $LIBS",\
AC_MSG_ERROR("install a termcap library first"))
dnl AC_CHECK_LIB(ncurses,main,LIBS="-lncurses $LIBS",\
dnl AC_MSG_ERROR("install an ncurses library first"))
AC_CHECK_LIB(readline,readline,LIBS="-lreadline $LIBS",\
	AC_MSG_ERROR("install GNU readline first"))
AC_CHECK_LIB(readline,using_history,\
	AC_DEFINE(HAVE_HISTORY,1,\
		[history provided by libreadline or libhistory]),\
	AC_CHECK_LIB(history,using_history,\
		AC_DEFINE(HAVE_HISTORY,1,\
			[history provided by libreadline or libhistory])))
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

AC_ARG_WITH(reduce-binary,[  --with-reduce-binary=PROG
                          complete path to the reduce binary (if NOT image
                          model)],
	redbin=$withval)

if test "${redbin:+set}" = set; then

AC_DEFINE_UNQUOTED(REDUCE,"$redbin",
	[Define your executable Reduce (if NOT image model)])

else

AC_ARG_WITH(reduce-root,[  --with-reduce-root=REDUCEROOT
                          root of the reduce tree [[/usr/local/reduce]]],
	reduceroot=$withval,reduceroot=/usr/local/reduce)
AC_SUBST(reduceroot)
AC_DEFINE_UNQUOTED(REDUCEROOT,"$reduceroot",
	[Define the location of the REDUCE tree])

AC_ARG_WITH(machine,[  --with-machine=MACHINE
                          MACHINE in the sense of Reduce [[linux]]],
	machine=$withval,machine=linux)
AC_SUBST(machine)

AC_ARG_WITH(csl,[  --with-csl=PROG         complete path to the binary csl],
csl=$withval)

if test "${csl:+set}" = set; then

AC_DEFINE_UNQUOTED(CSL,"$csl",[Define your CSL executable])

AC_ARG_WITH(img,[  --with-img=IMAGE        complete path to the image file [[use find]]],rf_cv_path_image=$withval)

if test "${rf_cv_path_image:+set}" != set; then

AC_MSG_CHECKING(for CSL REDUCE image)
AC_CACHE_VAL(rf_cv_path_image,
rf_cv_path_image="`if test -r $reduceroot/lisp/csl; then find $reduceroot/lisp/csl -name "reduce.img" -print; fi`")

if test "${rf_cv_path_image:+set}" = set; then
AC_MSG_RESULT(find succeeded)
else
AC_MSG_RESULT(find failed)
fi

fi

AC_DEFINE_UNQUOTED(RCSL,"lisp/csl/$machine/csl",
	[Define the relative location of csl in the REDUCE tree])

AC_DEFINE_UNQUOTED(RREDIMG,"lisp/csl/$machine/reduce.img",
	[Define the relative location of reduce.img in the REDUCE tree])

else

AC_ARG_WITH(bpsl,[  --with-bpsl=PROG        complete path to the binary psl [[use find]]],
bpsl=$withval,bpsl=`find $reduceroot/lisp/psl -path "*/lisp/psl/*/psl/bpsl" | head -1`)
AC_DEFINE_UNQUOTED(BPSL,"$bpsl",[Define your PSL executable (if image model)])

AC_ARG_WITH(td,[  --with-td=BYTES         override the BPSL default memory [[BYTES=128000000]]],
	defmem=$withval,defmem=128000000)
AC_DEFINE_UNQUOTED(MEMORY,"$defmem",
	[Define the number of bytes allocated by BPSL (-td argument)
	as a string])

AC_ARG_WITH(img,[  --with-img=IMAGE        complete path to the image file [[use find]]],rf_cv_path_image=$withval)

if test "${rf_cv_path_image:+set}" != set; then

AC_MSG_CHECKING(for PSL REDUCE image)
AC_CACHE_VAL(rf_cv_path_image,
rf_cv_path_image="`if test -r $reduceroot/lisp/psl; then find $reduceroot/lisp/psl -name "reduce.img" -print; fi`")
if test "${rf_cv_path_image:+set}" = set; then
AC_MSG_RESULT(find succeeded)
else
AC_MSG_RESULT(find failed)
fi

fi

AC_DEFINE_UNQUOTED(RBPSL,"lisp/psl/$machine/psl/bpsl",
	[Define the relative location of bpsl in the REDUCE tree])
AC_DEFINE_UNQUOTED(RREDIMG,"lisp/psl/$machine/red/reduce.img",
	[Define the relative location of reduce.img in the REDUCE tree])
fi

if test "${rf_cv_path_image:+set}" = set; then
AC_DEFINE_UNQUOTED(REDIMG,"$rf_cv_path_image",
	[Define your REDUCE image file (if image model)])
fi

fi

AC_ARG_WITH(redfront-root,[  --with-redfront-root=DIR
                          location of redfront.red
                          [[REDUCEROOT/packages/redfront]]],
	redfrontroot=$withval,redfrontroot=$reduceroot/packages/redfront)
AC_DEFINE_UNQUOTED(REDFRONTROOT,"$redfrontroot",
	[Define the location of redfront.red])


AC_ARG_ENABLE(color,[  --enable-color          build for color xterm [[yes]]],
if test "$enableval" = no ; then
AC_DEFINE(HAVE_COLOR,0,[Define for color xterm support])
else
AC_DEFINE(HAVE_COLOR,1,[Define for color xterm support])
fi,
AC_DEFINE(HAVE_COLOR,1,[Define for color xterm support])
)

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

AC_OUTPUT(Makefile)

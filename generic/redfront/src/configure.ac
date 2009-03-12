dnl --------------------------------------------------------------------
dnl $Id: configure.in,v 1.14 2006/11/16 08:45:54 sturm Exp $
dnl --------------------------------------------------------------------
dnl Copyright (c) 1999 Andreas Dolzmann and Thomas Sturm
dnl --------------------------------------------------------------------
dnl $Log: configure.in,v $
dnl Revision 1.14  2006/11/16 08:45:54  sturm
dnl reduce.img have moved to lisp/csl/$MACHINE.
dnl
dnl Revision 1.13  2006/06/04 17:30:19  sturm
dnl --with-reduce-binary now builds correctly. In that case there is always
dnl REDUCEROOT used, and $reduce is neither checked nor set.
dnl
dnl Revision 1.12  2006/06/03 11:31:29  sturm
dnl Adapted to the CSL development system.
dnl Before I had wrong ideas about image model vs. csl.
dnl
dnl Revision 1.11  2006/06/02 10:19:48  sturm
dnl The default location of redfront has moved from $reduce/redfront to
dnl $reduce/packages/redfront.
dnl
dnl Revision 1.10  2006/05/18 03:05:57  sturm
dnl Carefully check for HAVE_UNION_WAIT.
dnl
dnl Revision 1.9  2006/05/17 18:15:43  sturm
dnl Check for using_history in linreadline first.
dnl This is essential at least on MacOS X.
dnl
dnl Revision 1.8  2004/09/23 09:55:49  sturm
dnl Fixed debugging output.
dnl Solaris Compilation.
dnl This is used for static binaries shipped with REDUCE 3.8.
dnl
dnl Revision 1.7  2004/09/02 13:54:19  sturm
dnl Allow to configure image location and static compilation.
dnl
dnl Revision 1.6  2004/09/02 08:53:42  sturm
dnl Improved color handling.
dnl Added support for $reduce.
dnl This is supposed to work with PSL-based REDUCE.
dnl
dnl Revision 1.5  2003/06/25 12:06:26  sturm
dnl Added lithist option.
dnl acconfig.h and redfront_color.red are obsolete.
dnl
dnl Revision 1.4  2003/06/23 08:12:10  sturm
dnl Implemented coloring and cmdhist option.
dnl
dnl Revision 1.3  1999/09/20 14:57:58  sturm
dnl Adapted --with-td default to 16000000 as specified for 3.7.
dnl
dnl Revision 1.2  1999/09/20 13:50:54  sturm
dnl Adapted PSL image model check to 3.7. Image can be anywhere in $reduce now.
dnl
dnl Revision 1.1  1999/09/20 13:37:52  sturm
dnl Private autoconf-based REDFRONT development branch by A. Dolzmann
dnl and T. Sturm.
dnl Initial check-in.
dnl
dnl --------------------------------------------------------------------

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

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
AC_INIT([Redfront],[3.2],[http://sourceforge.net/forum/forum.php?forum_id=899364])

abssrcdir=`cd $srcdir/../../../scripts; ./here.sh`

AC_DEFINE_UNQUOTED(REDFRONTSRCDIR,"$abssrcdir/generic/redfront/src",[Absolute path to the redfront source directory])

AC_CANONICAL_HOST
BUILD=`eval "$SHELL $srcdir/../../../scripts/findhost.sh $host $ac_configure_args"`
AC_MSG_NOTICE([Build platform detected as $BUILD])
AC_SUBST(BUILD)

RBUILD=$(basename $BUILD -debug)

dnl Checks for programs.
AC_PROG_CC

AS_IF([test "$EXEEXT" = .exe],
  [AC_DEFINE(WIN32,1,[This is some Windows version])
   AC_DEFINE(USE_PIPES,1,[Define as 1 for using pipes instead if sockets])
   COMEXT=.com
   on_windows=yes],
  [AC_ARG_ENABLE(pipes,
   AC_HELP_STRING([--enable-pipes],
		  [use pipes not sockets on systems other than Windows]),
   if test "$enableval" = no ; then
      AC_DEFINE(USE_PIPES,0,[Define  1 for using pipes instead if sockets])
   else
      AC_DEFINE(USE_PIPES,1,[Define to 1 for using pipes instead if sockets])
   fi,
   AC_DEFINE(USE_PIPES,0,[Define to 1 for using pipes instead if sockets]))
   COMEXT=""])

dnl I have copied the following Apple stuff from cslbase/configure.ac.
dnl Since I do not use automake, considerations about depnedency
dnl tracking there are not relevant for me:
case $host in *darwin*)
  on_darwin=yes
  AC_MSG_NOTICE([Building for Macintosh/Darwin])
  AC_DEFINE(MACINTOSH, [1], [True if we are running on Macintosh])
# The following line was suggested by the libEDIT configuration files.
# Even though I no longer use libEDIT I will keep it!
#
# OK. -fno-common causes C programs to lead to a linker error if you have
#     declarations of variables in several files. It may thus count as
#     and extra safety measure.
#     -no-cpp-precomp was historically useful because some people
#     found that the Apple pre-processor gave them trouble, so I think it
#     arranges a slower but possibly safer compilation. It is probably not
#     needed at all these days.
  CFLAGS="$CFLAGS -fno-common -no-cpp-precomp"
  CXXFLAGS="$CXXFLAGS -fno-common -no-cpp-precomp"

  AC_ARG_ENABLE(universal,
    AC_HELP_STRING([--enable-universal],
	[build universal binary on Mac OSX]),
    universal="$enableval",
    universal=no)

  AS_IF([test "$universal" = yes],[
   AC_MSG_NOTICE([Checking for ability to build dual arch binaries])
# If it seems to be supported at all I will go "-arch ppc -arch i386" to
# build a fat binary that will run on both powerpc and intel-based
# 32-bit macs.
   sysroot=""
   AC_MSG_NOTICE([Checking for OSX10.5 framework])
   OLDCFLAGS="$CFLAGS"
   CFLAGS="$CFLAGS -isysroot /Developer/SDKs/MacOSX10.5.sdk"
   AC_LINK_IFELSE([AC_LANG_PROGRAM([[#include <stdio.h>]],
                                   [[printf("Hello\n");]])],
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
                                    [[printf("Hello\n");]])],
      [CXXFLAGS="$CXXFLAGS -isysroot /Developer/SDKs/MacOSX10.4u.sdk"
       AC_MSG_NOTICE([MacOS10.4u SDK found])
       sysroot="/Developer/SDKs/MacOSX10.4u"],
      [CFLAGS="$OLDCFLAGS"
       AC_MSG_NOTICE([MacOS10.4u SKD NOT found])])
  fi
  OLDCFLAGS="$CFLAGS"
  CFLAGS="$CFLAGS -arch ppc -arch i386"
  AC_LINK_IFELSE([AC_LANG_PROGRAM([[#include <stdio.h>]],
                                  [[printf("Hello\n");]])],
     [CXXFLAGS="$CXXFLAGS -arch ppc -arch i386"
     LDFLAGS="$LDFLAGS -arch ppc -arch i386"
     fat_support_available="yes"],
    [CFLAGS="$OLDCFLAGS"
     fat_support_available="no"])
  AC_MSG_NOTICE([fat_support=$fat_support_available])
])
;;
esac

AC_CONFIG_HEADER(config.h)

AC_ARG_WITH(csl-reduce,[  --with-csl-reduce=FILE  location of the executable CSL REDUCE],
        cslreduce="$withval",cslreduce="$abssrcdir/cslbuild/$RBUILD/csl/reduce$COMEXT")
AC_DEFINE_UNQUOTED(REDUCE,"$cslreduce",
	[Define your executable REDUCE (with CSL)])

AC_ARG_WITH(csl-bootstrapreduce,[  --with-csl-bootstrapreduce=FILE  location of the executable CSL bootstrap REDUCE],
        cslbootstrapreduce="$withval",cslbootstrapreduce="$abssrcdir/cslbuild/$RBUILD/csl/bootstrapreduce$COMEXT")
AC_DEFINE_UNQUOTED(BOOTSTRAPREDUCE,"$cslbootstrapreduce",
	[Define your executable bootstrap REDUCE (with CSL)])

AC_DEFINE_UNQUOTED(REDUCE,"$cslreduce",
	[Define your executable REDUCE (with CSL)])

AC_ARG_WITH(bpsl,[  --with-bpsl=FILE        location of executable bpsl (with PSL)],
        bpsl="$withval",bpsl="$abssrcdir/pslbuild/$RBUILD/psl/bpsl$EXEEXT")
AC_DEFINE_UNQUOTED(BPSL,"$bpsl",
	[Define your executable bpsl (with PSL)])

AC_ARG_WITH(reduce-img,[  --with-reduce-img=FILE  location of the REDUCE image (with PSL)],
        redimg="$withval",redimg="$abssrcdir/pslbuild/$RBUILD/red/reduce.img")
AC_DEFINE_UNQUOTED(REDIMG,"$redimg",
	[Define your REDUCE image (with PSL)])
AC_ARG_WITH(td,AC_HELP_STRING([--with-td=BYTES],
	[the default argument for bpsl -td]),defmem=$withval,defmem=0)
AC_DEFINE_UNQUOTED(MEMORY,"$defmem",
	[Define bytes allocated by BPSL (-td argument) as a string])

dnl AC_ARG_WITH(csl,
dnl   AC_HELP_STRING([--with-csl], [use the CSL Lisp system]),
dnl   [],
dnl   [with_csl="no"])

dnl AC_ARG_WITH(psl,
dnl   AC_HELP_STRING([--with-psl], [use the PSL Lisp system]),
dnl   [],
dnl   [with_psl="no"])

dnl if test "x$with_csl" != "xno" ; then
dnl    if test "x$with_psl" != "xno" ; then
dnl       AC_MSG_ERROR("use only one of --with-csl or --with-psl")
dnl    fi
dnl    AC_DEFINE_UNQUOTED(REDUCE,"$abssrcdir/cslbuild/$RBUILD/csl/reduce$COMEXT",
dnl       [Define your executable REDUCE (with CSL)])
dnl elif test "x$with_psl" != "xno" ; then
dnl    if test "x$with_csl" != "xno" ; then
dnl       AC_MSG_ERROR("use only one of --with-csl or --with-psl")
dnl    fi
dnl    AC_DEFINE_UNQUOTED(BPSL,"$abssrcdir/pslbuild/$RBUILD/psl/bpsl$EXEEXT",
dnl 	[Define your executable bpsl (with PSL)])
dnl    AC_DEFINE_UNQUOTED(REDIMG,"$abssrcdir/pslbuild/$RBUILD/red/reduce.img",
dnl 	[Define your REDUCE image (with PSL)])
dnl    AC_ARG_WITH(td,
dnl 	AC_HELP_STRING([--with-td=BYTES],
dnl 		[the default argument for bpsl -td]),
dnl 	defmem=$withval,defmem=0)
dnl    AC_DEFINE_UNQUOTED(MEMORY,"$defmem",
dnl 	[Define bytes allocated by BPSL (-td argument) as a string])
dnl else
dnl    AC_MSG_ERROR("use one of --with-csl or --with-psl")
dnl fi

AC_ARG_WITH(redfront-root,[  --with-redfront-root=DIR  location of the redfront.red file],
        redfrontroot="$withval",redfrontroot="$abssrcdir/packages/redfront")
AC_DEFINE_UNQUOTED(REDFRONTROOT,"$redfrontroot",
	[Define the location of redfront.red])

AC_ARG_WITH(package-map,[  --with-package-map=FILE location of the pacakge.map file],
        packagemap="$withval",packagemap="$abssrcdir/packages/package.map")
AC_DEFINE_UNQUOTED(PACKAGE_MAP,"$packagemap",
	[Define the location of package.map])

dnl Checks for libraries.
AC_CHECK_LIB(termcap,main,LIBS="-ltermcap $LIBS",\
AC_MSG_ERROR("Please install libtermcap-devel (or similar) first"))
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
   AC_HELP_STRING([--disable-color],[do not color any text]),
   if test "$enableval" = no ; then
      AC_DEFINE(HAVE_COLOR,0,[Define for color terminal support])
   else
      AC_DEFINE(HAVE_COLOR,1,[Define for color terminal support])
   fi,
   AC_DEFINE(HAVE_COLOR,1,[Define for color terminal support]))

AC_ARG_WITH(hist-size,[  --with-hist-size=LINES  length of the .reduce_history file [[LINES=10000]]],
	histfilesize=$withval,histfilesize=10000)
AC_DEFINE_UNQUOTED(HISTFILESIZE,$histfilesize,
	[Define the maximum number of lines in your .reduce_history])

AC_ARG_ENABLE(debug,
   AC_HELP_STRING([--enable-debug],
      [comprehensive printing of debugging messages]),
if test "$enableval" = yes ; then
AC_DEFINE(DEBUG,1,[Define this for debug information on signals and files])
fi)

AC_ARG_ENABLE(static,
   [AC_HELP_STRING([--enable-static],
       [static linking on systems other than Windows])
AC_HELP_STRING([--disable-static],
       [dynamic linking on Windows])],
if test "$enableval" = yes ; then
AC_DEFINE(STATIC,1,[static linking info in banner])
AC_SUBST(LDFLAGS,"-static $LDFLAGS")
else
AC_DEFINE(STATIC,0,[static linking info in banner])
fi,
if test "$on_windows" = yes ; then
AC_DEFINE(STATIC,1,[static linking info in banner])
AC_SUBST(LDFLAGS,"-static $LDFLAGS")
else
AC_DEFINE(STATIC,0,[static linking info in banner])
fi
)

editline=yes
#editlinepath="$abssrcdir/generic/redfront/$RBUILD/libedit"
editlinepath=""
AC_ARG_WITH(libedit,
   AC_HELP_STRING([--without-libedit],[do not use libedit]),
if test "$withval" = no 
  then editline=no
elif test -n "$withval"
  then editlinepath="$withval"
fi)

if test "$editline" = yes ; then
  AC_DEFINE(HAVE_LIBEDIT,1,[use libedit])
fi

AS_IF([test "$editline" = no -a "$on_darwin" = yes],
   [CFLAGS="$CFLAGS -I/sw/include"; LDFLAGS="$LDFLAGS -L/sw/lib"])

AS_IF([test "$editline" = no],
  [AC_CHECK_LIB(readline,readline,LIBS="-lreadline $LIBS",
      AC_MSG_ERROR("no editline alternative found"))
   AC_CHECK_LIB(readline,using_history,
      AC_DEFINE(HAVE_HISTORY,1,[history available]),
      AC_CHECK_LIB(history,using_history,
         AC_DEFINE(HAVE_HISTORY,1,[history provided by libhistory])))])

AS_IF([test "$editline" = yes &&
         { test "$on_darwin" != yes || test "$fat_support_available" != yes; }],
  [if test "$editlinepath" != "yes" ; then
     ebd=$editlinepath
     CFLAGS="$CFLAGS -I$ebd/include"
     LDFLAGS="$LDFLAGS -L$ebd/lib -L$ebd/lib64"
     if test "X$on_windows" != Xyes && test "X$on_darwin" != Xyes ; then
         LDFLAGS="$LDFLAGS -Wl,-rpath,$ebd/lib -Wl,-rpath,$ebd/lib64"
     fi
   fi
   AC_CHECK_HEADERS(filecomplete.h,
      AC_DEFINE(HAVE_FILECOMPLETE_H,1))
])

AS_IF([test "$editline" = yes],
   AC_CHECK_LIB(edit,using_history,
      [LIBS="$editlinepath/lib/libedit.a $LIBS"
dnl I am adding the libedit/src for filecomplete.h. This is going to
dnl be used even with the system libedit for Darwin universal builds.
#       CFLAGS="$CFLAGS -I$abssrcdir/generic/redfront/libedit/src"
       AC_DEFINE(HAVE_HISTORY,1,[history provided by libedit])],
      AC_MSG_ERROR("libedit not found")))

AC_ARG_ENABLE(cmdhist,
   AC_HELP_STRING([--disable-cmdhist],[do not use cmdhist in the sense of bash]),
if test "$enableval" = no ; then
AC_DEFINE(CMDHIST,0,[Use bash cmdhist history style])
else
AC_DEFINE(CMDHIST,1,[Use bash cmdhist history style])
fi,
AC_DEFINE(CMDHIST,1,[Use bash cmdhist history style])
)

AC_ARG_ENABLE(lithist,
   AC_HELP_STRING([--disable-lithist],[do not use lithist in the sense of bash]),
if test "$enableval" = no ; then
AC_DEFINE(LITHIST,0,[Use bash lithist history style])
else
AC_DEFINE(LITHIST,1,[Use bash lithist history style])
fi,
AC_DEFINE(LITHIST,1,[Use bash lithist history style])
)

AC_ARG_ENABLE(ignoredups,
   AC_HELP_STRING([--disable-ignoredups],[do not use ignordups in the sense of bash]),
if test "$enableval" = no ; then
AC_DEFINE(IGNOREDUPS,0,[Ignore adjacent duplicate history entries])
else
AC_DEFINE(IGNOREDUPS,1,[Ignore adjacent duplicate history entries])
fi,
AC_DEFINE(IGNOREDUPS,1,[Ignore adjacent duplicate history entries])
)

AC_OUTPUT(Makefile)

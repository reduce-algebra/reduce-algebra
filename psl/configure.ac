#### FIX THE NEXT LINE
AC_INIT([PSL], [20080915], [https://sourceforge.net/p/reduce-algebra/bugs/],,
	       [https://reduce-algebra.sourceforge.io/])

AC_COPYRIGHT([The REDUCE project])

AC_CANONICAL_HOST()

AC_CONFIG_SRCDIR(README.PSL)

AC_CONFIG_FILES([Makefile])
AC_CONFIG_MACRO_DIRS([m4])
AC_CONFIG_AUX_DIR([.])

AM_INIT_AUTOMAKE([1.8.3 -Wno-portability foreign no-dist-gzip dist-bzip2])

LT_INIT

AC_CHECK_PROGS(CYGPATH,[cygpath],[no])
AM_CONDITIONAL(cygpath, test "x$CYGPATH" != "xno")

AC_ARG_WITH(autogen,
  AS_HELP_STRING([--with-autogen], [Regenerate autoconf-related files]),
  [],
  [with_autogen="yes"])

AC_ARG_WITH(m32,
   AS_HELP_STRING([--with-m32], [Force use of 32-bit mode on 64-bit host]),
   [],
   [with_m32="no"])

AC_ARG_WITH(csl,
  AS_HELP_STRING([--with-csl], [Use the CSL Lisp system]),
  [],
  [with_csl="no"])

AC_ARG_WITH(psl,
  AS_HELP_STRING([--with-psl], [Use the PSL Lisp system]),
  [],
  [with_psl="no"])

AC_ARG_WITH(build,
   AS_HELP_STRING([--with-build], [specify host-name to use when logging]),
   [],
   [with_build="unknown"])

BUILD="$with_build"

if test "x$BUILD" = "xunknown"
then
  BUILD=`eval "$SHELL $srcdir/../scripts/findhost.sh $host $ac_configure_args"`
  AC_MSG_NOTICE([Build platform detected as $BUILD])
else
  AC_MSG_NOTICE([Build platform specified as $BUILD])

fi

AC_SUBST(BUILD)

AC_ARG_WITH(package,
  AS_HELP_STRING(AS_HELP_STRING([--with-package=PKG]),
                 [Use PKG.map rather than package.map to list modules]),
  [PACKAGEMAP="$withval"],
  [PACKAGEMAP="package"])

AC_SUBST(PACKAGEMAP)

pslver=`"$srcdir/../scripts/pslver.sh"`

# Stop if the system type is not recognized

if test "$pslver" = "unknown"
then
  AC_MSG_ERROR([No PSL port found for platform $BUILD])
fi

# Here if "--with-m32" is set I demote some 64-bit hosts to run in 32-bit
# mode. This has in thge past been useful when running on a 64-bit Linux
# host but wanting to test or build a 32-bit system.

if test "$with_m32" = "yes"
then
  case $pslver in
  amd64|AMD64|AMD64_ext)
    pslver="linux"
    ;;
  macintel64)
    pslver="macintel"
    ;;
  solaris64)
    pslver="solaris"
    ;;
  mingw-w64)
    pslver="win32"
    ;;
  aarch64)
    pslver="armv6"
    ;;
  esac
fi

if test -d $srcdir/psl-$pslver -a -f $srcdir/psl-$pslver/xport.pat -a "x$DONT_USE_XPORT" = "x"
then
# Now I need to build a copy of the "xport" utility. You may view it as
# mildly eccentric to build this tool at configure time!

mkdir -p xport
cd xport
"$srcdir"/support-packages/xport-2.05/configure
make
cd ..

fi

AC_MSG_NOTICE([Will build this PSL using the $pslver initial binaries])

# rm -rf psl
mkdir -p psl

test -d $srcdir/psl-$pslver && cp -r $srcdir/psl-$pslver/* psl

if test -f psl/xport.pat -a "x$DONT_USE_XPORT" = "x"
then

# Now in my new world about the only thing that will have been copied here
# will be a file "xport.pat". This can then be used to arrange to fetch the
# relevant pre-build PSL binary files from a web-site (www.zib.de) where they
# are maintained, and is a scheme adopted here to make thePSL version
# available NOW while a full source release is still being worked on.

cd psl
# If there is no xport.pat file, do not try to update the files
if test -f xport.pat; then
  AC_MSG_NOTICE([About to update PSL binaries from master web-site at ZIB])
  ../xport/xport -fetch
fi
# xport.pat should really have "executable bpsl" in it, but in case it does
# not I will force executable status here...
chmod +x bpsl*
cd ..

else

  cp ../../psl/dist/nonkernel/$pslver/lap/* psl
  cp ../../psl/dist/lap/$pslver/*.b psl
  cp ../../psl/dist/kernel/$pslver/bpsl* psl

  cp psl/nbig32.b psl/zbig.b
  rm -f psl/*rlisp*.b psl/compat.b

  chmod +x psl/bpsl*

fi

# The pre-built PSL file-sets contain a file called "64", probably containing
# just the text "yes", in cases that the implementation is 64-bit.

AM_CONDITIONAL(sixty_four, test -f psl/64)

unm=`uname -m`
uns=`uname -s`

AM_CONDITIONAL(windows, test "X$OS" = "XWindows_NT")
# AM_CONDITIONAL(i686, test "$unm" = "i686")
AM_CONDITIONAL(x86_64, test "$unm" = "x86_64")
AM_CONDITIONAL(macintosh, test "$uns" = "Darwin")
AM_CONDITIONAL(linux, test "$uns" = "Linux")

AC_OUTPUT

# end of configure.ac


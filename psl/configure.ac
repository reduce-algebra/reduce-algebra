#### FIX THE NEXT LINE
AC_INIT([PSL], [20080915], [email@maintainer.org])

#### FIX THE NEXT LINE
AC_COPYRIGHT([Whoever])

AC_CANONICAL_HOST()

AC_CONFIG_SRCDIR(README.PSL)

AM_INIT_AUTOMAKE([1.9.0 -Wall -Werror -Wno-portability foreign no-dist-gzip dist-bzip2])

AC_CONFIG_FILES([Makefile])

AC_CHECK_PROGS(CYGPATH,[cygpath],[no])
AM_CONDITIONAL(cygpath, test "x$CYGPATH" != "xno")

AC_ARG_WITH(m32,
   AC_HELP_STRING([--with-m32], [Force use of 32-bit mode on 64-bit host]),
   [],
   [with_m32="no"])

AC_ARG_WITH(csl,
  AC_HELP_STRING([--with-csl], [Use the CSL Lisp system]),
  [],
  [with_csl="no"])

AC_ARG_WITH(psl,
  AC_HELP_STRING([--with-psl], [Use the PSL Lisp system]),
  [],
  [with_psl="no"])

AC_ARG_WITH(build,
   AC_HELP_STRING([--with-build], [specify host-name to use when logging]),
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

pslver=`$srcdir/../scripts/pslver.sh`

# Here if "--with-m32" is set I demote some 64-bit hosts to run in 32-bit
# mode. This has in thge past been useful when running on a 64-bit Linux
# host but wanting to test or build a 32-bit system.

if test "$with_m32" = "yes"
then
  case $pslver in
  amd64)
    pslver="linux"
    ;;
  macintel64)
    pslver="macintel"
    ;;
  solaris64)
    pslver="solaris"
    ;;
  esac
fi

# Now I need to build a copy of the "xport" utility. You may view it as
# mildly eccentric to build this tool at configure time!

mkdir xport
cd xport
$srcdir/support-packages/xport-2.05/configure
make
cd ..

AC_MSG_NOTICE([Will build this PSL using the $pslver initial binaries])

# rm -rf psl
mkdir psl
cp -r $srcdir/psl-$pslver/* psl

# Now in my new world about the only thing that will have been copied here
# will be a file "xport.pat". This can then be used to arrange to fetch the
# relevant pre-build PSL binary files from a web-site (www.zib.de) where they
# are maintained, and is a scheme adopted here to make thePSL version
# available NOW while a full source release is still being worked on.

cd psl
AC_MSG_NOTICE([About to update PSL binaries from master web-site at ZIB])
../xport/xport -fetch
# xport.pat should really have "executable bpsl" in it, but in case it does
# not I will force executable status here...
chmod +x bpsl*
cd ..

# The pre-built PSL file-sets contain a file called "64", probably containing
# just the text "yes", in cases that the implementation is 64-bit.

AM_CONDITIONAL(sixty_four, test -f psl/64)

AC_OUTPUT

# end of configure.ac


AC_INIT([REDUCE], [20080421], [acn1@cam.ac.uk])

AC_COPYRIGHT([The REDUCE project])

abssrcdir=`$srcdir/scripts/here.sh`

AC_MSG_NOTICE([Absolute path to source directory = $abssrcdir])

# The following MESS is hereto check whether the autoconf-related files
# are all up to date.

ok="yes"

# Step 1: aclocal.m4 must be later than configure.ac in directories where
#         libtool is not involved.

for d in . csl csl/cslbase csl/foxtests csl/fox psl psl/support-packages/xport-2.05
do
  c="configure.ac"
  if test "$d" = "csl/fox"; then c="configure.in"; fi
  if test $srcdir/$d/aclocal.m4 -ot $srcdir/$d/$c
  then
    echo $d/aclocal.m4 is older than $d/$c
    ok="no"
  fi
done

# Step 2: aclocal.m4 must be newer that both configure.ac and the
#         libtool-related things in the m4 directory when they
#         exist. In the csl/fox directory the name configure.in is
#         used for historical reasons.

lt="m4/libtool.m4 m4/ltoptions.m4 m4/ltsugar.m4 m4/ltversion.m4 m4/lt~obsolete.m4"

for d in csl csl/fox
do
  for x in $lt
  do
    if test $srcdir/$d/aclocal.m4 -ot $srcdir/$d/$x
    then
      echo "$d/aclocal.m4 was older than $d/$x"
      ok="no"
    fi
  done
done


# Step 3: Makefile.in must be newer than aclocal.m4, and that will lead
#         to it being newer than any of the libtool-related m4 files.
#         It must also be newer than Makefile.am.

for d in . csl csl/cslbase csl/foxtests psl psl/support-packages/xport-2.05
do
  if test $srcdir/$d/Makefile.in -ot $srcdir/$d/aclocal.m4
  then
    echo $d/Makefile.in is older than $d/aclocal.m4
    ok="no"
  fi
  if test $srcdir/$d/Makefile.in -ot $srcdir/$d/Makefile.am
  then
    echo $d/Makefile.in is older than $d/Makefile.am
    ok="no"
  fi
done

# Step 3a: As step 3, but in cases where aclocal.m4 lives in a parent
#          directory.

for d in csl/fox csl/fox/doc csl/fox/doc/art csl/fox/doc/screenshots csl/fox/include csl/fox/src csl/fox/utils
do
  if test $srcdir/$d/Makefile.in -ot $srcdir/csl/fox/aclocal.m4
  then
    echo $d/Makefile.in is older than csl/fox/aclocal.m4
    ok="no"
  fi
  if test $srcdir/$d/Makefile.in -ot $srcdir/$d/Makefile.am
  then
    echo $d/Makefile.in is older than $d/Makefile.am
    ok="no"
  fi
done

# Step 4: config.h.in must be newer than aclocal.m4

for d in csl csl/cslbase
do
  if test $srcdir/$d/config.h.in -ot $srcdir/$d/aclocal.m4
  then
    echo $d/config.h.in is older than $d/aclocal.m4
    ok="no"
  fi
done

# Step 5: configure must be newer than aclocal.m4

for d in . csl csl/cslbase csl/fox csl/foxtests psl psl/support-packages/xport-2.05
do
  if test $srcdir/$d/configure -ot $srcdir/$d/aclocal.m4
  then
    echo $d/configure is older than $d/aclocal.m4
    ok="no"
  fi
done

if test "x$ok" = "xno"
then
  ( ( $srcdir/autogen.sh && eval "$SHELL $srcdir/configure $ac_configure_args" ) ; exit 0 )
fi

AC_CANONICAL_HOST()

AC_ARG_WITH(csl,
  AC_HELP_STRING([--with-csl], [Use the CSL Lisp system]),
  [],
  [with_csl="no"])

AC_ARG_WITH(psl,
  AC_HELP_STRING([--with-psl], [Use the PSL Lisp system]),
  [],
  [with_psl="no"])

AC_ARG_WITH(build,
  AC_HELP_STRING([--with-build], [Used internally to control build directory]),
  [],
  [with_build="unknown"])

# Ensure that at least one Lisp system is selected
if test "x$with_psl" = "xno" && test "x$with_csl" = "xno"
then
  AC_MSG_ERROR(
    [you must specify either --with-csl or --with-psl to select a Lisp])
fi

############################################################################
#
# Modern versions of the autoconf tools seems to moan dreadfully if you pass
# down a flag that they do not know about, and so I transcribe into here
# all the flags that the CSL configuration may ever want!

# My understanding of the LGPL is now that the mechanism that this enabled
# is not in fact needed.

AC_ARG_WITH(lgplfiles,
   AC_HELP_STRING([--with-lgplfiles],
                  [Make binaries even safer to distribute wrt LGPL]),
   [],
   [with_lgplfiles="no"])

AC_ARG_WITH(mingw64,
   AC_HELP_STRING([--with-mingw64],
                  [Try to cross-build using 64-bit mingw]),
   [],
   [with_mingw64="no"])

AC_ARG_WITH(m32,
   AC_HELP_STRING([--with-m32],
                  [Force 32-bit model even on 64-bit gcc]),
   [],
   [with_m32="no"])

AC_ARG_WITH(m64,
   AC_HELP_STRING([--with-m64],
                  [Force 64-bit model even if 32-bit is default]),
   [],
   [with_m64="no"])

AC_ARG_WITH(cygwin,
  AC_HELP_STRING([--with-cygwin],
                 [Force use of raw cywgin (note GPL)]),
  [],
  [with_cygwin="no"])
AC_ARG_WITH(mingw,
  AC_HELP_STRING([--with-mingw[=DIR]],
                 [MingW installation location]),
  mingw_location="$withval",
  mingw_location="")
AC_ARG_WITH(fox,
  AC_HELP_STRING([--with-fox=DIR],
                 [FOX installation location]),
  [],
  [with_fox="no"])
AC_ARG_WITH(fox-pending,
  AC_HELP_STRING([--with-fox-pending],
                 [do not check dir from --with-fox]),
  [],
  [with_fox_pending="no"])
AC_ARG_WITH(xft,
  AC_HELP_STRING([--with-xft],
                 [Can be used to disable use of XFT. Default is yes]),
  [],
  [with_xft="yes"])
AC_ARG_ENABLE(debug,
  AC_HELP_STRING([--enable-debug],
                 [compile for debugging]),
  [],
  [enable_debug="no"])
AC_ARG_ENABLE(conservative,
  AC_HELP_STRING([--enable-conservative],
                 [garbage collect option]),
  [],
  [enable_conservative="no"])
AC_ARG_ENABLE(test,
  AC_HELP_STRING([--enable-test],
                 [testing-mode version]),
  [],
  [enable_test="no"])
AC_ARG_ENABLE(jit,
  AC_HELP_STRING([--enable-jit],
                 [build in experimental JIT]),
  [],
  [enable_jit="no"])
AC_ARG_ENABLE(static,
  AC_HELP_STRING([--enable-static],
                 [link it all statically]),
  [],
  [enable_static="no"])

###########################################################################

# I have a fairly elaborate scheme to select a directory to use.
build=`eval "$SHELL $srcdir/scripts/findhost.sh $host $ac_configure_args"`

case $srcdir in
  .)
# Here somebody has run the "configure" script within the top-level
# source directory. I really want the build to take place in a
# host-specific subdirectory so I will divert things!
# When testing if --with-csl etc got passed I should check that the option
# NO was NOT given rather than that the option yes was.
  if test "x$with_csl" != "xno"
  then
    AC_MSG_NOTICE([+++ Will build in $abssrcdir/cslbuild/$build])
    if ! test -d $abssrcdir/cslbuild/$build
    then
      mkdir -p $abssrcdir/cslbuild/$build
    fi
# When I configure I will install a default "profile.dat" if there is
# not one in place already, but the user can always regenerate a newer
# local version of the profile.
    if ! test -f $abssrcdir/cslbuild/profile.dat
    then
      cp -p $abssrcdir/csl/profile.dat $abssrcdir/cslbuild
    fi
    if ! test -d $abssrcdir/cslbuild/csl-c
    then
      rm -rf $abssrcdir/cslbuild/generated-c
      mkdir -p $abssrcdir/cslbuild/generated-c
    fi
    cd $abssrcdir/cslbuild/$build 
    eval "$SHELL $abssrcdir/configure $ac_configure_args --with-build=$build"
    cd $abssrcdir
  fi
  if test "x$with_psl" != "xno"
  then
    AC_MSG_NOTICE([+++ Will build in $abssrcdir/pslbuild/$build])
    if ! test -d $abssrcdir/pslbuild/$build
    then
      mkdir -p $abssrcdir/pslbuild/$build
    fi
    cd $abssrcdir/pslbuild/$build
    eval "$SHELL $abssrcdir/psl/configure $ac_configure_args --with-build=$build"
    cd $abssrcdir
  fi
  exit 0
  ;;
  *)
  AC_MSG_NOTICE([+++ standard build case, srcdir = $srcdir = $abssrcdir])
  ;;
esac


# This is where the main bit of this script starts.


AC_CONFIG_SRCDIR(scripts/make.sh)

AM_INIT_AUTOMAKE([-Wall -Werror -Wno-portability foreign no-dist-gzip dist-bzip2])

AC_CONFIG_FILES([Makefile])

###############################################################################
if test "x$with_csl" != "xno"
then
# Here I have a bunch of sub-directories that I need to configure

  builddir=`pwd`

  AC_MSG_NOTICE([About to configure CSL core])
  mkdir -p csl
  cd csl

  AC_MSG_NOTICE([$SHELL $abssrcdir/csl/cslbase/configure $ac_configure_args --with-fox=$builddir --with-fox-pending=yes --with-build=$build])
  eval "$SHELL $abssrcdir/csl/cslbase/configure $ac_configure_args --with-fox=$builddir --with-fox-pending=yes --with-build=$build"

  cd $builddir

  AC_MSG_NOTICE([About to configure FOX])
  mkdir -p fox/src
  cd fox

  # The Makefile that comes with FOX seems to require these GIF files
  # in the build directory.
  cp $abssrcdir/csl/fox/src/*.gif src

  AC_ARG_WITH(cygwin,
    AC_HELP_STRING([--with-cygwin], [Use raw cygwin so link with cygwin1.dll (GPL)]),
    [],
    [with_cygwin="no"])

  extras=

  case $host in
    *cygwin*)
      if test "x$with_cygwin" != "xyes"
      then
# Unless the user explictly asked for "--with-cygwin" I will arrange to
# build in "mingw" mode to avoid linking in cygwin1.dll and becoming
# constrained by the limitations (however minor some may consider them
# to be) of the cygwin licensing terms.
        AC_MSG_NOTICE([GCC option "-mno-cygwin" being used to avoid use GPL libraries.])
        CPPFLAGS="$CPPFLAGS -mno-cygwin"
        CFLAGS="$CFLAGS -mno-cygwin"
        CXXFLAGS="$CXXFLAGS -mno-cygwin"
        LDFLAGS="-mwindows"
        export CPPFLAGS CFLAGS CXXFLAGS LDFLAGS
      else
        AC_MSG_NOTICE([Using raw cygwin])
        CFLAGS="$CFLAGS "
        CXXFLAGS="$CXXFLAGS "
        export CFLAGS CXXFLAGS
        extras="--with-xft"
      fi
      ;;
    *-*solaris*)
# Solaris is treated specially here because my experiments with it seemed
# to show that Xft gave me a lot of pain. So I do not look for it on
# that platform. That may at present cause everything to fail to build!
      CFLAGS="$CFLAGS "
      CXXFLAGS="$CXXFLAGS "
      export CFLAGS CXXFLAGS
      ;;
    *)
# On most non-windowed platforms Xft is a very good idea! And I am now
# relying on it.
      CFLAGS="$CFLAGS "
      CXXFLAGS="$CXXFLAGS "
      export CFLAGS CXXFLAGS
      extras="--with-xft"
      ;;
  esac

  AC_ARG_WITH(m32,
    AC_HELP_STRING([--with-m32], [Pass "-m32" to C compiler]),
    [],
    [with_m32="no"])
  AC_ARG_WITH(m64,
    AC_HELP_STRING([--with-m64], [Pass "-m64" to C compiler]),
    [],
    [with_m64="no"])

  if test "x$with_m32" != "xno"
  then
    CFLAGS="$CFLAGS -m32"
    CXXFLAGS="$CXXFLAGS -m32"
    LDFLAGS="$LDFLAGS -m32"
    extras="$extras --x-libraries=/usr/X11R6/lib"
    export CFLAGS CXXFLAGS LDFLAGS
  fi

  if test "x$with_m64" != "xno"
  then
    CFLAGS="$CFLAGS -m64"
    CXXFLAGS="$CXXFLAGS -m64"
    LDFLAGS="$LDFLAGS -m64"
    extras="$extras --x-libraries=/usr/X11R6/lib64"
    export CFLAGS CXXFLAGS LDFLAGS
  fi

  AC_MSG_NOTICE([CPPFLAGS=$CPPFLAGS])
  AC_MSG_NOTICE([CFLAGS=$CFLAGS])
  AC_MSG_NOTICE([CXXFLAGS=$CXXFLAGS])
  AC_MSG_NOTICE([LDFLAGS=$LDFLAGS])
  AC_MSG_NOTICE([$SHELL $abssrcdir/csl/fox/configure $ac_configure_args \
          CPPFLAGS="$CPPFLAGS" CFLAGS="$CFLAGS" \
          CXXFLAGS="$CXXFLAGS" LDFLAGS="$LDFLAGS" \
          --disable-shared --enable-release --with-opengl=no \
          --disable-jpeg --disable-zlib --disable-bz2lib \
          --disable-png --disable-tiff --prefix=$builddir $extras])
  eval "$SHELL $abssrcdir/csl/fox/configure $ac_configure_args \
          CPPFLAGS=\"$CPPFLAGS\" CFLAGS=\"$CFLAGS\" \
          CXXFLAGS=\"$CXXFLAGS\" LDFLAGS=\"$LDFLAGS\" \
          --disable-shared --enable-release --with-opengl=no \
          --disable-jpeg --disable-zlib --disable-bz2lib \
          --disable-png --disable-tiff --prefix=$builddir $extras"

# If you do NOT use libtoolcacheize then the time it takes to compile
# FOX when you are on Windows is extreme. This is mainly because
# Windows does not provide an efficient mechanism that can support "fork",
# and the scripts within libtool end up running VERY VERY slowly.

  LTC="false"
  IFSsave="$IFS"
  IFS=":"
  for p in $PATH
  do
    if test "$LTC" = "false"
    then
#     AC_MSG_NOTICE([checking for $p/libtoolcacheize])
      if test -x $p/libtoolcacheize
      then
         LTC="$p/libtoolcacheize"
         IFS="$IFSsave"
         AC_MSG_NOTICE([Found $LTC])
      fi
    fi
  done
  IFS="$IFSsave"
# I will look in /usr/local/bin even if it is not in $PATH
  if test "$LIC" = "false" && test -x /usr/local/bin/libtoolcacheize
  then
    LIC="/usr/local/bin/libtoolcacheize"
  fi

  if test "$LTC" != "false"
  then
    AC_MSG_NOTICE([About to run $LTC])
    if $LTC
    then
      AC_MSG_NOTICE([libtoolcacheized successfully])
    else
      AC_MSG_NOTICE([$LTC failed])
    fi
  else
    AC_MSG_NOTICE([libtoolcacheize not found])
  fi

  cd $builddir

  if test -d $abssrcdir/csl/foxtests
  then
    AC_MSG_NOTICE([About to configure FOX tests])
    mkdir -p foxtests
    cd foxtests

    AC_MSG_NOTICE([$SHELL $abssrcdir/csl/foxtests/configure $ac_configure_args --with-fox=$builddir --with-fox-pending=yes $extras])
    eval "$SHELL $abssrcdir/csl/foxtests/configure $ac_configure_args --with-fox=$builddir --with-fox-pending=yes $extras"

    cd $builddir
  fi

fi

###############################################################################


AM_CONDITIONAL(csl, test "x$with_csl" != "xno")
AM_CONDITIONAL(psl, test "x$with_psl" != "xno")
AM_CONDITIONAL(cslpsl, test "x$with_csl" != "xno" && test "x$with_psl" != "xno")

AC_MSG_NOTICE([final output from top level configuration])

AC_OUTPUT

# end of configure.ac


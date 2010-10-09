AC_INIT([REDUCE], [20080421], [acn1@cam.ac.uk])

# The next line is a dreadful thing and is in case I am launched
# from a bash prompt, in which case the SHELL variable will be set
# to /bin/bash (or perhaps the user's login shell?). Anyway that hurts
# config.guess on Solaris.... so I will force matters so that I use
# plan vanilla /bin/sh henceforth. So BEWARE and do not use bash extensions!
if test -x /bin/sh
then
  SHELL=/bin/sh
  export SHELL
fi

AC_COPYRIGHT([The REDUCE project])

# I am going to expect that you have at least this version of
# autoconf. In general I will build with  the latest version and
# not really verify that 2.61 is still sufficient!
AC_PREREQ(2.61)

abssrcdir=`$srcdir/scripts/here.sh`

AC_MSG_NOTICE([Absolute path to source directory = $abssrcdir])

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

if test "x$with_psl" != "xno" && test "x$with_csl" != "xno"
then
  AC_MSG_ERROR(
    [If you want to build both CSL and PSL versions then you will
need to run the configure script twice, once with --with-csl and any
other relevent options and once with --with-psl and any relevant PSL
options. After that you may use "make" and both systems should be made.])
fi

############################################################################
#
# Modern versions of the autoconf tools seems to moan dreadfully if you pass
# down a flag that they do not know about, and so I transcribe into here
# all the flags that the CSL configuration may ever want!

AC_ARG_WITH(mingw64,
   AC_HELP_STRING([--with-mingw64],
                  [Shorthand to force --host=x86_64-w64-mingw32. CSL only]),
   [],
   [with_mingw64="no"])

AC_ARG_WITH(m32,
   AC_HELP_STRING([--with-m32],
                  [Force 32-bit model even on 64-bit gcc. CSL only]),
   [],
   [with_m32="no"])

AC_ARG_WITH(m64,
   AC_HELP_STRING([--with-m64],
                  [Force 64-bit model even if 32-bit is default. CSL only]),
   [],
   [with_m64="no"])

AC_ARG_WITH(cygwin,
  AC_HELP_STRING([--with-cygwin],
                 [Force use of raw cywgin (note licensing consequences please). CSL only]),
  [],
  [with_cygwin="no"])

AC_ARG_WITH(mingw,
  AC_HELP_STRING([--with-mingw[=DIR]],
                 [MingW installation location. CSL only]),
  mingw_location="$withval",
  mingw_location="")

AC_ARG_WITH(fox,
  AC_HELP_STRING([--with-fox=DIR],
                 [FOX installation location, or disable use of FOX. CSL only]),
  [],
  [with_fox="yes"])

AC_ARG_WITH(fox-pending,
  AC_HELP_STRING([--with-fox-pending],
                 [do not check dir from --with-fox. CSL only]),
  [],
  [with_fox_pending="no"])

AC_ARG_WITH(xft,
  AC_HELP_STRING([--with-xft],
                 [Can be used to disable use of XFT. Default is yes. CSL only]),
  [],
  [with_xft="yes"])

AC_ARG_WITH(xim,
  AC_HELP_STRING([--with-xim],
                 [Can be used to control use of XIM. Default is yes (now). CSL only]),
  [],
  [with_xft="yes"])

AC_ARG_ENABLE(debug,
  AC_HELP_STRING([--enable-debug],
                 [compile for debugging. CSL only]),
  [],
  [enable_debug="no"])

AC_ARG_ENABLE(conservative,
  AC_HELP_STRING([--enable-conservative],
                 [garbage collect option. CSL only]),
  [],
  [enable_conservative="no"])

AC_ARG_ENABLE(test,
  AC_HELP_STRING([--enable-test],
                 [testing-mode version. CSL only]),
  [],
  [enable_test="no"])

AC_ARG_ENABLE(jit,
  AC_HELP_STRING([--enable-jit],
                 [build in experimental JIT. CSL only]),
  [],
  [enable_jit="no"])

AC_ARG_ENABLE(static,
  AC_HELP_STRING([--enable-static],
                 [link it all statically. CSL only]),
  [],
  [enable_static="no"])

AC_ARG_WITH(smallpage,
  AC_HELP_STRING([--with-smallpage],
                 [Use 256K pages rather than 4M ones. CSL only]),
  [],
  [with_smallpage="no"])

###########################################################################

# This following is both a shorthand and a fudge to preserve a historical
# way I did things. If you say "--with-mingw64" to this top-level
# configure script it pretends you had asked for cross compilation using
# the standard idiom --host-x86_64-w64-mingw32. Doing things this way here
# means that the lower-level configure scripts just need to understand
# about cross compilation and should not look for --with-mingw64 as such.

if test "x$with_mingw64" != "xno"
then
  host="x86_64-w64-mingw32"
  ac_configure_args="$ac_configure_args --host=$host"
fi

# Now I want to know if the current directory is the same as $srcdir. At
# one stage I checked that by looking to see if $srcdir was ".". That was OK
# for direct calls of the form "./configure" where the "." as in "./" was
# detected. But the reconfig step messes that up and anyway it is a delicate
# cheat. So here is a different delicate cheat!

rm -f ./testfile.tst $srcdir/testfile.tst
touch $srcdir/testfile.tst
if test -f ./testfile.tst
then
  rm -f ./testfile.tst
  inplace="yes"
else
  inplace="no"
fi

echo in-place build attempt = $inplace

# I have a fairly elaborate scheme to select a directory to use. At present
# for PSL there are no relevant extra configure parameters, so I will not
# pass anthing down even if something has been specified! Thus PSL will get
# built in a simple directory named after the operating system while for
# CSL you may be able to create multiple versions (eg debugging and
# non-debugging) on the same machine, and the binaries will get created in
# separate sub-directories.

if test "x$with_psl" != "xno"
then
  build=`eval "$SHELL $srcdir/scripts/findhost.sh $host"`
else
  build=`eval "$SHELL $srcdir/scripts/findhost.sh $host $ac_configure_args"`
fi

AC_MSG_NOTICE([Will build in the $build subdirectory])

case $inplace in
  yes)
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
    if ! test -d $abssrcdir/cslbuild/generated-c ||
       ! test -f $abssrcdir/cslbuild/generated-c/profile.dat
    then
      rm -rf $abssrcdir/cslbuild/generated-c
      mkdir -p $abssrcdir/cslbuild/generated-c
      cp -r $abssrcdir/csl/generated-c $abssrcdir/cslbuild
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
# This passes down any configure arguments to the PSL-specific configuration
# but at present I do not expect any to be relevant.
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

AC_MSG_NOTICE([with_csl=$with_csl with_psl=$with_psl])

AC_CONFIG_SRCDIR(scripts/make.sh)

AM_INIT_AUTOMAKE([1.9.0 -Wall -Werror -Wno-portability foreign no-dist-gzip dist-bzip2])

AC_CONFIG_FILES([Makefile])

###############################################################################
if test "x$with_csl" != "xno"
then
# Here I have a bunch of sub-directories that I need to configure

  builddir=`pwd`

  AC_MSG_NOTICE([About to configure CSL core])
  mkdir -p csl
  cd csl

  if test "x$with_fox" != "xno"
  then
    AC_MSG_NOTICE([$SHELL $abssrcdir/csl/cslbase/configure $ac_configure_args --with-fox=$builddir --with-fox-pending=yes --with-build=$build])
    eval "$SHELL $abssrcdir/csl/cslbase/configure $ac_configure_args --with-fox=$builddir --with-fox-pending=yes --with-build=$build"
  else
    AC_MSG_NOTICE([$SHELL $abssrcdir/csl/cslbase/configure $ac_configure_args --with-build=$build])
    eval "$SHELL $abssrcdir/csl/cslbase/configure $ac_configure_args --with-build=$build"
  fi

  cd $builddir

  if test "x$with_fox" != "xno"
  then
    AC_MSG_NOTICE([About to configure FOX])
    mkdir -p fox/src
    cd fox

    # The Makefile that comes with FOX seems to require these GIF files
    # in the build directory.
    cp $abssrcdir/csl/fox/src/*.gif src
  fi

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
        extras="--with-xft --with-xim"
      fi
      ;;
#
# Well it is easier for me in general if I ALWAYS assume and require Xft
# so I will remove this cop-out... and see how things behave.
#
#    *-*solaris*)
## Solaris is treated specially here because my experiments with it seemed
## to show that Xft gave me a lot of pain. So I do not look for it on
## that platform. That may at present cause everything to fail to build!
#      CFLAGS="$CFLAGS "
#      CXXFLAGS="$CXXFLAGS "
#      export CFLAGS CXXFLAGS
#      ;;
    *)
# On most non-windowed platforms Xft is a very good idea! And I am now
# relying on it. Ditto XIM
      CFLAGS="$CFLAGS "
      CXXFLAGS="$CXXFLAGS "
      export CFLAGS CXXFLAGS
      extras="--with-xft --with-xim"
      ;;
  esac

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
  if test "x$with_fox" != "xno"
  then
    AC_MSG_NOTICE([$SHELL $abssrcdir/csl/fox/configure $ac_configure_args \
            CPPFLAGS="$CPPFLAGS" CFLAGS="$CFLAGS" \
            CXXFLAGS="$CXXFLAGS" LDFLAGS="$LDFLAGS" \
            --enable-release --with-opengl=no \
            --disable-jpeg --disable-zlib --disable-bz2lib \
            --disable-png --disable-tiff --prefix=$builddir $extras])
    eval "$SHELL $abssrcdir/csl/fox/configure $ac_configure_args \
            CPPFLAGS=\"$CPPFLAGS\" CFLAGS=\"$CFLAGS\" \
            CXXFLAGS=\"$CXXFLAGS\" LDFLAGS=\"$LDFLAGS\" \
            --enable-release --with-opengl=no \
            --disable-jpeg --disable-zlib --disable-bz2lib \
            --disable-png --disable-tiff --prefix=$builddir $extras"
    cd $builddir

    if test -d $abssrcdir/csl/foxtests
    then
      AC_MSG_NOTICE([About to configure FOX tests])
      mkdir -p foxtests
      cd foxtests

      AC_MSG_NOTICE([$SHELL $abssrcdir/csl/foxtests/configure $ac_configure_args --with-fox=$builddir --with-fox-pending=yes $extras])
      eval "$SHELL $abssrcdir/csl/foxtests/configure $ac_configure_args --with-fox=$builddir --with-fox-pending=yes $extras"
    fi

    cd $builddir
  fi

fi

###############################################################################


AM_CONDITIONAL(csl, test "x$with_csl" != "xno")
AM_CONDITIONAL(psl, test "x$with_psl" != "xno")
AM_CONDITIONAL(cslpsl, test "x$with_csl" != "xno" && test "x$with_psl" != "xno")
AM_CONDITIONAL(fox, test "x$with_fox" != "xno")

AC_MSG_NOTICE([final output from top level configuration])

AC_OUTPUT

# end of configure.ac


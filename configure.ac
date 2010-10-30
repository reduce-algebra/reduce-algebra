AC_INIT([REDUCE], [20080421], [acn1@cam.ac.uk])

# The next line is a dreadful thing and is in case I am launched
# from a bash prompt, in which case the SHELL variable will be set
# to /bin/bash (or perhaps the user's login shell?). Anyway that hurts
# config.guess on Solaris.... so I will force matters so that I use
# plan vanilla /bin/sh henceforth. So BEWARE and do not use bash extensions.
if test -x /bin/sh
then
  SHELL=/bin/sh
  export SHELL
fi

AC_COPYRIGHT([The REDUCE project])

# I am going to expect that you have at least this version of
# autoconf. In general I will build with  the latest version and
# not really verify that 2.61 is still sufficient.
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
# all the flags that the CSL configuration may ever want. The down-side of
# this is that "configure --help" shows them all.

AC_ARG_WITH(mingw64,
   AC_HELP_STRING([--with-mingw64],
                  [Shorthand to force --host=x86_64-w64-mingw32 (CSL only)]),
   [],
   [with_mingw64="default"])

AC_ARG_WITH(m32,
   AC_HELP_STRING([--with-m32],
                  [Force 32-bit model even on 64-bit gcc (CSL only)]),
   [],
   [with_m32="no"])

AC_ARG_WITH(m64,
   AC_HELP_STRING([--with-m64],
                  [Force 64-bit model even if 32-bit is default (CSL only)]),
   [],
   [with_m64="no"])

AC_ARG_WITH(cygwin,
  AC_HELP_STRING([--with-cygwin],
                 [Force use of raw cywgin (note licensing consequences please) (CSL only)]),
  [],
  [with_cygwin="no"])

AC_ARG_WITH(gui,
  AC_HELP_STRING([--with-gui],
                 [use --without-gui to get a text-only system (CSL only)]),
  [],
  [with_gui="yes"])

# As part of what MAY be a transition I am supporting two possible GUI
# toolkits, viz FOX and wxWidgets. See www.fox-toolkit.org and
# www.wxwidgets.org. If you do not say anything explicit then you will
# get the code built with my default choice and the build will occur in
# un-decorated directory-names. If you explicitly go either "--with-fox"
# or "--with-wx" then you get that GUI toolkit used and the directory will
# be decorated so that this does not interfere with the default. I set the
# default here...
# If you go "--without-fox" or "--without-wx" then that will disable use
# of that toolkit. If the other was selected this will in effect get ignored.
# If the one you say "--without" about is the one that would have been the
# default then you get a system without a GUI at all.

# I reserve the right (one day) to change the default toolkit I use to build
# a GUI, but at the stage I put this in there is a workable one using FOX
# and essentially nothing beyond some configuration steps using wxWidgets!

default_gui="fox"
#default_gui="wx"

AC_ARG_WITH(wx,
  AC_HELP_STRING([--with-wx=DIR],
                 [wxWidgets installation location, or disable use of wxWidgets (CSL only)]),
  [],
  [with_wx="default"])

AC_ARG_WITH(fox,
  AC_HELP_STRING([--with-fox=DIR],
                 [FOX installation location, or disable use of FOX (CSL only)]),
  [],
  [with_fox="default"])

AC_ARG_WITH(fox-pending,
  AC_HELP_STRING([--with-fox-pending],
                 [do not check dir from --with-fox (CSL only)]),
  [],
  [with_fox_pending="no"])

if test "x$with_psl" != "xno"
then
  with_fox=no
  with_fox_pending=no
  with_wx=no
  with_gui=no
fi

AC_ARG_WITH(xft,
  AC_HELP_STRING([--with-xft],
                 [Can be used to disable use of XFT. Default is yes (CSL only)]),
  [],
  [with_xft="yes"])

AC_ARG_WITH(xim,
  AC_HELP_STRING([--with-xim],
                 [Can be used to control use of XIM. Default is yes (now) (CSL only)]),
  [],
  [with_xft="yes"])

AC_ARG_ENABLE(debug,
  AC_HELP_STRING([--enable-debug],
                 [compile for debugging (CSL only)]),
  [],
  [enable_debug="no"])

AC_ARG_ENABLE(conservative,
  AC_HELP_STRING([--enable-conservative],
                 [garbage collect option: not available yet (CSL only)]),
  [],
  [enable_conservative="no"])

AC_ARG_ENABLE(test,
  AC_HELP_STRING([--enable-test],
                 [testing-mode version (CSL only)]),
  [],
  [enable_test="no"])

AC_ARG_ENABLE(jit,
  AC_HELP_STRING([--enable-jit],
                 [build in experimental JIT (CSL only)]),
  [],
  [enable_jit="no"])

AC_ARG_ENABLE(static,
  AC_HELP_STRING([--enable-static],
                 [link it all statically (CSL only)]),
  [],
  [enable_static="no"])

AC_ARG_WITH(smallpage,
  AC_HELP_STRING([--with-smallpage],
                 [Use 256K pages rather than 4M ones (CSL only)]),
  [],
  [with_smallpage="no"])

###########################################################################

# This following is both a shorthand and a fudge to preserve a historical
# way I did things. If you say "--with-mingw64" to this top-level
# configure script it pretends you had asked for cross compilation using
# the standard idiom --host-x86_64-w64-mingw32. Doing things this way here
# means that the lower-level configure scripts just need to understand
# about cross compilation and should not look for --with-mingw64 as such.
# Then "--without-mingw64" explicitly avoids this cross-build. If you do the
# compilation on a 64-bit version of Windows under cygwin and if you have
# the relevent cross compilers installed the default will be to create a
# 64-bit version, except that if you explicitly set --host. This is all
# a bit complicated but I *HOPE* that the behaviour will end up feelin
# natural.
#
# If you try to use --with-ming64 and an explicit setting of the host
# at the same time I will moan!

if test "x$with_mingw64" != "xdefault"
then
  case $ac_configure_args in
  *--host=*)
    AC_MSG_ERROR([You may not use --with-mingw64 or --without-mings64 and --host=$host at the same time])
    ;;
  *)
    ;;
  esac
fi

if test "x$with_csl" != "xno" && test "x$with_cygwin" = "xno"
then
  AC_CHECK_PROG(X64_GCC, x86_64-w64-mingw32-gcc, "yes", "no")
  case $ac_configure_args in
  **--host=*)
    ;;
  *)
    case `uname` in
  *CYGWIN*WOW64*)
      if test "x$with_mingw64" = "xdefault"
      then
        with_mingw64="$X64_GCC"
      fi
      ;;
    esac
    ;;
  esac

  if test "x$with_mingw64" = "xyes"
  then
    host="x86_64-w64-mingw32"
    ac_configure_args="$ac_configure_args --host=$host"
  fi

  if test "x$host" = "xx86_64_w64_mingw32" && test "x$X64_GCC" = "xno"
  then
    AC_MSG_ERROR([Attempt to build Windows-64 system without correct cross ocmpiler installed])
  fi
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

AC_MSG_NOTICE([host=$host args=$ac_configure_args])

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
    doconfig="$SHELL $abssrcdir/configure $ac_configure_args \
            CPPFLAGS=\"$CPPFLAGS\" CFLAGS=\"$CFLAGS\" \
            CXXFLAGS=\"$CXXFLAGS\" LDFLAGS=\"$LDFLAGS\" \
            --with-build=$build"
    AC_MSG_NOTICE([$doconfig])
    eval "$doconfig"
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

# If the user has said nothing then both with_fox and with_wx will be
# "default", and default_gui will be either"fox" or "wx".

# The things the user can reasonably say will be
#    <nothing>         build using default GUI in directory x-y-z
#                      (eg in cslbuild/i386-pc-windows)
#    --without-gui     build non-GUI version in x-y-x-nogui
#    --with-fox        build FOX version in x-y-z-fox
#    --with-wx         build wxWidgets version in x-y-z-wx
#    --with-wx=builtin force use of wxWidgets from source her even if
#                      if a system-wide copy is available.
#    --without-fox     if FOX is the default behave as --without -gui
#    --without-wx      if wxWidgets is the default behave as --without-gui
# If the user says --without-wx when FOX was to be the default GUI then in
# effect this redundant statement is ignored.
# It is not proper to say more than one from --with-fox, --with-wx,
# and --without-gui, but each can be used in separate calls to the
# configure script to build parallel versions.
#
# At the TOP LEVEL there is no point or merit in --with-fox=XXXX for some XXX
# other than "yes" OR "no", and "--with-fox=no" is interpreted as being the
# same as "--without-fox" (etc). I use "--with-fox=default" as the situation
# if the user does not specify "--with-fox" at all.

  if test "x$with_gui" = "xno" && (test "x$with_fox" != "xdefault" || test "x$with_wx" != "xdefault")
  then
    AC_MSG_ERROR([If you say --without-gui you must not say --with-fox or --with-wx as well
(or even --without-fox or --without-wx)])
  fi
  if test "x$with_fox" != "xdefault" && test "x$with_wx" != "xdefault"
  then
    AC_MSG_ERROR([You must not say --with-fox (or --without-fox) and --with-wx
(or --without-wx) at the same time])
  fi

  if test "x$with_gui" = "xno"
  then
    with_fox="no"
    with_wx="no"
  else
    case $default_gui/$with_fox/$with_wx in
    fox/default/default)
# simple default case
      with_fox="yes"
      with_wx="no";
      ;;
    fox/yes/*)
# explicit --with-fox. I allow this even though in this situation it
# is redundant because when wxWidgets becomes the default it will be
# needed if you want a fox build.
      with_fox="yes"
      with_wx="no";
      ;;
    fox/no/*)
# explicit --without-fox. If fox is that default this
# leads to the without-gui situation.
      with_fox="no"
      with_wx="no";
      ;;
    fox/*/yes)
# explicit --with-wx overrides the default
      with_fox="no"
      with_wx="yes";
      ;;
    fox/*/no)
# explicit --without-wx. If fox is the default this will not have any
# effect and since maybe somebody thought it would disable the whole
# GUI I will make it an error
      AC_MSG_ERROR([--with-fox is the default configuration so --without-wx is not needed])
      ;;
    wx/default/default)
# simple default case (if wx is preferred)
      with_fox="no"
      with_wx="yes";
      ;;
    wx/*/yes)
# explicit --with-wx is permitted even when not needed
      with_fox="no"
      with_wx="yes";
      ;;
    wx/yes/*)
# explicit --with-fox that overrides default
      with_fox="yes"
      with_wx="no";
      ;;
    wx/no/*)
# explicit --without-fox
      AC_MSG_ERROR([--with-wx is the default configuration so --without-fox is not needed])
      ;;
    *)
      AC_MSG_ERROR([--with=fox=$with_fox and --with-wx=$with_wx inconsistent here])
      ;;
    esac
  fi

  AC_MSG_NOTICE([with_fox=$with_fox, with_wx=$with_wx])  

  
# Now at most one of with_wx and with_fox will be "yes". They could both
# be "no".
  if test "x$with_wx" != "xno"
  then
# If the user says "--with-wx=builtin" then I will use the version of
# wxWidgets included with with the Reduce archive even if there is a
# (possibly different) version of wxWidgets available system-wide.
    if test "x$with_wx" != "xbuiltin"
    then
      AC_PATH_PROGS(WX_CONFIG, wx-config, [no],
         [$PATH:/usr/local/bin/usr/sfw/bin:/usr/csw/bin])
      AC_MSG_NOTICE([WX_CONFIG=$WX_CONFIG])
      if test "x$WX_CONFIG" != "xno" && test "x$cross_compiling" != "xyes"
      then
        wxver=`$WX_CONFIG --version`
        case $wxver in
      1.* | 2.0.* | 2.1.* | 2.2.* | 2.3.* | 2.4.* | 2.5.* | 2.6.* | 2.7.* | 2.8.* | 2.9.0)
          AC_MSG_NOTICE([System version of wxWidgets too old - will use built in copy])
          with_wx=builtin
          ;;
      2.9.*)
# I will only accept a system version if it is 2.9.1 or up. When  at some time
# in the distant future a 2.10 series is released I will need to review this
# but the fall-back will be to use a copy that I ship along with my code. So
# being fussy here is not terribly damaging.
          AC_MSG_NOTICE([Found wxWidgets $wxver and will use that])
          ;;
      *)
          AC_MSG_NOTICE([System version of wxWidgets $wxver not recognised - will use built in copy])
          with_wx=builtin
          ;;
        esac
      else
        with_wx=builtin
      fi
    fi
    AC_MSG_NOTICE([after checking for system wxWidgets with_wx=$with_wx])
    if test "x$with_wx" = "xbuiltin" && ! test -d $abssrcdir/csl/wxWidgets
    then
      d=`pwd`
      cd $abssrcdir/csl/support-packages
      a=`echo wxWidgets-v*.tar.bz2`
      a=${a##* }
      b=${a%.tar.bz2}
      cd ..
      rm -rf wxWidgets
      tar xfj support-packages/$a
      chmod -R +rw wxWidgets-*
      mv wxWidgets-* wxWidgets
      echo wxWidgets unpacked from archive $a
      cd $d
    fi
    if test "x$with_wx" = "xbuiltin"
    then
      doconfig="$SHELL $abssrcdir/csl/cslbase/configure $ac_configure_args --with-wx=$builddir --with-wx-pending=yes --with-build=$build --without-fox"
    else
      doconfig="echo \"System provided version of wxxWidgets will be used\""
    fi
    AC_MSG_NOTICE([config for wx = $doconfig])
  elif test "x$with_fox" != "xno"
  then
    doconfig="$SHELL $abssrcdir/csl/cslbase/configure $ac_configure_args --with-fox=$builddir --with-fox-pending=yes --with-build=$build --without-wx"
  else
# This final version will be without any GUI.
    doconfig="$SHELL $abssrcdir/csl/cslbase/configure $ac_configure_args --with-build=$build --without-fox --without-wx"
  fi
  AC_MSG_NOTICE([$doconfig])
  eval "$doconfig"
  cd $builddir

  if test "x$with_wx" = "xbuiltin"
  then
    AC_MSG_NOTICE([About to configure wxWidgets])
    mkdir -p wxWidgets
  elif test "x$with_fox" != "xno"
  then
    AC_MSG_NOTICE([About to configure FOX])
    mkdir -p fox/src

    # The Makefile that comes with FOX seems to require these GIF files
    # in the build directory.
    cp $abssrcdir/csl/fox/src/*.gif fox/src
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
        AC_MSG_NOTICE([GCC option "-mno-cygwin" being used.])
        CPPFLAGS="$CPPFLAGS -mno-cygwin"
        CFLAGS="$CFLAGS -mno-cygwin"
        CXXFLAGS="$CXXFLAGS -mno-cygwin"
        LDFLAGS="$LDFLAGS -mno-cygwin -mwindows"
      else
        AC_MSG_NOTICE([Using raw cygwin])
        CFLAGS="$CFLAGS "
        CXXFLAGS="$CXXFLAGS "
        extras="--with-xft --with-xim"
      fi
      ;;
    *Darwin*)
      CFLAGS="$CFLAGS "
      CXXFLAGS="$CXXFLAGS "
      extras="--with-xft --with-xim"
# Note I do not even try to build wxWidgets with an SDK other than 10.6
# because that is the first one that provides reasonably full support for
# 64-bit systems.
      wx="--with-cocoa --enable-universal_binary --with-macosx-sdk=/Developer/SDKs/MacOSX10.6.sdk"
      ;;
    *)
# On most non-windowed platforms Xft is a very good idea! And I am now
# relying on it. Ditto XIM
      CFLAGS="$CFLAGS "
      CXXFLAGS="$CXXFLAGS "
      extras="--with-xft --with-xim"
      ;;
  esac

  if test "x$with_m32" != "xno"
  then
    CFLAGS="$CFLAGS -m32"
    CXXFLAGS="$CXXFLAGS -m32"
    LDFLAGS="$LDFLAGS -m32"
    extras="$extras --x-libraries=/usr/X11R6/lib"
  fi

  if test "x$with_m64" != "xno"
  then
    CFLAGS="$CFLAGS -m64"
    CXXFLAGS="$CXXFLAGS -m64"
    LDFLAGS="$LDFLAGS -m64"
    extras="$extras --x-libraries=/usr/X11R6/lib64"
  fi

  AC_MSG_NOTICE([CPPFLAGS=$CPPFLAGS])
  AC_MSG_NOTICE([CFLAGS=$CFLAGS])
  AC_MSG_NOTICE([CXXFLAGS=$CXXFLAGS])
  AC_MSG_NOTICE([LDFLAGS=$LDFLAGS])

  if test "x$with_wx" != "xno"
  then
    if test "x$with_wx" = "xbuiltin"
    then
      cd wxWidgets
      doconfig="$SHELL $abssrcdir/csl/wxWidgets/configure $wx \
              CPPFLAGS=\"$CPPFLAGS\" CFLAGS=\"$CFLAGS\" \
              CXXFLAGS=\"$CXXFLAGS\" LDFLAGS=\"$LDFLAGS\" \
              --disable-shared --enable-unicode \
              --disable-compat26 --disable-compat28 \
              --with-png=builtin --without-libjpeg \
              --without-libtiff --with-libsvg=no \
              --with-sdl=no --with-zlib=builtin \
              --without-expat --with-regex=builtin \
              --disable-gif --disable-pcx \
              --disable-tga --disable-pnm \
              --disable-svg --prefix=$builddir"
      AC_MSG_NOTICE([$doconfig])
      eval "$doconfig"
      cd $builddir
    fi
  elif test "x$with_fox" != "xno"
  then
    cd fox
    doconfig="$SHELL $abssrcdir/csl/fox/configure $ac_configure_args \
            CPPFLAGS=\"$CPPFLAGS\" CFLAGS=\"$CFLAGS\" \
            CXXFLAGS=\"$CXXFLAGS\" LDFLAGS=\"$LDFLAGS\" \
            --enable-release --with-opengl=no \
            --disable-jpeg --disable-zlib --disable-bz2lib \
            --disable-png --disable-tiff --prefix=$builddir $extras"
    AC_MSG_NOTICE([$doconfig])
    eval "$doconfig"
    cd $builddir

    if test -d $abssrcdir/csl/foxtests
    then
      AC_MSG_NOTICE([About to configure FOX tests])
      mkdir -p foxtests
      cd foxtests

      doconfig="$SHELL $abssrcdir/csl/foxtests/configure $ac_configure_args \
            CPPFLAGS=\"$CPPFLAGS\" CFLAGS=\"$CFLAGS\" \
            CXXFLAGS=\"$CXXFLAGS\" LDFLAGS=\"$LDFLAGS\" \
            --with-fox=$builddir --with-fox-pending=yes $extras"
      AC_MSG_NOTICE([$doconfig])
      eval "$doconfig"
    fi

    cd $builddir
  fi

fi

###############################################################################


AM_CONDITIONAL(csl, test "x$with_csl" != "xno")
AM_CONDITIONAL(psl, test "x$with_psl" != "xno")
AM_CONDITIONAL(cslpsl, test "x$with_csl" != "xno" && test "x$with_psl" != "xno")
AM_CONDITIONAL(fox, test "x$with_fox" != "xno")
AM_CONDITIONAL(wx,  test "x$with_wx" != "xno")
AM_CONDITIONAL(wxbuiltin,  test "x$with_wx" = "xbuiltin")

AC_MSG_NOTICE([final output from top level configuration])

AC_OUTPUT

# end of configure.ac


AC_INIT([REDUCE], [20101217], [acn1@cam.ac.uk])

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

# I have tested this on Fedora Core 1 and 2 with the versions of automake
# and autoconf that each had at that stage back in 2003. FC1 with
# autoconf 2.57 and automake 1.7.8 failed to establish configuration
# because several features of automake that I use are newer than that
# (eg -Wno-portability, no-dist-gzip) but even when I removed them
# it behaved badly for me. However FC2 with autoconf 2.59 and automake
# 1.8.3 gave me MANY warning messages (eg about underquoted arguments in the
# m4 scripts) but allowed me to continue. So I set that level as my
# baseline and ask everybody to install software newer that late 2003.
#
# If necessary they can fetch source versions of autoconf and automake and
# install private versions for use here.

# HOWEVER since the subversion repository for Reduce contains ready build
# configuration files there should only even be an attempt to rerun
# autoconf etc if time-stamps get out of order. There is a script
# .../trunk/scripts/stamp.sh that should restore them. So any user who only
# has ancient versions of autoconf and automake available is advised to run
# scripts/stamp.sh after each time they go "svn update".

AC_PREREQ(2.59)

abssrcdir=`"$srcdir/scripts/here.sh"`

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

AC_ARG_WITH(pslbuild,
  AC_HELP_STRING([--with-pslbuild], [Used internally to control build directory]),
  [],
  [with_pslbuild="unknown"])

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
                  [Use "with" or "without" to force windows-64 build status (CSL only)]),
   [],
   [with_mingw64="default"])

AC_ARG_WITH(lionSDK,
   AC_HELP_STRING([--without-lionSDK],
                  [can be used to avoid use of MacOSX SDK 10.7 (CSL ONLY)]),
   [],
   [with_lionSDK="yes"])

AC_ARG_WITH(lto,
   AC_HELP_STRING([--with-lto],
                  [Experiment with extreme optimisation in gcc (CSL only)]),
   [],
   [with_lto="no"])

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
                 [Force use of raw cygwin (note licensing consequences please) (CSL only)]),
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
  [with_xim="yes"])

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

# I have a state of complication on Windows as regards 32 and 64-bit
# windows builds. In each case I will often be doing the build hosted in
# a cygwin environment on Windows. To create a native Windows style
# executable (as distinct from somethin that links via the cygwin dll to
# provide a posix-like world) I want to use the mingw version of the
# compilers. But they might not even be installed! And the proper and
# modern way to do the build will be to treat it as a cross-compilation so
# that the various build-tools used are found with a host prefix - eg
# "x86_64-w64-mingw32-g++". Sometimes I will wish to build a set of 32-bit
# executables even if my computer happens to be running a 64-bit version of
# windows, and sometimes I might want to build 64-bit executables even though
# I am only in a 32-bit world.
#
# The behaviour I intend to establish is that the user can find-tune things
# using the option "--with-mingw64":
#    --with-mingw64 or --with-mingw64=yes:
#         Treat very much as "--host=x86_64-w64-mingw32" and hence build
#         64 bit executables. If the necessary cross-compile is not
#         installed then this configuration will (obviously) fail.
#    --without-mingw64 or --with-mingw64=no:
#         If the relevent cross compiler is present treat very much
#         as "--host=i686-w64-mingw32" and hence build 32-bit native
#         windows exectuables. If that cross compiler is not available
#         then you are liable to FAIL.
#    --with-mingw64=default or no explicit mention about this:
#         A 32-bit version will always be built. If x86_64-w64-mingw32-g++
#         is installed and the version of Windows being used is 64-bit
#         then a 64-bit version will be built too. So note that if you are
#         using 64-bit windows you will often get TWO versions built for
#         you (because the 32-bit one may be useful for passing to friends),
#         while if you are on a 32-bit system you will need to go
#         "--with-mingw64" explicitly to build 64-bit executables. 
#
# Note that on Windows under cygwin i686-w64-mingw32 and/or x86_64-w64-mingw32
# compilers MUST be installed.
#
# When testing for build environents I will look to see if <host>-g++ is
# available, and if it is I will assume the <host>-gcc and any other
# relevant build tools and libraries will be installed. This is just to
# simplify the tests here!
#
# I will tend to implement all this by causing the script to re-launch itself
# in certain cases. I will NOT re-launch if "--host" has been set explicitly
# or if "CC", "CXX" or associated flags have been provided explicitly.

considermingw="yes"
if test "x$with_csl" = "xno" || test "x$with_cygwin" != "xno"
then
  considermingw="no"
fi

case $ac_configure_args in
*--host=* | *CC=* | *CXX=* | *CFLAGS=* | *CXXFLAGS=*)
# The above items in ac_configure_args either indicate me having already
# made my adjustments or they show the use explicitly setting options that
# I perhaps ought to respect.
  considermingw="no"
  explicitcc="yes"
  ;;
*CFLAGS=* | *CXXFLAGS=*)
  considermingw="no"
  ;;
esac

case `uname` in
*CYGWIN*WOW64*)
  wow64="yes"
  ;;
*CYGWIN* | *cygwin* | *mingw*)
  wow64="no"
  ;;
*)
# If I am not building on a cygwin machine I should not mess around with
# windows-specific activity.
  considermingw="no"
esac

if test "x$considermingw" != "xno"
then
# check for the availability of compilers that might matter to me.
  AC_CHECK_PROG(X64_GCC, x86_64-w64-mingw32-g++, "yes", "no")
  AC_CHECK_PROG(X32_GCC, i686-w64-mingw32-g++, "yes", "no")
  if test "x$with_mingw64" = "xyes"
  then
    if test "x$X64_GCC" = "xno"
    then
      AC_MSG_ERROR([Attempt to build Windows-64 system without correct cross ocmpiler installed])
    fi
    doconfig="$SHELL \"$abssrcdir/configure\" $ac_configure_args \
             --host=x86_64-w64-mingw32"
    AC_MSG_NOTICE([$doconfig])
    eval "$doconfig"
    exit
  elif test "x$with_mingw64" = "xno" || \
       test "x$wow64" = "xno" || \
       test "x$X64_GCC" = "xno"
  then
# Here I either explicitly want to build a 32-bit version, or I am on
# a 32-bit windows and did not explicitly ask for a 64-bit version. I
# build for 32-bits. There are several possible ways to do that and I
# will look at them here in order of preference. I do this even if I am on
# a 64-bit Windows if the 64-bit compilers are not available.
#
    if test "$X32_GCC" = "yes"
    then
# Use cross-compilation using i686-w64-mingw32-g++ etc.
      doconfig="$SHELL \"$abssrcdir/configure\" $ac_configure_args \
               --host=i686-w64-mingw32"
      AC_MSG_NOTICE([$doconfig])
      eval "$doconfig"
      exit
    else
      AC_MSG_ERROR([Under cygwin please install i686-w64-mingw compilers.])
      exit
    fi
  else
# This final case is when I have not said anything explicit about with or
# without mingw64 but I am running on a 64-bit windows and have the 64-bit
# compilers installed. In this case I will try to configure both versions.
    doconfig="$SHELL \"$abssrcdir/configure\" $ac_configure_args \
             --with-mingw64=no"
    AC_MSG_NOTICE([$doconfig])
    eval "$doconfig"
    doconfig="$SHELL \"$abssrcdir/configure\" $ac_configure_args \
             --with-mingw64=yes"
    AC_MSG_NOTICE([$doconfig])
    eval "$doconfig"
    exit
  fi
fi

# Now I want to know if the current directory is the same as $srcdir. At
# one stage I checked that by looking to see if $srcdir was ".". That was OK
# for direct calls of the form "./configure" where the "." as in "./" was
# detected. But the reconfig step messes that up and anyway it is a delicate
# cheat. So here is a different delicate cheat!

rm -f ./testfile.tst "$srcdir/testfile.tst"
touch "$srcdir/testfile.tst"
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

# One HORRID issue is that as regards anything that is to do with selecting
# directories to build in etc I want to look at $host as produced by
# just one version of config.guess. This is because in the past I have
# come across cases where different versions or releases of config.guess
# report the same machine with slightly different names. That could cause
# messy confusion! So when I want that information I find it once here and
# as necessary pass it down to lower parts of the tree.

AC_MSG_NOTICE([host=$host args=$ac_configure_args])

pslbuild=`eval "$SHELL \"$srcdir/scripts/findhost.sh\" $host"`

if test "x$with_psl" != "xno"
then
  build="$pslbuild"
else
  build=`eval "$SHELL \"$srcdir/scripts/findhost.sh\" $host $ac_configure_args"`
fi

#####################@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
# The following two lines are outrageous hacks so that I can see if what
# follows is robust against file-names with parens and whitespace. At present
# it appears that I can build the FOX-based version with these active, but not
# build wxWidgets (unless and until I hack wxWidgets!).
#pslbuild="$pslbuild(for psl)"
#build="$build(for csl)"
#####################@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


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
    if ! test -d "$abssrcdir/cslbuild/$build"
    then
      mkdir -p "$abssrcdir/cslbuild/$build"
    fi
# When I configure I will install a default "profile.dat" if there is
# not one in place already, but the user can always regenerate a newer
# local version of the profile.
    if ! test -d "$abssrcdir/cslbuild/generated-c" ||
       ! test -f "$abssrcdir/cslbuild/generated-c/profile.dat"
    then
      rm -rf "$abssrcdir/cslbuild/generated-c"
      mkdir -p "$abssrcdir/cslbuild/generated-c"
      cp -r "$abssrcdir/csl/generated-c" "$abssrcdir/cslbuild"
    fi
    cd "$abssrcdir/cslbuild/$build"
    if test "x$CC$CPP$CXX$CXXCPP" != "x"
    then
      passcc="CC=\"$CC\" CPP=\"$CPP\" CXX=\"$CXX\" CXXCPP=\"$CXXCPP\""
    fi
    AC_MSG_NOTICE([passcc = $passcc])
    pass_build="--with-build=\"$build\" --with-pslbuild=\"$pslbuild\""
    doconfig="$SHELL \"$abssrcdir/configure\" $ac_configure_args \
            CPPFLAGS=\"$CPPFLAGS\" CFLAGS=\"$CFLAGS\" \
            CXXFLAGS=\"$CXXFLAGS\" LDFLAGS=\"$LDFLAGS\" LIBS=\"$LIBS\" \
            $passcc $pass_build"
    AC_MSG_NOTICE([doconfig = $doconfig])
    eval "$doconfig"
    cd "$abssrcdir"
  fi
  if test "x$with_psl" != "xno"
  then
    AC_MSG_NOTICE([+++ Will build in $abssrcdir/pslbuild/$build])
    if ! test -d "$abssrcdir/pslbuild/$build"
    then
      mkdir -p "$abssrcdir/pslbuild/$build"
    fi
    cd "$abssrcdir/pslbuild/$build"
# This passes down any configure arguments to the PSL-specific configuration
# but at present I do not expect any to be relevant.
    pass_build="--with-build=\"$build\""
    eval "$SHELL \"$abssrcdir/psl/configure\" $ac_configure_args $pass_build"
    cd "$abssrcdir"
  fi
  exit 0
  ;;
  *)
  AC_MSG_NOTICE([+++ standard build case, srcdir = $srcdir = "$abssrcdir"])
  ;;
esac

# This is where the main bit of this script starts.

AC_CONFIG_SRCDIR(scripts/make.sh)

AM_INIT_AUTOMAKE([1.8.3 -Wall -Werror -Wno-portability foreign no-dist-gzip dist-bzip2])

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
    fox/*/builtin)
# explicit --with-wx=builtin overrides the default
      with_fox="no"
      with_wx="builtin";
      ;;
    fox/*/no)
# explicit --without-wx. If fox is the default this will not have any
# effect and since maybe somebody thought it would disable the whole
# GUI I will make it an error.
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
    wx/*/builtin)
# explicit --with-wx=builtin is permitted even when not needed
      with_fox="no"
      with_wx="builtin";
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
      AC_MSG_ERROR([--with-fox=$with_fox and --with-wx=$with_wx inconsistent here])
      ;;
    esac
  fi

  AC_MSG_NOTICE([with_fox=$with_fox, with_wx=$with_wx])  

# If I am compiling for native Cygwin I will not pass down "--host".
  if test "x$with_cygwin" != "xno"
  then
    sethost=""
  else
    sethost="--host=$host"
  fi

  AC_MSG_NOTICE([with_cygwin=$with_cygwin sethost=$sethost])

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
# A short essay to explain why I pass down "--host=$host" here. There are
# two points. The first is that I cope with 64-bit windows by use of
# cross-compilation using the x86_64-win32-mingw32 toolchain. To try to
# be helpful I use this if I am running on 64-bit windows even though
# cygwin and config.guess view the main architecture as i686-pc-windows.
# This involves overriding "host", and I want to pass that decision down.
# The second reason is that different releases of "config.guess" can report
# machine identities differently. I have particularly observes this on
# openSuSE Linux where some versions brand the host triple with "-suse-" in
# the middle. I do not mind much just what triple is used, but I do mind
# very much it it is not consistent all the way through my build. So I
# let this top-level configure script make the choice and by explicitly
# propagating if to sub-packages I end up safer.
# However if I am building for raw cygwin I find that I have pain if I
# specify --host specifically, so in that case I will not!
    pass_build="--with-build=\"$build\""
    doconfig="$SHELL \"$abssrcdir/csl/cslbase/configure\" $ac_configure_args $sethost --with-wx=\"$with_wx\" $pass_build --without-fox"
  elif test "x$with_fox" != "xno"
  then
    pass_build="--with-build=\"$build\""
    doconfig="$SHELL \"$abssrcdir/csl/cslbase/configure\" $ac_configure_args $sethost --with-fox=\"$builddir\" --with-fox-pending=yes $pass_build --without-wx"
  else
# This final version will be without any GUI.
    pass_build="--with-build=\"$build\""
    doconfig="$SHELL \"$abssrcdir/csl/cslbase/configure\" $ac_configure_args $sethost $pass_build --without-fox --without-wx"
  fi
  AC_MSG_NOTICE([$doconfig])
  eval "$doconfig"
  cd "$builddir"

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
    cp "$abssrcdir/csl/fox/src/"*.gif fox/src
  fi

  extras=
  wx=

  case $host in
    *cygwin*)
      if test "x$with_cygwin" != "xyes"
      then
        AC_MSG_NOTICE([gcc will be used in mingw mode.])
      else
        AC_MSG_NOTICE([Using raw cygwin])
        CFLAGS="$CFLAGS -I/usr/include/ncurses "
        CXXFLAGS="$CXXFLAGS -I/usr/include/ncurses "
        extras="--with-xft --with-xim"
      fi
      ;;
    *Darwin* | *darwin*)
# Note I do not even try to build wxWidgets with an SDK older than 10.6
# because that is the first one that provides reasonably full support for
# 64-bit systems. So binaries that I build will not be suitable for anything
# prior to Snow Leopard. I will now build JUST for x86_64 because there
# are not liable to be Intel Macs that do not support 64-bit mode, and ppc
# can now be viewed as obsolete.
# As of mid July 2011 when Lion (10.7) has just been released wxWidgets does
# not survive the 10.7 SDK, so I support a "--without-lionSDK" configuration
# option to drop back...
      if test -d /Developer/SDKs/MacOSX10.7.sdk && test "x$with_lionSDK" != "xno"
      then
        CFLAGS="$CFLAGS -msse2"
        CXXFLAGS="$CXXFLAGS -msse2"
        SDK=/Developer/SDKs/MacOSX10.7.sdk
        MACARCH="--enable-macos_arch=x86_64" 
      else
        SDK=/Developer/SDKs/MacOSX10.6.sdk
#       MACARCH="--enable-univeral_binaries" 
        MACARCH="--enable-macos_arch=x86_64" 
      fi
      extras="--with-xft --with-xim"
      wx="--with-cocoa \
          --with-macosx-sdk=$SDK \
          --with-macosx-version-min=10.6 \
          $MACARCH "
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

  if test "x$with_wx" != "xno"
  then
    if test "x$with_wx" = "xbuiltin"
    then
      cd wxWidgets
# I need --enable-unicode on Windows at least so that I can use the
# BaKoMa fonts which remap at least one TeX glyph to outside the range
# of simple 8-bit characters. This will bring some follow-on pain no doubt
# but addressing that pain is probably good in the long term. 
      if test "x$CC$CPP$CXX$CXXCPP" != "x"
      then
        passcc="CC=\"$CC\" CPP=\"$CPP\" CXX=\"$CXX\" CXXCPP=\"$CXXCPP\""
      fi
      AC_MSG_NOTICE([passcc = $passcc])
      doconfig="$SHELL \"$abssrcdir/csl/wxWidgets/configure\" $wx \
              $sethost CPPFLAGS=\"$CPPFLAGS\" CFLAGS=\"$CFLAGS\" \
              CXXFLAGS=\"$CXXFLAGS\" LDFLAGS=\"$LDFLAGS\" $passcc \
              --disable-shared --enable-unicode \
              --disable-compat26 --disable-compat28 \
              --with-png=builtin --without-libjpeg \
              --without-libtiff --with-libsvg=no \
              --with-sdl=no --with-zlib=builtin \
              --without-expat --with-regex=builtin \
              --disable-gif --disable-pcx --enable-graphics_ctx \
              --disable-tga --disable-pnm \
              --disable-svg --prefix=\"$builddir\""
      if test "x$enable_debug" != "xno"
      then
        doconfig="$doconfig --enable-debug"
      fi
      AC_MSG_NOTICE([doconfig = $doconfig])
      eval "$doconfig"
      cd "$builddir"
    fi
  elif test "x$with_fox" != "xno"
  then
    cd fox
    if test "x$CC$CPP$CXX$CXXCPP" != "x"
    then
      passcc="CC=\"$CC\" CPP=\"$CPP\" CXX=\"$CXX\" CXXCPP=\"$CXXCPP\""
    fi
    AC_MSG_NOTICE([passcc = $passcc])
    doconfig="$SHELL \"$abssrcdir/csl/fox/configure\" $ac_configure_args \
            CPPFLAGS=\"$CPPFLAGS\" CFLAGS=\"$CFLAGS\" \
            CXXFLAGS=\"$CXXFLAGS\" LDFLAGS=\"$LDFLAGS\" $passcc \
            $sethost --enable-release --with-opengl=no \
            --disable-jpeg --disable-zlib --disable-bz2lib \
            --disable-png --disable-tiff --prefix=\"$builddir\" $extras"
    AC_MSG_NOTICE([doconfig = $doconfig])
    eval "$doconfig"
    cd "$builddir"

    if test -d "$abssrcdir/csl/foxtests"
    then
      AC_MSG_NOTICE([About to configure FOX tests])
      mkdir -p foxtests
      cd foxtests

      if test "x$CC$CPP$CXX$CXXCPP" != "x"
      then
        passcc="CC=\"$CC\" CPP=\"$CPP\" CXX=\"$CXX\" CXXCPP=\"$CXXCPP\""
      fi
      AC_MSG_NOTICE([passcc = $passcc])
      doconfig="$SHELL \"$abssrcdir/csl/foxtests/configure\" $ac_configure_args \
            $sethost CPPFLAGS=\"$CPPFLAGS\" CFLAGS=\"$CFLAGS\" \
            CXXFLAGS=\"$CXXFLAGS\" LDFLAGS=\"$LDFLAGS\" $passcc \
            --with-fox=\"$builddir\" --with-fox-pending=yes $extras"
      AC_MSG_NOTICE([doconfig = $doconfig])
      eval "$doconfig"
    fi

    cd "$builddir"
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


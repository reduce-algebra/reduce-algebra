AC_INIT([REDUCE], [from SourceForge], [acn1@cam.ac.uk])

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

# $Id$

# If necessary you can fetch source versions of autoconf and automake and
# install private versions for use here. Following discussions with other
# developers I am now going to require autoconf, automake and libtool
# availability, although an enthusiastic person could probably get things
# working without them.

AC_PREREQ(2.61)
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_MACRO_DIRS([m4])

abssrcdir=`"$srcdir/scripts/here.sh"`

AC_MSG_NOTICE([Absolute path to source directory = $abssrcdir])

#
# There is a horror here. If one fetches everything from subversion
# then timstamps can be ill-ordered, and it can seem necessary to
# re-create the autoconf-related files. The standard way that autoconf and
# automake allow for this is not very generous if the version of autoconf
# on the local machine does not match the one used in the files from the
# central site.
#
# I am now going to try to respond to that by forcing a re-generation of
# all the autoconf files each time anybody runs configure. That adds to the
# cost for everybody and means that everybody NEEDS autoconf, automake and
# libtool installed, but may be more robust. I will check the versions of
# autoconf and automake that are present and stop if they are too old.
# If that case hits you you may need to fetch new versions (in source form)
# and build and install them somewhere on your PATH. This is in fact not
# too difficult, it is along the lines of
#   <fetch source archive from the Free Software Foundation archives>
#   # (please use a local mirror)
#   tar xvfz <source-archive.tgz>
#   cd <where it unpacked to>
#   ./configure --prefix=/usr/local/bin
#   make
#   sudo make install
# and if you do not have authority to write files to /usr/local/bin then
# set up a directory of your own, put it early in your PATH and use that as
# the "--prefix".

AC_ARG_WITH(autogen,
  AC_HELP_STRING([--with-autogen], [Regenerate autoconf file at start]),
  [],
  [with_autogen="yes"])

if test "x$with_autogen" = "xyes"
then

  if ! which autoconf > /dev/null 2> /dev/null
  then
    wait $procids
    printf "You must have autoconf (at least version 2.61) installed to\n"
    printf "build this package. Install it and try again please.\n"
    exit 1
  fi

  if ! which automake > /dev/null 2> /dev/null
  then
    wait $procids
    printf "You must have automake (at least version 1.13) installed to\n"
    printf "build this package. Install it and try again please.\n"
    exit 1
  fi

  if ! which libtool > /dev/null 2> /dev/null
  then
    wait $procids
    printf "You must have libtool installed to build this package. Install\n"
    printf "it and try again please.\n"
    printf "Note on some Linux systems it is in a package called libtool-bin\n"
    exit 1
  fi

# The next fragment should extract version numbers for autoconf and automake

# I extract version info from the two utilities. The first line of
# the output from "autoxx --version" is "autoxx ...  nn.nn.nn" with
# a two or three component version number at the end.

  acver=`autoconf --version 2> /dev/null | head -1`
  amver=`automake --version 2> /dev/null | head -1`

# Get rid of everything as far as the final blank in the data. What is
# left is just the version number, whihc may be two or three components,
# such as 14.2.1 or 15.0

  acver=`echo $acver | sed -e 's/.* //'`
  amver=`echo $amver | sed -e 's/.* //'`

# The major version number is got by stripping of everything from the "." on.

  acmaj=`echo $acver | sed -e 's/\..*//'`
  ammaj=`echo $amver | sed -e 's/\..*//'`

# The minor version number is left if one deleted the major number.

  acver=`echo $acver | sed -e "s/$acmaj\.//"`
  amver=`echo $amver | sed -e "s/$ammaj\.//"`

# What was left could have a patch level - get rid of it.

  acmin=`echo $acver | sed -e 's/\..*//'`
  ammin=`echo $amver | sed -e 's/\..*//'`

  AC_MSG_NOTICE([detected autoconf: $acmaj.$acmin automake: $ammaj.$ammin])

  if test $acmaj -lt 2 || test $acmaj -eq 2 && test $acmin -lt 61
  then
    wait $procids
    printf "You have autoconf $acmaj.$acmin but at least 2.61 is needed\n"
    printf "to build this package. Install it and try again please.\n"
    exit 1
  fi

  if test $ammaj -lt 1 || test $ammaj -eq 1 && test $ammin -lt 13
  then
    wait $procids
    printf "You have automake $ammaj.$ammin but at least 1.13 is needed\n"
    printf "to build this package. Install it and try again please.\n"
    exit 1
  fi

  here=`pwd`
  cd $abssrcdir
  printf "Regenerate autoconf-related files\n"
  if ! eval $SHELL -c \"./autogen.sh $ac_configure_args\"
  then
    wait $procids
    printf "The autogen.sh script seems to have failed. I can not continue\n"
    exit 1
  fi
  cd $here

# It is unexpectedly important the the "--without-autogen" be provided as
# the first argument in the re-try. This is because otherwise some malformed
# input later on (eg "--") could cause it not to be recognised, leading
# to an infinite cycle of attempted re-generation!
  printf "Restart: $abssrcdir/configure --without-autogen $ac_configure_args\n"
# Because this uses "exec" it chains into the restarted processing and does
# not proceed further in this shell.
  exec $SHELL -c "$abssrcdir/configure --without-autogen $ac_configure_args"
fi

# Next and before I do anything much else I will see if any GUI toolkit that
# I am using needs to be unpacked from source. Well before I do that I need
# to sort out whether I am using CSL or PSL and in the former case whether
# I am using the FOX or wxWidgets toolkit.

AC_ARG_WITH(csl,
  AC_HELP_STRING([--with-csl], [Use the CSL Lisp system]),
  [],
  [with_csl="no"])

AC_ARG_WITH(psl,
  AC_HELP_STRING([--with-psl], [Use the PSL Lisp system]),
  [],
  [with_psl="no"])

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

if test "x$with_csl" != "xno"
then
# This is where I unpack a new copy of  wxWidgets if I need to.

# If the user has said nothing then both with_fox and with_wx will be
# "default", and default_gui will be either"fox" or "wx".

# The things the user can reasonably say will be
#    <nothing>         build using default GUI in directory x-y-z
#                      (eg in cslbuild/i386-pc-windows)
#    --without-gui     build non-GUI version in x-y-x-nogui
#    --with-fox        build FOX version in x-y-z-fox
#    --with-wx         build wxWidgets version in x-y-z-wx
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

# Now at most one of with_wx and with_fox will be "yes". They could both
# be "no".
  if test "x$with_wx" != "xno"
  then
    d=`pwd`
    cd $abssrcdir/csl/support-packages
# The next line should collect the names of all versions of wxWidgets that
# I have .tar.bz2 files for, and they should end up in alphabetic order.
    a=`echo wxWidgets-*-*-*.tar.bz2`
# Here I keep the last item in the list, which should be the latest version
# present.
    a=${a##* }
# Remove the ".tar.bz2" suffix
    b=${a%.tar.bz2}
    cd ..
# Now I need to check if the version of wxWidgets I have already got
# in an unpacked state matches the most recent one available. Well I look at
# date-stamps - has the unpacked copy of wxWidgets got a newer date-stamp than
# the archived one?
    if test $abssrcdir/csl/support-packages/wxWidgets_revision -nt \
            wxWidgets/wxWidgets_revision
    then
      printf "will unpack a fresh copy of wxWidgets\n"
      mkdir wxWidgets-new
      cp $abssrcdir/csl/support-packages/wxWidgets_revision wxWidgets-new
      mv wxWidgets-new wxWidgets
# At present my wxWidgets archive is packed as for a directory named
# just "wxWidgets", but I will allow for any future change where the
# directory mentioned in the tar archive has a version number included.
      tar xfj support-packages/$a -C wxWidgets --strip-components=1
# At one stage I had trouble with the unpacked archive not being all
# readable, so here I forcibly reset permssions
      chmod -R +rw wxWidgets
# The official distribution needs its autogen.sh script run to create
# a configure file.
      cd wxWidgets
      ./autogen.sh
      cd ..
      printf "wxWidgets unpacked from archive $a\n"
    fi
    cd $d
  fi
fi

# On Windows there could potentially be 4 (or in some sense 6!) variants
# of Reduce made:
#   cygwin 32-bit
#   cygwin 64-bit
#   native windows 32-bit console mode
#   native windows 32-bit windows mode
#   native windows 64-bit console mode
#   native windows 64-bit windows mode
#
# If you are trying to build Reduce and are running only a 32-bit
# operating system you will not be able to build the 64-bit cygwin version
# and the 64-bit native windows version may be somewhat irrelevant to you.
# If you are on a 64-bit operating system using 64-bit cygwin you may not be
# interested in backwards compatibility and thus the 32-bit versions. If
# you only want to run console mode versions under cygwin then the native
# windows versions will be superfluous. To cope with these variations
# I provide flags to enable each version individually. These are of the
# form --with-w32, --with-w64, --with-c32 and --with-c64. The intent will
# be that if you have a a 32-bit operating system only w32 and c32 will be
# enabled by default. At present on a 64-bit operating system where both
# versions of cygwin are installed all 4 versions will be enabled, but at some
# stage in the future I expect to change that so that the 32-bit versions are
# only built if explicitly requested.
# Regardless of host and operating system I will want the i686-w64-mingw32
# toolchain installed, since that produces binaries that come closest to
# being able to run everywhere. Specifically I will want that toolchain
# installed even if you specify --without-w32.

with_w32="yes"
with_w64="yes"
with_c32="yes"
with_c64="yes"

AC_ARG_WITH(w32,
  AC_HELP_STRING([--with-w32], [Build 32-bit Windows version]),
  []
  [with_w32="yes"])

AC_ARG_WITH(w64,
  AC_HELP_STRING([--with-w64], [Build 64-bit Windows version]),
  []
  [with_w64="yes"])

AC_ARG_WITH(c32,
  AC_HELP_STRING([--with-c32], [Build 32-bit Cygwin version]),
  []
  [with_c32="default"])

AC_ARG_WITH(c64,
  AC_HELP_STRING([--with-c64], [Build 64-bit Cygwin version]),
  []
  [with_c64="default"])

uname_m=`uname -m`
uname_s=`uname -s`
case "$uname_s" in
*WOW)
  wow="yes"
  uname_o=`uname -o 2>/dev/null`
  ;;
Darwin)
# "uname -o" is not available on the Macintosh!
  wow="no"
  uname_o="macOS"
  ;;
*)
  wow="no"
  uname_o=`uname -o 2>/dev/null`
  ;;
esac

if test "$uname_o" = "Cygwin"
then
#
# If I am building under some sort of Cygwin I will adjust the "with-w32"
# etc options...
#

# The program that I build here scans the Windows registry to look for
# cygwin installations. When run it generates output "32", "64" or "32 64"
# depending on which variants it finds.

i686-w64-mingw32-g++ -O3 $srcdir/csl/cslbase/other-cygwin.cpp -static -o ./other-cygwin
i686-w64-mingw32-strip ./other-cygwin
CYGAVAIL=`./other-cygwin`

case $CYGAVAIL in
*32*)
  cyg32_available="yes"
  ;;
*)
  cyg32_available="no"
  ;;
esac
case $CYGAVAIL in
*64*)
  cyg64_available="yes"
  ;;
*)
  cyg64_available="no"
  ;;
esac
# If I am either running under 64-bit cygwin or are on 32-bit cygwin but on
# a 64-bit operating system I might be able to build 64-bit cygwin stuff.
  if test "$uname_m" = "x86_64" ||
     test "$wow" = "yes"
  then
    sixtyfour_feasible="yes"
  else
    sixtyfour_feasible="no"
  fi
# If 32-bit cygwin is available then by default build for it. If it is
# not then refuse to even if the user asked for it.
  if test "$cyg32_available" = "yes"
  then
    if test "$with_c32" = "default"
    then
      with_c32="yes"
    fi
  else
    if test "$with_c32" = "yes"
    then
      AC_MSG_ERROR([32-bit cygwin environment needed but not found in c:\cygwin])
    fi
    with_c32="no"
  fi

  if test "$sixtyfour_feasible" = "yes" && test "$cyg64_available" = "yes"
  then
    if test "$with_c64" = "default"
    then
      with_c64="yes"
    fi
  else
    if test "$with_c64" = "yes"
    then
      AC_MSG_ERROR([64-bit cygwin environment needed but not found in c:\cygwin64])
    fi
    with_c64="no"
  fi
fi

# In general it will be an inner invocation of this script that might
# have --with-cygwin32 or --with-cygwin64 passed. When that happens
# I ensure that the shell I am running under is the variant of cygwin
# indicated. This is useful because then just the plan commands gcc and g++
# will build binaries for that platform. I need to do this because
# cross-build toolchains for cygwin32 and cygwin64 do not seem to be
# complete enough to count as reliable.

AC_ARG_WITH(cygwin32,
  AC_HELP_STRING([--with-cygwin32],
                 [Force configure and build to be under cygwin32]),
  [],
  [with_cygwin32="no"])

AC_ARG_WITH(cygwin64,
  AC_HELP_STRING([--with-cygwin64],
                 [Force configure and build to be under cygwin64]),
  [],
  [with_cygwin64="no"])

# If the "--with-cygwin32" flag was passed and I am at present running under
# a 64-bit cygwin shell then I will insist on changing gear so that I run
# using a 32-bit cygwin shell.

if which i686-w64-mingw32-g++ >/dev/null 2>/dev/null &&
   which i686-w64-mingw32-strip >/dev/null 2>/dev/null
then
  i686-w64-mingw32-g++ -O3 -DFORCE32 $abssrcdir/csl/cslbase/other-cygwin.cpp -static -o cyg32.exe
  i686-w64-mingw32-strip ./cyg32.exe
  i686-w64-mingw32-g++ -O3 -DFORCE64 $abssrcdir/csl/cslbase/other-cygwin.cpp -static -o cyg64.exe
  i686-w64-mingw32-strip ./cyg64.exe
fi
LOCALCYG=""
if test "x$with_cygwin32" != "xno"
then
  LOCALCYG=`pwd`/cyg32.exe
fi
if test "x$with_cygwin64" != "xno"
then
  LOCALCYG=`pwd`/cyg64.exe
fi
AC_SUBST(LOCALCYG)

if test "x$with_cygwin32" != "xno" &&
   test "x$uname_o" = "xCygwin" &&
   test "x$uname_m" = "xx86_64"
then
  AC_MSG_NOTICE([Restart to use a 32-bit Cygwin shell])
  AC_MSG_NOTICE([with-cygwin32=$with_cygwin32 uname_o=$uname_o uname_m=$uname_m])
  doconfig="$LOCALCYG $SHELL -c \"$abssrcdir/configure $ac_configure_args\""
  AC_MSG_NOTICE([$doconfig])
  exec $doconfig
fi

if test "x$with_cygwin64" != "xno" &&
   test "x$uname_o" = "xCygwin" &&
   test "x$uname_m" = "xi686" &&
   test "x$wow" = "xyes"
then
  AC_MSG_NOTICE([Restart to use a 64-bit Cygwin shell])
  AC_MSG_NOTICE([with-cygwin64=$with_cygwin64 uname_o=$uname_o uname_m=$uname_m uname_s=$uname_s wow=$wow])
  doconfig="$LOCALCYG $SHELL -c \"$abssrcdir/configure $ac_configure_args\""
  AC_MSG_NOTICE([$doconfig])
  exex $doconfig
fi

AC_CANONICAL_HOST()

AC_ARG_WITH(build,
  AC_HELP_STRING([--with-build], [Used internally to control build directory]),
  [],
  [with_build="unknown"])

AC_ARG_WITH(pslbuild,
  AC_HELP_STRING([--with-pslbuild], [Used internally to control build directory]),
  [],
  [with_pslbuild="unknown"])

AC_ARG_WITH(cygbuild,
  AC_HELP_STRING([--with-cygbuild], [Used internally to control build directory]),
  [],
  [with_cygbuild="unknown"])

AC_ARG_WITH(cygbuild64,
  AC_HELP_STRING([--with-cygbuild64], [Used internally to control build directory]),
  [],
  [with_cygbuild64="unknown"])

AC_ARG_WITH(force,
  AC_HELP_STRING([--with-force], [Forces refresh of windows varients]),
  [],
  [with_force="no"])

# I could provide a --with-libedit=... option but the plan here is that
# the version used will only change during transitions made by the developers
# and so I limit myself to a fixed setting here. No ordinary person should
# ever need to alter this.

# This is set here so that if I need to experiment with or chance to a
# different version that will be reasonably tidy.
LIBEDIT_VERSION=20140620-3.1

############################################################################
#
# Modern versions of the autoconf tools seems to moan dreadfully if you pass
# down a flag that they do not know about, and so I transcribe into here
# all the flags that the CSL configuration may ever want. The down-side of
# this is that "configure --help" shows them all.

AC_ARG_WITH(lto,
   AC_HELP_STRING([--with-lto],
                  [Experiment with extreme optimisation in gcc (CSL only)]),
   [],
   [with_lto="no"])

# By and large the "-m32" and "-m64" flags that ONCE helped g++ with
# multi-arch support as between 32 and 64-bit targers. It is now used
# in the PSL case to control whether a 32 or 64-bit version gets set up.
# It should no longer be used with CSL please.

AC_ARG_WITH(m32,
   AC_HELP_STRING([--with-m32],
                  [Force 32-bit model even if 64-bit (for PSL).]),
   [],
   [with_m32="no"])

AC_ARG_WITH(m64,
   AC_HELP_STRING([--with-m64],
                  [Force 64-bit model even if 32-bit.]),
   [],
   [with_m64="no"])

AC_ARG_WITH(cygwin,
  AC_HELP_STRING([--with-cygwin],
                 [Force use of raw cygwin (CSL only)]),
  [],
  [with_cygwin="no"])

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
                 [garbage collect option: testing andf development use (CSL only)]),
  [],
  [enable_conservative="no"])

AC_ARG_ENABLE(test,
  AC_HELP_STRING([--enable-test],
                 [testing-mode version (CSL only)]),
  [],
  [enable_test="no"])

AC_ARG_ENABLE(experiment,
  AC_HELP_STRING([--enable-experiment],
                 [testing-mode version (CSL only)]),
  [],
  [enable_experiment="no"])

if test "x$enable_experiment" = "xyes"
then
  enable_test="yes"
fi

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

# Note that on Windows under cygwin i686-w64-mingw32 and x86_64-w64-mingw32
# compilers MUST be installed, and there should be a 32-bit
# cygwin installation in c:\cygwin and a 64-bit one in c:\cygwin64.
#

# Now I want to know if the current directory is the same as $srcdir. At
# one stage I checked that by looking to see if $srcdir was ".". That was OK
# for direct calls of the form "./configure" where the "." as in "./" was
# detected. But the reconfig step messes that up and anyway it is a delicate
# cheat. So here is a different delicate cheat!

rm -f ./testfile.tst "$abssrcdir/testfile.tst"
touch "$abssrcdir/testfile.tst"
if test -f ./testfile.tst
then
  rm -f ./testfile.tst
  inplace="yes"
else
  inplace="no"
fi

printf "in-place build attempt = $inplace\n"

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

if test "x$with_psl" != "xno"
then
  case $host in
  *windows | *cygwin)
# building PSL on Windows - need to decide whether to build for 32 or 64bit.
# Hah - I use "--with-m32" for selection of a PSL 32-bit option.
# Do not select 32bit when I am in a 32-bit shell running on a 64-bit operating
# system.
    if test "$uname_m" = "i686" -a "$wow" != "yes" ||
       test "x$with_m32" = "xyes"
    then 
      build="i686-pc-windows"
# For PSL I will build a 64-bit version either if I am running in 64-bit
# mode already or I am in a 32-bit shell running on a 64-bit operating
# system.
    elif test "$uname_m" = "x86_64" ||
         test "$wow" = "yes"
    then
      build="x86_64-pc-windows"
    else
# If neither of those tests resolve matters I will just take some default.
      build="$host"
    fi
# Normalize the name that PSL puts its (windows) builds in.
    case $build in
    *i686*)
       build=i686-pc-windows
       ;;
    *)
       build="x86_64-pc-windows"
       ;;
    esac
    ;;
  *)
# For cases other than Windows the PSL case is simpler.
    build=`$SHELL $abssrcdir/scripts/findhost.sh $host`
    ;;
  esac
else
# For PSL find an initial name for the directory to build in. In the Windows
# case this will be messed with further.
  build=`eval "$SHELL $abssrcdir/scripts/findhost.sh $host $ac_configure_args"`
fi

AC_MSG_NOTICE([Will build in the $build subdirectory])
procids=""

# There are many configure options that are valid or relevant at the
# top level but are not needed for sub-configure calls
filtered=`$abssrcdir/scripts/filter.sh "$ac_configure_args"`
nohost=`$abssrcdir/scripts/nohost.sh "$ac_configure_args"`
AC_MSG_NOTICE([args=<$ac_configure_args>])
AC_MSG_NOTICE([filtered=<$filtered>])
AC_MSG_NOTICE([nohost=<$nohost>])

AC_ARG_WITH(sequential,
  AC_HELP_STRING([--with-sequential],
                 [Avoid parallel configure to make log clearer to read]),
  [],
  [with_sequential="no"])


csl_inplace_cygwin_build ()
{
# The argument here will be either i686-pc-cygwin or x88_64-pc-cygwin
  target=$1
  forcer=$2
# Find the proper name for the target directory, allowing for --enable-debug
# and any other options that may be relevant.
  build=`eval "$SHELL $abssrcdir/scripts/findhost.sh $target $ac_configure_args" --with-cygwin`
  AC_MSG_NOTICE([target=$target => build=$build])
  mkdir -p "$abssrcdir/cslbuild/$build"
  cd "$abssrcdir/cslbuild/$build"
  if test "x$CC$CPP$CXX$CXXCPP" != "x"
  then
    passcc="CC=\"$CC\" CPP=\"$CPP\" CXX=\"$CXX\" CXXCPP=\"$CXXCPP\""
  else
    passcc=""
  fi
  AC_MSG_NOTICE([passcc = $passcc])
  AC_MSG_NOTICE([host=$host buildmc=$buildmc pass_host=$pass_host])
  pass_build="--with-build=\"$build\" --with-pslbuild=\"$pslbuild\""
  flip=""
  if test "$uname_m" = "x86_64" &&
     test "target" = "i686-pc-windows"
  then
    AC_MSG_NOTICE([Will build utility to flip cygwin version from 64 to 32 bit])
    i686-w64-mingw32-g++ -O3 -DFORCE32 $abssrcdir/csl/cslbase/other-cygwin.cpp -static -o cyg32
    i686-w64-mingw32-strip cyg32
    flip="`pwd`/cyg32.exe "
  fi
  if test "$uname_m" = "i686" &&
     test "target" = "x86_64-pc-windows"
  then
    AC_MSG_NOTICE([Will build utility to flip cygwin version from 32 to 64 bit])
    i686-w64-mingw32-g++ -O3 -DFORCE64 $abssrcdir/csl/cslbase/other-cygwin.cpp -static -o cyg64
    i686-w64-mingw32-strip cyg64
    flip="`pwd`/cyg64.exe "
  fi
  doconfig="$SHELL $flip $abssrcdir/configure --config-cache $ac_configure_args \
          CC=\"$flip$CC\" CXX=\"$flip$CXX\" \
          STRIP=\"$flip$STRIP\" RANLIB=\"$flip$RANLIB\" \ 
          $forcer CPPFLAGS=\"$CPPFLAGS\" CFLAGS=\"$CFLAGS\" \
          CXXFLAGS=\"$CXXFLAGS\" LDFLAGS=\"$LDFLAGS\" LIBS=\"$LIBS\" \
          $passcc $pass_build --with-cygwin"
  AC_MSG_NOTICE([doconfig = $doconfig])
  if test "x$with_sequential" = "xno"
  then
    eval "$doconfig" &
    procids="$procids $!"
  else
    eval "$doconfig"
  fi
  AC_MSG_NOTICE([configuration for cygwin on $target complete])
  cd "$abssrcdir"
}

csl_inplace_nativewin_build ()
{
  buildmc=$1
  host=$2
  AC_MSG_NOTICE([CSL inplace for native Windows])
  build=`eval "$SHELL $abssrcdir/scripts/findhost.sh $buildmc $ac_configure_args"`
  AC_MSG_NOTICE([About to configure using $host in $build])
  mkdir -p "$abssrcdir/cslbuild/$build"
  cd "$abssrcdir/cslbuild/$build"
  if test "x$CC$CPP$CXX$CXXCPP" != "x"
  then
    passcc="CC=\"$CC\" CPP=\"$CPP\" CXX=\"$CXX\" CXXCPP=\"$CXXCPP\""
  else
    passcc=""
  fi
  AC_MSG_NOTICE([passcc = $passcc])
# The Windows version would like to know where to find cygwin variants...
  cygextra=
  ed32="s/.*windows/i686-pc-cygwin/; s/.*cygwin/i686-pc-cygwin/"
  dd32=`echo $build | sed -e "$ed32"`
  cygextra="--with-cygbuild=$abssrcdir/cslbuild/$dd32"
  ed64="s/.*windows/x86_64-pc-cygwin/; s/.*cygwin/x86_64-pc-cygwin/"
  dd64=`echo $build | sed -e "$ed64"`
  cygextra="$cygextra --with-cygbuild64=$abssrcdir/cslbuild/$dd64"
  AC_MSG_NOTICE([cygextra = $cygextra])
  pass_build="--with-build=\"$build\" --with-pslbuild=\"$pslbuild\""
  doconfig="$SHELL $abssrcdir/configure --config-cache $ac_configure_args \
          CC=\"$CC\" CXX=\"$CXX\" \
          CPPFLAGS=\"$CPPFLAGS\" CFLAGS=\"$CFLAGS\" \
          CXXFLAGS=\"$CXXFLAGS\" LDFLAGS=\"$LDFLAGS\" LIBS=\"$LIBS\" \
          $passcc $cygextra $pass_build --host=$host"
  AC_MSG_NOTICE([doconfig = $doconfig])
  if test "x$with_sequential" = "xno"
  then
    eval "$doconfig" &
    procids="$procids $!"
  else
    eval "$doconfig"
  fi
  AC_MSG_NOTICE([configuration for $target complete])
  cd "$abssrcdir"
}

csl_inplace_windows_build ()
{
# If I am on Windows I will configure for variants:
#   i686-pc-cygwin
#   x86_64-pc-cygwin
#   i686-w64-mingw
#   x86_64-w64-mingw
  AC_MSG_NOTICE([Inplace Windows build...])
# I am going to suppose that all the compilers I could possibly want
# are installed. That means I do not need to put in code here to test that!
  AC_MSG_NOTICE([with_c32=$with_c32 with_c64=$with_c64 with_w32=$with_w32 with_w64=$with_w64 ])
  if test "$with_c32" = "yes"
  then
    AC_MSG_NOTICE([Configure cygwin32 version])
    csl_inplace_cygwin_build "i686-pc-cygwin" "--with-cygwin32"
  fi
  if test "$with_c64" = "yes"
  then
    AC_MSG_NOTICE([Configure cygwin64 version])
    csl_inplace_cygwin_build "x86_64-pc-cygwin" "--with-cygwin64"
  fi
# I will also need to build the native versions...
  if test "$with_w32" = "yes"
  then
    AC_MSG_NOTICE([Configure windows32 version])
    csl_inplace_nativewin_build "i686-pc-windows" "i686-w64-mingw32"
  fi
  if test "$with_w64"
  then
    AC_MSG_NOTICE([Configure windows64 version])
    csl_inplace_nativewin_build "x86_64-pc-windows" "x86_64-w64-mingw32"
  fi
}

csl_inplace_build ()
{
  mkdir -p "$abssrcdir/cslbuild"
# When I configure I will install a default "profile.dat" if there is
# not one in place already, but the user can always regenerate a newer
# local version of the profile.
  if test ! -d "$abssrcdir/cslbuild/generated-c" ||
     test ! -f "$abssrcdir/cslbuild/generated-c/profile.dat"
  then
    rm -rf "$abssrcdir/cslbuild/generated-c"
    mkdir -p "$abssrcdir/cslbuild/generated-c"
    cp -r "$abssrcdir/csl/generated-c" "$abssrcdir/cslbuild"
  fi
# Now I am configuring for CSL and am doing so from the top directory.
  AC_MSG_NOTICE([CSL in-place build for $build])
  case $build in
  *cygwin* | *windows* | *mingw*)
    csl_inplace_windows_build
    ;;
  *)
# All other platforms come here...
    mkdir -p "$abssrcdir/cslbuild/$build"
    cd "$abssrcdir/cslbuild/$build"
    if test "x$CC$CPP$CXX$CXXCPP" != "x"
    then
      passcc="CC=\"$CC\" CPP=\"$CPP\" CXX=\"$CXX\" CXXCPP=\"$CXXCPP\""
    else
      passcc=""
    fi
    AC_MSG_NOTICE([passcc = $passcc])
    pass_build="--with-build=\"$build\" --with-pslbuild=\"$pslbuild\""
    doconfig="$SHELL $abssrcdir/configure --config-cache $ac_configure_args \
            CC=\"$CC\" CXX=\"$CXX\" \
            CPPFLAGS=\"$CPPFLAGS\" CFLAGS=\"$CFLAGS\" \
            CXXFLAGS=\"$CXXFLAGS\" LDFLAGS=\"$LDFLAGS\" LIBS=\"$LIBS\" \
            $passcc $pass_build"
    AC_MSG_NOTICE([doconfig = $doconfig])
    eval "$doconfig"
    cd "$abssrcdir"
    ;;
  esac
}

psl_inplace_build ()
{
  AC_MSG_NOTICE([+++ Will build in $abssrcdir/pslbuild/$build])
  mkdir -p "$abssrcdir/pslbuild/$build"
  cd "$abssrcdir/pslbuild/$build"
# This passes down any configure arguments to the PSL-specific configuration
# but at present I do not expect any to be relevant.
  pass_build="--with-build=\"$build\""
  eval "$SHELL $abssrcdir/psl/configure --config-cache $ac_configure_args $pass_build"

  AC_MSG_NOTICE([About to configure crlibm])
  builddir=`pwd`
  mkdir -p crlibm
  cd crlibm

  if test "x$CC$CPP$CXX$CXXCPP" != "x"
  then
    passcc="CC=\"$CC\" CPP=\"$CPP\" CXX=\"$CXX\" CXXCPP=\"$CXXCPP\""
  else
    passcc=""
  fi
  case $host in
  i386* | i486* | i586* | i686*)
    passcc="$passcc --enable-sse2"
    ;;
  esac

  AC_MSG_NOTICE([passcc = $passcc])
  doconfig="$SHELL $abssrcdir/libraries/crlibm/configure --config-cache $filtered \
        $pass_host \
        CPPFLAGS=\"$CPPFLAGS\" \
        CFLAGS=\"$CFLAGS\" \
        CXXFLAGS=\"$CXXFLAGS\" \
        LDFLAGS=\"$LDFLAGS\" \
        $passcc \
        --prefix=\"$builddir\" \
        --libdir=\"$builddir/lib\" \
        --includedir=\"$builddir/include\""
  AC_MSG_NOTICE([doconfig = $doconfig])
  eval "$doconfig"
  cd "$builddir"

  AC_MSG_NOTICE([About to configure libedit])
  mkdir -p libedit
  cd libedit
  doconfig="$SHELL $abssrcdir/libraries/libedit-$LIBEDIT_VERSION/configure --config-cache \
        $nohost \
        CC=\"$CC\" CXX=\"$CXX\" \
        CPPFLAGS=\"$CPPFLAGS\" \
        CFLAGS=\"$CFLAGS\" \
        CXXFLAGS=\"$CXXFLAGS\" \
        LDFLAGS=\"$LDFLAGS\" \
        --enable-widec=yes \
        --prefix=\"$builddir\" \
        --libdir=\"$builddir/lib\" \
        --includedir=\"$builddir/include\""
  AC_MSG_NOTICE([doconfig = $doconfig])
  eval "$doconfig"

  cd "$builddir"

  ln -f -s $abssrcdir/libraries/wineditline .

  AC_MSG_NOTICE([About to configure redfront])
  mkdir -p redfront
  cd redfront

  doconfig="$SHELL $abssrcdir/generic/newfront/configure --config-cache $nohost \
        CC=\"$CC\" CXX=\"$CXX\" \
        CPPFLAGS=\"$CPPFLAGS\" \
        CFLAGS=\"$CFLAGS\" \
        CXXFLAGS=\"$CXXFLAGS\" \
        LDFLAGS=\"$LDFLAGS\" \
        --prefix=\"$builddir\" \
        --libdir=\"$builddir/lib\" \
        --includedir=\"$builddir/include\""
  AC_MSG_NOTICE([doconfig = $doconfig])
  eval "$doconfig"

  cd "$builddir"
}

# There are many configure options that are valid or relevant at the
# top level but are not needed for sub-configure calls
filtered=`$abssrcdir/scripts/filter.sh "$ac_configure_args"`
nohost=`$abssrcdir/scripts/nohost.sh "$ac_configure_args"`

case $inplace in
yes)
# Here somebody has run the "configure" script within the top-level
# source directory. I really want the build to take place in a
# host-specific subdirectory so I will divert things!
# When testing if --with-csl etc got passed I should check that the option
# NO was NOT given rather than that the option yes was.
  if test "x$with_csl" != "xno"
  then
    csl_inplace_build
  fi
  if test "x$with_psl" != "xno"
  then
    psl_inplace_build
  fi
  wait $procids
  printf "All sub-tasks should have completed\n"
  exit 0
  ;;
*)
  AC_MSG_NOTICE([+++ standard build case, abssrcdir = $abssrcdir = "$abssrcdir"])
  ;;
esac

# This is where the main bit of this script starts.

AC_CONFIG_SRCDIR(scripts/make.sh)

AM_INIT_AUTOMAKE([1.13 -Wno-portability foreign no-dist-gzip dist-bzip2])
LT_INIT

AC_CONFIG_FILES([Makefile])

###############################################################################
builddir=`pwd`

AC_ARG_WITH(ccache,
  AC_HELP_STRING([--with-ccache],
                 [--without-ccache can be used to disable use of ccache]),
  [], [])

AC_CHECK_PROG([CCACHE], [ccache], [ccache], [])
AC_MSG_NOTICE([CC=/$CC/ CXX=/$CXX/ CCACHE=/$CCACHE/])

# The use of ccache here deserves an explanation. The first and maybe obvious
# thing is that if wither ccache seems to to be installed or if the person
# who invoked the configure script had overridden CC or CXX so specify any
# custom compilers that I will not do anything.
# Then the "obvious" thing do do would be to go 'CC="ccache $CC"' so that
# subsequent compilation ended up cached. Well before I can do that I need
# to get CC set - and remember that if --host is set then it may end up
# being a cross-compiler. So 'CC="ccache gcc"' is certainly not good enough.
# However the autoconf macros that set CC (and CXX) also set CFLAGS etc
# in ways I do not want, so I take steps to preserve and restore those.
# Now an issue that caused me much pain. If CC ends up as text with embedded
# whitespace then passing it down to lower-level configure scripts is
# delicate. And at leats one library that I use performs a test of the form
#    if test $CC = xxx; then
# (where perhaps more properly it would have gone 'test "$CC" = "xxx"') and
# if CC expands to more than one word that gives a syntax error. So to work
# around both those problems I dynamically create short scripts to compile
# via ccache. These are placed in the top level build directory, which should
# be platform specific. This extra layer of shell scripting will have an
# adverse cost, but I hope that will be balanced by the effects of ccache. 
# Please note that here (and in other places) that whitespace in the path
# to where Reduce gets built is not supported. If some keen person would
# like to review all the build scripts and get quoting of strings fully
# correct that might be nice!
# Hah - a further issue. On some platforms gcc and g++ (and som others) will
# be links to ccache and so the facility is already used automatically. In
# that case it is not a help to wrap in an extra call to ccache!

ORIG="$CC$CXX"
OLD_CFLAGS="$CFLAGS"
OLD_CXXFLAGS="$CXXFLAGS"
OLD_CPPFLAGS="$CPPFLAGS"
AC_PROG_CC
AC_PROG_CXX
CFLAGS="$OLD_CFLAGS"
CXXFLAGS="$OLD_CXXFLAGS"
CPPFLAGS="$OLD_CPPFLAGS"

if test "$with_ccache" != "no" &&
   test "$ORIG" = "" &&
   test "$CCACHE" != ""
then
  RAWCC="`which $CC 2> /dev/null`"
  RAWXX="`which $CXX 2> /dev/null`"
  case "$CC$CXX `ls -l $RAWCC 2>/dev/null` `ls -l $RAWCXX 2>/dev/null`" in
  *ccache*)
    ;;
  *)
    d=`pwd`
    printf "#! /bin/sh\nccache $CC \"\$@\"\n" > $d/cachecc.sh
    printf "#! /bin/sh\nccache $CXX \"\$@\"\n" > $d/cachecxx.sh
    chmod +x $d/cachecc.sh $d/cachecxx.sh
    case $build in
    *cygwin* | *windows* | *mingw*)
# Now I want to turn the path into one that is "very" absolute. I need to
# do this because I will be building both cygwin32 and cygwin64 variants
# of Reduce, and paths such as "/home/USER/..." are liable to mean different
# things as between the 32 and 64-bit world. So what I need to end up with
# may be more like
#   /cygdrive/C/cygwin64/home/USER/reduce...
# which will find the same file in both worlds. "cygpath -m" turns a path
# into one that will start with a drive letter (C:/cygwin64...) and the
# jolly use of sed should turn that into what I need.
      d=`cygpath -m "$d" | sed -e 's_^\([a-zA-Z]\):_/cygdrive/\1_'`
      ;;
    esac
    CC="$d/cachecc.sh"
    CXX="$d/cachecxx.sh"
    ;;
  esac
fi

if test "x$with_csl" != "xno"
then
# Here I have a bunch of sub-directories that I need to configure

  AC_MSG_NOTICE([About to configure CSL core])
  mkdir -p csl
  cd csl

  case $host in
  *darwin* | *Darwin*)
    CPPFLAGS="$CPPFLAGS -mmacosx-version-min=10.9 -I/opt/local/include"
    LDFLAGS="$LDFLAGS -L/opt/local/lib"
    ;;
  esac

# If I am compiling for native Cygwin I will not pass down "--host"
# if I am building for the natural target.
  AC_MSG_NOTICE([host=$host build=$build])
  pass_host="--host=$host"
  if test "x$with_cygwin" != "xno"
  then
    pass_host=""
    case `uname -m -o` in
    *i686*Cygwin*)
      if test "x$host" != "xi686-unknown-cygwin" &&
         test "x$host" != "xi686-pc-cygwin"
      then
        pass_host="--host=$host"
      fi
      ;;
    *x86_64*Cygwin*)
      if test "x$host" != "xx86_64-unknown-cygwin" &&
         test "x$host" != "xx86_64-pc-cygwin"
      then
        pass_host="--host=$host"
      fi
      ;;
    esac
  fi

  AC_MSG_NOTICE([with_cygwin=$with_cygwin pass_host=$pass_host])

  if test "x$with_wx" != "xno"
  then
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
    doconfig="$SHELL $abssrcdir/csl/cslbase/configure -C \
        $ac_configure_args \
        CC=\"$CC\" CXX=\"$CXX\" \
        CPPFLAGS=\"$CPPFLAGS\" CFLAGS=\"$CFLAGS\" \
        CXXFLAGS=\"$CXXFLAGS\" LDFLAGS=\"$LDFLAGS\" LIBS=\"$LIBS\" \
        $pass_host --with-wx=\"$with_wx\" $pass_build --without-fox"
  elif test "x$with_fox" != "xno"
  then
    pass_build="--with-build=\"$build\""
    doconfig="$SHELL $abssrcdir/csl/cslbase/configure -C \
        $ac_configure_args \
        CC=\"$CC\" CXX=\"$CXX\" \
        CPPFLAGS=\"$CPPFLAGS\" CFLAGS=\"$CFLAGS\" \
        CXXFLAGS=\"$CXXFLAGS\" LDFLAGS=\"$LDFLAGS\" LIBS=\"$LIBS\" \
        $pass_host --with-fox=\"$builddir\" --with-fox-pending=yes $pass_build --without-wx"
  else
# This final version will be without any GUI.
    pass_build="--with-build=\"$build\""
    doconfig="$SHELL $abssrcdir/csl/cslbase/configure \
        -C \
        $ac_configure_args \
        CC=\"$CC\" CXX=\"$CXX\" \
        CPPFLAGS=\"$CPPFLAGS\" CFLAGS=\"$CFLAGS\" \
        CXXFLAGS=\"$CXXFLAGS\" LDFLAGS=\"$LDFLAGS\" LIBS=\"$LIBS\" \
        $pass_host $pass_build --without-fox --without-wx"
  fi
  AC_MSG_NOTICE([$doconfig])
  if test "x$with_sequential" = "xno"
  then
    eval "$doconfig" &
    procids="$procids $!"
  else
    eval "$doconfig"
  fi
  cd "$builddir"

    extras=
  wx=

  case $host in
    *cygwin*)
      if test "x$with_cygwin" != "xyes"
      then
        AC_MSG_NOTICE([gcc will be used in mingw mode.])
      else
        AC_MSG_NOTICE([Using raw cygwin])
        CPPFLAGS="$CPPFLAGS -I/usr/include/freetype2 -I/usr/include/ncurses "
        extras="--with-xft --with-xim"
      fi
      ;;
    *Darwin* | *darwin*)
# clang on MacOSX does not provide -mfpmath
#     CFLAGS="$CFLAGS -msse2 -mfpmath=sse"
#     CXXFLAGS="$CXXFLAGS -msse2 -mfpmath=sse"
      MACARCH="--enable-macosx_arch=x86_64" 
      extras="--with-xft --with-xim"
      wx="--with-cocoa \
          --with-macosx-version-min=10.10 \
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

  if test "x$with_wx" != "xno"
  then
    mkdir wxWidgets
    cd wxWidgets
    AC_MSG_NOTICE([About to configure wxWidgets])
# I need --enable-unicode on Windows at least so that I can use the
# BaKoMa fonts which remap at least one TeX glyph to outside the range
# of simple 8-bit characters. This will bring some follow-on pain no doubt
# but addressing that pain is probably good in the long term. 
    if test "x$CC$CPP$CXX$CXXCPP" != "x"
    then
      passcc="CC=\"$CC\" CPP=\"$CPP\" CXX=\"$CXX\" CXXCPP=\"$CXXCPP\""
    else
      passcc=""
    fi
    AC_MSG_NOTICE([passcc = $passcc pass_host=$pass_host])
    doconfig="$SHELL $abssrcdir/csl/wxWidgets/configure -C $wx \
            $pass_host \
            CPPFLAGS=\"$CPPFLAGS -D_GNU_SOURCE=1\" \
            CFLAGS=\"$CFLAGS\" \
            CFLAGS=\"$CFLAGS\" \
            CXXFLAGS=\"$CXXFLAGS\" \
            LDFLAGS=\"$LDFLAGS\" \
            $passcc \
            --disable-shared \
            --enable-unicode \
            --disable-compat28 \
            --enable-monolithic \
            --disable-sys-libs \
            --without-libjpeg \
            --without-libtiff \
            --disable-svg \
            --without-sdl \
            --without-expat \
            --without-libiconv \
            --without-regex \
            --disable-webview \
            --disable-richtext \
            --disable-gif \
            --disable-pcx \
            --enable-graphics_ctx \
            --disable-tga \
            --disable-pnm \
            --enable-dynlib \
            --enable-dynamicloader \
            --prefix=\"$builddir\" \
            --libdir=\"$builddir/lib\" \
            --includedir=\"$builddir/include\""
    if test "x$enable_debug" != "xno"
    then
      doconfig="$doconfig --enable-debug"
    else
      doconfig="$doconfig --disable-debug"
    fi
    if test "x$with_cygwin" != "xno"
    then
      doconfig="$doconfig --with-gtk"
    fi
    AC_MSG_NOTICE([doconfig = $doconfig])
    if test "x$with_sequential" = "xno"
    then
      eval "$doconfig" &
      jobs
      procids="$procids $!"
    else
      eval "$doconfig"
    fi
    cd "$builddir"
  elif test "x$with_fox" != "xno"
  then
    AC_MSG_NOTICE([About to configure FOX])
    mkdir -p fox/src
    # The Makefile that comes with FOX seems to require these GIF files
    # in the build directory.
    cp "$abssrcdir/csl/fox/src/"*.gif fox/src
    cd fox
    if test "x$CC$CPP$CXX$CXXCPP" != "x"
    then
      passcc="CC=\"$CC\" CPP=\"$CPP\" CXX=\"$CXX\" CXXCPP=\"$CXXCPP\""
    else
      passcc=""
    fi
    AC_MSG_NOTICE([passcc = $passcc])
    doconfig="$SHELL $abssrcdir/csl/fox/configure -C $ac_configure_args \
            CPPFLAGS=\"$CPPFLAGS\" \
            CFLAGS=\"$CFLAGS\" \
            CXXFLAGS=\"$CXXFLAGS\" \
            LDFLAGS=\"$LDFLAGS\" \
            $passcc \
            $pass_host \
            --enable-release \
            --with-opengl=no \
            --disable-jpeg \
            --disable-zlib \
            --disable-bz2lib \
            --disable-png \
            --disable-tiff \
            --prefix=\"$builddir\" \
            --libdir=\"$builddir/lib\" \
            --includedir=\"$builddir/include\" \
            $extras"
    AC_MSG_NOTICE([doconfig = $doconfig])
    if test "x$with_sequential" = "xno"
    then
      eval "$doconfig" &
      procids="$procids $!"
    else
      eval "$doconfig"
    fi
    cd "$builddir"
  fi

fi

AC_MSG_NOTICE([GUI toolkit config spawned])

if test "x$with_crlibm" = "xno"
then
  AC_MSG_NOTICE([crlibm will not be used here])
else
  AC_MSG_NOTICE([About to configure crlibm])
  mkdir -p crlibm
  cd crlibm

  if test "x$CC$CPP$CXX$CXXCPP" != "x"
  then
    passcc="CC=\"$CC\" CPP=\"$CPP\" CXX=\"$CXX\" CXXCPP=\"$CXXCPP\""
  else
    passcc=""
  fi
  case $host in
  i386* | i486* | i586* | i686*)
    passcc="$passcc --enable-sse2"
    ;;
  esac
  AC_MSG_NOTICE([passcc = $passcc])
  doconfig="$SHELL $abssrcdir/libraries/crlibm/configure -C $filtered \
        $pass_host \
        CPPFLAGS=\"$CPPFLAGS\" \
        CFLAGS=\"$CFLAGS\" \
        CXXFLAGS=\"$CXXFLAGS\" \
        LDFLAGS=\"$LDFLAGS\" \
        $passcc \
        --prefix=\"$builddir\" \
        --libdir=\"$builddir/lib\" \
        --includedir=\"$builddir/include\""
  AC_MSG_NOTICE([doconfig = $doconfig])
  if test "x$with_sequential" = "xno"
  then
    eval "$doconfig" &
    procids="$procids $!"
  else
    eval "$doconfig"
  fi
  cd "$builddir"
fi

AC_MSG_NOTICE([About to configure libffi])
mkdir -p libffi
cd libffi

if test "x$CC$CPP$CXX$CXXCPP" != "x"
then
  passcc="CC=\"$CC\" CPP=\"$CPP\" CXX=\"$CXX\" CXXCPP=\"$CXXCPP\""
else
  passcc=""
fi
AC_MSG_NOTICE([passcc = $passcc])
doconfig="$SHELL $abssrcdir/libraries/libffi/configure -C $filtered \
        $pass_host \
        CPPFLAGS=\"$CPPFLAGS\" \
        CFLAGS=\"$CFLAGS\" \
        CXXFLAGS=\"$CXXFLAGS\" \
        LDFLAGS=\"$LDFLAGS\" \
        $passcc \
        --disable-multi-os-directory \
        --disable-docs \
        --prefix=\"$builddir\" \
        --libdir=\"$builddir/lib\" \
        --includedir=\"$builddir/include\""
AC_MSG_NOTICE([doconfig = $doconfig])
if test "x$with_sequential" = "xno"
then
  eval "$doconfig" &
  procids="$procids $!"
else
  eval "$doconfig"
fi
cd "$builddir"

if test "x$CC$CPP$CXX$CXXCPP" != "x"
then
  passcc="CC=\"$CC\" CPP=\"$CPP\" CXX=\"$CXX\" CXXCPP=\"$CXXCPP\""
else
  passcc=""
fi
AC_MSG_NOTICE([passcc = $passcc])
doconfig="$SHELL $abssrcdir/libraries/SoftFloat-3a/source/configure -C \
        $filtered \
        $pass_host \
        CPPFLAGS=\"$CPPFLAGS\" \
        CFLAGS=\"$CFLAGS\" \
        CXXFLAGS=\"$CXXFLAGS\" \
        LDFLAGS=\"$LDFLAGS\" \
        $passcc \
        --prefix=\"$builddir\" \
        --libdir=\"$builddir/lib\" \
        --includedir=\"$builddir/include\""
AC_MSG_NOTICE([doconfig = $doconfig])
if test "x$with_sequential" = "xno"
then
  eval "$doconfig" &
  procids="$procids $!"
else
  eval "$doconfig"
fi

cd "$builddir"

AC_MSG_NOTICE([About to configure libedit])
mkdir -p libedit
cd libedit

doconfig="$SHELL $abssrcdir/libraries/libedit-$LIBEDIT_VERSION/configure -C \
        $nohost \
        CC=\"$CC\" CXX=\"$CXX\" \
        CPPFLAGS=\"$CPPFLAGS\" \
        CFLAGS=\"$CFLAGS\" \
        CXXFLAGS=\"$CXXFLAGS\" \
        LDFLAGS=\"$LDFLAGS\" \
        --enable-widec=yes \
        --prefix=\"$builddir\" \
        --libdir=\"$builddir/lib\" \
        --includedir=\"$builddir/include\""
AC_MSG_NOTICE([doconfig = $doconfig])
if test "x$with_sequential" = "xno"
then
  eval "$doconfig" &
  procids="$procids $!"
else
  eval "$doconfig"
fi

cd "$builddir"

ln -f -s $abssrcdir/libraries/wineditline .

AC_MSG_NOTICE([About to configure redfront])
mkdir -p redfront
cd redfront

doconfig="$SHELL $abssrcdir/generic/newfront/configure -C $nohost \
        CC=\"$CC\" CXX=\"$CXX\" \
        CPPFLAGS=\"$CPPFLAGS\" \
        CFLAGS=\"$CFLAGS\" \
        CXXFLAGS=\"$CXXFLAGS\" \
        LDFLAGS=\"$LDFLAGS\" \
        --prefix=\"$builddir\" \
        --libdir=\"$builddir/lib\" \
        --includedir=\"$builddir/include\""
AC_MSG_NOTICE([doconfig = $doconfig])
if test "x$with_sequential" = "xno"
then
  eval "$doconfig" &
  procids="$procids $!"
else
  eval "$doconfig"
fi

cd "$builddir"

AC_MSG_NOTICE([All sub-packages have had their configure script launched])

###############################################################################

AM_CONDITIONAL(csl, test "x$with_csl" != "xno")
AM_CONDITIONAL(psl, test "x$with_psl" != "xno")
AM_CONDITIONAL(cslpsl, test "x$with_csl" != "xno" && test "x$with_psl" != "xno")
AM_CONDITIONAL(fox, test "x$with_fox" != "xno")
AM_CONDITIONAL(wx,  test "x$with_wx" != "xno")
AM_CONDITIONAL(crlibm, test "x$with_crlibm" != "xno")

AC_MSG_NOTICE([final output from top level configuration])

AC_OUTPUT

printf "Wait for %s\n" "$procids"
wait $procids
printf "All sub-tasks should have completed\n"

# end of configure.ac

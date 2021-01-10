AC_INIT([REDUCE], [from SourceForge], [acn1@cam.ac.uk])

# **************************************************************************
# * Copyright (C) 2017-20, Codemist.                      A C Norman       *
# *                                                                        *
# * Redistribution and use in source and binary forms, with or without     *
# * modification, are permitted provided that the following conditions are *
# * met:                                                                   *
# *                                                                        *
# *     * Redistributions of source code must retain the relevant          *
# *       copyright notice, this list of conditions and the following      *
# *       disclaimer.                                                      *
# *     * Redistributions in binary form must reproduce the above          *
# *       copyright notice, this list of conditions and the following      *
# *       disclaimer in the documentation and/or other materials provided  *
# *       with the distribution.                                           *
# *                                                                        *
# * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    *
# * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      *
# * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS      *
# * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE         *
# * COPYRIGHT OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,   *
# * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,   *
# * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS  *
# * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND *
# * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR  *
# * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF     *
# * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH   *
# * DAMAGE.                                                                *
# **************************************************************************



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
AC_CONFIG_AUX_DIR([.])

abssrcdir=`"$srcdir/scripts/here.sh"`

if which cygpath 2> /dev/null
then
  a=`cygpath -am "$abssrcdir"`
  b="${a%%/*}/"
  d="${a#${b}}"
  c=`cygpath $b`
  abssrcdir="$c$d"
fi

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
    printf "You must have autoconf (at least version 2.61) installed to\n"
    printf "build this package. Install it and try again please.\n"
    exit 1
  fi

  if ! which automake > /dev/null 2> /dev/null
  then
    printf "You must have automake (at least version 1.13) installed to\n"
    printf "build this package. Install it and try again please.\n"
    exit 1
  fi

  if ! which libtool > /dev/null 2> /dev/null
  then
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
    printf "You have autoconf $acmaj.$acmin but at least 2.61 is needed\n"
    printf "to build this package. Install it and try again please.\n"
    exit 1
  fi

  if test $ammaj -lt 1 || test $ammaj -eq 1 && test $ammin -lt 13
  then
    printf "You have automake $ammaj.$ammin but at least 1.13 is needed\n"
    printf "to build this package. Install it and try again please.\n"
    exit 1
  fi

  here=`pwd`
  cd $abssrcdir
  printf "Regenerate autoconf-related files\n"
  if ! eval $SHELL -c \"./autogen.sh $ac_configure_args\"
  then
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
  AC_HELP_STRING([--with-wx],
                 [enable or disable use of wxWidgets (CSL only)]),
  [],
  [with_wx="default"])

AC_ARG_WITH(fox,
  AC_HELP_STRING([--with-fox],
                 [enable or disable use of FOX (CSL only)]),
  [],
  [with_fox="default"])

if test "x$with_psl" != "xno"
then
  with_fox=no
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
#    --with-fox        build FOX version in x-y-z
#    --with-wx         build wxWidgets version in x-y-z-wx
#    --without-fox     if FOX is the default behave as --without -gui
#    --without-wx      if wxWidgets is the default behave as --without-gui
# If the user says --without-wx when FOX was to be the default GUI then in
# effect this redundant statement is ignored.
# It is not proper to say more than one from --with-fox, --with-wx,
# and --without-gui, but each can be used in separate calls to the
# configure script to build parallel versions.
#
# There is no point or merit in --with-fox=XXXX for some XXX
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

# On Windows there should be 3 variants  of Reduce made:
#   cygwin 64-bit (this can be used either in console mode or using X)
#   native windows 64-bit console mode
#   native windows 64-bit windows mode
#

uname_s=`uname -s`
case "$uname_s" in
Darwin)
# "uname -o" is not available on the Macintosh!
  uname_o="macOS"
  ;;
*)
  uname_o=`uname -o 2>/dev/null`
  ;;
esac

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
                 [garbage collect option: testing and development use (CSL only)]),
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

AC_ARG_WITH(arithlib,
  AC_HELP_STRING([--with-arithlib],
                 [development of arithlib.hpp support (CSL only)]),
  [],
  [with_arithlib="no"])

AC_ARG_ENABLE(static,
  AC_HELP_STRING([--enable-static],
                 [link it all statically (CSL only)]),
  [],
  [enable_static="no"])

AC_ARG_WITH(throw,
  AC_HELP_STRING([--without-throw],
                 [Avoid C++ catch & throw. Experimental. (CSL only)]),
  [],
  [with_throw="yes"])

CSLBASE=cslbase
GENERATED_C=generated-c

AC_ARG_ENABLE(static,
  AC_HELP_STRING([--enable-static],
                 [link it all statically (CSL only)]),
  [],
  [enable_static="no"])

###########################################################################

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
    build="x86_64-pc-windows"
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

# There are many configure options that are valid or relevant at the
# top level but are not needed for sub-configure calls
filtered=`$abssrcdir/scripts/filter.sh "$ac_configure_args"`
nohost=`$abssrcdir/scripts/nohost.sh "$ac_configure_args"`
AC_MSG_NOTICE([args=<$ac_configure_args>])
AC_MSG_NOTICE([filtered=<$filtered>])
AC_MSG_NOTICE([nohost=<$nohost>])


# Hah - the next is a jolly jape. It arranged that when I build on one of my
# own real machines I default to a new and experimental layout for the build
# of windows versions, but everybody else (unless their host has a name
# matching mine!) should be undisturbed.

# I have disabled this just for a while... I am making other changes and I do
# not want this confusion to mess me up.

case `uname -n` in
*panamintXXX* | *gauguinXXX*)
  default_windows_layout="new"
  ;;
*)
  default_windows_layout="old"
  ;;
esac

AC_ARG_WITH(windows_layout,
  AC_HELP_STRING([--with-windows_layout], [old or new windows layout]),
  [],
  [with_windows_layout="$default_windows_layout"])

AC_MSG_NOTICE([default=$default_windows_layout this-layout=$with_windows_layout])

if test "$with_windows_layout" != "new"
then
  with_windows_layout="old"
fi

AC_ARG_WITH(mac_universal,
  AC_HELP_STRING([--with-mac-universal], [Build universal mac app]),
  [],
  [with_mac_universal="no"])

AC_ARG_WITH(mac_x86_64,
  AC_HELP_STRING([--with-mac-x86_64], [Build x86_64 mac app]),
  [],
  [with_mac_x86_64="no"])

AC_ARG_WITH(mac_arm64,
  AC_HELP_STRING([--with-mac-arm64], [Build arm64 mac app]),
  [],
  [with_mac_arm64="no"])

csl_inplace_cygwin_build ()
{
# The argument here should be x88_64-pc-cygwin
  target=$1
  forcer=$2
AC_MSG_NOTICE([in csl_inplace_cygwin_build wwl=$with_windows_layout])
# Find the proper name for the target directory, allowing for --enable-debug
# and any other options that may be relevant.
  if test "$with_windows_layout" = "new"
  then
    cygver="cyg64"
    build=`eval "$SHELL $abssrcdir/scripts/findhost.sh intel-pc-windows $ac_configure_args --with-cygwin"`
    AC_MSG_NOTICE([target=$target => build=$build/$cygver])
    mkdir -p "$abssrcdir/cslbuild/$build/$cygver"
    cp "$abssrcdir/csl/$CSLBASE/Makefile.windows" "$abssrcdir/cslbuild/$build/Makefile"
    cp "$abssrcdir/csl/$CSLBASE/stub2020.c" "$abssrcdir/cslbuild/$build/stub2020.c"
    cp "$abssrcdir/csl/$CSLBASE/make-cygwin-symlink.c" "$abssrcdir/cslbuild/$build/make-cygwin-symlink.c"
    cp "$abssrcdir/csl/$CSLBASE/redpsl.sh" "$abssrcdir/cslbuild/$build/redpsl"
    cd "$abssrcdir/cslbuild/$build/$cygver"
  elif test "x$with_mac_universal" = "xyes" &&
       test "x$with_mac_x86_64" = "xno" &&
       test "x$with_mac_arm64" = "xno"
  then
    build=`eval "$SHELL $abssrcdir/scripts/findhost.sh universal-mac-macos $ac_configure_args"`
    AC_MSG_NOTICE([target=$target => build=$build])
    mkdir -p "$abssrcdir/cslbuild/$build/x86_64"
    mkdir -p "$abssrcdir/cslbuild/$build/arm64"
    cp "$abssrcdir/csl/$CSLBASE/Makefile.mac-universal" "$abssrcdir/cslbuild/$build/Makefile"
    cd "$abssrcdir/cslbuild/$build"
    config_both="yes"
  else
    build=`eval "$SHELL $abssrcdir/scripts/findhost.sh $target $ac_configure_args --with-cygwin"`
    AC_MSG_NOTICE([target=$target => build=$build])
    mkdir -p "$abssrcdir/cslbuild/$build"
    cd "$abssrcdir/cslbuild/$build"
  fi
  if test "x$CC$CPP$CXX$CXXCPP" != "x"
  then
    passcc="CC=\"$CC\" CPP=\"$CPP\" CXX=\"$CXX\" CXXCPP=\"$CXXCPP\""
  else
    passcc=""
  fi
  AC_MSG_NOTICE([passcc = $passcc])
  AC_MSG_NOTICE([host=$host buildmc=$buildmc pass_host=$pass_host])
  pass_build="--with-build=\"$build\" --with-pslbuild=\"$pslbuild\""
  if test "$config_both" = "yes"
  then
    cd x86_64
    doconfig="$SHELL $abssrcdir/configure --config-cache $ac_configure_args \
            CC=\"$CC\" CXX=\"$CXX\" \
            STRIP=\"$STRIP\" RANLIB=\"$RANLIB\" \ 
            $forcer CPPFLAGS=\"$CPPFLAGS -arch x86_64\" CFLAGS=\"$CFLAGS -arch x86_64\" \
            CXXFLAGS=\"$CXXFLAGS -arch x86_64\" LDFLAGS=\"$LDFLAGS -arch x86_64\" LIBS=\"$LIBS\" \
            $passcc $pass_build --with-cygwin"
    AC_MSG_NOTICE([doconfig = $doconfig])
    eval "$doconfig"
    cd ../arm64
    doconfig="$SHELL $abssrcdir/configure --config-cache $ac_configure_args \
            CC=\"$CC\" CXX=\"$CXX -arch arm64\" \
            STRIP=\"$STRIP\" RANLIB=\"$RANLIB\" \ 
            $forcer CPPFLAGS=\"$CPPFLAGS -arch arm64\" CFLAGS=\"$CFLAGS -arch arm64\" \
            CXXFLAGS=\"$CXXFLAGS -arch arm64\" LDFLAGS=\"$LDFLAGS -arch arm64\" LIBS=\"$LIBS\" \
            $passcc $pass_build --with-cygwin"
    AC_MSG_NOTICE([doconfig = $doconfig])
    eval "$doconfig"
    cd ..
  else
    doconfig="$SHELL $abssrcdir/configure --config-cache $ac_configure_args \
            CC=\"$CC\" CXX=\"$CXX\" \
            STRIP=\"$STRIP\" RANLIB=\"$RANLIB\" \ 
            $forcer CPPFLAGS=\"$CPPFLAGS\" CFLAGS=\"$CFLAGS\" \
            CXXFLAGS=\"$CXXFLAGS\" LDFLAGS=\"$LDFLAGS\" LIBS=\"$LIBS\" \
            $passcc $pass_build --with-cygwin"
    AC_MSG_NOTICE([doconfig = $doconfig])
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
  if test "$with_windows_layout" = "new"
  then
    winver="win64"
    build=`eval "$SHELL $abssrcdir/scripts/findhost.sh intel-pc-windows $ac_configure_args"`
    AC_MSG_NOTICE([About to configure using $host in $build/$winver])
    mkdir -p "$abssrcdir/cslbuild/$build/$winver"
    cp "$abssrcdir/csl/$CSLBASE/Makefile.windows" "$abssrcdir/cslbuild/$build/Makefile"
    cd "$abssrcdir/cslbuild/$build/$winver"
  else
    build=`eval "$SHELL $abssrcdir/scripts/findhost.sh $target $ac_configure_args"`
    AC_MSG_NOTICE([About to configure using $host in $build])
    mkdir -p "$abssrcdir/cslbuild/$build"
    cd "$abssrcdir/cslbuild/$build"
  fi
  if test "x$CC$CPP$CXX$CXXCPP" != "x"
  then
    passcc="CC=\"$CC\" CPP=\"$CPP\" CXX=\"$CXX\" CXXCPP=\"$CXXCPP\""
  else
    passcc=""
  fi
  AC_MSG_NOTICE([passcc = $passcc])
  if test "$with_windows_layout" = "new"
  then
    cygextra=
  else
# The Windows version would like to know where to find cygwin variants
# at run-time.
    cygextra=
    ed64="s/.*windows/x86_64-pc-cygwin/; s/.*cygwin/x86_64-pc-cygwin/"
    dd64=`echo $build | sed -e "$ed64"`
    cygextra="$cygextra --with-cygbuild64=$abssrcdir/cslbuild/$dd64"
    AC_MSG_NOTICE([cygextra = $cygextra])
  fi
  pass_build="--with-build=\"$build\" --with-pslbuild=\"$pslbuild\""
  doconfig="$SHELL $abssrcdir/configure --config-cache $ac_configure_args \
          CC=\"$CC\" CXX=\"$CXX\" \
          CPPFLAGS=\"$CPPFLAGS\" CFLAGS=\"$CFLAGS\" \
          CXXFLAGS=\"$CXXFLAGS\" LDFLAGS=\"$LDFLAGS\" LIBS=\"$LIBS\" \
          $passcc $cygextra $pass_build --host=$host"
  AC_MSG_NOTICE([doconfig = $doconfig])
  eval "$doconfig"
  AC_MSG_NOTICE([configuration for $target complete])
  cd "$abssrcdir"
}

csl_inplace_windows_build ()
{
# If I am on Windows I will configure for variants:
#   x86_64-pc-cygwin
#   x86_64-w64-mingw
  AC_MSG_NOTICE([Inplace Windows build...])
# I am going to suppose that all the compilers I could possibly want
# are installed. That means I do not need to put in code here to test that!
  AC_MSG_NOTICE([Configure cygwin64 version])
  csl_inplace_cygwin_build "x86_64-pc-cygwin" "--with-cygwin64"
  AC_MSG_NOTICE([Configure windows64 version])
  csl_inplace_nativewin_build "x86_64-pc-windows" "x86_64-w64-mingw32"
}

csl_inplace_build ()
{
  mkdir -p "$abssrcdir/cslbuild"
# When I configure I will install a default "profile.dat" if there is
# not one in place already, but the user can always regenerate a newer
# local version of the profile.
  if test ! -d "$abssrcdir/cslbuild/$GENERATED_C" ||
     test ! -f "$abssrcdir/cslbuild/$GENERATED_C/profile.dat"
  then
    rm -rf "$abssrcdir/cslbuild/$GENERATED_C"
    mkdir -p "$abssrcdir/cslbuild/$GENERATED_C"
    cp -r "$abssrcdir/csl/$GENERATED_C" "$abssrcdir/cslbuild"
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
    CPPFLAGS="$CPPFLAGS -I/opt/local/include"
    LDFLAGS="$LDFLAGS -L/opt/local/lib"
# The Apple change-over from x86_64 to arm64 will be "fun". For now
# I have 4 scenarios:
#     default:              build explicitly for x86_64 and up to 10.13.
#     --with-mac-x86_64:    ditto.
#     --with-mac-arm64:     build for arm64 and 11.0 up.
#     --with-mac-universal: build both versions (not yet implemented but
#                           should become the new default if on an arm64 mac).
    if test "x$with_mac_x86_64" = "xyes"
    then
       CPPFLAGS="$CPPFLAGS -mmacosx-version-min=10.13 -arch x86_64"
       CFLAGS="$CFLAGS -mmacosx-version-min=10.13 -arch x86_64"
       CXXFLAGS="$CXXFLAGS -mmacosx-version-min=10.13 -arch x86_64"
       LDFLAGS="$LDFLAGS -mmacosx-version-min=10.13 -arch x86_64"
    elif test "x$with_mac_arm64" = "xyes"
    then
       CPPFLAGS="$CPPFLAGS -mmacosx-version-min=11.0 -arch arm64"
       CFLAGS="$CFLAGS -mmacosx-version-min=11.0 -arch arm64"
       CXXFLAGS="$CXXFLAGS -mmacosx-version-min=11.0 -arch arm64"
       LDFLAGS="$LDFLAGS -mmacosx-version-min=11.0 -arch arm64"
    elif test "x$with_mac_universal" != "xyes"
    then
       CPPFLAGS="$CPPFLAGS -mmacosx-version-min=10.13"
       CFLAGS="$CFLAGS -mmacosx-version-min=10.13"
       CXXFLAGS="$CXXFLAGS -mmacosx-version-min=10.13"
       LDFLAGS="$LDFLAGS -mmacosx-version-min=10.13"
    fi
    ;;
  esac

# If I am compiling for native Cygwin I will not pass down "--host"
# if I am building for the natural target.
  AC_MSG_NOTICE([host=$host build=$build])
  pass_host="--host=$host"
  if test "x$with_cygwin" != "xno"
  then
    pass_host=""
    if test "x$host" != "xx86_64-unknown-cygwin" &&
       test "x$host" != "xx86_64-pc-cygwin"
    then
      pass_host="--host=$host"
    fi
  fi

  AC_MSG_NOTICE([with_cygwin=$with_cygwin pass_host=$pass_host])

  if test "x$with_wx" != "xno"
  then
# A short essay to explain why I pass down "--host=$host" here. There are
# two points. The first is that I cope with 64-bit windows by use of
# cross-compilation using the x86_64-win32-mingw32 toolchain, and I need
# to pass down the information that I am doing that.
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
    doconfig="$SHELL $abssrcdir/csl/$CSLBASE/configure -C \
        $ac_configure_args \
        CC=\"$CC\" CXX=\"$CXX\" \
        CPPFLAGS=\"$CPPFLAGS\" CFLAGS=\"$CFLAGS\" \
        CXXFLAGS=\"$CXXFLAGS\" LDFLAGS=\"$LDFLAGS\" LIBS=\"$LIBS\" \
        $pass_host --with-wx=\"$with_wx\" $pass_build --without-fox"
  elif test "x$with_fox" != "xno"
  then
    pass_build="--with-build=\"$build\""
    doconfig="$SHELL $abssrcdir/csl/$CSLBASE/configure -C \
        $ac_configure_args \
        CC=\"$CC\" CXX=\"$CXX\" \
        CPPFLAGS=\"$CPPFLAGS\" CFLAGS=\"$CFLAGS\" \
        CXXFLAGS=\"$CXXFLAGS\" LDFLAGS=\"$LDFLAGS\" LIBS=\"$LIBS\" \
        $pass_host --with-fox=\"$builddir\" $pass_build --without-wx"
  else
# This final version will be without any GUI.
    pass_build="--with-build=\"$build\""
    doconfig="$SHELL $abssrcdir/csl/$CSLBASE/configure \
        -C \
        $ac_configure_args \
        CC=\"$CC\" CXX=\"$CXX\" \
        CPPFLAGS=\"$CPPFLAGS\" CFLAGS=\"$CFLAGS\" \
        CXXFLAGS=\"$CXXFLAGS\" LDFLAGS=\"$LDFLAGS\" LIBS=\"$LIBS\" \
        $pass_host $pass_build --without-fox --without-wx"
  fi
  AC_MSG_NOTICE([$doconfig])
  eval "$doconfig"
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
          --with-macosx-version-min=10.13 \
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
    eval "$doconfig"
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
    eval "$doconfig"
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
  eval "$doconfig"
  cd "$builddir"
fi

AC_MSG_NOTICE([About to configure libffi])
mkdir -p libffi
case "`uname -s` `uname -m`" in
*Darwin*arm64*)
  cp $abssrcdir/libraries/libffi-for-mac/Makefile libffi
  ;;
*)
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
  eval "$doconfig"
  cd "$builddir"
  ;;
esac

AC_MSG_NOTICE([About to configure libsoftfloat])
mkdir -p softfloat
cd softfloat

if test "x$CC$CPP$CXX$CXXCPP" != "x"
then
  passcc="CC=\"$CC\" CPP=\"$CPP\" CXX=\"$CXX\" CXXCPP=\"$CXXCPP\""
else
  passcc=""
fi
AC_MSG_NOTICE([passcc = $passcc])

# NOTE that there is now a SoftFloat-3e and I should migrate to use of it!

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
eval "$doconfig"

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
eval "$doconfig"

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
eval "$doconfig"

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

printf "All sub-tasks should have completed\n"

# end of configure.ac

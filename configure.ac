AC_INIT([REDUCE], [2016], [acn1@cam.ac.uk])

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
# m4 scripts) but allowed me to continue. So I set 2.61 as my
# baseline since that is better behaved.
#
# Well now it is 2016, and I have moved my reliance on to automake 1.13,
# which was released at the end of 2012. The reason for this move is because
# I wish to use libtool, and full libtool integration and support for
# AC_CONFIG_MACRO_DIRS (please note "DIRS" not "DIR" here) date from then.
# So earlier systems may need a private copy of autoconf installed.
#
# If necessary they can fetch source versions of autoconf and automake and
# install private versions for use here. Following discussions with other
# developers I am now going to require autoconf, automake and libtool
# availability, although an enthusiastic person could probably get things
# working without them.

AC_PREREQ(2.61)

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
#

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

  if ! which libtoolize > /dev/null 2> /dev/null
  then
    printf "You must have libtool installed to build this package. Install\n"
    printf "it and try again please.\n"
    exit 1
  fi

# The next fragment should extract version numbers for autoconf and automake

# I extract versionm infor from the two utilities. The first line of
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
    printf "You have autconf $acmaj.$acmin but at least 2.61 is needed\n"
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
  cd $srcdir
  printf "Regenerate autoconf-related files\n"
  if ! ./autogen.sh $ac_configure_args
  then
    printf "The autogen.sh script seems to have failed. I can not continue\n"
    exit 1
  fi
  cd $here

# It is unexpectedly important the the "--without-autogen" be provided as
# the first argument in the re-try. This is because otherwise some malformed
# input olater on (eg "--") could cause it not to be recognised, leading
# to an infinite cycle of attempted re-generation!
  printf "Restart: $srcdir/configure --without-autogen $ac_configure_args\n"
  exec /bin/sh -c "$srcdir/configure --without-autogen $ac_configure_args"
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

AC_ARG_WITH(crlibm,
  AC_HELP_STRING([--with-crlibm], [Can be used to disable use of crlibm library]),
  [],
  [with_crlibm="yes"])

AC_MSG_NOTICE([with_crlibm = $with_crlibm])

AC_ARG_WITH(boehm,
  AC_HELP_STRING([--with-boehm], [Can be used to disable use of boehm collector]),
  [],
  [with_boehm="no"])

# For now I will insist on an explicit request for this...
AC_MSG_NOTICE([with_boehm = $with_boehm])

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

AC_ARG_WITH(lto,
   AC_HELP_STRING([--with-lto],
                  [Experiment with extreme optimisation in gcc (CSL only)]),
   [],
   [with_lto="no"])

AC_ARG_WITH(m32,
   AC_HELP_STRING([--with-m32],
                  [Force 32-bit model even on 64-bit gcc]),
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
# Further to the above, if I configure ANY Windows version I will also
# ensure that the (raw) cygwin Windows version is configured as well.
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
*CYGWIN*WOW*)
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
  if test "x$host" = "xi686-pc-cygwin"
  then
# building PSL on Windows - need to decide whether to build for 32 or 64bit
    if test "x$with_m32" = "xyes"
    then 
      build="i686-pc-windows"
    elif test "x$with_m64" = "xyes" -o "x$wow64" = "xyes"
    then
      build="x86_64-pc-windows"
    else
      build="i686-pc-windows"
    fi
  else
    build=`eval "$SHELL \"$srcdir/scripts/findhost.sh\" $host"`
  fi
else
  build=`eval "$SHELL \"$srcdir/scripts/findhost.sh\" $host $ac_configure_args"`
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
# Now I am configuring for CSL and am doing so from the top directory. If
# I am on Windows I will configure for variants:
#   i686-pc-cygwin
#   x86_64-pc-cygwin
#   i686-w64-mingw
#   x86_64-w64-mingw
# I will run the configure script for one of those if I have the relevant
# compiler available and if the config.status file where I would build is
# older that my "configure" script. The tests are known to be happening under
# cygwin so I am not going to worry overmuch about general portability issues!
# I also want to know if my platform if the 32 or 64-bit variant of cygwin.
    case `uname -m -o` in
    *i686*Cygwin*)
      cyg32="yes"
      ;;
    *x86_64*Cygwin*)
      cyg64="yes"
      ;;
    esac
    case $build in
    *cygwin* | *windows* | *mingw*)
      if test -x /usr/bin/i686-pc-cygwin-gcc
      then
        have_cyg32="yes"
      else
        have_cyg32="no"
      fi
      if test -x /usr/bin/x86_64-pc-cygwin-gcc
      then
        have_cyg64="yes"
      else
        have_cyg64="no"
      fi
      if test -x /usr/bin/i686-w64-mingw32-gcc
      then
        have_mingw32="yes"
      else
        have_mingw32="no"
      fi
      if test -x /usr/bin/x86_64-w64-mingw32-gcc
      then
        have_mingw64="yes"
      else
        have_mingw64="no"
      fi
      AC_MSG_NOTICE([Compilers: cygwin32:$have_cyg32 cygwin64:$have_cyg64 win32:$have_mingw32 win64:$have_mingw64])
      if test "$have_mingw32" = "no" && test "$have_mingw64" = "no"
      then
        AC_MSG_ERROR(
          [you must have at least one of i686-w64-mingw32-gcc or x86_64-w64-mingw32-gcc])
      fi
# At some stage in the future I very much hope that it will be possible to
# (cross) build both 32 and 64-bit cygwin code from just one of the
# platforms using either platfornm - but at present the 64-bit world does
# not have enough development libraries available to support that. So here
# I will only configure to build both 32 and 64 bit versions if I am
# running on cyg32 but only the 64-bit if I am on cyg64. Well as of February
# 2015 I can not cross-build the wxWidgets version for cyg64 using cyg32...
#
# Note that I will need to coordinte what I do here with the scripts in
# winbuild that arrange to create all possible versions... and I probably
# want an option that will cause this configure scrrip to fall back and make
# just exactly one system.
      if test "x$cyg32" = "xyes"
      then
        if test "x$with_wx" = "xyes"
        then
          cygplatforms="i686-pc-cygwin"
        else
          cygplatforms="i686-pc-cygwin x86_64-pc-cygwin"
        fi
      fi
      if test "x$cyg64" = "xyes"
      then
        cygplatforms="x86_64-pc-cygwin"
      fi
      AC_MSG_NOTICE([cygplatfroms = $cygplatforms])
      for buildmc in $cygplatforms
      do
        build=`eval "$SHELL \"$srcdir/scripts/findhost.sh\" $buildmc $ac_configure_args" --with-cygwin`
        AC_MSG_NOTICE([buildmc=$buildmc => build=$build])
        pass_host=""
        case `uname -m -o` in
        *i686*Cygwin*)
          AC_MSG_NOTICE([i686-Cygwin host building for $buildmc])
          if test "x$buildmc" != "xi686-pc-cygwin"
          then
            pass_host="--host=$buildmc"
          fi
          ;;
        *x86_64*Cygwin*)
          AC_MSG_NOTICE([x86_64-Cygwin host building for $buildmc])
          if test "x$buildmc" != "xx86_64-pc-cygwin"
          then
            pass_host="--host=$buildmc"
          fi
          ;;
        *)
          AC_MSG_NOTICE([non-cygwin host building for $buildmc])
          pass_host="--host=$buildmc"
          ;;
        esac
        AC_MSG_NOTICE([host=$host buildmc=$buildmc pass_host=$pass_host])
        if test -x /usr/bin/$buildmc-gcc ||
           test "x$pass_host" = "x"
        then
          if test "x$with_force" != "xno" ||
             test $abssrcdir/configure -nt $abssrcdir/cslbuild/$build/config.status
          then
            printf "Need to reconfigure for $build\n"
            mkdir -p "$abssrcdir/cslbuild/$build"
            cd "$abssrcdir/cslbuild/$build"
            if test "x$CC$CPP$CXX$CXXCPP" != "x"
            then
              passcc="CC=\"$CC\" CPP=\"$CPP\" CXX=\"$CXX\" CXXCPP=\"$CXXCPP\""
            fi
            AC_MSG_NOTICE([passcc = $passcc])
# If I am running in a cygwin-32 shell and building for cygwin-32, or
# equivalently for cygwin-64, then I do not need to pass "--host" since
# just "gcc" will be what I want to use, rather than "i686-pc-cygwin-gcc"
# or whatever. Indeed on 64-bit cygwin at the time of writing an attempt
# to use the sort of "cross-compile to self" pattern causes build failures,
# so this is more than mere optimisation, it is bug avoidance.
            AC_MSG_NOTICE([host=$host buildmc=$buildmc pass_host=$pass_host])
            pass_build="--with-build=\"$build\" --with-pslbuild=\"$pslbuild\""
            doconfig="$SHELL \"$abssrcdir/configure\" $ac_configure_args \
                    CPPFLAGS=\"$CPPFLAGS\" CFLAGS=\"$CFLAGS\" \
                    CXXFLAGS=\"$CXXFLAGS\" LDFLAGS=\"$LDFLAGS\" LIBS=\"$LIBS\" \
                    $passcc $pass_build $pass_host --with-cygwin"
            AC_MSG_NOTICE([doconfig = $doconfig])
            eval "$doconfig"
            cd "$abssrcdir"
          else
            AC_MSG_NOTICE([Version for $build is already configured])
          fi
        else
          AC_MSG_NOTICE([Compiler for $buildmc not available])
        fi
      done
      cygextra=
      ed32="s/.*windows/i686-pc-cygwin/; s/.*cygwin/i686-pc-cygwin/"
      dd32=`echo $build | sed -e "$ed32"`
      cygextra="--with-cygbuild=$abssrcdir/cslbuild/$dd32"
      ed64="s/.*windows/x86_64-pc-cygwin/; s/.*cygwin/x86_64-pc-cygwin/"
      dd64=`echo $build | sed -e "$ed64"`
      cygextra="$cygextra --with-cygbuild64=$abssrcdir/cslbuild/$dd64"
      AC_MSG_NOTICE([cygextra = $cygextra])
# I will now configure both 32 and 64-bit native windows builds. When
# somebody used "--with-force" this may configure whether you are on a
# 32 or 64-bit version of cygwin, but normally the test to see if the
# configuration has already been done will avoid confusion and
# redundant work. I build the native windows versions whether I am on
# a 32 or 64-bit cygwin. PLEASE do not configure from both 32 and 64-bit
# cygwins in the same tree since then both would prepare to build native
# windows code but the two environments would clash.
      if test "x$cyg32" = "xyes" || test "x$cyg64" = "xyes"
      then
        for buildmc in "i686-w64-mingw32" "x86_64-w64-mingw32"
        do
          build=`eval "$SHELL \"$srcdir/scripts/findhost.sh\" $buildmc $ac_configure_args"`
          if test -x /usr/bin/$buildmc-gcc && test "x$with_cygwin" = "xno"
          then
            if test "x$with_force" != "xno" ||
               test $abssrcdir/configure -nt $abssrcdir/cslbuild/$build/config.status
            then
              printf "Need to reconfigure for $build\n"
              mkdir -p "$abssrcdir/cslbuild/$build"
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
                      $passcc $cygextra $pass_build --host=$buildmc"
              AC_MSG_NOTICE([doconfig = $doconfig])
              eval "$doconfig"
              cd "$abssrcdir"
            else
              AC_MSG_NOTICE([Version for $build is already configured])
            fi
          else
            AC_MSG_NOTICE([Compiler for $buildmc not available])
          fi
        done
      fi
      ;;
    *)
      mkdir -p "$abssrcdir/cslbuild/$build"
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
      ;;
    esac
  fi
  if test "x$with_psl" != "xno"
  then
    AC_MSG_NOTICE([+++ Will build in $abssrcdir/pslbuild/$build])
    if test ! -d "$abssrcdir/pslbuild/$build"
    then
      mkdir -p "$abssrcdir/pslbuild/$build"
    fi
    cd "$abssrcdir/pslbuild/$build"
# This passes down any configure arguments to the PSL-specific configuration
# but at present I do not expect any to be relevant.
    pass_build="--with-build=\"$build\""
    eval "$SHELL \"$abssrcdir/psl/configure\" $ac_configure_args $pass_build"
# I have the configuration for crlibm here as a repeat copy of the code
# used to configure it for use with CSL. This is UGLY but is like this
# because of messy details of how the PSL version is configured here.
# Right now I do not want to write out an explanatio of all the horrid
# details.
    if test "x$with_crlibm" == "xno"
    then
      AC_MSG_NOTICE([crlibm will not be used here])
    else
      AC_MSG_NOTICE([About to configure crlibm])
      builddir=`pwd`
      mkdir -p crlibm
      cd crlibm

      if test "x$CC$CPP$CXX$CXXCPP" != "x"
      then
        passcc="CC=\"$CC\" CPP=\"$CPP\" CXX=\"$CXX\" CXXCPP=\"$CXXCPP\""
      fi
      case $host in
      i386* | i486* | i586* | i686*)
        passcc="$passcc --enable-sse2"
        ;;
      esac
      filter=""
      for x in $ac_configure_args
      do
# The processing here is so that I do not pass CSL or REDUCE-specific
# configuration flags down when configuring crlibm. This then has to have
# a catalogue of all the options I need to ignore. Messy!
        case $x in
        \'--with-force*\' | \
        \'--with*-autogen*\' | \
        \'--with-mingw*\' | \
        \'--with-lto*\' | \
        \'--with-m32*\' | \
        \'--with-m64*\' | \
        \'--with*-gui*\' | \
        \'--with*-xft*\' | \
        \'--with*-xim*\' | \
        \'--with-smallpage*\' | \
        \'--with*-fox*\' | \
        \'--with*-wx*\' | \
        \'--with-cyg*\' | \
        \'--with-csl*\' | \
        \'--with-psl*\' | \
        \'--with-build*\' | \
        \'--with-pslbuild*\' | \
        \'--with*-crlibm*\' | \
        \'--with*-boehm*\' | \
        \'--enable-debug*\' | \
        \'--enable-conservative*\' | \
        \'--enable-test*\' | \
        \'--enable-jit*\' | \
        \'--enable-static*\' | \
        \'--enable-silent*\' | \
        \'--disable-silent*\' )
          ;;
        *)
          filter="$filter $x"
          ;;
        esac
      done
      AC_MSG_NOTICE([passcc = $passcc])
      doconfig="$SHELL \"$abssrcdir/csl/cslbase/crlibm/configure\" $filter \
            $pass_host CPPFLAGS=\"$CPPFLAGS\" CFLAGS=\"$CFLAGS\" \
            CXXFLAGS=\"$CXXFLAGS\" LDFLAGS=\"$LDFLAGS\" $passcc \
            --prefix=\"$builddir\""
      AC_MSG_NOTICE([doconfig = $doconfig])
      eval "$doconfig"
      cd "$builddir"
fi


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

AM_INIT_AUTOMAKE([1.13 -Wno-portability foreign no-dist-gzip dist-bzip2])

AC_CONFIG_FILES([Makefile])

###############################################################################
builddir=`pwd`

if test "x$with_csl" != "xno"
then
# Here I have a bunch of sub-directories that I need to configure

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

# Now at most one of with_wx and with_fox will be "yes". They could both
# be "no".
  if test "x$with_wx" != "xno"
  then
# At one stage I only unpacked a fresh wxWidgets if either one was not
# already unpacked or if the "--with-force" option was set. That may have
# saved some time but it meant that it was necessary to take special
# action when a new revision of wxWidgets got installed upstream. So now
# I will always unpack here. This is still not perfect in that the
# unpacking only happens when somebody does a top level
#   ./configure --with-csl --with-wx
# and generally lower level reconfigurations are not triggered automatically,
# so I will do yet further work to work around that and make things appear
# almost neat. These extra tricks require a file "wxWidgets_revision"
# to be stored in various places...
#   if test ! -d $abssrcdir/csl/wxWidgets || test "x$with_force" != "xno"
#   then
      d=`pwd`
      cd $abssrcdir/csl/support-packages
      a=`echo wxWidgets-v*.tar.bz2`
      a=${a##* }
      b=${a%.tar.bz2}
      cd ..
      printf "will unpack a fresh copy of wxWidgets\n"
      rm -rf wxWidgets
      tar xfj support-packages/$a
      chmod -R +rw wxWidgets-*
      mv wxWidgets-* wxWidgets
# Now I will force all autoconf-related files to be in the correct order.
# This is because I really want to use the versions from the archive, and
# I have seen cases where the default unpacked version triggers an attempt
# to run autoconf/automake again in ways that are costly but what is worse
# do not work on all platforms.
      find . \( -name configure.ac -o -name configure.in \
                -o -name Makefile.am \) -print | xargs touch
      sleep 1
      find wxWidgets -name aclocal.m4 -print | xargs touch
      sleep 1
      find wxWidgets -name configure -print | xargs touch
      find wxWidgets -name configure -print | xargs chmod +x
      sleep 1
      find wxWidgets -name config.h.in -print | xargs touch
      sleep 1
      find wxWidgets -name Makefile.in -print | xargs touch
      cp $abssrcdir/csl/support-packages/wxWidgets_revision wxWidgets
# Now I will force all autoconf-related files to be in the correct order.
# This is because I really want to use the versions from the archive, and
# I have seen cases where the default unpacked version triggers an attempt
# to run autoconf/automake again in ways that are costly but what is worse
# do not work on all platforms.
      find . \( -name configure.ac -o -name configure.in \
                -o -name Makefile.am \) -print | xargs touch
      sleep 1
      find wxWidgets -name aclocal.m4 -print | xargs touch
      sleep 1
      find wxWidgets -name configure -print | xargs touch
      find wxWidgets -name configure -print | xargs chmod +x
      sleep 1
      find wxWidgets -name config.h.in -print | xargs touch
      sleep 1
      find wxWidgets -name Makefile.in -print | xargs touch
      printf "wxWidgets unpacked from archive $a\n"
      cd $d
#   fi
#
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
    doconfig="$SHELL \"$abssrcdir/csl/cslbase/configure\" $ac_configure_args $pass_host --with-wx=\"$with_wx\" $pass_build --without-fox"
  elif test "x$with_fox" != "xno"
  then
    pass_build="--with-build=\"$build\""
    doconfig="$SHELL \"$abssrcdir/csl/cslbase/configure\" $ac_configure_args $pass_host --with-fox=\"$builddir\" --with-fox-pending=yes $pass_build --without-wx"
  else
# This final version will be without any GUI.
    pass_build="--with-build=\"$build\""
    doconfig="$SHELL \"$abssrcdir/csl/cslbase/configure\" $ac_configure_args $pass_host $pass_build --without-fox --without-wx"
  fi
  AC_MSG_NOTICE([$doconfig])
  eval "$doconfig"
  cd "$builddir"

  if test "x$with_wx" != "xno"
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
        CPPFLAGS="$CPPFLAGS -I/usr/include/freetype2 -I/usr/include/ncurses "
        extras="--with-xft --with-xim"
      fi
      ;;
    *Darwin* | *darwin*)
# clang on MacOSX does not provide -mfpmath
#     CFLAGS="$CFLAGS -msse2 -mfpmath=sse"
#     CXXFLAGS="$CXXFLAGS -msse2 -mfpmath=sse"
# For wxWidgets I will ONLY support x86_64, and I will demand at least
# Operating System 10.9 (Mavericks). I believe there were significant
# changes introduces between supporting 10.8 and 10.9 as the lowest
# release and these cause real compilation problems.
      MACARCH="--enable-macos_arch=x86_64" 
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
    cd wxWidgets
# I need --enable-unicode on Windows at least so that I can use the
# BaKoMa fonts which remap at least one TeX glyph to outside the range
# of simple 8-bit characters. This will bring some follow-on pain no doubt
# but addressing that pain is probably good in the long term. 
    if test "x$CC$CPP$CXX$CXXCPP" != "x"
    then
      passcc="CC=\"$CC\" CPP=\"$CPP\" CXX=\"$CXX\" CXXCPP=\"$CXXCPP\""
    fi
    AC_MSG_NOTICE([passcc = $passcc pass_host=$pass_host])
    doconfig="$SHELL \"$abssrcdir/csl/wxWidgets/configure\" $wx \
            $pass_host CPPFLAGS=\"$CPPFLAGS\" CFLAGS=\"$CFLAGS\" \
            CXXFLAGS=\"$CXXFLAGS\" \
            LDFLAGS=\"$LDFLAGS\" $passcc \
            --disable-shared --enable-unicode \
            --disable-compat28 --enable-compat30 \
            --with-png=builtin --without-libjpeg \
            --without-libtiff --with-libsvg=no \
            --with-sdl=no --with-zlib=builtin \
            --without-expat --with-regex=builtin \
            --without-libiconv --with-libz=builtin \
            --with-libpng=builtin --disable-richtext \
            --disable-gif --disable-pcx --enable-graphics_ctx \
            --disable-tga --disable-pnm \
            --disable-svg --prefix=\"$builddir\""
    if test "x$enable_debug" != "xno"
    then
      doconfig="$doconfig --enable-debug"
    fi
    if test "x$with_cygwin" != "xno"
    then
      doconfig="$doconfig --with-gtk --without-msw"
    fi
    AC_MSG_NOTICE([doconfig = $doconfig])
    eval "$doconfig"
    cd "$builddir"
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
            $pass_host --enable-release --with-opengl=no \
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
            $pass_host CPPFLAGS=\"$CPPFLAGS\" CFLAGS=\"$CFLAGS\" \
            CXXFLAGS=\"$CXXFLAGS\" LDFLAGS=\"$LDFLAGS\" $passcc \
            --with-fox=\"$builddir\" --with-fox-pending=yes $extras"
      AC_MSG_NOTICE([doconfig = $doconfig])
      eval "$doconfig"
    fi

    cd "$builddir"
  fi

fi

if test "x$with_crlibm" == "xno"
then
  AC_MSG_NOTICE([crlibm will not be used here])
else
  AC_MSG_NOTICE([About to configure crlibm])
  mkdir -p crlibm
  cd crlibm

  if test "x$CC$CPP$CXX$CXXCPP" != "x"
  then
    passcc="CC=\"$CC\" CPP=\"$CPP\" CXX=\"$CXX\" CXXCPP=\"$CXXCPP\""
  fi
  case $host in
  i386* | i486* | i586* | i686*)
    passcc="$passcc --enable-sse2"
    ;;
  esac
  filter=""
  for x in $ac_configure_args
  do
# The processing here is so that I do not pass CSL or REDUCE-specific
# configuration flags down when configuring crlibm. This then has to have
# a catalogue of all the options I need to ignore. Messy!
    case $x in
    \'--with-force*\' | \
    \'--with*-autogen*\' | \
    \'--with-mingw*\' | \
    \'--with-lto*\' | \
    \'--with-m32*\' | \
    \'--with-m64*\' | \
    \'--with*-gui*\' | \
    \'--with*-xft*\' | \
    \'--with*-xim*\' | \
    \'--with-smallpage*\' | \
    \'--with*-fox*\' | \
    \'--with*-wx*\' | \
    \'--with-cyg*\' | \
    \'--with-csl*\' | \
    \'--with-psl*\' | \
    \'--with-build*\' | \
    \'--with-pslbuild*\' | \
    \'--with*-crlibm*\' | \
    \'--with*-boehm*\' | \
    \'--enable-debug*\' | \
    \'--enable-conservative*\' | \
    \'--enable-test*\' | \
    \'--enable-jit*\' | \
    \'--enable-static*\' | \
    \'--enable-silent*\' | \
    \'--disable-silent*\' )
      ;;
    *)
      filter="$filter $x"
      ;;
    esac
  done
  AC_MSG_NOTICE([passcc = $passcc])
  doconfig="$SHELL \"$abssrcdir/csl/cslbase/crlibm/configure\" $filter \
        $pass_host CPPFLAGS=\"$CPPFLAGS\" CFLAGS=\"$CFLAGS\" \
        CXXFLAGS=\"$CXXFLAGS\" LDFLAGS=\"$LDFLAGS\" $passcc \
        --prefix=\"$builddir\""
  AC_MSG_NOTICE([doconfig = $doconfig])
  eval "$doconfig"

  cd "$builddir"
fi

if test "x$with_boehm" == "xno"
then
  AC_MSG_NOTICE([boehm will not be used here])
else
  AC_MSG_NOTICE([About to configure boehm])
  mkdir -p boehm
  cd boehm

  if test "x$CC$CPP$CXX$CXXCPP" != "x"
  then
    passcc="CC=\"$CC\" CPP=\"$CPP\" CXX=\"$CXX\" CXXCPP=\"$CXXCPP\""
  fi
  filter=""
  for x in $ac_configure_args
  do
# The processing here is so that I do not pass CSL or REDUCE-specific
# configuration flags down when configuring crlibm. This then has to have
# a catalogue of all the options I need to ignore. Messy!
    case $x in
    \'--with-force*\' | \
    \'--with-mingw*\' | \
    \'--with-lto*\' | \
    \'--with-m32*\' | \
    \'--with-m64*\' | \
    \'--with*-gui*\' | \
    \'--with*-xft*\' | \
    \'--with*-xim*\' | \
    \'--with-smallpage*\' | \
    \'--with*-fox*\' | \
    \'--with*-wx*\' | \
    \'--with-cyg*\' | \
    \'--with-csl*\' | \
    \'--with-psl*\' | \
    \'--with-build*\' | \
    \'--with-pslbuild*\' | \
    \'--with*-crlibm*\' | \
    \'--with*-boehm*\' | \
    \'--enable-debug*\' | \
    \'--enable-conservative*\' | \
    \'--enable-test*\' | \
    \'--enable-jit*\' | \
    \'--enable-static*\' | \
    \'--enable-silent*\' | \
    \'--disable-silent*\' )
      ;;
    *)
      filter="$filter $x"
      ;;
    esac
  done
  case $build in
  *windows* | *win32* | *mingw*)
    thr="win32"
    ;;
  *)
    thr="posix"
    ;;
  esac
  AC_MSG_NOTICE([passcc = $passcc])
  doconfig="$SHELL \"$abssrcdir/csl/cslbase/gc-7/configure\" $filter \
        $pass_host \
        CPPFLAGS=\"$CPPFLAGS -DDONT_ADD_BYTE_AT_END=1\" \
        CFLAGS=\"$CFLAGS\" \
        CXXFLAGS=\"$CXXFLAGS\" \
        LDFLAGS=\"$LDFLAGS\" $passcc \
        --prefix=\"$builddir\" \
        --enable-threads=$thr \
        --enable-thread-local-alloc \
        --enable-parallel-mark \
        --without-libatomic-ops"
  AC_MSG_NOTICE([doconfig = $doconfig])
  eval "$doconfig"

  cd "$builddir"
fi

###############################################################################


AM_CONDITIONAL(csl, test "x$with_csl" != "xno")
AM_CONDITIONAL(psl, test "x$with_psl" != "xno")
AM_CONDITIONAL(cslpsl, test "x$with_csl" != "xno" && test "x$with_psl" != "xno")
AM_CONDITIONAL(fox, test "x$with_fox" != "xno")
AM_CONDITIONAL(wx,  test "x$with_wx" != "xno")
AM_CONDITIONAL(crlibm, test "x$with_crlibm" != "xno")

AC_MSG_NOTICE([final output from top level configuration])

AC_OUTPUT

# end of configure.ac


#! /bin/sh

#
# File: "Build-fox-1.6.sh"         A C Norman, Codemist Ltd, 2005-2006
#

#
# Usage:
#
# build-fox [--enable-debug]          enable debug version
#           [--with-xp64]             cross-build for Windows XP 64-bit
#           [--with-mingw64]          semi-native 64-bit Vista build
#           [--with-m32]              force 32-bit build
#           [--with-m64]              force 64-bit build
#           [--with-cygwin]           force cygwin X11 build
#           version                   specify non-default FOX minor version
#           [--arch=triple]           use given triple as location for build


if test "x$SED" = "x"
then
  if test -x /opt/sfw/bin/gsed
  then SED=/opt/sfw/bin/gsed
  elif test -x /usr/local/bin/gsed
  then SED=/usr/local/bin/gsed
  elif test -x /usr/bin/gsed
  then SED=/usr/bin/gsed
  else SED=sed
  fi
  export SED
fi

# I want this script to be one I can launch from anywhere, but at least
# some of its sub-scripts will not be so generous. So find out where it
# lives so that other locations can be found relative to that.

a=$0
c=unknown
case $a in
/* )
  c=$a  
  ;;
*/* )
  case $a in
  ./* )
    a=`echo $a | $SED 's,\./,,'`
    ;;
  esac
  c=`pwd`/$a
  ;;
* ) 
  for d in $PATH
  do
    if test -x $d/$a
    then
      c=$d/$a
    fi
  done
  if test $c = "unknown" ;then
    echo "Unable to find full path for script. Please re-try"
    echo "launching it using a fully rooted path."
    exit 1
  fi
  ;;
esac
here=`echo $c | $SED 's,/[^/]*$,,'`

#
# At times I have build using FOX 1.0.x and 1.1.x. In May 2004
# the official "stable" branch of FOX became the 1.2.x one, while in
# February 2005 it moved on to be 1.4.x: I will now only support 1.6.x.
#

FOX_SERIES="6"

# This selects the minor release number, as in 1.6.1, 1.6.2, 1.6.3, ...
# and I HOPE but can not guarantee that versions of FOX other than the
# one established by default here will all remain compatible.
. ${here}/fox-1.${FOX_SERIES}-version.sh

FOX_VERSION="$FOXVER"


# This script can be passed the flag "--with-xp64" which will cause it to
# assume it is running on cygwin with the Microsoft 64-bit compilers
# set up for cross-compilation! Well actually I will recognize any flag with
# the string "xp64" in it...
#
# Note that getting the Microsoft C compilers and DDK on the PATH and
# having cygwin available too is a somewhat odd configuration and is not
# expected to make sense to casual users.
#
# The flag "--with-cygwin" is also only sensible if building on Windows.
# It disables the normal "-mno-cygwin" usage and so will lead to libraries
# that rely on cygwin1.dll
#
# "--enable-debug" does what you may expect. The library will be put in
# a directory with "-debug" fillowing the machine-triple.
#
# "--arch=dir" gives a name for the directory to put the build
# version of FOX in and this overrides my careful evaluation of my
# environment here.
#
# Any other option is expected to be a FOX version number.
#

xp64="no"
mingw64="no"
m32="no"
m64="no"
real_cygwin="no"
debug_mode="no"
extra_flags=
arch="-"

for fg in $*
do
  case "$fg" in
  --arch=* )
    arch=`echo $fg | $SED 's,--arch=,,'`
    ;;
  *debug* )
    debug_mode="yes"
    extra_flags="$extra_flags --enable-debug"
    ;;
  *xp64* )
    xp64="yes"
    extra_flags="$extra_flags --with-xp64"
    ;;
  *mingw64* )
    mingw64="yes"
    extra_flags="$extra_flags --with-mingw64"
    ;;
  *m32* )
    m32="yes"
    CFLAGS="$CFLAGS -m32"
    export CFLAGS
    CXXFLAGS="$CXXFLAGS -m32"
    export CXXFLAGS
    LDFLAGS="$LDFLAGS -m32"
    export LDFLAGS
    extra_flags="$extra_flags --x-libraries=/usr/X11R6/lib"
    ;;
  *m64* )
    m64="yes"
    CFLAGS="$CFLAGS -m64"
    export CFLAGS
    CXXFLAGS="$CXXFLAGS -m64"
    export CXXFLAGS
    LDFLAGS="$LDFLAGS -m64"
    export LDFLAGS
    extra_flags="$extra_flags --x-libraries=/usr/X11R6/lib64"
    ;;
  *cygwin* )
    real_cygwin="yes"
# When building under Cygwin it appears to be necessary to indicate
# explictly that some of the X related libraries are not to be used.
# This is because headers for those features seem to be present but
# not the corresponding library files....
    extra_flags="$extra_flags --without-shape --without-xshm"
    ;;
  * )
    FOX_VERSION="$fg"
  esac
done



# On Solaris 10 x86 (at least) I need to use gmake rather than make. I have
# not tracked down exactly what the issue is, but the easiest scheme I can
# come up with for now is to test for gmake and if it is available to use it.
# I could have a more elaborate script here but instead I look in a few
# places that are known to be used on Solaris or are otherwise plausible.
# I do this for LOTS of commands! This is TEDIOUS but what it allows is
# for building to happen without needing /usr/swf/bin to be on the $PATH
# on a Solaris 10 system!

if test "x$MAKE" = "x"
then
  if test -x /usr/sfw/bin/gmake
  then MAKE=/usr/sfw/bin/gmake
  elif test -x /usr/local/bin/gmake
  then MAKE=/usr/local/bin/gmake
  elif test -x /usr/bin/gmake
  then MAKE=/usr/bin/gmake
  else MAKE=make
  fi
  export MAKE
fi

if test "x$ACLOCAL" = "x"
then
  if test -x /opt/sfw/bin/aclocal
  then ACLOCAL=/opt/sfw/bin/aclocal
  elif test -x /usr/local/bin/aclocal
  then ACLOCAL=/usr/local/bin/aclocal
  elif test -x /usr/bin/aclocal
  then ACLOCAL=/usr/bin/aclocal
  else ACLOCAL=aclocal
  fi
  export ACLOCAL
fi

if test "x$AUTOM4TE" = "x"
then
  if test -x /opt/sfw/bin/autom4te
  then AUTOM4TE=/opt/sfw/bin/autom4te
  elif test -x /usr/local/bin/autom4te
  then AUTOM4TE=/usr/local/bin/autom4te
  elif test -x /usr/bin/autom4te
  then AUTOM4TE=/usr/bin/autom4te
  else AUTOM4TE=autom4te
  fi
  export AUTOM4TE
fi

if test "x$AUTOCONF" = "x"
then
  if test -x /opt/sfw/bin/autoconf
  then AUTOCONF=/opt/sfw/bin/autoconf
  elif test -x /usr/local/bin/autoconf
  then AUTOCONF=/usr/local/bin/autoconf
  elif test -x /usr/bin/autoconf
  then AUTOCONF=/usr/bin/autoconf
  else AUTOCONF=autoconf
  fi
  export AUTOCONF
fi

if test "x$AUTOMAKE" = "x"
then
  if test -x /opt/sfw/bin/automake
  then AUTOMAKE=/opt/sfw/bin/automake
  elif test -x /usr/local/bin/automake
  then AUTOMAKE=/usr/local/bin/automake
  elif test -x /usr/bin/automake
  then AUTOMAKE=/usr/bin/automake
  else AUTOMAKE=automake
  fi
  export AUTOMAKE
fi

if test "x$INSTALL" = "x"
then
  if test -x /opt/sfw/bin/install
  then INSTALL=/opt/sfw/bin/install
  elif test -x /usr/local/bin/install
  then INSTALL=/usr/local/bin/install
  elif test -x /usr/bin/install
  then INSTALL=/usr/bin/install
  else INSTALL=install
  fi
  export INSTALL
fi

if test "x$mingw64" != "xyes"
then
# I had better be careful wrt compiler tools since for cross compilation
# they will NOT be the simple ones named here!

  if test "x$CC" = "x"
  then
    if test -x /usr/sfw/bin/gcc
    then CC=/usr/sfw/bin/gcc
    elif test -x /usr/local/bin/gcc
    then CC=/usr/local/bin/gcc
    elif test -x /usr/bin/gcc
    then CC=/usr/bin/gcc
    fi
    export CC
  fi

  if test "x$CXX" = "x"
  then
    if test -x /usr/sfw/bin/g++
    then CXX=/usr/sfw/bin/g++
    elif test -x /usr/local/bin/g++
    then CXX=/usr/local/bin/g++
    elif test -x /usr/bin/g++
    then CXX=/usr/bin/g++
    fi
    export CXX
  fi

  if test "x$AR" = "x"
  then
    if test -x /usr/sfw/bin/gar
    then AR=/usr/sfw/bin/gar
    elif test -x /usr/local/bin/gar
    then AR=/usr/local/bin/gar
    elif test -x /usr/bin/gar
    then AR=/usr/bin/gar
    else AR=ar
    fi
    export AR
  fi
fi

original_dir=`pwd`

# There are two specalities here. If I have asked to build a Windows-64
# version I force an artificial machine name "x86_64-pc-windows64". And
# unless I have specifically asked to make a real Cygwin system (in which
# case propagation may be prevented by the GPL libraries cygwin1.dll etc.)
# I map "cygwin" onto "windows" because the "-mno-cygwin" flag will be
# used when compiling. Well now there are three - the mingw64 case is new.

if test $arch != "-"
then
  machine="$arch"
elif test $mingw64 = "yes"
then
  machine="x86_64-pc-mingw32"
elif test $xp64 = "yes"
then
  machine="x86_64-pc-windows64"
else
  machine=`/bin/sh $here/config.guess`
  if test $real_cygwin != "yes"
  then
    machine=`echo $machine | $SED -e 's/cygwin/windows/'`
  fi

# Here I will adjust foxdir to mention the Linux distribution involved
# in case that I can discover that. The effect is that my (adjusted)
# "triple" will be something liek say
#     i686-pc-fedora_6    OR   powerpc-macos_10.4_tiger-darwin8.8.0
# rather than
#     i686-pc=linux-gnu   OR   powerpc-apple-darwin8.8.0

  distrib=`$here/findos.sh`
  echo distrib = $distrib

  if test "x$distrib" != "xunknown"
  then
    machine=`echo $machine | $SED -e s/linux-gnu/$distrib/`
    machine=`echo $machine | $SED -e s/apple/$distrib/`
  fi
fi

if test $arch = "-"
then
  if test $m32 = "yes"
  then
    machine="${machine}-m32"
  else
    if test $m64 = "yes"
    then
      machine="${machine}-m64"
    fi
  fi

  if test $debug_mode = "yes"
  then
    machine="${machine}-debug"
  fi
fi

echo "delete old FOX directory and unpack fresh copy from archive"
# Note that I do not use "tar xfz" since only GNU tar supports the "z" flag

# I put the unpacked FOX sources in the local "fox" directory. I used to put
# them in "/tmp" to save long-term space but maybe this is safer?

echo About to grab FOXDIR given $here and $machine 

FOXDIR=`echo $here | $SED s,/[\^/]\\*\\$,/fox/${machine},`

echo FOXDIR = $FOXDIR

if test -d ${FOXDIR}; then
  echo ${FOXDIR} already exists 
else
  mkdir -p ${FOXDIR}
fi
cd ${FOXDIR}

# Observe that I will build FOX in a directory called something
# line   ..../fox/i686-pc-linux
# where the final directory is a GNU-style triple found by using
# "config.guess". The effect of this is that if I have file-space
# shared between several machines the different machines will build
# FOX in different places: a safe situation. However if the machines
# concerned are similar and all run Linux but use different distributions
# this does not distinguish...

if test -d fox-1.${FOX_SERIES}.${FOX_VERSION}; then
   rm -rf fox-1.${FOX_SERIES}.${FOX_VERSION} 
fi
gunzip -c $here/fox-1.${FOX_SERIES}.${FOX_VERSION}.tar.gz | tar xf -

#
# I apply a set of patches. These ensure that Windows 95 can be supported and
# allow the code to build on a Macintosh under 10.1 with gcc 2.95, where
# otherwise there is (minor) trouble.
#
# I also patch the "configure.in" file so that when I build (as I will
# sometimes here) with cygwin and -mno-cygwin the correct things are
# detected and done: specifically as of FOX 1.6.0 the version of Cygwin
# I have leads to confusion over -lXcursor without my patches.
#
# I really hope that the flexibility of patch copes gracefully with different
# releases of FOX!

cd fox-1.${FOX_SERIES}.${FOX_VERSION}
foxsrc=`pwd`

# These days I will keep the patches file compressed since it is
# RIDICULOUSLY big, mainly because it contains a new version of the
# configure script created by autoconf. I remove the old autoconf output
# before applying patches so that if those files are regenerated in
# the distribution it does not upset me.

rm aclocal.m4 configure
find . -name Makefile.in -print | xargs rm

echo "Apply $here/fox-1.${FOX_SERIES}.patches.gz"

# I rather want to use the GNU version of patch here. On Solaris that tends
# to get installed under the name "gpatch" hance the following test.

if test -x /usr/bin/gpatch
then PATCHPROG="/usr/bin/gpatch"
else
PATCHPROG="patch"
fi

gunzip -c $here/fox-1.${FOX_SERIES}.patches.gz | ${PATCHPROG} -Nlp1

echo "About to configure FOX"
#
# Note that this is intended to be a build just sufficient for my
# CSL/Reduce purposes, and a general purpose installation of FOX
# might include more. I only build static libraries because shipping
# out a system with shared libraries raises extra delicacies.
#

# Note that if the user passed an "--arch=xxx" argument to this script
# the value used will be inspected here...

echo machine = $machine

case $machine in
  *mingw* | *windows* )
     if test "x$mingw64" != "xyes"
     then
       echo "GCC option \"-mno-cygwin\" being used to avoid use GPL libraries."
       CPPFLAGS="$CPPFLAGS -mno-cygwin"
       CFLAGS="$CFLAGS -mno-cygwin"
       CXXFLAGS="$CXXFLAGS -mno-cygwin"
       LDFLAGS="-mwindows"
       export CPPFLAGS CFLAGS CXXFLAGS LDFLAGS
     fi
# Since I have need to run autoconf here I will check that it is
# installed and complain if not.
     if type $ACLOCAL && type $AUTOMAKE && type $AUTOCONF
     then echo re-autoconf everything
          rm -rf aclocal.m4 autom4te.cache Makefile.in configure
          echo aclocal = $ACLOCAL
          $ACLOCAL
          echo automake = $AUTOMAKE
          $AUTOMAKE
          echo autoconf = $AUTOCONF
          $AUTOCONF
          autoconfed="yes"
     else
       echo "On Cygwin/Mingw you must have 'autoconf' installed"
       echo "Please install it and try again."
       exit 1
     fi
     ;;
  *cygwin* )
# Since I have need to run autoconf here I will check that it is
# installed and complain if not.
     if type $ACLOCAL && type $AUTOMAKE && type $AUTOCONF
     then rm -r aclocal.m4 autom4te.cache Makefle.in configure 2>/dev/null
          $ACLOCAL; $AUTOMAKE; $AUTOCONF; autoconfed="yes"
     else
       echo "On Cygwin you must have 'autoconf' installed"
       echo "Please install it and try again."
       exit 1
     fi
     ;;
  *SunOS* | *solaris* )
     echo "Building on SunOS"
     ;;
  *)
     echo "Building on $machine"
     ;;
esac

#
# I have patched "configure.ac" but the patches to it are only relevant in
# the Windows/cygwin case. However patching it has upset its date-stamp.
# I will reset time-stamps on autoconf-related files to ensure that they
# have dates after all others in this directory. This is to prevent
# dependencies in the Makefile from trying to re-create them again when I
# do not want that to happen. Well if autoconf seems to be installed I will
# assume that aclocal and automake are too and use them, which is probably the
# tidiest scheme.
#
if test "x$autoconfed" != "xyes"; then
  if type $ACLOCAL && type $AUTOCONF && type $AUTOMAKE; then
# On some systems there may be multiple versions of the autoxxx tools installed
# and the version invoked could be selected based on files left around. So
# here I delete the old files to avoid them messing anything up. I CERTAINLY
# have an issue of that flavour under cygwin, and CERTAINLY if one tries to use
# old enough versions of automake etc things fail.
    rm -r aclocal.m4 autom4te.cache Makefile.in configure 2>/dev/null
    $ACLOCAL
    $AUTOMAKE
    $AUTOCONF
  else
    echo "autoconf etc not installed: consider installing them please"
    sleep 1
    touch aclocal.m4
    sleep 1
    touch Makefile.in
    sleep 1
    touch configure
  fi
fi

# AC_PROG_CC tends to force CFLAGS to be "-O2 -g" if it is unset, and
# similarly with CXXFLAGS. I view this as "over-helpful" and so ensure that
# the flags variables contain at least a space...

CFLAGS="$CFLAGS "
CXXFLAGS="$CXXFLAGS "
export CFLAGS CXXFLAGS

echo Am at `pwd`

# It is probably worth understanding how to exploit --with-xft to support
# client-side fonts under X, but an initial test of that in October 2004
# shows that the support for Xft within FOX needs further work and reveals
# that compatibility with anything other than a rather recent Linux is
# still a bit delicate.
./configure  $CONFIG_EXTRA $extra_flags --disable-shared --enable-release \
	--with-opengl=no --disable-jpeg --disable-zlib --disable-bz2lib \
	--disable-png --disable-tiff --prefix=${FOXDIR}

echo "About to compile FOX and its test programs"
$MAKE

echo "About to install FOX"
$MAKE install

cd $original_dir

echo " "
echo "FOX 1.${FOX_SERIES}.${FOX_VERSION} should now be up to date"
echo "Note you will have the FOX build-tree left in $foxsrc"
echo "and you can delete it if you are short of disc space."



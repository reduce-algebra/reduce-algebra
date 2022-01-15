#! /bin/sh

# Find name for a directory to build stuff in.
# Usage
#     ./findhost.sh $host <args to ./configure>
# OR  ./findhost.sh $host --short

# The idea here is that I want to name the directory by the Linux
# distribution or other OS variant, and tag on parts that indicate
# key configuration flags. This is necessary because different versions
# even of the same basic system (eg Linux) are not in general mutually
# binary compatible. Things are MUCH better in that respect than they
# were a decade ago, but I can still not be 100% confident that a
# system configured and built on Fedora will run on Ubuntu (or vice versa).
# For the Mac I can not be certain that something built for one release
# of the operating system will be suitable for the previous or next
# release... etc. 

# I want this script to be one I can launch from anywhere, but at least
# some of its sub-scripts will not be so generous. So find out where it
# lives so that other locations can be found relative to that.

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
fi

here="$0";while test -L "$here";do here=`ls -ld "$here" | sed 's/.*-> //'`;done
here=`dirname "$here"`
here=`cd "$here"; pwd -P`

host=$1
shift

case $host in
*apple-darwin*)
  case $* in
  *--enable-universal*)
    host=`echo $host | $SED -e s/x86_64/universal/`
    host=`echo $host | $SED -e s/aarch64/universal/`
    ;;
  esac
  ;;
*)
# The following line may help on FreeBSD where AC_CANONICAL_HOST
# and config.guess apppear to have differing ideas. And in that case
# please remember to use GNU make not the vanilla one.
  host=`echo $host | $SED -e s/amd64/x86_64/`
  ;;
esac

if test "x$1" = "x--short"
then
  variant=`"$here/findos.sh" short`
else
  variant=`"$here/findos.sh"`
fi

# I once tried to do special things for when running under msys
# to use mingw - but I now withdraw that. For a build on Windows
# please run under a cygwin bash shell. Here if the host is a cygwin variant
# I map it to say just "windows" and will tend to end up using a mingw
# compiler. Later on if "--with-cygwin" is set I will unwiind that.
case $host in
x86_64*cygwin* | x86_64*mingw*)
  host="x86_64-pc-windows"
  ;;
*CYGWIN* | *Cygwin* | *cygwin* | *mingw*)
  host="i686-pc-windows"
  ;;
esac

# The exact transformations I apply are a matter of taste, I think. I
# put things in a state that I view as tidy. Specifically instead of
# calling something say i386-pc-linux-gnu I will call it i686-pc-suse103
# or i686-pc-fedora7 indicating a concrete distribution. I want to do
# that because Linux binaries do not guarantee compatibility between
# distributions or even from release to release within a distribution.
# Well things are a LOT better than they used to be, but I still do not
# believe it is perfect. Hence the mere tag "linux-gnu" is inadequate.
#
# I find (HORROR) that different versions of "config.guess" can give
# different results even on a single machine. Specifically on some OpenSuSE
# systems I see x86_64-suse-linux-gnu with some copies of config.guess but
# x86_64-unknown-linux-gnu using others. And there seem to be cases where
# I may see "-pc-" in the middle rather than "-unknown-". This can really
# lead to confusion. so I normalise cases I spot down to "-unknown-" which
# seemd the safest base state to be in. Oh dear what a mess! 

if test "x$variant" != "xunknown"
then
  host=`echo $host | $SED -e s/-suse-linux/-unknown-linux/`
  host=`echo $host | $SED -e s/-pc-linux/-unknown-linux/`
  host=`echo $host | $SED -e s/linux-gnu/$variant/`
  host=`echo $host | $SED -e s/apple/$variant/`
fi

# If the host name as found so far ended up with various unusual characters
# in it that could upset some of my scripts, so I do a little filtering here.
#host=`echo $host | $SED -e 's/[()<>{}[\];&\*?\$]/_/g'`
host=`echo $host | $SED -e 's/[()<>{};&\*?\$|[]/_/g'`
host=`echo $host | $SED -e 's/\]/_/g'`


if test "x$1" = "x--short"
then
  echo $host
  exit 0
fi

debug=
profile=
test=
arithlib=
conservative=
nothrow=
m32=
m64=
nogui=
original=$host
fox=
wx=

# The decoding here is NOT PERFECT and will not be fully compatible with
# all that the configure script does, but it should be sufficient for
# common usage.

for a in $*
do
  case $a in
  --enable-debug=no | --disable-debug)
    debug=
    ;;
  --enable-debug)
    debug=-debug
    ;;
  --enable-profile=no | --disable-profile)
    profile=
    ;;
  --enable-profile)
    profile=-p
    ;;
  --enable-test=no | --disable-test)
    test=
    ;;
  --enable-test*)
    test=-test
    ;;
  --enable-experiment=no | disable-experiment)
    experiment=
    ;;
  --enable-experiment*)
    experiment=-experiment
    ;;
  --with-arithlib=no | --without-arithlib)
    arithlib=
    ;;
  --with-arithlib*)
    arithlib=-arithlib
    ;;
  --enable-conservative=no | --disable-conservative)
    conservative=
    ;;
  --with-throw=no | --without-throw)
    nothrow=-nothrow
    ;;
  --enable-conservative*)
    conservative=-conservative
    ;;
  --with-throw=no | --without-throw)
    nothrow=nothrow
    ;;
  --with-mingw64=no | --without-mingw64)
    host=$original
    ;;
  --with-mingw64*)
    host=x86_64-pc-windows
    ;;
  --with-cygwin=no | --without-cygwin)
    host=$original
    ;;
  --with-cygwin*)
# Here I will map the host identity to signify 32 or 64-bit cygwin
# in a way that I hope will be relevant.
    case $host
    in
    *x86_64*)
      host=x86_64-pc-cygwin
      ;;
    intel-*)
      ;;
    *)
      host=i686-pc-cygwin
      ;;
    esac
    ;;
  --with-m32=no | --without-m32)
    m32=
    ;;
  --with-m32*)
    m32=-m32
    m64=
    ;;
  --with-m64=no | --without-m64)
    m64=
    ;;
  --with-m64*)
    m64=-m64
    m32=
    ;;
  --without-fox | --with-fox=no | --without-wx | --with-wx=no | --without-gui | --with-gui=no)
    fox=
    wx=
    nogui=-nogui
    ;;
  --with-fox*)
    fox=-fox
    wx=
    nogui=
    ;;
  --with-wx*)
    fox=
    wx=-wx
    nogui=
    ;;
  esac
done

echo $host$m32$m64$nogui$fox$wx$test$experiment$arithlib$conservative$nothrow$debug$profile

exit 0

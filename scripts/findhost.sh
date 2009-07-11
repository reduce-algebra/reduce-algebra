#! /bin/sh

# Find name for a directory to build stuff in.
# Usage
#     ./findhost.sh $host <args to ./configure>
# OR  ./findhost.sh $host --short

# The idea here is that I want to name the directory by the Linux
# distribution or other OS variant, and tag on parts that indicate
# key configuration flags. This is necessary because 

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

a=$0
c=unknown
case $a in
/* )
  c=$a  
  ;;
*/* )
  case $a in
  ./* )
    a=`echo $a | $SED -e s+./++`
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

here=`echo $c | $SED -e 's+/[^/]*$++'`

host=$1
shift

case $host in
*apple-darwin*)
# There are TWO things going on here. One is that the GNU script
# "config.guess" seems to have changes recently between reporting i386 and
# i686, so I wan to normalise. The second is that the build for the Mac
# creates a "fat" universal binary that should run on either powerpc or
# Intel Macs, and so to tag the build with one or the other architecture
# may could as clumsy.
  host=`echo $host | $SED -e s/i386/universal/`
  host=`echo $host | $SED -e s/i686/universal/`
  host=`echo $host | $SED -e s/powerpc/universal/`
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
  variant=`$here/findos.sh short`
else
  variant=`$here/findos.sh`
fi

case $host in
*CYGWIN* | *Cygwin* | *cygwin* | *MINGW* | *MinGW* | *Mingw* | *mingw*)
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

if test "x$variant" != "xunknown"
then
  host=`echo $host | $SED -e s/-suse-/-pc-/`
  host=`echo $host | $SED -e s/linux-gnu/$variant/`
  host=`echo $host | $SED -e s/apple/$variant/`
fi

if test "x$1" = "x--short"
then
  echo $host
  exit 0
fi

debug=
m32=
m64=
original=$host

# The decoding here is NOT PERFECT and will not be fully compatible with
# all that the configure script does, but it should be sufficient for
# common usage.

for a in $*
do
  case $a in
  --enable-debug=no)
    debug=
    ;;
  --enable-debug)
    debug=-debug
    ;;
  --with-mingw64=no)
    host=$original
    ;;
  --with-mingw64*)
    host=x86_64-pc-windows
    ;;
  --with-cygwin=no)
    host=$original
    ;;
  --with-cygwin*)
    host=i686-pc-cygwin
    ;;
  --with-m32=no)
    m32=
    ;;
  --with-m32*)
    m32=-m32
    m64=
    ;;
  --with-m64=no)
    m64=
    ;;
  --with-m64*)
    m64=-m64
    m32=
    ;;
  esac
done

echo $host$m32$m64$debug

exit 0

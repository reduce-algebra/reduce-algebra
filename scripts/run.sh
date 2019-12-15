#! /bin/sh
# This is called as
#    run directory-it-is-in appname scriptname args
# args can start with some mix of --nogui, --fox, --wx etc and those
# are used to select a variant of the code to use, so in particular
# --degug will select the (slower) debugging version and some of the
# other options activate experimental development versions.
#
here="$1"
ap="$2"
scr="$3"
shift
shift
shift

while :
do
  case ${1:-nothing} in
  --nogui)
    nogui="-nogui"
    shift
    ;;
  --fox)
    fox="-fox"
    shift
    ;;
  --wx)
    wx="-wx"
    shift
    ;;
  --test)
    test="-test"
    shift
    ;;
  --arithlib)
    arithlib="-arithlib"
    shift
    ;;
  --conservative)
    conservative="-conservative"
    shift
    ;;
  --debug)
    debug="-debug"
    shift
    ;;
  *)
    break
    ;;
  esac
done

version="$nogui$fox$wx$test$arithlib$conservative$debug"

case "x$OS" in
xWindows_NT)
# Here I have three situations that might be relevant:
# (1) I am on a 32-bit Windows
# (2) I am on 64-bit Windows running 32-bit cygwin
# (3) I am running 64-bit cygwin
  case `uname -a` in
  *x86_64*)
# 64-bit cygwin
    c64="64";
    try64="yes"
    ;;
  *WOW*)
# 32-bit cygwin on 64-bit Windows
    c64=""
    try64="no"
    ;;
  *)
# 32-bit Windows
    c64=""
    try64="no";
    ;;
  esac
  pre=""
  if test "x$ap" = "xbootstrapreduce"
  then
    suffix=".exe"
  else
    suffix=".com"
  fi
  xtra=""
  if ! $here/../bin/not-under-cygwin.exe $*
  then
    $here/../bin/cygwin${c64}-isatty.exe $*
    case $? in
    0)
      xtra="--gui"
      ;;
    1)
      pre="cygwin${c64}-"
      suffix=".exe"
      ;;
    *)
      ;;
    esac
  fi

# I put an ordered list of preferences here. I put 64-bit release
# versions first: FOX-based, wxWidgets-based and a version without a GUI
# at all. These (if available) will support large memory and might (I hope)
# run fastest. Failing any of those I try a 32-bit version. If none of those
# are present I try for the same varieties but with debug builds. I will use
# the first of these where I find a built version...
  if test "$try64" = "yes"
  then
    if test "x$cygwin" = "xyes"
    then
      versions="x86_64-pc-cygwin \
                i686-pc-cygwin"
    else
      versions="x86_64-pc-windows \
                i686-pc-windows \
                x86_64-pc-cygwin \
                i686-pc-cygwin"
    fi
  else
      versions="i686-pc-windows \
                i686-pc-cygwin"
  fi
  for hx in $versions
  do
#   echo Try: -x $here/../cslbuild/$hx$version/csl/$pre$ap$suffix
    if test -x $here/../cslbuild/$hx$version/csl/$pre$ap$suffix
    then
      exec $here/../cslbuild/$hx$version/csl/$pre$ap$suffix $xtra $(CSLFLAGS) $*
      exit 0
    fi
  done
# If only a cygwin version has been built this next fragment (which looks
# for eg reduce.exe rather than either cygwin-reduce.exe or reduce.com)
# may sometimes help.
  for hx in $versions
  do
#   echo Try: -x $here/../cslbuild/$hx$version/csl/$ap.exe
    if test -x $here/../cslbuild/$hx$version/csl/$ap.exe
    then
      exec $here/../cslbuild/$hx$version/csl/$ap.exe $xtra $(CSLFLAGS) $*
      exit 0
    fi
  done
  host0="i686-pc-windows"
  host="i686-pc-windows"
  ;;
*)
  host0=`$here/../config.guess`
  host=`$here/findhost.sh $host0`
  if test -x $here/../cslbuild/$host$version/csl/$ap
  then
    exec $here/../cslbuild/$host$version/csl/$ap $(CSLFLAGS) $*
    exit 0
  fi
  ;;
esac

# Here a there does not seem to be a version made for the EXACT operating
# system version that we are running on at present.

echo Failed to find a version of $ap that you have built
echo try "./configure; make" to build one.

exit 1

#! /bin/sh
# This is called as
#    run directory-it-is-in appname scriptname args
# args can start with some mix of --fox, --wx etc and those
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

# If you need to debug this script set the shell variable DEBUG to "yes"
if test "$DEBUG" = "yes"
then
  maybe_echo=echo
else
  maybe_echo=:
fi

# The options here are only really relevent to hard-core CSL hackers. They
# make it possible to launch versions of the system that have been built
# with various experimental and debugging options. There are here to make
# it possible for those who are working on such developments to run their
# special version of the code in a way that makes it easy for them to switch
# between that and the standard version, and hence easy to compare output and
# performance.
while :
do
  $maybe_echo First arg: ${1:-nothing}
  case ${1:-nothing} in
  --debug)
    debug="-debug"
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
  --arithlib)
    arithlib="-arithlib"
    shift
    ;;
  --conservative)
    conservative="-conservative"
    shift
    ;;
  *)
    break
    ;;
  esac
done

version="$fox$wx$arithlib$conservative$debug"

# Note that the shell variable OS is liable to be set to "Windows_NT"
# in a Windows world but it is probably otherwise unset.
case "x$OS" in
xWindows_NT)
# Now I will want to check which variant of reduce to use...
  pre=""
  suffix=".com"

  for x in $*
  do
    $maybe_echo Arg to executable: $x
    if test "$x" = "--nogui" ||
       test "$x" = "-w-" ||
       test "$x" = "-w"
    then
      withgui="no"
      break
    fi
  done
# On Cygwin (and here I have the cygwin64 case) I will behave as follows:
#    --nogui or -w or -w- present on the command line: these indicate
# that a console style use of Reduce is required. So run the explicitly
# cygwin64 variant so it knows how to interact with a cygwin console.
# Also if the --nogui option is not selected so a GUI is requested and
# if DISPLAY is set also use the cygwin64 version that will use X11 for its
# display.
  $maybe_echo withgui=$withgui DISPLAY=$DISPLAY
  if test "$withgui" = "no" || ! test -z "$DISPLAY"
  then
    pre="cygwin64-"
    suffix=".exe"
    cygwin="yes"
# Otherwise the request was for the default behaviour, which is to use
# the GUI, and the Windows-native version should be the one used.
  fi

  $maybe_echo ap=$ap
  if test "x$ap" = "xbootstrapreduce"
  then
    suffix=".exe"
  fi

# If I have built anything using the "new layout" I will try that!
  $maybe_echo test for new dir structure case $here/cslbuild/intel-pc-windows*
  case $here/cslbuild/intel-pc-windows*
  in
  \*)
    ;;
  *)
    pre=""
    suffix=""
    ;;
  esac

# I put an ordered list of preferences here. I put 64-bit release
# versions first: FOX-based, wxWidgets-based and a version without a GUI
# at all. These (if available) will support large memory and might (I hope)
# run fastest. If none of those
# are present I try for the same varieties but with debug builds. I will use
# the first of these where I find a built version...
# I now put "intel-pc-windows" first and that is the name used by my
# "new layout" - when it is in general use I can withdraw a load of the
# rest of the complication that is here!
  $maybe_echo cygwin=$cygwin
  if test "x$cygwin" = "xyes"
  then
    versions="intel-pc-windows \
              x86_64-pc-cygwin"
  else
    versions="intel-pc-windows \
              x86_64-pc-windows \
              x86_64-pc-cygwin"
  fi
  $maybe_echo version=$versions
  for hx in $versions
  do
    $maybe_echo Try: $here/../cslbuild/$hx$version/csl/$pre$ap$suffix
    if test -x $here/../cslbuild/$hx$version/csl/$pre$ap$suffix
    then
      $maybe_echo exec $here/../cslbuild/$hx$version/csl/$pre$ap$suffix $xtra $CSLFLAGS $*
      exec $here/../cslbuild/$hx$version/csl/$pre$ap$suffix $xtra $CSLFLAGS $*
      exit 0
    fi
    $maybe_echo Try: $here/..cslbuild/$hx$version/$pre$ap$suffix
    if test -x $here/../cslbuild/$hx$version/$pre$ap$suffix
    then
      $maybe_echo exec $here/../cslbuild/$hx$version/$pre$ap$suffix $xtra $CSLFLAGS $*
      exec $here/../cslbuild/$hx$version/$pre$ap$suffix $xtra $CSLFLAGS $*
      exit 0
    fi
  done
# If only a cygwin version has been built this next fragment (which looks
# for eg reduce.exe rather than either cygwin-reduce.exe or reduce.com)
# may sometimes help.
  for hx in $versions
  do
    $maybe_echo Try: $here/../cslbuild/$hx$version/csl/$ap.exe
    if test -x $here/../cslbuild/$hx$version/csl/$ap.exe
    then
      $maybe_echo exec $here/../cslbuild/$hx$version/csl/$ap.exe $xtra $CSLFLAGS $*
      exec $here/../cslbuild/$hx$version/csl/$ap.exe $xtra $CSLFLAGS $*
      exit 0
    fi
  done
  ;;
*)
  host0=`$here/../config.guess`
  host=`$here/findhost.sh $host0`
  $maybe_echo if test -x $here/../cslbuild/$host$version/csl/$ap
  if test -x $here/../cslbuild/$host$version/csl/$ap
  then
    $maybe_echo exec $here/../cslbuild/$host$version/csl/$ap $CSLFLAGS $*
    exec $here/../cslbuild/$host$version/csl/$ap $CSLFLAGS $*
    exit 0
  else
    host1=`echo $host | sed 's/aarch64/universal/'`
    host1=`echo $host1 | set 's/x86_64/universal/'`
    $maybe_echo host=$host host1=$host1
    if test -x $here/../cslbuild/$host1$version/csl/$ap
    then
      $maybe_echo exec $here/../cslbuild/$host1$version/csl/$ap $CSLFLAGS $*
      exec $here/../cslbuild/$host1$version/csl/$ap $CSLFLAGS $*
      exit 0
    fi
  fi
  ;;
esac

# Here a there does not seem to be a version made for the EXACT operating
# system version that we are running on at present.

echo Failed to find a version of $ap that you have built
echo try "./configure; make" to build one.

exit 1

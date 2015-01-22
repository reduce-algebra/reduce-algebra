#! /bin/sh
# This is called as
#    run directory-it-is-in appname scriptname args
here="$1"
ap="$2"
scr="$3"
shift
shift
shift
case "x$OS" in
xWindows_NT)
# Here I have three situations that might be relevant:
# (1) I am on a 32-bit Windows
# (2) I am on 64-bit Windows running 32-bit cygwin
# (3) I am running 64-bit cygwin
# and coupled with that the user may have specified "--cygwin" on the command
# line.
  case $* in
  *--cygwin*)
    cygwin="yes"
    notcygwin="no"
    ;;
  *)
    cygwin="no"
    notcygwin="yes"
    ;;
  esac
  case `uname -a` in
  *x86_64*)
# 64-bit cygwin
    c64="64";
    try64="yes"
    ;;
  *WOW64*)
# 32-bit cygwin on 64-bit Windows
    c64=""
    try64="$notcygwin"
    ;;
  *)
# 32-bit Windows
    c64=""
    try64="no";
    ;;
  esac
  pre=""
  suffix=".com"
  xtra=""
  if test "x$cygwin" = "xyes"
  then
    suffix=".exe"
  else
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
      versions="x86_64-pc-cygwin x86_64-pc-cygwin-wx \
            x86_64-pc-cygwin-nogui \
            x86_64-pc-cygwin-debug x86_64-pc-window-wx-debug \
            x86_64-pc-cygwin-nogui-debug"
    else
      versions="x86_64-pc-windows x86_64-pc-windows-wx \
            x86_64-pc-windows-nogui \
            i686-pc-windows i686-pc-window-wx i686-pc-windows-nogui \
            x86_64-pc-windows-debug x86_64-pc-window-wx-debug \
            x86_64-pc-windows-nogui-debug \
            i686-pc-windows-debug i686-pc-windows-wx-debug \
            i686-pc-windows-nogui-debug"
    fi
  else
    if test "x$cygwin" = "xyes"
    then
      versions="i686-pc-cygwin i686-pc-cygwin-wx i686-pc-cygwin-nogui \
            i686-pc-cygwin-debug i686-pc-cygwin-wx-debug \
            i686-pc-cygwin-nogui-debug"
    else
      versions="i686-pc-windows i686-pc-window-wx i686-pc-windows-nogui \
            i686-pc-windows-debug i686-pc-windows-wx-debug \
            i686-pc-windows-nogui-debug"
    fi
  fi
  for hx in $versions
  do
#   echo Try: -x $here/../cslbuild/$hx/csl/$pre$ap$suffix
    if test -x $here/../cslbuild/$hx/csl/$pre$ap$suffix
    then
      exec $here/../cslbuild/$hx/csl/$pre$ap$suffix $xtra $*
      exit 0
    fi
  done
  if test "x$cygwin" = "xyes"
  then
    if test "x$try64" = "xyes"
    then
      host0="i686-pc-cygwin"
      host="i686-pc-cygwin"
    else
      host0="x86_64-pc-cygwin"
      host="x86_64-pc-cygwin"
    fi
  else
    host0="i686-pc-windows"
    host="i686-pc-windows"
  fi
  ;;
*)
  host0=`$here/../config.guess`
  host=`$here/findhost.sh $host0`
  for hx in "" "-debug" "-m32" "-m32-debug" "-m64" "-m64-debug" \
            "-nogui" "-nogui-debug" "-m32-nogui" "-m32-nogui-debug" \
            "-m64-nogui" "-m64-nogui-debug"
  do
    if test -x $here/../cslbuild/$host$hx/csl/$ap
    then
      exec $here/../cslbuild/$host$hx/csl/$ap $*
      exit 0
    fi
  done
  ;;
esac

# Here a there does not seem to be a version made for the EXACT operating
# system version that we are running on at present.

echo Failed to find a version of $ap that you have built
echo try "./configure; make" to build one.

exit 1

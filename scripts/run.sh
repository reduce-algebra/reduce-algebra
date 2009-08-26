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
  for hx in "x86_64-pc-windows" "x86_64-pc-windows-debug" "i686-pc-windows" "i686-pc-windows-debug"
  do
    if test -x $here/../cslbuild/$hx/csl/$ap.com
    then
      exec $here/../cslbuild/$hx/csl/$ap.com $*
      exit 0
    fi
    if test -x $here/../cslbuild/$hx/csl/$ap.exe
    then
      exec $here/../cslbuild/$hx/csl/$ap.exe $*
      exit 0
    fi
  done
  host0="i686-pc-windows"
  host="i686-pc-windows"
  ;;
*)
  host0=`$here/../config.guess`
  host=`$here/findhost.sh $host0`
  for hx in "" "-debug" "-m32" "-m32-debug" "-m64" "-m64-debug"
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
# system version that we are running on at present. So to try to be kind I
# will try to see if there is one for a version that may be related. In this
# case "related" should mean using the same CPU (eg as in i686 vs x86_64)
# and with the same "OS vendor" (eg debian, ubuntu, fedora etc). The effect
# is intended to be that if you have installed say a version intended for
# ubuntu 8.10 while in fact you are now running ubuntu 9.04 then things
# will work. But because there is a potential conflict here (eg a version
# built for fedora 9 might now work on fedora 2) I will display an alert 
# about the possible issue. Furthermore in this case (because I would like
# you to install a version exactly matching your operating system) I will
# not update the run script and so will do the tedious search every time.

host1=`$here/findhost.sh $host0 --short`
for hx in $here/../cslbuild/${host1}*
do
  if test -x $hx/csl/$ap
  then
    hx1=`echo $hx | sed -e 's+.*/++'`
    echo "You are running $host but the nearest match"
    echo "I can find was built for $hx1. I will try"
    echo "it, but if there are problems you need to compile"
    echo "a version for yourself using \"./configure; make\"".
    exec $hx/csl/$ap $*
    exit 0
  fi
done

echo Failed to find a version of $ap that you have built
echo try "./configure; make" to build one.

exit 1

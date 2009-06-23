#! /bin/sh

# This is used to try to run a program, allowing for the fact
# that possibly many architectures have been built in the tree.

# This is called as
#    run appname scriptname args

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
    a=`echo $a | sed -e s+./++`
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

here=`echo $c | sed -e 's+/[^/]*$++'`

ap="$1"
scr="$2"
shift
shift

host0=`$here/../config.guess`
host=`$here/findhost.sh $host0`

# If I am on a Windows machine and I have built a Windows-64 system
# I should try that too. On windows the "-m32" and "-m64" flags do
# not apply.

mkdir -p $here/../bin

if test "x$host" = "xi686-pc-windows"
then
  for hx in "x86_64-pc-windows" "x86_64-pc-windows-debug" "i686-pc-windows" "i686-pc-windows-debug"
  do
    if test -x $here/../cslbuild/$hx/csl/$ap.com
    then
      bin="$here/../cslbuild/$hx/csl/$ap.com"
      binw=`cygpath -w $bin`
      rm -f $here/../bin/$ap
      ln -s -f $bin $here/../bin/$scr
      rm -f $here/../bin/$scr.bat
      echo $binw %\* > $here/../bin/$scr.bat
      exec $bin $*
      exit 0
    fi
    if test -x $here/../cslbuild/$hx/csl/$ap.exe
    then
      bin="$here/../cslbuild/$hx/csl/$ap.exe"
      binw=`cygpath -w $bin`
      rm -f $here/../bin/$ap
      ln -s -f $bin $here/../bin/$scr
      rm -f $here/../bin/$scr.bat
      echo $binw %\* > $here/../bin/$scr.bat
      exec $bin $*
      exit 0
    fi
  done
else
  for hx in "" "-debug" "-m32" "-m32-debug" "-m64" "-m64-debug"
  do
    if test -x $here/../cslbuild/$host$hx/csl/$ap
    then
      bin="$here/../cslbuild/$host$hx/csl/$ap"
      rm -f $here/../bin/$scr
      ln -s -f $bin $here/../bin/$scr
      exec $bin $*
      exit 0
    fi
  done

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
      bin="$hx/csl/$ap"
#     rm -f $here/../bin/$scr
#     ln -s -f $bin $here/../bin/$scr
      exec $bin $*
      exit 0
    fi
  done

fi

echo Failed to find a version of $ap that you have built
echo try "./configure; make" to build one.

exit 0


#! /bin/sh -v

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
    a=${a#./}
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

here=${c%/*}

ap="$1"
scr="$2"
shift
shift

host=`$here/../config.guess`
host=`$here/findhost.sh $host`

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
      ln -s $bin $here/../bin/$scr
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
      ln -s $bin $here/../bin/$scr
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
      ln -s $bin $here/../bin/$scr
      exec $bin $*
      exit 0
    fi
  done
  exit 0
fi

echo Failed to find a version of $ap that you have built
echo try "./configure; make" to build one.

exit 0


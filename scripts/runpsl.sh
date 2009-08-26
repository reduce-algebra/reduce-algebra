#! /bin/sh


# This is used to try to run a program, allowing for the fact
# that possibly many architectures have been built in the tree.

# This is called as
#    run appname scriptname args

# apname is bpsl scriptname will be redpsl. These are not at present
# actually varied ever!

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

host=`$here/../config.guess`
host=`$here/findhost.sh $host`

mkdir -p $here/../bin

if test "x$host" = "xi686-pc-windows"
then
  for hx in "i686-pc-windows" "i686-pc-windows-debug"
  do
    if test -x $here/../pslbuild/$hx/psl/$ap.exe
    then
      bin="$here/../pslbuild/$hx/psl/$ap.exe"
      binw=`cygpath -w $bin`
      img=`cygpath -m $here/../pslbuild/$hx/red/reduce.img`
#     rm -f $here/../bin/$scr
#     echo "exec $bin -td 16000000 -f $img \$*" > $here/../bin/$scr
#     chmod +x $here/../bin/$scr
      exec $bin -td 16000000 -f $img $*
      exit 0
    fi
  done
else
  for hx in "" "-debug" "-m32" "-m32-debug" "-m64" "-m64-debug"
  do
    if test -x $here/../pslbuild/$host$hx/psl/$ap
    then
      STORE=16000000
      if test -f $here/../pslbuild/$host$hx/psl/64
      then
        STORE=2000
      fi
      bin="$here/../pslbuild/$host$hx/psl/$ap"
#     rm -f $here/../bin/$scr
#     echo "exec $bin -td $STORE -f $here/../pslbuild/$host$hx/red/reduce.img \$*" > $here/../bin/$scr
#     chmod +x $here/../bin/$scr
      exec $bin -td $STORE -f $here/../pslbuild/$host$hx/red/reduce.img $*
      exit 0
    fi
  done
fi

echo Failed to find a version of $ap that you have built
echo try "./configure --with-psl; make" to build one.

exit 0


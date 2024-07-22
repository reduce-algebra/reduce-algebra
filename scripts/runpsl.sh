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

here="$0";while test -L "$here";do here=`ls -ld "$here" | sed 's/.*-> //'`;done
here=`dirname "$here"`
here=`cd "$here"; pwd -P`

ap="$1"
scr="$2"
shift
shift

host=`$here/../config.guess`
host=`$here/findhost.sh $host`

case `uname -a` in
  *Darwin*arm64*)
    echo "Sorry, PSL Reduce is not supported on ARM based Macs"
    exit 1
    ;;
esac

mkdir -p $here/../bin

if test "x$host" = "xi686-pc-windows" || test "x$host" = "xx86_64-pc-windows"
then
  case `uname -a` in
  *CYGWIN*WOW* | *CYGWIN*x86_64*)
    pathlist="x86_64-pc-windows x86_64-pc-windows-debug i686-pc-windows i686-pc-windows-debug"
    ;;
  *)
    pathlist="i686-pc-windows i686-pc-windows-debug"
    ;;
  esac
  for hx in $pathlist
  do
    if test -x $here/../pslbuild/$hx/psl/$ap.exe
    then
      if test -f $here/../pslbuild/$hx/psl/64
      then
        STORE=$($here/pslmem64.sh)
      else
        STORE=$($here/pslmem32.sh)
      fi
      bin="$here/../pslbuild/$hx/psl/$ap.exe"
      binw=`cygpath -w $bin`
      img=`cygpath -m $here/../pslbuild/$hx/red/reduce.img`
      export fasl="$here/../pslbuild/$host$hx/red"
      export reduce="$here/.."
#     rm -f $here/../bin/$scr
#     echo "exec $bin -td 16000000 -f $img \$*" > $here/../bin/$scr
#     chmod +x $here/../bin/$scr
      exec $bin -td $STORE -f $img $PSLFLAGS $*
      exit 0
    fi
  done
else
  for hx in "" "-debug" "-m32" "-m32-debug" "-m64" "-m64-debug"
  do
    if test -x $here/../pslbuild/$host$hx/psl/$ap
    then
      if test -f $here/../pslbuild/$host$hx/psl/64
      then
        STORE=$($here/pslmem64.sh)
      else
        STORE=$($here/pslmem32.sh)
      fi
      bin="$here/../pslbuild/$host$hx/psl/$ap"
      export fasl="$here/../pslbuild/$host$hx/red"
      export reduce="$here/.."
#     rm -f $here/../bin/$scr
#     echo "exec $bin -td $STORE -f $here/../pslbuild/$host$hx/red/reduce.img \$*" > $here/../bin/$scr
#     chmod +x $here/../bin/$scr
#     printf "here = %s\n"
      if ! ulimit -s unlimited 2> /dev/null
# The Macintosh (at least) rejects an attempt to set an unlimited stack
# size, and can only ever decrease an existing limit. So I try a range
# of sizes here and use the largest where ulimit seems to succeed.
      then
        if ! ulimit -s 65000 2> /dev/null
        then
          if ! ulimit -s 32000 2> /dev/null
          then
            ulimit -s 16000 2> /dev/null
          fi
        fi
      fi
      exec $bin -td $STORE -f $here/../pslbuild/$host$hx/red/reduce.img $PSLFLAGS $*
      exit 0
    fi
  done
fi

echo Failed to find a version of $ap that you have built
echo try "./configure --with-psl; make" to build one.

exit 0


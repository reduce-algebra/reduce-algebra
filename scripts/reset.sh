#! /bin/sh

# Reset a file in "bin" to its generic state

if test "x$1" = "x"
then
   echo "Usage: scripts/reset.sh appname"
   echo "resets that application to a generic state"
   exit 1
fi

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

mkdir -p $here/../bin

rm -f $here/../bin/$1 $here/../bin/$1-s
cp $here/here0.sh $here/../bin/$1
cp $here/here0.sh $here/../bin/$1-s

case $1 in
redcsl)
  echo "exec \$here/scripts/run.sh \$here/scripts reduce $1 \$*" >> $here/../bin/$1
  echo "exec \$here/scripts/run.sh \$here/scripts reduce $1 \$*" >> $here/../bin/$1-s
  ;;
redpsl)
  echo "exec \$here/scripts/runpsl.sh bpsl $1 \$*" >> $here/../bin/$1
  echo "exec \$here/scripts/runpsl.sh bpsl $1 \$*" >> $here/../bin/$1-s
# redpslw and redpsl2-s are only relevant on windows when launching from
# a cygwin shell, I think!
  cp $here/here0.sh $here/../bin/$1w
  cp $here/here0.sh $here/../bin/$1w-s
  echo "exec \$here/scripts/runpsl.sh bpslw $1 \$*" >> $here/../bin/$1w
  echo "exec \$here/scripts/runpsl.sh bpslw $1 \$*" >> $here/../bin/$1w-s
  ;;
*)
  echo "exec \$here/scripts/run.sh \$here/scripts $1 $1 \$*" >> $here/../bin/$1
  echo "exec \$here/scripts/run.sh \$here/scripts $1 $1 \$*" >> $here/../bin/$1-s
  ;;
esac


chmod +x $here/../bin/$1 $here/../bin/$1-s

case $1 in
redpsl)
  rm -f $here/../bin/redpsl.bat $here/../bin/redpslw.bat
  cp $here/redpsl.bat $here/../bin
  cp $here/redpslw.bat $here/../bin
  rm -f $here/../bin/redpsl-s.bat $here/../bin/redpslw-s.bat
  cp $here/redpsl.bat $here/../bin/redpsl-s.bat
  cp $here/redpslw.bat $here/../bin/redpslw-s.bat
  ;;
redcsl)
  rm -f $here/../bin/redcsl.bat
  cp $here/redcsl.bat $here/../bin
  rm -f $here/../bin/redcsl-s.bat
  cp $here/redcsl.bat $here/../bin/redcsl-s.bat
  ;;
*)
  rm -f $here/../bin/$1.bat
  cp $here/run.bat $here/../bin/$1.bat
  rm -f $here/../bin/$1-s.bat
  cp $here/run.bat $here/../bin/$1-s.bat
  ;;
esac

exit 0


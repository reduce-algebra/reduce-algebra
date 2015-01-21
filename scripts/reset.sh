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

here=`dirname "$0"`
here=`cd "$here" ; pwd`

mkdir -p $here/../bin

rm -f $here/../bin/$1
cp $here/here0.sh $here/../bin/$1

case $1 in
redcsl)
  echo "exec \$here/scripts/run.sh \$here/scripts reduce $1 \$*" >> $here/../bin/$1
  ;;
redpsl)
  echo "exec \$here/scripts/runpsl.sh bpsl $1 \$*" >> $here/../bin/$1
  echo "exec \$here/scripts/runpsl.sh bpslw $1 \$*" >> $here/../bin/$1w
  ;;
*)
  echo "exec \$here/scripts/run.sh \$here/scripts $1 $1 \$*" >> $here/../bin/$1
  ;;
esac


chmod +x $here/../bin/$1

case $1 in
redpsl)
  rm -f $here/../bin/redpsl.bat $here/../bin/redpslw.bat
  cp $here/redpsl.bat $here/../bin
  cp $here/redpslw.bat $here/../bin
  ;;
redcsl)
  rm -f $here/../bin/redcsl.bat
  cp $here/redcsl.bat $here/../bin
  ;;
*)
  rm -f $here/../bin/$1.bat
  cp $here/run.bat $here/../bin/$1.bat
  ;;
esac

exit 0


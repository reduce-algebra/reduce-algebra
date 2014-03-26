#! /bin/bash

# ./makebin.sh clean dir host args
#
# This configures and then builds versions of Reduce: clean if (clean)
# in directory (dir) for host system (host) passing extra information
# from (args) to the configure step.

# Eg
#        ./makebin.sh yes win32 i686-w64-mingw32 --with-cygbuild32=... [etc]
# or     ./makebin.sh no cyg32 i686-pc-cygwin --with-cygwin

# I will speed up building by using this many parallel tasks. On my
# home computer I can use 8 tasks and the total rebuild of all four
# Reduce varients ends up taking a bit over 10 minutes.

NCPUS=8

clean=${1:-yes}
dir=${2:-w32}
host=${3:-i686-w64-mingw32}
shift 3
args=$*

here=`cygpath -a .`

if test "x$clean" = "xyes"
then
  rm -rf $here/$dir
  mkdir $here/$dir
fi

cd $here/$dir

if test "x$clean" = "xyes"
then
  $here/../../configure --with-csl --host=$host $args

  cd fox
  make -j$NCPUS install
  cd ..

  cd crlibm
  make -j$NCPUS install
  cd ..

fi
cd ../csl
make -j$NCPUS csl.exe
make -j$NCPUS bootstrapreduce.exe
make -j$NCPUS reduce.exe
make

cd $here

exit 0

#! /bin/bash

# ./makebin.sh dir host args
#
# This configures and then builds fresh clean versions of Reduce
# in directory (dir) for host system (host) passing extra information
# from (args) to the configure step.

# Eg
#        ./makebin.sh win32 i686-w64-mingw32 --with-cygbuild32=... [etc]
# or     ./makebin.sh cyg32 i686-pc-cygwin --with-cygwin

# I will speed up building by using this many parallel tasks. On my
# home computer I can use 8 tasks and the total rebuild of all four
# Reduce varients ends up taking a bit over 10 minutes.

NCPUS=8

dir=${1:-w32}
host=${2:-i686-w64-mingw32}
shift 2
args=$*

here=`cygpath -a .`

rm -rf $here/$dir
mkdir $here/$dir

cd $here/$dir
$here/../../configure --with-csl --host=$host $args

cd fox
make -j$NCPUS install

cd ../crlibm
make -j$NCPUS install

cd ../csl
make -j$NCPUS csl.exe
make -j$NCPUS bootstrapreduce.exe
make -j$NCPUS reduce.exe
make

cd $here

exit 0

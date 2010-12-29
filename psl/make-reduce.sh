#!/bin/sh 
#
#  usage  make-reduce.sh <PSL_name> <generic_name>
#
#  Prerequisites:  configure of the generic system
#                  cd psl ; ./make-psl.sh      for the PSL system
#
# as default the names are 'guessed' like the configured system
#
host=`../config.guess`
variant=`../scripts/findos.sh`

if test "x$variant" != "xunknown"
 then
   host=`echo $host | sed  -e s/-suse-linux/-unknown-linux/`
   host=`echo $host | sed -e s/-pc-linux/-unknown-linux/`
   host=`echo $host | sed -e s/linux-gnu/$variant/`
   host=`echo $host | sed -e s/apple/$variant/`
 fi

if test "x$2" != "x"
  then
    host=$2
 fi

guess=`../config.guess`

if test $guess = "x86_64-unknown-linux-gnu"
 then
        export MACHINE=AMD64
fi

if test $guess = "x86_64-apple-darwin10.4.0"
 then
        export MACHINE=macintel64
fi

if test $guess = "x86_64-apple-darwin10.5.0"
 then
        export MACHINE=macintel64
fi

if test $guess = "i386-apple-darwin10.4.0"
 then
        export MACHINE=macintel
fi

if test $guess = "i686-pc-linux-gnu"
 then
        export MACHINE=linux

fi

echo
echo "PSL REDUCE is made for " $MACHINE " from " $host
echo
 
cd ../pslbuild
mkdir $MACHINE
cd $MACHINE
mkdir psl
mkdir red
cp -r ../$host/xport .
cp -r ../$host/deps .
cp -r ../$host/conf* .
mkdir buildlogs
cp -r ../$host/Makefile .
cp ../../psl/dist/nonkernel/$MACHINE/lap/* psl
cp ../../psl/dist/lap/$MACHINE/* psl
cp ../../psl/dist/kernel/$MACHINE/bpsl psl/
rm -f red/*.img
touch ../../psl/mkreduce
cp psl/nbig32.b psl/zbig.b
rm -f psl/*rlisp*.b
make
cat > redpsl << EOF
#
`pwd`/psl/bpsl -td 500 -f `pwd`/red/reduce.img

EOF
chmod +x redpsl


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


case "guess:$guess" in

  guess:x86_64-unknown-linux-gnu )
        MACHINE=AMD64_ext
        ;;

  guess:i686-pc-linux-gnu )
	MACHINE=linux
	;;

  guess:i386-apple-darwin* )
	MACHINE=macintel
	;;

  guess:x86_64-apple-darwin* )
	MACHINE=macintel64
	;;

  x86_64-unknown-freebsd8.* | guess:amd64-unknown-freebsd* )
	MACHINE=freeBSD64
	;;

  i386-unknown-freebsd8.* )
	MACHINE=freeBSD
	;;

  guess:i686-pc-cygwin )
	MACHINE=win32
	test "$BPSL_CYGDRIVE_PREFIX" = "" && export BPSL_CYGDRIVE_PREFIX=/cygdrive
	# get windows path of current dir and try to cd to /cygdrive version
	CURDIR=`cygpath -a -m . | sed -e 's/^\(.\):/\/cygdrive\/\1/'`
	cd "$CURDIR"
	;;

  guess:x86_64-unknown-cygwin )
	MACHINE=mingw-w64
	test "$BPSL_CYGDRIVE_PREFIX" = "" && export BPSL_CYGDRIVE_PREFIX=/cygdrive
	# get windows path of current dir and try to cd to /cygdrive version
        CURDIR=`cygpath -a -m . | sed -e 's/^\(.\):/\/cygdrive\/\1/'`
        cd "$CURDIR"
	;;

  guess:armv6l-unknown-linux* )
	MACHINE=armv6
	;;

  guess:aarch64-unknown-linux* )
	MACHINE=aarch64
	;;


esac

export MACHINE

echo
echo "PSL REDUCE is made for " $MACHINE " from " $host
echo
 
cd ../pslbuild
cd $MACHINE
make

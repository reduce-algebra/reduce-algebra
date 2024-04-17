#!/bin/sh 
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
#    * Redistributions of source code must retain the relevant copyright
#      notice, this list of conditions and the following disclaimer.
#    * Redistributions in binary form must reproduce the above copyright
#      notice, this list of conditions and the following disclaimer in the
#      documentation and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
# THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR
# CONTRIBUTORS
# BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#
# $Id$
#
##############################################################################
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
        MACHINE=AMD64
        ;;

  guess:amd64-unknown-openbsd* )
        MACHINE=AMD64_openbsd
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

  guess:aarch64-apple-darwin* )
        MACHINE=macaarch64
        ;;

  guess:x86_64-unknown-freebsd* | guess:amd64-unknown-freebsd* )
	MACHINE=freeBSD64
	;;

  guess:i386-unknown-freebsd* | guess:i586-unknown-freebsd*)
	MACHINE=freeBSD
	;;

  guess:aarch64-unknown-freebsd*)
	MACHINE=FreeBSD_aarch64
	;;

esac

if test "x$1" != "x"
  then
      MACHINE=$1
 fi

export MACHINE


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
if test "../../psl/dist/kernel/$MACHINE/bpsl" -nt "red/bootstrap.img"
   then
    rm red/bootstrap.img
fi
touch ../../psl/mkreduce
cp psl/nbig32.b psl/zbig.b
rm -f psl/*rlisp*.b
make
cat > redpsl << EOF
#
`pwd`/psl/bpsl -td 500 -f `pwd`/red/reduce.img

EOF
chmod +x redpsl


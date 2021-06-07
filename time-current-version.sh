#! /bin/bash

# This builds Reduec from the most up to date subversion revision
# and runs the test scripts. It puts a copy of the output from the
# testing in a file "red-REVISION:DATE.log"
#
# If invoked with an argument "profile" it will re-profile the CSL
# version of Reduce before collecting the timings.
# If given "fetch" it will bring the current sources into step with the
# sourceforge repository before doing anything. Even though I generally want
# to measure a sourcefore version I make the default behaviour without
# "fetch" be to avoid overwriting current local changes.
# "nopsl" is for use on platforms where the PSL version is not available.
#
# The above options can be given in any order and with or without prefixed
# "-" or "--". In fact the decoding is very crude indeed so any argument with
# those strings of letters included will be acted upon.
#
# HOWEVER in ALL cases this will remove and rebuild the cslbuild and
# pslbuild directories.


P=""
F=""
NOPSL="--csl --psl"

case "$*" in
*profile*)
  P="P"
  ;;
esac
case "$*" in
*fetch*)
  F="F"
  ;;
esac
case "$*" in
*nopsl*)
  NOPSL="--csl"
  ;;
esac

if test "$F" = "F"
then
  svn -R revert .
  svn update
fi

rm -rf cslbuild pslbuild
./autogen.sh
( ./configure --without-autogen --with-csl
  for d in cslbuild/*-*-*
  do
    cd $d/fox; make -j `nproc` install
    cd ../crli*; make -j `nproc` install
    cd ../libffi*; make -j `nproc` install
    cd ../soft*; make -j `nproc` install
    cd ../csl
    make -j `nproc` bootstrapreduce
    cd ../../..
  done
  cd `ls cslbuild/*/csl | head -1` && \
    make -j `nproc` standard-c-code && \
    cd ../../.. 
  make -j `nproc` reduce.img ) &
CSL=$!
case "$NOPSL" in
*psl*)
  ./configure --without-autogen --with-psl
  make psl
  ;;
esac
wait $CSL

if test "$P" = "P"
then
  make profile
  make reduce.img
fi

script -c "time scripts/testall.sh --noregressions $NOPSL" \
   red-`scripts/revision.sh`$P:`date +%y-%m-%d`.log

printf "Data collected\n"
exit 0

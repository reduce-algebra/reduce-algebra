#! /bin/bash -v

export PROOT=`pwd`
export MACHINE=macintel64
. dist/psl-names.bash

$pdist/make-bare-psl
$pdist/make-pslcomp

cd $PROOT/dist
make bpsl
cd ..

svn diff $pxk/main.s
svn diff $pxk/dmain.s

$pdist/make-bare-psl
$pdist/make-pslcomp



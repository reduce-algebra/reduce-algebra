#! /bin/bash

# Used as a helper for packing the distribution

rm -rf distrib
mkdir distrib
mkdir distrib/psl
mkdir distrib/csl

cd README.for.distribution distrib/README

cp -r $1/cslbuild/*/csl/*.app distrib/csl
cp runcsl.sh distrib/csl

cp -r $1/pslbuild/*/psl distrib/psl
cp -r $1/pslbuild/*/red distrib/psl
cp runpsl.sh distrib/psl/redpsl

cp Reduce_source.tar.bz2 distrib/Reduce_source-$TODAY.tar.bz2

exit
